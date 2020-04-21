#include <stddef.h>

int yylex(union YYSTYPE *lvalp, struct YYLTYPE *llocp, void *pUserData);

void yyerror(struct YYLTYPE *llocp, void *pUserData, const char *s);

//https://www.gnu.org/software/bison/manual/html_node/Table-of-Symbols.html
#define YYSTACK_USE_ALLOCA 1
#include "yyparser.inl"

#include "mdlparser.h"

int mdlparse(void *pUserData)
{
    return yyparse(pUserData);
}

//https://www.gnu.org/software/bison/manual/html_node/Union-Decl.html#Union-Decl
//https://www.gnu.org/software/bison/manual/html_node/Location-Type.html

int yylex(union YYSTYPE *lvalp, struct YYLTYPE *llocp, void *pUserData)
{
    //struct mdl_parser_semantic_type mdllval;

    //struct mdl_parser_location_type mdllloc;
    //int yytoken = mdllex(pUserData, &mdllval, &mdllloc);

    //llocp->first_line = mdllloc.first_line;
    //llocp->first_column = mdllloc.first_column;
    //llocp->last_line = mdllloc.last_line;
    //llocp->last_column = mdllloc.last_column;

    //return yytoken;

    int yytoken = TOKEN_T_INTEGER_LITERAL;
    return yytoken;
}

void yyerror(struct YYLTYPE *llocp, void *pUserData, const char *s)
{
    return mdlerror(pUserData, s);
}