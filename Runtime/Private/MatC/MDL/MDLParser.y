%define api.pure full

%define api.value.type {union YYSTYPE}

// Tell Bison to track locations for improved error messages
%locations

%define parse.error verbose

%parse-param {void *pUserData} {void *pScanner}
%lex-param {void *pUserData} {void *pScanner}

%code{
    int yylex(union YYSTYPE *lvalp, YYLTYPE *llocp, void *pUserData, void *pScanner);
    void yyerror(YYLTYPE *llocp, void *pUserData, void *pScanner, const char *s);
}


// Define the terminal symbols.
%token STRING_LITERAL
%token SEMICOLON
%token COMMA
%token MDL
%token IMPORT
%token USING
%token MODULE
%token EXPORT
%token UNIFORM
%token VARYING
%token BOOL
%token BOOL2
%token BOOL3
%token BOOL4 
%token INT
%token INT2
%token INT3
%token INT4 
%token FLOAT
%token FLOAT2 
%token FLOAT3
%token FLOAT4
%token FLOAT2X2 
%token FLOAT2X3
%token FLOAT2X4
%token FLOAT3X2 
%token FLOAT3X3 
%token FLOAT3X4 
%token FLOAT4X2
%token FLOAT4X3
%token FLOAT4X4 
%token DOUBLE
%token DOUBLE2
%token DOUBLE3 
%token DOUBLE4 
%token DOUBLE2X2 
%token DOUBLE2X3 
%token DOUBLE2X4 
%token DOUBLE3X2 
%token DOUBLE3X3 
%token DOUBLE3X4 
%token DOUBLE4X2
%token DOUBLE4X3 
%token DOUBLE4X4 
%token COLOR
%token STRING
%token SDF
%token EDF
%token VDF 
%token LIGHT_PROFILE
%token MATERIAL
%token MATERIAL_EMISSION
%token MATERIAL_GEOMETRY
%token MATERIAL_SURFACE 
%token MATERIAL_VOLUME
%token TEXTURE_2D
%token TEXTURE_3D 
%token TEXTURE_CUBE 
%token TEXTURE_PTEX
%token BSDF_MEASUREMENT
%token INTENSITY_MODE 
%token INTENSITY_RADIANT_EXITANCE
%token INTENSITY_POWER
%token HAIR_BSDF
%token TRUE
%token FALSE
%token LET
%token IN
%token ANNOTATION
%token CONST
%token TYPEDEF
%token STRUCT
%token ENUM
%token IF
%token ELSE
%token SWITCH
%token CASE
%token DEFAULT
%token WHILE
%token DO
%token FOR
%token BREAK
%token CONTINUE
%token RETURN
%token CAST
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
%token LESS_OR_EQUAL_OP
%token GREATER_OR_EQUAL_OP
%token SHIFT_LEFT_OP
%token SHIFT_RIGHT_OP
%token UNSIGNED_SHIFT_RIGHT_OP
%token DIVIDE_OP
%token MODULO_OP
%token BITWISE_COMPLEMENT_OP
%token LOGICAL_NOT_OP
%token POSITIVE_OP //PLUS_OP
%token NEGATIVE_OP //MINUS_OP
%token INCREMENT_OP
%token DECREMENT_OP
%token DOT
%token DOTDOT
%token SCOPE
%token STAR //MULTIPLY_OP
%token COLON
%token ANNOTATION_BLOCK_BEGIN
%token ANNOTATION_BLOCK_END
%token LEFT_PARENTHESIS
%token RIGHT_PARENTHESIS
%token LEFT_SQUARE_BRACKET
%token RIGHT_SQUARE_BRACKET
%token LEFT_ANGLE_BRACKET //LESS_OP
%token RIGHT_ANGLE_BRACKET //GREATER_OP
%token LEFT_CURLY_BRACE
%token RIGHT_CURLY_BRACE
%token <_string> IDENT
%token INTEGER_LITERAL 
%token FRACT_LITERAL
%token FLOATING_LITERAL
%token DOUBLE_LITERAL

// Define the nonterminals 
%type <_null> mdl 
%type <_decl> import_declaration;
%type <_string> simple_type_or_lvalue;
%type <_string> type_or_variable_qualified_name;
%type <_string> simple_name;

// Define the starting nonterminal
%start mdl

%%

