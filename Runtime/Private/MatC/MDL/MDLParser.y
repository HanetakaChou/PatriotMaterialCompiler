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
%token USING
%token MODULE
%token EXPORT
%token SSIGN
%token MULTIPLY_ASSIGN
%token DIVIDE_ASSIGN
%token MODULO_ASSIGN
%token PLUS_ASSIGN
%token MINUS_ASSIGN
%token SHIFT_LEFT_ASSIGN
%token SHIFT_RIGHT_ASSIGN
%token UNSIGNED_SHIFT_RIGHT_ASSIGN
%token BITWISE_AND_ASSIGN
%token BITWISE_XOR_ASSIGN
%token BITWISE_OR_ASSIGN
%token DOT
%token DOTDOT
%token SCOPE
%token STAR
%token COLON
%token ANNOTATION_BLOCK_BEGIN;
%token ANNOTATION_BLOCK_END;
%token LEFT_PAREN;
%token RIGHT_PAREN;
%token <_IDENT> IDENT
%token <_INTEGER_LITERAL> INTEGER_LITERAL 
%token <_FLOATING_LITERAL> FLOATING_LITERAL

// Define the nonterminals 
%type <_null> mdl 
%type <_decl> import_declaration;

// Define the starting nonterminal
%start mdl

%%

mdl: mdl_version import_declarations_opt module_declaration_opt { $$ = NULL; };

mdl_version: MDL FLOATING_LITERAL SEMICOLON;

import_declarations_opt: import_declarations;
import_declarations_opt: ;

module_declaration_opt: module_declaration;
module_declaration_opt: ;

import_declarations: import_declarations import_declaration;
import_declarations: import_declaration;

import_declaration: IMPORT qualified_imports SEMICOLON { $$ = NULL; };
import_declaration: EXPORT USING qualified_import_prefix IMPORT unqualified_import SEMICOLON { $$ = NULL; };

qualified_imports: qualified_imports COMMA qualified_import;
qualified_imports: qualified_import;

qualified_import_prefix: qualified_import_prefix_opt qualified_name;

unqualified_import: unqualified_import_simple_names;
unqualified_import: STAR;

qualified_import: qualified_import_prefix_opt qualified_name qualified_import_suffix_opt;

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

qualified_name: qualified_name SCOPE simple_name;
qualified_name: simple_name;

qualified_import_suffix_opt: qualified_import_suffix;
qualified_import_suffix_opt: ;

qualified_import_suffix: SCOPE STAR;

simple_name: IDENT;

module_declaration: MODULE annotation_block_opt SEMICOLON;

annotation_block_opt: annotation_block;
annotation_block_opt: ;

annotation_block: ANNOTATION_BLOCK_BEGIN annotations ANNOTATION_BLOCK_END;

annotations: annotations COMMA annotation;
annotations: annotation;

annotation: qualified_name argument_list;

argument_list: LEFT_PAREN named_arguments RIGHT_PAREN;

named_arguments: named_arguments COMMA named_argument;
named_arguments: named_argument;

named_argument: simple_name COLON assignment_expression;

assignment_expression: DIVIDE_ASSIGN;

//%%
