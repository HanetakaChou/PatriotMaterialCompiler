#include <stddef.h>

extern int PTInputStream_Read(void *pUserData, void *pUserStream, void *buf, size_t max_size);

#define YY_INPUT(buf, result, max_size)                                              \
    {                                                                                \
        (*(&result)) = PTInputStream_Read((yyextra), ((void *)yyin), buf, max_size); \
        if (result == -1)                                                            \
        {                                                                            \
            YY_FATAL_ERROR("input in flex scanner failed");                          \
        }                                                                            \
    }

#include "yytoken.h"

#define YY_DECL int lllex(yyscan_t yyscanner, void *lvalp)

#include "yylexer.inl"

#if 1
int main()
{
    void *pUserInputStream = (void *)1;

    yyscan_t scanner;
    lllex_init_extra(NULL, &scanner);
    llset_in(((FILE *)pUserInputStream), scanner);
    llset_extra((void *)1, scanner);
    lllex(scanner, pUserInputStream);
    lllex_destroy(scanner);
    return 0;
}
#endif

//https://westes.github.io/flex/manual/Generated-Scanner.html#Generated-Scanner
int llwrap(yyscan_t yyscanner)
{
    void *user_defined = llget_extra(yyscanner);
    return 1;
}

void *llalloc(yy_size_t size, yyscan_t yyscanner)
{
    struct yyguts_t *yyg = (struct yyguts_t *)yyscanner;
    (void)yyg;
    return malloc(size);
}

void *llrealloc(void *ptr, yy_size_t size, yyscan_t yyscanner)
{
    struct yyguts_t *yyg = (struct yyguts_t *)yyscanner;
    (void)yyg;

    /* The cast to (char *) in the following accommodates both
	 * implementations that use char* generic pointers, and those
	 * that use void* generic pointers.  It works with the latter
	 * because both ANSI C and C++ allow castless assignment from
	 * any pointer type to void*, and deal with argument conversions
	 * as though doing an assignment.
	 */
    return realloc(ptr, size);
}

void llfree(void *ptr, yyscan_t yyscanner)
{
    struct yyguts_t *yyg = (struct yyguts_t *)yyscanner;
    (void)yyg;
    free((char *)ptr); /* see llrealloc() for (char *) cast */
}
