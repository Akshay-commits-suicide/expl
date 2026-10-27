%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "exptree.h"

    int yylex(void);
    extern FILE* yyin;

    FILE* fp;
    FILE* intermediate;

    int currentType = -1;
    typedef struct FieldTmp { char *name; int type; struct FieldTmp *next; } FieldTmp;
    static FieldTmp *appendField(FieldTmp *a, FieldTmp *b) { if(!a)return b; FieldTmp *p=a; while(p->next)p=p->next; p->next=b; return a; }
    static char *pendingTupleType = NULL;
    static char *currentUserTypeName = NULL;
    static char *currentClassName = NULL;
    static void defineTupleAndInstall(char *tn, FieldTmp *f, char *vars) { (void)tn; (void)f; (void)vars; }
%}

%union {
    struct tnode* no;
    char* name;
    int type;
    Param* param;
    struct FieldTmp* fields;
}

%token <no> NUM
%token <name> ID
%token <no> STRR

%token TBEGIN
%token END
%token RETURN
%token WRITE READ
%token IF THEN ELSE
%token WHILE DO
%token ENDIF ENDWHILE
%token UNTILL REPEAT
%token BREAK CONTINUE
%token ENDDECL DECL
%token INT STR TUPLE TYPEDEF ENDTYPE CLASS ENDCLASS SELF NEW
%token <no> NULLTOK

%type <no> program
%type <no> stmtlist stmt callstmt
%type <no> inputstmt outputstmt asgstmt
%type <no> E
%type <no> ifstmt whilestmt dowhilestmt repeatuntillstmt
%type <no> breakstmt continuestmt
%type <no> function functionlist
%type <no> arglist field typeblock typeDefList typeDef fieldDeclList fieldDecl classblock classDefList classDef classMemberList classMember classMethodDefList classMethodDef

%type <param> paramlist param
%type <fields> tuplefields tuplefield

%type <no> varlist decllist decl declarations
%type <no> localdecl localdecllist localdeclarations
%type <type> type

%type <no> optsemi

%left NE EQ
%left '<' '>' LE GE
%left '+' '-'
%left '*' '/' '%'

%%


/* ============================================================
   PROGRAM
   ============================================================ */

program
    : typeblock classblock declarations functionlist
      {
          $$ = $4;
          resolveAllCalls($4);
          codegenFunctions();
          codegen($4);
      }
    | typeblock classblock functionlist
      {
          $$ = $3;
          resolveAllCalls($3);
          codegenFunctions();
          codegen($3);
      }
    | typeblock classblock declarations TBEGIN stmtlist END optsemi
      {
          $$ = $5;
          resolveAllCalls($5);
          codegenFunctions();
          codegen($5);
      }
    | typeblock classblock TBEGIN stmtlist END optsemi
      {
          $$ = $4;
          resolveAllCalls($4);
          codegenFunctions();
          codegen($4);
      }
    ;

typeblock
    : TYPEDEF typeDefList ENDTYPE optsemi
      { $$ = NULL; }
    | /* empty */
      { $$ = NULL; }
    ;

typeDefList
    : typeDefList typeDef
      { $$ = NULL; }
    | typeDef
      { $$ = NULL; }
    ;

typeDef
    : ID
      {
          beginUserType($1);
          currentUserTypeName = $1;
      }
      '{' fieldDeclList '}' ';'
      { currentUserTypeName = NULL; $$ = NULL; }
    ;

fieldDeclList
    : fieldDeclList fieldDecl
      { $$ = NULL; }
    | fieldDecl
      { $$ = NULL; }
    ;

fieldDecl
    : type ID ';'
      {
          addUserTypeField(currentUserTypeName, $1, $2);
          $$ = NULL;
      }
    ;


/* ============================================================
   STAGE 7 CLASSES
   Classes reuse the existing user-type field layout. Methods are lowered
   to ordinary functions named ClassName__method, with an implicit first
   parameter named self. Existing AST, symbol tables and calling convention
   remain in place.
   ============================================================ */

classblock
    : CLASS classDefList ENDCLASS optsemi { $$ = NULL; }
    | /* empty */ { $$ = NULL; }
    ;

classDefList
    : classDefList classDef { $$ = NULL; }
    | classDef { $$ = NULL; }
    ;

