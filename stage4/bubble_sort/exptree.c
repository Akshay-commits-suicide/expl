#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exptree.h"

int breakflag = 0;
int continueflag = 0;
gsymbol *ghead = NULL;
int binding = 0;

tnode *makeLeafNode(int n)
{
	tnode *temp = (tnode *)calloc(1, sizeof(tnode));
	temp->nodetype = NODE_NUM;
	temp->val = n;
	temp->type = TYPE_INT;
	return temp;
}
void printt()
{
	gsymbol* temp = ghead;
	while(!temp)
	{
		printf("%s %d\n",temp->name,temp->binding+4096 );
		temp=temp->next;
	}
}
tnode *makeStringNode(char *name)
{
	tnode *temp = (tnode *)(calloc(1, sizeof(tnode)));
	temp->nodetype = NODE_STR;
	temp->type = TYPE_STR;
	int len = strlen(name);
	temp->name = (char *)(malloc(len - 1));
	strncpy(temp->name, name + 1, len - 2);
	temp->name[len - 2] = '\0';
	return temp;
}

tnode *makeArrayNode(char *name, tnode *index)
{
	if (index->type != TYPE_INT)
	{
		yyerror("ERROR:Invalid Array indexing\n");
	}
	gsymbol *sym = lookup(name);
	if (sym->size == 1 || sym->size1 != 0)
	{
		yyerror("ERROR:Invalid array indexing on a non array datatype\n");
	}
	tnode *temp = (tnode *)(calloc(1, sizeof(tnode)));
	temp->type = sym->type;
	temp->nodetype = NODE_ARR;
	temp->left = index;
	temp->symbol = sym;
	temp->name = strdup(name);
	return temp;
}

tnode *makeAssignmentArrayNode(char *name, tnode *index, tnode *value)
{
	gsymbol *sym = lookup(name);
	if (value->type != sym->type)
	{
		yyerror("ERROR:Type mismatch!\n");
	}
	if (index->type != TYPE_INT)
	{
		yyerror("ERROR:Invalid indexing\n");
	}
	if (sym->size == 1 || sym->size1 != 0)
	{
		yyerror("ERROR:Invalid array indexing on a non array datatype\n");
	}
	tnode *temp = (tnode *)(calloc(1, sizeof(tnode)));

	temp->nodetype = NODE_ARR_ASSG;
	temp->type = sym->type;

	temp->name = strdup(name);
	temp->symbol = sym;

	temp->left = index;
	temp->right = value;

	return temp;
}

tnode *make2DArrayNode(char *name, tnode *index, tnode *index1)
{
	if (index->type != TYPE_INT || index1->type != TYPE_INT)
	{
		yyerror("ERROR:Invalid Array indexing\n");
	}
	gsymbol *sym = lookup(name);
	if (sym->size1 == 0)
	{
		yyerror("ERROR:Invalid 2D-array indexing on a non 2D-array datatype\n");
	}
	tnode *temp = (tnode *)(calloc(1, sizeof(tnode)));
	temp->type = sym->type;
	temp->nodetype = NODE_2D_ARR;
	temp->left = index;
	temp->middle = index1;
	temp->symbol = sym;
	temp->name = strdup(name);
	return temp;
}

tnode *makeAssignment2DArrayNode(char *name, tnode *index, tnode *index1, tnode *value)
{
	gsymbol *sym = lookup(name);
	if (value->type != sym->type)
	{
		yyerror("ERROR:Type mismatch!\n");
	}
	if (index->type != TYPE_INT || index1->type != TYPE_INT)
	{
		yyerror("ERROR:Invalid indexing\n");
	}
	if (sym->size1 == 0)
	{
		yyerror("ERROR:Invalid 2D-array indexing on a non 2D-array datatype\n");
	}
	tnode *temp = (tnode *)(calloc(1, sizeof(tnode)));

	temp->nodetype = NODE_2D_ARR_ASSG;
	temp->type = sym->type;

	temp->name = strdup(name);
	temp->symbol = sym;

	temp->left = index;
	temp->middle = index1;
	temp->right = value;

	return temp;
}

gsymbol *lookup(char *name)
{
	gsymbol *temp = ghead;
	while (temp != NULL)
	{
		if (strcmp(name, temp->name) == 0)
		{
			return temp;
		}
		temp = temp->next;
	}
	printf("ERROR:Undeclared Variable Called\n");
	exit(1);
}

