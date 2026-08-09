#include "exptree.h"
#include <stdio.h>
#include <stdlib.h>

extern FILE* intermediate;
int count = -1;

int getReg()
{
	if(count<20)
	{
		count++;
		return count;
	}
	printf("Out of Registers\n");
	exit(1);
}
void freeReg()
{
	if(count>=0)
	{
		count--;
	}
}
int codegen(struct tnode* t)
{
	if(t==NULL)
	{
		return -1;
	}
	else if(t->op==NULL)
	{
		int r1=getReg();
		fprintf(intermediate,"MOV R%d, %d\n",r1,t->val);
		return r1;
	}
	int r1=codegen(t->left);
	int r2=codegen(t->right);
	if(t->op[0]=='+')
	{
		fprintf(intermediate,"ADD R%d, R%d\n",r1,r2);
		freeReg();
		return r1;
	}
	else if(t->op[0]=='-')
        {
		fprintf(intermediate,"SUB R%d, R%d\n",r1,r2);
                freeReg();
                return r1;
        }
	else if(t->op[0]=='*')
        {
		fprintf(intermediate,"MUL R%d, R%d\n",r1,r2);
                freeReg();
                return r1;
        }
	else if(t->op[0]=='/')
        {
		fprintf(intermediate,"DIV R%d, R%d\n",r1,r2);
                freeReg();
                return r1;
        }
}
