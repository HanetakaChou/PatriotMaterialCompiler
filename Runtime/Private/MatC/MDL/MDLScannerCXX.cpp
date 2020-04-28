#include "MDLFrontend.h"
#include <stdexcept>
extern "C" class MDLFrontend *mdl_llget_extra(struct llscan_t *yyscanner);

extern "C" int mdl_ll_stream_read(void *, class MDLFrontend_InputStream *pUserStream, void *buf, size_t size)
{
	ptrdiff_t _res = pUserStream->Read(buf, size);
	return static_cast<int>(_res);
}

//https://westes.github.io/flex/manual/Generated-Scanner.html#Generated-Scanner
extern "C" int mdl_llwrap(struct llscan_t *scanner)
{
	return 1;
}


#if defined(_MSC_VER)
static inline __declspec(noreturn) void mdl_ll_fatal_error_cxx(char const *msg, class MDLFrontend *pUserData);
extern "C" void mdl_ll_fatal_error(char const *msg, class MDLFrontend *pUserData)
{
	return mdl_ll_fatal_error_cxx(msg, pUserData);
}
static inline __declspec(noreturn) void mdl_ll_fatal_error_cxx(char const *msg, class MDLFrontend *pUserData)
#elif defined(__GNUC__)
extern "C" __attribute__((__noreturn__)) void mdl_ll_fatal_error(char const *msg, class MDLFrontend *pUserData)
#else
#error Unknown Compiler //未知的编译器
#endif
{
	//RaiseException
	throw std::logic_error(msg);
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