classDef
    : ID '{'
      {
          beginClass($1);
          currentClassName = strdup($1);
      }
      DECL classMemberList ENDDECL classMethodDefList '}'
      {
          validateClassMethods(currentClassName);
          currentClassName = NULL;
          $$ = NULL;
      }
    ;

classMemberList
    : classMemberList classMember { $$ = NULL; }
    | /* empty */ { $$ = NULL; }
    ;

classMember
    : type ID ';'
      {
          addUserTypeField(currentClassName, $1, $2);
          $$ = NULL;
      }
    | type ID '(' paramlist ')' ';'
      {
          char *mn = mangleMethodName(currentClassName, $2);
          Param *all = prependSelfParam(currentClassName, $4);
          installFunction(mn, $1, all, isUserType($1));
          $$ = NULL;
      }
    ;

classMethodDefList
    : classMethodDefList classMethodDef { $$ = NULL; }
    | classMethodDef { $$ = NULL; }
    | /* empty */ { $$ = NULL; }
    ;

classMethodDef
    : type ID '(' paramlist ')'
      '{'
      {
          char *mn = mangleMethodName(currentClassName, $2);
          Param *all = prependSelfParam(currentClassName, $4);
          installFunction(mn, $1, all, isUserType($1));
          beginFunction(lookupFunction(mn));
      }
      localdeclarations TBEGIN stmtlist END optsemi '}'
      {
          gsymbol *f = currentFunction;
          makeFunctionNode(f, $10);
          endFunction();
          $$ = NULL;
      }
    ;

/* ============================================================
   FUNCTION LIST
   ============================================================ */

functionlist
    : functionlist function
      {
          $$ = makeConnectorNode($1,$2);
      }

    | /* empty */
      {
          $$ = NULL;
      }
    ;


/* ============================================================
   FUNCTION DEFINITIONS
   ============================================================ */

/* Normal return type */

function
    : type ID '(' paramlist ')'
      '{'
      {
          installFunction($2, $1, $4, isUserType($1));
          beginFunction(lookupFunction($2));
      }
      localdeclarations TBEGIN stmtlist END optsemi '}'
      {
          gsymbol *f = currentFunction;
          $$ = makeFunctionNode(f,$10);
          endFunction();
      }

    /* Pointer return type */

    | type '*' ID '(' paramlist ')'
      '{'
      {
          installFunction($3, $1, $5, 1);
          beginFunction(lookupFunction($3));
      }
      localdeclarations TBEGIN stmtlist END optsemi '}'
      {
          gsymbol *f = currentFunction;
          $$ = makeFunctionNode(f,$11);
          endFunction();
      }
    ;


/* ============================================================
   PARAMETERS
   ============================================================ */

paramlist
    : paramlist ',' param
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


param
    : type ID
      {
          $$ = makeParam($2,$1,isUserType($1));
      }

    | type '*' ID
      {
          $$ = makeParam($3,$1,1);
      }
    ;


/* ============================================================
   GLOBAL DECLARATIONS / FUNCTION PROTOTYPES
   ============================================================ */

declarations
    : DECL decllist ENDDECL optsemi
      {
          $$ = NULL;
      }

    | DECL ENDDECL optsemi
      {
          $$ = NULL;
      }
    ;


decllist
    : decllist decl
      {
          $$ = NULL;
      }

    | decl
      {
          $$ = NULL;
      }
    ;


/* Normal variable declaration */

decl
    : TUPLE ID '(' tuplefields ')'
      {
          int n=0; for(FieldTmp *f=$4;f;f=f->next)n++;
          char **names=calloc(n,sizeof(char*)); int *types=calloc(n,sizeof(int)); int i=0;
          for(FieldTmp *f=$4;f;f=f->next){ names[i]=f->name; types[i++]=f->type; }
          defineTupleType($2,names,types,n);
          pendingTupleType = $2;
      }
      ID tuplevarlist ';'
      {
          installTupleVariable(pendingTupleType,$7,0);
          $$=NULL;
      }
    | type varlist ';'
      {
          $$ = NULL;
      }

    /* Normal function prototype */

    | type ID '(' paramlist ')' ';'
      {
          installFunction($2,$1,$4,isUserType($1));
          $$ = NULL;
      }

    /* Pointer-returning function prototype */

    | type '*' ID '(' paramlist ')' ';'
      {
          installFunction($3,$1,$5,1);
          $$ = NULL;
      }
    ;


