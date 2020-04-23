/***************************************************************************************************
 * Copyright (c) 2011-2019, NVIDIA CORPORATION. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *  * Neither the name of NVIDIA CORPORATION nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 **************************************************************************************************/


#if !defined(mi__mdl_COCO_PARSER_H__)
#define mi__mdl_COCO_PARSER_H__

#include <cstring>
#include <cmath>

#include <mdl/compiler/compilercore/compilercore_mdl.h>
#include <mdl/compiler/compilercore/compilercore_allocator.h>
#include <mdl/compiler/compilercore/compilercore_wchar_support.h>
#include <mdl/compiler/compilercore/compilercore_errors.h>

#define ERR_TYPE ((IType_name *)1)
#define ERR_EXPR ((IExpression *)1)
#define ERR_STMT ((IStatement *)1)
#define ERR_DECL ((IDeclaration *)1)


#include "Scanner.h"

#ifdef _BOOL
// ICC predefines this as "1"
#undef _BOOL
#endif

#ifdef _COMMA
// defined by something in the VC11 build
#undef _COMMA
#endif

namespace mi {
namespace mdl {


class Parser {
public:
	enum {
		_EOF=0,
		_IDENT=1,
		_INTEGER_LITERAL=2,
		_FRACT_LITERAL=3,
		_FLOATING_LITERAL=4,
		_STRING_LITERAL=5,
		_IMPORT=6,
		_EXPORT=7,
		_USING=8,
		_EQUAL=9,
		_COMMA=10,
		_SEMICOLON=11,
		_DOT=12,
		_DOTDOT=13,
		_COLON=14,
		_SCOPE=15,
		_QUESTION=16,
		_LEFT_PARENTHESIS=17,
		_RIGHT_PARENTHESIS=18,
		_STAR=19,
		_PLUS=20,
		_MINUS=21,
		_TILDE=22,
		_BANG=23,
		_INC_OP=24,
		_DEC_OP=25,
		_CAST=26,
		_LEFT_SQUARE_BRACKET=27,
		_RIGHT_SQUARE_BRACKET=28,
		_ANNOTATION_BLOCK_BEGIN=29,
		_UNIFORM=30,
		_VARYING=31,
		_BOOL=32,
		_BOOL2=33,
		_BOOL3=34,
		_BOOL4=35,
		_INT=36,
		_INT2=37,
		_INT3=38,
		_INT4=39,
		_FLOAT=40,
		_FLOAT2=41,
		_FLOAT3=42,
		_FLOAT4=43,
		_FLOAT2X2=44,
		_FLOAT2X3=45,
		_FLOAT2X4=46,
		_FLOAT3X2=47,
		_FLOAT3X3=48,
		_FLOAT3X4=49,
		_FLOAT4X2=50,
		_FLOAT4X3=51,
		_FLOAT4X4=52,
		_DOUBLE=53,
		_DOUBLE2=54,
		_DOUBLE3=55,
		_DOUBLE4=56,
		_DOUBLE2X2=57,
		_DOUBLE2X3=58,
		_DOUBLE2X4=59,
		_DOUBLE3X2=60,
		_DOUBLE3X3=61,
		_DOUBLE3X4=62,
		_DOUBLE4X2=63,
		_DOUBLE4X3=64,
		_DOUBLE4X4=65,
		_COLOR=66,
		_STRING=67,
		_BSDF=68,
		_EDF=69,
		_VDF=70,
		_LIGHT_PROFILE=71,
		_TEXTURE_2D=72,
		_TEXTURE_3D=73,
		_TEXTURE_CUBE=74,
		_TEXTURE_PTEX=75,
		_BSDF_MEASUREMENT=76,
		_INTENSITY_MODE=77,
		_INTENSITY_RADIANT_EXITANCE=78,
		_INTENSITY_POWER=79,
		_MATERIAL=80,
		_MATERIAL_EMISSION=81,
		_MATERIAL_GEOMETRY=82,
		_MATERIAL_SURFACE=83,
		_MATERIAL_VOLUME=84,
		_MODULE=85,
		_TRUE=86,
		_FALSE=87,
		_HAIR_BSDF=88,
		_R_RESERVED=89,
		maxT=138,
		noSym = 138
	};

private:
	Token *dummyToken;
	int errDist;
	int minErrDist;

	void SynErr(int n);
	void Get();
	void Expect(int n);
	bool StartOf(int s);
	void ExpectWeak(int n, int follow);
	bool WeakSeparator(int n, int syFol, int repFol);

public:
	Scanner *scanner;
	Errors  *errors;

