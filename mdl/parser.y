

%define api.pure full
%define api.value.type {struct mdl_parser_semantic_type}
%locations

//%token <int> YYTOK_INT 

%parse-param {void *pUserData} //{void *pUserData2}
%lex-param {void *pUserData} 

%%

lines: line lines;
lines: line;

line: exp '\n';

exp: addexp;

addexp: addexp '+' n;
addexp: n;

n: '1'|'2'|'3'|'4'|'5'|'6'|'7'|'8'|'9'|'0';

%%
