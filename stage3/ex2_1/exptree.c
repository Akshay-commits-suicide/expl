#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exptree.h"

tnode *makeLeafNode(int n)
{
	tnode *temp = (tnode *)malloc(sizeof(tnode));
	temp->nodetype = NODE_NUM;
	temp->val = n;
	temp->type = TYPE_INT;
	return temp;
}
tnode *makeAssignmentNode(char *name, tnode *t1)
{
	if (t1->type == TYPE_BOOL)
	{
		yyerror("Type mismatch:Compilation Error\n");
		return NULL;
	}
	tnode *temp = (tnode *)(malloc(sizeof(tnode)));
	temp->type = TYPE_INT;
	temp->nodetype = NODE_ASSIGN;
	temp->name = strdup(name);
	temp->left = t1;
	return temp;
}
tnode *makeTreeNode(int nodetype, tnode *t1, tnode *t2, tnode *t3)
{
	if (t1->type == TYPE_INT)
	{
		yyerror("Type mismatch:Compilation Error\n");
		return NULL;
	}
	tnode *temp = (tnode *)(malloc(sizeof(tnode)));
	temp->nodetype = nodetype;
	temp->left = t1;
	temp->middle = t2;
	temp->right = t3;
	return temp;
}
tnode *makeReadNode(char *name)
{
	tnode *temp = (tnode *)(malloc(sizeof(tnode)));
	temp->nodetype = NODE_READ;
	temp->name = strdup(name);
	return temp;
}

tnode *makeWriteNode(tnode *a)
{
	tnode *temp = (tnode *)(malloc(sizeof(tnode)));
	temp->nodetype = NODE_WRITE;
	temp->left = a;
	return temp;
}

tnode *makeVariableNode(char *name)
{
	tnode *temp = (tnode *)(malloc(sizeof(tnode)));
	temp->name = strdup(name);
	temp->nodetype = NODE_VAR;
	temp->type = TYPE_INT;
	return temp;
}

tnode *makeConnectorNode(tnode *t1, tnode *t2)
{
	tnode *temp = (tnode *)(malloc(sizeof(tnode)));
	temp->nodetype = NODE_CONNECTOR;
	temp->left = t1;
	temp->right = t2;
	return temp;
}

tnode *makeOperatorNode(char op, tnode *l, tnode *r)
{
	if (l->type != TYPE_INT || r->type != TYPE_INT)
	{
		yyerror("Type mismatch:Compilation Error\n");
	}
	tnode *temp = (tnode *)malloc(sizeof(tnode));
	temp->val = 0;
	temp->op = (char *)malloc(3 * sizeof(char));
	temp->type = TYPE_BOOL;
	if (op == 'g')
	{
		temp->op[0] = '>';
		temp->op[1] = '=';
		temp->op[2] = '\0';
	}
	else if (op == 'l')
	{
		temp->op[0] = '<';
		temp->op[1] = '=';
		temp->op[2] = '\0';
	}
	else if (op == 'n')
	{
		temp->op[0] = '!';
		temp->op[1] = '=';
		temp->op[2] = '\0';
	}
	else if (op == 'e')
	{
		temp->op[0] = '=';
		temp->op[1] = '=';
		temp->op[2] = '\0';
	}
	else if (op == '>')
	{
		temp->op[0] = op;
		temp->op[1] = '\0';
	}
	else if (op == '<')
	{
		temp->op[0] = op;
		temp->op[1] = '\0';
	}
	else
	{
		temp->op[0] = op;
		temp->op[1] = '\0';
		temp->type = TYPE_INT;
	}
	temp->left = l;
	temp->right = r;

	temp->nodetype = NODE_OP;

	return temp;
}
/*void preorder(tnode* root)
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
}*/
int variables[26] = {0};
int evaluate(tnode *t)
{
	if (t == NULL)
	{
		return 0;
	}
	else if (t->nodetype == NODE_NUM)
	{
		return t->val;
	}
	else if (t->nodetype == NODE_VAR)
	{
		return variables[t->name[0] - 'a'];
	}
	else if (t->nodetype == NODE_OP)
	{
		if (t->op[0] == '+')
		{
			return evaluate(t->left) + evaluate(t->right);
		}
		else if (t->op[0] == '-')
		{
			return evaluate(t->left) - evaluate(t->right);
		}
		else if (t->op[0] == '*')
		{
			return evaluate(t->left) * evaluate(t->right);
		}
		else if (t->op[0] == '/')
		{
			return evaluate(t->left) / evaluate(t->right);
		}
		else if (strcmp(t->op, "==") == 0)
		{
			return evaluate(t->left) == evaluate(t->right);
		}
		else if (strcmp(t->op, "!=") == 0)
		{
			return evaluate(t->left) != evaluate(t->right);
		}
		else if (strcmp(t->op, "<") == 0)
		{
			return evaluate(t->left) < evaluate(t->right);
		}
		else if (strcmp(t->op, ">") == 0)
		{
			return evaluate(t->left) > evaluate(t->right);
		}
		else if (strcmp(t->op, "<=") == 0)
		{
			return evaluate(t->left) <= evaluate(t->right);
		}
		else if (strcmp(t->op, ">=") == 0)
		{
			return evaluate(t->left) >= evaluate(t->right);
		}
	}
	else if (t->nodetype == NODE_ASSIGN)
	{
		int value = evaluate(t->left);
		variables[t->name[0] - 'a'] = value;
		return value;
	}
	else if (t->nodetype == NODE_READ)
	{
		int num;
		printf("Enter input for %s: ", t->name);
		scanf("%d", &num);
		variables[t->name[0] - 'a'] = num;
		return num;
	}
	else if (t->nodetype == NODE_WRITE)
	{
		int value = evaluate(t->left);
		printf("%d\n", value);
		return value;
	}
	else if (t->nodetype == NODE_CONNECTOR)
	{
		evaluate(t->left);
		evaluate(t->right);
		return 0;
	}
	else if (t->nodetype == NODE_IF)
	{
		if (evaluate(t->left))
		{
			evaluate(t->middle);
		}
		else if (t->right != NULL)
		{
			evaluate(t->right);
		}
	}
	else if (t->nodetype == NODE_WHILE)
	{
		while (evaluate(t->left))
		{
			evaluate(t->middle);
		}
	}
}
