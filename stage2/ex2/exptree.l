%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "exptree.h"
	#include "y.tab.h"
	
	int number;
	int yyerror(char* s);
%}

%%
"begin" { return BEGIN; }

"end"	{ return END; }

"read"	{ return READ; }

"write" { return WRITE; }

[0-9]+  {number=atoi(yytext);
	yylval.no = makeLeafNode(number);
	return NUM;}

[a-z]	{yylval.name=strdup(yytext);
	return ID;}

[ \t]	{}

[-+*/();=] {return *yytext;}

	
[.] {yyerror("Invalid char error\n");
     exit(0);}

%%
int yywrap(void){
	return 1;
}
