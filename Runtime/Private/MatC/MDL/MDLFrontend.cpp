#include "MDLFrontend.h"
#include "../PT_MatC_Stream.h"
#include <stddef.h>
#include <stdlib.h>
#include <memory.h>
#include <iostream>
#include <new>
#include <assert.h>

extern "C" int mdl_lllex_init_extra(void *user_defined, struct llscan_t **scanner);
extern "C" void mdl_llset_in(void *user_inputstream, struct llscan_t *scanner);
extern "C" int mdl_lllex_destroy(struct llscan_t *scanner);
extern "C" int mdl_yyparse(void *pUserData, struct llscan_t *pScanner);

MDLFrontend::MDLFrontend()
{
}

void MDLFrontend::Compile()
{
    PT_MatC_Stream_File stream("/home/share/github/PatriotMaterialCompiler/tutorials.mdl");

    struct llscan_t *scanner;
    mdl_lllex_init_extra(this, &scanner);
    mdl_llset_in(&stream, scanner);
    mdl_yyparse(this, scanner);
    mdl_lllex_destroy(scanner);
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