mdl: mdl_version import_declarations module_declaration global_declarations { $$ = NULL; };
mdl: mdl_version import_declarations global_declarations { $$ = NULL; };
mdl: mdl_version module_declaration global_declarations { $$ = NULL; };
mdl: mdl_version import_declarations module_declaration { $$ = NULL; };
mdl: mdl_version import_declarations { $$ = NULL; };
mdl: mdl_version module_declaration { $$ = NULL; };
mdl: mdl_version global_declarations { $$ = NULL; };
mdl: mdl_version { $$ = NULL; };

mdl_version: MDL FRACT_LITERAL SEMICOLON;

import_declarations: import_declarations import_declaration;
import_declarations: import_declaration;

global_declarations: global_declarations global_declaration;
global_declarations: global_declaration;

variable_declarations: variable_declarations variable_declaration;
variable_declarations: variable_declaration;

import_declaration: IMPORT qualified_imports SEMICOLON { $$ = NULL; };
import_declaration: EXPORT USING qualified_import_prefix IMPORT unqualified_import SEMICOLON { $$ = NULL; };

qualified_imports: qualified_imports COMMA qualified_import;
qualified_imports: qualified_import;

qualified_import_prefix: qualified_import_prefix_relative_current qualified_name_infix;
qualified_import_prefix: qualified_import_prefix_relative_parent qualified_name_infix;
qualified_import_prefix: qualified_import_prefix_absolute qualified_name_infix;
qualified_import_prefix: qualified_name_infix;

unqualified_import: unqualified_import_simple_names;
unqualified_import: STAR;

qualified_import: qualified_import_prefix_relative_current qualified_name_infix qualified_import_suffix;
qualified_import: qualified_import_prefix_relative_parent qualified_name_infix qualified_import_suffix;
qualified_import: qualified_import_prefix_absolute qualified_name_infix qualified_import_suffix;
qualified_import: qualified_name_infix qualified_import_suffix;
qualified_import: qualified_import_prefix_relative_current qualified_name_infix;
qualified_import: qualified_import_prefix_relative_parent qualified_name_infix;
qualified_import: qualified_import_prefix_absolute qualified_name_infix;
qualified_import: qualified_name_infix;

unqualified_import_simple_names: unqualified_import_simple_names COMMA simple_name;
unqualified_import_simple_names: simple_name;

qualified_import_prefix_relative_current: DOT SCOPE;

qualified_import_prefix_relative_parent: qualified_import_prefix_relative_parent DOTDOT SCOPE;
qualified_import_prefix_relative_parent: DOTDOT SCOPE;

qualified_import_prefix_absolute: SCOPE;

qualified_name_infix: qualified_name_infix SCOPE simple_name;
qualified_name_infix: simple_name;

qualified_import_suffix: SCOPE STAR;

module_declaration: MODULE annotation_block SEMICOLON;
module_declaration: MODULE SEMICOLON;

global_declaration: EXPORT annotation_declaration;
global_declaration: EXPORT constant_declaration;
global_declaration: EXPORT type_declaration;
global_declaration: EXPORT function_declaration;
global_declaration: annotation_declaration;
global_declaration: constant_declaration;
global_declaration: type_declaration;
global_declaration: function_declaration;

annotation_declaration: ANNOTATION simple_name parameter_list annotation_block SEMICOLON;
annotation_declaration: ANNOTATION simple_name parameter_list SEMICOLON;

constant_declaration: CONST type constant_declarators SEMICOLON;

constant_declarators: constant_declarators COMMA constant_declarator;
constant_declarators: constant_declarator;

constant_declarator: simple_name argument_list annotation_block;
constant_declarator: simple_name argument_list;
constant_declarator: simple_name ASSIGN_OP conditional_expression annotation_block;
constant_declarator: simple_name ASSIGN_OP conditional_expression;

type_declaration: alias_type_declaration;
type_declaration: struct_type_declaration;
type_declaration: enum_type_declaration;

alias_type_declaration: TYPEDEF type simple_name SEMICOLON;

struct_type_declaration: STRUCT simple_name annotation_block LEFT_CURLY_BRACE struct_field_declarators RIGHT_CURLY_BRACE SEMICOLON;
struct_type_declaration: STRUCT simple_name LEFT_CURLY_BRACE struct_field_declarators RIGHT_CURLY_BRACE SEMICOLON;
struct_type_declaration: STRUCT simple_name annotation_block LEFT_CURLY_BRACE RIGHT_CURLY_BRACE SEMICOLON;
struct_type_declaration: STRUCT simple_name LEFT_CURLY_BRACE RIGHT_CURLY_BRACE SEMICOLON;

