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
	else if(t->nodetype==NODE_NUM)
	{
		int r1=getReg();
		fprintf(intermediate,"MOV R%d, %d\n",r1,t->val);
		return r1;
	}
	else if(t->nodetype==NODE_OP)
	{
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
        else if(t->nodetype==NODE_VAR)
        {
		int r = getReg();
		int address = 4096 + (t->name[0] - 'a');
		fprintf(intermediate,"MOV R%d, [%d]\n",r,address);
		return r;
        }
        else if(t->nodetype==NODE_ASSIGN)
        {
		int r = codegen(t->left);
		int address = 4096 + (t->name[0] - 'a');
		fprintf(intermediate,"MOV [%d], R%d\n",address,r);
		freeReg();
		return -1;
        }
        else if(t->nodetype==NODE_CONNECTOR)
        {
		codegen(t->left);
		codegen(t->right);
		return -1;
        }
        else if(t->nodetype==NODE_READ)
        {
		int address = 4096 + (t->name[0]-'a');
		fprintf(intermediate,"MOV R2, \"Read\"\n");
		fprintf(intermediate,"PUSH R2\n");
		fprintf(intermediate,"MOV R2,-1\n");
		fprintf(intermediate,"PUSH R2\n");
		fprintf(intermediate,"MOV R2,%d\n",address);
		fprintf(intermediate,"PUSH R2\n");
		fprintf(intermediate,"PUSH R2\n");
		fprintf(intermediate,"PUSH R2\n");
		fprintf(intermediate,"CALL 0\n");
		fprintf(intermediate,"POP R0\n");
		fprintf(intermediate,"POP R1\n");
		fprintf(intermediate,"POP R1\n");
		fprintf(intermediate,"POP R1\n");
		fprintf(intermediate,"POP R1\n");
		return -1;
        }
        else if(t->nodetype==NODE_WRITE)
        {
		int r = codegen(t->left);
		fprintf(intermediate,"MOV R2,\"Write\"\n");
		fprintf(intermediate,"PUSH R2\n");
		fprintf(intermediate,"MOV R2,-2\n");
		fprintf(intermediate,"PUSH R2\n");
		fprintf(intermediate,"PUSH R%d\n",r);
		fprintf(intermediate,"PUSH R2\n");
		fprintf(intermediate,"PUSH R2\n");
		fprintf(intermediate,"CALL 0\n");
		fprintf(intermediate,"POP R0\n");
		fprintf(intermediate,"POP R1\n");
		fprintf(intermediate,"POP R1\n");
		fprintf(intermediate,"POP R1\n");
		fprintf(intermediate,"POP R1\n");

		freeReg();
		return -1;
        }
}
