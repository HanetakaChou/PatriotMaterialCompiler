#include <stddef.h>

extern int mdl_ll_inputstream_read(void *pUserData, void *pUserStream, void *buf, size_t max_size);

#define YY_INPUT(buf, result, max_size)                                               \
    {                                                                                 \
        (*(&result)) = mdl_ll_inputstream_read((yyextra), ((void *)yyin), buf, max_size); \
        if (result == -1)                                                             \
        {                                                                             \
            YY_FATAL_ERROR("input in flex scanner failed");                           \
        }                                                                             \
    }

#include "mdl_yyparser.h"

#define YY_DECL int mdl_lllex(yyscan_t yyscanner, union YYSTYPE *lvalp)

#include "mdl_lllexer.inl"

#if 0
int main()
{
    void *pUserInputStream = (void *)1;

    yyscan_t scanner;
    lllex_init_extra(NULL, &scanner);
    llset_in(((FILE *)pUserInputStream), scanner);
    llset_extra((void *)1, scanner);
    union YYSTYPE yylval;
    lllex(scanner, &yylval);
    lllex_destroy(scanner);
    return 0;
}
#endif

static void _static_assert_yylexer_(void)
{
    char _static_assert_yy_size_t_[((sizeof(yy_size_t) == sizeof(size_t)) ? 1 : -1)];
    char _static_assert_yyscan_t_[((sizeof(yyscan_t) == sizeof(void *)) ? 1 : -1)];
}
