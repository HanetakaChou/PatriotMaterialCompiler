#include "PT_MatC_Stream.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include <assert.h>


PT_MatC_Stream_File::PT_MatC_Stream_File(char const *filename) : m_fd(openat(AT_FDCWD, filename, O_RDONLY))
{
    assert(m_fd != -1);
}

PT_MatC_Stream_File::~PT_MatC_Stream_File()
{
    close(m_fd);
}

ptrdiff_t PT_MatC_Stream_File::Read(void *buf, size_t size)
{
    return read(m_fd, buf, size);
}
