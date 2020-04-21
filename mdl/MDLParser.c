#include <stddef.h>

#include "MDLParser.h"

//https://www.gnu.org/software/bison/manual/html_node/Table-of-Symbols.html
//#define YYSTACK_USE_ALLOCA 1
#include "MDLParser.inl"

//https://www.gnu.org/software/bison/manual/html_node/Union-Decl.html#Union-Decl
//https://www.gnu.org/software/bison/manual/html_node/Location-Type.html

int YYTOKEN_MDL = MDL;
int YYTOKEN_IMPORT = IMPORT;
int YYTOKEN_IDENT = IDENT;
int YYTOKEN_INTEGER_LITERAL = INTEGER_LITERAL;
int YYTOKEN_FLOATING_LITERAL = FLOATING_LITERAL;