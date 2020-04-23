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
%token SEMICOLON;
%token MDL
%token IMPORT
%token SCOPE;
%token <_IDENT> IDENT
%token <_INTEGER_LITERAL> INTEGER_LITERAL 
%token <_FLOATING_LITERAL> FLOATING_LITERAL

// Define the nonterminals 
%type <n> mdl 
%type <n> mdl_version 


// Define the starting nonterminal
%start mdl

%%

mdl: mdl_version import_declaration_opt;

mdl_version: MDL FLOATING_LITERAL SEMICOLON;

import_declaration_opt: import_declarations;
import_declaration_opt: ;

import_declarations: import_declarations import_declaration;
import_declarations: ;

import_declaration: IMPORT qualified_import SEMICOLON;

qualified_import: simple_name;

simple_name: IDENT;

//%%