struct_field_declarators: struct_field_declarators struct_field_declarator;
struct_field_declarators: struct_field_declarator;

struct_field_declarator: type simple_name ASSIGN_OP comma_expression annotation_block SEMICOLON;
struct_field_declarator: type simple_name ASSIGN_OP comma_expression SEMICOLON;
struct_field_declarator: type simple_name annotation_block SEMICOLON;
struct_field_declarator: type simple_name SEMICOLON;

enum_type_declaration: ENUM simple_name annotation_block LEFT_CURLY_BRACE enum_value_declarators RIGHT_CURLY_BRACE SEMICOLON;
enum_type_declaration: ENUM simple_name LEFT_CURLY_BRACE enum_value_declarators RIGHT_CURLY_BRACE SEMICOLON;
enum_type_declaration: ENUM simple_name annotation_block LEFT_CURLY_BRACE RIGHT_CURLY_BRACE SEMICOLON;
enum_type_declaration: ENUM simple_name LEFT_CURLY_BRACE RIGHT_CURLY_BRACE SEMICOLON;

enum_value_declarators: enum_value_declarators COMMA enum_value_declarator;
enum_value_declarators: enum_value_declarator;

enum_value_declarator: simple_name ASSIGN_OP assignment_expression annotation_block;
enum_value_declarator: simple_name ASSIGN_OP assignment_expression;
enum_value_declarator: simple_name annotation_block;
enum_value_declarator: simple_name;

function_declaration: type annotation_block simple_name parameter_list UNIFORM annotation_block SEMICOLON;
function_declaration: type annotation_block simple_name parameter_list VARYING annotation_block SEMICOLON;
function_declaration: type annotation_block simple_name parameter_list annotation_block SEMICOLON;
function_declaration: type annotation_block simple_name parameter_list UNIFORM SEMICOLON;
function_declaration: type annotation_block simple_name parameter_list VARYING SEMICOLON;
function_declaration: type annotation_block simple_name parameter_list SEMICOLON;
function_declaration: type simple_name parameter_list UNIFORM annotation_block SEMICOLON;
function_declaration: type simple_name parameter_list VARYING annotation_block SEMICOLON;
function_declaration: type simple_name parameter_list annotation_block SEMICOLON;
function_declaration: type simple_name parameter_list UNIFORM SEMICOLON;
function_declaration: type simple_name parameter_list VARYING SEMICOLON;
function_declaration: type simple_name parameter_list SEMICOLON;

function_declaration: type annotation_block simple_name parameter_list UNIFORM annotation_block compound_statement;
function_declaration: type annotation_block simple_name parameter_list VARYING annotation_block compound_statement;
function_declaration: type annotation_block simple_name parameter_list annotation_block compound_statement;
function_declaration: type annotation_block simple_name parameter_list UNIFORM compound_statement;
function_declaration: type annotation_block simple_name parameter_list VARYING compound_statement;
function_declaration: type annotation_block simple_name parameter_list compound_statement;
function_declaration: type simple_name parameter_list UNIFORM annotation_block compound_statement;
function_declaration: type simple_name parameter_list VARYING annotation_block compound_statement;
function_declaration: type simple_name parameter_list annotation_block compound_statement;
function_declaration: type simple_name parameter_list UNIFORM compound_statement;
function_declaration: type simple_name parameter_list VARYING compound_statement;
function_declaration: type simple_name parameter_list compound_statement;

function_declaration: type annotation_block simple_name parameter_list UNIFORM annotation_block ASSIGN_OP comma_expression SEMICOLON;
function_declaration: type annotation_block simple_name parameter_list VARYING annotation_block ASSIGN_OP comma_expression SEMICOLON;
function_declaration: type annotation_block simple_name parameter_list annotation_block ASSIGN_OP comma_expression SEMICOLON;
function_declaration: type annotation_block simple_name parameter_list UNIFORM ASSIGN_OP comma_expression SEMICOLON;
function_declaration: type annotation_block simple_name parameter_list VARYING ASSIGN_OP comma_expression SEMICOLON;
function_declaration: type annotation_block simple_name parameter_list ASSIGN_OP comma_expression SEMICOLON;
function_declaration: type simple_name parameter_list UNIFORM annotation_block ASSIGN_OP comma_expression SEMICOLON;
function_declaration: type simple_name parameter_list VARYING annotation_block ASSIGN_OP comma_expression SEMICOLON;
function_declaration: type simple_name parameter_list annotation_block ASSIGN_OP comma_expression SEMICOLON;
function_declaration: type simple_name parameter_list UNIFORM ASSIGN_OP comma_expression SEMICOLON;
function_declaration: type simple_name parameter_list VARYING ASSIGN_OP comma_expression SEMICOLON;
function_declaration: type simple_name parameter_list ASSIGN_OP comma_expression SEMICOLON;