	Token *t;			// last recognized token
	Token *la;			// lookahead token

IAllocator *m_alloc;

    MDL *m_mdl;

    IName_factory *m_name_factory;

    IType_factory *m_type_factory;

    IValue_factory *m_value_factory;

    IExpression_factory *m_expression_factory;

    IStatement_factory *m_statement_factory;

    IDeclaration_factory *m_declaration_factory;

    IAnnotation_factory *m_annotation_factory;

    void set_imdl(IAllocator *alloc, MDL *imdl)
    {
        m_alloc = alloc;
        m_mdl = imdl;
        m_type_factory = m_mdl->get_type_factory();
    }

    Module *m_module;
    bool m_enable_experimental_features;

    void set_module(Module *module, bool enable_experimental_features)
    {
        m_module                       = module;
        m_enable_experimental_features = enable_experimental_features;
        m_name_factory                 = m_module->get_name_factory();
        m_type_factory                 = m_module->get_type_factory();
        m_expression_factory           = m_module->get_expression_factory();
        m_value_factory                = m_module->get_value_factory();
        m_statement_factory            = m_module->get_statement_factory();
        m_declaration_factory          = m_module->get_declaration_factory();
        m_annotation_factory           = m_module->get_annotation_factory();
    }

    Module *get_module()
    {
        return m_module;
    }

    // Parses an expression instead of a full MDL document.
    IExpression const *parse_expression()
    {
        IExpression const *expr = NULL;

        t = NULL;
        la = dummyToken = scanner->CreateToken();
        la->val = L"Dummy Token";
        Get();
        expression(expr);
        Expect(0);

        return expr;
    }

    // Check if the lookahead token is a comma.
    bool see_comma()
    {
        return la->kind == _COMMA;
    }

    // Skip square brackets.
    bool skip_square_brackets(Token *&x)
    {
        for(;;) {
            x = scanner->Peek();
            if (x->kind == _LEFT_SQUARE_BRACKET) {
                if (!skip_square_brackets(x))
                    return false;
            } else if (x->kind == _RIGHT_SQUARE_BRACKET) {
                x = scanner->Peek();
                return true;
            } else if (x->kind == _EOF) {
                break;
            }
        }
        return false;
    }

    // Skip a type.
    bool skip_type(Token *&x)
    {
        if ((x->kind == _UNIFORM) || (x->kind == _VARYING))
            x = scanner->Peek();
        switch (x->kind) {
        case _SCOPE:
            x = scanner->Peek();
            return skip_type(x);
        case _IDENT:
            x = scanner->Peek();
            if (x->kind == _SCOPE) {
                x = scanner->Peek();
                return skip_type(x);
            } else if (x->kind == _LEFT_SQUARE_BRACKET) {
                return skip_square_brackets(x);
            }
            return true;
        case _BOOL:
        case _BOOL2:
        case _BOOL3:
        case _BOOL4:
        case _INT:
        case _INT2:
        case _INT3:
        case _INT4:
        case _FLOAT:
        case _FLOAT2:
        case _FLOAT3:
        case _FLOAT4:
        case _FLOAT2X2:
        case _FLOAT2X3:
        case _FLOAT2X4:
        case _FLOAT3X2:
        case _FLOAT3X3:
        case _FLOAT3X4:
        case _FLOAT4X2:
        case _FLOAT4X3:
        case _FLOAT4X4:
        case _DOUBLE:
        case _DOUBLE2:
        case _DOUBLE3:
        case _DOUBLE4:
        case _DOUBLE2X2:
        case _DOUBLE2X3:
        case _DOUBLE2X4:
        case _DOUBLE3X2:
        case _DOUBLE3X3:
        case _DOUBLE3X4:
        case _DOUBLE4X2:
        case _DOUBLE4X3:
        case _DOUBLE4X4:
        case _COLOR:
        case _STRING:
        case _BSDF:
        case _EDF:
        case _VDF:
        case _LIGHT_PROFILE:
        case _TEXTURE_2D:
        case _TEXTURE_3D:
        case _TEXTURE_CUBE:
        case _TEXTURE_PTEX:
        case _BSDF_MEASUREMENT:
        case _INTENSITY_MODE:
        case _MATERIAL:
        case _MATERIAL_EMISSION:
        case _MATERIAL_GEOMETRY:
        case _MATERIAL_SURFACE:
        case _MATERIAL_VOLUME:
        case _HAIR_BSDF:
            x = scanner->Peek();
            if (x->kind == _LEFT_SQUARE_BRACKET)
                return skip_square_brackets(x);
            return true;
        default:
            return false;
        }
    }

