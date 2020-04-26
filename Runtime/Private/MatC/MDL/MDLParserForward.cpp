#include "MDLParser.h"
#include "MDLFrontend.h"

static inline MDLStringRef wrap(std::string *x) { return reinterpret_cast<MDLStringRef>(x); }
static inline std::string *unwrap(MDLStringRef x) { return reinterpret_cast<std::string *>(x); }

extern "C" MDLStringRef MDLFrontend_CreateString(void *pUserData, char const *s)
{
    return wrap(static_cast<class MDLFrontend *>(pUserData)->Callback_CreateString(s));
}

extern "C" MDLStringRef MDLFrontend_StringAppend(void *pUserData, MDLStringRef _self, char const *s)
{
    return wrap(static_cast<class MDLFrontend *>(pUserData)->Callback_StringAppend(unwrap(_self), s));
}


