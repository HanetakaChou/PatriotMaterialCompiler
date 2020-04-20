
//int yylex(); //For example //#define yylex(x) pUserdata->lex((x)) //To use pUserdata
#include "parser.inl"

int main()
{
    yy::parser yacc_parser;
    yacc_parser.parse();
    return 0;
}

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
    std::cout << msg << '\n';
}

} // namespace yy
