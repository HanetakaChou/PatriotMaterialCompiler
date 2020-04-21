#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

extern ptrdiff_t mdl_ll_stream_read(void *pUserData, void *pUserStream, void *buf, size_t size);

#define YY_INPUT(buf, result, max_size)                                              \
    {                                                                                \
        (*(&result)) = mdl_ll_stream_read((yyextra), ((void *)yyin), buf, max_size); \
        if (result == -1)                                                            \
        {                                                                            \
            YY_FATAL_ERROR("input in flex scanner failed");                          \
        }                                                                            \
    }

#define YY_DECL int mdl_lllex(yyscan_t yyscanner, union YYSTYPE *lvalp)

#include "mdl_yyparser.h"
int SCAN_INTEGER_LITERAL_DECIMAL(char const *pBegin, char const *pEnd);
int SCAN_INTEGER_LITERAL_HEXADECIMAL(char const *pBegin, char const *pEnd);
int SCAN_INTEGER_LITERAL_OCTAL(char const *pBegin, char const *pEnd);

#include "mdl_lllexer.inl"

static void _static_assert_mdl_ll_lexer_(void)
{
    char _static_assert_yy_size_t_[((sizeof(yy_size_t) == sizeof(size_t)) ? 1 : -1)];
    char _static_assert_yyscan_t_[((sizeof(yyscan_t) == sizeof(void *)) ? 1 : -1)];
}

#include <assert.h>

int SCAN_INTEGER_LITERAL_DECIMAL(char const *pBegin, char const *pEnd)
{
    int integer_value = 0;
    for (char const *pCh = pBegin; pCh < pEnd; ++pCh)
    {
        integer_value *= 10;
        assert((*pCh) >= '0' && (*pCh) <= '9');
        integer_value += ((*pCh) - '0');
    }
    return integer_value;
}

int SCAN_INTEGER_LITERAL_HEXADECIMAL(char const *pBegin, char const *pEnd)
{
    int integer_value = 0;
    assert((*pBegin) == '0' && ((*(pBegin + 1)) == 'x' || (*(pBegin + 1)) == 'X'));
    for (char const *pCh = (pBegin + 2); pCh < pEnd; ++pCh)
    {
        integer_value *= 16;
        assert(((*pCh) >= '0' && (*pCh) <= '9') || ((*pCh) >= 'A' && (*pCh) <= 'F') || ((*pCh) >= 'a' && (*pCh) <= 'f'));
        assert('9' < 'A' && 'F' < 'a');
        integer_value += ((*pCh) <= '9') ? ((*pCh) - '0') : (((*pCh) <= 'F') ? (((*pCh) - 'A') + 10) : (((*pCh) - 'a') + 10));
    }
    return integer_value;
}

int SCAN_INTEGER_LITERAL_OCTAL(char const *pBegin, char const *pEnd)
{
    int integer_value = 0;
    for (char const *pCh = pBegin; pCh < pEnd; ++pCh)
    {
        integer_value *= 8;
        assert((*pCh) >= '0' && (*pCh) <= '7');
        integer_value += ((*pCh) - '0');
    }
    return integer_value;
}
