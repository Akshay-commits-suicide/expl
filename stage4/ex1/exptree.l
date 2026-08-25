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
"begin" { return TBEGIN; }

"end"	{ return END; }

"read"	{ return READ; }

"write" { return WRITE; }

"if"	{return IF;}

"endif"	{return ENDIF;}

"else"    {return ELSE;}

"then"    {return THEN;}

"while"    {return WHILE;}

"endwhile" {return ENDWHILE;}

"do"    {return DO;}

"repeat" {return REPEAT;}

"untill" {return UNTILL;}

"break" {return BREAK;}

"continue" {return CONTINUE;}

">="    {return GE;}

"<="    {return LE;}

"!="    {return NE;}

"=="    {return EQ;}

"decl" {return DECL;}

"enddecl" {return ENDDECL;}

"int" {return INT;}

"str" {return STR;}


[0-9]+  {number=atoi(yytext);
	yylval.no = makeLeafNode(number);
	return NUM;}

[a-z]+	{yylval.name=strdup(yytext);
	return ID;}
	
\"[^\"]*\" {yylval.no = makeStringNode(yytext);
	   return STRR;}

[ \t \n]	{}

[-+*/();=><\[\]] {return *yytext;}


. {yyerror("Invalid char error\n");
     exit(0);}

%%
int yywrap(void){
	return 1;
}
