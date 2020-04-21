#include "mdlparser.h"

int yylex(struct mdl_parser_semantic_type *lvalp, struct YYLTYPE *llocp, void *pUserData);

void yyerror(struct YYLTYPE *llocp, void *pUserData, const char *s);

#include "yyparser.inl"

int mdlparse(void *pUserData)
{
    return yyparse(pUserData);
}

//https://www.gnu.org/software/bison/manual/html_node/Location-Type.html

int yylex(struct mdl_parser_semantic_type *lvalp, struct YYLTYPE *llocp, void *pUserData)
{
    return mdllex(pUserData, lvalp, llocp->first_line, llocp->first_column, llocp->last_line, llocp->last_column);
}

void yyerror(struct YYLTYPE *llocp, void *pUserData, const char *s)
{
    return mdlerror(pUserData, s);
}