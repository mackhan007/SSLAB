%{
#include<stdio.h>
#include<stdlib.h>
int yylex();
int yyerror();
%}
%token A B NL
%%
str:S NL {return 0;}
S:A S|A B;
%%
int main()
{
	printf("\nEnter A String\n");
	yyparse();
	printf("Successful Grammar\n");
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
