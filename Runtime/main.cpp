
#include "Public/MatC/PT_MatC_Frontend.h"

//#include <stddef.h>
//#include <stdlib.h>

#include <llvm-c/Core.h>
#if 0
#include <llvm-c/Transforms/PassManagerBuilder.h>
#include <llvm-c/Transforms/IPO.h>
#include <llvm-c/BitReader.h>
#include <llvm-c/ExecutionEngine.h>

#include <vector>
#endif

#if defined(PTPOSIX)
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#elif defined(PTWIN32)
#include <winsdkver.h>
#define WIN32_LEAN_AND_MEAN 1
#include <Windows.h>
#else
#error Unknown Platform
#endif

int main()
{

#if defined(PTPOSIX)
	int fd = openat(AT_FDCWD, "/home/share/github/PatriotMaterialCompiler/tutorials.mdl", O_RDONLY);
	PT_MatC_MDLFrontend_Run(
		reinterpret_cast<void *>(static_cast<intptr_t>(fd)),
		[](void *pUserStream, void *buf, size_t count) -> ptrdiff_t {
			ssize_t _res = read(static_cast<int>(reinterpret_cast<intptr_t>(pUserStream)), buf, count);
			return _res;
		});
#elif defined(PTWIN32)
	HANDLE hFile = CreateFileW(L"C:\\Users\\Administrator\\Documents\\github\\PatriotMaterialCompiler\\tutorials.mdl", FILE_READ_DATA, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	PT_MatC_MDLFrontend_Run(
		hFile,
		[](void *pUserStream, void *buf, size_t count) -> ptrdiff_t {
			DWORD _numberOfBytesRead;
			BOOL _res = ReadFile(static_cast<HANDLE>(pUserStream), buf, count, &_numberOfBytesRead, NULL);
			return ((_res != FALSE) ? _numberOfBytesRead : -1);
		});
#else
#error Unknown Platform
#endif
	//LLVMContextRef llvm_context = LLVMContextCreate();

	//MDLFrontend mdlfrontend;
	//mdlfrontend.Compile();

#if 0
	LLVMContextRef llvm_context = LLVMContextCreate();

	LLVMTypeRef llvm_type_float = LLVMFloatTypeInContext(llvm_context);
	LLVMTypeRef llvm_type_int = LLVMInt32TypeInContext(llvm_context);
	LLVMTypeRef llvm_type_float_ptr = LLVMPointerType(llvm_type_float, 0);

	LLVMTypeRef llvm_type_triple = NULL;
	{
		llvm_type_triple = LLVMStructCreateNamed(llvm_context, "Vec3");
		LLVMTypeRef _triplefields[3] = { llvm_type_float, llvm_type_float, llvm_type_float };
		LLVMStructSetBody(llvm_type_triple, _triplefields, 3, false);
	}

	LLVMTypeRef llvm_type_triple_ptr = LLVMPointerType(llvm_type_triple, 0);

	LLVMTypeRef llvm_type_matrix = NULL;
	{
		llvm_type_matrix = LLVMStructCreateNamed(llvm_context, "Matrix4");
		LLVMTypeRef _matrixfields[16] = { llvm_type_float, llvm_type_float, llvm_type_float, llvm_type_float,
										 llvm_type_float, llvm_type_float, llvm_type_float, llvm_type_float,
										 llvm_type_float, llvm_type_float, llvm_type_float, llvm_type_float,
										 llvm_type_float, llvm_type_float, llvm_type_float, llvm_type_float };
		LLVMStructSetBody(llvm_type_matrix, _matrixfields, 16, false);
	}

	LLVMTypeRef llvm_type_matrix_ptr = LLVMPointerType(llvm_type_matrix, 0);

	extern int osl_llvm_compiled_ops_size;
	extern char osl_llvm_compiled_ops_block[];
	LLVMMemoryBufferRef buf = LLVMCreateMemoryBufferWithMemoryRange(osl_llvm_compiled_ops_block, osl_llvm_compiled_ops_size, "llvm_ops", false);

	//LLVMParseBitcodeInContext2

	//llvm::getLazyBitcodeModule
	LLVMModuleRef llvm_module = NULL;
	LLVMBool res = LLVMGetBitcodeModuleInContext2(llvm_context, buf, &llvm_module);

	//LLVMModuleCreateWithNameInContext

	LLVMTypeRef params[1] = { llvm_type_matrix };
	LLVMTypeRef functype = LLVMFunctionType(llvm_type_float, params, 1, false);
	LLVMValueRef func = LLVMAddFunction(llvm_module, "huhu", functype);
	LLVMSetFunctionCallConv(func, LLVMFastCallConv);
	LLVMValueRef llvm_value2 = LLVMGetNamedFunction(llvm_module, "huhu");

	LLVMBasicBlockRef entry_bb = LLVMAppendBasicBlockInContext(llvm_context, func, "huhu");
	LLVMBuilderRef irbuilder = LLVMCreateBuilderInContext(llvm_context);
	LLVMPositionBuilderAtEnd(irbuilder, entry_bb);

	//LLVMBuildGEP2

	LLVMPassManagerRef llvm_func_passes = LLVMCreateFunctionPassManagerForModule(llvm_module);

	LLVMPassManagerRef llvm_module_passes = LLVMCreatePassManager();

	LLVMPassManagerBuilderRef builder = LLVMPassManagerBuilderCreate();
	LLVMPassManagerBuilderSetOptLevel(builder, 3);
	LLVMPassManagerBuilderUseInlinerWithThreshold(builder, 3);

	LLVMPassManagerBuilderPopulateFunctionPassManager(builder, llvm_func_passes);
	LLVMPassManagerBuilderPopulateModulePassManager(builder, llvm_module_passes);

	//LLVMAddFunctionInliningPass(llvm_func_passes);

	std::vector<void *> jit_block;

	LLVMMCJITMemoryManagerRef llvm_jitmm = LLVMCreateSimpleMCJITMemoryManager(
		&jit_block,
		[](void *Opaque, uintptr_t Size, unsigned Alignment, unsigned SectionID, const char *SectionName) -> uint8_t * {
		void *memptr = NULL;
		int res = posix_memalign(&memptr, Alignment, Size);
		if (res == 0)
		{
			static_cast<std::vector<void *> *>(Opaque)->push_back(memptr);
			return static_cast<uint8_t *>(memptr);
		}
		else
		{
			return NULL;
		}
	},
		[](void *Opaque, uintptr_t Size, unsigned Alignment, unsigned SectionID, const char *SectionName, LLVMBool IsReadOnly) -> uint8_t * {
		void *memptr = NULL;
		int res = posix_memalign(&memptr, Alignment, Size);
		if (res == 0)
		{
			static_cast<std::vector<void *> *>(Opaque)->push_back(memptr);
			return static_cast<uint8_t *>(memptr);
		}
		else
		{
			return NULL;
		}
	},
		[](void *Opaque, char **ErrMsg) -> LLVMBool {
		return 0;
	},
		[](void *Opaque) -> void {
		for (void *memptr : (*static_cast<std::vector<void *> *>(Opaque)))
		{
			free(memptr);
		}
	});

	LLVMExecutionEngineRef engine_builder = NULL;
	{
		LLVMMCJITCompilerOptions options;
		LLVMInitializeMCJITCompilerOptions(&options, sizeof(LLVMMCJITCompilerOptions));
		options.OptLevel = LLVMCodeGenLevelDefault;
		options.MCJMM = llvm_jitmm;

		LLVMBool res1 = LLVMInitializeNativeTarget();

		char *OutError = NULL;
		LLVMBool res2 = LLVMCreateMCJITCompilerForModule(&engine_builder, llvm_module, &options, sizeof(LLVMMCJITCompilerOptions), &OutError);
		OutError = NULL;

		//LLVMJITEventListenerRef vtuneProfiler = LLVMCreateIntelJITEventListener();
		//m_llvm_exec->RegisterJITEventListener (vtuneProfiler);
	}
#endif

	return 0;
}
