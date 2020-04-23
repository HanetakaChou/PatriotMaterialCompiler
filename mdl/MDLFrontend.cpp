#include "MDLFrontend.h"
#include "PT_MatC_Stream.h"
#include <stddef.h>
#include <stdlib.h>
#include <memory.h>
#include <iostream>
extern "C" int mdl_lllex_init_extra(void *user_defined, struct llscan_t **scanner);
extern "C" void mdl_llset_in(void *user_inputstream, struct llscan_t *scanner);
extern "C" int mdl_lllex_destroy(struct llscan_t *scanner);
extern "C" int mdl_yyparse(void *pUserData, struct llscan_t *pScanner);

MDLFrontend::MDLFrontend()
{

}

void MDLFrontend::compile()
{
    PT_MatC_Stream_File stream("test.mdl");

    struct llscan_t *scanner;
    mdl_lllex_init_extra(this, &scanner);
    mdl_llset_in(&stream, scanner);
    mdl_yyparse(this, scanner);
    mdl_lllex_destroy(scanner);
}

size_t MDLFrontend::HashIdentName(char const *pIdentName)
{
    return 0;
}

void *MDLFrontend::callback_malloc(size_t size)
{
    return malloc(size);
}

void *MDLFrontend::callback_realloc(void *ptr, size_t size)
{
    return realloc(ptr, size);
}

void MDLFrontend::callback_free(void *ptr)
{
    return free(ptr);
}

void MDLFrontend::callback_error(char const *s)
{
    std::cout << s << std::endl;
}