    // If we see either "import" or "using" or "export" followed by "import" or "using"
    // during lookeahed, we assume that the declaration is an import declaration.
    bool is_import_declaration()
    {
        scanner->ResetPeek();
        Token *x = la;
        if (x->kind == _EXPORT) {
            x = scanner->Peek();
        }
        return (x->kind == _IMPORT) || (x->kind == _USING);
    }

    // If we see a type followed by an identifier during lookahead,
    // we assume that this is a declaration.
    bool is_declaration()
    {
        scanner->ResetPeek();
        Token *x = la;
        if (!skip_type(x))
            return false;
        return (x->kind == _IDENT) || (x->kind == _ANNOTATION_BLOCK_BEGIN);
    }

    /// Check for C-style cast: We have already seen '(' expr '), check for start(postfix_expr)
    bool is_c_style_cast()
    {
        scanner->ResetPeek();
        Token *x = la;
        if (x->kind != _LEFT_PARENTHESIS)
            return false;
        x = scanner->Peek();
        if (!skip_type(x))
            return false;
        if (x->kind != _RIGHT_PARENTHESIS)
            return false;
        x = scanner->Peek();

        switch (x->kind) {
        // start of unary expression
        case _TILDE:
        case _BANG:
        case _PLUS:
        case _MINUS:
        case _INC_OP:
        case _DEC_OP:
        case _CAST:
        // start of primary expression (subset of unary)
        case _TRUE:
        case _FALSE:
        case _INTEGER_LITERAL:
        case _FLOATING_LITERAL:
        case _FRACT_LITERAL:
        case _STRING_LITERAL:
        case _SCOPE:
        case _BOOL:
        case _BOOL2:
        case _BOOL3:
        case _BOOL4:
        case _INT:
        case _INT2:
        case _INT3:
        case _INT4:
        case _FLOAT:
        case _FLOAT2:
        case _FLOAT3:
        case _FLOAT4:
        case _FLOAT2X2:
        case _FLOAT2X3:
        case _FLOAT2X4:
        case _FLOAT3X2:
        case _FLOAT3X3:
        case _FLOAT3X4:
        case _FLOAT4X2:
        case _FLOAT4X3:
        case _FLOAT4X4:
        case _DOUBLE:
        case _DOUBLE2:
        case _DOUBLE3:
        case _DOUBLE4:
        case _DOUBLE2X2:
        case _DOUBLE2X3:
        case _DOUBLE2X4:
        case _DOUBLE3X2:
        case _DOUBLE3X3:
        case _DOUBLE3X4:
        case _DOUBLE4X2:
        case _DOUBLE4X3:
        case _DOUBLE4X4:
        case _COLOR:
        case _STRING:
        case _BSDF:
        case _EDF:
        case _VDF:
        case _LIGHT_PROFILE:
        case _TEXTURE_2D:
        case _TEXTURE_3D:
        case _TEXTURE_CUBE:
        case _TEXTURE_PTEX:
        case _BSDF_MEASUREMENT:
        case _INTENSITY_MODE:
        case _MATERIAL:
        case _MATERIAL_EMISSION:
        case _MATERIAL_GEOMETRY:
        case _MATERIAL_SURFACE:
        case _MATERIAL_VOLUME:
        case _HAIR_BSDF:
        case _IDENT:
            return true;
        case _LEFT_PARENTHESIS:
            // while '(' is a start of a primary expression, do not treat it as a c-style cast
            // here:
            // (t)(f) *is* legal
            return false;
        default:
            return false;
        }
    }

    // If we see an identifier followed by a colon during lookeahed,
    // we assume that the argument is named.
    bool is_named_argument()
    {
        scanner->ResetPeek();
        Token *x = la;
        if (x->kind == _COMMA)
            x = scanner->Peek();
        if (x->kind == _IDENT) {
            x = scanner->Peek();
            return x->kind == _COLON;
        } else {
            return false;
        }
    }

    // Check if the next two tokens are coupled right brackets
    bool is_anno_block_end()
    {
        scanner->ResetPeek();
        if (la->kind == _RIGHT_SQUARE_BRACKET) {
            int line = la->line;
            int col  = la->col;
            Token *x = scanner->Peek();
            if (x->kind != _RIGHT_SQUARE_BRACKET)
                return false;
            return line == x->line && col + 1 == x->col;
        }
        return false;
    }

    // Check if the next two tokens are '[' and ']
    bool is_array_constructor()
    {
        scanner->ResetPeek();
        if (la->kind == _LEFT_SQUARE_BRACKET) {
            Token *x = scanner->Peek();
            if (x->kind == _RIGHT_SQUARE_BRACKET)
                return true;
        }
        return false;
    }

