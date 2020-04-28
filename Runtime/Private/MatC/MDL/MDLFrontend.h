#ifndef _MDLFRONTEND_H_
#define _MDLFRONTEND_H_ 1

#include "../../../Public/MatC/PT_MatC_MDLFrontend.h"

#include <stddef.h>
#include <string>
#include <vector>
#include <unordered_set>

#if 0
class MDLFrontend_UserStream
{
	void * const m_pUserStream;
	ptrdiff_t(PTPTR * const m_pFn_UserStream_Read)(void *pUserStream, void *buf, size_t count);
	void(PTPTR * const m_pFn_UserStream_Dispose)(void *pUserStream);

public:
	inline MDLFrontend_UserStream(
		void *pUserStream,
		ptrdiff_t(PTPTR *pFn_UserStream_Read)(void *pUserStream, void *buf, size_t count),
		void(PTPTR *pFn_UserStream_Dispose)(void *pUserStream)
	) :m_pUserStream(pUserStream),
		m_pFn_UserStream_Read(pFn_UserStream_Read),
		m_pFn_UserStream_Dispose(pFn_UserStream_Dispose)
	{

	}

	inline ~MDLFrontend_UserStream()
	{
		m_pFn_UserStream_Dispose(m_pUserStream);
	}
};
#endif

class MDLFrontend_InputStream
{
	void * const m_pUserStream;
	ptrdiff_t(PTPTR * const m_pFn_UserStream_Read)(void *, void *, size_t);

public:
	inline MDLFrontend_InputStream(
		void *pUserStream,
		ptrdiff_t(PTPTR *pFn_UserStream_Read)(void *, void *, size_t))
		:m_pUserStream(pUserStream),
		m_pFn_UserStream_Read(pFn_UserStream_Read)
	{

	}

	inline ptrdiff_t Read(void *buf, size_t count)
	{
		return m_pFn_UserStream_Read(m_pUserStream, buf, count);
	}
};

class MDLFrontend
{
	//std::vector<MDLFrontend_UserStream> m_UserStream_Vec;
	//std::unordered_set<std::string> m_ident_name_hash;

public:
	MDLFrontend();
	void Run(MDLFrontend_InputStream *pInputStream);
	std::string *Callback_CreateString(char const *s);
	std::string *Callback_StringAppend(std::string *l, std::string *r);
	std::string *Callback_StringAppend(std::string *l, char const *m, std::string *r);
	void Callback_DisposeString(std::string *s);
	void Callback_HashTypeName(std::string *s);
	void Callback_HashVariableName(std::string *s);
	void Callback_Error(char const *s);
	void *Callback_Malloc(size_t size);
	void *Callback_Realloc(void *ptr, size_t size);
	void Callback_Free(void *ptr);
};

#endif