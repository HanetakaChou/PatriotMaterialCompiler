#ifndef _MDLPARSER_H_
#define _MDLPARSER_H_ 1

struct mdl_parser_semantic_type
{
};

#ifdef __cplusplus
extern "C"
{
#endif
    int mdlparse(void *pUserData);
    int mdllex(void *pUserData, struct mdl_parser_semantic_type *lvalp, int mdl_parser_location_first_line, int mdl_parser_location_first_column, int mdl_parser_location_last_line, int mdl_parser_location_last_column);
    extern void mdlerror(void *pUserData, const char *s);
#ifdef __cplusplus
}
#endif

#endif