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


#include <wchar.h>
#include "Parser.h"
#include "Scanner.h"


namespace mi {
namespace mdl {


void Parser::SynErr(int n) {
	if (errDist >= minErrDist) errors->SynErr(la, n);
	errDist = 0;
}

void Parser::SemErr(const wchar_t* msg) {
	if (errDist >= minErrDist) errors->Error(t, msg);
	errDist = 0;
}

void Parser::Get() {
	for (;;) {
		t = la;
		la = scanner->Scan();
		if (la->kind <= maxT) { ++errDist; break; }

		if (dummyToken != t) {
			dummyToken->kind = t->kind;
			dummyToken->pos = t->pos;
			dummyToken->col = t->col;
			dummyToken->line = t->line;
			dummyToken->next = NULL;
			dummyToken->val = t->val;
			t = dummyToken;
		}
		la = t;
	}
}

void Parser::Expect(int n) {
	if (la->kind==n) Get(); else { SynErr(n); }
}

void Parser::ExpectWeak(int n, int follow) {
	if (la->kind == n) Get();
	else {
		SynErr(n);
		while (!StartOf(follow)) Get();
	}
}

bool Parser::WeakSeparator(int n, int syFol, int repFol) {
	if (la->kind == n) {Get(); return true;}
	else if (StartOf(repFol)) {return false;}
	else {
		SynErr(n);
		while (!(StartOf(syFol) || StartOf(repFol) || StartOf(0))) {
			Get();
		}
		return StartOf(syFol);
	}
}

void Parser::mdl() {
		mdl_version();
		while (is_import_declaration()) {
			IDeclaration const *declaration = ERR_DECL; 
			import(declaration);
			add_declaration(declaration); 
		}
		if (la->kind == _MODULE) {
			IDeclaration const *declaration = ERR_DECL; 
			module_declaration(declaration);
			add_declaration(declaration); 
		}
		while (StartOf(1)) {
			bool exported = false; 
			if (la->kind == _EXPORT) {
				Get();
				exported = true; 
			}
			IDeclaration const *declaration = ERR_DECL; 
			global_declaration(exported, declaration);
			add_declaration(declaration); 
		}
}

void Parser::mdl_version() {
		Expect(90 /* "mdl" */);
		int major = 0, minor = 0;
		
		fract_literal(major,minor);
		if (errDist > 0) {
		   bool res = m_module->set_version(
		       m_mdl,
		       major,
		       minor,
		       m_enable_experimental_features);
		   if (!res) {
		       errors->Error(
		           t->line, t->col,
		           UNSUPPORTED_MDL_VERSION,
		           Error_params(m_alloc)
		               .add(major)
		               .add(minor));
		   } else {
		       scanner->set_mdl_version(major, minor);
		   }
		}
		
		while (!(la->kind == _EOF || la->kind == _SEMICOLON)) {SynErr(139); Get();}
		Expect(_SEMICOLON);
}

void Parser::import(IDeclaration const *&declaration) {
		if (la->kind == _IMPORT) {
			Get();
			IQualified_name *qual_name = NULL;
			IDeclaration_import *import
			   = m_declaration_factory
			       ->create_import(0,
			                       false,
			                       t->line,
			                       t->col);
			
			qualified_import(qual_name);
			import->add_name(qual_name); 
			while (WeakSeparator(_COMMA,3,2) ) {
				qualified_import(qual_name);
				import->add_name(qual_name); 
			}
			while (!(la->kind == _EOF || la->kind == _SEMICOLON)) {SynErr(140); Get();}
			Expect(_SEMICOLON);
			Position &pos = import->access_position();
			pos.set_end_line(t->line);
			pos.set_end_column(t->col);
			declaration = import;
			
		} else if (la->kind == _EXPORT || la->kind == _USING) {
			bool exported = false; 
			if (la->kind == _EXPORT) {
				Get();
				exported = true; 
			}
			IQualified_name *module_name = NULL;
			ISimple_name const *simp_name = NULL;
			
			Expect(_USING);
			int sl = t->line, sc = t->col; 
			qualified_import_prefix(module_name);
			IDeclaration_import *import
			   = m_declaration_factory
			       ->create_import(module_name,
			                       exported,
			                       sl,
			                       sc);
			
			Expect(_IMPORT);
			if (la->kind == _STAR) {
				Get();
				import->add_name(to_qualified(to_simple(t))); 
			} else if (la->kind == _IDENT) {
				simple_name(simp_name);
				import->add_name(to_qualified(simp_name));
				
				while (WeakSeparator(_COMMA,4,2) ) {
					simple_name(simp_name);
					import->add_name(to_qualified(simp_name));
					
				}
			} else SynErr(141);
			while (!(la->kind == _EOF || la->kind == _SEMICOLON)) {SynErr(142); Get();}
			Expect(_SEMICOLON);
			Position &pos = import->access_position();
			pos.set_end_line(t->line);
			pos.set_end_column(t->col);
			declaration = import;
			
		} else SynErr(143);
}

void Parser::module_declaration(IDeclaration const *&declaration) {
		IAnnotation_block *annos = NULL;
		int sl = t->line;
		int sc = t->col;
		
		Expect(_MODULE);
		if (la->kind == _ANNOTATION_BLOCK_BEGIN) {
			annotation_block(annos);
		}
		Expect(_SEMICOLON);
		declaration = m_declaration_factory->create_module(
		   annos,
		   sl,
		   sc,
		   t->line,
		   t->col);
		
}

void Parser::global_declaration(bool exported, IDeclaration const *&declaration) {
		if (la->kind == 93 /* "annotation" */) {
			annotation_declaration(exported,declaration);
		} else if (la->kind == 94 /* "const" */) {
			constant_declaration(exported,declaration);
		} else if (la->kind == 95 /* "typedef" */ || la->kind == 96 /* "struct" */ || la->kind == 99 /* "enum" */) {
			type_declaration(exported,declaration);
		} else if (StartOf(5)) {
			function_declaration(exported,declaration);
		} else SynErr(144);
}

void Parser::boolean_literal(bool &value,int &sl,int &sc,int &el,int &ec) {
		if (la->kind == _TRUE) {
			Get();
			value = true;
			sl = t->line;
			sc = t->col;
			el = t->line;
			ec = t->col + wcslen(t->val) - 1;
			
		} else if (la->kind == _FALSE) {
			Get();
			value = false;
			sl = t->line;
			sc = t->col;
			el = t->line;
			ec = t->col + wcslen(t->val) - 1;
			
		} else SynErr(145);
}

void Parser::integer_literal(unsigned long &value, int &sl, int &sc, int &el, int &ec) {
		Expect(_INTEGER_LITERAL);
		bool overflow = false;
		integer_value(t->val, overflow, value);
		if (overflow)
		   errors->Warning(
		       t->line, t->col, L"Integer constant overflow");
		sl = t->line;
		sc = t->col;
		el = t->line;
		ec = t->col + wcslen(t->val) - 1;
		
}

void Parser::fract_literal(int &major, int &minor) {
		Expect(_FRACT_LITERAL);
		bool overflow = false, ov = false;
		unsigned long v;
		
		wchar_t const *dot = integer_value(t->val, ov, v);
		overflow |= ov;
		major = v;
		
		ov = false;
		integer_value(dot + 1, ov, v);
		overflow |= ov;
		if (overflow)
		   errors->Warning(
		       t->line, t->col, L"Integer constant overflow");
		
		minor = v;
		
}

void Parser::floating_literal(double &value,int &sl,int &sc,int &el,int &ec,bool &is_float,bool &is_error) {
		if (la->kind == _FLOATING_LITERAL) {
			Get();
		} else if (la->kind == _FRACT_LITERAL) {
			Get();
		} else SynErr(146);
		if (errDist > 0) {
		   wchar_t *end;
		   value = wcstod(t->val,&end);
		   if (value == HUGE_VAL || value == -HUGE_VAL) {
		       errors->Error(
		           t->line, t->col,
		           CONSTANT_TOO_BIG,
		           Error_params(m_alloc));
		   }
		   switch (*end) {
		   case 'f': case 'F': is_float = true; ++end; break;
		   case 'd': case 'D': is_float = false; ++end; break;
		   case '\0': is_float = true; break;
		   }
		   if (*end)
		       fprintf(
		           stderr,
		           "failed to convert floating literal '%ls'\n",
		           t->val);
		   sl = t->line;
		   sc = t->col;
		   el = t->line;
		   ec = t->col + wcslen(t->val) - 1;
		   is_error = false;
		} else {
		   is_error = true;
		   value = 0.0;
		}
		
}

void Parser::string_literal(wchar_t const *&value,int &sl,int &sc,int &el,int &ec) {
		Expect(_STRING_LITERAL);
		value = t->val;
		sl = t->line;
		sc = t->col;
		el = t->line;
		ec = t->col + wcslen(t->val) - 1;
		
}

void Parser::simple_name(ISimple_name const *&value) {
		Expect(_IDENT);
		value = to_simple(t); 
}

void Parser::qualified_import(IQualified_name *&value) {
		value = m_name_factory->create_qualified_name();
		ISimple_name const *simp_name = NULL;
		
		if (la->kind == _DOT || la->kind == _DOTDOT || la->kind == _SCOPE) {
			if (la->kind == _DOT) {
				Get();
				value->add_component(to_simple(t)); 
				Expect(_SCOPE);
			} else if (la->kind == _DOTDOT) {
				Get();
				value->add_component(to_simple(t)); 
				Expect(_SCOPE);
				while (la->kind == _DOTDOT) {
					Get();
					value->add_component(to_simple(t)); 
					Expect(_SCOPE);
				}
			} else {
				Get();
				value->set_absolute(); 
			}
		}
		simple_name(simp_name);
		value->add_component(simp_name);
		
		while (is_scope_ident()) {
			Expect(_SCOPE);
			simple_name(simp_name);
			value->add_component(simp_name);
			
		}
		if (la->kind == _SCOPE) {
			Get();
			Expect(_STAR);
			value->add_component(to_simple(t)); 
		}
}

void Parser::qualified_name(IQualified_name *&value) {
		value = m_name_factory->create_qualified_name();
		ISimple_name const *simp_name = NULL;
		
		if (la->kind == _SCOPE) {
			Get();
			value->set_absolute(); 
		}
		simple_name(simp_name);
		value->add_component(simp_name);
		
		while (la->kind == _SCOPE) {
			Get();
			simple_name(simp_name);
			value->add_component(simp_name);
			
		}
}

void Parser::qualified_import_prefix(IQualified_name *&value) {
		value = m_name_factory->create_qualified_name();
		ISimple_name const *simp_name = NULL;
		
		if (la->kind == _DOT || la->kind == _DOTDOT || la->kind == _SCOPE) {
			if (la->kind == _DOT) {
				Get();
				value->add_component(to_simple(t)); 
				Expect(_SCOPE);
			} else if (la->kind == _DOTDOT) {
				Get();
				value->add_component(to_simple(t)); 
				Expect(_SCOPE);
				while (la->kind == _DOTDOT) {
					Get();
					value->add_component(to_simple(t)); 
					Expect(_SCOPE);
				}
			} else {
				Get();
				value->set_absolute(); 
			}
		}
		simple_name(simp_name);
		value->add_component(simp_name);
		
		while (la->kind == _SCOPE) {
			Get();
			simple_name(simp_name);
			value->add_component(simp_name);
			
		}
}

void Parser::frequency_qualifier(Qualifier &qualifier,int &sl,int &sc) {
		if (la->kind == _VARYING) {
			Get();
			qualifier = FQ_VARYING;
			sl = t->line;
			sc = t->col;
			
		} else if (la->kind == _UNIFORM) {
			Get();
			qualifier = FQ_UNIFORM;
			sl = t->line;
			sc = t->col;
			
		} else SynErr(147);
}

void Parser::relative_type(IType_name *prefix,IType_name *&name) {
		switch (la->kind) {
		case _BOOL: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _BOOL2: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _BOOL3: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _BOOL4: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _INT: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _INT2: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _INT3: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _INT4: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _FLOAT: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _FLOAT2: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _FLOAT3: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _FLOAT4: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _FLOAT2X2: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _FLOAT2X3: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _FLOAT2X4: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _FLOAT3X2: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _FLOAT3X3: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _FLOAT3X4: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _FLOAT4X2: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _FLOAT4X3: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _FLOAT4X4: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _DOUBLE: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _DOUBLE2: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _DOUBLE3: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _DOUBLE4: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _DOUBLE2X2: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _DOUBLE2X3: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _DOUBLE2X4: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _DOUBLE3X2: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _DOUBLE3X3: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _DOUBLE3X4: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _DOUBLE4X2: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _DOUBLE4X3: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _DOUBLE4X4: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _COLOR: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _STRING: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _BSDF: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _EDF: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _VDF: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _LIGHT_PROFILE: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _MATERIAL: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _MATERIAL_EMISSION: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _MATERIAL_GEOMETRY: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _MATERIAL_SURFACE: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _MATERIAL_VOLUME: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _TEXTURE_2D: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _TEXTURE_3D: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _TEXTURE_CUBE: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _TEXTURE_PTEX: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _BSDF_MEASUREMENT: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _INTENSITY_MODE: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _INTENSITY_RADIANT_EXITANCE: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _INTENSITY_POWER: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _HAIR_BSDF: {
			Get();
			name = to_type(prefix, t); 
			break;
		}
		case _IDENT: {
			Get();
			name = to_type(prefix, t); 
			if (la->kind == _SCOPE) {
				Get();
				IType_name *name_cont = ERR_TYPE; 
				relative_type(name,name_cont);
				name = check_type(name_cont); 
			}
			break;
		}
		default: SynErr(148); break;
		}
}

void Parser::simple_type(IType_name *prefix,IType_name *&name) {
		bool is_absolute = false; 
		if (la->kind == _SCOPE) {
			Get();
			is_absolute = true; 
		}
		relative_type(prefix,name);
		name = check_type(name);
		if (is_absolute)
		   name->set_absolute();
		
}

void Parser::array_type(IType_name *&name) {
		simple_type(0,name);
		name = check_type(name); 
		if (la->kind == _LEFT_SQUARE_BRACKET) {
			ISimple_name const *size_name = NULL; 
			Get();
			name->set_incomplete_array(); 
			if (StartOf(6)) {
				if (StartOf(7)) {
					IExpression const *exp = NULL; 
					conditional_expression(exp);
					name->set_array_size(check_expr(exp)); 
				} else {
					Get();
					simple_name(size_name);
					Expect(92 /* ">" */);
					name->set_size_name(size_name); 
				}
			}
			Expect(_RIGHT_SQUARE_BRACKET);
			Position &pos = name->access_position();
			pos.set_end_line(t->line);
			pos.set_end_column(t->col);
			
		}
}

void Parser::conditional_expression(IExpression const *&exp) {
		exp = ERR_EXPR; 
		logical_or_expression(exp);
		exp = check_expr(exp); 
		if (la->kind == _QUESTION) {
			IExpression const *true_exp = ERR_EXPR,
			                 *false_exp = ERR_EXPR; 
			Get();
			expression(true_exp);
			Expect(_COLON);
			assignment_expression(false_exp);
			true_exp = check_expr(true_exp);
			false_exp = check_expr(false_exp);
			exp = m_expression_factory
			       ->create_conditional(
			           exp,
			           true_exp,
			           false_exp);
			
		}
}

void Parser::type(IType_name *&name) {
		Qualifier qualifier = FQ_NONE;
		int sl = 0, sc = 0;
		
		if (la->kind == _UNIFORM || la->kind == _VARYING) {
			frequency_qualifier(qualifier,sl,sc);
		}
		array_type(name);
		name = check_type(name);
		name->set_qualifier(qualifier);
		if (sl) {
		   Position &pos = name->access_position();
		   pos.set_start_line(sl);
		   pos.set_start_column(sc);
		}
		
}

void Parser::parameter(IParameter const *&parameter) {
		IType_name *type_name = ERR_TYPE;
		ISimple_name const *parameter_name = NULL;
		IExpression const *init_exp = NULL;
		IAnnotation_block *annos = NULL;
		int sl = 0, sc = 0;
		
		type(type_name);
		simple_name(parameter_name);
		if (la->kind == _EQUAL) {
			Get();
			assignment_expression(init_exp);
		}
		if (la->kind == _ANNOTATION_BLOCK_BEGIN) {
			annotation_block(annos);
		}
		parameter = create_parameter(
		               sl,
		               sc,
		               type_name,
		               parameter_name,
		               check_expr(init_exp),
		               annos);
		
}

void Parser::assignment_expression(IExpression const *&exp) {
		exp = ERR_EXPR; 
		logical_or_expression(exp);
		exp = check_expr(exp); 
		if (StartOf(8)) {
			if (la->kind == _QUESTION) {
				IExpression const *true_exp = ERR_EXPR;
				IExpression const *false_exp = ERR_EXPR;
				
				Get();
				expression(true_exp);
				Expect(_COLON);
				assignment_expression(false_exp);
				true_exp = check_expr(true_exp);
				false_exp = check_expr(false_exp);
				exp = create_conditional(
				           exp,
				           true_exp,
				           false_exp);
				
			} else {
				IExpression_binary::Operator op
				   = IExpression_binary::OK_ASSIGN;
				IExpression const *right = ERR_EXPR;
				
				assignment_operator(op);
				assignment_expression(right);
				right = check_expr(right);
				exp = create_binary(op,exp,right);
				
			}
		}
}

void Parser::annotation_block(IAnnotation_block *&annos) {
		Expect(_ANNOTATION_BLOCK_BEGIN);
		IAnnotation *anno = NULL;
		annos = m_annotation_factory
		           ->create_annotation_block(
		               t->line,
		               t->col);
		
		annotation(anno);
		add_annotation(annos,anno); 
		while (WeakSeparator(_COMMA,10,9) ) {
			annotation(anno);
			add_annotation(annos,anno); 
		}
		if (is_anno_block_end()) {
			Expect(_RIGHT_SQUARE_BRACKET);
			Expect(_RIGHT_SQUARE_BRACKET);
		} else if (false) {
			Expect(_RIGHT_SQUARE_BRACKET);
			Expect(_RIGHT_SQUARE_BRACKET);
			
		} else SynErr(149);
		Position &pos = anno->access_position();
		pos.set_end_line(t->line);
		pos.set_end_column(t->col);
		
}

void Parser::parameter_list(Parameter_vector &parameters) {
		Expect(_LEFT_PARENTHESIS);
		IParameter const *para = NULL; 
		if (StartOf(5)) {
			parameter(para);
			parameters.push_back(para); 
			while (WeakSeparator(_COMMA,5,11) ) {
				parameter(para);
				parameters.push_back(para); 
			}
		}
		Expect(_RIGHT_PARENTHESIS);
}

void Parser::positional_argument(IArgument const *&arg) {
		IExpression const *exp = NULL; 
		assignment_expression(exp);
		arg = create_positional_argument(exp);
		
}

void Parser::named_argument(IArgument const *&arg) {
		ISimple_name const *parameter_name = NULL;
		IExpression const  *exp = NULL;
		
		simple_name(parameter_name);
		Expect(_COLON);
		assignment_expression(exp);
		arg = create_named_argument(
		       parameter_name,
		       exp);
		
}

void Parser::argument_list(Argument_owner &arg_owner) {
		Expect(_LEFT_PARENTHESIS);
		IArgument const *argument = NULL; 
		if (StartOf(7)) {
			if (is_named_argument()) {
				named_argument(argument);
				arg_owner.add_argument(argument); 
				while (WeakSeparator(_COMMA,4,11) ) {
					named_argument(argument);
					arg_owner.add_argument(argument); 
				}
			} else {
				positional_argument(argument);
				arg_owner.add_argument(argument); 
				while (see_comma() && !is_named_argument()) {
					ExpectWeak(_COMMA, 12);
					positional_argument(argument);
					arg_owner.add_argument(argument); 
				}
				while (WeakSeparator(_COMMA,4,11) ) {
					named_argument(argument);
					arg_owner.add_argument(argument); 
				}
			}
		}
		Expect(_RIGHT_PARENTHESIS);
}

void Parser::annotation_declaration(bool exported, IDeclaration const *&declaration) {
		declaration = ERR_DECL;
		IAnnotation_block *annos = NULL;
		
		Expect(93 /* "annotation" */);
		ISimple_name const *annotation_name = NULL;
		Parameter_vector parameters(m_alloc);
		int sl = t->line;
		int sc = t->col;
		
		simple_name(annotation_name);
		parameter_list(parameters);
		if (la->kind == _ANNOTATION_BLOCK_BEGIN) {
			annotation_block(annos);
		}
		while (!(la->kind == _EOF || la->kind == _SEMICOLON)) {SynErr(150); Get();}
		Expect(_SEMICOLON);
		IDeclaration_annotation *annotation
		   = m_declaration_factory
		       ->create_annotation(
		           annotation_name,
		           annos,
		           exported,
		           sl,
		           sc,
		           t->line,
		           t->col);
		size_t count = parameters.size();
		for (size_t i = 0; i < count; ++i)
		   annotation->add_parameter(parameters[i]);
		declaration = annotation;
		
}

void Parser::constant_declaration(bool exported, IDeclaration const *&declaration) {
		declaration = ERR_DECL; 
		Expect(94 /* "const" */);
		IType_name *type_name = ERR_TYPE;
		int sl = t->line;
		int sc = t->col;
		
		type(type_name);
		IDeclaration_constant *constant_declaration
		   = m_declaration_factory
		       ->create_constant(
		           type_name,
		           exported,
		           sl,
		           sc);
		
		constant_declarator(constant_declaration);
		while (WeakSeparator(_COMMA,4,2) ) {
			constant_declarator(constant_declaration);
		}
		while (!(la->kind == _EOF || la->kind == _SEMICOLON)) {SynErr(151); Get();}
		Expect(_SEMICOLON);
		Position &pos
		   = constant_declaration
		       ->access_position();
		pos.set_end_line(t->line);
		pos.set_end_column(t->col);
		declaration = constant_declaration;
		
}

void Parser::type_declaration(bool exported, IDeclaration const *&declaration) {
		if (la->kind == 95 /* "typedef" */) {
			declaration = ERR_DECL; 
			alias_type_declaration(exported,declaration);
		} else if (la->kind == 96 /* "struct" */) {
			declaration = ERR_DECL; 
			struct_type_declaration(exported,declaration);
		} else if (la->kind == 99 /* "enum" */) {
			declaration = ERR_DECL; 
			enum_type_declaration(exported,declaration);
		} else SynErr(152);
}

void Parser::function_declaration(bool exported, IDeclaration const *&declaration) {
		declaration = ERR_DECL;
		IDeclaration_function *function = NULL;
		IType_name *ret_type = ERR_TYPE;
		ISimple_name const *function_name = NULL;
		IAnnotation_block *ret_annos = NULL;
		IAnnotation_block *fct_annos = NULL;
		Parameter_vector parameters(m_alloc);
		Qualifier qualifier = FQ_NONE;
		int sl = 0, sc = 0;
		
		type(ret_type);
		ret_type = check_type(ret_type); 
		if (la->kind == _ANNOTATION_BLOCK_BEGIN) {
			annotation_block(ret_annos);
		}
		simple_name(function_name);
		if (!is_clone()) {
			parameter_list(parameters);
			if (la->kind == _UNIFORM || la->kind == _VARYING) {
				frequency_qualifier(qualifier,sl,sc);
			}
			if (la->kind == _ANNOTATION_BLOCK_BEGIN) {
				annotation_block(fct_annos);
			}
			if (la->kind == _SEMICOLON) {
				Get();
				Position const &pos
				               = ret_type->access_position();
				function
				   = m_declaration_factory
				       ->create_function(
				           ret_type,
				           ret_annos,
				           function_name,
				           /*is_preset=*/false,
				           0,
				           fct_annos,
				           exported,
				           pos.get_start_line(),
				           pos.get_start_column(),
				           t->line,
				           t->col);
				size_t count = parameters.size();
				for (size_t i = 0; i < count; ++i)
				   function->add_parameter(parameters[i]);
				
			} else if (la->kind == 97 /* "{" */) {
				IStatement const *body = NULL; 
				compound_statement(body);
				body = check_stmt(body);
				int el = 0, ec = 0;
				if (fct_annos) {
				   Position const &pos
				           = fct_annos->access_position();
				   el = pos.get_end_line();
				   ec = pos.get_end_column();
				} else {
				   Position const &pos
				           = body->access_position();
				   el = pos.get_end_line();
				   ec = pos.get_end_column();
				}
				Position const &pos
				               = ret_type->access_position();
				function
				   = m_declaration_factory
				       ->create_function(
				           ret_type,
				           ret_annos,
				           function_name,
				           /*is_preset=*/false,
				           body,
				           fct_annos,
				           exported,
				           pos.get_start_line(),
				           pos.get_start_column(),
				           el,
				           ec);
				size_t count = parameters.size();
				for (size_t i = 0; i < count; ++i)
				   function->add_parameter(parameters[i]);
				
			} else if (la->kind == _EQUAL) {
				Get();
				IExpression const *init_exp = ERR_EXPR; 
				expression(init_exp);
				while (!(la->kind == _EOF || la->kind == _SEMICOLON)) {SynErr(153); Get();}
				Expect(_SEMICOLON);
				Position const &pos
				               = ret_type->access_position();
				function
				   = m_declaration_factory
				       ->create_function(
				           ret_type,
				           ret_annos,
				           function_name,
				           /*is_preset=*/false,
				           to_statement(init_exp),
				           fct_annos,
				           exported,
				           pos.get_start_line(),
				           pos.get_start_column(),
				           t->line,
				           t->col);
				size_t count = parameters.size();
				for (size_t i = 0; i < count; ++i)
				   function->add_parameter(parameters[i]);
				
			} else SynErr(154);
		} else if (la->kind == _LEFT_PARENTHESIS) {
			Get();
			Expect(_STAR);
			Expect(_RIGHT_PARENTHESIS);
			IExpression const *init_exp = ERR_EXPR; 
			if (la->kind == _ANNOTATION_BLOCK_BEGIN) {
				annotation_block(fct_annos);
			}
			Expect(_EQUAL);
			expression(init_exp);
			while (!(la->kind == _EOF || la->kind == _SEMICOLON)) {SynErr(155); Get();}
			Expect(_SEMICOLON);
			Position const &pos
			               = ret_type->access_position();
			function
			   = m_declaration_factory
			       ->create_function(
			           ret_type,
			           ret_annos,
			           function_name,
			           /*is_preset=*/true,
			           to_statement(init_exp),
			           fct_annos,
			           exported,
			           pos.get_start_line(),
			           pos.get_start_column(),
			           t->line,
			           t->col);
			
		} else SynErr(156);
		if (function) {
		   // no syntax error
		   function->set_qualifier(qualifier);
		   declaration = function;
		}
		
}

void Parser::constant_declarator(IDeclaration_constant *declaration) {
		ISimple_name const *constant_name = NULL;
		IExpression const *init_exp = ERR_EXPR;
		IAnnotation_block *annos = NULL;
		
		simple_name(constant_name);
		if (la->kind == _LEFT_PARENTHESIS) {
			Position const &start_pos =
			   constant_name->access_position();
			int sl = start_pos.get_start_line();
			int sc = start_pos.get_start_column();
			IType_name *tn = m_module->clone_name(
			   declaration->get_type_name(),
			   /*modifier=*/NULL);
			IExpression_call *call
			   = m_expression_factory
			       ->create_call(
			           to_reference(tn),
			           sl,
			           sc,
			           t->line,
			           t->col);
			Argument_owner arg_owner(call);
			
			argument_list(arg_owner);
			init_exp = call;
			
		} else if (la->kind == _EQUAL) {
			Get();
			conditional_expression(init_exp);
		} else SynErr(157);
		if (la->kind == _ANNOTATION_BLOCK_BEGIN) {
			annotation_block(annos);
		}
		declaration->add_constant(
		               constant_name,
		               check_expr(init_exp),
		               annos);
		
}

void Parser::alias_type_declaration(bool exported, IDeclaration const *&declaration) {
		declaration = ERR_DECL; 
		Expect(95 /* "typedef" */);
		IType_name *type_name = ERR_TYPE;
		ISimple_name const *alias_name = NULL;
		int sl = t->line;
		int sc = t->col;
		
		type(type_name);
		simple_name(alias_name);
		while (!(la->kind == _EOF || la->kind == _SEMICOLON)) {SynErr(158); Get();}
		Expect(_SEMICOLON);
		declaration
		   = m_declaration_factory
		       ->create_alias(
		           type_name,
		           alias_name,
		           exported,
		           sl,
		           sc,
		           t->line,
		           t->col);
		
}

void Parser::struct_type_declaration(bool exported, IDeclaration const *&declaration) {
		declaration = ERR_DECL; 
		Expect(96 /* "struct" */);
		ISimple_name const *struct_name = NULL;
		IAnnotation_block *annos = NULL;
		int sl = t->line;
		int sc = t->col;
		
		simple_name(struct_name);
		if (la->kind == _ANNOTATION_BLOCK_BEGIN) {
			annotation_block(annos);
		}
		IDeclaration_type_struct *struct_declaration
		   = m_declaration_factory
		       ->create_struct(
		           struct_name,
		           annos,
		           exported,
		           sl,
		           sc);
		
		Expect(97 /* "{" */);
		while (StartOf(5)) {
			struct_field_declarator(struct_declaration);
		}
		Expect(98 /* "}" */);
		while (!(la->kind == _EOF || la->kind == _SEMICOLON)) {SynErr(159); Get();}
		Expect(_SEMICOLON);
		Position &pos
		   = struct_declaration->access_position();
		pos.set_end_line(t->line);
		pos.set_end_column(t->col);
		declaration = struct_declaration;
		
}

void Parser::enum_type_declaration(bool exported, IDeclaration const *&declaration) {
		declaration = ERR_DECL; 
		Expect(99 /* "enum" */);
		ISimple_name const *enum_name = NULL;
		IAnnotation_block *annos = NULL;
		int sl = t->line;
		int sc = t->col;
		bool enum_class = false;
		
		simple_name(enum_name);
		if (la->kind == _ANNOTATION_BLOCK_BEGIN) {
			annotation_block(annos);
		}
		IDeclaration_type_enum *enum_declaration
		   = m_declaration_factory
		       ->create_enum(
		           enum_name,
		           annos,
		           exported,
		           enum_class,
		           sl,
		           sc);
		
		Expect(97 /* "{" */);
		enum_value_declarator(enum_declaration);
		while (WeakSeparator(_COMMA,4,13) ) {
			enum_value_declarator(enum_declaration);
		}
		Expect(98 /* "}" */);
		while (!(la->kind == _EOF || la->kind == _SEMICOLON)) {SynErr(160); Get();}
		Expect(_SEMICOLON);
		Position &pos
		   = enum_declaration->access_position();
		pos.set_end_line(t->line);
		pos.set_end_column(t->col);
		declaration = enum_declaration;
		
}

void Parser::struct_field_declarator(IDeclaration_type_struct *declaration) {
		IType_name *field_type = ERR_TYPE;
		ISimple_name const *field_name = NULL;
		IExpression const *init_exp = NULL;
		IAnnotation_block *annos = NULL;
		
		type(field_type);
		simple_name(field_name);
		if (la->kind == _EQUAL) {
			Get();
			init_exp = ERR_EXPR; 
			expression(init_exp);
		}
		if (la->kind == _ANNOTATION_BLOCK_BEGIN) {
			annotation_block(annos);
		}
		while (!(la->kind == _EOF || la->kind == _SEMICOLON)) {SynErr(161); Get();}
		Expect(_SEMICOLON);
		declaration->add_field(
		               field_type,
		               field_name,
		               check_expr(init_exp),
		               annos);
		
}

void Parser::expression(IExpression const *&exp) {
		exp = ERR_EXPR; 
		assignment_expression(exp);
		exp = check_expr(exp); 
		while (la->kind == _COMMA) {
			Get();
			IExpression const *right = NULL; 
			assignment_expression(right);
			right = check_expr(right);
			exp = create_binary(
			           IExpression_binary::OK_SEQUENCE,
			           exp,
			           right);
			
		}
}

void Parser::enum_value_declarator(IDeclaration_type_enum *declaration) {
		ISimple_name const *enum_value_name = NULL;
		IExpression const *init_exp = NULL;
		IAnnotation_block *annos = NULL;
		
		simple_name(enum_value_name);
		if (la->kind == _EQUAL) {
			Get();
			init_exp = ERR_EXPR; 
			assignment_expression(init_exp);
		}
		if (la->kind == _ANNOTATION_BLOCK_BEGIN) {
			annotation_block(annos);
		}
		declaration->add_value(
		               enum_value_name,
		               check_expr(init_exp),
		               annos);
		
}

void Parser::variable_declarator(IDeclaration_variable *declaration) {
		ISimple_name const *variable_name = NULL;
		IExpression const *init_exp = NULL;
		IAnnotation_block *annos = NULL;
		
		simple_name(variable_name);
		if (la->kind == _EQUAL || la->kind == _LEFT_PARENTHESIS) {
			if (la->kind == _LEFT_PARENTHESIS) {
				Position const &start_pos =
				   variable_name->access_position();
				int sl = start_pos.get_start_line();
				int sc = start_pos.get_start_column();
				IType_name *tn = m_module->clone_name(
				   declaration->get_type_name(),
				   /*modifier=*/NULL);
				IExpression_call *call
				   = m_expression_factory
				       ->create_call(
				           to_reference(tn),
				           sl,
				           sc,
				           t->line,
				           t->col);
				Argument_owner arg_owner(call);
				
				argument_list(arg_owner);
				init_exp = call;
				
			} else {
				Get();
				assignment_expression(init_exp);
			}
		}
		if (la->kind == _ANNOTATION_BLOCK_BEGIN) {
			annotation_block(annos);
		}
		declaration->add_variable(
		               variable_name,
		               check_expr(init_exp),
		               annos);
		
}

void Parser::variable_declaration(bool exported, IDeclaration const *&declaration) {
		declaration = ERR_DECL; 
		IType_name *type_name = ERR_TYPE;
		int sl = 0, sc = 0;
		
		type(type_name);
		Position &t_pos = type_name->access_position();
		IDeclaration_variable *variable_declaration
		   = m_declaration_factory
		       ->create_variable(
		           type_name,
		           exported,
		           sl ? sl : t_pos.get_start_line(),
		           sc ? sc : t_pos.get_start_column());
		
		variable_declarator(variable_declaration);
		while (WeakSeparator(_COMMA,4,2) ) {
			variable_declarator(variable_declaration);
		}
		while (!(la->kind == _EOF || la->kind == _SEMICOLON)) {SynErr(162); Get();}
		Expect(_SEMICOLON);
		Position &pos
		   = variable_declaration->access_position();
		pos.set_end_line(t->line);
		pos.set_end_column(t->col);
		declaration = variable_declaration;
		
}

void Parser::compound_statement(const IStatement *&stmnt) {
		stmnt = ERR_STMT; 
		Expect(97 /* "{" */);
		IStatement_compound *block
		   = m_statement_factory->create_compound(
		                               t->line,
		                               t->col);
		IStatement const *component = NULL;
		
		while (StartOf(14)) {
			statement(component);
			block->add_statement(check_stmt(component)); 
		}
		Expect(98 /* "}" */);
		Position &pos = block->access_position();
		pos.set_end_line(t->line);
		pos.set_end_column(t->col);
		stmnt = block;
		
}

void Parser::annotation(IAnnotation *&anno) {
		anno = NULL;
		IQualified_name *annotation_name = NULL;
		
		qualified_name(annotation_name);
		Position const &n_pos
		   = annotation_name->access_position();
		anno = m_annotation_factory
		       ->create_annotation(
		           annotation_name,
		           n_pos.get_start_line(),
		           n_pos.get_start_column());
		Argument_owner arg_owner(anno);
		
		argument_list(arg_owner);
		Position &pos = anno->access_position();
		pos.set_end_line(t->line);
		pos.set_end_column(t->col);
		
}

void Parser::statement(IStatement const *&stmnt) {
		bool is_decl = is_declaration();
		stmnt = ERR_STMT;
		
		if (la->kind == 97 /* "{" */) {
			compound_statement(stmnt);
		} else if (la->kind == 95 /* "typedef" */ || la->kind == 96 /* "struct" */ || la->kind == 99 /* "enum" */) {
			IDeclaration const *declaration = NULL; 
			type_declaration(false,declaration);
			stmnt = create_declaration(declaration); 
		} else if (la->kind == 94 /* "const" */) {
			IDeclaration const *declaration = NULL; 
			constant_declaration(false,declaration);
			stmnt = create_declaration(declaration); 
		} else if (la->kind == 100 /* "if" */) {
			if_statement(stmnt);
		} else if (la->kind == 102 /* "switch" */) {
			switch_statement(stmnt);
		} else if (la->kind == 105 /* "while" */) {
			while_statement(stmnt);
		} else if (la->kind == 106 /* "do" */) {
			do_statement(stmnt);
		} else if (la->kind == 107 /* "for" */) {
			for_statement(stmnt);
		} else if (la->kind == 108 /* "break" */) {
			break_statement(stmnt);
		} else if (la->kind == 109 /* "continue" */) {
			continue_statement(stmnt);
		} else if (la->kind == 110 /* "return" */) {
			return_statement(stmnt);
		} else if (is_decl) {
			IDeclaration const *declaration = NULL; 
			variable_declaration(false,declaration);
			stmnt = create_declaration(declaration); 
		} else if (!is_decl) {
			expression_statement(stmnt);
		} else SynErr(163);
}

void Parser::if_statement(IStatement const *&stmnt) {
		stmnt = ERR_STMT; 
		Expect(100 /* "if" */);
		IExpression const *cond = NULL;
		IStatement const *true_stmnt = NULL;
		IStatement const *false_stmnt = NULL;
		int sl = t->line;
		int sc = t->col;
		
		Expect(_LEFT_PARENTHESIS);
		expression(cond);
		Expect(_RIGHT_PARENTHESIS);
		statement(true_stmnt);
		true_stmnt  = check_stmt(true_stmnt); 
		if (la->kind == 101 /* "else" */) {
			Get();
			statement(false_stmnt);
			false_stmnt = check_stmt(false_stmnt); 
		}
		int el = 0, ec = 0;
		if (false_stmnt) {
		   Position const &pos
		       = false_stmnt->access_position();
		   el = pos.get_end_line();
		   ec = pos.get_end_column();
		} else {
		   Position const &pos
		       = true_stmnt->access_position();
		   el = pos.get_end_line();
		   ec = pos.get_end_column();
		}
		stmnt
		   = m_statement_factory
		       ->create_if(
		           check_expr(cond),
		           true_stmnt,
		           false_stmnt,
		           sl,
		           sc,
		           el,
		           ec);
		
}

void Parser::switch_statement(IStatement const *&stmnt) {
		stmnt = ERR_STMT; 
		Expect(102 /* "switch" */);
		IStatement_switch *switch_stmnt = NULL;
		IExpression const *cond = NULL;
		IStatement const  *scase = NULL;
		int sl = t->line;
		int sc = t->col;
		
		Expect(_LEFT_PARENTHESIS);
		expression(cond);
		Expect(_RIGHT_PARENTHESIS);
		switch_stmnt = m_statement_factory
		       ->create_switch(check_expr(cond), sl, sc);
		
		Expect(97 /* "{" */);
		while (la->kind == 103 /* "case" */ || la->kind == 104 /* "default" */) {
			switch_case(scase);
			switch_stmnt->add_case(check_stmt(scase)); 
		}
		Expect(98 /* "}" */);
		Position &pos = switch_stmnt->access_position();
		pos.set_end_line(t->line);
		pos.set_end_column(t->col);
		stmnt = switch_stmnt;
		
}

void Parser::while_statement(IStatement const *&stmnt) {
		stmnt = ERR_STMT; 
		Expect(105 /* "while" */);
		IExpression const *cond = NULL;
		IStatement const *body = NULL;
		int sl = t->line;
		int sc = t->col;
		
		Expect(_LEFT_PARENTHESIS);
		expression(cond);
		Expect(_RIGHT_PARENTHESIS);
		statement(body);
		body = check_stmt(body);
		Position const &pos = body->access_position();
		stmnt = m_statement_factory
		           ->create_while(
		               check_expr(cond),
		               body,
		               sl,
		               sc,
		               pos.get_end_line(),
		               pos.get_end_column());
		
}

void Parser::do_statement(IStatement const *&stmnt) {
		stmnt = ERR_STMT; 
		Expect(106 /* "do" */);
		IExpression const *cond = NULL;
		IStatement const *body = NULL;
		int sl = t->line;
		int sc = t->col;
		
		statement(body);
		Expect(105 /* "while" */);
		Expect(_LEFT_PARENTHESIS);
		expression(cond);
		Expect(_RIGHT_PARENTHESIS);
		while (!(la->kind == _EOF || la->kind == _SEMICOLON)) {SynErr(164); Get();}
		Expect(_SEMICOLON);
		stmnt = m_statement_factory
		           ->create_do_while(
		               check_expr(cond),
		               check_stmt(body),
		               sl,
		               sc,
		               t->line,
		               t->col);
		
}

void Parser::for_statement(IStatement const *&stmnt) {
		stmnt = ERR_STMT; 
		Expect(107 /* "for" */);
		IDeclaration const *init_decl = NULL;
		IStatement const *init_stmnt = NULL;
		IExpression const *test = NULL;
		IExpression const *update = NULL;
		IStatement const *body = ERR_STMT;
		int sl = t->line;
		int sc = t->col;
		
		Expect(_LEFT_PARENTHESIS);
		bool is_decl = is_declaration(); 
		if (is_decl) {
			variable_declaration(false,init_decl);
		} else if (!is_decl) {
			expression_statement(init_stmnt);
		} else SynErr(165);
		if (StartOf(7)) {
			expression(test);
		}
		while (!(la->kind == _EOF || la->kind == _SEMICOLON)) {SynErr(166); Get();}
		Expect(_SEMICOLON);
		if (StartOf(7)) {
			expression(update);
		}
		Expect(_RIGHT_PARENTHESIS);
		statement(body);
		if (init_decl)
		   init_stmnt
		       = create_declaration(init_decl);
		body = check_stmt(body);
		Position const &pos = body->access_position();
		stmnt
		   = m_statement_factory
		       ->create_for(
		           check_stmt(init_stmnt),
		           check_expr(test),
		           check_expr(update),
		           body,
		           sl,
		           sc,
		           pos.get_end_line(),
		           pos.get_end_column());
		
}

void Parser::break_statement(IStatement const *&stmnt) {
		stmnt = ERR_STMT; 
		Expect(108 /* "break" */);
		int sl = t->line;
		int sc = t->col;
		
		while (!(la->kind == _EOF || la->kind == _SEMICOLON)) {SynErr(167); Get();}
		Expect(_SEMICOLON);
		stmnt = m_statement_factory->create_break(
		                               sl,
		                               sc,
		                               t->line,
		                               t->col);
		
}

void Parser::continue_statement(IStatement const *&stmnt) {
		stmnt = ERR_STMT; 
		Expect(109 /* "continue" */);
		int sl = t->line;
		int sc = t->col;
		
		while (!(la->kind == _EOF || la->kind == _SEMICOLON)) {SynErr(168); Get();}
		Expect(_SEMICOLON);
		stmnt = m_statement_factory->create_continue(
		                               sl,
		                               sc,
		                               t->line,
		                               t->col);
		
}

void Parser::return_statement(IStatement const *&stmnt) {
		stmnt = ERR_STMT; 
		Expect(110 /* "return" */);
		IExpression const *exp = ERR_EXPR;
		int sl = t->line;
		int sc = t->col;
		
		expression(exp);
		while (!(la->kind == _EOF || la->kind == _SEMICOLON)) {SynErr(169); Get();}
		Expect(_SEMICOLON);
		stmnt = m_statement_factory->create_return(
		                               check_expr(exp),
		                               sl,
		                               sc,
		                               t->line,
		                               t->col);
		
}

void Parser::expression_statement(IStatement const *&stmnt) {
		stmnt = ERR_STMT;
		IExpression const *exp = NULL;
		
		if (StartOf(7)) {
			expression(exp);
		}
		while (!(la->kind == _EOF || la->kind == _SEMICOLON)) {SynErr(170); Get();}
		Expect(_SEMICOLON);
		if (errDist - 1 < minErrDist)
		   exp = ERR_EXPR;
		int sl = t->line;
		int sc = t->col;
		if (exp != NULL && exp != ERR_EXPR) {
		   Position const &pos = exp->access_position();
		   sl = pos.get_start_line();
		   sc = pos.get_start_column();
		}
		IStatement_expression *expr_stmnt
		   = m_statement_factory
		       ->create_expression(
		           check_expr(exp),
		           sl,
		           sc,
		           t->line,
		           t->col);
		stmnt = expr_stmnt;
		
}

void Parser::switch_case(IStatement const *&stmnt) {
		if (la->kind == 103 /* "case" */) {
			stmnt = ERR_STMT; 
			Get();
			IExpression const *exp = ERR_EXPR;
			IStatement const *component = NULL;
			int sl = t->line;
			int sc = t->col;
			int el = sl;
			int ec = sc;
			
			expression(exp);
			Expect(_COLON);
			IStatement_case *switch_case
			   = m_statement_factory
			       ->create_switch_case(
			           check_expr(exp),
			           sl,
			           sc);
			
			while (StartOf(14)) {
				statement(component);
				component = check_stmt(component);
				Position const &s_pos
				               = component->access_position();
				el = s_pos.get_end_line();
				ec = s_pos.get_end_column();
				switch_case->add_statement(component);
				
			}
			Position &pos = switch_case->access_position();
			pos.set_end_line(el);
			pos.set_end_column(ec);
			stmnt = switch_case;
			
		} else if (la->kind == 104 /* "default" */) {
			stmnt = ERR_STMT; 
			Get();
			IStatement const *component = NULL;
			int sl = t->line;
			int sc = t->col;
			int el = sl;
			int ec = sc;
			
			Expect(_COLON);
			IStatement_case *switch_case
			   = m_statement_factory
			       ->create_switch_case(0,sl,sc);
			
			while (StartOf(14)) {
				statement(component);
				component = check_stmt(component);
				Position const &s_pos
				               = component->access_position();
				el = s_pos.get_end_line();
				ec = s_pos.get_end_column();
				switch_case->add_statement(component);
				
			}
			Position &pos = switch_case->access_position();
			pos.set_end_line(el);
			pos.set_end_column(ec);
			stmnt = switch_case;
			
		} else SynErr(171);
}

void Parser::literal_expression(IExpression const *&exp) {
		if (la->kind == _TRUE || la->kind == _FALSE) {
			exp = ERR_EXPR;
			bool boolean_value;
			int sl = 0, sc = 0, el = 0, ec = 0;
			
			boolean_literal(boolean_value,sl,sc,el,ec);
			exp = m_expression_factory
			       ->create_literal(
			           m_value_factory
			               ->create_bool(boolean_value),
			           sl,sc,el,ec);
			
		} else if (la->kind == _INTEGER_LITERAL) {
			exp = ERR_EXPR;
			unsigned long integer_value;
			int sl = 0, sc = 0, el = 0, ec = 0;
			
			integer_literal(integer_value,sl,sc,el,ec);
			exp = m_expression_factory
			       ->create_literal(
			           m_value_factory
			               ->create_int(integer_value),
			           sl,sc,el,ec);
			
		} else if (la->kind == _FRACT_LITERAL || la->kind == _FLOATING_LITERAL) {
			exp = ERR_EXPR;
			double floating_value;
			int sl = 0, sc = 0, el = 0, ec = 0;
			bool is_float = true;
			bool is_error = true;
			
			floating_literal(floating_value,sl,sc,el,ec,is_float,is_error);
			IValue *v = is_float ?
			   (IValue *)m_value_factory->create_float(
			       float(floating_value)) :
			   (IValue *)m_value_factory->create_double(
			       floating_value);
			exp = m_expression_factory
			       ->create_literal(v,sl,sc,el,ec);
			
		} else if (la->kind == _STRING_LITERAL) {
			exp = ERR_EXPR;
			wchar_t const *string_value;
			int sl = 0, sc = 0, el = 0, ec = 0;
			string result(m_alloc);
			
			string_literal(string_value,sl,sc,el,ec);
			result += convert_escape_sequences_skip_quotes(string_value);
			
			while (la->kind == _STRING_LITERAL) {
				int dsl = 0, dsc = 0; 
				string_literal(string_value,dsl,dsc,el,ec);
				result += convert_escape_sequences_skip_quotes(string_value);
				
			}
			exp = m_expression_factory
			       ->create_literal(
			           m_value_factory
			               ->create_string(result.c_str()),
			           sl,sc,el,ec);
			
		} else SynErr(172);
}

void Parser::primary_expression(IExpression const *&exp) {
		if (StartOf(15)) {
			exp = ERR_EXPR; 
			literal_expression(exp);
		} else if (StartOf(16)) {
			exp = ERR_EXPR;
			IType_name *type_name = ERR_TYPE;
			
			simple_type(0,type_name);
			bool is_array_con = false; 
			if (is_array_constructor()) {
				Expect(_LEFT_SQUARE_BRACKET);
				Expect(_RIGHT_SQUARE_BRACKET);
				is_array_con = true; 
			}
			exp = to_reference(type_name, is_array_con); 
		} else if (la->kind == _LEFT_PARENTHESIS) {
			exp = ERR_EXPR; 
			Get();
			expression(exp);
			Expect(_RIGHT_PARENTHESIS);
			mark_parenthesis(exp); 
		} else SynErr(173);
}

void Parser::cast_expression(IExpression const *&exp) {
		int sl = t->line;
		int sc = t->col;
		
		Expect(_CAST);
		Expect(91 /* "<" */);
		IExpression const *right     = ERR_EXPR;
		IType_name        *type_name = ERR_TYPE; 
		type(type_name);
		Expect(92 /* ">" */);
		Expect(_LEFT_PARENTHESIS);
		unary_expression(right);
		IExpression_unary *un_exp = create_unary(
		   IExpression_unary::OK_CAST, check_expr(right));
		Position &pos = un_exp->access_position();
		pos.set_start_line(sl);
		pos.set_start_column(sc);
		un_exp->set_type_name(type_name);
		exp = un_exp;
		
		Expect(_RIGHT_PARENTHESIS);
}

void Parser::unary_expression(IExpression const *&exp) {
		IType_name *name = ERR_TYPE;
		int sl = t->line;
		int sc = t->col;
		exp = ERR_EXPR;
		
		if (is_c_style_cast()) {
			Expect(_LEFT_PARENTHESIS);
			type(name);
			Expect(_RIGHT_PARENTHESIS);
			unary_expression(exp);
			errors->Error(
			   sl, sc,
			   FORBIDDED_C_STYLE_CAST,
			   Error_params(m_alloc));
			// convert to call
			name = check_type(name);
			exp  = check_expr(exp);
			IExpression const *cons =
			   make_invalid(name->access_position());
			IExpression_call *call =
			   m_expression_factory->create_call(
			       cons,
			       sl,
			       sc,
			       t->line,
			       t->col);
			IArgument_positional const *arg =
			   create_positional_argument(exp);
			call->add_argument(arg);
			exp = call;
			
		} else if (StartOf(17)) {
			postfix_expression(exp);
		} else if (StartOf(18)) {
			IExpression_unary::Operator op
			   = IExpression_unary::OK_POSITIVE;
			IExpression const *right = ERR_EXPR;
			
			switch (la->kind) {
			case _TILDE: {
				Get();
				op = IExpression_unary::OK_BITWISE_COMPLEMENT; 
				break;
			}
			case _BANG: {
				Get();
				op = IExpression_unary::OK_LOGICAL_NOT; 
				break;
			}
			case _PLUS: {
				Get();
				op = IExpression_unary::OK_POSITIVE; 
				break;
			}
			case _MINUS: {
				Get();
				op = IExpression_unary::OK_NEGATIVE; 
				break;
			}
			case _INC_OP: {
				Get();
				op = IExpression_unary::OK_PRE_INCREMENT; 
				break;
			}
			case _DEC_OP: {
				Get();
				op = IExpression_unary::OK_PRE_DECREMENT; 
				break;
			}
			}
			unary_expression(right);
			IExpression_unary *un_exp = create_unary(
			   op, check_expr(right));
			Position &pos = un_exp->access_position();
			pos.set_start_line(sl);
			pos.set_start_column(sc);
			exp = un_exp;
			
		} else if (la->kind == 111 /* "let" */) {
			let_expression(exp);
		} else SynErr(174);
}

void Parser::postfix_expression(IExpression const *&exp) {
		exp = ERR_EXPR;
		int sl = 0;
		int sc = 0;
		
		if (StartOf(19)) {
			primary_expression(exp);
		} else if (la->kind == _CAST) {
			cast_expression(exp);
		} else SynErr(175);
		Position const &pos = exp->access_position();
		sl = pos.get_start_line();
		sc = pos.get_start_column();
		
		while (StartOf(20)) {
			if (la->kind == _INC_OP) {
				Get();
				IExpression_unary *un_exp = create_unary(
				           IExpression_unary::OK_POST_INCREMENT,
				           check_expr(exp));
				Position &pos = un_exp->access_position();
				pos.set_end_line(t->line);
				pos.set_end_column(t->col + 1);
				exp = un_exp;
				
			} else if (la->kind == _DEC_OP) {
				Get();
				IExpression_unary *un_exp = create_unary(
				           IExpression_unary::OK_POST_DECREMENT,
				           check_expr(exp));
				Position &pos = un_exp->access_position();
				pos.set_end_line(t->line);
				pos.set_end_column(t->col + 1);
				exp = un_exp;
				
			} else if (la->kind == _DOT) {
				Get();
				ISimple_name const *field_name = NULL; 
				simple_name(field_name);
				IExpression const *right
				                   = to_reference(field_name);
				IExpression_binary *bin_exp = create_binary(
				           IExpression_binary::OK_SELECT,
				           check_expr(exp),
				           right);
				exp = bin_exp;
				
				
			} else if (la->kind == _LEFT_PARENTHESIS) {
				IExpression_call *call
				   = m_expression_factory->create_call(
				       check_expr(exp),
				       sl,
				       sc,
				       t->line,
				       t->col);
				Argument_owner arg_owner(call);
				
				argument_list(arg_owner);
				exp = call;
				
			} else {
				Get();
				IExpression const *right = NULL;
				
				expression(right);
				Expect(_RIGHT_SQUARE_BRACKET);
				IExpression_binary *bin_exp = create_binary(
				           IExpression_binary::OK_ARRAY_INDEX,
				           check_expr(exp),
				           check_expr(right));
				Position &pos = bin_exp->access_position();
				pos.set_end_line(t->line);
				pos.set_end_column(t->col);
				exp = bin_exp;
				
			}
		}
}

void Parser::let_expression(IExpression const *&exp) {
		exp = ERR_EXPR; 
		Expect(111 /* "let" */);
		IExpression_let *let_exp
		   = m_expression_factory->create_let(
		                               0,
		                               t->line,
		                               t->col);
		IDeclaration const *decl = ERR_DECL;
		
		if (StartOf(5)) {
			variable_declaration(false, decl);
			let_exp->add_declaration(check_decl(decl)); 
		} else if (la->kind == 97 /* "{" */) {
			Get();
			variable_declaration(false, decl);
			let_exp->add_declaration(check_decl(decl)); 
			while (StartOf(5)) {
				variable_declaration(false, decl);
				let_exp->add_declaration(check_decl(decl)); 
			}
			Expect(98 /* "}" */);
		} else SynErr(176);
		ExpectWeak(112 /* "in" */, 12);
		IExpression const *right = ERR_EXPR; 
		unary_expression(right);
		right = check_expr(right);
		let_exp->set_expression(right);
		Position const &e_pos = right->access_position();
		Position &pos = let_exp->access_position();
		pos.set_end_line(e_pos.get_end_line());
		pos.set_end_column(e_pos.get_end_column());
		exp = let_exp;
		
}

void Parser::multiplicative_expression(IExpression const *&exp) {
		exp = ERR_EXPR; 
		unary_expression(exp);
		exp = check_expr(exp); 
		while (la->kind == _STAR || la->kind == 113 /* "/" */ || la->kind == 114 /* "%" */) {
			IExpression_binary::Operator op
			   = IExpression_binary::OK_MULTIPLY;
			IExpression const *right = ERR_EXPR;
			
			if (la->kind == _STAR) {
				Get();
				op = IExpression_binary::OK_MULTIPLY; 
			} else if (la->kind == 113 /* "/" */) {
				Get();
				op = IExpression_binary::OK_DIVIDE; 
			} else {
				Get();
				op = IExpression_binary::OK_MODULO; 
			}
			unary_expression(right);
			right = check_expr(right);
			exp = create_binary(op, exp, right);
			
		}
}

void Parser::additive_expression(IExpression const *&exp) {
		exp = ERR_EXPR; 
		multiplicative_expression(exp);
		exp = check_expr(exp); 
		while (la->kind == _PLUS || la->kind == _MINUS) {
			IExpression_binary::Operator op
			   = IExpression_binary::OK_PLUS;
			IExpression const *right = ERR_EXPR;
			
			if (la->kind == _PLUS) {
				Get();
				op = IExpression_binary::OK_PLUS; 
			} else {
				Get();
				op = IExpression_binary::OK_MINUS; 
			}
			multiplicative_expression(right);
			right = check_expr(right);
			exp = create_binary(op,exp,right);
			
		}
}

void Parser::shift_expression(IExpression const *&exp) {
		exp = ERR_EXPR; 
		additive_expression(exp);
		exp = check_expr(exp); 
		while (la->kind == 115 /* "<<" */ || la->kind == 116 /* ">>" */ || la->kind == 117 /* ">>>" */) {
			IExpression_binary::Operator op
			   = IExpression_binary::OK_SHIFT_LEFT;
			IExpression const *right = ERR_EXPR;
			
			if (la->kind == 115 /* "<<" */) {
				Get();
				op = IExpression_binary::OK_SHIFT_LEFT; 
			} else if (la->kind == 116 /* ">>" */) {
				Get();
				op = IExpression_binary::OK_SHIFT_RIGHT; 
			} else {
				Get();
				op = IExpression_binary::OK_UNSIGNED_SHIFT_RIGHT; 
			}
			additive_expression(right);
			right = check_expr(right);
			exp = create_binary(op,exp,right);
			
		}
}

void Parser::relational_expression(IExpression const *&exp) {
		exp = ERR_EXPR; 
		shift_expression(exp);
		exp = check_expr(exp); 
		while (StartOf(21)) {
			IExpression_binary::Operator op
			   = IExpression_binary::OK_LESS;
			IExpression const *right = ERR_EXPR;
			
			if (la->kind == 91 /* "<" */) {
				Get();
				op = IExpression_binary::OK_LESS; 
			} else if (la->kind == 118 /* "<=" */) {
				Get();
				op = IExpression_binary::OK_LESS_OR_EQUAL; 
			} else if (la->kind == 119 /* ">=" */) {
				Get();
				op = IExpression_binary::OK_GREATER_OR_EQUAL; 
			} else {
				Get();
				op = IExpression_binary::OK_GREATER; 
			}
			shift_expression(right);
			right = check_expr(right);
			exp = create_binary(op,exp,right);
			
		}
}

void Parser::equality_expression(IExpression const *&exp) {
		exp = ERR_EXPR; 
		relational_expression(exp);
		exp = check_expr(exp); 
		while (la->kind == 120 /* "==" */ || la->kind == 121 /* "!=" */) {
			IExpression_binary::Operator op
			   = IExpression_binary::OK_EQUAL;
			IExpression const *right = ERR_EXPR;
			
			if (la->kind == 120 /* "==" */) {
				Get();
				op = IExpression_binary::OK_EQUAL; 
			} else {
				Get();
				op = IExpression_binary::OK_NOT_EQUAL; 
			}
			relational_expression(right);
			right = check_expr(right);
			exp = create_binary(op,exp,right);
			
		}
}

void Parser::and_expression(IExpression const *&exp) {
		exp = ERR_EXPR; 
		equality_expression(exp);
		exp = check_expr(exp); 
		while (la->kind == 122 /* "&" */) {
			Get();
			IExpression const *right = ERR_EXPR; 
			equality_expression(right);
			right = check_expr(right);
			exp = create_binary(
			           IExpression_binary::OK_BITWISE_AND,
			           exp,
			           right);
			
		}
}

void Parser::exclusive_or_expression(IExpression const *&exp) {
		exp = ERR_EXPR; 
		and_expression(exp);
		exp = check_expr(exp); 
		while (la->kind == 123 /* "^" */) {
			Get();
			IExpression const *right = ERR_EXPR; 
			and_expression(right);
			right = check_expr(right);
			exp = create_binary(
			           IExpression_binary::OK_BITWISE_XOR,
			           exp,
			           right);
			
		}
}

void Parser::inclusive_or_expression(IExpression const *&exp) {
		exp = ERR_EXPR; 
		exclusive_or_expression(exp);
		exp = check_expr(exp); 
		while (la->kind == 124 /* "|" */) {
			Get();
			IExpression const *right = ERR_EXPR; 
			exclusive_or_expression(right);
			right = check_expr(right);
			exp = create_binary(
			           IExpression_binary::OK_BITWISE_OR,
			           exp,
			           right);
			
		}
}

void Parser::logical_and_expression(IExpression const *&exp) {
		exp = ERR_EXPR; 
		inclusive_or_expression(exp);
		exp = check_expr(exp); 
		while (la->kind == 125 /* "&&" */) {
			Get();
			IExpression const *right = ERR_EXPR; 
			inclusive_or_expression(right);
			right = check_expr(right);
			exp = create_binary(
			           IExpression_binary::OK_LOGICAL_AND,
			           exp,
			           right);
			
		}
}

void Parser::logical_or_expression(IExpression const *&exp) {
		exp = ERR_EXPR; 
		logical_and_expression(exp);
		exp = check_expr(exp); 
		while (la->kind == 126 /* "||" */) {
			Get();
			IExpression const *right = ERR_EXPR; 
			logical_and_expression(right);
			right = check_expr(right);
			exp = create_binary(
			           IExpression_binary::OK_LOGICAL_OR,
			           exp,
			           right);
			
		}
}

void Parser::assignment_operator(IExpression_binary::Operator &op) {
		switch (la->kind) {
		case _EQUAL: {
			Get();
			op = IExpression_binary::OK_ASSIGN; 
			break;
		}
		case 127 /* "*=" */: {
			Get();
			op = IExpression_binary::OK_MULTIPLY_ASSIGN; 
			break;
		}
		case 128 /* "/=" */: {
			Get();
			op = IExpression_binary::OK_DIVIDE_ASSIGN; 
			break;
		}
		case 129 /* "%=" */: {
			Get();
			op = IExpression_binary::OK_MODULO_ASSIGN; 
			break;
		}
		case 130 /* "+=" */: {
			Get();
			op = IExpression_binary::OK_PLUS_ASSIGN; 
			break;
		}
		case 131 /* "-=" */: {
			Get();
			op = IExpression_binary::OK_MINUS_ASSIGN; 
			break;
		}
		case 132 /* "<<=" */: {
			Get();
			op = IExpression_binary::OK_SHIFT_LEFT_ASSIGN; 
			break;
		}
		case 133 /* ">>=" */: {
			Get();
			op = IExpression_binary::OK_SHIFT_RIGHT_ASSIGN; 
			break;
		}
		case 134 /* ">>>=" */: {
			Get();
			op = IExpression_binary::OK_UNSIGNED_SHIFT_RIGHT_ASSIGN; 
			break;
		}
		case 135 /* "&=" */: {
			Get();
			op = IExpression_binary::OK_BITWISE_AND_ASSIGN; 
			break;
		}
		case 136 /* "^=" */: {
			Get();
			op = IExpression_binary::OK_BITWISE_XOR_ASSIGN; 
			break;
		}
		case 137 /* "|=" */: {
			Get();
			op = IExpression_binary::OK_BITWISE_OR_ASSIGN; 
			break;
		}
		default: SynErr(177); break;
		}
}




// If the user declared a method Init and a mehtod Destroy they should
// be called in the contructur and the destructor respctively.
//
// The following templates are used to recognize if the user declared
// the methods Init and Destroy.

template<typename T>
struct ParserInitExistsRecognizer {
	template<typename U, void (U::*)() = &U::Init>
	struct ExistsIfInitIsDefinedMarker{};