int install(char *name, int type, int size, int size1)
{
	if (type != TYPE_INT && type != TYPE_STR && type != TYPE_BOOL)
	{
		printf("ERROR: Invalid datatype declared\n");
		exit(1);
	}
	gsymbol *temp;
	temp = ghead;
	while (temp != NULL)
	{
		if (strcmp(name, temp->name) == 0)
		{
			yyerror("ERROR: More than one variable of same name\n");
		}
		temp = temp->next;
	}
	gsymbol *newnode = (gsymbol *)(calloc(1, sizeof(gsymbol)));
	newnode->type = type;
	newnode->size = size;
	newnode->size1 = size1;
	newnode->name = strdup(name);
	newnode->binding = binding;
	newnode->next = NULL;
        printf("%s %d  %d\n",newnode->name,newnode->size,newnode->binding+4096 );
	if (size1 == 0)
	{
		binding += size;
	}
	else
	{
		binding += size * size1;
	}
	if (ghead == NULL)
	{
		ghead = newnode;
	}
	else
	{
		temp = ghead;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newnode;
	}
	return 1;
}

tnode *makeBreakNode()
{
	tnode *temp = (tnode *)(calloc(1, sizeof(tnode)));
	temp->nodetype = NODE_BREAK;
	return temp;
}

tnode *makeContinueNode()
{
	tnode *temp = (tnode *)(calloc(1, sizeof(tnode)));
	temp->nodetype = NODE_CONTINUE;
	return temp;
}

tnode *makeAssignmentNode(char *name, tnode *t1)
{
	gsymbol *sym = lookup(name);
	if (sym->size > 1 || sym->size1 != 0)
	{
		yyerror("ERROR:Cannot directly assign to array\n");
	}
	if (t1->type != sym->type)
	{
		yyerror("Type mismatch:Compilation Error\n");
		return NULL;
	}
	tnode *temp = (tnode *)(calloc(1, sizeof(tnode)));
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
	tnode *temp = (tnode *)(calloc(1, sizeof(tnode)));
	temp->nodetype = nodetype;
	temp->left = t1;
	temp->middle = t2;
	temp->right = t3;
	return temp;
}

tnode *makeReadNode(char *name)
{
	gsymbol *sym = lookup(name);
	if (sym->size > 1 || sym->size1 != 0)
	{
		yyerror("ERROR:Invalid array Read\n");
	}
	tnode *temp = (tnode *)(calloc(1, sizeof(tnode)));
	temp->nodetype = NODE_READ;
	temp->name = strdup(name);
	temp->symbol = sym;
	temp->type = sym->type;
	return temp;
}

tnode *makeReadArrayNode(char *name, tnode *index)
{
	gsymbol *sym = lookup(name);
	if (index->type != TYPE_INT)
	{
		yyerror("ERROR:Invalid indexing type\n");
	}
	if (sym->size == 1 || sym->size1 != 0)
	{
		yyerror("ERROR:Invalid array indexing on a non array datatype\n");
	}
	tnode *temp = (tnode *)calloc(1, sizeof(tnode));

	temp->type = sym->type;
	temp->nodetype = NODE_READ;
	temp->name = strdup(name);
	temp->symbol = sym;
	temp->left = index;

	return temp;
}

tnode *makeRead2DArrayNode(char *name, tnode *index, tnode *index1)
{
	gsymbol *sym = lookup(name);
	if (index->type != TYPE_INT || index1->type != TYPE_INT)
	{
		yyerror("ERROR:Invalid indexing type\n");
	}
	if (sym->size1 == 0)
	{
		yyerror("ERROR:Invalid array indexing on a non array datatype\n");
	}
	tnode *temp = (tnode *)calloc(1, sizeof(tnode));

	temp->type = sym->type;
	temp->nodetype = NODE_READ;
	temp->name = strdup(name);
	temp->symbol = sym;
	temp->left = index;
	temp->middle = index1;
	return temp;
}

tnode *makeWriteNode(tnode *a)
{
	tnode *temp = (tnode *)(calloc(1, sizeof(tnode)));
	temp->nodetype = NODE_WRITE;
	temp->left = a;
	temp->type = a->type;
	return temp;
}

tnode *makeVariableNode(char *name)
{
	gsymbol *temp1 = lookup(name);
	if (temp1->size > 1 || temp1->size1 != 0)
	{
		yyerror("ERROR:Cannot used an array without indexing\n");
	}
	tnode *temp = (tnode *)(calloc(1, sizeof(tnode)));
	temp->name = strdup(name);
	temp->nodetype = NODE_VAR;
	temp->symbol = temp1;
	temp->type = temp1->type;
	return temp;
}

