%{
#include "y.tab.h"
%}
%%
a {return A;}
b {return B;}
. return yytext[0];
\n return NL;
%%

/* run cmd
    yacc -d 2.y  
    lex 2.l
    gcc lex.yy.c y.tab.c -ll
    ./a.out
*/