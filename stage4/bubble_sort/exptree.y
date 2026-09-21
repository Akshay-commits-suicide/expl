%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "exptree.h"
	int yylex(void);
	extern FILE* yyin;
	FILE* fp;
	FILE* intermediate;
	void print(int);
	int currentType = -1;
%}

%union {
	struct tnode* no;
	char* name;
	int type;
}


%token <no> NUM
%token <name> ID
%token <no>  STRR

%token TBEGIN
%token END
%token WRITE
%token READ
%token IF
%token THEN
%token ELSE
%token WHILE
%token DO
%token ENDIF
%token ENDWHILE
%token UNTILL
%token REPEAT
%token BREAK
%token CONTINUE
%token ENDDECL
%token DECL
%token INT
%token STR

%type <no> program
%type <no> stmtlist
%type <no> stmt
%type <no> inputstmt
%type <no> outputstmt
%type <no> asgstmt
%type <no> E
%type <no> ifstmt
%type <no> whilestmt
%type <no> dowhilestmt
%type <no> repeatuntillstmt
%type <no> breakstmt
%type <no> continuestmt
%type <no> varlist
%type <no> decllist
%type <no> decl
%type <no> declarations
%type <type> type

%left NE EQ
%left '<' '>' LE GE
%left '+' '-'
%left '*' '/'

%%

program : declarations stmtlist
	{
		$$=$2;
		printt();
		evaluate($2);
		codegen($2);
	}
	| declarations
	{
		$$ = NULL;
	}
	;

declarations : DECL decllist ENDDECL ';'
	     {

	     }
	     | DECL ENDDECL ';'
	     {

	     };

decllist : decllist decl
	{

	}
	| decl
	{

	};

decl : type varlist ';'
     {

     }
     ;

varlist : varlist ',' ID '[' NUM ']' '[' NUM ']'
	{
		install($3,currentType,$5->val,$8->val);
	}
	| varlist ',' ID '[' NUM ']'
	{
		 install($3,currentType,$5->val,0);
	}
	| varlist ',' ID
	{
		install($3,currentType,1,0);
	}
	| ID '[' NUM ']' '[' NUM ']'
	{
		install($1,currentType,$3->val,$6->val);
	}
	| ID '[' NUM ']'
	{
		install($1,currentType,$3->val,0);
	}
	| ID
	{
		install($1,currentType,1,0);
	}
	;

type : INT
     {
	currentType = TYPE_INT;
     }
     | STR
     {
	currentType = TYPE_STR;
     }
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
	| ifstmt
	{
		$$ = $1;
	}
	| whilestmt
	{
		$$ = $1;
	}
	| dowhilestmt
	{
		$$ = $1;
	}
	| repeatuntillstmt
	{
		$$ = $1;
	}
	| breakstmt
	{
		$$ = $1;
	}
	| continuestmt
	{
		$$ = $1;
	}
	;
ifstmt
	: IF '(' E ')' THEN stmtlist ELSE stmtlist ENDIF ';'
	{
		$$ = makeTreeNode(NODE_IF,$3,$6,$8);
	}
	| IF '(' E ')' THEN stmtlist ENDIF ';'
	{
		$$ = makeTreeNode(NODE_IF,$3,$6,NULL);
	}
	;
whilestmt
	: WHILE '(' E ')' DO stmtlist ENDWHILE ';'
	{
		$$ = makeTreeNode(NODE_WHILE,$3,$6,NULL);
	}
	;
repeatuntillstmt
		: REPEAT stmtlist UNTILL '(' E ')' ';'
		{
			$$ = makeTreeNode(NODE_REPEAT,$5,$2,NULL);
		}
		;
dowhilestmt
	  : DO stmtlist WHILE '(' E ')' ';'
	  {
		$$ = makeTreeNode(NODE_DOWHILE,$5,$2,NULL);
	  }
	  ;
inputstmt
	: READ '(' ID ')' ';'
	{
		gsymbol* sym = lookup($3);
		if(sym->size>1 || sym->size1 != 0)
		{
			yyerror("ERROR:Cannot accept array input as a whole.Use arr[i] to take input!");
		}
		$$ = makeReadNode($3);
	}
	| READ '(' ID '[' E ']' ')' ';'
	{
		$$ = makeReadArrayNode($3,$5);
	}
	| READ '(' ID '[' E ']' '[' E ']' ')' ';'
	{
		$$ = makeRead2DArrayNode($3,$5,$8);
	}
	;
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
	| ID '[' E ']' '=' E ';'
	{
		$$ = makeAssignmentArrayNode($1,$3,$6);
	}
	| ID '[' E ']' '[' E ']' '=' E ';'
	{
		$$ = makeAssignment2DArrayNode($1,$3,$6,$9);
	}
	;
breakstmt
	: BREAK ';'
	{
		$$ = makeBreakNode();
	}
	;
continuestmt
	: CONTINUE ';'
	{
		$$ = makeContinueNode();
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
  | E '>' E
    {
        $$ = makeOperatorNode('>', $1, $3);
    }
  | E '<' E
    {
        $$ = makeOperatorNode('<', $1, $3);
    }
  | E NE E
    {
        $$ = makeOperatorNode('n', $1, $3);
    }
  | E EQ E
    {
        $$ = makeOperatorNode('e', $1, $3);
    }
  | E LE E
    {
        $$ = makeOperatorNode('l', $1, $3);
    }
  | E GE E
    {
        $$ = makeOperatorNode('g', $1, $3);
    }
  | '(' E ')'
    {
        $$ = $2;
    }
  | NUM
    {
        $$ = $1;
    }
  | STRR
  {
	$$ =$1;
  }
	| ID '[' E ']' '[' E ']'
	{
			$$ = make2DArrayNode($1,$3,$6);
	}
  | ID '[' E ']'
  {
		$$ = makeArrayNode($1,$3);
  }
  | ID
  {
		$$ = makeVariableNode($1);
  }
  ;

%%

int yyerror(char *s){
	printf("yyerror:%s\n",s);
	exit(1);
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
		fprintf(intermediate,"MOV SP, 5000\n");
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
