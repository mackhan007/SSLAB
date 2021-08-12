%{
#include<stdio.h>
#include "y.tab.h"
%}
%%
"<".*\n
[+|-|*|/|=|<|>] {printf("Operator is %s\n",yytext);return OP;}
int|char|bool|float|void|for|do|while|if|else|return|void|main|include|printf {printf("Keyword is %s\n",yytext);return KEY;}
[_a-zA-Z]+ {printf("Identifier is %s\n",yytext);return ID;}
"(".*")" 
. 
%% 


