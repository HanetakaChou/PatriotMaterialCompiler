
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

     /* string literal */
STRING_LITERAL (\"(\\.|[^\\"\n])*\")

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
BOOL ("bool")
BOOL2 ("bool2")
BOOL3 ("bool3")
BOOL4 ("bool4")
INT ("int")
INT2 ("int2")
INT3 ("int3")
INT4 ("int4")
FLOAT ("float")
FLOAT2 ("float2")
FLOAT3 ("float3")
FLOAT4 ("float4")
FLOAT2X2 ("float2x2")
FLOAT2X3 ("float2x3")
FLOAT2X4 ("float2x4")
FLOAT3X2 ("float3x2")
FLOAT3X3 ("float3x3")
FLOAT3X4 ("float3x4")
FLOAT4X2 ("float4x2")
FLOAT4X3 ("float4x3")
FLOAT4X4 ("float4x4")
DOUBLE ("double")
DOUBLE2 ("double2")
DOUBLE3 ("double3")
DOUBLE4 ("double4")
DOUBLE2X2 ("double2x2")
DOUBLE2X3 ("double2x3")
DOUBLE2X4 ("double2x4")
DOUBLE3X2 ("double3x2")
DOUBLE3X3 ("double3x3")
DOUBLE3X4 ("double3x4")
DOUBLE4X2 ("double4x2")
DOUBLE4X3 ("double4x3")
DOUBLE4X4 ("double4x4")
COLOR ("color")
STRING ("string")
SDF ("bsdf")
EDF ("edf")
VDF ("vdf")
LIGHT_PROFILE ("light_profile")
MATERIAL ("material")
MATERIAL_EMISSION ("material_emission")
MATERIAL_GEOMETRY ("material_geometry")
MATERIAL_SURFACE ("material_surface")
MATERIAL_VOLUME ("material_volume")
TEXTURE_2D ("texture_2d")
TEXTURE_3D ("texture_3d")
TEXTURE_CUBE ("texture_cube")
TEXTURE_PTEX ("texture_ptex")
    /* MDL 1.1+ */
BSDF_MEASUREMENT ("bsdf_measurement")
    /* MDL 1.1+ */
INTENSITY_MODE ("intensity_mode")
    /* MDL 1.1+ */
INTENSITY_RADIANT_EXITANCE ("intensity_radiant_exitance")
    /* MDL 1.1+ */
INTENSITY_POWER ("intensity_power")
    /* MDL 1.5+ */
