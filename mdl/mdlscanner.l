
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
HEXDIGIT [0-9a-fA-F]
OCTDIGIT [0-7]

INTEGER_LITERAL_DECIMAL {NONZERODIGIT}{DIGIT}*
INTEGER_LITERAL_HEXADECIMAL [0][xX]{HEXDIGIT}{HEXDIGIT}*

%%
{INTEGER_LITERAL_DECIMAL} { 
    lvalp->_INTEGER_LITERAL = PARSE_INTEGER_LITERAL_DECIMAL(yytext, yytext + yyleng);
    return YYTOKEN_INTEGER_LITERAL; 
    }

{INTEGER_LITERAL_HEXADECIMAL} { 
    lvalp->_INTEGER_LITERAL = PARSE_INTEGER_LITERAL_HEXADECIMAL(yytext, yytext + yyleng);
    return YYTOKEN_INTEGER_LITERAL; 
    } 

%%