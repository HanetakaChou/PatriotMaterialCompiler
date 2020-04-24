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
%token PLUS_OP
%token MINUS_OP
%token DIVIDE_OP
%token MODULO_OP
%token BITWISE_COMPLEMENT_OP
%token LOGICAL_NOT_OP
%token POSITIVE_OP
%token NEGATIVE_OP
%token PRE_INCREMENT_OP
%token PRE_DECREMENT_OP
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

annotation_block: ANNOTATION_BLOCK_BEGIN annotations ANNOTATION_BLOCK_END;

annotations: annotations COMMA annotation;
annotations: annotation;

annotation: qualified_name argument_list;

qualified_name: SCOPE qualified_name_infix;
qualified_name: qualified_name_infix;

argument_list: LEFT_PARENTHESIS named_arguments RIGHT_PARENTHESIS;

named_arguments: named_arguments COMMA named_argument;
named_arguments: named_argument;

named_argument: simple_name COLON assignment_expression;

// Operators in MDL are right associative 
// To see compilercore_parser.atg

comma_expression: assignment_expression COMMA comma_expression;
comma_expression: assignment_expression;

assignment_expression: conditional_expression;
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

conditional_expression: logical_or_expression CONDITIONAL_OP comma_expression COLON assignment_expression;

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

additive_expression: multiplicative_expression PLUS_OP additive_expression;
additive_expression: multiplicative_expression MINUS_OP additive_expression;
additive_expression: multiplicative_expression;

multiplicative_expression: unary_expression STAR multiplicative_expression; 
multiplicative_expression: unary_expression DIVIDE_OP multiplicative_expression; 
multiplicative_expression: unary_expression MODULO_OP multiplicative_expression; 
multiplicative_expression: unary_expression;

unary_expression: postfix_expression;
unary_expression: BITWISE_COMPLEMENT_OP unary_expression;
unary_expression: LOGICAL_NOT_OP unary_expression;
unary_expression: POSITIVE_OP unary_expression;
unary_expression: NEGATIVE_OP unary_expression;
unary_expression: PRE_INCREMENT_OP unary_expression;
unary_expression: PRE_DECREMENT_OP unary_expression;

postfix_expression: primary_expression;

primary_expression: literal_expression;
primary_expression: simple_type;
primary_expression: simple_type LEFT_SQUARE_BRACKET RIGHT_SQUARE_BRACKET;
primary_expression: LEFT_PARENTHESIS comma_expression RIGHT_PARENTHESIS;

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

/*
type: VARYING array_type;
type: UNIFORM array_type;
type: array_type;

array_type: simple_type LEFT_SQUARE_BRACKET RIGHT_SQUARE_BRACKET;
array_type: simple_type LEFT_SQUARE_BRACKET conditional_expression RIGHT_SQUARE_BRACKET;
array_type: simple_type LEFT_SQUARE_BRACKET LEFT_ANGLE_BRACKET simple_name RIGHT_ANGLE_BRACKET RIGHT_SQUARE_BRACKET;
*/

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
