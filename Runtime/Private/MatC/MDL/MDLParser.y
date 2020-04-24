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
%token <_IDENT> IDENT
%token <_INTEGER_LITERAL> INTEGER_LITERAL 
%token <_FLOATING_LITERAL> FLOATING_LITERAL

// Define the nonterminals 
%type <_null> mdl 
%type <_decl> import_declaration;

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

mdl_version: MDL FLOATING_LITERAL SEMICOLON;

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

simple_name: IDENT;

module_declaration: MODULE annotation_block SEMICOLON;
module_declaration: MODULE SEMICOLON;

variable_declaration: type variable_declarators SEMICOLON;

variable_declarators: variable_declarators COMMA variable_declarator;
variable_declarators: variable_declarator;

variable_declarator: simple_name argument_list annotation_block;
variable_declarator: simple_name argument_list;
variable_declarator: simple_name ASSIGN_OP assignment_expression annotation_block;
variable_declarator: simple_name ASSIGN_OP assignment_expression;
variable_declarator: simple_name annotation_block;
variable_declarator: simple_name;

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

qualified_name: SCOPE qualified_name_infix;
qualified_name: qualified_name_infix;

annotation: qualified_name argument_list;

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

// Operators in MDL are right associative 
// To see compilercore_parser.atg

comma_expression: assignment_expression COMMA comma_expression;
comma_expression: assignment_expression;

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
assignment_expression: conditional_expression;

conditional_expression: logical_or_expression CONDITIONAL_OP comma_expression COLON assignment_expression;
conditional_expression: logical_or_expression;

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

relational_expression: shift_expression LEFT_ANGLE_BRACKET relational_expression;
relational_expression: shift_expression LESS_OR_EQUAL_OP relational_expression;
relational_expression: shift_expression GREATER_OR_EQUAL_OP relational_expression;
relational_expression: shift_expression RIGHT_ANGLE_BRACKET relational_expression;
relational_expression: shift_expression;

shift_expression: additive_expression SHIFT_LEFT_OP shift_expression;
shift_expression: additive_expression SHIFT_RIGHT_OP shift_expression;
shift_expression: additive_expression UNSIGNED_SHIFT_RIGHT_OP shift_expression;
shift_expression: additive_expression;

additive_expression: multiplicative_expression POSITIVE_OP additive_expression;
additive_expression: multiplicative_expression NEGATIVE_OP additive_expression;
additive_expression: multiplicative_expression;

multiplicative_expression: unary_expression STAR multiplicative_expression; 
multiplicative_expression: unary_expression DIVIDE_OP multiplicative_expression; 
multiplicative_expression: unary_expression MODULO_OP multiplicative_expression; 
multiplicative_expression: unary_expression;

unary_expression: BITWISE_COMPLEMENT_OP unary_expression;
unary_expression: LOGICAL_NOT_OP unary_expression;
unary_expression: POSITIVE_OP unary_expression;
unary_expression: NEGATIVE_OP unary_expression;
unary_expression: INCREMENT_OP unary_expression;
unary_expression: DECREMENT_OP unary_expression;
unary_expression: postfix_expression;
unary_expression: let_expression;


postfix_expression: postfix_expression INCREMENT_OP;
postfix_expression: postfix_expression DECREMENT_OP;
postfix_expression: postfix_expression DOT simple_name;
postfix_expression: postfix_expression argument_list;
postfix_expression: postfix_expression LEFT_SQUARE_BRACKET comma_expression RIGHT_SQUARE_BRACKET; /* [-Wconflicts-sr] */
postfix_expression: primary_expression;
postfix_expression: cast_expression;

primary_expression: array_type;
/* primary_expression: simple_type LEFT_SQUARE_BRACKET RIGHT_SQUARE_BRACKET;   [-Wconflicts-sr] */
/* primary_expression: simple_type;  [-Wconflicts-sr] */
primary_expression: literal_expression;
primary_expression: LEFT_PARENTHESIS comma_expression RIGHT_PARENTHESIS;

cast_expression: CAST LEFT_ANGLE_BRACKET type RIGHT_ANGLE_BRACKET LEFT_PARENTHESIS unary_expression RIGHT_PARENTHESIS;

let_expression: LET variable_declaration IN unary_expression;
let_expression: LET LEFT_CURLY_BRACE variable_declarations RIGHT_CURLY_BRACE IN unary_expression;

literal_expression: boolean_literal;
literal_expression: integer_literal;
literal_expression: floating_literal;
literal_expression: string_literal;

boolean_literal: TRUE;
boolean_literal: FALSE;

integer_literal: INTEGER_LITERAL;

floating_literal: FLOATING_LITERAL;

string_literal: string_literal STRING_LITERAL;
string_literal: STRING_LITERAL;

type: VARYING array_type;
type: UNIFORM array_type;
type: array_type;

array_type: simple_type LEFT_SQUARE_BRACKET LEFT_ANGLE_BRACKET simple_name RIGHT_ANGLE_BRACKET RIGHT_SQUARE_BRACKET;
array_type: simple_type LEFT_SQUARE_BRACKET conditional_expression RIGHT_SQUARE_BRACKET;
array_type: simple_type LEFT_SQUARE_BRACKET RIGHT_SQUARE_BRACKET;
array_type: simple_type;

simple_type: SCOPE relative_type;
simple_type: relative_type;

relative_type: BOOL;
relative_type: BOOL2;
relative_type: BOOL3;
relative_type: BOOL4;
relative_type: INT;
relative_type: INT2;
relative_type: INT3;
relative_type: INT4;
relative_type: FLOAT;
relative_type: FLOAT2;
relative_type: FLOAT3;
relative_type: FLOAT4;
relative_type: FLOAT2X2;
relative_type: FLOAT2X3;
relative_type: FLOAT2X4;
relative_type: FLOAT3X2;
relative_type: FLOAT3X3;
relative_type: FLOAT3X4;
relative_type: FLOAT4X2;
relative_type: FLOAT4X3;
relative_type: FLOAT4X4; 
relative_type: DOUBLE;
relative_type: DOUBLE2;
relative_type: DOUBLE3; 
relative_type: DOUBLE4;
relative_type: DOUBLE2X2;
relative_type: DOUBLE2X3;
relative_type: DOUBLE2X4; 
relative_type: DOUBLE3X2;
relative_type: DOUBLE3X3;
relative_type: DOUBLE3X4;
relative_type: DOUBLE4X2;
relative_type: DOUBLE4X3; 
relative_type: DOUBLE4X4; 
relative_type: COLOR;
relative_type: STRING;
relative_type: SDF;
relative_type: EDF;
relative_type: VDF;
relative_type: LIGHT_PROFILE;
relative_type: MATERIAL;
relative_type: MATERIAL_EMISSION;
relative_type: MATERIAL_GEOMETRY;
relative_type: MATERIAL_SURFACE; 
relative_type: MATERIAL_VOLUME;
relative_type: TEXTURE_2D;
relative_type: TEXTURE_3D; 
relative_type: TEXTURE_CUBE; 
relative_type: TEXTURE_PTEX;
relative_type: BSDF_MEASUREMENT;
relative_type: INTENSITY_MODE;
relative_type: INTENSITY_RADIANT_EXITANCE;
relative_type: INTENSITY_POWER;
relative_type: HAIR_BSDF;
relative_type: qualified_name_infix;

//%%
