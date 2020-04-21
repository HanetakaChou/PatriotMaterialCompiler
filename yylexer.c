#include <stddef.h>
extern int PTStream_Read(void *pUserData, void *pUserStream, void *buf, size_t max_size);

#define YY_NO_INPUT 1
#define YY_NO_UNPUT 1
#define YY_NO_UNISTD_H 1

#include <assert.h>
#define YY_INPUT(buf, result, max_size)                                         \
    assert(!(YY_CURRENT_BUFFER_LVALUE->yy_is_interactive));                     \
    {                                                                           \
        (*(&result)) = PTStream_Read((yyextra), ((void *)yyin), buf, max_size); \
        if (result == -1)                                                       \
        {                                                                       \
            YY_FATAL_ERROR("input in flex scanner failed");                     \
        }                                                                       \
    }

#define isatty(fd) (0)
#include <stdio.h>
#define fileno(stream) (-1)
#include "yylexer.inl"

#if 1
int main()
{
    void *pUserInputStream = (void *)1;

    yyscan_t scanner;
    lex_lex_init_extra(NULL, &scanner);
    lex_set_in(((FILE *)pUserInputStream), scanner);
    lex_set_extra((void *)1, scanner);
    lex_lex(scanner);
    lex_lex_destroy(scanner);

    return 0;
}
#endif

//https://westes.github.io/flex/manual/Generated-Scanner.html#Generated-Scanner
int lex_wrap(yyscan_t yyscanner)
{
    void *user_defined = lex_get_extra(yyscanner);
    return 1;
}