#ifndef EXPTREE_H
#define EXPTREE_H

#define NODE_NUM 1
#define NODE_VAR 2
#define NODE_OP 3
#define NODE_ASSIGN 4
#define NODE_READ 5
#define NODE_WRITE 6
#define NODE_CONNECTOR 7
#define NODE_IF 8
#define NODE_WHILE 9
#define NODE_DOWHILE 10
#define NODE_REPEAT 11
#define NODE_BREAK 12
#define NODE_CONTINUE 13
#define NODE_STR 14
#define NODE_ARR 15
#define NODE_ARR_ASSG 16
#define NODE_2D_ARR 17
#define NODE_2D_ARR_ASSG 18

#define TYPE_INT 0
#define TYPE_BOOL 1
#define TYPE_STR 2

typedef struct Gsymbol
{
    char *name;
    int type;
    int size;
    int size1;
    int binding;
    struct Gsymbol *next;
} gsymbol;

typedef struct tnode
{
    int val;
    int type;
    int nodetype;
    char *name;
    gsymbol *symbol;
    char *op;                            // indicates the name of the operator for a non leaf node
    struct tnode *left, *middle, *right; // left and right branches
} tnode;

/*Make a leaf tnode and set the value of val field*/
struct tnode *makeLeafNode(int n);

/*Make a tnode with operator, left and right branches set*/
struct tnode *makeOperatorNode(char op, struct tnode *l, struct tnode *r);

struct tnode *makeVariableNode(char *name);

struct tnode *makeAssignmentNode(char *name, struct tnode *expr);

struct tnode *makeReadNode(char *name);

struct tnode *makeWriteNode(struct tnode *expr);

struct tnode *makeConnectorNode(struct tnode *l, struct tnode *r);

struct tnode *makeTreeNode(int nodeType, struct tnode *l, struct tnode *middle, struct tnode *r);

struct tnode *makeBreakNode();

struct tnode *makeStringNode(char *name);

struct tnode *makeContinueNode();

struct tnode *makeArrayNode(char *name, struct tnode *index);

struct tnode *makeAssignmentArrayNode(char *name, struct tnode *index, struct tnode *value);

struct tnode *makeReadArrayNode(char *name, struct tnode *index);

struct tnode *make2DArrayNode(char *name, struct tnode *index1, struct tnode *index2);

struct tnode *makeAssignment2DArrayNode(char *name, struct tnode *index1, struct tnode *index2, struct tnode *value);

struct tnode *makeRead2DArrayNode(char *name, struct tnode *index1, struct tnode *index2);

int install(char *name, int type, int size1, int size2);

gsymbol *lookup(char *name);

int evaluate(struct tnode *t);

int codegen(struct tnode *t);

int yyerror(char *s);

#endif
