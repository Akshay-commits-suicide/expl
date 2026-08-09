#include <stdio.h>
#include <stdlib.h>

typedef struct tnode{
    int val;
    char *op;
    struct tnode *left;
    struct tnode *right;
}tnode;

tnode* makeLeafNode(int n)
{
    tnode *temp = (tnode *)malloc(sizeof(tnode));

    temp->val = n;
    temp->op = NULL;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

tnode* makeOperatorNode(char op, tnode *l, tnode *r)
{
    tnode *temp = (tnode *)malloc(sizeof(tnode));

    temp->val = 0;
    temp->op = (char *)malloc(2*sizeof(char));
    temp->op[0] = op;
    temp->op[1] = '\0';

    temp->left = l;
    temp->right = r;

    return temp;
}
void preorder(tnode* root)
{
	if(root==NULL)
	{
		return;
	}
	if(root->op==NULL)
	{
		printf("%d ",root->val);
	}
	else
	{
		printf("%s ",root->op);
	}
	preorder(root->left);
	preorder(root->right);
}
void postorder(tnode* root)
{
	if(root==NULL)
	{
		return;
	}
	postorder(root->left);
	postorder(root->right);
	if(root->op==NULL)
	{
		printf("%d ",root->val);
	}
	else
	{
		printf("%s ",root->op);
	}
}
int evaluate(tnode* t)
{
	if(t->op == NULL)
	{
		return t->val;
	}
	else
	{
		if(t->op[0]=='+')
		{
			return evaluate(t->left) + evaluate(t->right);
		}
		else if(t->op[0]=='-')
		{
			return evaluate(t->left) - evaluate(t->right);
		}
		else if(t->op[0]=='*')
		{
			return evaluate(t->left) * evaluate(t->right);
		}
		else if(t->op[0]=='/')
		{
			return evaluate(t->left) / evaluate(t->right);
		}
	}
}
