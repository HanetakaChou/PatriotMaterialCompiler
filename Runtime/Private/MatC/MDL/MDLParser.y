%define api.pure full

%define api.value.type {union YYSTYPE}

// Tell Bison to track locations for improved error messages
%locations

%parse-param {void *pUserData} {void *pScanner}
%lex-param {void *pUserData} {void *pScanner}

%code{
    int yylex(union YYSTYPE *lvalp, YYLTYPE *llocp, void *pUserData, void *pScanner);
    void yyerror(YYLTYPE *llocp, void *pUserData, void *pScanner, const char *s);
}


// Define the terminal symbols.
%token SEMICOLON
%token COMMA
%token MDL
%token IMPORT
%token USING;
%token MODULE
%token EXPORT
%token DOT
%token DOTDOT
%token SCOPE
%token STAR
%token <_IDENT> IDENT
%token <_INTEGER_LITERAL> INTEGER_LITERAL 
%token <_FLOATING_LITERAL> FLOATING_LITERAL

// Define the nonterminals 
%type <_null> mdl 
%type <_decl> import_declaration;

// Define the starting nonterminal
%start mdl

%%

mdl: mdl_version import_declarations_opt { $$ = NULL; };

mdl_version: MDL FLOATING_LITERAL SEMICOLON;

import_declarations_opt: import_declarations;
import_declarations_opt: ;

import_declarations: import_declarations import_declaration;
import_declarations: import_declaration;

import_declaration: IMPORT qualified_imports SEMICOLON { $$ = NULL; };
import_declaration: EXPORT USING qualified_import_prefix IMPORT unqualified_import SEMICOLON { $$ = NULL; };

qualified_imports: qualified_imports COMMA qualified_import;
qualified_imports: qualified_import;

qualified_import_prefix: qualified_import_prefix_opt qualified_import_infix;

unqualified_import: unqualified_import_simple_names;
unqualified_import: STAR;

qualified_import: qualified_import_prefix_opt qualified_import_infix qualified_import_suffix_opt;

unqualified_import_simple_names: unqualified_import_simple_names COMMA simple_name;
unqualified_import_simple_names: simple_name;

qualified_import_prefix_opt: qualified_import_prefix_relative_current;
qualified_import_prefix_opt: qualified_import_prefix_relative_parent;
qualified_import_prefix_opt: qualified_import_prefix_absolute;
qualified_import_prefix_opt: ;

qualified_import_prefix_relative_current: DOT SCOPE;

qualified_import_prefix_relative_parent: qualified_import_prefix_relative_parent DOTDOT SCOPE;
qualified_import_prefix_relative_parent: DOTDOT SCOPE;

qualified_import_prefix_absolute: SCOPE;

qualified_import_infix: qualified_import_infix SCOPE simple_name;
qualified_import_infix: simple_name;

qualified_import_suffix_opt: qualified_import_suffix;
qualified_import_suffix_opt: ;

qualified_import_suffix: SCOPE STAR;

simple_name: IDENT;

//%%