    // Check if the next three tokens are '(', '*', and ')'.
    bool is_clone()
    {
        scanner->ResetPeek();
        if (la->kind == _LEFT_PARENTHESIS) {
            Token *x = scanner->Peek();
            if (x->kind == _STAR) {
                x = scanner->Peek();
                if (x->kind == _RIGHT_PARENTHESIS)
                    return true;
            }
        }
        return false;
    }

    // Check if we see '::' and IDENT
    bool is_scope_ident()
    {
        scanner->ResetPeek();
        Token *x = la;
        if (x->kind != _SCOPE)
            return false;
        x = scanner->Peek();
        return x->kind == _IDENT;
    }

    // Create a simple name from a token.
    ISimple_name const *to_simple(Token const *t)
    {
        string tmp(m_alloc);
        wchar_t const *s = errDist > 0 ? t->val : L"<ERROR>";
        ISymbol const *symbol = m_name_factory->create_symbol(wchar_to_utf8(tmp, s));
        return m_name_factory->create_simple_name(
                    symbol,
                    t->line,
                    t->col,
                    t->line,
                    t->col + wcslen(t->val) - 1);
    }

    // Create a qualified name from a simple name.
    IQualified_name *to_qualified(ISimple_name const *simple_name)
    {
        IQualified_name *qualified_name = m_name_factory->create_qualified_name();
        qualified_name->add_component(simple_name);
        return qualified_name;
    }

    // Create a qualified error name.
    IQualified_name *qualified_error()
    {
        ISymbol const *symbol = m_name_factory->create_symbol("<ERROR>");
        ISimple_name const *simple_name = m_name_factory->create_simple_name(
                    symbol,
                    t->line,
                    t->col,
                    t->line,
                    t->col);
        return to_qualified(simple_name);
    }

    // Create a type name from a type name prefix and a token.
    IType_name *to_type(IType_name *prefix, Token *tok)
    {
        IType_name *type_name = prefix;
        IQualified_name *qualified_name;

        if (type_name) {
            qualified_name = type_name->get_qualified_name();
        } else {
            qualified_name = m_name_factory->create_qualified_name();
            type_name = m_name_factory->create_type_name(qualified_name, tok->line, tok->col);
        }
        ISimple_name const *simple_name = to_simple(tok);
        qualified_name->add_component(simple_name);
        Position &tpos = type_name->access_position();
        Position const &qpos = qualified_name->access_position();
        tpos.set_end_line(qpos.get_end_line());
        tpos.set_end_column(qpos.get_end_column());
        return type_name;
    }

    // Create a type name from a simple name.
    IType_name *to_type(ISimple_name const *simple_name)
    {
        IQualified_name *qualified_name = to_qualified(simple_name);
        IType_name *type_name = m_name_factory->create_type_name(qualified_name);
        Position &q_pos = qualified_name->access_position();
        Position &t_pos = type_name->access_position();
        t_pos.set_start_line(q_pos.get_start_line());
        t_pos.set_start_column(q_pos.get_start_column());
        t_pos.set_end_line(q_pos.get_end_line());
        t_pos.set_end_column(q_pos.get_end_column());
        return type_name;
    }

    // Create a reference from a type name.
    IExpression_reference const *to_reference(
        IType_name const *type_name,
        bool             is_array_con = false)
    {
        IExpression_reference *result = m_expression_factory->create_reference(type_name);
        if (is_array_con)
            result->set_array_constructor();
        Position const &t_pos = type_name->access_position();
        Position &r_pos = result->access_position();
        r_pos.set_start_line(t_pos.get_start_line());
        r_pos.set_start_column(t_pos.get_start_column());
        r_pos.set_end_line(t_pos.get_end_line());
        r_pos.set_end_column(t_pos.get_end_column());
        return result;
    }

    // Create a reference from a simple name.
    IExpression_reference const *to_reference(ISimple_name const *simple_name)
    {
        return to_reference(to_type(simple_name));
    }

    // Create a statement from an expression.
    IStatement_expression const *to_statement(IExpression const *exp)
    {
        exp = check_expr(exp);
        IStatement_expression *result = m_statement_factory->create_expression(exp);
        if (exp != NULL) {
            Position const &pos = exp->access_position();
            Position &r_pos = result->access_position();
            r_pos.set_start_line(pos.get_start_line());
            r_pos.set_start_column(pos.get_start_column());
            r_pos.set_end_line(pos.get_end_line());
            r_pos.set_end_column(pos.get_end_column());
        }
        return result;
    }

