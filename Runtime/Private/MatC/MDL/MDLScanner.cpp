#include "MDLFrontend.h"
#include "../PT_MatC_Stream.h"
#include <stdexcept>
extern "C" void *mdl_llget_extra(struct llscan_t *yyscanner);

extern "C" int mdl_ll_stream_read(void *pUserData, void *pUserStream, void *buf, size_t size)
{
    return static_cast<class PT_MatC_Stream *>(pUserStream)->Read(buf, size);
}

//https://westes.github.io/flex/manual/Generated-Scanner.html#Generated-Scanner
extern "C" int mdl_llwrap(struct llscan_t *scanner)
{
    //void *user_defined = mdl_llget_extra(scanner);
    return 1;
}

#if defined(_MSC_VER)
extern "C" __declspec(noreturn) void mdl_ll_fatal_error(char const *msg, void *pUserData)
#elif defined(__GNUC__)
extern "C" __attribute__((__noreturn__)) void mdl_ll_fatal_error(char const *msg, void *pUserData)
#else
#error Unknown Compiler //未知的编译器
#endif
{
    //RaiseException
    throw std::logic_error(msg);
}

extern "C" void *mdl_llalloc(size_t size, struct llscan_t *scanner)
{
    return static_cast<class MDLFrontend *>(mdl_llget_extra(scanner))->Callback_Malloc(size);
}

extern "C" void *mdl_llrealloc(void *ptr, size_t size, struct llscan_t *scanner)
{
    return static_cast<class MDLFrontend *>(mdl_llget_extra(scanner))->Callback_Realloc(ptr, size);
}

extern "C" void mdl_llfree(void *ptr, struct llscan_t *scanner)
{
    return static_cast<class MDLFrontend *>(mdl_llget_extra(scanner))->Callback_Free(ptr);
}