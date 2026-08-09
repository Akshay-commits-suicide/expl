%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "exptree.h"
	int yylex(void);
	extern FILE* yyin;
	FILE* fp;
	FILE* intermediate;
	void print(int);
%}

%union {
	struct tnode* no;
}

%type <no> E program
%token <no> NUM
%token END
%left '+' '-'
%left '*' '/'

%%

program : E END 
	{
		int r=codegen($1);
		preorder($1);
		printf("\n");
		postorder($1);
		print(r);
	};
	
E : E '+' E
    {
        $$ = makeOperatorNode('+', $1, $3);
    }
  | '(' E ')'
    {
        $$ = $2;
    }
  | NUM
    {
        $$ = $1;
    }
  ;

%%

int yyerror(char *s){
	printf("yyerror:%s\n",s);
	return 0;
}
void print(int r)
{
    fprintf(intermediate, "MOV [4096], R%d\n", r);

    fprintf(intermediate, "MOV R2, \"Write\"\n");
    fprintf(intermediate, "PUSH R2\n");
    fprintf(intermediate, "MOV R2, -2\n");
    fprintf(intermediate, "PUSH R2\n");
    fprintf(intermediate, "PUSH R%d\n", r);
    fprintf(intermediate, "PUSH R2\n");
    fprintf(intermediate, "PUSH R2\n");
    fprintf(intermediate, "CALL 0\n");
    fprintf(intermediate, "POP R0\n");
    fprintf(intermediate, "POP R1\n");
    fprintf(intermediate, "POP R1\n");
    fprintf(intermediate, "POP R1\n");
    fprintf(intermediate, "POP R1\n");
    fprintf(intermediate, "MOV R2, \"Exit\"\n");
    fprintf(intermediate, "PUSH R2\n");
    fprintf(intermediate, "PUSH R2\n");
    fprintf(intermediate, "PUSH R2\n");
    fprintf(intermediate, "PUSH R2\n");
    fprintf(intermediate, "PUSH R2\n");
    fprintf(intermediate, "CALL 0\n");
    fprintf(intermediate, "INT 10\n");
    exit(1);
}
int main(int argc,char *argv[])
{
	if(argc<2)
	{
		printf("No input for filename\n");
		exit(1);
	}
	else
	{
		intermediate = fopen("ex1.xsm","w");
		fprintf(intermediate,"0\n2056\n0\n0\n0\n0\n0\n1\n");
		fp = fopen(argv[1], "r");
		if(!fp)
		{
			printf("Invalid file specs");
			exit(1);
		}
		else
		{
			yyin=fp;
		}
	}
	yyparse();
	return 0;
}
