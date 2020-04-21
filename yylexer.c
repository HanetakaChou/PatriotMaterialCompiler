#include <stddef.h>

extern int ll_inputstream_read(void *pUserData, void *pUserStream, void *buf, size_t max_size);

#define YY_INPUT(buf, result, max_size)                                               \
    {                                                                                 \
        (*(&result)) = ll_inputstream_read((yyextra), ((void *)yyin), buf, max_size); \
        if (result == -1)                                                             \
        {                                                                             \
            YY_FATAL_ERROR("input in flex scanner failed");                           \
        }                                                                             \
    }

#include "yyparser.h"

#define YY_DECL int lllex(yyscan_t yyscanner, union YYSTYPE *lvalp)

#include "yylexer.inl"

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

//https://westes.github.io/flex/manual/Generated-Scanner.html#Generated-Scanner
int llwrap(yyscan_t yyscanner)
{
    void *user_defined = llget_extra(yyscanner);
    return 1;
}

static void _static_assert_yylexer_(void)
{
    char _static_assert_yy_size_t_[((sizeof(yy_size_t) == sizeof(size_t)) ? 1 : -1)];
    char _static_assert_yyscan_t_[((sizeof(yyscan_t) == sizeof(void *)) ? 1 : -1)];
}
