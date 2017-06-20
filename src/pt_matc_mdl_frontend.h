/*
 * Copyright (C) YuqiaoZhang
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef _PT_MATC_MDL_FRONTEND_H_
#define _PT_MATC_MDL_FRONTEND_H_ 1

#include "../include/pt_matc_mdl.h"

#include <stddef.h>
#include <stdlib.h>
#include <string>
#include <vector>
//#include <unordered_set>

class MDLFrontend
{
	MDLFrontend_InputStreamRef(PT_PTR *m_pFn_CreateInputStream)(char const *pFileName);
	ptrdiff_t(PT_PTR *m_pFn_InputStreamRead)(MDLFrontend_InputStreamRef InputStreamRef, void *buf, size_t count);
	void(PT_PTR *m_pFn_InputStreamDispose)(MDLFrontend_InputStreamRef InputStreamRef);

	std::vector<std::string> m_inputstream_filename_stack;

public:
	MDLFrontend(
		MDLFrontend_InputStreamRef(PT_PTR *pFn_CreateInputStream)(char const *pFileName), //For process #include
		ptrdiff_t(PT_PTR *pFn_InputStreamRead)(MDLFrontend_InputStreamRef InputStreamRef, void *buf, size_t count),
		void(PT_PTR *pFn_InputStreamDispose)(MDLFrontend_InputStreamRef InputStreamRef));

	void Run(char const *pInitialFileName);

	ptrdiff_t Callback_InputStreamRead(MDLFrontend_InputStreamRef _InputStreamRef, void *buf, size_t count);

	int Callback_Wrap();

	std::string *Callback_CreateString(char const *s);
	std::string *Callback_StringAppend(std::string *l, std::string *r);
	std::string *Callback_StringAppend(std::string *l, char const *m, std::string *r);
	void Callback_DisposeString(std::string *s);

	void Callback_HashTypeName(std::string *s);
	void Callback_HashVariableName(std::string *s);

	void Callback_Error(int line, int column, char const *s);

	void *Callback_Malloc(size_t size);
	void *Callback_Realloc(void *ptr, size_t size);
	void Callback_Free(void *ptr);
};

#endif