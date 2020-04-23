#include <stddef.h>

#include "MDLParser.h"

void *mdl_yyalloc(size_t size, void *pUserData);
void *mdl_yyrealloc(void *ptr, size_t size, void *pUserData);
void mdl_yyfree(void *ptr, void *pUserData);

#define YYMALLOC(size) (mdl_yyalloc((size), pUserData))
#define YYREALLOC(ptr, size) (mdl_yyrealloc((ptr), (size), pUserData))
#define YYFREE(ptr) (mdl_yyfree((ptr), pUserData))

//https://www.gnu.org/software/bison/manual/html_node/Table-of-Symbols.html
//#define YYSTACK_USE_ALLOCA 1
#include "MDLParser.inl"

//https://www.gnu.org/software/bison/manual/html_node/Union-Decl.html#Union-Decl
//https://www.gnu.org/software/bison/manual/html_node/Location-Type.html

int YYTOKEN_SEMICOLON = SEMICOLON;
int YYTOKEN_COMMA = COMMA;
int YYTOKEN_MDL = MDL;
int YYTOKEN_IMPORT = IMPORT;
int YYTOKEN_MODULE = MODULE;
int YYTOKEN_EXPORT = EXPORT;
int YYTOKEN_SCOPE = SCOPE;
int YYTOKEN_IDENT = IDENT;
int YYTOKEN_INTEGER_LITERAL = INTEGER_LITERAL;
int YYTOKEN_FLOATING_LITERAL = FLOATING_LITERAL;

static void _static_assert_mdl_yy_parser_(void)
{
    char _static_assert_yyeof_[((YYEOF == 0) ? 1 : -1)];
}