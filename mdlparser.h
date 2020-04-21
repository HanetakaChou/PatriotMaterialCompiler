#ifndef _MDLPARSER_H_
#define _MDLPARSER_H_ 1

struct mdl_parser_semantic_type
{
    
};

struct mdl_parser_location_type
{
    int first_line;
    int first_column;
    int last_line;
    int last_column;
};

#ifdef __cplusplus
extern "C"
{
#endif
    int mdlparse(void *pUserData);
    int mdllex(void *pUserData, struct mdl_parser_semantic_type *lvalp, struct mdl_parser_location_type *llocp);
    extern void mdlerror(void *pUserData, const char *s);
#ifdef __cplusplus
}
#endif

#endif