#ifndef _MDLSCANNER_HPP_
#define _MDLSCANNER_HPP_ 1

#include <stddef.h>

#ifdef __cplusplus
extern "C"
{
#endif

size_t MDLFrontend_HashIdentName(void *pUserData, char const *pIdentName);

#ifdef __cplusplus
}
#endif

#endif