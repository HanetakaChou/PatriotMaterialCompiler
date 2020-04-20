
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

namespace yy
{
int yylex(parser::semantic_type *yylval)
{
    static int i = 0;
    char str[] = {"1+1"};
    char ch = str[i];
    ++i;
    return ch;
}

void parser::error(const std::string &msg)
{
    std::cout << msg << '\n';
}

} // namespace yy
