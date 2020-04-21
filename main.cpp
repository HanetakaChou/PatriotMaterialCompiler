
#include "mdlparser.h"

#include <stddef.h>

int main()
{

    mdlparse(NULL);

#if 0
    yy::parser yacc_parser;
    yacc_parser.parse();
#endif

    return 0;
}

#include <stdio.h>
#include <iostream>

extern "C" int mdllex(void *pUserData, struct mdl_parser_semantic_type *lvalp, int mdl_parser_location_first_line, int mdl_parser_location_first_column, int mdl_parser_location_last_line, int mdl_parser_location_last_column)
{
    //For example //static_cast<MyClass *>(pUserdata)->lex(lvalp) //To use pUserdata
    char ch = getchar();
    return ch;
}

extern "C" void mdlerror(void *pUserData, const char *s)
{
    std::cout << s << std::endl;
}

#if 0
//yylex
//https://www.gnu.org/software/bison/manual/bison.html#Split-Symbols

#include <stdio.h>
#include <iostream>

namespace yy
{
int yylex(parser::semantic_type *yylval)
{
    char ch = getchar();
    return ch;
}

void parser::error(const std::string &msg)
{
    std::cout << msg << std::endl;
}

} // namespace yy
#endif