/* ============================================================
   GLOBAL VARIABLE LIST
   ============================================================ */

tuplevarlist
    : /* empty */ { }
    | ',' ID { installTupleVariable(pendingTupleType,$2,0); }
    | tuplevarlist ',' ID { installTupleVariable(pendingTupleType,$3,0); }
    ;

tuplefields
    : tuplefield { $$=$1; }
    | tuplefields ',' tuplefield { $$=appendField($1,$3); }
    ;
tuplefield
    : INT ID { $$=calloc(1,sizeof(FieldTmp)); $$->name=$2; $$->type=TYPE_INT; }
    | STR ID { $$=calloc(1,sizeof(FieldTmp)); $$->name=$2; $$->type=TYPE_STR; }
    ;

varlist
    : varlist ',' ID '[' NUM ']' '[' NUM ']'
      {
          install($3,currentType,$5->val,$8->val);
          $$ = NULL;
      }

    | varlist ',' ID '[' NUM ']'
      {
          install($3,currentType,$5->val,0);
          $$ = NULL;
      }

    | varlist ',' '*' ID
      {
          install($4,currentType,1,-1);
          $$ = NULL;
      }

    | varlist ',' ID
      {
          install($3,currentType,1,0);
          $$ = NULL;
      }

    | ID '[' NUM ']' '[' NUM ']'
      {
          install($1,currentType,$3->val,$6->val);
          $$ = NULL;
      }

    | ID '[' NUM ']'
      {
          install($1,currentType,$3->val,0);
          $$ = NULL;
      }

    | '*' ID
      {
          install($2,currentType,1,-1);
          $$ = NULL;
      }

    | ID
      {
          install($1,currentType,1,0);
          $$ = NULL;
      }
    ;


/* ============================================================
   LOCAL DECLARATIONS
   ============================================================ */

localdeclarations
    : DECL localdecllist ENDDECL optsemi
      {
          $$ = NULL;
      }

    | DECL ENDDECL optsemi
      {
          $$ = NULL;
      }

    | /* empty */
      {
          $$ = NULL;
      }
    ;


optsemi
    : ';'
      {
          $$ = NULL;
      }

    | /* empty */
      {
          $$ = NULL;
      }
    ;


localdecllist
    : localdecllist localdecl
      {
          $$ = NULL;
      }

    | localdecl
      {
          $$ = NULL;
      }
    ;


localdecl
    : type localvarlist ';'
      {
          $$ = NULL;
      }
    | TUPLE ID ID ';'
      {
          installTupleVariable($2,$3,1);
          $$ = NULL;
      }
    ;


/* ============================================================
   LOCAL VARIABLE LIST
   ============================================================ */

localvarlist
    : localvarlist ',' ID '[' NUM ']' '[' NUM ']'
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


/* ============================================================
   TYPES
   ============================================================ */

type
    : INT
      {
          currentType = TYPE_INT;
          $$ = TYPE_INT;
      }

    | STR
      {
          currentType = TYPE_STR;
          $$ = TYPE_STR;
      }

    | ID
      {
          int userType = lookupUserType($1);
          if (userType < 0)
              yyerror("ERROR: Undeclared user-defined type\\n");
          currentType = userType;
          $$ = userType;
      }
    ;


/* ============================================================
   STATEMENTS
   ============================================================ */

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

    | RETURN E ';'
      {
          $$ = makeReturnNode($2);
      }

    | callstmt
      {
          $$ = $1;
      }
    ;


/* Function call used as a statement, e.g. swap(p,&b); */
callstmt
    : ID '(' arglist ')' ';'
      {
          $$ = makeCallStmtNode($1,$3,countArguments($3));
      }
    | ID '.' ID '(' arglist ')' ';'
      {
          $$ = makeMethodCallNode(makeVariableNode($1), $3, $5, countArguments($5));
          $$->nodetype = NODE_CALL_STMT;
      }
    | SELF '.' ID '(' arglist ')' ';'
      {
          $$ = makeMethodCallNode(makeVariableNode("self"), $3, $5, countArguments($5));
          $$->nodetype = NODE_CALL_STMT;
      }
    ;


/* ============================================================
   IF / WHILE / REPEAT
   ============================================================ */

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


/* ============================================================
   INPUT / OUTPUT
   ============================================================ */

