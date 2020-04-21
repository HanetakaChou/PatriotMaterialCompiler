#ifndef _MDLFRONTEND_H_
#define _MDLFRONTEND_H_ 1

#include <stddef.h>

class MDLFrontend
{
public:
    MDLFrontend();

    void compile();

    void callback_error(const char *s);

    void *callback_malloc(size_t size);
    void *callback_realloc(void *ptr, size_t size);
    void callback_free(void *ptr);
};

#endif