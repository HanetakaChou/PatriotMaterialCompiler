#include "../../../Public/MatC/PT_MatC_OSLPreprocessor.h"


extern "C" PTMATCAPI void PTCALL PT_MatC_OSLPreprocessor_Run(
	void *pUserStream, 
	ptrdiff_t(PTPTR *pFn_UserStream_Read)(void *pUserStream, void *buf, size_t count)
)
{
    //clang_createIndex()

    //clang_CXIndex_setGlobalOptions
}