    // Create an integer value.
    static wchar_t const *integer_value(wchar_t const *val, bool &overflow, unsigned long &value)
    {
        int base = 0;
        unsigned long res = 0;
        unsigned long maxv = 0, maxd = 0;
        overflow = false;

        wchar_t const *s = val;
        if (*s == L'0') {
            ++s;
            if (*s == L'x' || *s == L'X') {
                ++s;
                base = 16;
                maxv = 0x10000000;  // 0x10000000 * 16 + 0 = 0x100000000
            } else if (*s == L'b' || *s == L'B') {
                ++s;
                base = 2;
                maxv = 0x80000000;  // 0x80000000 *  2 + 0 = 0x100000000
            } else {
                base = 8;
                maxv = 0x20000000;  // 0x20000000 *  8 + 0 = 0x100000000
            }
        } else {
            base = 10;
            maxv = 0x19999999;      // 0x19999999 * 10 + 6 = 0x100000000
            maxd = 6;
        }

        for (;;) {
            unsigned long digit = 16;
            switch (*s) {
            case L'0': digit = 0; break;
            case L'1': digit = 1; break;
            case L'2': digit = 2; break;
            case L'3': digit = 3; break;
            case L'4': digit = 4; break;
            case L'5': digit = 5; break;
            case L'6': digit = 6; break;
            case L'7': digit = 7; break;
            case L'8': digit = 8; break;
            case L'9': digit = 9; break;
            case L'a': digit = 10; break;
            case L'b': digit = 11; break;
            case L'c': digit = 12; break;
            case L'd': digit = 13; break;
            case L'e': digit = 14; break;
            case L'f': digit = 15; break;
            case L'A': digit = 10; break;
            case L'B': digit = 11; break;
            case L'C': digit = 12; break;
            case L'D': digit = 13; break;
            case L'E': digit = 14; break;
            case L'F': digit = 15; break;
            default: goto out;
            }

            // beware of C++ semantics: gcc will optimize simple overflow tests away :-(
            if (res >= maxv && digit >= maxd)
                overflow = true;

            res *= base;
            res += digit;
            ++s;
        }
    out:
        /* ignore overflow on sign bit, this cannot be checked reliable here
        if (res >= 0x80000000) {
            // overflow on sign bit
            overflow = true;
        }
        */
        value = res;
        return s;
    }

    // Check an expression.
    IType_name *check_type(IType_name *type) {
        if (type == ERR_TYPE) {
            IQualified_name *q_name = qualified_error();
            IType_name *result = m_name_factory->create_type_name(q_name);
            Position const &t_pos = q_name->access_position();
            Position &r_pos = result->access_position();
            r_pos.set_start_line(t_pos.get_start_line());
            r_pos.set_start_column(t_pos.get_start_column());
            r_pos.set_end_line(t_pos.get_end_line());
            r_pos.set_end_column(t_pos.get_end_column());
            return result;
        }
        return type;
    }

    // Check an expression.
    IExpression const *check_expr(IExpression const *expr) {
        if (expr == ERR_EXPR)
            return m_expression_factory->create_invalid(
                    t->line,
                    t->col,
                    t->line,
                    t->col);
        return expr;
    }

    // Make an invalid expression from onother expression.
    IExpression const *make_invalid(Position const &pos) {
        return m_expression_factory->create_invalid(
            pos.get_start_line(),
            pos.get_start_column(),
            pos.get_end_line(),
            pos.get_end_column());
    }

    // Check a statement.
    IStatement const *check_stmt(IStatement const *stmt) {
        if (stmt == ERR_STMT)
            return m_statement_factory->create_invalid(
                    t->line,
                    t->col,
                    t->line,
                    t->col);
        return stmt;
    }

    // Check a declaration.
    IDeclaration const *check_decl(IDeclaration const *decl) {
        if (decl == ERR_DECL)
            return m_declaration_factory->create_invalid(
                    /*exported=*/false,
                    t->line,
                    t->col,
                    t->line,
                    t->col);
        return decl;
    }

    // Create an unary expression.
    IExpression_unary *create_unary(
        IExpression_unary::Operator const op,
        IExpression const                 *argument)
    {
        argument = check_expr(argument);
        Position const &pos = argument->access_position();
        IExpression_unary *expr = m_expression_factory->create_unary(
                                                            op,
                                                            argument,
                                                            pos.get_start_line(),
                                                            pos.get_start_column(),
                                                            pos.get_end_line(),
                                                            pos.get_end_column());
        return expr;
    }

