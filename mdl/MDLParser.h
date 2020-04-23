#ifndef _MDL_YYPARSER_H_
#define _MDL_YYPARSER_H_ 1

#ifndef __cplusplus

union YYSTYPE {
    size_t _IDENT; //unordered_set hash unique value
    int _INTEGER_LITERAL;
    float _FLOATING_LITERAL;
};

extern int YYTOKEN_MDL;
extern int YYTOKEN_SEMICOLON;
extern int YYTOKEN_IMPORT;
extern int YYTOKEN_SCOPE;
extern int YYTOKEN_IDENT;
extern int YYTOKEN_INTEGER_LITERAL;
extern int YYTOKEN_FLOATING_LITERAL;

#else
#error C++ Not Supported
#endif

#endif