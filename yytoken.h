#ifndef _YYTOEKN_H_
#define _YYTOEKN_H_ 1

#ifndef __cplusplus
extern int LL_IDENT;
extern int LL_INTEGER_LITERAL;

union YYSTYPE {
    size_t _IDENT; //unordered_set hash unique value
    int _INTEGER_LITERAL;
};

#else
#error C++ Not Supported
#endif

#endif