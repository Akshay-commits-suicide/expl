%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "exptree.h"
	#include "y.tab.h"
	
	int number;
	int yyerror(char* s);
%}

%%

[0-9]+  {number=atoi(yytext);
	yylval.no = makeLeafNode(number);
	return NUM;}

[ \t]	{}

[-+*/()] {return *yytext;}

[\n] {return END;}

[.] {yyerror("invalid char error\n");
     exit(0);}

%%
int yywrap(void){
	return 1;
}
