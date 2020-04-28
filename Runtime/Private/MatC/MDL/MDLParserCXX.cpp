#include "MDLParser.h"
#include "MDLFrontend.h"
#include <stdexcept>
extern "C" int mdl_lllex(struct llscan_t *scanner, union YYSTYPE *lvalp, struct YYLTYPE *llocp);

extern "C" int mdl_yylex(union YYSTYPE *lvalp, struct YYLTYPE *llocp, class MDLFrontend *pUserData, struct llscan_t *pScanner)
{
    try
    {
        int yytoken = mdl_lllex(pScanner, lvalp, llocp);
        return yytoken;
    }
    catch (const std::exception &e)
    {
		pUserData->Callback_Error(e.what());
		return YYTOKEN_EOF;
    }
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

extern "C" void mdl_yyerror(YYLTYPE *llocp, class MDLFrontend *pUserData, struct llscan_t *, const char *s)
{
	char msg_yyerror[4096];
	snprintf(msg_yyerror, 4096, "%s at line %d column %d", s, llocp->first_line, llocp->first_column);
	pUserData->Callback_Error(msg_yyerror);
}

extern "C" void *mdl_yyalloc(size_t size, class MDLFrontend *pUserData)
{
	return pUserData->Callback_Malloc(size);
}

extern "C" void *mdl_yyrealloc(void *ptr, size_t size, class MDLFrontend *pUserData)
{
	return pUserData->Callback_Realloc(ptr, size);
}

extern "C" void mdl_yyfree(void *ptr, class MDLFrontend *pUserData)
{
	return pUserData->Callback_Free(ptr);
}