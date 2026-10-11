#include "exptree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern FILE *intermediate;
int count = -1;
int ind = 0;
int breakstack[100];
int continuestack[100];
int loopind = -1;

void push(int breakLabel, int continueLabel)
{
	loopind++;
	breakstack[loopind] = breakLabel;
	continuestack[loopind] = continueLabel;
}
void pop()
{
	loopind--;
}
int getReg()
{
	if (count < 19)
	{
		count++;
		if (count == 2)
			count++;
		return count;
	}
	printf("Out of Registers\n");
	exit(1);
}
int getLabel()
{
	return ind++;
}
void freeReg()
{
	if (count >= 0)
	{
		count--;
		if (count == 2)
			count--;
	}
}

static int symbolBinding(tnode *t)
{
	return t->lsymbol ? t->lsymbol->binding : t->symbol->binding;
}
static int symbolSize(tnode *t)
{
	return t->lsymbol ? t->lsymbol->size : t->symbol->size;
}
static int symbolSize1(tnode *t)
{
	return t->lsymbol ? t->lsymbol->size1 : t->symbol->size1;
}
static int isLocal(tnode *t)
{
	return t->lsymbol != NULL;
}
static void loadAddress(tnode *t, int reg)
{
	if (isLocal(t))
		fprintf(intermediate, "MOV R%d, BP\nADD R%d, %d\n", reg, reg, symbolBinding(t));
	else
		fprintf(intermediate, "MOV R%d, %d\n", reg, 4096 + symbolBinding(t));
}
static void loadValue(tnode *t, int reg)
{
	if (isLocal(t))
	{
		fprintf(intermediate, "MOV R2, BP\nADD R2, %d\nMOV R%d, [R2]\n", symbolBinding(t), reg);
	}
	else
		fprintf(intermediate, "MOV R%d, [%d]\n", reg, 4096 + symbolBinding(t));
}
static void storeValue(tnode *t, int reg)
{
	if (isLocal(t))
		fprintf(intermediate, "MOV R2, BP\nADD R2, %d\nMOV [R2], R%d\n", symbolBinding(t), reg);
	else
		fprintf(intermediate, "MOV [%d], R%d\n", 4096 + symbolBinding(t), reg);
}

static int countLocalCells(gsymbol *f)
{
	int n = 0;
	for (Lsymbol *x = f->localTable; x != NULL; x = x->next)
		if (x->binding > 0)
			n += (x->size1 > 0) ? x->size * x->size1 : x->size;
	return n;
}

static void emitPopLocals(gsymbol *f)
{
	int n = countLocalCells(f);
	while (n-- > 0)
		fprintf(intermediate, "POP R0\n");
}

static void emitPushLocals(Lsymbol *x)
{
	if (x == NULL)
		return;
	emitPushLocals(x->next);
	if (x->binding > 0)
	{
		int n = (x->size1 > 0) ? x->size * x->size1 : x->size;
		while (n-- > 0)
			fprintf(intermediate, "PUSH R0\n");
	}
}

static int countArgs(tnode *a)
{
	if (a == NULL)
		return 0;
	if (a->nodetype == NODE_CONNECTOR)
		return countArgs(a->left) + countArgs(a->right);
	return 1;
}

static void pushArgsReverse(tnode *a)
{
	if (a == NULL)
		return;
	if (a->nodetype == NODE_CONNECTOR)
	{
		pushArgsReverse(a->right);
		pushArgsReverse(a->left);
		return;
	}
	int r = codegen(a);
	fprintf(intermediate, "PUSH R%d\n", r);
	freeReg();
}

static void saveCallerRegisters(int n)
{
	for (int i = 0; i <= n; i++)
	{
		if (i == 2)
			continue;
		fprintf(intermediate, "PUSH R%d\n", i);
	}
}
static void restoreCallerRegisters(int n)
{
	for (int i = n; i >= 0; i--)
	{
		if (i == 2)
			continue;
		fprintf(intermediate, "POP R%d\n", i);
	}
}