function_declaration: type annotation_block simple_name LEFT_PARENTHESIS STAR RIGHT_PARENTHESIS annotation_block ASSIGN_OP comma_expression SEMICOLON;
function_declaration: type annotation_block simple_name LEFT_PARENTHESIS STAR RIGHT_PARENTHESIS ASSIGN_OP comma_expression SEMICOLON;
function_declaration: type simple_name LEFT_PARENTHESIS STAR RIGHT_PARENTHESIS annotation_block ASSIGN_OP comma_expression SEMICOLON;
function_declaration: type simple_name LEFT_PARENTHESIS STAR RIGHT_PARENTHESIS ASSIGN_OP comma_expression SEMICOLON;

compound_statement: LEFT_CURLY_BRACE statements RIGHT_CURLY_BRACE;
compound_statement: LEFT_CURLY_BRACE RIGHT_CURLY_BRACE;

statements: statements statement;
statements: statement;

statement: matched_statement;
statement: unmatched_statement;

matched_statement: compound_statement;
matched_statement: type_declaration;
matched_statement: constant_declaration;
matched_statement: matched_if_statement;
matched_statement: switch_statement;
matched_statement: matched_while_statement;
matched_statement: matched_do_statement;
matched_statement: matched_for_statement;
matched_statement: break_statement;
matched_statement: continue_statement;
matched_statement: return_statement;
matched_statement: variable_declaration;
matched_statement: comma_expression SEMICOLON;
matched_statement: SEMICOLON;

unmatched_statement: unmatched_if_statement;
unmatched_statement: unmatched_while_statement;
unmatched_statement: unmatched_do_statement;
unmatched_statement: unmatched_for_statement;

matched_if_statement: IF LEFT_PARENTHESIS comma_expression RIGHT_PARENTHESIS matched_statement ELSE matched_statement;
unmatched_if_statement: IF LEFT_PARENTHESIS comma_expression RIGHT_PARENTHESIS statement;
unmatched_if_statement: IF LEFT_PARENTHESIS comma_expression RIGHT_PARENTHESIS matched_statement ELSE unmatched_statement;

switch_statement: SWITCH LEFT_PARENTHESIS comma_expression RIGHT_PARENTHESIS LEFT_CURLY_BRACE switch_cases RIGHT_CURLY_BRACE;
switch_statement: SWITCH LEFT_PARENTHESIS comma_expression RIGHT_PARENTHESIS LEFT_CURLY_BRACE RIGHT_CURLY_BRACE;

switch_cases: switch_cases switch_case;
switch_cases: switch_case;

switch_case: CASE comma_expression COLON statement;
switch_case: CASE comma_expression COLON;
switch_case: DEFAULT COLON statement;
switch_case: DEFAULT COLON;

matched_while_statement: WHILE LEFT_PARENTHESIS comma_expression RIGHT_PARENTHESIS matched_statement;
unmatched_while_statement: WHILE LEFT_PARENTHESIS comma_expression RIGHT_PARENTHESIS unmatched_statement;

matched_do_statement: DO matched_statement WHILE LEFT_PARENTHESIS comma_expression RIGHT_PARENTHESIS SEMICOLON;

unmatched_do_statement: DO unmatched_statement WHILE LEFT_PARENTHESIS comma_expression RIGHT_PARENTHESIS SEMICOLON;

