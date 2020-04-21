#include <stddef.h>

#include "mdl_yyparser.h"

//https://www.gnu.org/software/bison/manual/html_node/Table-of-Symbols.html
//#define YYSTACK_USE_ALLOCA 1
#include "mdl_yyparser.inl"

//https://www.gnu.org/software/bison/manual/html_node/Union-Decl.html#Union-Decl
//https://www.gnu.org/software/bison/manual/html_node/Location-Type.html

int YYTOKEN_IDENT = IDENT;
int YYTOKEN_INTEGER_LITERAL = INTEGER_LITERAL;
