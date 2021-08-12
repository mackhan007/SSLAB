%{
#include<stdio.h>
int br=0,opr=0,id=0;
%}
%x OPR
%%
[0-9]+ {BEGIN(OPR);id++;printf("%s is an identifier\n",yytext);}
[\t\n]+
[(] {br++;}
[^0-9]+ {printf("Invalid Expression\n");exit(0);}
<OPR>[+\-*/] {BEGIN(0);opr++;printf("%s is an operator\n",yytext);}
<OPR>[\t\n]+
<OPR>[)] {br--;}
<OPR><<EOF>> {return 0;}
<OPR>. {printf("Invalid Expresion\n");exit(0);}
%%
int main()
{
	printf("Enter the Expression:\n");
	yylex();
	if(br!=0||(id == 1 && (opr == 0 || opr == 1)))
	{
		printf("Invalid Expression\n");
		return 0;
	}
	else
	{
		printf("Valid Expression\n");
		printf("Identifier count = %d\nOperator count = %d\n",id,opr);
	}
return 0;
}
int yywrap(){return(1);}

/* run cmd
    lex 1a.l
    gcc lex.yy.c -ll
    ./a.out
*/