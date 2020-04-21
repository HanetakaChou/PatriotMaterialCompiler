#ifndef _YYTOEKN_H_
#define _YYTOEKN_H_ 1

#ifndef __cplusplus

union YYSTYPE {
    size_t _IDENT; //unordered_set hash unique value
    int _INTEGER_LITERAL;
};

extern int YYTOKEN_IDENT;
extern int YYTOKEN_INTEGER_LITERAL;

#else
#error C++ Not Supported
#endif

#endif