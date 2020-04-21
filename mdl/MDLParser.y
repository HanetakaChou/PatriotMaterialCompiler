

%define api.pure full
//%define api.value.type union-directive
//%define api.value.union.name YYSTYPE
//%union {
//  size_t _IDENT; //unordered_set hash unique value
//  int _INTEGER_LITERAL;
//}
%define api.value.type {union YYSTYPE}

%token <_MDL> MDL

%token <_IDENT> IDENT
%token <_INTEGER_LITERAL> INTEGER_LITERAL 
%token <_FLOATING_LITERAL> FLOATING_LITERAL

%locations

%parse-param {void *pUserData} {void *pScanner}
%lex-param {void *pUserData} {void *pScanner}

%code{
    int yylex(union YYSTYPE *lvalp, YYLTYPE *llocp, void *pUserData, void *pScanner);
    void yyerror(YYLTYPE *llocp, void *pUserData, void *pScanner, const char *s);
}

//Token即终结符
//推理规则必须全部转换为终结符（即Token），才能完成推理

//%define api.value.type union //{struct YYSTYPE}
//%token <int> INTEGER_LITERAL

//The features of the scanner is a subset of the parser
//We can use YACC to implement the features of the scanner //Maybe inefficient



%%


mdl: mdl_version;

mdl_version: MDL FLOATING_LITERAL ';';


//%%
