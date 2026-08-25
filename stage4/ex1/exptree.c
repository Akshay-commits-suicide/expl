#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exptree.h"
int breakflag=0;
int continueflag=0;
gsymbol* ghead = NULL;
int binding = 0;
tnode *makeLeafNode(int n)
{
	tnode *temp = (tnode *)malloc(sizeof(tnode));
	temp->nodetype = NODE_NUM;
	temp->val = n;
	temp->type = TYPE_INT;
	return temp;
}

tnode* makeStringNode(char* name)
{
      tnode* temp = (tnode*)(malloc(sizeof(tnode)));
      temp->nodetype = NODE_STR;
      temp->type = TYPE_STR;
      int len = strlen(name);
      temp->name = (char*)(malloc(len-1));
      strncpy(temp->name,name+1,len-2);
      temp->name[len-2] = '\0';
      return temp;
}

tnode* makeArrayNode(char* name,tnode* index)
{
	gsymbol* sym = lookup(name);
	tnode* temp = (tnode*)(malloc(sizeof(tnode)));
	temp->type = sym->type;
	temp->nodetype = NODE_ARR;
	temp->left = index;
	temp->symbol = sym;
	temp->name = strdup(name);
}

tnode* makeAssignmentArrayNode(char* name,tnode* index,tnode* value)
{
	gsymbol* sym = lookup(name);
	if(value->type != sym->type)
	{
		yyerror("ERROR:Type mismatch!\n");
	}
	if(index->type != TYPE_INT)
	{
		yyerror("ERROR:Invalid indexing\n");
	}

	tnode* temp =(tnode*)(malloc(sizeof(tnode)));

	temp->nodetype = NODE_ARR_ASSG;
	temp->type = sym->type;

	temp-name = strdup(name);
	temp->symbol = sym;

	temp->left = index;
	temp->right = value;

	return temp;
}

gsymbol* lookup(char* name)
{
	gsymbol* temp = ghead;
	while( temp != NULL )
	{
		if(strcmp(name,temp->name) == 0)
		{
			return temp;
		}
		temp = temp->next;
	}
	printf("ERROR:Undeclared Variable Called\n");
	exit(1);
}

int install(char* name,int type,int size)
{
	if(type != TYPE_INT && type != TYPE_STR && type != TYPE_BOOL)
	{
		printf("ERROR: Invalid datatype declared\n");
		exit(1);
	}
	gsymbol* temp;
	temp = ghead;
	while(temp!=NULL)
	{
		if(strcmp(name,temp->name)==0)
		{
			printf("ERROR: More than one variable of same name\n");
			exit(1);
		}
		temp=temp->next;
	}
	gsymbol* newnode = (gsymbol*)(malloc(sizeof(gsymbol)));
	newnode->type = type;
	newnode->size = size;
	newnode->name = strdup(name);
	newnode->binding = binding;
	newnode->next = NULL;

	binding += size;
	if(ghead == NULL)
	{
		ghead = newnode;
	}
	else
	{
		temp = ghead;
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next = newnode;
	}
	return 1;
}
tnode* makeBreakNode()
{
        tnode* temp = (tnode*)(malloc(sizeof(tnode)));
        temp->nodetype= NODE_BREAK;
        return temp;
}
tnode* makeContinueNode()
{
        tnode* temp = (tnode*)(malloc(sizeof(tnode)));
        temp->nodetype= NODE_CONTINUE;
        return temp;
}

tnode *makeAssignmentNode(char *name, tnode *t1)
{
	gsymbol* sym = lookup(name);
	if (t1->type != sym->type)
	{
		yyerror("Type mismatch:Compilation Error\n");
		return NULL;
	}
	tnode *temp = (tnode *)(malloc(sizeof(tnode)));
	temp->type = sym->type;
	temp->nodetype = NODE_ASSIGN;
	temp->name = strdup(name);
	temp->symbol = sym;
	temp->left = t1;
	return temp;
}
tnode *makeTreeNode(int nodetype, tnode *t1, tnode *t2, tnode *t3)
{
	if (t1->type != TYPE_BOOL)
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
	gsymbol* sym = lookup(name);
	temp->symbol = sym;
	temp->type = sym->type;
	return temp;
}