inputstmt
    : READ '(' field ')' ';'
      {
          $$ = makeReadFieldNode($3);
      }
    | READ '(' ID ')' ';'
      {
          $$ = makeReadNode($3);
      }

    | READ '(' '*' ID ')' ';'
      {
          $$ = makeReadPointerNode($4);
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


/* ============================================================
   ASSIGNMENT
   ============================================================ */

asgstmt
    : field '=' E ';'
      { $$ = makeFieldAssignmentNode($1, $3); }
    | ID '=' ID ';'
      { $$=makeTupleAssignmentNode($1,$3); }
    | ID '=' E ';'
      {
          $$ = makeAssignmentNode($1,$3);
      }

    | '*' ID '=' E ';'
      {
          $$ = makePointerAssignmentNode($2,$4);
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


/* ============================================================
   BREAK / CONTINUE
   ============================================================ */

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


/* ============================================================
   EXPRESSIONS
   ============================================================ */

E
    : E '+' E
      {
          $$ = makeOperatorNode('+',$1,$3);
      }

    | E '-' E
      {
          $$ = makeOperatorNode('-',$1,$3);
      }

    | E '*' E
      {
          $$ = makeOperatorNode('*',$1,$3);
      }

    | E '/' E
      {
          $$ = makeOperatorNode('/',$1,$3);
      }

    | E '%' E
      {
          $$ = makeOperatorNode('%',$1,$3);
      }

    | E '>' E
      {
          $$ = makeOperatorNode('>',$1,$3);
      }

    | E '<' E
      {
          $$ = makeOperatorNode('<',$1,$3);
      }

    | E NE E
      {
          $$ = makeOperatorNode('n',$1,$3);
      }

    | E EQ E
      {
          $$ = makeOperatorNode('e',$1,$3);
      }

    | E LE E
      {
          $$ = makeOperatorNode('l',$1,$3);
      }

    | E GE E
      {
          $$ = makeOperatorNode('g',$1,$3);
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
          $$ = $1;
      }

    | NULLTOK
      {
          $$ = $1;
      }

    | ID '[' E ']' '[' E ']'
      {
          $$ = make2DArrayNode($1,$3,$6);
      }

    | ID '[' E ']'
      {
          $$ = makeArrayNode($1,$3);
      }

    | '*' ID
      {
          $$ = makeDeReferenceNode($2);
      }

    | '&' ID
      {
          $$ = makeAddressNode($2);
      }

    | ID
      {
          $$ = makeVariableNode($1);
      }

    | field
      {
          $$ = $1;
      }

    | NEW '(' ID ')'
      {
          $$ = makeNewNode($3);
      }

    | ID '.' ID '(' arglist ')'
      {
          $$ = makeMethodCallNode(makeVariableNode($1), $3, $5, countArguments($5));
      }

    | SELF '.' ID '(' arglist ')'
      {
          $$ = makeMethodCallNode(makeVariableNode("self"), $3, $5, countArguments($5));
      }

    | ID '(' arglist ')'
      {
          $$ = makeCallNode($1,$3,countArguments($3));
      }
    ;


field
    : ID '.' ID
      {
          $$ = makeFieldAccessNode(makeVariableNode($1), $3);
      }
    | SELF '.' ID
      {
          $$ = makeFieldAccessNode(makeVariableNode("self"), $3);
      }
    | ID '[' E ']' '.' ID
      {
          $$ = makeArrayFieldAccessNode($1, $3, $6);
      }
    | field '.' ID
      {
          $$ = makeFieldAccessNode($1, $3);
      }
    ;


arglist
    : /* empty */
      {
          $$ = NULL;
      }

    | E
      {
          $$ = $1;
      }

    | arglist ',' E
      {
          $$ = makeConnectorNode($1,$3);
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
    if(argc < 2)
    {
        printf("No input for filename\n");
        exit(1);
    }

    intermediate = fopen("ex2.xsm","w");

    fprintf(intermediate,"0\n2056\n0\n0\n0\n0\n0\n1\n");
    fprintf(intermediate,"MOV SP, 5000\n");

    fp = fopen(argv[1],"r");

    if(!fp)
    {
        printf("Invalid file specs");
        exit(1);
    }

    yyin = fp;

    yyparse();

    fclose(fp);
    fclose(intermediate);

    return 0;
}
