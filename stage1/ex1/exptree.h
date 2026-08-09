#ifndef EXPTREE_H
#define EXPTREE_H

typedef struct tnode{
    int val;
    char *op; //indicates the name of the operator for a non leaf node
    struct tnode *left, *right; //left and right branches
} tnode;

/*Make a leaf tnode and set the value of val field*/
struct tnode* makeLeafNode(int n);

/*Make a tnode with operator, left and right branches set*/
struct tnode* makeOperatorNode(char op,struct tnode *l,struct tnode *r);

int evaluate(struct tnode* t);

int codegen(struct tnode* t);

void preorder(struct tnode* t);

void postorder(struct tnode* t);
#endif
