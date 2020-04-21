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

//https://www.gnu.org/software/bison/manual/bison.html#Location-Type
struct YYLTYPE
{
    int first_line;
    int first_column;
    int last_line;
    int last_column;
};
typedef struct YYLTYPE YYLTYPE;

#define YY_DECL int mdl_lllex(yyscan_t yyscanner, union YYSTYPE *lvalp, struct YYLTYPE *llocp)

size_t MDLFrontend_HashIdentName(void *pUserData, char const *pIdentName);

#include <stdlib.h>
#include <assert.h>
#include "MDLParser.h"

#include "MDLScanner.inl"

static void _static_assert_mdl_ll_lexer_(void)
{
    char _static_assert_yy_size_t_[((sizeof(yy_size_t) == sizeof(size_t)) ? 1 : -1)];
    char _static_assert_yyscan_t_[((sizeof(yyscan_t) == sizeof(void *)) ? 1 : -1)];
}