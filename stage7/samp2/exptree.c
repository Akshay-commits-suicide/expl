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


typedef struct TupleDef { char *name; int count; char **fields; int *types; struct TupleDef *next; } TupleDef;
typedef struct TupleVar { char *name; TupleDef *def; int local; struct TupleVar *next; } TupleVar;
static TupleDef *tupleDefs = NULL;
static TupleVar *tupleVars = NULL;
static TupleDef *findTuple(char *name) { for(TupleDef *t=tupleDefs;t;t=t->next) if(!strcmp(t->name,name)) return t; return NULL; }
static TupleVar *findTupleVar(char *name) { for(TupleVar *t=tupleVars;t;t=t->next) if(!strcmp(t->name,name)) return t; return NULL; }
int defineTupleType(char *name, char *fieldNames[], int fieldTypes[], int count) {
 if(findTuple(name)) yyerror("ERROR: Tuple type already declared\n");
 TupleDef *t=calloc(1,sizeof(TupleDef)); t->name=strdup(name); t->count=count;
 t->fields=calloc(count,sizeof(char*)); t->types=calloc(count,sizeof(int));
 for(int i=0;i<count;i++){ t->fields[i]=strdup(fieldNames[i]); t->types[i]=fieldTypes[i]; }
 t->next=tupleDefs; tupleDefs=t; return TYPE_TUPLE_BASE+(int)(tupleDefs ? 0 : 0);
}
int installTupleVariable(char *typeName, char *name, int local) {
 TupleDef *d=findTuple(typeName); if(!d) yyerror("ERROR: Undeclared tuple type\n");
 if(findTupleVar(name)) yyerror("ERROR: Tuple variable already declared\n");
 TupleVar *v=calloc(1,sizeof(TupleVar)); v->name=strdup(name); v->def=d; v->local=local; v->next=tupleVars; tupleVars=v;
 for(int i=0;i<d->count;i++){ char buf[256]; snprintf(buf,sizeof(buf),"%s.%s",name,d->fields[i]); if(local) installLocal(buf,d->types[i],1,0); else install(buf,d->types[i],1,0); }
 return 1;
}
tnode *makeTupleFieldNode(char *name, char *field) {
 char buf[256]; snprintf(buf,sizeof(buf),"%s.%s",name,field); return makeVariableNode(buf);
}
tnode *makeTupleAssignmentNode(char *dst, char *src) {
 TupleVar *a=findTupleVar(dst), *b=findTupleVar(src);
 if(!a || !b) return makeAssignmentNode(dst,makeVariableNode(src));
 if(a->def!=b->def) yyerror("ERROR: Tuple assignment type mismatch\n");
 tnode *root=NULL;
 for(int i=0;i<a->def->count;i++){ char x[256],y[256]; snprintf(x,sizeof(x),"%s.%s",dst,a->def->fields[i]); snprintf(y,sizeof(y),"%s.%s",src,a->def->fields[i]); tnode *n=makeAssignmentNode(x,makeVariableNode(y)); root=root?makeConnectorNode(root,n):n; }
 return root;
}


/* User-defined aggregate types. Every member occupies one word. Members
 * whose type is another user type hold a pointer to another allocated object. */
typedef struct UserField {
    char *name;
    int type;
    int offset;
    struct UserField *next;
} UserField;

typedef struct UserType {
    char *name;
    int typeId;
    int fieldCount;
    UserField *fields;
    struct UserType *next;
} UserType;

static UserType *userTypes = NULL;
static int nextUserTypeId = TYPE_USER_BASE;

static UserType *findUserTypeByName(const char *name)
{
    for (UserType *t = userTypes; t; t = t->next)
        if (strcmp(t->name, name) == 0) return t;
    return NULL;
}
static UserType *findUserTypeById(int type)
{
    for (UserType *t = userTypes; t; t = t->next)
        if (t->typeId == type) return t;
    return NULL;
}
int lookupUserType(char *name)
{
    UserType *t = findUserTypeByName(name);
    return t ? t->typeId : -1;
}
int isUserType(int type) { return findUserTypeById(type) != NULL; }

