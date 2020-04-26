
#include "MDL/MDLFrontend.h"

#include <stddef.h>

#include <llvm-c/Core.h>
#include <llvm-c/ExecutionEngine.h>

int main()
{
    //MDLFrontend mdlfrontend;
    //mdlfrontend.Compile();

    LLVMContextRef llvm_context = LLVMContextCreate();

    LLVMTypeRef llvm_type_float = LLVMFloatTypeInContext(llvm_context);
    LLVMTypeRef llvm_type_int = LLVMInt32TypeInContext(llvm_context);
    LLVMTypeRef llvm_type_float_ptr = LLVMPointerType(llvm_type_float, 0);

    LLVMMCJITMemoryManagerRef llvm_jitmm = LLVMCreateSimpleMCJITMemoryManager(
        NULL,
        [](void *Opaque, uintptr_t Size, unsigned Alignment, unsigned SectionID, const char *SectionName) -> uint8_t * {

        },
        [](void *Opaque, uintptr_t Size, unsigned Alignment, unsigned SectionID, const char *SectionName, LLVMBool IsReadOnly) -> uint8_t * {

        },
        [](void *Opaque, char **ErrMsg) -> LLVMBool {

        },
        [](void *Opaque) -> void {

        });

    return 0;
}
