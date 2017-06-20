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

#include "pt_matc_mdl_frontend.h"
#include <exception>
extern "C" MDLFrontend *mdl_llget_extra(struct llscan_t *yyscanner);

extern "C" int mdl_ll_stream_read(MDLFrontend *pUserData, MDLFrontend_InputStreamRef _InputStreamRef, void *buf, size_t size)
{
	ptrdiff_t _res = pUserData->Callback_InputStreamRead(_InputStreamRef, buf, size);
	return static_cast<int>(_res);
}

//https://westes.github.io/flex/manual/Generated-Scanner.html#Generated-Scanner
extern "C" int mdl_llwrap(struct llscan_t *scanner)
{
	return mdl_llget_extra(scanner)->Callback_Wrap();
}

#if defined(_MSC_VER)
static inline __declspec(noreturn) void mdl_ll_fatal_error_cxx(int line, int column, char const *msg, MDLFrontend *pUserData);
extern "C" void mdl_ll_fatal_error(int line, int column, char const *msg, MDLFrontend *pUserData)
{
	return mdl_ll_fatal_error_cxx(line, column, msg, pUserData);
}
static inline __declspec(noreturn) void mdl_ll_fatal_error_cxx(int line, int column, char const *msg, MDLFrontend *pUserData)
#elif defined(__GNUC__)
extern "C" __attribute__((__noreturn__)) void mdl_ll_fatal_error(int line, int column, char const *msg, MDLFrontend *pUserData)
#else
#error Unknown Compiler //未知的编译器
#endif
{
	pUserData->Callback_Error(line, column, msg);

	//RaiseException
	throw std::exception();
}

extern "C" void *mdl_llalloc(size_t size, struct llscan_t *scanner)
{
	return mdl_llget_extra(scanner)->Callback_Malloc(size);
}

extern "C" void *mdl_llrealloc(void *ptr, size_t size, struct llscan_t *scanner)
{
	return mdl_llget_extra(scanner)->Callback_Realloc(ptr, size);
}

extern "C" void mdl_llfree(void *ptr, struct llscan_t *scanner)
{
	return mdl_llget_extra(scanner)->Callback_Free(ptr);
}