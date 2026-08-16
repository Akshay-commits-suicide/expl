#ifndef EXPTREE_H
#define EXPTREE_H
#define NODE_NUM 1
#define NODE_VAR 2
#define NODE_OP 3
#define NODE_ASSIGN 4
#define NODE_READ 5
#define NODE_WRITE 6
#define NODE_CONNECTOR 7


typedef struct tnode{
    int val;
    int nodetype;
    char* name;
    char *op; //indicates the name of the operator for a non leaf node
    struct tnode *left, *right; //left and right branches
} tnode;

/*Make a leaf tnode and set the value of val field*/
struct tnode* makeLeafNode(int n);

/*Make a tnode with operator, left and right branches set*/
struct tnode* makeOperatorNode(char op,struct tnode *l,struct tnode *r);

struct tnode* makeVariableNode(char* name);

struct tnode* makeAssignmentNode(char* name,struct tnode* expr);

struct tnode* makeReadNode(char* name);

struct tnode* makeWriteNode(struct tnode* expr);

struct tnode* makeConnectorNode(struct tnode* l,struct tnode* r);

int evaluate(struct tnode* t);

int codegen(struct tnode* t);

#endif
