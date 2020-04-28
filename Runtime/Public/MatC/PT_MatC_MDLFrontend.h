#ifndef _PT_MATC_MDLFRONTEND_H_
#define _PT_MATC_MDLFRONTEND_H_ 1

#include "../PTCommon.h"
#include "PT_MatC_Common.h"

#include <stddef.h>

typedef struct MDLFrontend_OpaqueInputStream *MDLFrontend_InputStreamRef;

extern "C" PTMATCAPI void PTCALL PT_MatC_MDLFrontend_Run(
	char const *pInitialFileName,
	MDLFrontend_InputStreamRef (PTPTR *pFn_CreateInputStream)(char const *pFileName), //For process #include
	ptrdiff_t(PTPTR *pFn_InputStreamRead)(MDLFrontend_InputStreamRef InputStreamRef, void *buf, size_t count),
	void (PTPTR *pFn_InputStreamDispose)(MDLFrontend_InputStreamRef InputStreamRef)
);

#endif