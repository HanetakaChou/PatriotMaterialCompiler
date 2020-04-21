#include "PTInputStream.h"

#include <stddef.h>

extern "C" int PTInputStream_Read(void *pUserData, void *pUserStream, void *buf, size_t max_size)
{
    return 0;
}