int userTypeFieldCount(int type)
{
    UserType *t = findUserTypeById(type);
    return t ? t->fieldCount : 0;
}
int userTypeFieldOffset(int type, char *fieldName)
{
    UserType *t = findUserTypeById(type);
    if (!t) yyerror("ERROR: Member access on a non-user-defined type\n");
    for (UserField *f = t->fields; f; f = f->next)
        if (strcmp(f->name, fieldName) == 0) return f->offset;
    yyerror("ERROR: No such member in user-defined type\n");
    return -1;
}
static int getUserFieldType(int type, const char *fieldName)
{
    UserType *t = findUserTypeById(type);
    if (!t) yyerror("ERROR: Member access on a non-user-defined type\n");
    for (UserField *f = t->fields; f; f = f->next)
        if (strcmp(f->name, fieldName) == 0) return f->type;
    yyerror("ERROR: No such member in user-defined type\n");
    return -1;
}
int beginUserType(char *name)
{
    if (!strcmp(name, "int") || !strcmp(name, "str") ||
        !strcmp(name, "bool") || findUserTypeByName(name))
        yyerror("ERROR: Duplicate or reserved user-defined type name\n");
    UserType *t = calloc(1, sizeof(UserType));
    if (!t) { perror("calloc"); exit(1); }
    t->name = strdup(name);
    t->typeId = nextUserTypeId++;
    t->next = userTypes;
    userTypes = t;
    return t->typeId;
}
int addUserTypeField(char *typeName, int fieldType, char *fieldName)
{
    UserType *t = findUserTypeByName(typeName);
    if (!t) yyerror("ERROR: Type definition is not active\n");
    if (fieldType != TYPE_INT && fieldType != TYPE_STR &&
        fieldType != TYPE_BOOL && !isUserType(fieldType))
        yyerror("ERROR: Invalid member field type\n");
    for (UserField *f = t->fields; f; f = f->next)
        if (!strcmp(f->name, fieldName))
            yyerror("ERROR: Duplicate member field name\n");
    if (t->fieldCount >= 8)
        yyerror("Too many member fields\n");
    UserField *f = calloc(1, sizeof(UserField));
    if (!f) { perror("calloc"); exit(1); }
    f->name = strdup(fieldName);
    f->type = fieldType;
    f->offset = t->fieldCount++;
    if (!t->fields) t->fields = f;
    else {
        UserField *tail = t->fields;
        while (tail->next) tail = tail->next;
        tail->next = f;
    }
    return fieldType;
}

tnode *makeFieldAccessNode(tnode *base, char *field)
{
    if (!base || !isUserType(base->type))
        yyerror("ERROR: Member access on a non-user-defined type\n");
    tnode *n = calloc(1, sizeof(tnode));
    n->nodetype = NODE_FIELD_ACCESS;
    n->left = base;
    n->name = strdup(field);
    n->val = userTypeFieldOffset(base->type, field);
    n->type = getUserFieldType(base->type, field);
    /* A user-defined member is represented by a pointer to its allocated object. */
    n->isPointer = isUserType(n->type);
    return n;
}
tnode *makeArrayFieldAccessNode(char *arrayName, tnode *index, char *fieldName)
{
    return makeFieldAccessNode(makeArrayNode(arrayName, index), fieldName);
}
tnode *makeFieldAssignmentNode(tnode *field, tnode *expr)
{
    if (!field || !expr || field->nodetype != NODE_FIELD_ACCESS)
        yyerror("ERROR: Invalid member assignment\n");
    if (expr->type != field->type &&
        !(expr->type == TYPE_NULL && isUserType(field->type)) &&
        expr->type != -1)
        yyerror("ERROR: Member assignment type mismatch\n");
    if (expr->isPointer && !isUserType(field->type))
        yyerror("ERROR: Cannot assign pointer to non-pointer field\n");
    tnode *n = calloc(1, sizeof(tnode));
    n->nodetype = NODE_FIELD_ASSIGN;
    n->left = field;
    n->right = expr;
    n->type = field->type;
    return n;
}
tnode *makeReadFieldNode(tnode *field)
{
    if (!field || field->nodetype != NODE_FIELD_ACCESS || isUserType(field->type))
        yyerror("ERROR: Cannot read an aggregate field directly\n");
    tnode *n = calloc(1, sizeof(tnode));
    n->nodetype = NODE_FIELD_READ;
    n->left = field;
    n->type = field->type;
    return n;
}

