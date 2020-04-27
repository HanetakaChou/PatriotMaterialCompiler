#ifndef _PT_MATC_FRONTEND_H_
#define _PT_MATC_FRONTEND_H_ 1

#include "../PTCommon.h"
#include "PT_MatC_Common.h"

#include <stddef.h>

extern "C" PTMATCAPI void PTCALL PT_MatC_MDLFrontend_Run(
	void *pUserStream, 
	ptrdiff_t(PTPTR *pFn_UserStream_Read)(void *pUserStream, void *buf, size_t count)
);

#endif