matched_for_statement: FOR LEFT_PARENTHESIS variable_declaration comma_expression SEMICOLON comma_expression RIGHT_PARENTHESIS matched_statement;
matched_for_statement: FOR LEFT_PARENTHESIS variable_declaration comma_expression SEMICOLON RIGHT_PARENTHESIS matched_statement;
matched_for_statement: FOR LEFT_PARENTHESIS variable_declaration SEMICOLON comma_expression RIGHT_PARENTHESIS matched_statement;
matched_for_statement: FOR LEFT_PARENTHESIS variable_declaration SEMICOLON RIGHT_PARENTHESIS matched_statement;
matched_for_statement: FOR LEFT_PARENTHESIS comma_expression SEMICOLON comma_expression SEMICOLON comma_expression RIGHT_PARENTHESIS matched_statement;
matched_for_statement: FOR LEFT_PARENTHESIS comma_expression SEMICOLON comma_expression SEMICOLON RIGHT_PARENTHESIS matched_statement;
matched_for_statement: FOR LEFT_PARENTHESIS comma_expression SEMICOLON SEMICOLON comma_expression RIGHT_PARENTHESIS matched_statement;
matched_for_statement: FOR LEFT_PARENTHESIS comma_expression SEMICOLON SEMICOLON RIGHT_PARENTHESIS matched_statement;
matched_for_statement: FOR LEFT_PARENTHESIS SEMICOLON comma_expression SEMICOLON comma_expression RIGHT_PARENTHESIS matched_statement;
matched_for_statement: FOR LEFT_PARENTHESIS SEMICOLON comma_expression SEMICOLON RIGHT_PARENTHESIS matched_statement;
matched_for_statement: FOR LEFT_PARENTHESIS SEMICOLON SEMICOLON comma_expression RIGHT_PARENTHESIS matched_statement;
matched_for_statement: FOR LEFT_PARENTHESIS SEMICOLON SEMICOLON RIGHT_PARENTHESIS matched_statement;

unmatched_for_statement: FOR LEFT_PARENTHESIS variable_declaration comma_expression SEMICOLON comma_expression RIGHT_PARENTHESIS unmatched_statement;
unmatched_for_statement: FOR LEFT_PARENTHESIS variable_declaration comma_expression SEMICOLON RIGHT_PARENTHESIS unmatched_statement;
unmatched_for_statement: FOR LEFT_PARENTHESIS variable_declaration SEMICOLON comma_expression RIGHT_PARENTHESIS unmatched_statement;
unmatched_for_statement: FOR LEFT_PARENTHESIS variable_declaration SEMICOLON RIGHT_PARENTHESIS unmatched_statement;
unmatched_for_statement: FOR LEFT_PARENTHESIS comma_expression SEMICOLON comma_expression SEMICOLON comma_expression RIGHT_PARENTHESIS unmatched_statement;
unmatched_for_statement: FOR LEFT_PARENTHESIS comma_expression SEMICOLON comma_expression SEMICOLON RIGHT_PARENTHESIS unmatched_statement;
unmatched_for_statement: FOR LEFT_PARENTHESIS comma_expression SEMICOLON SEMICOLON comma_expression RIGHT_PARENTHESIS unmatched_statement;
unmatched_for_statement: FOR LEFT_PARENTHESIS comma_expression SEMICOLON SEMICOLON RIGHT_PARENTHESIS unmatched_statement;
unmatched_for_statement: FOR LEFT_PARENTHESIS SEMICOLON comma_expression SEMICOLON comma_expression RIGHT_PARENTHESIS unmatched_statement;
unmatched_for_statement: FOR LEFT_PARENTHESIS SEMICOLON comma_expression SEMICOLON RIGHT_PARENTHESIS unmatched_statement;
unmatched_for_statement: FOR LEFT_PARENTHESIS SEMICOLON SEMICOLON comma_expression RIGHT_PARENTHESIS unmatched_statement;
unmatched_for_statement: FOR LEFT_PARENTHESIS SEMICOLON SEMICOLON RIGHT_PARENTHESIS unmatched_statement;

break_statement: BREAK SEMICOLON;

continue_statement: CONTINUE SEMICOLON;

return_statement: RETURN comma_expression SEMICOLON;

variable_declaration: type variable_declarators SEMICOLON;

variable_declarators: variable_declarators COMMA variable_declarator;
variable_declarators: variable_declarator;

variable_declarator: simple_name argument_list annotation_block;
variable_declarator: simple_name argument_list;
variable_declarator: simple_name ASSIGN_OP assignment_expression annotation_block;
variable_declarator: simple_name ASSIGN_OP assignment_expression;
variable_declarator: simple_name annotation_block;
variable_declarator: simple_name;

parameter_list: LEFT_PARENTHESIS parameters RIGHT_PARENTHESIS;
parameter_list: LEFT_PARENTHESIS RIGHT_PARENTHESIS;

parameters: parameters COMMA parameter;
parameters: parameter;

