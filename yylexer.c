#include <stdio.h>
// Note that the FILE pointer in the call to yy_create_buffer is only used as the value of yyin seen by YY_INPUT.
// If you redefine YY_INPUT() so it no longer uses yyin, then you can safely pass a NULL FILE pointer to yy_create_buffer.
int yyinput(void *buf, int result, int max_size, FILE *file);

#define YY_NO_INPUT 1
#define YY_NO_UNPUT 1
#define YY_NO_UNISTD_H 1
#define YY_INPUT(buf, result, max_size) (yyinput((buf), (result), (max_size), (yyin)))
#define isatty(fd) (0)
#define fileno(stream) (-1)
#include "yylexer.inl"

int main()
{
    void *pUserInputStream = (void *)1;

    yyscan_t scanner;
    yylex_init_extra(NULL, &scanner);
    yyset_in(((FILE *)pUserInputStream), scanner);
    yylex(scanner);
    yylex_destroy(scanner);
    return 0;
}

int yyinput(void *buf, int result, int max_size, FILE *file)
{
    // Note that the FILE pointer in the call to yy_create_buffer is only used as the value of yyin seen by YY_INPUT.
    // If you redefine YY_INPUT() so it no longer uses yyin, then you can safely pass a NULL FILE pointer to yy_create_buffer.
    void *pUserInputStream = ((void *)file);

    return 0;
}

//https://westes.github.io/flex/manual/Generated-Scanner.html#Generated-Scanner
int yywrap(yyscan_t yyscanner)
{
    return 1;
}