HAIR_BSDF ("hair_bsdf")
TRUE ("true")
FALSE ("false")

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
LESS_OR_EQUAL_OP ("<=")
GREATER_OR_EQUAL_OP (">=")
SHIFT_LEFT_OP ("<<")
SHIFT_RIGHT_OP (">>")
UNSIGNED_SHIFT_RIGHT_OP (">>>")
PLUS_OP ("+")
MINUS_OP ("-")
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

    /* https://westes.github.io/flex/manual/Patterns.html#Patterns */

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

     /* string literal */
{STRING_LITERAL} {
    return YYTOKEN_STRING_LITERAL;
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

{BOOL}  {
    return YYTOKEN_BOOL;
    }

{BOOL2}  {
    return YYTOKEN_BOOL2;
    }

{BOOL3}  {
    return YYTOKEN_BOOL3;
    }

{BOOL4}  {
    return YYTOKEN_BOOL4;
    }

{INT}  {
    return YYTOKEN_INT;
    }


{INT2}  {
    return YYTOKEN_INT2;
    }

{INT3}  {
    return YYTOKEN_INT3;
    }

{INT4}  {
    return YYTOKEN_INT4;
    }

{FLOAT}  {
    return YYTOKEN_FLOAT;
    }

{FLOAT2}  {
    return YYTOKEN_FLOAT2;
    }

{FLOAT3}  {
    return YYTOKEN_FLOAT3;
    }

{FLOAT4}  {
    return YYTOKEN_FLOAT4;
    }

{FLOAT2X2}  {
    return YYTOKEN_FLOAT2X2;
    }

{FLOAT2X3}  {
    return YYTOKEN_FLOAT2X3;
    }

{FLOAT2X4}  {
    return YYTOKEN_FLOAT2X4;
    }

{FLOAT3X2}  {
    return YYTOKEN_FLOAT3X2;
    }

{FLOAT3X3}  {
    return YYTOKEN_FLOAT3X3;
    }

{FLOAT3X4}  {
    return YYTOKEN_FLOAT3X4;
    }

{FLOAT4X2}  {
    return YYTOKEN_FLOAT4X2;
    }

{FLOAT4X3}  {
    return YYTOKEN_FLOAT4X3;
    }

{FLOAT4X4}  {
    return YYTOKEN_FLOAT4X4;
    }

{DOUBLE}  {
    return YYTOKEN_DOUBLE;
    }

{DOUBLE2}  {
    return YYTOKEN_DOUBLE2;
    }

{DOUBLE3}  {
    return YYTOKEN_DOUBLE3;
    }

{DOUBLE4}  {
    return YYTOKEN_DOUBLE4;
    }

{DOUBLE2X2}  {
    return YYTOKEN_DOUBLE2X2;
    }

{DOUBLE2X3}  {
    return YYTOKEN_DOUBLE2X3;
    }

{DOUBLE2X4}  {
    return YYTOKEN_DOUBLE2X4;
    }

{DOUBLE3X2}  {
    return YYTOKEN_DOUBLE3X2;
    }

{DOUBLE3X3}  {
    return YYTOKEN_DOUBLE3X3;
    }

{DOUBLE3X4}  {
    return YYTOKEN_DOUBLE3X4;
    }

{DOUBLE4X2}  {
    return YYTOKEN_DOUBLE4X2;
    }

{DOUBLE4X3}  {
    return YYTOKEN_DOUBLE4X3;
    }

{DOUBLE4X4}  {
    return YYTOKEN_DOUBLE4X4;
    }

{COLOR}  {
    return YYTOKEN_COLOR;
    }

{STRING}  {
    return YYTOKEN_STRING;
    }

{SDF}  {
    return YYTOKEN_SDF;
    }

{EDF}  {
    return YYTOKEN_EDF;
    }

{VDF}  {
    return YYTOKEN_VDF;
    }

{LIGHT_PROFILE}  {
    return YYTOKEN_LIGHT_PROFILE;
    }

{MATERIAL}  {
    return YYTOKEN_MATERIAL;
    }

{MATERIAL_EMISSION}  {
    return YYTOKEN_MATERIAL_EMISSION;
    }

{MATERIAL_GEOMETRY}  {
    return YYTOKEN_MATERIAL_GEOMETRY;
    }

{MATERIAL_SURFACE}  {
    return YYTOKEN_MATERIAL_SURFACE;
    }

{MATERIAL_VOLUME}  {
    return YYTOKEN_MATERIAL_VOLUME;
    }

{TEXTURE_2D}  {
    return YYTOKEN_TEXTURE_2D;
    }

{TEXTURE_3D}  {
    return YYTOKEN_TEXTURE_3D;
    }

{TEXTURE_CUBE}  {
    return YYTOKEN_TEXTURE_CUBE;
    }

{TEXTURE_PTEX}  {
    return YYTOKEN_TEXTURE_PTEX;
    }

    /* MDL 1.1+ */
{BSDF_MEASUREMENT}  {
    return YYTOKEN_BSDF_MEASUREMENT;
    }

    /* MDL 1.1+ */
{INTENSITY_MODE}  {
    return YYTOKEN_INTENSITY_MODE;
    }

    /* MDL 1.1+ */
{INTENSITY_RADIANT_EXITANCE}  {
    return YYTOKEN_INTENSITY_RADIANT_EXITANCE;
    }

    /* MDL 1.1+ */
{INTENSITY_POWER}  {
    return YYTOKEN_INTENSITY_POWER;
    }

    /* MDL 1.5+ */
{HAIR_BSDF}  {
    return YYTOKEN_HAIR_BSDF;
    }

{TRUE} {
    return YYTOKEN_TRUE;
    }

{FALSE} {
    return YYTOKEN_FALSE;
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

{LESS_OR_EQUAL_OP} {
    return YYTOKEN_LESS_OR_EQUAL_OP;
    }

{GREATER_OR_EQUAL_OP} {
    return YYTOKEN_GREATER_OR_EQUAL_OP;
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

{LEFT_PARENTHESIS} {
    return YYTOKEN_LEFT_PARENTHESIS;
}

{RIGHT_PARENTHESIS} {
    return YYTOKEN_RIGHT_PARENTHESIS;
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