    // Create a binary expression.
    IExpression_binary *create_binary(
        IExpression_binary::Operator const op,
        IExpression const                  *left,
        IExpression const                  *right)
    {
        left  = check_expr(left);
        right = check_expr(right);
        IExpression_binary *expr = m_expression_factory->create_binary(op, left, right);
        Position const &l_pos = left->access_position();
        Position const &r_pos = right->access_position();
        Position &e_pos = expr->access_position();
        e_pos.set_start_line(l_pos.get_start_line());
        e_pos.set_start_column(l_pos.get_start_column());
        e_pos.set_end_line(r_pos.get_end_line());
        e_pos.set_end_column(r_pos.get_end_column());
        return expr;
    }

    // Create a conditional expression.
    IExpression_conditional *create_conditional(
        IExpression const *cond,
        IExpression const *true_exp,
        IExpression const *false_exp)
    {
        cond  = check_expr(cond);
        true_exp = check_expr(true_exp);
        false_exp = check_expr(false_exp);
        Position const &s_pos = cond->access_position();
        Position const &e_pos = false_exp->access_position();
        return m_expression_factory->create_conditional(
            cond,
            true_exp,
            false_exp,
            s_pos.get_start_line(),
            s_pos.get_start_column(),
            e_pos.get_end_line(),
            e_pos.get_end_column());
    }

    // Create a positional argument.
    IArgument_positional const *create_positional_argument(IExpression const *expr)
    {
        expr = check_expr(expr);
        Position const &e_pos = expr->access_position();
        return m_expression_factory->create_positional_argument(
                expr,
                e_pos.get_start_line(),
                e_pos.get_start_column(),
                e_pos.get_end_line(),
                e_pos.get_end_column());
    }

    // Create a named argument.
    IArgument_named const *create_named_argument(
        ISimple_name const *parameter_name,
        IExpression const  *expr)
    {
        expr = check_expr(expr);
        Position const &p_pos = parameter_name->access_position();
        Position const &e_pos = expr->access_position();
        return m_expression_factory->create_named_argument(
            parameter_name,
            expr,
            p_pos.get_start_line(),
            p_pos.get_start_column(),
            e_pos.get_end_line(),
            e_pos.get_end_column());
    }

    // Create a parameter.
    IParameter const *create_parameter(
        int                     sl,
        int                     sc,
        IType_name const        *type_name,
        ISimple_name const      *name,
        IExpression const       *init,
        IAnnotation_block const *annotations)
    {
        init = check_expr(init);
        Position const &t_pos = type_name->access_position();
        int start_line = sl ? sl : t_pos.get_start_line();
        int start_column = sc ? sc : t_pos.get_start_column();
        int end_line = t_pos.get_end_line();
        int end_column = t_pos.get_end_line();
        if (annotations) {
            Position const &a_pos = annotations->access_position();
            end_line = a_pos.get_end_line();
            end_column = a_pos.get_end_column();
        } else if (init) {
            Position const &i_pos = init->access_position();
            end_line = i_pos.get_end_line();
            end_column = i_pos.get_end_column();
        }
        IParameter const *param = m_declaration_factory->create_parameter(
                                        type_name,name,init,annotations,
                                        start_line,start_column,end_line,end_column);
        return param;
    }

    // Create a declaration.
    IStatement_declaration *create_declaration(IDeclaration const *decl)
    {
        decl = check_decl(decl);
        IStatement_declaration *stmnt = m_statement_factory->create_declaration(decl);
        Position const &d_pos = decl->access_position();
        Position &s_pos = stmnt->access_position();
        s_pos.set_start_line(d_pos.get_start_line());
        s_pos.set_start_column(d_pos.get_start_column());
        s_pos.set_end_line(d_pos.get_end_line());
        s_pos.set_end_column(d_pos.get_end_column());
        return stmnt;
    }

    // Add a declaration.
    void add_declaration(IDeclaration const *decl)
    {
        decl = check_decl(decl);
        m_module->add_declaration(decl);
    }

    // Add an annotation.
    static void add_annotation(
        IAnnotation_block *&annotations,
        IAnnotation const *anno)
    {
        // just ignore wrong annotations
        if (anno != NULL)
            annotations->add_annotation(anno);
    }

    // Mark that an expression was in parenthesis.
    static void mark_parenthesis(IExpression const *exp)
    {
      if (exp != ERR_EXPR)
          const_cast<IExpression *>(exp)->mark_parenthesis();
    }

