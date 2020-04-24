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
%token ASSIGN_OP
%token BITWISE_OR_ASSIGN_OP
%token BITWISE_AND_ASSIGN_OP
%token BITWISE_XOR_ASSIGN_OP
%token SHIFT_LEFT_ASSIGN_OP
%token SHIFT_RIGHT_ASSIGN_OP
%token UNSIGNED_SHIFT_RIGHT_ASSIGN_OP
%token MULTIPLY_ASSIGN_OP
%token DIVIDE_ASSIGN_OP
%token MODULO_ASSIGN_OP
%token PLUS_ASSIGN_OP
%token MINUS_ASSIGN_OP
%token CONDITIONAL_OP
%token LOGICAL_OR_OP
%token LOGICAL_AND_OP
%token BITWISE_OR_OP
%token BITWISE_XOR_OP
%token BITWISE_AND_OP
%token EQUAL_OP
%token NOT_EQUAL_OP
%token LESS_OP
%token LESS_OR_EQUAL_OP
%token GREATER_OR_EQUAL_OP
%token GREATER_OP
%token SHIFT_LEFT_OP
%token SHIFT_RIGHT_OP
%token UNSIGNED_SHIFT_RIGHT_OP
%token PLUS_OP
%token MINUS_OP
%token MULTIPLY_OP
%token DIVIDE_OP
%token MODULO_OP
%token DOT
%token DOTDOT
%token SCOPE
%token STAR
%token COLON
%token ANNOTATION_BLOCK_BEGIN;
%token ANNOTATION_BLOCK_END;
%token LEFT_PARENTHESIS;
%token RIGHT_PARENTHESIS;
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

argument_list: LEFT_PARENTHESIS named_arguments RIGHT_PARENTHESIS;

named_arguments: named_arguments COMMA named_argument;
named_arguments: named_argument;

named_argument: simple_name COLON assignment_expression;

// Operators in MDL are right associative 
// To see: compilercore_parser.atg

comma_expression: assignment_expression COMMA comma_expression;
comma_expression: assignment_expression;

assignment_expression: logical_or_expression CONDITIONAL_OP comma_expression COLON assignment_expression;
assignment_expression: logical_or_expression ASSIGN_OP assignment_expression;
assignment_expression: logical_or_expression BITWISE_OR_ASSIGN_OP assignment_expression;
assignment_expression: logical_or_expression BITWISE_AND_ASSIGN_OP assignment_expression;
assignment_expression: logical_or_expression BITWISE_XOR_ASSIGN_OP assignment_expression;
assignment_expression: logical_or_expression SHIFT_LEFT_ASSIGN_OP assignment_expression;
assignment_expression: logical_or_expression SHIFT_RIGHT_ASSIGN_OP assignment_expression;
assignment_expression: logical_or_expression UNSIGNED_SHIFT_RIGHT_ASSIGN_OP assignment_expression;
assignment_expression: logical_or_expression MULTIPLY_ASSIGN_OP assignment_expression;
assignment_expression: logical_or_expression DIVIDE_ASSIGN_OP assignment_expression;
assignment_expression: logical_or_expression MODULO_ASSIGN_OP assignment_expression;
assignment_expression: logical_or_expression PLUS_ASSIGN_OP assignment_expression;
assignment_expression: logical_or_expression MINUS_ASSIGN_OP assignment_expression;
assignment_expression: logical_or_expression;

logical_or_expression: logical_and_expression LOGICAL_OR_OP logical_or_expression;
logical_or_expression: logical_and_expression;

logical_and_expression: inclusive_or_expression LOGICAL_AND_OP logical_and_expression;
logical_and_expression: inclusive_or_expression;

inclusive_or_expression: exclusive_or_expression BITWISE_OR_OP inclusive_or_expression;
inclusive_or_expression: exclusive_or_expression;

exclusive_or_expression: and_expression BITWISE_XOR_OP exclusive_or_expression;
exclusive_or_expression: and_expression;

and_expression: equality_expression BITWISE_AND_OP and_expression;
and_expression: equality_expression;

equality_expression: relational_expression EQUAL_OP equality_expression;
equality_expression: relational_expression NOT_EQUAL_OP equality_expression;
equality_expression: relational_expression;

relational_expression: shift_expression LESS_OP relational_expression;
relational_expression: shift_expression LESS_OR_EQUAL_OP relational_expression;
relational_expression: shift_expression GREATER_OR_EQUAL_OP relational_expression;
relational_expression: shift_expression GREATER_OP relational_expression;
relational_expression: shift_expression;

shift_expression: additive_expression SHIFT_LEFT_OP shift_expression;
shift_expression: additive_expression SHIFT_RIGHT_OP shift_expression;
shift_expression: additive_expression UNSIGNED_SHIFT_RIGHT_OP shift_expression;
shift_expression: additive_expression;

additive_expression: multiplicative_expression PLUS_OP additive_expression;
additive_expression: multiplicative_expression MINUS_OP additive_expression;
additive_expression: multiplicative_expression;

multiplicative_expression: unary_expression MULTIPLY_OP multiplicative_expression; 
multiplicative_expression: unary_expression DIVIDE_OP multiplicative_expression; 
multiplicative_expression: unary_expression MODULO_OP multiplicative_expression; 
multiplicative_expression: unary_expression;

unary_expression: LEFT_PARENTHESIS RIGHT_PARENTHESIS;

//%%