tnode *makeWriteNode(tnode *a)
{
	tnode *temp = (tnode *)(malloc(sizeof(tnode)));
	temp->nodetype = NODE_WRITE;
	temp->left = a;
	temp->type = a->type;
	return temp;
}

tnode *makeVariableNode(char *name)
{
	tnode *temp = (tnode *)(malloc(sizeof(tnode)));
	temp->name = strdup(name);
	temp->nodetype = NODE_VAR;
	gsymbol* temp1 = lookup(name);
	temp->symbol = temp1;
	temp->type = temp1->type;
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
char* strvar[26] = {NULL};
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
	else if (t->nodetype == NODE_STR)
	{
	        return 0;
	}
	else if (t->nodetype == NODE_VAR)
	{
		return variables[t->name[0] - 'a'];
	}
	else if (t->nodetype == NODE_BREAK)
	{
	      breakflag=1;
	      return 0;
	}
	else if (t->nodetype == NODE_CONTINUE)
	{
	      continueflag=1;
	      return 0;
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
	        if(t->type == TYPE_INT)
	        {
		    int value = evaluate(t->left);
		    variables[t->name[0] - 'a'] = value;
		    return value;
		}
		else
		{
		    int ind = t->name[0] - 'a';
		    free(strvar[ind]);
		    if(t->left->nodetype == NODE_STR)
		    {
		        strvar[ind] = strdup(t->left->name);
		        return 0;
		    }
		    int sind = t->left->name[0] - 'a';
		    if(strvar[sind] != NULL)
		    {
		        strvar[ind] = strdup(strvar[sind]);
		    }
		    else
		    {
		        strvar[ind] = NULL;
		    }
		    return 0;
		}
	}
	else if (t->nodetype == NODE_READ)
	{
		printf("Enter input for %s: ", t->name);
		if(t->type == TYPE_INT)
		{
		    int num;
		    scanf("%d", &num);
		    variables[t->name[0]-'a'] = num;
		    return num;
		}
		else
		{
		    char buffer[2000];
		    scanf(" %1999[^\n]",buffer);
		    free(strvar[t->name[0]-'a']);
		    strvar[t->name[0]-'a'] = strdup(buffer);
		    return 0;
		}
	}
	else if (t->nodetype == NODE_WRITE)
	{
	        if(t->left->type == TYPE_INT)
	        {
	            int ind = evaluate(t->left);
	            printf("%d\n",ind);
	            return ind;
	        }
	        else
	        {
	            if(t->left->nodetype == NODE_STR)
	            {
	                printf("%s\n",t->left->name);
	                return 0;
	            }
	            int ind = t->left->name[0]-'a';
	            if(strvar[ind] != NULL)
	            {
	                printf("%s\n",strvar[ind]);
	            }
	            return 0;
	        }
	}
	else if (t->nodetype == NODE_CONNECTOR)
	{
		evaluate(t->left);
		if(breakflag || continueflag)
		{
		    return 0;
		}
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
		return 0;
	}
	else if(t->nodetype == NODE_DOWHILE)
	{
	    do
	    {
	      evaluate(t->middle);
	      if(breakflag)
	      {
		    breakflag=0;
		    break;
	      }
	      if(continueflag)
	      {
		    continueflag=0;
	      }
	    }while(evaluate(t->left));
	    return 0;
	}
	else if(t->nodetype == NODE_REPEAT)
	{
	  do
	    {
	      evaluate(t->middle);
	      if(breakflag)
	      {
		    breakflag=0;
		    break;
	      }
	      if(continueflag)
	      {
		    continueflag=0;
	      }
	    }while(!(evaluate(t->left)));
	    return 0;
	}
	else if (t->nodetype == NODE_WHILE)
	{
		while (evaluate(t->left))
		{
		        evaluate(t->middle);
			if(breakflag)
			{
			    breakflag=0;
			    break;
			}
			if(continueflag)
			{
			    continueflag=0;
			    continue;
			}
		}
		return 0;
	}
}
