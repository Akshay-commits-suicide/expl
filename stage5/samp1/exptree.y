%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "exptree.h"
	int yylex(void);
	extern FILE* yyin;
	FILE* fp;
	FILE* intermediate;
	int currentType = -1;
%}

%union {
	struct tnode* no;
	char* name;
	int type;
	Param* param;
}

%token <no> NUM
%token <name> ID
%token <no> STRR
%token TBEGIN
%token END
%token RETURN
%token WRITE READ IF THEN ELSE WHILE DO ENDIF ENDWHILE UNTILL REPEAT BREAK CONTINUE
%token ENDDECL DECL INT STR

%type <no> program stmtlist stmt inputstmt outputstmt asgstmt E ifstmt whilestmt dowhilestmt repeatuntillstmt breakstmt continuestmt function
%type <no> functionlist function
%type <no> arglist
%type <param> paramlist param
%type <no> varlist decllist decl declarations localdecl localdecllist localdeclarations
%type <type> type
%type <no> optsemi

%left NE EQ
%left '<' '>' LE GE
%left '+' '-'
%left '*' '/' '%'

%%

program : declarations functionlist
	{
		$$ = $2;
		resolveAllCalls($2);
		codegenFunctions();
		codegen($2);
	}
	| functionlist
	{
		$$ = $1;
		resolveAllCalls($1);
		codegenFunctions();
		codegen($1);
	}
	;

functionlist : functionlist function
	{
		$$ = makeConnectorNode($1,$2);
	}
	| /* empty */
	{
		$$ = NULL;
	}
	;

function : type ID '(' paramlist ')'
	'{'
	{
		/*
		 * The function may already have been declared
		 * in the global declaration section.
		 */
		installFunction($2,$1,$4);
		beginFunction(lookupFunction($2));
	}
	localdeclarations TBEGIN stmtlist END optsemi '}'
	{
		gsymbol *f = currentFunction;
		$$ = makeFunctionNode(f,$10);
		endFunction();
	}
	;

paramlist : paramlist ',' param
	{
		$$ = appendParam($1,$3);
	}
	| param
	{
		$$ = $1;
	}
	| /* empty */
	{
		$$ = NULL;
	}
	;

param : type ID
	{
		$$ = makeParam($2,$1);
	}
	;

declarations : DECL decllist ENDDECL optsemi
	{
		$$ = NULL;
	}
	| DECL ENDDECL optsemi
	{
		$$ = NULL;
	}
	;

decllist : decllist decl
	{
		$$ = NULL;
	}
	| decl
	{
		$$ = NULL;
	}
	;

/* Global declarations OR function prototypes */
decl : type varlist ';'
	{
		$$ = NULL;
	}
	| type ID '(' paramlist ')' ';'
	{
		installFunction($2,$1,$4);
		$$ = NULL;
	}
	;

varlist : varlist ',' ID '[' NUM ']' '[' NUM ']'
	{
		install($3,currentType,$5->val,$8->val);
		$$=NULL;
	}
	| varlist ',' ID '[' NUM ']'
	{
		install($3,currentType,$5->val,0);
		$$=NULL;
	}
	| varlist ',' '*' ID
	{
		install($4,currentType,1,-1);
		$$=NULL;
	}
	| varlist ',' ID
	{
		install($3,currentType,1,0);
		$$=NULL;
	}
	| ID '[' NUM ']' '[' NUM ']'
	{
		install($1,currentType,$3->val,$6->val);
		$$=NULL;
	}
	| ID '[' NUM ']'
	{
		install($1,currentType,$3->val,0);
		$$=NULL;
	}
	| '*' ID
	{
		install($2,currentType,1,-1);
		$$=NULL;
	}
	| ID
	{
		install($1,currentType,1,0);
		$$=NULL;
	}
	;

localdeclarations : DECL localdecllist ENDDECL optsemi
	{
		$$=NULL;
	}
	| DECL ENDDECL optsemi
	{
		$$=NULL;
	}
	| /* empty */
	{
		$$=NULL;
	}
	;

optsemi : ';'
	{
		$$=NULL;
	}
	| /* empty */
	{
		$$=NULL;
	}
	;

localdecllist : localdecllist localdecl
	{
		$$=NULL;
	}
	| localdecl
	{
		$$=NULL;
	}
	;

localdecl : type localvarlist ';'
	{
		$$=NULL;
	}
	;

localvarlist : localvarlist ',' ID '[' NUM ']' '[' NUM ']'
	{
		installLocal($3,currentType,$5->val,$8->val);
	}
	| localvarlist ',' ID '[' NUM ']'
	{
		installLocal($3,currentType,$5->val,0);
	}
	| localvarlist ',' '*' ID
	{
		installLocal($4,currentType,1,-1);
	}
	| localvarlist ',' ID
	{
		installLocal($3,currentType,1,0);
	}
	| ID '[' NUM ']' '[' NUM ']'
	{
		installLocal($1,currentType,$3->val,$6->val);
	}
	| ID '[' NUM ']'
	{
		installLocal($1,currentType,$3->val,0);
	}
	| '*' ID
	{
		installLocal($2,currentType,1,-1);
	}
	| ID
	{
		installLocal($1,currentType,1,0);
	}
	;

