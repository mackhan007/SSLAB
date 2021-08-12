%{
#include<stdio.h>
#include<stdlib.h>
int yylex();
int yyerror();
%}
%token NUM
%left'+''-'
%left'*''/'
%%
start: expr {printf("Result is %d\n",$1);return 0;}
expr:expr'+'expr{$$=$1+$3;}
|expr'-'expr{$$=$1-$3;}
|expr'*'expr{$$=$1*$3;}
|expr'/'expr{ { if($3==0){printf("Divide by Zero error\n");exit(0);} else
$$=$1/$3;}}
|'('expr')'{$$=$2;}
|NUM {$$=$1;};
%%
int main()
{
	printf("\nEnter an Expression: \n");
	yyparse();
}
int yyerror()
{
	printf("\nError \n");
	exit(0);
}