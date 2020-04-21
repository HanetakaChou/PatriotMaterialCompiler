

%define api.pure full
//%define api.value.type union-directive
//%define api.value.union.name YYSTYPE
%union {
  size_t _IDENT; //unordered_set hash unique value
  int _INTEGER_LITERAL;
}
%token <_IDENT> IDENT
//%token <_INTEGER_LITERAL> INTEGER_LITERAL 


%{
    inline int yylex(YYSTYPE *lvalp, YYLTYPE *llocp, void *pUserData);
    inline void yyerror(YYLTYPE *llocp, void *pUserData, const char *s);
%}

//Token即终结符
//推理规则必须全部转换为终结符（即Token），才能完成推理

//%define api.value.type union //{struct YYSTYPE}
//%token <int> INTEGER_LITERAL

//The features of the scanner is a subset of the parser
//We can use YACC to implement the features of the scanner //Maybe inefficient

%locations


%parse-param {void *pUserData} //{void *pUserData2}
%lex-param {void *pUserData} 

%%


mdl: INTEGER_LITERAL;

INTEGER_LITERAL: NONZERODIGIT;

INTEGER_LITERAL: NONZERODIGIT DIGIT;

INTEGER_LITERAL: '0' 'x' HEXDIGIT

DIGIT: '0'|'1'|'2'|'3'|'4'|'5'|'6'|'7'|'8'|'9';

NONZERODIGIT: '1'|'2'|'3'|'4'|'5'|'6'|'7'|'8'|'9';

HEXDIGIT: '0'|'1'|'2'|'3'|'4'|'5'|'6'|'7'|'8'|'9'|'a'|'b'|'c'|'d'|'e'|'f'|'A'|'B'|'C'|'D'|'E'|'F';

//%%
