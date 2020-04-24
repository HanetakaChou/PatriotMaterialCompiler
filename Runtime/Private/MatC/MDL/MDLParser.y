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
%token MODULE
%token EXPORT
%token DOT
%token DOTDOT
%token SCOPE
%token <_IDENT> IDENT
%token <_INTEGER_LITERAL> INTEGER_LITERAL 
%token <_FLOATING_LITERAL> FLOATING_LITERAL

// Define the nonterminals 
%type <_null> mdl 
%type <_decl> import_declaration;

// Define the starting nonterminal
%start mdl

%%

mdl: mdl_version import_declarations_opt module_declaration_opt global_declarations_opt { $$ = NULL; };

mdl_version: MDL FLOATING_LITERAL SEMICOLON;

import_declarations_opt: import_declarations;
import_declarations_opt: ;

import_declarations: import_declarations import_declaration;
import_declarations: import_declaration;

import_declaration: IMPORT qualified_imports SEMICOLON  { $$ = NULL; };

qualified_imports: qualified_import;
qualified_imports: qualified_imports COMMA qualified_import;

qualified_import: qualified_import_prefix_opt qualified_import_suffix;

qualified_import_prefix_opt: qualified_import_prefix;
qualified_import_prefix_opt: ;

qualified_import_prefix: qualified_import_prefix DOT SCOPE;
qualified_import_prefix: DOT SCOPE;

qualified_import_suffix: qualified_import_suffix SCOPE simple_name;
qualified_import_suffix: simple_name;

simple_name: IDENT;

module_declaration_opt: module_declaration;
module_declaration_opt: ;

module_declaration: MODULE IDENT SEMICOLON;

global_declarations_opt: global_declarations;
global_declarations_opt: ;

global_declarations: global_declarations global_declaration;
global_declarations: global_declaration;

global_declaration: EXPORT IDENT SEMICOLON;
global_declaration: IDENT SEMICOLON;

//%%
