#ifndef _MDLFRONTEND_H_
#define _MDLFRONTEND_H_ 1

#include "../../../Public/MatC/PT_MatC_MDLFrontend.h"

#include <stddef.h>
#include <stdlib.h>
#include <string>
#include <vector>
//#include <unordered_set>

class MDLFrontend
{
	MDLFrontend_InputStreamRef(PTPTR *m_pFn_CreateInputStream)(char const *pFileName);
	ptrdiff_t(PTPTR *m_pFn_InputStreamRead)(MDLFrontend_InputStreamRef InputStreamRef, void *buf, size_t count);
	void(PTPTR *m_pFn_InputStreamDispose)(MDLFrontend_InputStreamRef InputStreamRef);

	std::vector<MDLFrontend_InputStreamRef> m_inputstream_stack;

	//std::vector<MDLFrontend_UserStream> m_UserStream_Vec;
	//std::unordered_set<std::string> m_ident_name_hash;

public:
	MDLFrontend(
		MDLFrontend_InputStreamRef(PTPTR *pFn_CreateInputStream)(char const *pFileName), //For process #include
		ptrdiff_t(PTPTR *pFn_InputStreamRead)(MDLFrontend_InputStreamRef InputStreamRef, void *buf, size_t count),
		void(PTPTR *pFn_InputStreamDispose)(MDLFrontend_InputStreamRef InputStreamRef));

	void Run(char const *pInitialFileName);

	ptrdiff_t Callback_InputStreamRead(MDLFrontend_InputStreamRef _InputStreamRef, void *buf, size_t count);
	int Callback_Wrap();

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