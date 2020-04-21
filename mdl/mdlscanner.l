
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

INTEGER_LITERAL_DECIMAL [1-9](([0-9])*)
INTEGER_LITERAL_HEXADECIMAL [0][xX][0-9a-fA-F](([0-9a-fA-F])*)
INTEGER_LITERAL_OCTAL [0](([0-7])*)

%%
{INTEGER_LITERAL_DECIMAL} { 
    lvalp->_INTEGER_LITERAL = SCAN_INTEGER_LITERAL_DECIMAL(yytext, yytext + yyleng);
    return YYTOKEN_INTEGER_LITERAL; 
    }

{INTEGER_LITERAL_HEXADECIMAL} { 
    lvalp->_INTEGER_LITERAL = SCAN_INTEGER_LITERAL_HEXADECIMAL(yytext, yytext + yyleng);
    return YYTOKEN_INTEGER_LITERAL; 
    } 

{INTEGER_LITERAL_OCTAL} { 
    lvalp->_INTEGER_LITERAL = SCAN_INTEGER_LITERAL_OCTAL(yytext, yytext + yyleng);
    return YYTOKEN_INTEGER_LITERAL; 
    }     

%%