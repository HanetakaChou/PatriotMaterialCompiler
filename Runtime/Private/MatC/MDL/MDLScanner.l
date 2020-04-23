
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

/* Ignore whitespace */
WHITE ([ \t\r](([ \t\r])*))

/* Split */
SEMICOLON (;)
COMMA (,)

/* keywords */
MDL (mdl)
IMPORT (import)
MODULE (module)
EXPORT (export)

/* Identifiers */
SCOPE (::)
IDENT (([A-Za-z])(([0-9A-Za-z_])*))

/* Literal values */
INTEGER_LITERAL_DECIMAL ([1-9](([0-9])*))
INTEGER_LITERAL_HEXADECIMAL ([0][xX]([0-9A-Fa-f])(([0-9A-Fa-f])*))
INTEGER_LITERAL_OCTAL ([0](([0-7])*))

DIGIT ([0-9])
E ([eE]([-+]?){DIGIT}({DIGIT}*))
FLOATING_LITERAL ((({DIGIT}*)[.]({DIGIT}*))({E}?))|(({DIGIT}({DIGIT}*)){E})  
FLOATING_LITERAL_FLOAT (({FLOATING_LITERAL})([Ff]?))
FLOATING_LITERAL_DOUBLE (({FLOATING_LITERAL})[Dd])

/* //https://westes.github.io/flex/manual/Patterns.html#Patterns */

%%
    
[/][/]((.)*) {
    /* Single line comment */
    }  

[/][*]([^*]*)[*]+([^*/][^*]*[*]+)*[/] {
    /* Multiline comment */
    }

[/][*] { 
    YY_FATAL_ERROR("Unterminated comment");
    }
    
    /* Ignore whitespace */
{WHITE} { 
    
    }

{SEMICOLON} {
    return YYTOKEN_SEMICOLON;
    }

{COMMA} {
    return YYTOKEN_COMMA;
    }
    
    /* keywords */
{MDL} { 
    return YYTOKEN_MDL; 
    }

{IMPORT} { 
    return YYTOKEN_IMPORT; 
    }

{MODULE} {
    return YYTOKEN_MODULE;
    }

{EXPORT} {
    return YYTOKEN_EXPORT;
    }

     /* Identifiers */
{SCOPE} {
    return YYTOKEN_SCOPE;
}

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
        assert(((yyleng) == 1));
        sprintf(msg_fatal_error, "Unexpect \'%c\' at line %d column %d", ((yytext)[0]), (yylineno), (yycolumn));
        YY_FATAL_ERROR(msg_fatal_error);
    }
%%