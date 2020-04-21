
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
%option yylineno

IDENT ([A-Z]|[a-z])(([0-9]|[A-Z]|[a-z]|[_])*)

INTEGER_LITERAL_DECIMAL [1-9](([0-9])*)
INTEGER_LITERAL_HEXADECIMAL [0][xX]([0-9]|[A-F]|[a-f])(([0-9]|[A-F]|[a-f])*)
INTEGER_LITERAL_OCTAL [0](([0-7])*)

%%
    
[/][/]((.)*)[\n] {} //COMMENT //无法处理最后一行未换行的情形  

[ ]|[\t](([ ]|[\t])*) {}

{IDENT} {
    lvalp->_IDENT = MDLFrontend_HashIdentName(yyextra, yytext);
    { llocp->first_line = yylineno; llocp->first_column = yycolumn; llocp->last_line = yylineno; llocp->last_column = yycolumn;}
    return YYTOKEN_IDENT;
    }

{INTEGER_LITERAL_DECIMAL} { 
    lvalp->_INTEGER_LITERAL = SCAN_INTEGER_LITERAL_DECIMAL(yytext, yytext + yyleng);
    { llocp->first_line = yylineno; llocp->first_column = yycolumn; llocp->last_line = yylineno; llocp->last_column = yycolumn;}
    return YYTOKEN_INTEGER_LITERAL; 
    }

{INTEGER_LITERAL_HEXADECIMAL} { 
    lvalp->_INTEGER_LITERAL = SCAN_INTEGER_LITERAL_HEXADECIMAL(yytext, yytext + yyleng);
    { llocp->first_line = yylineno; llocp->first_column = yycolumn; llocp->last_line = yylineno; llocp->last_column = yycolumn;}
    return YYTOKEN_INTEGER_LITERAL; 
    } 

{INTEGER_LITERAL_OCTAL} { 
    lvalp->_INTEGER_LITERAL = SCAN_INTEGER_LITERAL_OCTAL(yytext, yytext + yyleng);
    { llocp->first_line = yylineno; llocp->first_column = yycolumn; llocp->last_line = yylineno; llocp->last_column = yycolumn;}
    return YYTOKEN_INTEGER_LITERAL; 
    }     

%%