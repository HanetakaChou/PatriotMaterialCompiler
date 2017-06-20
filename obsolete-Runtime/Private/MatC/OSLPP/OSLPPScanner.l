%option reentrant
%option prefix="oslpp_ll"
%option noinput
%option nounput
%option batch
%option fast
%option nounistd
%option never-interactive
%option noyyalloc
%option noyyfree
%option noyyrealloc
%option yylineno

    /* https://westes.github.io/flex/manual/Start-Conditions.html#Start-Conditions */
%x incl
%s incl2

    /* https://westes.github.io/flex/manual/Patterns.html#Patterns */

%%

("//"((.)*)) {
    /* Single line comment */
    }  

("/*"((("*"[^/])?)|[^*])*"*/") {
    /* Multiline comment */
    }

("/*") { 
    YY_FATAL_ERROR("Unterminated comment");
    }

(^'#include')  { BEGIN(incl);}

<incl>([ \t]*)    {  /* eat the whitespace */}
<incl>[^ \t\n]+   {  
    /* got the include file name */
    /* call_back */
    if()
    {
        YY_FATAL_ERROR("Unterminated comment");
    }
    
    yypush_buffer_state(yy_create_buffer( yyin, YY_BUF_SIZE ));
    BEGIN(incl2);
    }

<incl2><<EOF>> {
    

}

%%