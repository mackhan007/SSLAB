%{
#include<stdio.h>
#include<stdlib.h>
int yylex();
int yyerror();
int id=0,key=0,op=0;
%}
%token ID KEY OP
%%
input:ID input {++id;}
|KEY input {++key;}
|OP input {++op;}
|ID {++id;}
|KEY {++key;}
|OP {++op;}
;
%%
extern FILE *yyin;
int main()
{
	yyin=fopen("input.c","r");
	yyparse();
	printf("Identifiers = %d\nKeywords = %d\nOperators = %d\n",id,key,op);
}
int yyerror()
{
	printf("\nError \n");
	exit(0);
}


/* run cmd
    yacc -d 2.y  
    lex 2.l
    gcc lex.yy.c y.tab.c -ll
    ./a.out
*/
