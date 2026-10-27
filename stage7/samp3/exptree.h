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
#define NODE_ADDR 19
#define NODE_DEREF 20
#define NODE_DEREF_ASSG 21
#define NODE_CALL 22
#define NODE_RETURN 23
#define NODE_FUNCTION 24
#define NODE_CALL_STMT 25
#define NODE_FIELD_ACCESS 26
#define NODE_FIELD_ASSIGN 27
#define NODE_FIELD_READ 28
#define NODE_BUILTIN_ALLOC 29
#define NODE_BUILTIN_FREE 30
#define NODE_BUILTIN_INITIALIZE 31

#define TYPE_INT 0
#define TYPE_BOOL 1
#define TYPE_STR 2
#define TYPE_TUPLE_BASE 100
#define TYPE_USER_BASE 200
#define TYPE_NULL -2

typedef struct Lsymbol Lsymbol;
typedef struct Param Param;

#define TYPE_PTR_FLAG 8

typedef struct Gsymbol
{
    char *name;
    int type;
    int size;
    int size1;
    int binding;
    int isFunction;
    int paramCount;
    Param *params;
    Lsymbol *localTable;
    struct tnode *body;
    int label;
    int returnLabel;
    int isPointer;
    struct Gsymbol *next;
} gsymbol;

struct Lsymbol
{
    char *name;
    int type;
    int size;
    int size1;
    int binding;
    struct Lsymbol *next;
};

struct Param
{
    char *name;
    int type;
    int isPointer;
    struct Param *next;
};

typedef struct tnode
{
    int val;
    int type;
    int isPointer;
    int nodetype;
    char *name;
    gsymbol *symbol;
    Lsymbol *lsymbol;
    char *op;
    int argCount;
    struct tnode *args;
    struct tnode *left, *middle, *right;
} tnode;

struct tnode *makeLeafNode(int n);
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
struct tnode *makeAddressNode(char *name);
struct tnode *makeDeReferenceNode(char *name);
struct tnode *makePointerAssignmentNode(char *name, struct tnode *value);
struct tnode *makeReadPointerNode(char *name);

// FUNCTION STUFF
struct tnode *makeCallNode(char *name, struct tnode *args, int argc);
struct tnode *makeCallStmtNode(char *name, struct tnode *args, int argc);
struct tnode *makeReturnNode(struct tnode *expr);
int countArguments(struct tnode *args);
void resolveAllCalls(struct tnode *mainTree);
int countArguments(struct tnode *args);
void resolveAllCalls(struct tnode *mainTree);
tnode *makeFunctionNode(gsymbol *sym, tnode *body);

int install(char *name, int type, int size1, int size2);
gsymbol *lookup(char *name);

// MORE FUNCTION STUFF
gsymbol *lookupFunction(char *name);
int installFunction(char *name, int type, Param *params, int isPointer);
void beginFunction(gsymbol *sym);
void endFunction(void);
int installLocal(char *name, int type, int size, int size1);
Lsymbol *lookupLocal(char *name);
Param *makeParam(char *name, int type, int isPointer);
Param *appendParam(Param *a, Param *b);

int evaluate(struct tnode *t);
int codegen(struct tnode *t);
void codegenFunctions(void);
int yyerror(char *s);
int defineTupleType(char *name, char *fieldNames[], int fieldTypes[], int count);
/* User-defined aggregate types (Task 1: front end and semantic analysis). */
int beginUserType(char *name);
int addUserTypeField(char *typeName, int fieldType, char *fieldName);
int lookupUserType(char *name);
int isUserType(int type);
int userTypeFieldOffset(int type, char *fieldName);
int userTypeFieldCount(int type);
tnode *makeFieldAccessNode(tnode *base, char *field);
tnode *makeFieldAssignmentNode(tnode *field, tnode *expr);
tnode *makeReadFieldNode(tnode *field);
tnode *makeNullNode(void);
tnode *makeArrayFieldAccessNode(char *arrayName, tnode *index, char *fieldName);
int installTupleVariable(char *typeName, char *name, int local);
tnode *makeTupleFieldNode(char *name, char *field);
tnode *makeTupleAssignmentNode(char *dst, char *src);

/* Minimal Stage 7 class support layered onto the existing user-type/function model. */
int beginClass(char *name);
int classType(char *name);
int validateClassMethods(char *className);
char *mangleMethodName(const char *className, const char *methodName);
Param *prependSelfParam(const char *className, Param *params);
tnode *makeNewNode(char *className);
tnode *makeMethodCallNode(tnode *receiver, char *methodName, tnode *args, int argc);

extern gsymbol *ghead;
extern gsymbol *currentFunction;
extern Lsymbol *lhead;

#endif
