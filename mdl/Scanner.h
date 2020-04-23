/***************************************************************************************************
 * Copyright (c) 2011-2019, NVIDIA CORPORATION. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *  * Neither the name of NVIDIA CORPORATION nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 **************************************************************************************************/


#if !defined(mi__mdl_COCO_SCANNER_H__)
#define mi__mdl_COCO_SCANNER_H__

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#include <mi/mdl/mdl_streams.h>
#include <mdl/compiler/compilercore/compilercore_errors.h>
#include <mdl/compiler/compilercore/compilercore_memory_arena.h>

#if _MSC_VER >= 1400
#define coco_swprintf swprintf_s
#elif _MSC_VER >= 1300
#define coco_swprintf _snwprintf
#elif defined __MINGW32__
#define coco_swprintf _snwprintf
#else
// assume every other compiler knows swprintf
#define coco_swprintf swprintf
#endif

#define COCO_WCHAR_MAX 65535
#define COCO_MIN_BUFFER_LENGTH 1024
#define COCO_MAX_BUFFER_LENGTH (64*COCO_MIN_BUFFER_LENGTH)
#define COCO_HEAP_BLOCK_SIZE (64*1024)
#define COCO_CPP_NAMESPACE_SEPARATOR L':'

namespace mi {
namespace mdl {


// string handling, wide character
unsigned coco_string_hash(const wchar_t* data, size_t len);

// forward
class Error_params;

class Token  
{
public:
	int kind;     // token kind
	int pos;      // token position in bytes in the source text (starting at 0)
	int charPos;  // token position in characters in the source text (starting at 0)
	int col;      // token column (starting at 1)
	int line;     // token line (starting at 1)
	const wchar_t* val; // token value
	Token *next;  // ML 2005-03-11 Peek tokens are kept in linked list

	Token();
};

class Errors {
public:
	int count;			// number of errors detected

	Errors();
	void SynErr(Token const *la, int n);
	virtual void Error(Token const *t, const wchar_t *s);
	virtual void Warning(int line, int col, const wchar_t *s);
	virtual void Warning(const wchar_t *s);
	virtual void Exception(const wchar_t *s);
	virtual void Error(int line, int col, int code, Error_params const &params);

}; // Errors

class Buffer {
private:
	Allocator_builder builder;

	int bufCapacity;    // capacity of buf
	int bufStart;       // position of first byte in buffer relative to input stream
	int bufLen;         // length of buffer
	int fileLen;        // length of input stream (may change if the stream is no file)
	int bufPos;         // current position in buffer
	bool isUserStream;  // was the stream opened by the user?
	IInput_stream *istream; // input stream (non-seekable)
	unsigned char *buf; // input buffer
	
	int ReadNextStreamChunk();
	
public:
	static const int EoF = COCO_WCHAR_MAX + 1;

	Buffer(IAllocator *alloc, IInput_stream* s, bool isUserStream);
	Buffer(Buffer *b);
	virtual ~Buffer();
	
	void Close();
	virtual int Read();
	int Peek();
	int GetPos();
	void SetPos(int value);
};

class UTF8Buffer : public Buffer {
public:
	UTF8Buffer(Buffer *b) : Buffer(b) {};
	virtual int Read();
};

//-----------------------------------------------------------------------------------
// StartStates  -- maps characters to start states of tokens
//-----------------------------------------------------------------------------------
class StartStates {
private:
	class Elem {
	public:
		int key, val;
		Elem *next;

		Elem(int key, int val) : key(key), val(val), next(NULL) {}
	};

	Arena_builder builder;
	Elem *tab[128];

public:
	StartStates(Memory_arena &arena)
		: builder(arena)
	{
		memset(tab, 0, 128 * sizeof(Elem*));
	}

	void set(int key, int val) {
		Elem *e = builder.create<Elem>(key, val);
		int k = key & 127;
		e->next = tab[k]; tab[k] = e;
	}

	int state(int key) {
		Elem *e = tab[key & 127];
		while (e != NULL && e->key != key) e = e->next;
		return e == NULL ? 0 : e->val;
	}
};

//-------------------------------------------------------------------------------------------
// KeywordMap  -- maps strings to integers (identifiers to keyword kinds)
//-------------------------------------------------------------------------------------------
class KeywordMap {
private:
	class Elem {
	public:
		const wchar_t *key;
		size_t len;
		int val;
		Elem *next;
		
		Elem(const wchar_t *key, size_t len, int val)
			: key(key)
			, len(len)
			, val(val)
			, next(NULL)
		{}
	};

	Arena_builder builder;
	Elem *tab[128];

public:
	KeywordMap(Memory_arena &arena)
		: builder(arena)
	{
		memset(tab, 0, 128 * sizeof(Elem*));
	}

	void set(const wchar_t *key, int val) {
		size_t len = wcslen(key);
		Elem *e = builder.create<Elem>(key, len, val);
		unsigned k = coco_string_hash(key, len) & 127;
		e->next = tab[k]; tab[k] = e;
	}

	int get(int len, const wchar_t *key, int defaultVal) {
		const Elem *e = tab[coco_string_hash(key, len) & 127];
		while (e != NULL && (len != e->len || wcsncmp(e->key, key, len) != 0))
			e = e->next;
		return e == NULL ? defaultVal : e->val;
	}

	void change_keyword(const wchar_t *key, int val) {
		size_t len = wcslen(key);
		Elem *e = tab[coco_string_hash(key, len) & 127];
		while (e != NULL && (len != e->len || wcsncmp(e->key, key, len) != 0))
			e = e->next;
		if (e != NULL)
			e->val = val;
	}
};

class Scanner {
protected:
	Memory_arena       arena;
	Arena_builder      arena_builder;
	Allocator_builder  alloc_builder;

	unsigned char EOL;
	int eofSym;
	int noSym;
	int maxT;
	StartStates start;
	KeywordMap keywords;

	Token *t;         // current token
	wchar_t *tval;    // text of current token
	int tvalLength;   // length of text of current token
	int tlen;         // length of current token

	Token *tokens;    // list of tokens already peeked (first token is a dummy)
	Token *pt;        // current peek token
	Errors *errors;   // error handler

	int ch;           // current input character

	int pos;          // byte position of current character
	int charPos;      // position by unicode characters starting with 0
	int line;         // line number of current character
	int col;          // column number of current character
	int oldEols;      // EOLs that appeared in a comment;

	void AppendVal(Token *t);
	void SetScannerBehindT();
	void UndeterminedComment(int line, int col);
	void initialize_mdl_keywords();

	void Init(int start_line, int start_col);
	void NextCh();
	void AddCh();
	bool Comment0();
	bool Comment1();

	Token* NextToken();

public:
	Buffer *buffer;   // scanner buffer
	
	Scanner(
		IAllocator *alloc,
		Errors *err,
		mi::mdl::IInput_stream* s,
		int start_line = 1,
		int start_col = 1);
	~Scanner();
	Token* Scan();
	Token* Peek();
	void ResetPeek();
	Token* CreateToken();
	void set_mdl_version(int major, int minor);
	void enable_native_keyword(bool flag);

}; // end Scanner

} // namespace
} // namespace


#endif

