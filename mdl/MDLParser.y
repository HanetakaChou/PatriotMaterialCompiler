%define api.pure full

%define api.value.type {union YYSTYPE}

%token <_MDL> MDL
%token <_IMPORT> IMPORT

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


%%


mdl: mdl_version import_declaration_closure;

mdl_version: MDL FLOATING_LITERAL ';';

import_declaration_closure: import_declaration_closure import_declaration;
import_declaration_closure: ;

import_declaration: IMPORT qualified_import ';';

qualified_import: simple_name;

simple_name: IDENT;

//%%
