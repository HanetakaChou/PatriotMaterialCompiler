
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

DIGIT [0-9]

IDENT ([A-Z]|[a-z])(([0-9]|[A-Z]|[a-z]|[_])*)

INTEGER_LITERAL_DECIMAL [1-9](([0-9])*)
INTEGER_LITERAL_HEXADECIMAL [0][xX]([0-9]|[A-F]|[a-f])(([0-9]|[A-F]|[a-f])*)
INTEGER_LITERAL_OCTAL [0](([0-7])*)

FLOATING_LITERAL (({DIGIT}({DIGIT}*)[.])|(([.]{DIGIT}({DIGIT}*))(([eE]{DIGIT}({DIGIT}*))?))|(({DIGIT}({DIGIT}*)[.]{DIGIT}({DIGIT}*))(([eE]{DIGIT}({DIGIT}*))?))) 
FLOATING_LITERAL_FLOAT ({FLOATING_LITERAL})([Ff]?)
FLOATING_LITERAL_DOUBLE ({FLOATING_LITERAL})[Dd]

/* //https://westes.github.io/flex/manual/Patterns.html#Patterns */

%%
    
[/][/]((.)*)$ {  My_Test(yytext, yyleng); /* Single line comment */ }  

[/][*]([^*]*)[*]+([^*/][^*]*[*]+)*[/] {  My_Test(yytext, yyleng); /* Multiline comment */ }

[/][*] { My_Test(yytext, yyleng); /* YY_FATAL_ERROR("Unterminated comment"); */ }

[ ]|[\t](([ ]|[\t])*) { My_Test(yytext, yyleng); }

[;] {
    return ';';
    }
    
    /* keywords */
[m][d][l] {
    return YYTOKEN_MDL;
    }

[i][m][p][o][r][t] {
    return YYTOKEN_IMPORT;
    }

     /* Identifiers */
{IDENT} {
    lvalp->_IDENT = MDLFrontend_HashIdentName(yyextra, yytext);
    return YYTOKEN_IDENT;
    }

     /* Literal values */
{INTEGER_LITERAL_DECIMAL} { 
    char *endptr = NULL;
    lvalp->_INTEGER_LITERAL = strtol(yytext, &endptr, 10);
    assert(endptr <= ((yytext) + (yyleng)));
    return YYTOKEN_INTEGER_LITERAL; 
    }

{INTEGER_LITERAL_HEXADECIMAL} { 
    char *endptr = NULL;
    lvalp->_INTEGER_LITERAL = strtol(yytext, &endptr, 16);
    assert(endptr <= ((yytext) + (yyleng)));
    return YYTOKEN_INTEGER_LITERAL; 
    } 

{INTEGER_LITERAL_OCTAL} { 
    char *endptr = NULL;
    lvalp->_INTEGER_LITERAL = strtol(yytext, &endptr, 8);
    assert(endptr <= ((yytext) + (yyleng)));
    return YYTOKEN_INTEGER_LITERAL; 
    }     

{FLOATING_LITERAL_FLOAT} {
    char *endptr = NULL;
    lvalp->_FLOATING_LITERAL = strtof(yytext, &endptr);
    assert(endptr <= ((yytext) + (yyleng)));
    return YYTOKEN_FLOATING_LITERAL;
    }
{FLOATING_LITERAL_DOUBLE} {
    char *endptr = NULL;
    lvalp->_FLOATING_LITERAL = strtod(yytext, &endptr);
    assert(endptr <= ((yytext) + (yyleng)));
    return YYTOKEN_FLOATING_LITERAL;
    }    
    
    /* catch-all rule for any other single characters */
(.) { 
        char msg_fatal_error[4096];
        sprintf(msg_fatal_error, "Unexpect \'%c\' at line %d column %d", ((yytext)[0]), (yylineno), (yycolumn));
        YY_FATAL_ERROR(msg_fatal_error);
    }

%%