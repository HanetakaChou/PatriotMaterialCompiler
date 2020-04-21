
#include "mdl/MDLFrontend.h"

#include <stddef.h>

int main()
{
    MDLFrontend mdlfrontend;
    mdlfrontend.compile();

    return 0;
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