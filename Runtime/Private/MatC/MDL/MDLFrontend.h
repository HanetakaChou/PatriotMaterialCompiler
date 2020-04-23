#ifndef _MDLFRONTEND_H_
#define _MDLFRONTEND_H_ 1

#include "../../../Public/PTCommon.h"

#include <stddef.h>
#include <string>
#include <unordered_set>

class PTEXPORT MDLFrontend
{
    std::unordered_set<std::string> m_ident_name_hash;
public:
    MDLFrontend();
    void Compile();
    size_t Callback_HashIdentName(char const *pIdentName);
    void Callback_Error(char const *s);
    void *Callback_Malloc(size_t size);
    void *Callback_Realloc(void *ptr, size_t size);
    void Callback_Free(void *ptr);
};

#endif