int codegen(struct tnode *t)
{
	if (t == NULL)
		return -1;
	else if (t->nodetype == NODE_NUM)
	{
		int r1 = getReg();
		fprintf(intermediate, "MOV R%d, %d\n", r1, t->val);
		return r1;
	}
	else if (t->nodetype == NODE_STR)
	{
		int r = getReg();
		fprintf(intermediate, "MOV R%d, \"%s\"\n", r, t->name);
		return r;
	}
	else if (t->nodetype == NODE_OP)
	{
		int r1 = codegen(t->left);
		int r2 = codegen(t->right);
		if (t->op[0] == '+')
			fprintf(intermediate, "ADD R%d, R%d\n", r1, r2);
		else if (t->op[0] == '-')
			fprintf(intermediate, "SUB R%d, R%d\n", r1, r2);
		else if (t->op[0] == '*')
			fprintf(intermediate, "MUL R%d, R%d\n", r1, r2);
		else if (t->op[0] == '/')
			fprintf(intermediate, "DIV R%d, R%d\n", r1, r2);
		else if (t->op[0] == '%')
			fprintf(intermediate, "MOD R%d, R%d\n", r1, r2);
		else if (strcmp(t->op, "<=") == 0)
			fprintf(intermediate, "LE R%d, R%d\n", r1, r2);
		else if (strcmp(t->op, ">=") == 0)
			fprintf(intermediate, "GE R%d, R%d\n", r1, r2);
		else if (strcmp(t->op, "!=") == 0)
			fprintf(intermediate, "NE R%d, R%d\n", r1, r2);
		else if (strcmp(t->op, "==") == 0)
			fprintf(intermediate, "EQ R%d, R%d\n", r1, r2);
		else if (t->op[0] == '<')
			fprintf(intermediate, "LT R%d, R%d\n", r1, r2);
		else if (t->op[0] == '>')
			fprintf(intermediate, "GT R%d, R%d\n", r1, r2);
		freeReg();
		return r1;
	}
	else if (t->nodetype == NODE_VAR)
	{
		int r = getReg();
		loadValue(t, r);
		return r;
	}
	else if (t->nodetype == NODE_ARR)
	{
		int r1 = getReg();
		int r2 = codegen(t->left);
		loadAddress(t, r1);
		fprintf(intermediate, "ADD R%d, R%d\n", r1, r2);
		freeReg();
		fprintf(intermediate, "MOV R%d, [R%d]\n", r1, r1);
		return r1;
	}
	else if (t->nodetype == NODE_2D_ARR)
	{
		int r1 = getReg();
		int r2 = codegen(t->left);
		int r3 = codegen(t->middle);
		loadAddress(t, r1);
		fprintf(intermediate, "MUL R%d, %d\n", r2, symbolSize1(t));
		fprintf(intermediate, "ADD R%d, R%d\n", r2, r3);
		freeReg();
		fprintf(intermediate, "ADD R%d, R%d\n", r1, r2);
		freeReg();
		fprintf(intermediate, "MOV R%d, [R%d]\n", r1, r1);
		return r1;
	}
	else if (t->nodetype == NODE_ASSIGN)
	{
		int r = codegen(t->left);
		storeValue(t, r);
		freeReg();
		return -1;
	}
	else if (t->nodetype == NODE_DEREF_ASSG)
	{
		int r = codegen(t->left);
		int r1 = getReg();
		loadValue(t, r1);
		fprintf(intermediate, "MOV [R%d], R%d\n", r1, r);
		freeReg();
		freeReg();
		return -1;
	}
	else if (t->nodetype == NODE_ARR_ASSG)
	{
		int r1 = getReg();
		int r3 = codegen(t->right);
		int r2 = codegen(t->left);
		loadAddress(t, r1);
		fprintf(intermediate, "ADD R%d,R%d\n", r1, r2);
		freeReg();
		fprintf(intermediate, "MOV [R%d],R%d\n", r1, r3);
		freeReg();
		freeReg();
		return -1;
	}
	else if (t->nodetype == NODE_2D_ARR_ASSG)
	{
		int r1 = getReg();
		int r4 = codegen(t->right);
		int r2 = codegen(t->left);
		int r3 = codegen(t->middle);
		loadAddress(t, r1);
		fprintf(intermediate, "MUL R%d,%d\n", r2, symbolSize1(t));
		fprintf(intermediate, "ADD R%d,R%d\n", r2, r3);
		freeReg();
		fprintf(intermediate, "ADD R%d,R%d\n", r1, r2);
		freeReg();
		fprintf(intermediate, "MOV [R%d],R%d\n", r1, r4);
		freeReg();
		freeReg();
		return -1;
	}
	else if (t->nodetype == NODE_CONNECTOR)
	{
		codegen(t->left);
		codegen(t->right);
		return -1;
	}
	else if (t->nodetype == NODE_BREAK)
	{
		if (loopind >= 0)
			fprintf(intermediate, "JMP L%d\n", breakstack[loopind]);
		return -1;
	}
	else if (t->nodetype == NODE_CONTINUE)
	{
		if (loopind >= 0)
			fprintf(intermediate, "JMP L%d\n", continuestack[loopind]);
		return -1;
	}
	else if (t->nodetype == NODE_IF)
	{
		int elselab = getLabel(), endlab = getLabel();
		int r = codegen(t->left);
		fprintf(intermediate, "JZ R%d, L%d\n", r, elselab);
		freeReg();
		codegen(t->middle);
		fprintf(intermediate, "JMP L%d\nL%d:\n", endlab, elselab);
		if (t->right)
			codegen(t->right);
		fprintf(intermediate, "L%d:\n", endlab);
		return -1;
	}
	else if (t->nodetype == NODE_WHILE)
	{
		int startlab = getLabel(), endlab = getLabel();
		push(endlab, startlab);
		fprintf(intermediate, "L%d:\n", startlab);
		int r = codegen(t->left);
		fprintf(intermediate, "JZ R%d, L%d\n", r, endlab);
		freeReg();
		codegen(t->middle);
		fprintf(intermediate, "JMP L%d\nL%d:\n", startlab, endlab);
		pop();
		return -1;
	}
	else if (t->nodetype == NODE_DOWHILE)
	{
		int startlab = getLabel(), midlab = getLabel(), endlab = getLabel();
		push(endlab, midlab);
		fprintf(intermediate, "L%d:\n", startlab);
		codegen(t->middle);
		fprintf(intermediate, "L%d:\n", midlab);
		int r = codegen(t->left);
		fprintf(intermediate, "JNZ R%d, L%d\n", r, startlab);
		freeReg();
		fprintf(intermediate, "L%d:\n", endlab);
		pop();
		return -1;
	}
	else if (t->nodetype == NODE_ADDR)
	{
		int r = getReg();
		loadAddress(t, r);
		return r;
	}
	else if (t->nodetype == NODE_DEREF)
	{
		int r = getReg(), r1 = getReg();
		loadValue(t, r1);
		fprintf(intermediate, "MOV R%d, [R%d]\n", r, r1);
		freeReg();
		return r;
	}
	else if (t->nodetype == NODE_REPEAT)
	{
		int startlab = getLabel(), midlab = getLabel(), endlab = getLabel();
		push(endlab, midlab);
		fprintf(intermediate, "L%d:\n", startlab);
		codegen(t->middle);
		fprintf(intermediate, "L%d:\n", midlab);
		int r = codegen(t->left);
		fprintf(intermediate, "JZ R%d, L%d\n", r, startlab);
		freeReg();
		fprintf(intermediate, "L%d:\n", endlab);
		pop();
		return -1;
	}
	else if (t->nodetype == NODE_READ)
	{
		int r = getReg();
		if (t->lsymbol && t->lsymbol->size1 == -1)
			loadValue(t, r);
		else if (t->middle != NULL)
		{
			int r1 = codegen(t->left);
			loadAddress(t, r);
			fprintf(intermediate, "MUL R%d, %d\n", r1, symbolSize1(t));
			int r2 = codegen(t->middle);
			fprintf(intermediate, "ADD R%d, R%d\n", r1, r2);
			freeReg();
			fprintf(intermediate, "ADD R%d, R%d\n", r, r1);
			freeReg();
		}
		else if (t->left != NULL)
		{
			int r1 = codegen(t->left);
			loadAddress(t, r);
			fprintf(intermediate, "ADD R%d, R%d\n", r, r1);
			freeReg();
		}
		else
			loadAddress(t, r);
		fprintf(intermediate, "MOV R2, \"Read\"\nPUSH R2\nMOV R2,-1\nPUSH R2\nMOV R2,R%d\nPUSH R2\nPUSH R2\nPUSH R2\nCALL 0\nPOP R0\nPOP R1\nPOP R1\nPOP R1\nPOP R1\n", r);
		freeReg();
		return -1;
	}
	else if (t->nodetype == NODE_WRITE)
	{
		int r = codegen(t->left);
		fprintf(intermediate, "MOV R2,\"Write\"\nPUSH R2\nMOV R2,-2\nPUSH R2\nPUSH R%d\nPUSH R2\nPUSH R2\nCALL 0\nPOP R0\nPOP R1\nPOP R1\nPOP R1\nPOP R1\n", r);
		freeReg();
		return -1;
	}
	else if (t->nodetype == NODE_CALL || t->nodetype == NODE_CALL_STMT)
	{
		/* Save only registers live in the caller. */
		int saved = count;
		saveCallerRegisters(saved);
		pushArgsReverse(t->args);
		/* Empty slot reserved for the return value. */
		fprintf(intermediate, "MOV R2, 0\nPUSH R2\n");
		fprintf(intermediate, "CALL L%d\n", t->symbol->label);
		int r = getReg();
		fprintf(intermediate, "POP R%d\n", r);
		for (int i = 0; i < t->argCount; i++)
			fprintf(intermediate, "POP R2\n");
		restoreCallerRegisters(saved);
		if (t->nodetype == NODE_CALL_STMT)
		{
			freeReg();
			return -1;
		}
		return r;
	}
	else if (t->nodetype == NODE_RETURN)
	{
		/* Store the return value first. The function epilogue is emitted
		 * once, at the common return label, so recursive calls do not
		 * accidentally execute two epilogues. */
		int r = codegen(t->left);
		fprintf(intermediate, "MOV R2, BP\nADD R2, -2\nMOV [R2], R%d\n", r);
		freeReg();
		fprintf(intermediate, "JMP L%d\n", t->symbol->returnLabel);
		return -1;
	}
	else
		return -1;
}

static void codegenFunction(gsymbol *f)
{
	fprintf(intermediate, "L%d:\n", f->label);
	fprintf(intermediate, "PUSH BP\nMOV BP, SP\n");
	emitPushLocals(f->localTable);
	codegen(f->body);
	/* All return statements converge here. */
	fprintf(intermediate, "L%d:\n", f->returnLabel);
	emitPopLocals(f);
	fprintf(intermediate, "POP BP\nRET\n");
}

void codegenFunctions(void)
{
	gsymbol *mainFunc = NULL;

	for (gsymbol *g = ghead; g != NULL; g = g->next)
	{
		if (g->isFunction)
		{
			g->label = getLabel();
			g->returnLabel = getLabel();

			if (strcmp(g->name, "main") == 0)
				mainFunc = g;
		}
	}

	if (mainFunc == NULL)
	{
		printf("main function not found\n");
		exit(1);
	}

	fprintf(intermediate, "CALL L%d\n", mainFunc->label);
	fprintf(intermediate, "INT 10\n");

	for (gsymbol *g = ghead; g != NULL; g = g->next)
		if (g->isFunction)
			codegenFunction(g);
}
