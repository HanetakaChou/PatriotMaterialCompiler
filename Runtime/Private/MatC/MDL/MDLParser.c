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
int YYTOKEN_USING = USING;
int YYTOKEN_MODULE = MODULE;
int YYTOKEN_EXPORT = EXPORT;
int YYTOKEN_ASSIGN = ASSIGN;
int YYTOKEN_MULTIPLY_ASSIGN = MULTIPLY_ASSIGN;
int YYTOKEN_DIVIDE_ASSIGN = DIVIDE_ASSIGN;
int YYTOKEN_MODULO_ASSIGN = MODULO_ASSIGN;
int YYTOKEN_PLUS_ASSIGN = PLUS_ASSIGN;
int YYTOKEN_MINUS_ASSIGN = MINUS_ASSIGN;
int YYTOKEN_SHIFT_LEFT_ASSIGN = SHIFT_LEFT_ASSIGN;
int YYTOKEN_SHIFT_RIGHT_ASSIGN = SHIFT_RIGHT_ASSIGN;
int YYTOKEN_UNSIGNED_SHIFT_RIGHT_ASSIGN = UNSIGNED_SHIFT_RIGHT_ASSIGN;
int YYTOKEN_BITWISE_AND_ASSIGN = BITWISE_AND_ASSIGN;
int YYTOKEN_BITWISE_XOR_ASSIGN = BITWISE_XOR_ASSIGN;
int YYTOKEN_BITWISE_OR_ASSIGN = BITWISE_OR_ASSIGN;
int YYTOKEN_DOT = DOT;
int YYTOKEN_DOTDOT = DOTDOT;
int YYTOKEN_STAR = STAR;
int YYTOKEN_SCOPE = SCOPE;
int YYTOKEN_COLON = COLON;
int YYTOKEN_ANNOTATION_BLOCK_BEGIN = ANNOTATION_BLOCK_BEGIN;
int YYTOKEN_ANNOTATION_BLOCK_END = ANNOTATION_BLOCK_END;
int YYTOKEN_LEFT_PAREN = LEFT_PAREN;
int YYTOKEN_RIGHT_PAREN = RIGHT_PAREN;
int YYTOKEN_IDENT = IDENT;
int YYTOKEN_INTEGER_LITERAL = INTEGER_LITERAL;
int YYTOKEN_FLOATING_LITERAL = FLOATING_LITERAL;

static void _static_assert_mdl_yy_parser_(void)
{
    char _static_assert_yyeof_[((YYEOF == 0) ? 1 : -1)];
}