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

#ifndef _PT_MATC_MDL_H_
#define _PT_MATC_MDL_H_ 1

#include "pt_common.h"
#include "pt_matc_common.h"

#include <stddef.h>

typedef struct MDLFrontend_OpaqueInputStream *MDLFrontend_InputStreamRef;

extern "C"
{
    PT_MATC_ATTR void PT_CALL PT_MatC_MDLFrontend_Run(
        char const *pInitialFileName,
        MDLFrontend_InputStreamRef(PT_PTR *pFn_CreateInputStream)(char const *pFileName), //For process #include
        ptrdiff_t(PT_PTR *pFn_InputStreamRead)(MDLFrontend_InputStreamRef InputStreamRef, void *buf, size_t count),
        void(PT_PTR *pFn_InputStreamDispose)(MDLFrontend_InputStreamRef InputStreamRef));
}

#endif