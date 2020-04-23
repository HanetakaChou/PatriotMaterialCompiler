#ifndef _PT_MATC_STREAM_H_
#define _PT_MATC_STREAM_H_ 1

#include <stddef.h>

class PT_MatC_Stream
{
public:
    virtual ptrdiff_t Read(void *buf, size_t size) = 0;
};

class PT_MatC_Stream_File : public PT_MatC_Stream
{
    int const m_fd;

public:
    PT_MatC_Stream_File(char const *filename);
    ~PT_MatC_Stream_File();
    ptrdiff_t Read(void *buf, size_t size);
};

#endif