parameter: type simple_name ASSIGN_OP assignment_expression annotation_block;
parameter: type simple_name ASSIGN_OP assignment_expression;
parameter: type simple_name annotation_block;
parameter: type simple_name;

annotation_block: ANNOTATION_BLOCK_BEGIN annotations ANNOTATION_BLOCK_END;

annotations: annotations COMMA annotation;
annotations: annotation;

annotation: SCOPE annotation_qualified_name argument_list;
annotation: annotation_qualified_name argument_list;

annotation_qualified_name: annotation_qualified_name SCOPE IDENT;
annotation_qualified_name: IDENT;

argument_list: LEFT_PARENTHESIS positional_arguments COMMA named_arguments RIGHT_PARENTHESIS;
argument_list: LEFT_PARENTHESIS named_arguments RIGHT_PARENTHESIS;
argument_list: LEFT_PARENTHESIS positional_arguments RIGHT_PARENTHESIS;
argument_list: LEFT_PARENTHESIS RIGHT_PARENTHESIS;

named_arguments: named_arguments COMMA named_argument;
named_arguments: named_argument;

positional_arguments: positional_arguments COMMA positional_argument;
positional_arguments: positional_argument;

named_argument: simple_name COLON assignment_expression;

positional_argument: assignment_expression;

comma_expression: assignment_expression COMMA comma_expression;
comma_expression: assignment_expression;

assignment_expression: lvalue_postfix_expression ASSIGN_OP assignment_expression;
assignment_expression: lvalue_postfix_expression BITWISE_OR_ASSIGN_OP assignment_expression;
assignment_expression: lvalue_postfix_expression BITWISE_AND_ASSIGN_OP assignment_expression;
assignment_expression: lvalue_postfix_expression BITWISE_XOR_ASSIGN_OP assignment_expression;
assignment_expression: lvalue_postfix_expression SHIFT_LEFT_ASSIGN_OP assignment_expression;
assignment_expression: lvalue_postfix_expression SHIFT_RIGHT_ASSIGN_OP assignment_expression;
assignment_expression: lvalue_postfix_expression UNSIGNED_SHIFT_RIGHT_ASSIGN_OP assignment_expression;
assignment_expression: lvalue_postfix_expression MULTIPLY_ASSIGN_OP assignment_expression;
assignment_expression: lvalue_postfix_expression DIVIDE_ASSIGN_OP assignment_expression;
assignment_expression: lvalue_postfix_expression MODULO_ASSIGN_OP assignment_expression;
assignment_expression: lvalue_postfix_expression PLUS_ASSIGN_OP assignment_expression;
assignment_expression: lvalue_postfix_expression MINUS_ASSIGN_OP assignment_expression;
assignment_expression: conditional_expression;

conditional_expression: logical_or_expression CONDITIONAL_OP comma_expression COLON assignment_expression;
conditional_expression: logical_or_expression;

logical_or_expression: logical_or_expression LOGICAL_OR_OP logical_and_expression;
logical_or_expression: logical_and_expression;

logical_and_expression: logical_and_expression LOGICAL_AND_OP inclusive_or_expression;
logical_and_expression: inclusive_or_expression;

inclusive_or_expression: inclusive_or_expression BITWISE_OR_OP exclusive_or_expression;
inclusive_or_expression: exclusive_or_expression;

exclusive_or_expression: exclusive_or_expression BITWISE_XOR_OP and_expression;
exclusive_or_expression: and_expression;

and_expression: and_expression BITWISE_AND_OP equality_expression;
and_expression: equality_expression;

equality_expression: equality_expression EQUAL_OP relational_expression;
equality_expression: equality_expression NOT_EQUAL_OP relational_expression;
equality_expression: relational_expression;

relational_expression: relational_expression LEFT_ANGLE_BRACKET shift_expression;
relational_expression: relational_expression LESS_OR_EQUAL_OP shift_expression;
relational_expression: relational_expression GREATER_OR_EQUAL_OP shift_expression;
relational_expression: relational_expression RIGHT_ANGLE_BRACKET shift_expression;
relational_expression: shift_expression;

shift_expression: shift_expression SHIFT_LEFT_OP additive_expression;
shift_expression: shift_expression SHIFT_RIGHT_OP  additive_expression;
shift_expression: shift_expression UNSIGNED_SHIFT_RIGHT_OP additive_expression;
shift_expression: additive_expression;

additive_expression: additive_expression POSITIVE_OP multiplicative_expression;
additive_expression: additive_expression NEGATIVE_OP multiplicative_expression;
additive_expression: multiplicative_expression;

