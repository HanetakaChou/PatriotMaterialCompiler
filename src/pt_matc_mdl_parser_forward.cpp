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

#include "pt_matc_mdl_parser.h"
#include "pt_matc_mdl_frontend.h"

static inline MDLStringRef wrap(std::string *x) { return reinterpret_cast<MDLStringRef>(x); }
static inline std::string *unwrap(MDLStringRef x) { return reinterpret_cast<std::string *>(x); }

extern "C" MDLStringRef MDLFrontend_CreateString(void *pUserData, char const *s)
{
    return wrap(static_cast<class MDLFrontend *>(pUserData)->Callback_CreateString(s));
}

extern "C" MDLStringRef MDLFrontend_StringAppend2(void *pUserData, MDLStringRef l, MDLStringRef r)
{
    return wrap(static_cast<class MDLFrontend *>(pUserData)->Callback_StringAppend(unwrap(l), unwrap(r)));
}

extern "C" MDLStringRef MDLFrontend_StringAppend3(void *pUserData, MDLStringRef l, char const *m, MDLStringRef r)
{
    return wrap(static_cast<class MDLFrontend *>(pUserData)->Callback_StringAppend(unwrap(l), m, unwrap(r)));
}

extern "C" void MDLFrontend_DisposeString(void *pUserData, MDLStringRef s)
{
    return static_cast<class MDLFrontend *>(pUserData)->Callback_DisposeString(unwrap(s));
}

extern "C" void MDLFrontend_HashTypeName(void *pUserData, MDLStringRef s)
{
    return static_cast<class MDLFrontend *>(pUserData)->Callback_HashTypeName(unwrap(s));
}

extern "C" void MDLFrontend_HashVariableName(void *pUserData, MDLStringRef s)
{
    return static_cast<class MDLFrontend *>(pUserData)->Callback_HashVariableName(unwrap(s));
}