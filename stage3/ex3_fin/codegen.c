#include "exptree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern FILE* intermediate;
int count = -1;
int ind = 0;
int breakstack[100];
int continuestack[100];
int loopind = -1;
void push(int breakLabel,int continueLabel)
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
	if(count<19)
	{
		count++;
		if(count==2)
		{
			count++;
		}
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
          else if(strcmp(t->op,"<=")==0)
          {
                fprintf(intermediate,"LE R%d, R%d\n",r1,r2);
                freeReg();
                return r1;
          }
	  else if(strcmp(t->op,">=")==0)
          {
                fprintf(intermediate,"GE R%d, R%d\n",r1,r2);
                freeReg();
                return r1;
          }
	  else if(strcmp(t->op,"!=")==0)
          {
                fprintf(intermediate,"NE R%d, R%d\n",r1,r2);
                freeReg();
                return r1;
          }
	  else if(strcmp(t->op,"==")==0)
          {
                fprintf(intermediate,"EQ R%d, R%d\n",r1,r2);
                freeReg();
                return r1;
          }
	  else if(t->op[0]=='<')
          {
                fprintf(intermediate,"LT R%d, R%d\n",r1,r2);
                freeReg();
                return r1;
          }
	  else if(t->op[0]=='>')
          {
                fprintf(intermediate,"GT R%d, R%d\n",r1,r2);
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
        else if(t->nodetype==NODE_BREAK)
        {
		if(loopind<0)
		{
		    return -1;
		}
		fprintf(intermediate,"JMP L%d\n",breakstack[loopind]);
		return -1;
        }
        else if(t->nodetype==NODE_CONTINUE)
        {
		if(loopind<0)
		{
		    return -1;
		}
		fprintf(intermediate,"JMP L%d\n",continuestack[loopind]);
		return -1;
        }
	else if(t->nodetype == NODE_IF)
	{
		int elselab = getLabel();
		int endlab = getLabel();
		int r = codegen(t->left);
		fprintf(intermediate,"JZ R%d, L%d\n",r,elselab);
		freeReg();
		codegen(t->middle);
		fprintf(intermediate,"JMP L%d\n",endlab);
		fprintf(intermediate,"L%d:\n",elselab);
		if(t->right != NULL)
		{
			codegen(t->right);
		}
		fprintf(intermediate,"L%d:\n",endlab);
		return -1;
	}
	else if(t->nodetype == NODE_WHILE)
	{
		int startlab = getLabel();
		int endlab = getLabel();
		push(endlab,startlab);
		fprintf(intermediate,"L%d:\n",startlab);
		int r = codegen(t->left);
		fprintf(intermediate,"JZ R%d, L%d\n",r,endlab);
		freeReg();
		codegen(t->middle);
		fprintf(intermediate,"JMP L%d\n",startlab);
		fprintf(intermediate,"L%d:\n",endlab);
		pop();
		return -1;
	}
	else if(t->nodetype == NODE_DOWHILE)
	{
		int startlab = getLabel();
		int midlab = getLabel();
		int endlab = getLabel();
		push(endlab,midlab);
		fprintf(intermediate,"L%d:\n",startlab);
		codegen(t->middle);
		fprintf(intermediate,"L%d:\n",midlab);
		int r = codegen(t->left);
		fprintf(intermediate,"JNZ R%d, L%d\n",r,startlab);
		freeReg();
		fprintf(intermediate,"L%d:\n",endlab);
		pop();
		return -1;
	}
	else if(t->nodetype == NODE_REPEAT)
	{
		int startlab = getLabel();
		int midlab = getLabel();
		int endlab = getLabel();
		push(endlab,midlab);
		fprintf(intermediate,"L%d:\n",startlab);
		codegen(t->middle);
		fprintf(intermediate,"L%d:\n",midlab);
		int r = codegen(t->left);
		fprintf(intermediate,"JZ R%d, L%d\n",r,startlab);
		freeReg();
		fprintf(intermediate,"L%d:\n",endlab);
		pop();
		return -1;
	}
        else if(t->nodetype==NODE_READ)
        {
		int address = 4096 + (t->name[0]-'a');
		fprintf(intermediate,"MOV R2, \"Read\"\n");
		fprintf(intermediate,"PUSH R2\n");
		fprintf(intermediate,"MOV R2,-1\n");
		fprintf(intermediate,"PUSH R2\n");
		fprintf(intermediate,"MOV R2,%d\n", address);
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
        else
        {
              return -1;
        }
}