tnode *makeConnectorNode(tnode *t1, tnode *t2)
{
	tnode *temp = (tnode *)(calloc(1, sizeof(tnode)));
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
	tnode *temp = (tnode *)calloc(1, sizeof(tnode));
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

int variables[1000] = {0};
char *strvar[1000] = {NULL};
int strind = -1;

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
		return variables[t->symbol->binding];
	}
	else if (t->nodetype == NODE_ARR)
	{
		int ind = evaluate(t->left);
		if (ind < 0 || ind >= t->symbol->size)
		{
			yyerror("ERROR:Out of bound index for array detected\n");
		}
		return variables[t->symbol->binding + ind];
	}
	else if (t->nodetype == NODE_2D_ARR)
	{
		int ind = evaluate(t->left);
		int ind1 = evaluate(t->middle);
		if (ind < 0 || ind >= t->symbol->size || ind1 < 0 || ind1 >= t->symbol->size1)
		{
			yyerror("ERROR:Out of bound index for array detected\n");
		}
		int offset = ind * t->symbol->size1 + ind1;
		return variables[t->symbol->binding + offset];
	}
	else if (t->nodetype == NODE_BREAK)
	{
		breakflag = 1;
		return 0;
	}
	else if (t->nodetype == NODE_CONTINUE)
	{
		continueflag = 1;
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
		if (t->type == TYPE_INT)
		{
			int value = evaluate(t->left);
			variables[t->symbol->binding] = value;
			return value;
		}
		else
		{
			int ind = t->symbol->binding;
			free(strvar[ind]);
			if (t->left->nodetype == NODE_STR)
			{
				strvar[ind] = strdup(t->left->name);
				return 0;
			}
			int sind = t->left->symbol->binding;
			if (strvar[sind] != NULL)
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
	else if (t->nodetype == NODE_ARR_ASSG)
	{
		int ind = evaluate(t->left);
		if (ind < 0 || ind >= t->symbol->size)
		{
			yyerror("ERROR:Out of bound index for array detected\n");
		}
		if (t->type == TYPE_INT)
		{
			int val = evaluate(t->right);
			variables[t->symbol->binding + ind] = val;
			return val;
		}
		else
		{
			free(strvar[t->symbol->binding + ind]);
			if (t->right->nodetype == NODE_STR)
			{
				strvar[t->symbol->binding + ind] = strdup(t->right->name);
			}
			else
			{
				int punind = evaluate(t->right->left);
				int srcind = t->right->symbol->binding + punind;
				if (strvar[srcind] == NULL)
				{
					strvar[t->symbol->binding + ind] = NULL;
				}
				else
				{
					strvar[t->symbol->binding + ind] = strdup(strvar[srcind]);
				}
			}
			return 0;
		}
	}
	else if (t->nodetype == NODE_2D_ARR_ASSG)
	{
		int ind = evaluate(t->left);
		int ind1 = evaluate(t->middle);
		int offset = ind * t->symbol->size1 + ind1;
		if (ind < 0 || ind >= t->symbol->size || ind1 < 0 || ind1 >= t->symbol->size1)
		{
			yyerror("ERROR:Out of bound index for array detected\n");
		}
		if (t->type == TYPE_INT)
		{
			int val = evaluate(t->right);
			variables[t->symbol->binding + offset] = val;
			return val;
		}
		else
		{
			free(strvar[t->symbol->binding + offset]);
			if (t->right->nodetype == NODE_STR)
			{
				strvar[t->symbol->binding + offset] = strdup(t->right->name);
			}
			else if (t->right->nodetype == NODE_2D_ARR)
			{
				int punind1 = evaluate(t->right->left);
				int punind2 = evaluate(t->right->middle);
				if (punind1 < 0 || punind1 >= t->right->symbol->size || punind2 < 0 || punind2 >= t->right->symbol->size1)
				{
					yyerror("ERROR:Out of bound index for array detected\n");
				}
				int offset1 = punind1 * (t->right->symbol->size1) + punind2;
				int srcind = t->right->symbol->binding + offset1;
				if (strvar[srcind] == NULL)
				{
					strvar[t->symbol->binding + offset] = NULL;
				}
				else
				{
					strvar[t->symbol->binding + offset] = strdup(strvar[srcind]);
				}
			}
			else
			{
				int punind = evaluate(t->right->left);
				if (punind < 0 || punind >= t->right->symbol->size)
				{
					yyerror("ERROR:Out of bound index for array detected\n");
				}
				int srcind = t->right->symbol->binding + punind;
				if (strvar[srcind] == NULL)
				{
					strvar[t->symbol->binding + offset] = NULL;
				}
				else
				{
					strvar[t->symbol->binding + offset] = strdup(strvar[srcind]);
				}
			}
			return 0;
		}
	}
	else if (t->nodetype == NODE_READ)
	{
		if (t->middle != NULL)
		{
			int ind = evaluate(t->left);
			int ind1 = evaluate(t->middle);
			int offset = ind * t->symbol->size1 + ind1;
			if (ind < 0 || ind >= t->symbol->size || ind1 < 0 || ind1 >= t->symbol->size1)
			{
				yyerror("ERROR:Out of Bound Indexing\n");
			}
			int pos = t->symbol->binding + offset;
			printf("Enter input for %s[%d][%d]: ", t->name, ind, ind1);
			if (t->type == TYPE_INT)
			{
				int num;
				scanf("%d", &num);
				variables[pos] = num;
				return num;
			}
			else
			{
				char buffer[2000];
				scanf(" %1999[^\n]", buffer);
				free(strvar[pos]);
				strvar[pos] = strdup(buffer);
				return 0;
			}
		}

		else if (t->left != NULL)
		{
			int ind = evaluate(t->left);
			if (ind < 0 || ind >= t->symbol->size)
			{
				yyerror("ERROR:Out of Bound Indexing\n");
			}
			int pos = t->symbol->binding + ind;
			printf("Enter input for %s[%d]: ", t->name, ind);
			if (t->type == TYPE_INT)
			{
				int num;
				scanf("%d", &num);
				variables[pos] = num;
				return num;
			}
			else
			{
				char buffer[2000];
				scanf(" %1999[^\n]", buffer);
				free(strvar[pos]);
				strvar[pos] = strdup(buffer);
				return 0;
			}
		}

		else
		{
			printf("Enter input for %s: ", t->name);
			if (t->type == TYPE_INT)
			{
				int num;
				scanf("%d", &num);
				variables[t->symbol->binding] = num;
				return num;
			}
			else
			{
				char buffer[2000];
				scanf(" %1999[^\n]", buffer);
				free(strvar[t->symbol->binding]);
				strvar[t->symbol->binding] = strdup(buffer);
				return 0;
			}
		}
	}
	else if (t->nodetype == NODE_WRITE)
	{
		if (t->left->nodetype == NODE_2D_ARR)
		{
			int ind = evaluate(t->left->left);
			int ind1 = evaluate(t->left->middle);
			int offset = ind * (t->left->symbol->size1) + ind1;

			if (ind < 0 || ind >= t->left->symbol->size || ind1 < 0 || ind1 >= t->left->symbol->size1)
			{
				yyerror("ERROR:Out of Bound Indexing\n");
			}
			int pos = t->left->symbol->binding + offset;
			if (t->left->type == TYPE_INT)
			{
				printf("%d\n", variables[pos]);
			}
			else
			{
				if (strvar[pos] != NULL)
				{
					printf("%s\n", strvar[pos]);
				}
			}
			return 0;
		}
		if (t->left->nodetype == NODE_ARR)
		{
			int ind = evaluate(t->left->left);

			if (ind < 0 || ind >= t->left->symbol->size)
			{
				yyerror("ERROR:Out of Bound Indexing\n");
			}
			int pos = t->left->symbol->binding + ind;
			if (t->left->type == TYPE_INT)
			{
				printf("%d\n", variables[pos]);
			}
			else
			{
				if (strvar[pos] != NULL)
				{
					printf("%s\n", strvar[pos]);
				}
			}
			return 0;
		}
		else if (t->left->type == TYPE_INT)
		{
			int ind = evaluate(t->left);
			printf("%d\n", ind);
			return ind;
		}
		else
		{
			if (t->left->nodetype == NODE_STR)
			{
				printf("%s\n", t->left->name);
				return 0;
			}
			int ind = t->left->symbol->binding;
			if (strvar[ind] != NULL)
			{
				printf("%s\n", strvar[ind]);
			}
			return 0;
		}
	}
	else if (t->nodetype == NODE_CONNECTOR)
	{
		evaluate(t->left);
		if (breakflag || continueflag)
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
	else if (t->nodetype == NODE_DOWHILE)
	{
		do
		{
			evaluate(t->middle);
			if (breakflag)
			{
				breakflag = 0;
				break;
			}
			if (continueflag)
			{
				continueflag = 0;
			}
		} while (evaluate(t->left));
		return 0;
	}
	else if (t->nodetype == NODE_REPEAT)
	{
		do
		{
			evaluate(t->middle);
			if (breakflag)
			{
				breakflag = 0;
				break;
			}
			if (continueflag)
			{
				continueflag = 0;
			}
		} while (!(evaluate(t->left)));
		return 0;
	}
	else if (t->nodetype == NODE_WHILE)
	{
		while (evaluate(t->left))
		{
			evaluate(t->middle);
			if (breakflag)
			{
				breakflag = 0;
				break;
			}
			if (continueflag)
			{
				continueflag = 0;
				continue;
			}
		}
		return 0;
	}
}
