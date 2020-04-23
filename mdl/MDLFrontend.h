#ifndef _MDLFRONTEND_H_
#define _MDLFRONTEND_H_ 1

#include <stddef.h>
#include <string>
#include <unordered_set>

class MDLFrontend
{
    std::unordered_set<std::string> m_ident_name_hash;
public:
    MDLFrontend();
    void compile();
    size_t HashIdentName(char const *pIdentName);
    void callback_error(char const *s);
    void *callback_malloc(size_t size);
    void *callback_realloc(void *ptr, size_t size);
    void callback_free(void *ptr);
};

#endif