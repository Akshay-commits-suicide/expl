#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exptree.h"

static void resolveName(char *name, gsymbol **gs, Lsymbol **ls);

int breakflag = 0;
int continueflag = 0;
gsymbol *ghead = NULL;
gsymbol *currentFunction = NULL;
Lsymbol *lhead = NULL;
int binding = 0;

tnode *makeLeafNode(int n)
{
	tnode *temp = (tnode *)calloc(1, sizeof(tnode));
	temp->nodetype = NODE_NUM;
	temp->val = n;
	temp->type = TYPE_INT;
	return temp;
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

tnode *makeAddressNode(char *name)
{
	gsymbol *sym = NULL;
	Lsymbol *lsym = NULL;
	resolveName(name, &sym, &lsym);
	if (sym->size1 == -1)
	{
		yyerror("ERROR:Too many References\n");
	}
	if (sym->size1 > 0 || sym->size > 1)
	{
		yyerror("ERROR:Cannot take address of whole array\n");
	}
	tnode *temp = (tnode *)(calloc(1, sizeof(tnode)));
	temp->name = strdup(name);
	temp->symbol = sym;
	temp->lsymbol = lsym;
	temp->type = sym->type;
	temp->isPointer = 1;
	temp->nodetype = NODE_ADDR;
	return temp;
}
tnode *makeDeReferenceNode(char *name)
{
	gsymbol *sym = NULL;
	Lsymbol *lsym = NULL;
	resolveName(name, &sym, &lsym);
	if (sym->size1 != -1)
	{
		yyerror("ERROR:Cannot reference a non-pointer\n");
	}
	tnode *temp = (tnode *)(calloc(1, sizeof(tnode)));
	temp->name = strdup(name);
	temp->symbol = sym;
	temp->lsymbol = lsym;
	temp->type = sym->type;
	temp->isPointer = 0;
	temp->nodetype = NODE_DEREF;
	return temp;
}
tnode *makeArrayNode(char *name, tnode *index)
{
	if (index->type != TYPE_INT)
	{
		yyerror("ERROR:Invalid Array indexing\n");
	}
	gsymbol *sym = NULL;
	Lsymbol *lsym = NULL;
	resolveName(name, &sym, &lsym);
	if (sym->size == 1 || sym->size1 != 0)
	{
		yyerror("ERROR:Invalid array indexing on a non array datatype\n");
	}
	tnode *temp = (tnode *)(calloc(1, sizeof(tnode)));
	temp->type = sym->type;
	temp->nodetype = NODE_ARR;
	temp->left = index;
	temp->symbol = sym;
	temp->lsymbol = lsym;
	temp->name = strdup(name);
	return temp;
}

tnode *makeAssignmentArrayNode(char *name, tnode *index, tnode *value)
{
	gsymbol *sym = NULL;
	Lsymbol *lsym = NULL;
	resolveName(name, &sym, &lsym);
	if (value->type != sym->type && value->type != -1)
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
	temp->lsymbol = lsym;

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
	gsymbol *sym = NULL;
	Lsymbol *lsym = NULL;
	resolveName(name, &sym, &lsym);
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
	temp->lsymbol = lsym;
	temp->name = strdup(name);
	return temp;
}

tnode *makeAssignment2DArrayNode(char *name, tnode *index, tnode *index1, tnode *value)
{
	gsymbol *sym = NULL;
	Lsymbol *lsym = NULL;
	resolveName(name, &sym, &lsym);
	if (value->type != sym->type && value->type != -1)
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
	temp->lsymbol = lsym;

	temp->left = index;
	temp->middle = index1;
	temp->right = value;

	return temp;
}

Lsymbol *lookupLocal(char *name)
{
	Lsymbol *temp = lhead;
	while (temp != NULL)
	{
		if (strcmp(name, temp->name) == 0)
			return temp;
		temp = temp->next;
	}
	return NULL;
}

gsymbol *lookupFunction(char *name)
{
	gsymbol *temp = ghead;
	while (temp != NULL)
	{
		if (strcmp(name, temp->name) == 0)
			return temp->isFunction ? temp : NULL;
		temp = temp->next;
	}
	return NULL;
}

gsymbol *lookup(char *name)
{
	Lsymbol *local = lookupLocal(name);
	if (local != NULL)
		return (gsymbol *)local; /* used only by old interface; local-aware nodes use lsymbol */

	gsymbol *temp = ghead;
	while (temp != NULL)
	{
		if (strcmp(name, temp->name) == 0)
			return temp;
		temp = temp->next;
	}
	printf("ERROR:Undeclared Variable Called\n");
	exit(1);
}

static void resolveName(char *name, gsymbol **gs, Lsymbol **ls)
{
	*ls = lookupLocal(name);
	if (*ls != NULL)
	{
		*gs = (gsymbol *)*ls;
		return;
	}
	{
		gsymbol *g = ghead;
		while (g != NULL && strcmp(name, g->name) != 0)
			g = g->next;
		if (g == NULL)
		{
			printf("ERROR:Undeclared Variable Called\n");
			exit(1);
		}
		if (g->isFunction)
		{
			printf("ERROR: Function used as variable\n");
			exit(1);
		}
		*gs = g;
	}
}

int install(char *name, int type, int size, int size1)
{
	if (type != TYPE_INT && type != TYPE_STR && type != TYPE_BOOL)
	{
		printf("ERROR: Invalid datatype declared\n");
		exit(1);
	}
	gsymbol *temp = ghead;
	while (temp != NULL)
	{
		if (strcmp(name, temp->name) == 0)
			yyerror("ERROR: More than one variable of same name\n");
		temp = temp->next;
	}
	if (currentFunction != NULL)
		yyerror("ERROR: Global declaration inside function\n");

	gsymbol *newnode = (gsymbol *)(calloc(1, sizeof(gsymbol)));
	newnode->type = type;
	newnode->size = size;
	newnode->size1 = size1;
	newnode->name = strdup(name);
	newnode->binding = binding;
	newnode->isFunction = 0;
	newnode->next = NULL;

	if (size1 == 0 || size1 == -1)
		binding += size;
	else
		binding += size * size1;

	if (ghead == NULL)
		ghead = newnode;
	else
	{
		temp = ghead;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = newnode;
	}
	return 1;
}

Param *makeParam(char *name, int type, int isPointer)
{
	Param *p = (Param *)calloc(1, sizeof(Param));
	p->name = strdup(name);
	p->type = type;
	p->isPointer = isPointer;
	return p;
}

Param *appendParam(Param *a, Param *b)
{
	if (a == NULL)
		return b;
	Param *t = a;
	while (t->next != NULL)
		t = t->next;
	t->next = b;
	return a;
}

static int sameParams(Param *a, Param *b)
{
	while (a != NULL && b != NULL)
	{
		if (a->type != b->type || a->isPointer != b->isPointer)
			return 0;
		a = a->next;
		b = b->next;
	}
	return a == NULL && b == NULL;
}

int installFunction(char *name, int type, Param *params, int isPointer)
{
	gsymbol *temp = ghead;
	while (temp != NULL)
	{
		if (strcmp(name, temp->name) == 0)
		{
			if (!temp->isFunction)
				yyerror("ERROR: Function/variable with same name already declared\n");

			/* A real definition may complete either a prototype or a
			 * forward-call placeholder. A second definition is illegal. */
			if (temp->body != NULL)
				yyerror("ERROR: Function already defined\n");

			if (temp->type != -1 &&
					(temp->type != type || temp->isPointer != isPointer))
				yyerror("ERROR: Function return type mismatch\n");

			if (temp->params != NULL && !sameParams(temp->params, params))
				yyerror("ERROR: Function parameter mismatch\n");

			temp->type = type;
			temp->isPointer = isPointer;
			temp->params = params;
			temp->paramCount = 0;
			for (Param *p = params; p != NULL; p = p->next)
				temp->paramCount++;
			return 1;
		}
		temp = temp->next;
	}

	gsymbol *f = (gsymbol *)calloc(1, sizeof(gsymbol));
	f->name = strdup(name);
	f->type = type;
	f->isFunction = 1;
	f->isPointer = isPointer;
	f->binding = binding;
	f->params = params;
	f->paramCount = 0;
	for (Param *p = params; p != NULL; p = p->next)
		f->paramCount++;
	f->next = NULL;

	if (ghead == NULL)
		ghead = f;
	else
	{
		temp = ghead;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = f;
	}
	return 1;
}

void beginFunction(gsymbol *sym)
{
	currentFunction = sym;
	lhead = NULL;
	int b = -3;
	for (Param *p = sym->params; p != NULL; p = p->next)
	{
		installLocal(p->name, p->type, 1, p->isPointer ? -1 : 0);
		lhead->binding = b;
		/* installLocal inserts at the head. Keep the prescribed parameter binding. */
		b--;
	}
}

void endFunction(void)
{
	if (currentFunction != NULL)
		currentFunction->localTable = lhead;
	currentFunction = NULL;
	lhead = NULL;
}

int installLocal(char *name, int type, int size, int size1)
{
	if (currentFunction == NULL)
		yyerror("ERROR: Local declaration outside a function\n");
	if (lookupLocal(name) != NULL)
		yyerror("ERROR: More than one local variable of same name\n");
	Lsymbol *x = (Lsymbol *)calloc(1, sizeof(Lsymbol));
	x->name = strdup(name);
	x->type = type;
	x->size = size;
	x->size1 = size1;
	x->binding = 1;
	if (lhead != NULL)
	{
		/* local variables occupy positive offsets from BP */
		int max = 0;
		for (Lsymbol *q = lhead; q != NULL; q = q->next)
		{
			int end = q->binding + ((q->size1 > 0) ? q->size * q->size1 : q->size) - 1;
			if (end > max)
				max = end;
		}
		x->binding = max + 1;
	}
	x->next = lhead;
	lhead = x;
	return 1;
}

int countArguments(tnode *a)
{
	if (a == NULL)
		return 0;
	if (a->nodetype == NODE_CONNECTOR)
		return countArguments(a->left) + countArguments(a->right);
	return 1;
}

tnode *makeCallNode(char *name, tnode *args, int argc)
{
	gsymbol *f = lookupFunction(name);
	if (f == NULL)
	{
		/* Keep a placeholder so calls to functions defined later are legal. */
		f = (gsymbol *)calloc(1, sizeof(gsymbol));
		f->name = strdup(name);
		f->type = -1;
		f->isFunction = 1;
		f->paramCount = -1;
		f->next = ghead;
		ghead = f;
	}
	tnode *temp = (tnode *)calloc(1, sizeof(tnode));
	temp->nodetype = NODE_CALL;
	temp->name = strdup(name);
	temp->symbol = f;
	temp->args = args;
	temp->argCount = argc;
	temp->type = f->type;
	temp->isPointer = f->isPointer;
	return temp;
}

tnode *makeCallStmtNode(char *name, tnode *args, int argc)
{
	tnode *temp = makeCallNode(name, args, argc);
	temp->nodetype = NODE_CALL_STMT;
	return temp;
}

tnode *makeReturnNode(tnode *expr)
{
	if (currentFunction == NULL)
		yyerror("ERROR:Return statement outside function\n");
	if (expr == NULL ||
			(expr->type != currentFunction->type && expr->type != -1) ||
			(expr->type != -1 && expr->isPointer != currentFunction->isPointer))
		yyerror("ERROR:Return type mismatch\n");
	tnode *temp = (tnode *)calloc(1, sizeof(tnode));
	temp->nodetype = NODE_RETURN;
	temp->left = expr;
	temp->symbol = currentFunction;
	temp->type = currentFunction->type;
	temp->isPointer = currentFunction->isPointer;
	return temp;
}

tnode *makeFunctionNode(gsymbol *sym, tnode *body)
{
	tnode *temp = (tnode *)calloc(1, sizeof(tnode));
	temp->nodetype = NODE_FUNCTION;
	temp->symbol = sym;
	temp->left = body;
	temp->name = strdup(sym->name);
	temp->type = sym->type;
	sym->body = body;
	return temp;
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
	gsymbol *sym = NULL;
	Lsymbol *lsym = NULL;
	resolveName(name, &sym, &lsym);
	if (sym->size > 1 || sym->size1 > 0)
	{
		yyerror("ERROR:Cannot directly assign to array\n");
	}
	if (sym->size1 == -1)
	{
		if (t1->type != sym->type && t1->type != -1)
			yyerror("ERROR:Pointer base type mismatch\n");
		if (t1->type != -1 && !t1->isPointer)
			yyerror("ERROR:Cannot assign non-pointer value to pointer\n");
	}
	else
	{
		if (t1->type != sym->type && t1->type != -1)
		{
			yyerror("Type mismatch:Compilation Error\n");
			return NULL;
		}
		if (t1->type != -1 && t1->isPointer)
			yyerror("ERROR:Cannot assign pointer to non-pointer\n");
	}
	tnode *temp = (tnode *)(calloc(1, sizeof(tnode)));
	temp->type = sym->type;
	temp->nodetype = NODE_ASSIGN;
	temp->name = strdup(name);
	temp->symbol = sym;
	temp->lsymbol = lsym;
	temp->left = t1;
	return temp;
}

tnode *makePointerAssignmentNode(char *name, tnode *t1)
{
	gsymbol *sym = NULL;
	Lsymbol *lsym = NULL;
	resolveName(name, &sym, &lsym);
	if (sym->size1 != -1)
	{
		yyerror("ERROR:Cannot deference non-pointer type\n");
	}
	if (sym->type != t1->type && t1->type != -1)
	{
		yyerror("Invalid Address\n");
		return NULL;
	}
	if (t1->type != -1 && t1->isPointer)
	{
		yyerror("Invalid pointer assignment\n");
		return NULL;
	}
	tnode *temp = (tnode *)(calloc(1, sizeof(tnode)));
	temp->type = sym->type;
	temp->nodetype = NODE_DEREF_ASSG;
	temp->name = strdup(name);
	temp->symbol = sym;
	temp->lsymbol = lsym;
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
	gsymbol *sym = NULL;
	Lsymbol *lsym = NULL;
	resolveName(name, &sym, &lsym);
	if (sym->size > 1 || sym->size1 > 0)
	{
		yyerror("ERROR:Invalid array Read\n");
	}
	tnode *temp = (tnode *)(calloc(1, sizeof(tnode)));
	temp->nodetype = NODE_READ;
	temp->name = strdup(name);
	temp->symbol = sym;
	temp->lsymbol = lsym;
	temp->type = sym->type;
	return temp;
}

tnode *makeReadPointerNode(char *name)
{
	gsymbol *sym = NULL;
	Lsymbol *lsym = NULL;
	resolveName(name, &sym, &lsym);
	if (sym->size1 != -1)
	{
		yyerror("ERROR:Cannot Deference a non-pointer\n");
	}
	tnode *temp = (tnode *)(calloc(1, sizeof(tnode)));
	temp->nodetype = NODE_READ;
	temp->name = strdup(name);
	temp->symbol = sym;
	temp->lsymbol = lsym;
	temp->type = sym->type;
	return temp;
}

tnode *makeReadArrayNode(char *name, tnode *index)
{
	gsymbol *sym = NULL;
	Lsymbol *lsym = NULL;
	resolveName(name, &sym, &lsym);
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
	temp->lsymbol = lsym;
	temp->left = index;

	return temp;
}

tnode *makeRead2DArrayNode(char *name, tnode *index, tnode *index1)
{
	gsymbol *sym = NULL;
	Lsymbol *lsym = NULL;
	resolveName(name, &sym, &lsym);
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
	temp->lsymbol = lsym;
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
	gsymbol *temp1 = NULL;
	Lsymbol *lsym = NULL;
	resolveName(name, &temp1, &lsym);
	if (temp1->size > 1 || temp1->size1 > 0)
		yyerror("ERROR:Cannot used an array without indexing\n");
	tnode *temp = (tnode *)calloc(1, sizeof(tnode));
	temp->name = strdup(name);
	temp->nodetype = NODE_VAR;
	temp->symbol = (lsym == NULL) ? temp1 : NULL;
	temp->lsymbol = lsym;
	temp->type = temp1->type;
	temp->isPointer = (temp1->size1 == -1);
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
	if ((l->type != TYPE_INT && l->type != -1) || (r->type != TYPE_INT && r->type != -1))
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

static void checkCallArguments(tnode *a, Param **p)
{
	if (a == NULL)
		return;
	if (a->nodetype == NODE_CONNECTOR)
	{
		checkCallArguments(a->left, p);
		checkCallArguments(a->right, p);
		return;
	}
	if (*p == NULL)
		yyerror("ERROR:Too many arguments\n");
	if (a->type != (*p)->type)
		yyerror("ERROR:Argument type mismatch\n");
	if (a->type != -1 && a->isPointer != (*p)->isPointer)
		yyerror("ERROR:Pointer/scalar argument mismatch\n");
	*p = (*p)->next;
}

static void resolveCallsInTree(tnode *t)
{
	if (t == NULL)
		return;
	if (t->nodetype == NODE_CALL || t->nodetype == NODE_CALL_STMT)
	{
		gsymbol *f = lookupFunction(t->name);
		if (f == NULL || f->paramCount < 0)
			yyerror("ERROR:Undeclared function called\n");
		if (t->argCount != f->paramCount)
			yyerror("ERROR:Incorrect number of arguments\n");
		Param *p = f->params;
		checkCallArguments(t->args, &p);
		if (p != NULL)
			yyerror("ERROR:Too few arguments\n");
		t->symbol = f;
		t->type = f->type;
		t->isPointer = f->isPointer;
	}
	resolveCallsInTree(t->left);
	resolveCallsInTree(t->middle);
	resolveCallsInTree(t->right);
	resolveCallsInTree(t->args);
}

void resolveAllCalls(tnode *mainTree)
{
	for (gsymbol *g = ghead; g != NULL; g = g->next)
		if (g->isFunction && g->body != NULL)
			resolveCallsInTree(g->body);
	resolveCallsInTree(mainTree);
}
