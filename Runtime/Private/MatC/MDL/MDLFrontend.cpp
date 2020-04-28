#include "MDLFrontend.h"
#include <stddef.h>
#include <stdlib.h>
#include <memory.h>
#include <iostream>
#include <new>
#include <assert.h>

extern "C" PTMATCAPI void PTCALL PT_MatC_MDLFrontend_Run(
	char const *pInitialFileName,
	MDLFrontend_InputStreamRef(PTPTR *pFn_CreateInputStream)(char const *pFileName), //For process #include
	ptrdiff_t(PTPTR *pFn_InputStreamRead)(MDLFrontend_InputStreamRef InputStreamRef, void *buf, size_t count),
	void(PTPTR *pFn_InputStreamDispose)(MDLFrontend_InputStreamRef InputStreamRef))
{
	MDLFrontend mdlfrontend(pFn_CreateInputStream, pFn_InputStreamRead, pFn_InputStreamDispose);
	mdlfrontend.Run(pInitialFileName);
}

extern "C" int mdl_lllex_init_extra(class MDLFrontend *user_defined, struct llscan_t **scanner);
extern "C" void mdl_llset_in(MDLFrontend_InputStreamRef user_inputstream, struct llscan_t *scanner);
extern "C" int mdl_lllex_destroy(struct llscan_t *scanner);
extern "C" int mdl_yyparse(class MDLFrontend *pUserData, struct llscan_t *pScanner);

MDLFrontend::MDLFrontend(
	MDLFrontend_InputStreamRef(PTPTR *pFn_CreateInputStream)(char const *pFileName), //For process #include
	ptrdiff_t(PTPTR *pFn_InputStreamRead)(MDLFrontend_InputStreamRef InputStreamRef, void *buf, size_t count),
	void(PTPTR *pFn_InputStreamDispose)(MDLFrontend_InputStreamRef InputStreamRef))
	: m_pFn_CreateInputStream(pFn_CreateInputStream),
	  m_pFn_InputStreamRead(pFn_InputStreamRead),
	  m_pFn_InputStreamDispose(pFn_InputStreamDispose)
{
}

void MDLFrontend::Run(char const *pInitialFileName)
{
	struct llscan_t *scanner;
	mdl_lllex_init_extra(this, &scanner);

	MDLFrontend_InputStreamRef _InitialInputStream = m_pFn_CreateInputStream(pInitialFileName);
	mdl_llset_in(_InitialInputStream, scanner);

	mdl_yyparse(this, scanner);

	m_pFn_InputStreamDispose(_InitialInputStream);

	mdl_lllex_destroy(scanner);
}

ptrdiff_t MDLFrontend::Callback_InputStreamRead(MDLFrontend_InputStreamRef _InputStreamRef, void *buf, size_t count)
{
	return m_pFn_InputStreamRead(_InputStreamRef, buf, count);
}

int MDLFrontend::Callback_Wrap()
{
	//return ((m_inputstream_stack.empty()) ? 1 : 0);
	return 1;
}

std::string *MDLFrontend::Callback_CreateString(char const *s)
{
	return new (Callback_Malloc(sizeof(std::string))) std::string(s);
}

std::string *MDLFrontend::Callback_StringAppend(std::string *l, std::string *r)
{
	std::string &ret = ((*l).append((*r)));
#ifndef NDEBUG
	(*r).clear();
#endif
	return &ret;
}

std::string *MDLFrontend::Callback_StringAppend(std::string *l, char const *m, std::string *r)
{
	std::string &ret = (((*l).append(m)).append(*r));
#ifndef NDEBUG
	(*r).clear();
#endif
	return &ret;
}

template <typename T>
void _Invoke_Destructor_Helper(T *_self)
{
	_self->~T();
}

void MDLFrontend::Callback_DisposeString(std::string *s)
{
#ifndef NDEBUG
	assert((*s).empty());
#endif
	_Invoke_Destructor_Helper(s);
	Callback_Free(s);
}

void MDLFrontend::Callback_HashTypeName(std::string *s)
{
	char const *ident = (*s).c_str();
	ident = NULL;
#ifndef NDEBUG
	(*s).clear();
#endif
}

void MDLFrontend::Callback_HashVariableName(std::string *s)
{
	char const *ident = (*s).c_str();
	ident = NULL;
#ifndef NDEBUG
	(*s).clear();
#endif
}

void MDLFrontend::Callback_Error(char const *s)
{
	std::cout << s << std::endl;
}

void *MDLFrontend::Callback_Malloc(size_t size)
{
	return malloc(size);
}

void *MDLFrontend::Callback_Realloc(void *ptr, size_t size)
{
	return realloc(ptr, size);
}

void MDLFrontend::Callback_Free(void *ptr)
{
	return free(ptr);
}
