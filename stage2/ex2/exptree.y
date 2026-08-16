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
	char* name;
}


%token <no> NUM
%token <name> ID

%token BEGIN
%token END
%token WRITE
%token READ

%type <no> program
%type <no> stmtlist
%type <no> stmt
%type <no> inputstmt
%type <no> outputstmt
%type <no> asgstmt
%type <no> E


%left '+' '-'
%left '*' '/'

%%

program : BEGIN stmtlist  END ';' 
	{
		$$=$2;
		evaluate($2);
		codegen($2);
		
	}
	| BEGIN END ';'
	{
		$$=NULL;
	}
	;

stmtlist
	: stmtlist stmt
	{
		$$ = makeConnectorNode($1,$2);
	}
	| stmt
	{
		$$ = $1;	
	}
	;
stmt
	: inputstmt
	{
		$$ = $1;
	}
	| outputstmt
	{
		$$ = $1;
	}
	| asgstmt
	{
		$$ = $1;
	}
	;

inputstmt
	: READ '(' ID ')' ';'
	{
		$$ = makeReadNode($3);
	}

outputstmt
	: WRITE '(' E ')' ';'
	{
		$$ = makeWriteNode($3);
	}
	;

asgstmt
	: ID '=' E ';'
	{
		$$ = makeAssignmentNode($1,$3);
	}
	;
	
E : 
    E '+' E
    {
        $$ = makeOperatorNode('+', $1, $3);
    }
  | E '-' E
    {
        $$ = makeOperatorNode('-', $1, $3);
    }
  | E '*' E
    {
        $$ = makeOperatorNode('*', $1, $3);
    }
  | E '/' E
    {
        $$ = makeOperatorNode('/', $1, $3);
    }
  | '(' E ')'
    {
        $$ = $2;
    }
  | NUM
    {
        $$ = $1;
    }
  | ID
  {
	$$ = makeVariableNode($1);
  }
  ;

%%

int yyerror(char *s){
	printf("yyerror:%s\n",s);
	return 0;
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
		intermediate = fopen("ex2.xsm","w");
		fprintf(intermediate,"0\n2056\n0\n0\n0\n0\n0\n1\n");
		fprintf(intermediate,"MOV SP, 4121\n");
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
	fprintf(intermediate,"INT 10\n");
	return 0;
}