    // Convert escape sequences in string literals amnd skip quaotes.
    string convert_escape_sequences_skip_quotes(wchar_t const *ws)
    {
        size_t l = wcslen(ws);
        wstring res(m_alloc);
        res.reserve(l - 2);

        wchar_t const *p = ws + 1;     // skip first quote
        wchar_t const *e = ws + l - 1; // skip last quote

        while (p < e) {
            if (*p == '\\') {
                ++p;
                wchar_t wc = *p;
                switch (wc) {
                case L'a': res += '\a'; ++p; break;
                case L'b': res += '\b'; ++p; break;
                case L'f': res += '\f'; ++p; break;
                case L'n': res += '\n'; ++p; break;
                case L'r': res += '\r'; ++p; break;
                case L't': res += '\t'; ++p; break;
                case L'v': res += '\v'; ++p; break;
                case L'\\': res += '\\'; ++p; break;
                case L'\'': res += '\''; ++p; break;
                case L'"': res += '"'; ++p; break;
                case L'0':
                case L'1':
                case L'2':
                case L'3':
                case L'4':
                case L'5':
                case L'6':
                case L'7':
                    {
                        unsigned code = 0;
                        bool exit = false;
                        do {
                            switch (*p) {
                            case L'0': code = code * 8 + 0; break;
                            case L'1': code = code * 8 + 1; break;
                            case L'2': code = code * 8 + 2; break;
                            case L'3': code = code * 8 + 3; break;
                            case L'4': code = code * 8 + 4; break;
                            case L'5': code = code * 8 + 5; break;
                            case L'6': code = code * 8 + 6; break;
                            case L'7': code = code * 8 + 7; break;
                            default: --p; exit = true; break;
                            }
                            ++p;
                         } while (!exit);
                         res += wchar_t(code);
                    }
                    break;
                case L'x':
                case L'u':
                case L'U':
                    {
                        unsigned code = 0;
                        unsigned range = 0x10FFFF;

                        if (code == L'x')
                            range = 0xFF;
                        else if (code == L'u')
                            range = 0xFFFF;
                        bool exit = false;
                        bool overrun = false;
                        ++p;
                        wchar_t const *start = p;
                        if (!isxdigit(*p)) {
                            wchar_t wbuf[32];
                            swprintf(wbuf, 32, L"\\%c used with no following hex digits", wc);

                            errors->Warning(t->line, int(t->col + p - ws), wbuf);
                            res += *p;
                         } else {
                            do {
                                switch (*p) {
                                case L'0': code = code * 16 + 0; break;
                                case L'1': code = code * 16 + 1; break;
                                case L'2': code = code * 16 + 2; break;
                                case L'3': code = code * 16 + 3; break;
                                case L'4': code = code * 16 + 4; break;
                                case L'5': code = code * 16 + 5; break;
                                case L'6': code = code * 16 + 6; break;
                                case L'7': code = code * 16 + 7; break;
                                case L'8': code = code * 16 + 8; break;
                                case L'9': code = code * 16 + 9; break;
                                case L'a':
                                case L'A': code = code * 16 + 10; break;
                                case L'b':
                                case L'B': code = code * 16 + 11; break;
                                case L'c':
                                case L'C': code = code * 16 + 12; break;
                                case L'd':
                                case L'D': code = code * 16 + 13; break;
                                case L'e':
                                case L'E': code = code * 16 + 14; break;
                                case L'f':
                                case L'F': code = code * 16 + 15; break;
                                default: --p; exit = true; break;
                                }
                                if (code > range)
                                    overrun = true;
                                ++p;
                             } while (!exit);
                             if (overrun) {
                                 wchar_t wbuf[48];
                                 swprintf(wbuf, 48, L"\\%c escape sequence out of range", wc);

                                 errors->Warning(t->line, int(t->col + p - start), wbuf);
                             }
                             res += wchar_t(code);
                         }
                    }
                    break;
                case L'\0':
                    res += wc; ++p; break;
                default:
                    {
                        wchar_t wbuf[32];
                        swprintf(wbuf, 32, L"Unknown escape sequence '\\%c'", wc);
                        errors->Warning(t->line, int(t->col + p - ws), wbuf);
                        res += wc; ++p;
                    }
                    break;
                }
            } else {
                res += *p;
                ++p;
            }
        }
        string tmp(m_alloc);
        res.reserve(l - 2);
        wchar_to_utf8(tmp, res.c_str());
        return tmp;
    }

    // The type of vectors of parameters.
    typedef vector<IParameter const *>::Type Parameter_vector;

    // A class for adding arguments to either a call or an annotation.
    class Argument_owner
    {
        public:
            // Constructor.
            // \param call  the call expression to which arguments should be added
            Argument_owner(IExpression_call *call)
            : m_call(call)
            , m_anno(NULL)
            {}

            // Constructor.
            // \param anno  the annotation to which arguments should be added
            Argument_owner(IAnnotation *anno)
            : m_call(NULL)
            , m_anno(anno)
            {}

