
%option reentrant
%option prefix="mdl_ll"
%option noinput
%option nounput
%option batch
%option fast
%option nounistd
%option never-interactive
%option noyyalloc
%option noyyfree
%option noyyrealloc

DIGIT [0-9]
NONZERODIGIT [1-9]
HEXDIGIT [0-9a-fA-f]
OCTDIGIT [0-7]

INTEGER_LITERAL  ({NONZERODIGIT})({DIGIT})*

%%
{INTEGER_LITERAL} { 
    lvalp->_INTEGER_LITERAL = strtol(yytext, NULL, 10);
    return YYTOKEN_INTEGER_LITERAL; 
    }

%%