tnode *makeNullNode(void)
{
    tnode *temp = (tnode *)calloc(1, sizeof(tnode));
    temp->nodetype = NODE_NUM;
    temp->val = 0;
    temp->type = TYPE_NULL;
    return temp;
}

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
    temp->isPointer = isUserType(sym->type) || sym->size1 == -1;
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
    if (value->type != sym->type && value->type != -1 &&
        !(value->type == TYPE_NULL && isUserType(sym->type))) {
        yyerror("ERROR:Type mismatch!\n");
    }
    if (isUserType(sym->type) && value->type != TYPE_NULL &&
        value->type != -1 && !value->isPointer) {
        yyerror("ERROR: Aggregate array element requires a pointer\n");
    } 
    if (!isUserType(sym->type) && value->type == -1 && value->isPointer) {
        yyerror("ERROR: Cannot assign pointer to primitive array element\n");
    } 
    if (!isUserType(sym->type) && value->type == -1 && value->isPointer) {
        yyerror("ERROR: Cannot assign pointer to primitive array element\n");
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
    temp->isPointer = isUserType(sym->type) || sym->size1 == -1;
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
    if (value->type != sym->type && value->type != -1 &&
        !(value->type == TYPE_NULL && isUserType(sym->type))) {
        yyerror("ERROR:Type mismatch!\n");
    }
    if (isUserType(sym->type) && value->type != TYPE_NULL &&
        value->type != -1 && !value->isPointer) {
        yyerror("ERROR: Aggregate array element requires a pointer\n");
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
	if (type != TYPE_INT && type != TYPE_STR && type != TYPE_BOOL && !isUserType(type))
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
    tnode *temp = calloc(1, sizeof(tnode));
    if (!strcmp(name, "Alloc") || !strcmp(name, "Free") ||
        !strcmp(name, "Initialize")) {
        if (!strcmp(name, "Alloc") && argc != 0)
            yyerror("ERROR: Alloc takes no arguments\n");
        if (!strcmp(name, "Initialize") && argc != 0)
            yyerror("ERROR: Initialize takes no arguments\n");
        if (!strcmp(name, "Free") && argc != 1)
            yyerror("ERROR: Free takes exactly one argument\n");
        temp->nodetype = NODE_CALL;
        temp->name = strdup(name);
        temp->args = args;
        temp->argCount = argc;
        temp->type = !strcmp(name, "Alloc") ? -1 : TYPE_INT;
        temp->isPointer = !strcmp(name, "Alloc");
        if (!strcmp(name, "Free") && args &&
            args->type != TYPE_NULL && !args->isPointer && !isUserType(args->type))
            yyerror("ERROR: Free expects a pointer or NULL\n");
        return temp;
    }

    gsymbol *f = lookupFunction(name);
    if (f == NULL) {
        /* Keep a placeholder so calls to functions defined later are legal. */
        f = calloc(1, sizeof(gsymbol));
        f->name = strdup(name);
        f->type = -1;
        f->isFunction = 1;
        f->paramCount = -1;
        f->next = ghead;
        ghead = f;
    }
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
    if (isUserType(sym->type))
    {
        /* User-defined variables store a pointer to their heap object. */
        if (t1->type != TYPE_NULL && t1->type != -1 &&
            (t1->type != sym->type || !t1->isPointer))
            yyerror("ERROR: User-defined type assignment mismatch\n");
    }
    else if (sym->size1 == -1)
    {
        if (t1->type != sym->type && t1->type != -1 &&
            !(t1->type == TYPE_NULL && isUserType(sym->type)))
            yyerror("ERROR:Pointer base type mismatch\n");
        if (t1->type != -1 && t1->type != TYPE_NULL && !t1->isPointer)
            yyerror("ERROR:Cannot assign non-pointer value to pointer\n");
    }
    else
    {
        if (t1->type != sym->type && t1->type != -1)
        {
            yyerror("Type mismatch:Compilation Error\n");
            return NULL;
        }
        if (t1->isPointer)
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
	if (isUserType(sym->type))
		yyerror("ERROR: Cannot read an aggregate value directly\n");
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
	if (a != NULL && isUserType(a->type))
		yyerror("ERROR: Cannot write an aggregate value directly\n");
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
	temp->isPointer = (temp1->size1 == -1 || isUserType(temp1->type));
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
    int pointerCompare = ((isUserType(l->type) &&
                           (r->type == l->type || r->type == TYPE_NULL)) ||
                          (isUserType(r->type) && l->type == TYPE_NULL));
    if (!pointerCompare &&
        ((l->type != TYPE_INT && l->type != -1) ||
         (r->type != TYPE_INT && r->type != -1 && r->type != TYPE_NULL)))
        yyerror("Type mismatch:Compilation Error\n");
    if (pointerCompare && !(op == 'e' || op == 'n')) {
        yyerror("Only equality comparisons are allowed for aggregate pointers\n");
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

// nvm these shi

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
	else if (t->nodetype == NODE_ADDR)
	{
		return t->symbol->binding;
	}
	else if (t->nodetype == NODE_DEREF)
	{
		int address = variables[t->symbol->binding];
		return variables[address];
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
		else if (t->op[0] == '%')
		{
			return evaluate(t->left) % evaluate(t->right);
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
	else if (t->nodetype == NODE_DEREF_ASSG)
	{
		int address = t->symbol->binding;
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
	if (a->type != (*p)->type && a->type != -1) {
        yyerror("ERROR:Argument type mismatch\n");
    }
    if (a->type != -1 && a->isPointer != (*p)->isPointer) {
        yyerror("ERROR:Pointer/scalar argument mismatch\n");
    }
	*p = (*p)->next;
}

static void resolveCallsInTree(tnode *t)
{
	if (t == NULL)
		return;
	if (t->nodetype == NODE_CALL || t->nodetype == NODE_CALL_STMT)
	{
        if (t->name && (!strcmp(t->name, "Alloc") ||
                        !strcmp(t->name, "Free") ||
                        !strcmp(t->name, "Initialize"))) {
            resolveCallsInTree(t->args);
            return;
        }
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


/* ---------------- Minimal Stage 7 class support ---------------- */
int beginClass(char *name)
{
    return beginUserType(name);
}

int classType(char *name)
{
    return lookupUserType(name);
}

char *mangleMethodName(const char *className, const char *methodName)
{
    size_t n = strlen(className) + strlen(methodName) + 3;
    char *out = malloc(n);
    if (!out) { perror("malloc"); exit(1); }
    snprintf(out, n, "%s__%s", className, methodName);
    return out;
}

Param *prependSelfParam(const char *className, Param *params)
{
    int ct = lookupUserType((char *)className);
    if (ct < 0) yyerror("ERROR: Unknown class type for method receiver\n");
    Param *self = makeParam("self", ct, 1);
    self->next = params;
    return self;
}

tnode *makeNewNode(char *className)
{
    int ct = lookupUserType(className);
    if (ct < 0) yyerror("ERROR: new() requires a declared class name\n");
    tnode *n = makeCallNode("Alloc", NULL, 0);
    n->type = ct;
    n->isPointer = 1;
    return n;
}

tnode *makeMethodCallNode(tnode *receiver, char *methodName, tnode *args, int argc)
{
    if (!receiver || !isUserType(receiver->type))
        yyerror("ERROR: Method receiver must be a class object\n");
    UserType *ut = findUserTypeById(receiver->type);
    if (!ut) yyerror("ERROR: Invalid method receiver type\n");
    char *mn = mangleMethodName(ut->name, methodName);
    tnode *allArgs = makeConnectorNode(receiver, args);
    tnode *call = makeCallNode(mn, allArgs, argc + 1);
    if (!call->symbol || call->symbol->paramCount < 0)
        yyerror("ERROR: Method is not declared for this class\n");
    if (call->symbol->paramCount != argc + 1)
        yyerror("ERROR: Incorrect number of method arguments\n");
    return call;
}

int validateClassMethods(char *className)
{
    size_t n = strlen(className) + 3;
    char *prefix = malloc(n);
    if (!prefix) { perror("malloc"); exit(1); }
    snprintf(prefix, n, "%s__", className);
    for (gsymbol *g = ghead; g; g = g->next) {
        if (g->isFunction && strncmp(g->name, prefix, strlen(prefix)) == 0 && !g->body)
            yyerror("ERROR: A declared class method has no definition\n");
    }
    free(prefix);
    return 1;
}
