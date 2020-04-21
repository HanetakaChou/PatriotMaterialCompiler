#include "MDLFrontend.h"

#include <stddef.h>
#include <stdlib.h>
#include <memory.h>
#include <iostream>

MDLFrontend::MDLFrontend()
{
}

extern "C" int mdl_lllex_init_extra(void *user_defined, struct llscan_t **scanner);
extern "C" void *mdl_llget_extra(struct llscan_t *yyscanner);
extern "C" void mdl_llset_in(void *user_inputstream, struct llscan_t *scanner);
extern "C" int mdl_lllex(struct llscan_t *scanner, union YYSTYPE *lvalp);
extern "C" int mdl_lllex_destroy(struct llscan_t *scanner);
extern "C" int mdl_yyparse(void *pUserData, struct llscan_t *pScanner);

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include <assert.h>

class PTStream_File
{
    int const m_fd;

public:
    inline PTStream_File(int fd) : m_fd(fd) { assert(fd != -1); }
    inline ~PTStream_File() { close(m_fd); }
    inline ptrdiff_t Read(void *buf, size_t size)
    {
        return read(m_fd, buf, size);
    }
};

void MDLFrontend::compile()
{
    PTStream_File stream{openat(AT_FDCWD, "test.mdl", O_RDONLY)};

    struct llscan_t *scanner;
    mdl_lllex_init_extra(this, &scanner);
    mdl_llset_in(&stream, scanner);
    mdl_yyparse(this, scanner);
    mdl_lllex_destroy(scanner);
}

extern "C" int mdl_ll_stream_read(void *pUserData, void *pUserStream, void *buf, size_t size)
{
    return static_cast<class PTStream_File *>(pUserStream)->Read(buf, size);
}

//https://westes.github.io/flex/manual/Generated-Scanner.html#Generated-Scanner
extern "C" int mdl_llwrap(struct llscan_t *scanner)
{
    void *user_defined = mdl_llget_extra(scanner);
    return 1;
}

extern "C" void *mdl_llalloc(size_t size, struct llscan_t *scanner)
{
    return static_cast<class MDLFrontend *>(mdl_llget_extra(scanner))->callback_malloc(size);
}

extern "C" void *mdl_llrealloc(void *ptr, size_t size, struct llscan_t *scanner)
{
    /* The cast to (char *) in the following accommodates both
	 * implementations that use char* generic pointers, and those
	 * that use void* generic pointers.  It works with the latter
	 * because both ANSI C and C++ allow castless assignment from
	 * any pointer type to void*, and deal with argument conversions
	 * as though doing an assignment.
	 */

    return static_cast<class MDLFrontend *>(mdl_llget_extra(scanner))->callback_realloc(ptr, size);
}

extern "C" void mdl_llfree(void *ptr, struct llscan_t *scanner)
{
    /* see llrealloc() for (char *) cast */

    return static_cast<class MDLFrontend *>(mdl_llget_extra(scanner))->callback_free(ptr);
}

extern "C" int mdl_yylex(union YYSTYPE *lvalp, union YYLTYPE *llocp, void *pUserData, struct llscan_t *pScanner)
{
    //YYEOF==0
    int yytoken = mdl_lllex(pScanner, lvalp);
    return yytoken;
}

extern "C" void mdl_yyerror(YYLTYPE *llocp, void *pUserData, struct llscan_t *pScanner, const char *s)
{
    return static_cast<class MDLFrontend *>(mdl_llget_extra(pScanner))->callback_error(s);
}

void *MDLFrontend::callback_malloc(size_t size)
{
    return malloc(size);
}

void *MDLFrontend::callback_realloc(void *ptr, size_t size)
{
    return realloc(ptr, size);
}

void MDLFrontend::callback_free(void *ptr)
{
    return free(ptr);
}

void MDLFrontend::callback_error(const char *s)
{
    std::cout << s << std::endl;
}