multiplicative_expression: multiplicative_expression STAR unary_expression; 
multiplicative_expression: multiplicative_expression DIVIDE_OP unary_expression; 
multiplicative_expression: multiplicative_expression MODULO_OP unary_expression; 
multiplicative_expression: unary_expression;

unary_expression: BITWISE_COMPLEMENT_OP unary_expression;
unary_expression: LOGICAL_NOT_OP unary_expression;
unary_expression: POSITIVE_OP unary_expression;
unary_expression: NEGATIVE_OP unary_expression;
unary_expression: INCREMENT_OP unary_expression;
unary_expression: DECREMENT_OP unary_expression;
unary_expression: postfix_expression;
unary_expression: let_expression;

postfix_expression: rvalue_postfix_expression;
postfix_expression: lvalue_postfix_expression;

let_expression: LET variable_declaration IN unary_expression;
let_expression: LET LEFT_CURLY_BRACE variable_declarations RIGHT_CURLY_BRACE IN unary_expression;

rvalue_postfix_expression: rvalue_postfix_expression INCREMENT_OP;
rvalue_postfix_expression: rvalue_postfix_expression DECREMENT_OP;
rvalue_postfix_expression: rvalue_postfix_expression DOT simple_name;
rvalue_postfix_expression: rvalue_postfix_expression argument_list;
rvalue_postfix_expression: rvalue_postfix_expression LEFT_SQUARE_BRACKET comma_expression RIGHT_SQUARE_BRACKET;
rvalue_postfix_expression: rvalue_primary_expression;

rvalue_primary_expression: cast_expression;
rvalue_primary_expression: constructor_expression; 
rvalue_primary_expression: literal_expression;
rvalue_primary_expression: LEFT_PARENTHESIS comma_expression RIGHT_PARENTHESIS;

cast_expression: CAST LEFT_ANGLE_BRACKET type RIGHT_ANGLE_BRACKET LEFT_PARENTHESIS unary_expression RIGHT_PARENTHESIS;

constructor_expression: array_type argument_list;
constructor_expression: simple_type argument_list;

literal_expression: boolean_literal;
literal_expression: integer_literal;
literal_expression: floating_literal;
literal_expression: string_literal;

lvalue_postfix_expression: lvalue_postfix_expression_with_index_operation;
lvalue_postfix_expression: lvalue_postfix_expression_without_index_operation;

lvalue_postfix_expression_with_index_operation: array_type_or_lvalue DOT simple_name;
lvalue_postfix_expression_with_index_operation: array_type_or_lvalue LEFT_SQUARE_BRACKET comma_expression RIGHT_SQUARE_BRACKET;
lvalue_postfix_expression_with_index_operation: array_type_or_lvalue;

lvalue_postfix_expression_without_index_operation: lvalue_postfix_expression_without_index_operation DOT simple_name;
lvalue_postfix_expression_without_index_operation: simple_type_or_lvalue {
    MDLFrontend_HashVariableName(pUserData, $1);
    MDLFrontend_DisposeString(pUserData, $1);
};

boolean_literal: TRUE;
boolean_literal: FALSE;

integer_literal: INTEGER_LITERAL;

floating_literal: FRACT_LITERAL;
floating_literal: FLOATING_LITERAL;
floating_literal: DOUBLE_LITERAL;

string_literal: string_literal STRING_LITERAL;
string_literal: STRING_LITERAL;

type: VARYING array_type;
type: UNIFORM array_type;
type: array_type;
type: VARYING simple_type;
type: UNIFORM simple_type;
type: simple_type;

