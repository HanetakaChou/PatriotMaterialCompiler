
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
SEMICOLON (";")
COMMA (",")

/* keywords */
MDL ("mdl")
IMPORT ("import")
USING ("using")
MODULE ("module")
EXPORT ("export")
UNIFORM ("uniform")
VARYING ("varying")

/* operators */
ASSIGN_OP ("=")
BITWISE_OR_ASSIGN_OP ("|=")
BITWISE_AND_ASSIGN_OP ("&=")
BITWISE_XOR_ASSIGN_OP ("^=")
SHIFT_LEFT_ASSIGN_OP ("<<=")
SHIFT_RIGHT_ASSIGN_OP (">>=")
UNSIGNED_SHIFT_RIGHT_ASSIGN_OP (">>>=")
MULTIPLY_ASSIGN_OP ("*=")
DIVIDE_ASSIGN_OP ("/=")
MODULO_ASSIGN_OP ("%=")
PLUS_ASSIGN_OP ("+=")
MINUS_ASSIGN_OP ("-=")
CONDITIONAL_OP ("?")
LOGICAL_OR_OP ("||")
LOGICAL_AND_OP ("&&")
BITWISE_OR_OP ("|")
BITWISE_AND_OP ("&")
BITWISE_XOR_OP ("^")
EQUAL_OP ("==")
NOT_EQUAL_OP ("!=")
LESS_OP ("<")
LESS_OR_EQUAL_OP ("<=")
GREATER_OR_EQUAL_OP (">=")
GREATER_OP (">")
SHIFT_LEFT_OP ("<<")
SHIFT_RIGHT_OP (">>")
UNSIGNED_SHIFT_RIGHT_OP (">>>")
PLUS_OP ("+")
MINUS_OP ("-")
MULTIPLY_OP ("*")
DIVIDE_OP ("/")
MODULO_OP ("%")

/* Identifiers */
DOT (".")
DOTDOT ("..")
SCOPE ("::")
STAR ("*")
COLON (":")
ANNOTATION_BLOCK_BEGIN ("[[")
ANNOTATION_BLOCK_END ("]]")
LEFT_PARENTHESIS ("(")
RIGHT_PARENTHESIS (")")
LEFT_SQUARE_BRACKET ("[")
RIGHT_SQUARE_BRACKET ("]")
LEFT_ANGLE_BRACKET ("<")
RIGHT_ANGLE_BRACKET (">")
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

{USING} {
    return YYTOKEN_USING;
    }    

{MODULE} {
    return YYTOKEN_MODULE;
    }

{EXPORT} {
    return YYTOKEN_EXPORT;
    }

{UNIFORM} {
    return YYTOKEN_UNIFORM;
    }

{VARYING} {
    return YYTOKEN_VARYING;
    }

    /* operators */
{ASSIGN_OP} {
    return YYTOKEN_ASSIGN_OP;
    }

{BITWISE_OR_ASSIGN_OP} {
    return YYTOKEN_BITWISE_OR_ASSIGN_OP;
    }

{BITWISE_AND_ASSIGN_OP} {
    return YYTOKEN_BITWISE_AND_ASSIGN_OP;
    }

{BITWISE_XOR_ASSIGN_OP} {
    return YYTOKEN_BITWISE_XOR_ASSIGN_OP;
    }

{SHIFT_LEFT_ASSIGN_OP} {
    return YYTOKEN_SHIFT_LEFT_ASSIGN_OP;
    }

{SHIFT_RIGHT_ASSIGN_OP} {
    return YYTOKEN_SHIFT_RIGHT_ASSIGN_OP;
    }

{UNSIGNED_SHIFT_RIGHT_ASSIGN_OP} {
    return YYTOKEN_UNSIGNED_SHIFT_RIGHT_ASSIGN_OP;
    }

{MULTIPLY_ASSIGN_OP} {
    return YYTOKEN_MULTIPLY_ASSIGN_OP;
    }

{DIVIDE_ASSIGN_OP} {
    return YYTOKEN_DIVIDE_ASSIGN_OP;
    }

{MODULO_ASSIGN_OP} {
    return YYTOKEN_MODULO_ASSIGN_OP;
    }

{PLUS_ASSIGN_OP} {
    return YYTOKEN_PLUS_ASSIGN_OP;
    }

{MINUS_ASSIGN_OP} {
    return YYTOKEN_MINUS_ASSIGN_OP;
    }

{CONDITIONAL_OP} {
    return YYTOKEN_CONDITIONAL_OP;    
    }

{LOGICAL_OR_OP} {
    return YYTOKEN_LOGICAL_OR_OP;
    }

{LOGICAL_AND_OP} {
    return YYTOKEN_LOGICAL_AND_OP;
    }

{BITWISE_OR_OP} {
    return YYTOKEN_BITWISE_OR_OP;
    }

{BITWISE_XOR_OP} {
    return YYTOKEN_BITWISE_XOR_OP;
    }

{BITWISE_AND_OP} {
    return YYTOKEN_BITWISE_AND_OP;
    }

{EQUAL_OP} {
    return YYTOKEN_EQUAL_OP;
    }

{NOT_EQUAL_OP} {
    return YYTOKEN_NOT_EQUAL_OP;
    }

{LESS_OP} {
    return YYTOKEN_LESS_OP;
    }

{LESS_OR_EQUAL_OP} {
    return YYTOKEN_LESS_OR_EQUAL_OP;
    }

{GREATER_OR_EQUAL_OP} {
    return YYTOKEN_GREATER_OR_EQUAL_OP;
    }

{GREATER_OP} {
    return YYTOKEN_GREATER_OP;
    }

{SHIFT_LEFT_OP} {
    return YYTOKEN_SHIFT_LEFT_OP;
    }

{SHIFT_RIGHT_OP} {
    return YYTOKEN_RIGHT_LEFT_OP;
    }

{UNSIGNED_SHIFT_RIGHT_OP} {
    return YYTOKEN_UNSIGNED_SHIFT_RIGHT_OP;
    }

{MULTIPLY_OP} {
    return YYTOKEN_MULTIPLY_OP;
    }

{DIVIDE_OP} {
    return YYTOKEN_DIVIDE_OP;
    }

{MODULO_OP} {
    return YYTOKEN_MODULO_OP;
    }

     /* Identifiers */
{DOT} {
    return YYTOKEN_DOT;
}

{DOTDOT} {
    return YYTOKEN_DOTDOT;
}

{SCOPE} {
    return YYTOKEN_SCOPE;
}

{STAR} {
    return YYTOKEN_STAR;
}

{COLON} {
    return YYTOKEN_COLON;
}

{ANNOTATION_BLOCK_BEGIN} {
    return YYTOKEN_ANNOTATION_BLOCK_BEGIN;
}

{ANNOTATION_BLOCK_END} {
    return YYTOKEN_ANNOTATION_BLOCK_END;
}

{LEFT_PAREN} {
    return YYTOKEN_LEFT_PAREN;
}

{RIGHT_PAREN} {
    return YYTOKEN_RIGHT_PAREN;
}

{LEFT_SQUARE_BRACKET} {
    return YYTOKEN_LEFT_SQUARE_BRACKET;
}

{RIGHT_SQUARE_BRACKET} {
    return YYTOKEN_RIGHT_SQUARE_BRACKET;
}

{LEFT_ANGLE_BRACKET} {
    return YYTOKEN_LEFT_ANGLE_BRACKET;
    }

{RIGHT_ANGLE_BRACKET} {
    return YYTOKEN_RIGHT_ANGLE_BRACKET;
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