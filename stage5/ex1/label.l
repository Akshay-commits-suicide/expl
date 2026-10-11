%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct label
{
	char name[50];
	int address;
	struct label* next;
} label;
label* head = NULL;

int address = 2056;
int pass = 1;

FILE* output;
int linecount=0;
void insertLabel(char* name,int address)
{
	label* newnode = (label *)(malloc(sizeof(label)));
	newnode->address = address;
	newnode->next = NULL;
	strcpy(newnode->name,name);
	if(head==NULL)
	{
		head = newnode;
		return;
	}
	label* temp = head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=newnode;
}
int searchLabel(char* name)
{
	label* temp = head;
	while(temp!=NULL)
	{
		if(strcmp(name,temp->name)==0)
		{
			return temp->address;
		}
		temp=temp->next;
	}
	return -1;
}
void processLine(char* line)
{
	linecount++;
	if(linecount<=8)
	{
		if(pass==2)
		{
			fprintf(output,"%s",line);
		}
		return;
	}
	char buffer[50];
	char label[50];
	strcpy(buffer,line);
	if(sscanf(buffer,"%49[^:]:",label) == 1)
	{
		char* colon = strchr(buffer,':');
		if(colon != NULL)
		{
			char* p = colon+1;
			while(*p == ' ' || *p == '\t')
			{
				p++;
			}
			if(*p == '\n' || *p == '\0')
			{
			
				if(pass == 1)
				{
					if(searchLabel(label) != -1)
					{
						printf("ERROR : Duplicate Label [%s] Found\n",label);
						exit(0);
					}
					insertLabel(label,address);
				}
			return;
			}
		}
	}
	if(pass == 1)
	{
		address += 2;
		return;
	}
	char instruction[50];
	char operand1[50];
	char operand2[50];
	
	int n = sscanf(buffer,"%49s %49[^,], %49s",instruction,operand1,operand2);
	if( strcmp(instruction,"JZ") == 0 || strcmp(instruction,"JNZ") == 0)
	{
		if(n>=3)
		{
			int addr = searchLabel(operand2);
			if(addr == -1)
			{
				printf("ERROR: Invalid Label Name: %s\n",operand2);
				exit(1);
			}
			fprintf(output,"%s %s, %d\n",instruction,operand1,addr);
		}
		else
		{
			fprintf(output,"%s",buffer);
		}
	}
	else if( strcmp(instruction,"JMP") == 0 )
	{
		char labelName[50];
		if( sscanf(buffer," %*s %49s",labelName) == 1)
		{
			int addr = searchLabel(labelName);
			if(addr == -1)
			{
				printf("ERROR: Invalid Label Name: %s\n",labelName);
				exit(1);
			}
			fprintf(output,"JMP %d\n",addr);
		}
	}
	else if( strcmp(instruction,"CALL") == 0 )
	{
		char operand[50];
		if( sscanf(buffer," %*s %49s",operand) == 1)
		{
			if(operand[0] >= '0' && operand[0] <= '9')
			{
				fprintf(output,"CALL %s\n",operand);
			}
			else
			{
				int addr = searchLabel(operand);
				if(addr == -1)
				{
					printf("ERROR: Invalid Label Name: %s\n",operand);
					exit(1);
				}	
				fprintf(output,"CALL %d\n",addr);
			}
		}
	}
	else
	{
		fprintf(output,"%s",buffer);
	}

	address += 2;
}

%}
%%

^.*\n {processLine(yytext);}

%%
int yywrap()
{
	return 1;
}
int main(int argc,char* argv[])
{
	FILE* input;
	if(argc!=3)
	{
		printf("Invalid number of arguments\n");
		return 0;
	}
	input = fopen(argv[1],"r");
	if(input == NULL)
	{
		printf("Error in opening the label file\n");
		return 0;
	}
	yyin = input;
	address = 2056;
	pass = 1;
	yylex();
	fclose(input);
	
	output = fopen(argv[2],"w");
	if(output == NULL)
	{
		printf("Error in creating the final output file\n");
		return 0;
	}
	input = fopen(argv[1],"r");
	yyin = input;
	address = 2056;
	pass = 2;
	yylex();
	fclose(input);
	fclose(output);
}

