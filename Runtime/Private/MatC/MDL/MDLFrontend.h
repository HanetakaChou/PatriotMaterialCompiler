#ifndef _MDLFRONTEND_H_
#define _MDLFRONTEND_H_ 1

#include "../../../Public/PTCommon.h"

#include <stddef.h>
#include <string>
#include <unordered_set>

class PTEXPORT MDLFrontend
{
    //std::unordered_set<std::string> m_ident_name_hash;
public:
    MDLFrontend();
    void Compile();
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