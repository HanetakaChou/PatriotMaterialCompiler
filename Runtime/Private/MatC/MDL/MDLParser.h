#ifndef _PT_MATC_MDL_MDLPARSER_H_
#define _PT_MATC_MDL_MDLPARSER_H_ 1

typedef struct MDLOpaqueString *MDLStringRef;

#ifdef __cplusplus
extern "C"
{
#endif
    MDLStringRef MDLFrontend_CreateString(void *pUserData, char const *s);
    MDLStringRef MDLFrontend_StringAppend(void *pUserData, MDLStringRef _self, char const *s);
#ifdef __cplusplus
}
#endif

#ifndef __cplusplus
union YYSTYPE {
    MDLStringRef _string; //unordered_set hash unique value
    long _INTEGER_LITERAL;
    struct
    {
        long major;
        long minor;
    } _FRACT_LITERAL;
    float _FLOATING_LITERAL;
    double _DOUBLE_LITERAL;
    struct MDLDeclaration *_decl;
    void *_null;
};

extern int YYTOKEN_STRING_LITERAL;
extern int YYTOKEN_SEMICOLON;
extern int YYTOKEN_COMMA;
extern int YYTOKEN_MDL;
extern int YYTOKEN_IMPORT;
extern int YYTOKEN_USING;
extern int YYTOKEN_MODULE;
extern int YYTOKEN_EXPORT;
extern int YYTOKEN_UNIFORM;
extern int YYTOKEN_VARYING;
extern int YYTOKEN_BOOL;
extern int YYTOKEN_BOOL2;
extern int YYTOKEN_BOOL3;
extern int YYTOKEN_BOOL4;
extern int YYTOKEN_INT;
extern int YYTOKEN_INT2;
extern int YYTOKEN_INT3;
extern int YYTOKEN_INT4;
extern int YYTOKEN_FLOAT;
extern int YYTOKEN_FLOAT2;
extern int YYTOKEN_FLOAT3;
extern int YYTOKEN_FLOAT4;
extern int YYTOKEN_FLOAT2X2;
extern int YYTOKEN_FLOAT2X3;
extern int YYTOKEN_FLOAT2X4;
extern int YYTOKEN_FLOAT3X2;
extern int YYTOKEN_FLOAT3X3;
extern int YYTOKEN_FLOAT3X4;
extern int YYTOKEN_FLOAT4X2;
extern int YYTOKEN_FLOAT4X3;
extern int YYTOKEN_FLOAT4X4;
extern int YYTOKEN_DOUBLE;
extern int YYTOKEN_DOUBLE2;
extern int YYTOKEN_DOUBLE3;
extern int YYTOKEN_DOUBLE4;
extern int YYTOKEN_DOUBLE2X2;
extern int YYTOKEN_DOUBLE2X3;
extern int YYTOKEN_DOUBLE2X4;
extern int YYTOKEN_DOUBLE3X2;
extern int YYTOKEN_DOUBLE3X3;
extern int YYTOKEN_DOUBLE3X4;
extern int YYTOKEN_DOUBLE4X2;
extern int YYTOKEN_DOUBLE4X3;
extern int YYTOKEN_DOUBLE4X4;
extern int YYTOKEN_COLOR;
extern int YYTOKEN_STRING;
extern int YYTOKEN_SDF;
extern int YYTOKEN_EDF;
extern int YYTOKEN_VDF;
extern int YYTOKEN_LIGHT_PROFILE;
extern int YYTOKEN_MATERIAL;
extern int YYTOKEN_MATERIAL_EMISSION;
extern int YYTOKEN_MATERIAL_GEOMETRY;
extern int YYTOKEN_MATERIAL_SURFACE;
extern int YYTOKEN_MATERIAL_VOLUME;
extern int YYTOKEN_TEXTURE_2D;
extern int YYTOKEN_TEXTURE_3D;
extern int YYTOKEN_TEXTURE_CUBE;
extern int YYTOKEN_TEXTURE_PTEX;
extern int YYTOKEN_BSDF_MEASUREMENT;
extern int YYTOKEN_INTENSITY_MODE;
extern int YYTOKEN_INTENSITY_RADIANT_EXITANCE;
extern int YYTOKEN_INTENSITY_POWER;
extern int YYTOKEN_HAIR_BSDF;
extern int YYTOKEN_TRUE;
extern int YYTOKEN_FALSE;
extern int YYTOKEN_LET;
extern int YYTOKEN_IN;
extern int YYTOKEN_ANNOTATION;
extern int YYTOKEN_CONST;
extern int YYTOKEN_TYPEDEF;
extern int YYTOKEN_STRUCT;
extern int YYTOKEN_ENUM;
extern int YYTOKEN_IF;
extern int YYTOKEN_ELSE;
extern int YYTOKEN_SWITCH;
extern int YYTOKEN_CASE;
extern int YYTOKEN_DEFAULT;
extern int YYTOKEN_WHILE;
extern int YYTOKEN_DO;
extern int YYTOKEN_FOR;
extern int YYTOKEN_BREAK;
extern int YYTOKEN_CONTINUE;
extern int YYTOKEN_RETURN;
extern int YYTOKEN_CAST;
extern int YYTOKEN_ASSIGN_OP;
extern int YYTOKEN_BITWISE_OR_ASSIGN_OP;
extern int YYTOKEN_BITWISE_AND_ASSIGN_OP;
extern int YYTOKEN_BITWISE_XOR_ASSIGN_OP;
extern int YYTOKEN_SHIFT_LEFT_ASSIGN_OP;
extern int YYTOKEN_SHIFT_RIGHT_ASSIGN_OP;
extern int YYTOKEN_UNSIGNED_SHIFT_RIGHT_ASSIGN_OP;
extern int YYTOKEN_MULTIPLY_ASSIGN_OP;
extern int YYTOKEN_DIVIDE_ASSIGN_OP;
extern int YYTOKEN_MODULO_ASSIGN_OP;
extern int YYTOKEN_PLUS_ASSIGN_OP;
extern int YYTOKEN_MINUS_ASSIGN_OP;
extern int YYTOKEN_CONDITIONAL_OP;
extern int YYTOKEN_LOGICAL_OR_OP;
extern int YYTOKEN_LOGICAL_AND_OP;
extern int YYTOKEN_BITWISE_OR_OP;
extern int YYTOKEN_BITWISE_XOR_OP;
extern int YYTOKEN_BITWISE_AND_OP;
extern int YYTOKEN_EQUAL_OP;
extern int YYTOKEN_NOT_EQUAL_OP;
extern int YYTOKEN_LESS_OR_EQUAL_OP;
extern int YYTOKEN_GREATER_OR_EQUAL_OP;
extern int YYTOKEN_SHIFT_LEFT_OP;
extern int YYTOKEN_SHIFT_RIGHT_OP;
extern int YYTOKEN_UNSIGNED_SHIFT_RIGHT_OP;
extern int YYTOKEN_DIVIDE_OP;
extern int YYTOKEN_MODULO_OP;
extern int YYTOKEN_BITWISE_COMPLEMENT_OP;
extern int YYTOKEN_LOGICAL_NOT_OP;
extern int YYTOKEN_POSITIVE_OP;
extern int YYTOKEN_NEGATIVE_OP;
extern int YYTOKEN_INCREMENT_OP;
extern int YYTOKEN_DECREMENT_OP;
extern int YYTOKEN_DOT;
extern int YYTOKEN_DOTDOT;
extern int YYTOKEN_SCOPE;
extern int YYTOKEN_STAR;
extern int YYTOKEN_COLON;
extern int YYTOKEN_ANNOTATION_BLOCK_BEGIN;
extern int YYTOKEN_ANNOTATION_BLOCK_END;
extern int YYTOKEN_LEFT_PARENTHESIS;
extern int YYTOKEN_RIGHT_PARENTHESIS;
extern int YYTOKEN_LEFT_SQUARE_BRACKET;
extern int YYTOKEN_RIGHT_SQUARE_BRACKET;
extern int YYTOKEN_LEFT_ANGLE_BRACKET;
extern int YYTOKEN_RIGHT_ANGLE_BRACKET;
extern int YYTOKEN_LEFT_CURLY_BRACE;
extern int YYTOKEN_RIGHT_CURLY_BRACE;
extern int YYTOKEN_IDENT;
extern int YYTOKEN_INTEGER_LITERAL;
extern int YYTOKEN_FRACT_LITERAL;
extern int YYTOKEN_FLOATING_LITERAL;
extern int YYTOKEN_DOUBLE_LITERAL;
#endif

#endif