array_type: SCOPE builtin_type LEFT_SQUARE_BRACKET LEFT_ANGLE_BRACKET simple_name RIGHT_ANGLE_BRACKET RIGHT_SQUARE_BRACKET;
array_type: SCOPE builtin_type LEFT_SQUARE_BRACKET conditional_expression RIGHT_SQUARE_BRACKET;
array_type: SCOPE builtin_type LEFT_SQUARE_BRACKET RIGHT_SQUARE_BRACKET;
array_type: SCOPE type_or_variable_qualified_name LEFT_SQUARE_BRACKET LEFT_ANGLE_BRACKET simple_name RIGHT_ANGLE_BRACKET RIGHT_SQUARE_BRACKET;
array_type: SCOPE type_or_variable_qualified_name LEFT_SQUARE_BRACKET RIGHT_SQUARE_BRACKET;
array_type: builtin_type LEFT_SQUARE_BRACKET LEFT_ANGLE_BRACKET simple_name RIGHT_ANGLE_BRACKET RIGHT_SQUARE_BRACKET;
array_type: builtin_type LEFT_SQUARE_BRACKET conditional_expression RIGHT_SQUARE_BRACKET;
array_type: builtin_type LEFT_SQUARE_BRACKET RIGHT_SQUARE_BRACKET;
array_type: type_or_variable_qualified_name LEFT_SQUARE_BRACKET LEFT_ANGLE_BRACKET simple_name RIGHT_ANGLE_BRACKET RIGHT_SQUARE_BRACKET;
array_type: type_or_variable_qualified_name LEFT_SQUARE_BRACKET RIGHT_SQUARE_BRACKET;
array_type: array_type_or_lvalue; //Use action to analyze further //Only support conditional_expression for array_type  

array_type_or_lvalue: SCOPE type_or_variable_qualified_name LEFT_SQUARE_BRACKET comma_expression RIGHT_SQUARE_BRACKET; 
array_type_or_lvalue: type_or_variable_qualified_name LEFT_SQUARE_BRACKET comma_expression RIGHT_SQUARE_BRACKET;

simple_type: SCOPE builtin_type;
simple_type: builtin_type;
simple_type: simple_type_or_lvalue {
    MDLFrontend_HashTypeName(pUserData, $1);
    MDLFrontend_DisposeString(pUserData, $1);
};

simple_type_or_lvalue: SCOPE type_or_variable_qualified_name {
    $$ = MDLFrontend_StringAppend2(pUserData, MDLFrontend_CreateString(pUserData, "::"), $2);
    MDLFrontend_DisposeString(pUserData, $2);
};
simple_type_or_lvalue: type_or_variable_qualified_name {
    $$ = $1;
}

builtin_type: BOOL;
builtin_type: BOOL2;
builtin_type: BOOL3;
builtin_type: BOOL4;
builtin_type: INT;
builtin_type: INT2;
builtin_type: INT3;
builtin_type: INT4;
builtin_type: FLOAT;
builtin_type: FLOAT2;
builtin_type: FLOAT3;
builtin_type: FLOAT4;
builtin_type: FLOAT2X2;
builtin_type: FLOAT2X3;
builtin_type: FLOAT2X4;
builtin_type: FLOAT3X2;
builtin_type: FLOAT3X3;
builtin_type: FLOAT3X4;
builtin_type: FLOAT4X2;
builtin_type: FLOAT4X3;
builtin_type: FLOAT4X4; 
builtin_type: DOUBLE;
builtin_type: DOUBLE2;
builtin_type: DOUBLE3; 
builtin_type: DOUBLE4;
builtin_type: DOUBLE2X2;
builtin_type: DOUBLE2X3;
builtin_type: DOUBLE2X4; 
builtin_type: DOUBLE3X2;
builtin_type: DOUBLE3X3;
builtin_type: DOUBLE3X4;
builtin_type: DOUBLE4X2;
builtin_type: DOUBLE4X3; 
builtin_type: DOUBLE4X4; 
builtin_type: COLOR;
builtin_type: STRING;
builtin_type: SDF;
builtin_type: EDF;
builtin_type: VDF;
builtin_type: LIGHT_PROFILE;
builtin_type: MATERIAL;
builtin_type: MATERIAL_EMISSION;
builtin_type: MATERIAL_GEOMETRY;
builtin_type: MATERIAL_SURFACE; 
builtin_type: MATERIAL_VOLUME;
builtin_type: TEXTURE_2D;
builtin_type: TEXTURE_3D; 
builtin_type: TEXTURE_CUBE; 
builtin_type: TEXTURE_PTEX;
builtin_type: BSDF_MEASUREMENT;
builtin_type: INTENSITY_MODE;
builtin_type: INTENSITY_RADIANT_EXITANCE;
builtin_type: INTENSITY_POWER;
builtin_type: HAIR_BSDF;

type_or_variable_qualified_name: type_or_variable_qualified_name SCOPE simple_name { 
    $$ = MDLFrontend_StringAppend3(pUserData, $1, "::", $3);
    MDLFrontend_DisposeString(pUserData, $3);
    };

type_or_variable_qualified_name: simple_name { $$ = $1; };

simple_name: IDENT { $$ = $1; } ;

//%%