	struct InitIsMissingType {
		char dummy1;
	};
	
	struct InitExistsType {
		char dummy1; char dummy2;
	};

	// exists always
	template<typename U>
	static InitIsMissingType is_here(...);

	// exist only if ExistsIfInitIsDefinedMarker is defined
	template<typename U>
	static InitExistsType is_here(ExistsIfInitIsDefinedMarker<U>*);

	enum { InitExists = (sizeof(is_here<T>(NULL)) == sizeof(InitExistsType)) };
};

template<typename T>
struct ParserDestroyExistsRecognizer {
	template<typename U, void (U::*)() = &U::Destroy>
	struct ExistsIfDestroyIsDefinedMarker{};

	struct DestroyIsMissingType {
		char dummy1;
	};
	
	struct DestroyExistsType {
		char dummy1; char dummy2;
	};

	// exists always
	template<typename U>
	static DestroyIsMissingType is_here(...);

	// exist only if ExistsIfDestroyIsDefinedMarker is defined
	template<typename U>
	static DestroyExistsType is_here(ExistsIfDestroyIsDefinedMarker<U>*);

	enum { DestroyExists = (sizeof(is_here<T>(NULL)) == sizeof(DestroyExistsType)) };
};

// The folloing templates are used to call the Init and Destroy methods if they exist.

// Generic case of the ParserInitCaller, gets used if the Init method is missing
template<typename T, bool = ParserInitExistsRecognizer<T>::InitExists>
struct ParserInitCaller {
	static void CallInit(T *t) {
		// nothing to do
	}
};

// True case of the ParserInitCaller, gets used if the Init method exists
template<typename T>
struct ParserInitCaller<T, true> {
	static void CallInit(T *t) {
		t->Init();
	}
};

// Generic case of the ParserDestroyCaller, gets used if the Destroy method is missing
template<typename T, bool = ParserDestroyExistsRecognizer<T>::DestroyExists>
struct ParserDestroyCaller {
	static void CallDestroy(T *t) {
		// nothing to do
	}
};

// True case of the ParserDestroyCaller, gets used if the Destroy method exists
template<typename T>
struct ParserDestroyCaller<T, true> {
	static void CallDestroy(T *t) {
		t->Destroy();
	}
};

void Parser::Parse() {
	t = NULL;
	la = dummyToken = scanner->CreateToken();
	la->val = L"Dummy Token";
	Get();
	mdl();
	Expect(0);
}

Parser::Parser(Scanner *scanner, Errors *err) {

	ParserInitCaller<Parser>::CallInit(this);
	dummyToken = NULL;
	t = la = NULL;
	minErrDist = 2;
	errDist = minErrDist;
	this->scanner = scanner;
	errors = err;
}

bool Parser::StartOf(int s) {
	const bool T = true;
	const bool x = false;

	static bool const set[22][140] = {
		{T,x,x,x, x,x,x,x, x,x,x,T, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x},
		{x,T,x,x, x,x,x,T, x,x,x,x, x,x,x,T, x,x,x,x, x,x,x,x, x,x,x,x, x,x,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,x,x,x, T,x,x,x, x,T,T,T, T,x,x,T, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x},
		{x,x,x,x, x,x,x,x, x,x,x,T, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x},
		{x,T,x,x, x,x,x,x, x,x,x,x, T,T,x,T, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x},
		{x,T,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x},
		{x,T,x,x, x,x,x,x, x,x,x,x, x,x,x,T, x,x,x,x, x,x,x,x, x,x,x,x, x,x,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,x,x,x, T,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x},
		{x,T,T,T, T,T,x,x, x,x,x,x, x,x,x,T, x,T,x,x, T,T,T,T, T,T,T,x, x,x,x,x, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,x,T,T, T,x,x,T, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,T, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x},
		{x,T,T,T, T,T,x,x, x,x,x,x, x,x,x,T, x,T,x,x, T,T,T,T, T,T,T,x, x,x,x,x, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,x,T,T, T,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,T, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x},
		{x,x,x,x, x,x,x,x, x,T,x,x, x,x,x,x, T,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,T, T,T,T,T, T,T,T,T, T,T,x,x},
		{x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, T,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x},
		{x,T,x,x, x,x,x,x, x,x,x,x, x,x,x,T, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x},
		{x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,T,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x},
		{T,T,T,T, T,T,x,x, x,x,x,T, x,x,x,T, x,T,x,x, T,T,T,T, T,T,T,x, x,x,x,x, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,x,T,T, T,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,T, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x},
		{x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,T,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x},
		{x,T,T,T, T,T,x,x, x,x,x,T, x,x,x,T, x,T,x,x, T,T,T,T, T,T,T,x, x,x,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,x,T,T, T,x,x,x, x,x,T,T, T,T,x,T, T,x,T,x, x,T,T,T, T,T,T,T, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x},
		{x,x,T,T, T,T,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,T,T, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x},
		{x,T,x,x, x,x,x,x, x,x,x,x, x,x,x,T, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,x,x,x, T,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x},
		{x,T,T,T, T,T,x,x, x,x,x,x, x,x,x,T, x,T,x,x, x,x,x,x, x,x,T,x, x,x,x,x, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,x,T,T, T,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x},
		{x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, T,T,T,T, T,T,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x},
		{x,T,T,T, T,T,x,x, x,x,x,x, x,x,x,T, x,T,x,x, x,x,x,x, x,x,x,x, x,x,x,x, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,T,T,T, T,x,T,T, T,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x},
		{x,x,x,x, x,x,x,x, x,x,x,x, T,x,x,x, x,T,x,x, x,x,x,x, T,T,x,T, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x},
		{x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,T, T,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,T,T, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x}
	};



	return set[s][la->kind];
}

Parser::~Parser() {
	ParserDestroyCaller<Parser>::CallDestroy(this);
}

Errors::Errors()
	: count(0)
{
}

void Errors::SynErr(Token const *la, int n) {
	wchar_t format[20];
	const wchar_t* s = format;
	switch (n) {
			case 0: s = L"EOF expected"; break;
			case 1: s = L"IDENT expected"; break;
			case 2: s = L"INTEGER_LITERAL expected"; break;
			case 3: s = L"FRACT_LITERAL expected"; break;
			case 4: s = L"FLOATING_LITERAL expected"; break;
			case 5: s = L"STRING_LITERAL expected"; break;
			case 6: s = L"\"import\" expected"; break;
			case 7: s = L"\"export\" expected"; break;
			case 8: s = L"\"using\" expected"; break;
			case 9: s = L"\"=\" expected"; break;
			case 10: s = L"\",\" expected"; break;
			case 11: s = L"\";\" expected"; break;
			case 12: s = L"\".\" expected"; break;
			case 13: s = L"\"..\" expected"; break;
			case 14: s = L"\":\" expected"; break;
			case 15: s = L"\"::\" expected"; break;
			case 16: s = L"\"?\" expected"; break;
			case 17: s = L"\"(\" expected"; break;
			case 18: s = L"\")\" expected"; break;
			case 19: s = L"\"*\" expected"; break;
			case 20: s = L"\"+\" expected"; break;
			case 21: s = L"\"-\" expected"; break;
			case 22: s = L"\"~\" expected"; break;
			case 23: s = L"\"!\" expected"; break;
			case 24: s = L"\"++\" expected"; break;
			case 25: s = L"\"--\" expected"; break;
			case 26: s = L"\"cast\" expected"; break;
			case 27: s = L"\"[\" expected"; break;
			case 28: s = L"\"]\" expected"; break;
			case 29: s = L"\"[[\" expected"; break;
			case 30: s = L"\"uniform\" expected"; break;
			case 31: s = L"\"varying\" expected"; break;
			case 32: s = L"\"bool\" expected"; break;
			case 33: s = L"\"bool2\" expected"; break;
			case 34: s = L"\"bool3\" expected"; break;
			case 35: s = L"\"bool4\" expected"; break;
			case 36: s = L"\"int\" expected"; break;
			case 37: s = L"\"int2\" expected"; break;
			case 38: s = L"\"int3\" expected"; break;
			case 39: s = L"\"int4\" expected"; break;
			case 40: s = L"\"float\" expected"; break;
			case 41: s = L"\"float2\" expected"; break;
			case 42: s = L"\"float3\" expected"; break;
			case 43: s = L"\"float4\" expected"; break;
			case 44: s = L"\"float2x2\" expected"; break;
			case 45: s = L"\"float2x3\" expected"; break;
			case 46: s = L"\"float2x4\" expected"; break;
			case 47: s = L"\"float3x2\" expected"; break;
			case 48: s = L"\"float3x3\" expected"; break;
			case 49: s = L"\"float3x4\" expected"; break;
			case 50: s = L"\"float4x2\" expected"; break;
			case 51: s = L"\"float4x3\" expected"; break;
			case 52: s = L"\"float4x4\" expected"; break;
			case 53: s = L"\"double\" expected"; break;
			case 54: s = L"\"double2\" expected"; break;
			case 55: s = L"\"double3\" expected"; break;
			case 56: s = L"\"double4\" expected"; break;
			case 57: s = L"\"double2x2\" expected"; break;
			case 58: s = L"\"double2x3\" expected"; break;
			case 59: s = L"\"double2x4\" expected"; break;
			case 60: s = L"\"double3x2\" expected"; break;
			case 61: s = L"\"double3x3\" expected"; break;
			case 62: s = L"\"double3x4\" expected"; break;
			case 63: s = L"\"double4x2\" expected"; break;
			case 64: s = L"\"double4x3\" expected"; break;
			case 65: s = L"\"double4x4\" expected"; break;
			case 66: s = L"\"color\" expected"; break;
			case 67: s = L"\"string\" expected"; break;
			case 68: s = L"\"bsdf\" expected"; break;
			case 69: s = L"\"edf\" expected"; break;
			case 70: s = L"\"vdf\" expected"; break;
			case 71: s = L"\"light_profile\" expected"; break;
			case 72: s = L"\"texture_2d\" expected"; break;
			case 73: s = L"\"texture_3d\" expected"; break;
			case 74: s = L"\"texture_cube\" expected"; break;
			case 75: s = L"\"texture_ptex\" expected"; break;
			case 76: s = L"\"bsdf_measurement\" expected"; break;
			case 77: s = L"\"intensity_mode\" expected"; break;
			case 78: s = L"\"intensity_radiant_exitance\" expected"; break;
			case 79: s = L"\"intensity_power\" expected"; break;
			case 80: s = L"\"material\" expected"; break;
			case 81: s = L"\"material_emission\" expected"; break;
			case 82: s = L"\"material_geometry\" expected"; break;
			case 83: s = L"\"material_surface\" expected"; break;
			case 84: s = L"\"material_volume\" expected"; break;
			case 85: s = L"\"module\" expected"; break;
			case 86: s = L"\"true\" expected"; break;
			case 87: s = L"\"false\" expected"; break;
			case 88: s = L"\"hair_bsdf\" expected"; break;
			case 89: s = L"\"reserved\" expected"; break;
			case 90: s = L"\"mdl\" expected"; break;
			case 91: s = L"\"<\" expected"; break;
			case 92: s = L"\">\" expected"; break;
			case 93: s = L"\"annotation\" expected"; break;
			case 94: s = L"\"const\" expected"; break;
			case 95: s = L"\"typedef\" expected"; break;
			case 96: s = L"\"struct\" expected"; break;
			case 97: s = L"\"{\" expected"; break;
			case 98: s = L"\"}\" expected"; break;
			case 99: s = L"\"enum\" expected"; break;
			case 100: s = L"\"if\" expected"; break;
			case 101: s = L"\"else\" expected"; break;
			case 102: s = L"\"switch\" expected"; break;
			case 103: s = L"\"case\" expected"; break;
			case 104: s = L"\"default\" expected"; break;
			case 105: s = L"\"while\" expected"; break;
			case 106: s = L"\"do\" expected"; break;
			case 107: s = L"\"for\" expected"; break;
			case 108: s = L"\"break\" expected"; break;
			case 109: s = L"\"continue\" expected"; break;
			case 110: s = L"\"return\" expected"; break;
			case 111: s = L"\"let\" expected"; break;
			case 112: s = L"\"in\" expected"; break;
			case 113: s = L"\"/\" expected"; break;
			case 114: s = L"\"%\" expected"; break;
			case 115: s = L"\"<<\" expected"; break;
			case 116: s = L"\">>\" expected"; break;
			case 117: s = L"\">>>\" expected"; break;
			case 118: s = L"\"<=\" expected"; break;
			case 119: s = L"\">=\" expected"; break;
			case 120: s = L"\"==\" expected"; break;
			case 121: s = L"\"!=\" expected"; break;
			case 122: s = L"\"&\" expected"; break;
			case 123: s = L"\"^\" expected"; break;
			case 124: s = L"\"|\" expected"; break;
			case 125: s = L"\"&&\" expected"; break;
			case 126: s = L"\"||\" expected"; break;
			case 127: s = L"\"*=\" expected"; break;
			case 128: s = L"\"/=\" expected"; break;
			case 129: s = L"\"%=\" expected"; break;
			case 130: s = L"\"+=\" expected"; break;
			case 131: s = L"\"-=\" expected"; break;
			case 132: s = L"\"<<=\" expected"; break;
			case 133: s = L"\">>=\" expected"; break;
			case 134: s = L"\">>>=\" expected"; break;
			case 135: s = L"\"&=\" expected"; break;
			case 136: s = L"\"^=\" expected"; break;
			case 137: s = L"\"|=\" expected"; break;
			case 138: s = L"??? expected"; break;
			case 139: s = L"this symbol not expected in mdl_version"; break;
			case 140: s = L"this symbol not expected in import"; break;
			case 141: s = L"invalid import"; break;
			case 142: s = L"this symbol not expected in import"; break;
			case 143: s = L"invalid import"; break;
			case 144: s = L"invalid global_declaration"; break;
			case 145: s = L"invalid boolean_literal"; break;
			case 146: s = L"invalid floating_literal"; break;
			case 147: s = L"invalid frequency_qualifier"; break;
			case 148: s = L"invalid relative_type"; break;
			case 149: s = L"invalid annotation_block"; break;
			case 150: s = L"this symbol not expected in annotation_declaration"; break;
			case 151: s = L"this symbol not expected in constant_declaration"; break;
			case 152: s = L"invalid type_declaration"; break;
			case 153: s = L"this symbol not expected in function_declaration"; break;
			case 154: s = L"invalid function_declaration"; break;
			case 155: s = L"this symbol not expected in function_declaration"; break;
			case 156: s = L"invalid function_declaration"; break;
			case 157: s = L"invalid constant_declarator"; break;
			case 158: s = L"this symbol not expected in alias_type_declaration"; break;
			case 159: s = L"this symbol not expected in struct_type_declaration"; break;
			case 160: s = L"this symbol not expected in enum_type_declaration"; break;
			case 161: s = L"this symbol not expected in struct_field_declarator"; break;
			case 162: s = L"this symbol not expected in variable_declaration"; break;
			case 163: s = L"invalid statement"; break;
			case 164: s = L"this symbol not expected in do_statement"; break;
			case 165: s = L"invalid for_statement"; break;
			case 166: s = L"this symbol not expected in for_statement"; break;
			case 167: s = L"this symbol not expected in break_statement"; break;
			case 168: s = L"this symbol not expected in continue_statement"; break;
			case 169: s = L"this symbol not expected in return_statement"; break;
			case 170: s = L"this symbol not expected in expression_statement"; break;
			case 171: s = L"invalid switch_case"; break;
			case 172: s = L"invalid literal_expression"; break;
			case 173: s = L"invalid primary_expression"; break;
			case 174: s = L"invalid unary_expression"; break;
			case 175: s = L"invalid postfix_expression"; break;
			case 176: s = L"invalid let_expression"; break;
			case 177: s = L"invalid assignment_operator"; break;

		default:
			coco_swprintf(format, 20, L"error %d", n);
			break;
	}
	Error(la, s);
}

void Errors::Error(Token const *t, const wchar_t *s) {
	wprintf(L"-- line %d col %d: %ls\n", t->line, t->col, s);
	count++;
}

void Errors::Warning(int line, int col, const wchar_t *s) {
	wprintf(L"-- line %d col %d: %ls\n", line, col, s);
}

void Errors::Warning(const wchar_t *s) {
	wprintf(L"%ls\n", s);
}

void Errors::Exception(const wchar_t* s) {
	wprintf(L"%ls", s); 
	exit(1);
}

void Errors::Error(int line, int col, int code, Error_params const &params) {
	wprintf(L"-- line %d col %d: Error code %d\n", line, col, code);
	count++;
}

} // namespace
} // namespace

