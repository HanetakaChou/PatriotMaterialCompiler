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


#include <memory.h>
#include <string.h>
#include "Scanner.h"

namespace mi {
namespace mdl {



// string handling, wide character
unsigned coco_string_hash(const wchar_t *data, size_t len) {
	unsigned h = 0;
	if (!data) { return 0; }
	for (size_t i = 0; i < len; ++i) {
		h = (h * 7) ^ unsigned(data[i]);
	}
	return h;
}


Token::Token()
	: kind(0)
	, pos(0)
	, charPos(0)
	, col(0)
	, line(0)
	, val(NULL)
	, next(NULL)
{
}

Buffer::Buffer(IAllocator *alloc, IInput_stream *s, bool isUserStream)
	: builder(alloc)
	, bufCapacity(COCO_MIN_BUFFER_LENGTH)
	, bufStart(0)
	, bufLen(0)
	, fileLen(0)
	, bufPos(0) // index 0 is already after the file, thus Pos = 0 is invalid
	, isUserStream(isUserStream)
	, istream(s)
	, buf(builder.alloc<unsigned char>(bufCapacity))
{
}

Buffer::Buffer(Buffer *b)
	: builder(b->builder.get_allocator())
	, bufCapacity(b->bufCapacity)
	, bufStart(b->bufStart)
	, bufLen(b->bufLen)
	, fileLen(b->fileLen)
	, bufPos(b->bufPos)
	, isUserStream(b->isUserStream)
	, istream(b->istream)
	, buf(b->buf)
{
	b->buf = NULL;
	b->istream = NULL;
}

Buffer::~Buffer() {
	Close();
	if (buf != NULL) {
		builder.free(buf);
		buf = NULL;
	}
}

void Buffer::Close() {
	if (!isUserStream) {
		if (istream != NULL) {
			istream->release();
			istream = NULL;
		}
	}
}

int Buffer::Read() {
	if (bufPos < bufLen) {
		return buf[bufPos++];
	} else if (GetPos() < fileLen) {
		SetPos(GetPos()); // shift buffer start to Pos
		return buf[bufPos++];
	} else if (ReadNextStreamChunk() > 0) {
		return buf[bufPos++];
	} else {
		return EoF;
	}
}

int Buffer::Peek() {
	int curPos = GetPos();
	int ch = Read();
	SetPos(curPos);
	return ch;
}

int Buffer::GetPos() {
	return bufPos + bufStart;
}

void Buffer::SetPos(int value) {
	if ((value < 0) || (value > fileLen)) {
		wprintf(L"--- buffer out of bounds access, position: %d\n", value);
		exit(1);
	}

	if ((value >= bufStart) && (value < (bufStart + bufLen))) { // already in buffer
		bufPos = value - bufStart;
	} else {
		bufPos = fileLen - bufStart; // make Pos return fileLen
	}
}

// Read the next chunk of bytes from the stream, increases the buffer
// if needed and updates the fields fileLen and bufLen.
// Returns the number of bytes read.
int Buffer::ReadNextStreamChunk() {
	int free = bufCapacity - bufLen;
	if (free == 0) {
		// in the case of a growing input stream
		// we can neither seek in the stream, nor can we
		// foresee the maximum length, thus we must adapt
		// the buffer size on demand.
		bufCapacity = bufLen * 2;
		unsigned char *newBuf = builder.alloc<unsigned char>(bufCapacity);
		memcpy(newBuf, buf, bufLen * sizeof(unsigned char));
		builder.free(buf);
		buf = newBuf;
		free = bufLen;
	}
	int read = 0;
	if (istream) {
		for (; read < free; ++read) {
			char c = istream->read_char();
			if (c == -1)
				break;
			buf[bufLen + read] = (unsigned char)c;
		}
	}
	if (read > 0) {
		fileLen = bufLen = (bufLen + read);
		return read;
	}
	// end of stream reached
	return 0;
}

int UTF8Buffer::Read() {
	int ch;
	do {
		ch = Buffer::Read();
		// until we find a utf8 start (0xxxxxxx or 11xxxxxx)
	} while ((ch >= 0x80) && ((ch & 0xC0) != 0xC0) && (ch != EoF));

	if (ch <= 0x7F || ch == EoF) {
		// nothing to do, first 127 chars are the same in ascii and utf8
		// 0xxxxxxx or end of file character
	} else if ((ch & 0xF8) == 0xF0) {
		// 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
		bool error = false;
		int pos = Buffer::GetPos();

		int c1 = ch & 0x07; ch = Buffer::Read(); error |= (ch & 0xC0) != 0x80;
		int c2 = ch & 0x3F; ch = Buffer::Read(); error |= (ch & 0xC0) != 0x80;
		int c3 = ch & 0x3F; ch = Buffer::Read(); error |= (ch & 0xC0) != 0x80;
		int c4 = ch & 0x3F;
		ch = (c1 << 18) | (c2 << 12) | (c3 << 6) | c4;

		// must be U+10000 .. U+10FFFF
		error |= (ch < 0x1000) || (ch > 0x10FFFF);

		if (error) {
			ch = 0xFFFD;  // replacement character
			Buffer::SetPos(pos);
		}
	} else if ((ch & 0xF0) == 0xE0) {
		// 1110xxxx 10xxxxxx 10xxxxxx
		bool error = false;
		int pos = Buffer::GetPos();

		int c1 = ch & 0x0F; ch = Buffer::Read(); error |= (ch & 0xC0) != 0x80;
		int c2 = ch & 0x3F; ch = Buffer::Read(); error |= (ch & 0xC0) != 0x80;
		int c3 = ch & 0x3F;
		ch = (c1 << 12) | (c2 << 6) | c3;

		// must be U+0800 .. U+FFFF
		error |= ch < 0x800;

		if (error) {
			ch = 0xFFFD;  // replacement character
			Buffer::SetPos(pos);
		}
	} else if ((ch & 0xE0) == 0xC0) {
		// 110xxxxx 10xxxxxx
		bool error = false;
		int pos = Buffer::GetPos();

		int c1 = ch & 0x1F; ch = Buffer::Read(); error |= (ch & 0xC0) != 0x80;
		int c2 = ch & 0x3F;
		ch = (c1 << 6) | c2;

		// must be U+0080 .. U+07FF
		error |= ch < 0x80;

		if (error) {
			ch = 0xFFFD;  // replacement character
			Buffer::SetPos(pos);
		}
	} else {
		// error
		ch = 0xFFFD;  // replacement character
	}
	return ch;
}

Scanner::Scanner(
		IAllocator *alloc,
		Errors *err,
		mi::mdl::IInput_stream* s,
		int start_line,
		int start_col)
	: arena(alloc, COCO_HEAP_BLOCK_SIZE)
	, arena_builder(arena)
	, alloc_builder(alloc)
	, start(arena)
	, keywords(arena)
	, t(NULL)
	, tlen(0)
	, errors(err)
{
	buffer = alloc_builder.create<Buffer>(alloc, s, true);
	Init(start_line, start_col);
}

Scanner::~Scanner() {
	alloc_builder.free(tval);
	alloc_builder.destroy(buffer);
}

void Scanner::Init(int start_line, int start_col) {
	// drop the arena
	arena.drop(NULL);

	EOL    = '\n';
	eofSym = 0;
	maxT = 138;
	noSym = 138;
	int i;
	for (i = 65; i <= 90; ++i) start.set(i, 1);
	for (i = 97; i <= 122; ++i) start.set(i, 1);
	for (i = 49; i <= 57; ++i) start.set(i, 26);
	start.set(L'0', 27);
	start.set(L'.', 28);
	start.set(L'"', 12);
	start.set(L'=', 56);
	start.set(L',', 14);
	start.set(L';', 15);
	start.set(L':', 29);
	start.set(L'?', 18);
	start.set(L'(', 19);
	start.set(L')', 20);
	start.set(L'*', 57);
	start.set(L'+', 58);
	start.set(L'-', 59);
	start.set(L'~', 21);
	start.set(L'!', 60);
	start.set(L'[', 30);
	start.set(L']', 24);
	start.set(L'<', 61);
	start.set(L'>', 62);
	start.set(L'{', 37);
	start.set(L'}', 38);
	start.set(L'/', 63);
	start.set(L'%', 64);
	start.set(L'&', 65);
	start.set(L'^', 66);
	start.set(L'|', 67);
	start.set(Buffer::EoF, -1);
	keywords.set(L"import", 6);
	keywords.set(L"export", 7);
	keywords.set(L"using", 8);
	keywords.set(L"cast", 26);
	keywords.set(L"uniform", 30);
	keywords.set(L"varying", 31);
	keywords.set(L"bool", 32);
	keywords.set(L"bool2", 33);
	keywords.set(L"bool3", 34);
	keywords.set(L"bool4", 35);
	keywords.set(L"int", 36);
	keywords.set(L"int2", 37);
	keywords.set(L"int3", 38);
	keywords.set(L"int4", 39);
	keywords.set(L"float", 40);
	keywords.set(L"float2", 41);
	keywords.set(L"float3", 42);
	keywords.set(L"float4", 43);
	keywords.set(L"float2x2", 44);
	keywords.set(L"float2x3", 45);
	keywords.set(L"float2x4", 46);
	keywords.set(L"float3x2", 47);
	keywords.set(L"float3x3", 48);
	keywords.set(L"float3x4", 49);
	keywords.set(L"float4x2", 50);
	keywords.set(L"float4x3", 51);
	keywords.set(L"float4x4", 52);
	keywords.set(L"double", 53);
	keywords.set(L"double2", 54);
	keywords.set(L"double3", 55);
	keywords.set(L"double4", 56);
	keywords.set(L"double2x2", 57);
	keywords.set(L"double2x3", 58);
	keywords.set(L"double2x4", 59);
	keywords.set(L"double3x2", 60);
	keywords.set(L"double3x3", 61);
	keywords.set(L"double3x4", 62);
	keywords.set(L"double4x2", 63);
	keywords.set(L"double4x3", 64);
	keywords.set(L"double4x4", 65);
	keywords.set(L"color", 66);
	keywords.set(L"string", 67);
	keywords.set(L"bsdf", 68);
	keywords.set(L"edf", 69);
	keywords.set(L"vdf", 70);
	keywords.set(L"light_profile", 71);
	keywords.set(L"texture_2d", 72);
	keywords.set(L"texture_3d", 73);
	keywords.set(L"texture_cube", 74);
	keywords.set(L"texture_ptex", 75);
	keywords.set(L"bsdf_measurement", 76);
	keywords.set(L"intensity_mode", 77);
	keywords.set(L"intensity_radiant_exitance", 78);
	keywords.set(L"intensity_power", 79);
	keywords.set(L"material", 80);
	keywords.set(L"material_emission", 81);
	keywords.set(L"material_geometry", 82);
	keywords.set(L"material_surface", 83);
	keywords.set(L"material_volume", 84);
	keywords.set(L"module", 85);
	keywords.set(L"true", 86);
	keywords.set(L"false", 87);
	keywords.set(L"hair_bsdf", 88);
	keywords.set(L"reserved", 89);
	keywords.set(L"mdl", 90);
	keywords.set(L"annotation", 93);
	keywords.set(L"const", 94);
	keywords.set(L"typedef", 95);
	keywords.set(L"struct", 96);
	keywords.set(L"enum", 99);
	keywords.set(L"if", 100);
	keywords.set(L"else", 101);
	keywords.set(L"switch", 102);
	keywords.set(L"case", 103);
	keywords.set(L"default", 104);
	keywords.set(L"while", 105);
	keywords.set(L"do", 106);
	keywords.set(L"for", 107);
	keywords.set(L"break", 108);
	keywords.set(L"continue", 109);
	keywords.set(L"return", 110);
	keywords.set(L"let", 111);
	keywords.set(L"in", 112);


	tvalLength = 128;
	tval = alloc_builder.alloc<wchar_t>(tvalLength); // text of current token

	pos = -1; line = start_line; col = start_col - 1; charPos = -1;
	oldEols = 0;
	NextCh();
	if (ch == 0xEF) { // check optional byte order mark for UTF-8
		NextCh(); int ch1 = ch;
		NextCh(); int ch2 = ch;
		if (ch1 == 0xBB && ch2 == 0xBF) {
			Buffer *oldBuf = buffer;
			buffer = alloc_builder.create<UTF8Buffer>(buffer);
			line = start_line; col = start_col - 1; charPos = -1;
			alloc_builder.destroy(oldBuf);
			NextCh();
		} else {
			errors->Warning(1, 1, L"Illegal byte order mark at start of file ignored");
			buffer->SetPos(0);
		}
	} else {
		// always use UTF-8
		buffer->SetPos(0);
		Buffer *oldBuf = buffer;
		buffer = alloc_builder.create<UTF8Buffer>(buffer);
		line = start_line; col = start_col - 1; charPos = -1;
		alloc_builder.destroy(oldBuf);
		NextCh();
	}


	initialize_mdl_keywords();
	pt = tokens = CreateToken(); // first token is a dummy
}

void Scanner::NextCh() {
	if (oldEols > 0) { ch = EOL; oldEols--; }
	else {
		pos = buffer->GetPos();
		// buffer reads unicode chars, if UTF8 has been detected
		ch = buffer->Read(); col++; charPos++;
		// replace isolated '\r' by '\n' in order to make
		// eol handling uniform across Windows, Unix and Mac
		if (ch == L'\r' && buffer->Peek() != L'\n') ch = EOL;
		if (ch == EOL) { line++; col = 0; }
	}

}

void Scanner::AddCh() {
	if (tlen >= tvalLength) {
		tvalLength *= 2;
		wchar_t *newBuf = alloc_builder.alloc<wchar_t>(tvalLength);
		memcpy(newBuf, tval, tlen*sizeof(wchar_t));
		alloc_builder.free(tval);
		tval = newBuf;
	}
	if (ch != Buffer::EoF) {
		tval[tlen++] = ch;
		NextCh();
	}
}


bool Scanner::Comment0() {
	int level = 1, pos0 = pos, line0 = line, col0 = col, charPos0 = charPos;
	NextCh();
	if (ch == L'/') {
		NextCh();
		for(;;) {
			if (ch == 10 || ch == buffer->EoF) {
				level--;
				if (level == 0) { oldEols = line - line0; NextCh(); return true; }
				NextCh();
			} else if (ch == buffer->EoF) {
				UndeterminedComment(line0, col0);
				return false;
			} else NextCh();
		}
	} else {
		buffer->SetPos(pos0); NextCh(); line = line0; col = col0; charPos = charPos0;
	}
	return false;
}

bool Scanner::Comment1() {
	int level = 1, pos0 = pos, line0 = line, col0 = col, charPos0 = charPos;
	NextCh();
	if (ch == L'*') {
		NextCh();
		for(;;) {
			if (ch == L'*') {
				NextCh();
				if (ch == L'/') {
					level--;
					if (level == 0) { oldEols = line - line0; NextCh(); return true; }
					NextCh();
				}
			} else if (ch == L'/') {
				NextCh();
				if (ch == L'*') {
					level++; NextCh();
				}
			} else if (ch == buffer->EoF) {
				UndeterminedComment(line0, col0);
				return false;
			} else NextCh();
		}
	} else {
		buffer->SetPos(pos0); NextCh(); line = line0; col = col0; charPos = charPos0;
	}
	return false;
}


Token* Scanner::CreateToken() {
	return arena_builder.create<Token>();
}

void Scanner::AppendVal(Token *t) {
	wchar_t *val = arena_builder.alloc<wchar_t>(tlen + 1);

	wcsncpy(val, tval, tlen);
	val[tlen] = L'\0';
	t->val = val;
}

Token* Scanner::NextToken() {
	while (ch == ' ' ||
			(ch >= 9 && ch <= 10) || ch == 13
	) NextCh();
	if ((ch == L'/' && Comment0()) || (ch == L'/' && Comment1())) return NextToken();
	int apx = 0;
	int recKind = noSym;
	int recEnd = pos;
	t = CreateToken();
	t->pos = pos; t->col = col; t->line = line; t->charPos = charPos;
	int state = start.state(ch);
	tlen = 0; AddCh();

	switch (state) {
		case -1: { t->kind = eofSym; break; } // NextCh already done
		case 0: {
			case_0:
			if (recKind != noSym) {
				tlen = recEnd - t->pos;
				SetScannerBehindT();
			}
			t->kind = recKind; break;
		} // NextCh already done
		case 1:
			case_1:
			recEnd = pos; recKind = 1;
			if ((ch >= L'0' && ch <= L'9') || (ch >= L'A' && ch <= L'Z') || ch == L'_' || (ch >= L'a' && ch <= L'z')) {AddCh(); goto case_1;}
			else {t->kind = 1; t->kind = keywords.get(tlen, tval, t->kind); break;}
		case 2:
			case_2:
			if ((ch >= L'0' && ch <= L'9') || (ch >= L'A' && ch <= L'F') || (ch >= L'a' && ch <= L'f')) {AddCh(); goto case_3;}
			else {goto case_0;}
		case 3:
			case_3:
			recEnd = pos; recKind = 2;
			if ((ch >= L'0' && ch <= L'9') || (ch >= L'A' && ch <= L'F') || (ch >= L'a' && ch <= L'f')) {AddCh(); goto case_3;}
			else {t->kind = 2; break;}
		case 4:
			case_4:
			{
				tlen -= apx;
				SetScannerBehindT();
				buffer->SetPos(t->pos); NextCh(); line = t->line; col = t->col;
				for (int i = 0; i < tlen; i++) NextCh();
				t->kind = 3; break;}
		case 5:
			case_5:
			if ((ch >= L'0' && ch <= L'9')) {AddCh(); goto case_7;}
			else if (ch == L'+' || ch == L'-') {AddCh(); goto case_6;}
			else {goto case_0;}
		case 6:
			case_6:
			if ((ch >= L'0' && ch <= L'9')) {AddCh(); goto case_7;}
			else {goto case_0;}
		case 7:
			case_7:
			recEnd = pos; recKind = 4;
			if ((ch >= L'0' && ch <= L'9')) {AddCh(); goto case_7;}
			else if (ch == L'D' || ch == L'F' || ch == L'd' || ch == L'f') {AddCh(); goto case_11;}
			else {t->kind = 4; break;}
		case 8:
			case_8:
			if ((ch >= L'0' && ch <= L'9')) {AddCh(); goto case_10;}
			else if (ch == L'+' || ch == L'-') {AddCh(); goto case_9;}
			else {goto case_0;}
		case 9:
			case_9:
			if ((ch >= L'0' && ch <= L'9')) {AddCh(); goto case_10;}
			else {goto case_0;}
		case 10:
			case_10:
			recEnd = pos; recKind = 4;
			if ((ch >= L'0' && ch <= L'9')) {AddCh(); goto case_10;}
			else if (ch == L'D' || ch == L'F' || ch == L'd' || ch == L'f') {AddCh(); goto case_11;}
			else {t->kind = 4; break;}
		case 11:
			case_11:
			{t->kind = 4; break;}
		case 12:
			case_12:
			if (ch <= L'!' || (ch >= L'#' && ch <= L'[') || (ch >= L']' && ch <= 65535)) {AddCh(); goto case_12;}
			else if (ch == L'"') {AddCh(); goto case_13;}
			else if (ch == 92) {AddCh(); goto case_31;}
			else {goto case_0;}
		case 13:
			case_13:
			{t->kind = 5; break;}
		case 14:
			{t->kind = 10; break;}
		case 15:
			{t->kind = 11; break;}
		case 16:
			case_16:
			{t->kind = 13; break;}
		case 17:
			case_17:
			{t->kind = 15; break;}
		case 18:
			{t->kind = 16; break;}
		case 19:
			{t->kind = 17; break;}
		case 20:
			{t->kind = 18; break;}
		case 21:
			{t->kind = 22; break;}
		case 22:
			case_22:
			{t->kind = 24; break;}
		case 23:
			case_23:
			{t->kind = 25; break;}
		case 24:
			{t->kind = 28; break;}
		case 25:
			case_25:
			{t->kind = 29; break;}
		case 26:
			case_26:
			recEnd = pos; recKind = 2;
			if ((ch >= L'0' && ch <= L'9')) {AddCh(); goto case_26;}
			else if (ch == L'.') {AddCh(); goto case_32;}
			else if (ch == L'E' || ch == L'e') {AddCh(); goto case_5;}
			else {t->kind = 2; break;}
		case 27:
			recEnd = pos; recKind = 2;
			if ((ch >= L'0' && ch <= L'7')) {AddCh(); goto case_33;}
			else if ((ch >= L'8' && ch <= L'9')) {AddCh(); goto case_34;}
			else if (ch == L'X' || ch == L'x') {AddCh(); goto case_2;}
			else if (ch == L'.') {AddCh(); goto case_32;}
			else if (ch == L'E' || ch == L'e') {AddCh(); goto case_5;}
			else {t->kind = 2; break;}
		case 28:
			recEnd = pos; recKind = 12;
			if ((ch >= L'0' && ch <= L'9')) {AddCh(); goto case_35;}
			else if (ch == L'.') {AddCh(); goto case_16;}
			else {t->kind = 12; break;}
		case 29:
			recEnd = pos; recKind = 14;
			if (ch == L':') {AddCh(); goto case_17;}
			else {t->kind = 14; break;}
		case 30:
			recEnd = pos; recKind = 27;
			if (ch == L'[') {AddCh(); goto case_25;}
			else {t->kind = 27; break;}
		case 31:
			case_31:
			if (ch <= 65535) {AddCh(); goto case_12;}
			else {goto case_0;}
		case 32:
			case_32:
			recEnd = pos; recKind = 4;
			if ((ch >= L'0' && ch <= L'9')) {AddCh(); goto case_36;}
			else if (ch == L'D' || ch == L'F' || ch == L'd' || ch == L'f') {AddCh(); goto case_11;}
			else if (ch == L'E' || ch == L'e') {AddCh(); goto case_5;}
			else {t->kind = 4; break;}
		case 33:
			case_33:
			recEnd = pos; recKind = 2;
			if ((ch >= L'0' && ch <= L'7')) {AddCh(); goto case_33;}
			else if ((ch >= L'8' && ch <= L'9')) {AddCh(); goto case_34;}
			else if (ch == L'.') {AddCh(); goto case_32;}
			else if (ch == L'E' || ch == L'e') {AddCh(); goto case_5;}
			else {t->kind = 2; break;}
		case 34:
			case_34:
			if ((ch >= L'0' && ch <= L'9')) {AddCh(); goto case_34;}
			else if (ch == L'.') {AddCh(); goto case_32;}
			else if (ch == L'E' || ch == L'e') {AddCh(); goto case_5;}
			else {goto case_0;}
		case 35:
			case_35:
			recEnd = pos; recKind = 4;
			if ((ch >= L'0' && ch <= L'9')) {AddCh(); goto case_35;}
			else if (ch == L'D' || ch == L'F' || ch == L'd' || ch == L'f') {AddCh(); goto case_11;}
			else if (ch == L'E' || ch == L'e') {AddCh(); goto case_8;}
			else {t->kind = 4; break;}
		case 36:
			case_36:
			recEnd = pos; recKind = 4;
			if (ch <= L'/' || (ch >= L':' && ch <= L'C') || (ch >= L'G' && ch <= L'c') || (ch >= L'g' && ch <= 65535)) {apx++; AddCh(); goto case_4;}
			else if ((ch >= L'0' && ch <= L'9')) {AddCh(); goto case_36;}
			else if (ch == L'E' || ch == L'e') {AddCh(); goto case_5;}
			else if (ch == L'D' || ch == L'F' || ch == L'd' || ch == L'f') {AddCh(); goto case_11;}
			else {t->kind = 4; break;}
		case 37:
			{t->kind = 97; break;}
		case 38:
			{t->kind = 98; break;}
		case 39:
			case_39:
			{t->kind = 118; break;}
		case 40:
			case_40:
			{t->kind = 119; break;}
		case 41:
			case_41:
			{t->kind = 120; break;}
		case 42:
			case_42:
			{t->kind = 121; break;}
		case 43:
			case_43:
			{t->kind = 125; break;}
		case 44:
			case_44:
			{t->kind = 126; break;}
		case 45:
			case_45:
			{t->kind = 127; break;}
		case 46:
			case_46:
			{t->kind = 128; break;}
		case 47:
			case_47:
			{t->kind = 129; break;}
		case 48:
			case_48:
			{t->kind = 130; break;}
		case 49:
			case_49:
			{t->kind = 131; break;}
		case 50:
			case_50:
			{t->kind = 132; break;}
		case 51:
			case_51:
			{t->kind = 133; break;}
		case 52:
			case_52:
			{t->kind = 134; break;}
		case 53:
			case_53:
			{t->kind = 135; break;}
		case 54:
			case_54:
			{t->kind = 136; break;}
		case 55:
			case_55:
			{t->kind = 137; break;}
		case 56:
			recEnd = pos; recKind = 9;
			if (ch == L'=') {AddCh(); goto case_41;}
			else {t->kind = 9; break;}
		case 57:
			recEnd = pos; recKind = 19;
			if (ch == L'=') {AddCh(); goto case_45;}
			else {t->kind = 19; break;}
		case 58:
			recEnd = pos; recKind = 20;
			if (ch == L'+') {AddCh(); goto case_22;}
			else if (ch == L'=') {AddCh(); goto case_48;}
			else {t->kind = 20; break;}
		case 59:
			recEnd = pos; recKind = 21;
			if (ch == L'-') {AddCh(); goto case_23;}
			else if (ch == L'=') {AddCh(); goto case_49;}
			else {t->kind = 21; break;}
		case 60:
			recEnd = pos; recKind = 23;
			if (ch == L'=') {AddCh(); goto case_42;}
			else {t->kind = 23; break;}
		case 61:
			recEnd = pos; recKind = 91;
			if (ch == L'<') {AddCh(); goto case_68;}
			else if (ch == L'=') {AddCh(); goto case_39;}
			else {t->kind = 91; break;}
		case 62:
			recEnd = pos; recKind = 92;
			if (ch == L'>') {AddCh(); goto case_69;}
			else if (ch == L'=') {AddCh(); goto case_40;}
			else {t->kind = 92; break;}
		case 63:
			recEnd = pos; recKind = 113;
			if (ch == L'=') {AddCh(); goto case_46;}
			else {t->kind = 113; break;}
		case 64:
			recEnd = pos; recKind = 114;
			if (ch == L'=') {AddCh(); goto case_47;}
			else {t->kind = 114; break;}
		case 65:
			recEnd = pos; recKind = 122;
			if (ch == L'&') {AddCh(); goto case_43;}
			else if (ch == L'=') {AddCh(); goto case_53;}
			else {t->kind = 122; break;}
		case 66:
			recEnd = pos; recKind = 123;
			if (ch == L'=') {AddCh(); goto case_54;}
			else {t->kind = 123; break;}
		case 67:
			recEnd = pos; recKind = 124;
			if (ch == L'|') {AddCh(); goto case_44;}
			else if (ch == L'=') {AddCh(); goto case_55;}
			else {t->kind = 124; break;}
		case 68:
			case_68:
			recEnd = pos; recKind = 115;
			if (ch == L'=') {AddCh(); goto case_50;}
			else {t->kind = 115; break;}
		case 69:
			case_69:
			recEnd = pos; recKind = 116;
			if (ch == L'>') {AddCh(); goto case_70;}
			else if (ch == L'=') {AddCh(); goto case_51;}
			else {t->kind = 116; break;}
		case 70:
			case_70:
			recEnd = pos; recKind = 117;
			if (ch == L'=') {AddCh(); goto case_52;}
			else {t->kind = 117; break;}

	}
	AppendVal(t);
	return t;
}

void Scanner::SetScannerBehindT() {
	buffer->SetPos(t->pos);
	NextCh();
	line = t->line; col = t->col; charPos = t->charPos;
	for (int i = 0; i < tlen; i++) NextCh();
}

void Scanner::UndeterminedComment(int line, int col) {
	errors->Error(line, col, UNDETERMINED_COMMENT, Error_params(arena.get_allocator()));
}

// get the next token (possibly a token already seen during peeking)
Token* Scanner::Scan() {
	if (tokens->next == NULL) {
		return pt = tokens = NextToken();
	} else {
		pt = tokens = tokens->next;
		return tokens;
	}
}

// peek for the next token, ignore pragmas
Token* Scanner::Peek() {
	do {
		if (pt->next == NULL) {
			pt->next = NextToken();
		}
		pt = pt->next;
	} while (pt->kind > maxT); // skip pragmas

	return pt;
}

// make sure that peeking starts at the current scan position
void Scanner::ResetPeek() {
	pt = tokens;
}

} // namespace
} // namespace

