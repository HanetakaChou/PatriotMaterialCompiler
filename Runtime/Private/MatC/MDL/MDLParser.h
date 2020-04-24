#ifndef _MDL_YYPARSER_H_
#define _MDL_YYPARSER_H_ 1

#ifndef __cplusplus

union YYSTYPE {
    size_t _IDENT; //unordered_set hash unique value
    int _INTEGER_LITERAL;
    float _FLOATING_LITERAL;
    struct MDLDeclaration *_decl;
    void *_null;
};

extern int YYTOKEN_MDL;
extern int YYTOKEN_SEMICOLON;
extern int YYTOKEN_COMMA;
extern int YYTOKEN_IMPORT;
extern int YYTOKEN_USING;
extern int YYTOKEN_MODULE;
extern int YYTOKEN_EXPORT;
extern int YYTOKEN_ASSIGN;
extern int YYTOKEN_MULTIPLY_ASSIGN;
extern int YYTOKEN_DIVIDE_ASSIGN;
extern int YYTOKEN_MODULO_ASSIGN;
extern int YYTOKEN_PLUS_ASSIGN;
extern int YYTOKEN_MINUS_ASSIGN;
extern int YYTOKEN_SHIFT_LEFT_ASSIGN;
extern int YYTOKEN_SHIFT_RIGHT_ASSIGN ;
extern int YYTOKEN_UNSIGNED_SHIFT_RIGHT_ASSIGN;
extern int YYTOKEN_BITWISE_AND_ASSIGN;
extern int YYTOKEN_BITWISE_XOR_ASSIGN;
extern int YYTOKEN_BITWISE_OR_ASSIGN;
extern int YYTOKEN_DOT;
extern int YYTOKEN_DOTDOT;
extern int YYTOKEN_STAR;
extern int YYTOKEN_SCOPE;
extern int YYTOKEN_COLON;
extern int YYTOKEN_ANNOTATION_BLOCK_BEGIN;
extern int YYTOKEN_ANNOTATION_BLOCK_END;
extern int YYTOKEN_LEFT_PAREN;
extern int YYTOKEN_RIGHT_PAREN;
extern int YYTOKEN_IDENT;
extern int YYTOKEN_INTEGER_LITERAL;
extern int YYTOKEN_FLOATING_LITERAL;

#else
#error C++ Not Supported
#endif

#endif