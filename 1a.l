%{
#include<stdio.h>
int t=-1,o=0,i=0;
char s[10];
%}

%%
[+] {o++;printf("%s is operator %d\n",yytext,o);}
[*] {o++;printf("%s is operator %d\n",yytext,o);}
[/] {o++;printf("%s is operator %d\n",yytext,o);}
[\-] {o++;printf("%s is operator  %d\n",yytext,o);}
[\n] {return 0;}
[0-9]+ {i++;printf("%s is identifier %d\n",yytext,i);}
[(] {s[++t]='(';}
[)] {if(s[t]=='('&& i-o==1) t--; else printf("invalid expression\n");}
%%
int main()
{
printf("enter the expression\n");
yylex();
if(t!=-1 || o>=i || i==1)
{printf("invalid expression\n");
return 0;}
else {printf("valid expression\n");
printf("number of operators%d and identifiers%d\n",o,i);
return 0;}
}
/* run cmd
    lex 1a.l
    gcc lex.yy.c -ll
    ./a.out
*/