type : INT
	{
		currentType=TYPE_INT;
		$$=TYPE_INT;
	}
	| STR
	{
		currentType=TYPE_STR;
		$$=TYPE_STR;
	}
	;

stmtlist : stmtlist stmt
	{
		$$=makeConnectorNode($1,$2);
	}
	| stmt
	{
		$$=$1;
	}
	;

stmt : inputstmt {$$=$1;}
	| outputstmt {$$=$1;}
	| asgstmt {$$=$1;}
	| ifstmt {$$=$1;}
	| whilestmt {$$=$1;}
	| dowhilestmt {$$=$1;}
	| repeatuntillstmt {$$=$1;}
	| breakstmt {$$=$1;}
	| continuestmt {$$=$1;}
	| RETURN E ';' {$$=makeReturnNode($2);}
	;

ifstmt : IF '(' E ')' THEN stmtlist ELSE stmtlist ENDIF ';'
	{
		$$=makeTreeNode(NODE_IF,$3,$6,$8);
	}
	| IF '(' E ')' THEN stmtlist ENDIF ';'
	{
		$$=makeTreeNode(NODE_IF,$3,$6,NULL);
	}
	;

whilestmt : WHILE '(' E ')' DO stmtlist ENDWHILE ';'
	{
		$$=makeTreeNode(NODE_WHILE,$3,$6,NULL);
	}
	;

repeatuntillstmt : REPEAT stmtlist UNTILL '(' E ')' ';'
	{
		$$=makeTreeNode(NODE_REPEAT,$5,$2,NULL);
	}
	;

dowhilestmt : DO stmtlist WHILE '(' E ')' ';'
	{
		$$=makeTreeNode(NODE_DOWHILE,$5,$2,NULL);
	}
	;

inputstmt : READ '(' ID ')' ';'
	{
		$$=makeReadNode($3);
	}
	| READ '(' '*' ID ')' ';'
	{
		$$=makeReadPointerNode($4);
	}
	| READ '(' ID '[' E ']' ')' ';'
	{
		$$=makeReadArrayNode($3,$5);
	}
	| READ '(' ID '[' E ']' '[' E ']' ')' ';'
	{
		$$=makeRead2DArrayNode($3,$5,$8);
	}
	;

outputstmt : WRITE '(' E ')' ';'
	{
		$$=makeWriteNode($3);
	}
	;

asgstmt : ID '=' E ';'
	{
		$$=makeAssignmentNode($1,$3);
	}
	| '*' ID '=' E ';'
	{
		$$=makePointerAssignmentNode($2,$4);
	}
	| ID '[' E ']' '=' E ';'
	{
		$$=makeAssignmentArrayNode($1,$3,$6);
	}
	| ID '[' E ']' '[' E ']' '=' E ';'
	{
		$$=makeAssignment2DArrayNode($1,$3,$6,$9);
	}
	;

breakstmt : BREAK ';'
	{
		$$=makeBreakNode();
	}
	;

continuestmt : CONTINUE ';'
	{
		$$=makeContinueNode();
	}
	;

E : E '+' E {$$=makeOperatorNode('+',$1,$3);}
  | E '-' E {$$=makeOperatorNode('-',$1,$3);}
  | E '*' E {$$=makeOperatorNode('*',$1,$3);}
  | E '/' E {$$=makeOperatorNode('/',$1,$3);}
  | E '%' E {$$=makeOperatorNode('%',$1,$3);}
  | E '>' E {$$=makeOperatorNode('>',$1,$3);}
  | E '<' E {$$=makeOperatorNode('<',$1,$3);}
  | E NE E {$$=makeOperatorNode('n',$1,$3);}
  | E EQ E {$$=makeOperatorNode('e',$1,$3);}
  | E LE E {$$=makeOperatorNode('l',$1,$3);}
  | E GE E {$$=makeOperatorNode('g',$1,$3);}
  | '(' E ')' {$$=$2;}
  | NUM {$$=$1;}
  | STRR {$$=$1;}
  | ID '[' E ']' '[' E ']' {$$=make2DArrayNode($1,$3,$6);}
  | ID '[' E ']' {$$=makeArrayNode($1,$3);}
  | '*' ID {$$=makeDeReferenceNode($2);}
  | '&' ID {$$=makeAddressNode($2);}
  | ID {$$=makeVariableNode($1);}
  | ID '(' arglist ')' {$$=makeCallNode($1,$3,countArguments($3));}
  ;

arglist : /* empty */
	{
		$$=NULL;
	}
	| E
	{
		$$=$1;
	}
	| arglist ',' E
	{
		$$=makeConnectorNode($1,$3);
	}
	;

%%

int yyerror(char *s)
{
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

	intermediate=fopen("ex2.xsm","w");

	fprintf(intermediate,"0\n2056\n0\n0\n0\n0\n0\n1\n");
	fprintf(intermediate,"MOV SP, 5000\n");

	fp=fopen(argv[1],"r");

	if(!fp)
	{
		printf("Invalid file specs");
		exit(1);
	}

	yyin=fp;
	yyparse();

	//fprintf(intermediate,"INT 10\n");

	fclose(fp);
	fclose(intermediate);

	return 0;
}