            // Add the given argument to the call or annotation provided with the constructor.
            void add_argument(IArgument const *arg)
            {
                if (m_call != NULL)
                    m_call->add_argument(arg);
                else if (m_anno != NULL)
                    m_anno->add_argument(arg);
            }

        private:
            // The call expression, or NULL if not used.
            IExpression_call *m_call;

            // The annotation, or NULL if not used.
            IAnnotation *m_anno;
    };



	Parser(Scanner *scanner, Errors *err);
	~Parser();
	void SemErr(const wchar_t* msg);

	void mdl();
	void mdl_version();
	void import(IDeclaration const *&declaration);
	void module_declaration(IDeclaration const *&declaration);
	void global_declaration(bool exported, IDeclaration const *&declaration);
	void boolean_literal(bool &value,int &sl,int &sc,int &el,int &ec);
	void integer_literal(unsigned long &value, int &sl, int &sc, int &el, int &ec);
	void fract_literal(int &major, int &minor);
	void floating_literal(double &value,int &sl,int &sc,int &el,int &ec,bool &is_float,bool &is_error);
	void string_literal(wchar_t const *&value,int &sl,int &sc,int &el,int &ec);
	void simple_name(ISimple_name const *&value);
	void qualified_import(IQualified_name *&value);
	void qualified_name(IQualified_name *&value);
	void qualified_import_prefix(IQualified_name *&value);
	void frequency_qualifier(Qualifier &qualifier,int &sl,int &sc);
	void relative_type(IType_name *prefix,IType_name *&name);
	void simple_type(IType_name *prefix,IType_name *&name);
	void array_type(IType_name *&name);
	void conditional_expression(IExpression const *&exp);
	void type(IType_name *&name);
	void parameter(IParameter const *&parameter);
	void assignment_expression(IExpression const *&exp);
	void annotation_block(IAnnotation_block *&annos);
	void parameter_list(Parameter_vector &parameters);
	void positional_argument(IArgument const *&arg);
	void named_argument(IArgument const *&arg);
	void argument_list(Argument_owner &arg_owner);
	void annotation_declaration(bool exported, IDeclaration const *&declaration);
	void constant_declaration(bool exported, IDeclaration const *&declaration);
	void type_declaration(bool exported, IDeclaration const *&declaration);
	void function_declaration(bool exported, IDeclaration const *&declaration);
	void constant_declarator(IDeclaration_constant *declaration);
	void alias_type_declaration(bool exported, IDeclaration const *&declaration);
	void struct_type_declaration(bool exported, IDeclaration const *&declaration);
	void enum_type_declaration(bool exported, IDeclaration const *&declaration);
	void struct_field_declarator(IDeclaration_type_struct *declaration);
	void expression(IExpression const *&exp);
	void enum_value_declarator(IDeclaration_type_enum *declaration);
	void variable_declarator(IDeclaration_variable *declaration);
	void variable_declaration(bool exported, IDeclaration const *&declaration);
	void compound_statement(const IStatement *&stmnt);
	void annotation(IAnnotation *&anno);
	void statement(IStatement const *&stmnt);
	void if_statement(IStatement const *&stmnt);
	void switch_statement(IStatement const *&stmnt);
	void while_statement(IStatement const *&stmnt);
	void do_statement(IStatement const *&stmnt);
	void for_statement(IStatement const *&stmnt);
	void break_statement(IStatement const *&stmnt);
	void continue_statement(IStatement const *&stmnt);
	void return_statement(IStatement const *&stmnt);
	void expression_statement(IStatement const *&stmnt);
	void switch_case(IStatement const *&stmnt);
	void literal_expression(IExpression const *&exp);
	void primary_expression(IExpression const *&exp);
	void cast_expression(IExpression const *&exp);
	void unary_expression(IExpression const *&exp);
	void postfix_expression(IExpression const *&exp);
	void let_expression(IExpression const *&exp);
	void multiplicative_expression(IExpression const *&exp);
	void additive_expression(IExpression const *&exp);
	void shift_expression(IExpression const *&exp);
	void relational_expression(IExpression const *&exp);
	void equality_expression(IExpression const *&exp);
	void and_expression(IExpression const *&exp);
	void exclusive_or_expression(IExpression const *&exp);
	void inclusive_or_expression(IExpression const *&exp);
	void logical_and_expression(IExpression const *&exp);
	void logical_or_expression(IExpression const *&exp);
	void assignment_operator(IExpression_binary::Operator &op);

	void Parse();

}; // end Parser

} // namespace
} // namespace


#endif

