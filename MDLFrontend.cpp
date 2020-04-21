#include "MDLFrontend.h"

#include <stddef.h>
#include <stdlib.h>
#include <memory.h>
#include <iostream>

MDLFrontend::MDLFrontend()
{
}

extern "C" int lllex_init_extra(void *user_defined, struct llscan_t **scanner);
extern "C" void *llget_extra(struct llscan_t *yyscanner);
extern "C" void llset_in(void *user_inputstream, struct llscan_t *scanner);
extern "C" int lllex(struct llscan_t *scanner, union YYSTYPE *lvalp);
extern "C" int lllex_destroy(struct llscan_t *scanner);
extern "C" int yyparse(void *pUserData, struct llscan_t *pScanner);

void MDLFrontend::compile()
{
    struct llscan_t *scanner;
    lllex_init_extra(this, &scanner);
    llset_in(this, scanner);
    yyparse(this, scanner);
    lllex_destroy(scanner);
}

extern "C" int ll_inputstream_read(void *pUserData, void *pUserStream, void *buf, size_t max_size)
{
    return 0;
}

extern "C" void *llalloc(size_t size, struct llscan_t *scanner)
{
    return static_cast<class MDLFrontend *>(llget_extra(scanner))->callback_malloc(size);
}

extern "C" void *llrealloc(void *ptr, size_t size, struct llscan_t *scanner)
{
    /* The cast to (char *) in the following accommodates both
	 * implementations that use char* generic pointers, and those
	 * that use void* generic pointers.  It works with the latter
	 * because both ANSI C and C++ allow castless assignment from
	 * any pointer type to void*, and deal with argument conversions
	 * as though doing an assignment.
	 */

    return static_cast<class MDLFrontend *>(llget_extra(scanner))->callback_realloc(ptr, size);
}

extern "C" void llfree(void *ptr, struct llscan_t *scanner)
{
    /* see llrealloc() for (char *) cast */

    return static_cast<class MDLFrontend *>(llget_extra(scanner))->callback_free(ptr);
}

extern "C" int yylex(union YYSTYPE *lvalp, union YYLTYPE *llocp, void *pUserData, struct llscan_t *pScanner)
{
    //YYEOF==0
    int yytoken = lllex(pScanner, lvalp);
    return yytoken;
}

extern "C" void yyerror(YYLTYPE *llocp, void *pUserData, struct llscan_t *pScanner, const char *s)
{
    return static_cast<class MDLFrontend *>(llget_extra(pScanner))->callback_error(s);
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

void MDLFrontend::callback_error(const char *s)
{
    std::cout << s << std::endl;
}
