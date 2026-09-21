/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 2
#define YYMINOR 0
#define YYPATCH 20240109

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#undef YYBTYACC
#define YYBTYACC 0
#define YYDEBUGSTR YYPREFIX "debug"
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "exptree.y"
	#include <stdio.h>
	#include <stdlib.h>
	#include "exptree.h"
	int yylex(void);
	extern FILE* yyin;
	FILE* fp;
	FILE* intermediate;
	void print(int);
	int currentType = -1;
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 13 "exptree.y"
typedef union YYSTYPE {
	struct tnode* no;
	char* name;
	int type;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 47 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

#if !(defined(yylex) || defined(YYSTATE))
int YYLEX_DECL();
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define NUM 257
#define ID 258
#define STRR 259
#define TBEGIN 260
#define END 261
#define WRITE 262
#define READ 263
#define IF 264
#define THEN 265
#define ELSE 266
#define WHILE 267
#define DO 268
#define ENDIF 269
#define ENDWHILE 270
#define UNTILL 271
#define REPEAT 272
#define BREAK 273
#define CONTINUE 274
#define ENDDECL 275
#define DECL 276
#define INT 277
#define STR 278
#define NE 279
#define EQ 280
#define LE 281
#define GE 282
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,   16,   16,   14,   14,   15,   13,   13,   13,
   13,   13,   13,   17,   17,    1,    1,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    7,    7,    8,   10,
    9,    3,    3,    3,    4,    5,    5,    5,   11,   12,
    6,    6,    6,    6,    6,    6,    6,    6,    6,    6,
    6,    6,    6,    6,    6,    6,    6,
};
static const YYINT yylen[] = {                            2,
    2,    1,    4,    3,    2,    1,    3,    9,    6,    3,
    7,    4,    1,    1,    1,    2,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,   10,    8,    8,    7,
    7,    5,    8,   11,    5,    4,    7,   10,    2,    2,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    1,    1,    7,    4,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,   14,   15,    0,    6,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   17,
   18,   19,   20,   21,   22,   23,   24,   25,   26,    4,
    0,    5,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   39,   40,   16,    3,    0,    7,    0,   53,
    0,   54,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   36,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   52,    0,
    0,    0,    0,    0,    0,    0,    0,   43,   44,   45,
    0,    0,   35,    0,   32,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   37,    0,    0,    0,    0,    0,   31,
   30,   11,    0,    0,    0,    0,   33,    0,   28,   29,
    0,   55,    0,    0,    0,    8,   38,    0,   27,   34,
};
#if defined(YYDESTRUCT_CALL) || defined(YYSTYPE_TOSTRING)
static const YYINT yystos[] = {                           0,
  276,  284,  300,  275,  277,  278,  298,  299,  301,  258,
  262,  263,  264,  267,  268,  272,  273,  274,  285,  286,
  287,  288,  289,  291,  292,  293,  294,  295,  296,   59,
  275,  299,  258,  297,   91,   61,   40,   40,   40,   40,
  285,  285,   59,   59,  286,   59,   91,   59,   44,  257,
  258,  259,   40,  290,  290,  290,  258,  290,  290,  267,
  271,  257,  258,   91,  290,  279,  280,   60,   62,  281,
  282,   43,   45,   42,   47,   37,   93,   59,   41,   91,
   41,   41,   41,   40,   40,   93,   91,  290,   41,  290,
  290,  290,  290,  290,  290,  290,  290,  290,  290,  290,
   91,   61,   59,  290,   59,  265,  268,  290,  290,   91,
  257,   93,  290,  290,   93,  285,  285,   41,   41,  257,
   93,   91,   93,   59,   91,   41,  266,  269,  270,   59,
   59,   93,   91,  290,   61,  290,   59,  285,   59,   59,
  257,   93,  290,   93,  269,   93,   59,   41,   59,   59,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
static const YYINT yydgoto[] = {                          2,
   19,   20,   21,   22,   23,   54,   24,   25,   26,   27,
   28,   29,   34,    7,    8,    3,    9,
};
static const YYINT yysindex[] = {                      -274,
 -251,    0,  318,  -39,    0,    0, -156,    0, -221,  -60,
   14,   15,   21,   22,  318,  318,   23,   26,  318,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   31,    0,   11,  -41,    4,    4,    4, -144,    4,    4,
  331,  258,    0,    0,    0,    0, -137,    0, -131,    0,
   37,    0,    4,   -9,   -2,    5,  -32,   27,   34,   91,
  107,   57,   64,    4,   56,    4,    4,    4,    4,    4,
    4,    4,    4,    4,    4,    4,  -42,    0,   98,    4,
  103, -107, -103,    4,    4,   82,  -90,   63,    0,  164,
  164,  347,  347,  347,  347,   41,   41,    0,    0,    0,
    4,    4,    0,   70,    0,  318,  318,   92,   99,  -82,
   85,   89,  106,  127,  -25,   96,  292,  -45,  125,   95,
  113,    4,  144,    0,    4,  154,  318,  160,  162,    0,
    0,    0,  -35,  134,    4,  148,    0,  305,    0,    0,
  132,    0,  155,  187,  170,    0,    0,  173,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,  239,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  246,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   36,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -37,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   65,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   67,    0,    0,    0,  -20,
   45,  171,  207,  233,  260,  175,  195,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -30,    0,    0,    0,    0,    0,    0,    0,    0,
  101,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
#if YYBTYACC
static const YYINT yycindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
#endif
static const YYINT yygindex[] = {                         0,
   76,  286,    0,    0,    0,  426,    0,    0,    0,    0,
    0,    0,    0,    0,  240,    0,    0,
};
#define YYTABLESIZE 605
static const YYINT yytable[] = {                         57,
   36,    1,   49,   57,   57,   57,   56,   57,   81,   57,
   56,   56,   56,  130,   56,  126,   56,   48,  102,   30,
   48,   57,   57,    4,   57,    5,    6,   76,   56,   56,
   35,   56,   74,   72,   76,   73,   33,   75,   48,   74,
   72,   76,   73,   53,   75,   79,   74,   72,  101,   73,
   68,   75,   69,   37,   38,   57,   78,   68,   80,   69,
   39,   40,   56,   76,   68,  125,   69,   82,   74,   72,
   76,   73,   48,   75,   83,   74,   72,   76,   73,   13,
   75,   43,   74,   77,   44,   49,   68,   75,   69,   46,
   41,   42,   76,   68,   13,   69,   89,   74,   72,   76,
   73,   47,   75,   49,   74,   72,   76,   73,   10,   75,
   12,   74,   72,   57,   73,   68,   75,   69,   31,   62,
    5,    6,   68,   10,   69,   12,   63,   64,   76,   68,
   84,   69,  118,   74,   72,   76,   73,   49,   75,  119,
   74,   72,   76,   73,    9,   75,   85,   74,   72,   86,
   73,   68,   75,   69,   87,  112,  103,  106,   68,    9,
   69,  105,  115,   76,  107,   68,  111,   69,   74,   72,
   76,   73,  110,   75,  120,   74,   72,  121,   73,  122,
   75,  116,  117,  131,   76,  124,   68,  132,   69,   74,
   72,   76,   73,   68,   75,   69,   74,   72,  123,   73,
   76,   75,  138,  133,  135,   74,   72,   68,   73,   69,
   75,   47,  137,  147,   68,   41,   69,   41,  139,   41,
  140,  141,  107,   68,  146,   69,  142,  148,  149,   47,
   47,  150,   47,   41,   41,   42,   41,   42,    2,   42,
  144,   57,   57,   57,   57,    1,   32,   46,   56,   56,
   56,   56,    0,   42,   42,    0,   42,    0,   48,   48,
   50,   51,   52,   47,    0,   46,   46,   41,   46,   66,
   67,   70,   71,   50,    0,    0,   66,   67,   70,   71,
    0,    0,    0,   66,   67,   70,   71,   42,    0,    0,
    0,   50,   50,    0,   50,    0,    0,    0,    0,   46,
   51,    0,    0,    0,   45,   66,   67,   70,   71,    0,
    0,    0,   66,   67,   70,   71,    0,    0,   51,   51,
    0,   51,    0,   49,   49,   50,   45,   45,    0,    0,
    0,    0,    0,    0,   66,   67,   70,   71,    0,    0,
    0,   66,   67,   70,   71,    0,    0,    0,   66,   67,
   70,   71,   51,   10,    0,    0,    0,   11,   12,   13,
    0,  127,   14,   15,  128,    0,    0,   16,   17,   18,
   66,   67,   70,   71,    0,    0,    0,   66,   67,   70,
   71,    0,    0,   76,   66,   67,   70,   71,   74,   72,
    0,   73,    0,   75,    0,    0,    0,    0,    0,    0,
    0,   45,   45,    0,    0,   66,   67,   70,   71,    0,
    0,    0,   66,   67,   70,   71,    0,    0,    0,    0,
    0,    0,    0,   45,    0,    0,   66,   67,   70,   71,
    0,    0,    0,   66,   67,   70,   71,    0,    0,    0,
    0,    0,    0,    0,   70,   71,    0,    0,    0,   47,
   47,   47,   47,   41,   41,   41,   41,    0,    0,    0,
    0,   55,   56,    0,   58,   59,    0,    0,    0,    0,
    0,    0,    0,   42,   42,   42,   42,    0,   65,    0,
    0,    0,    0,    0,    0,   46,   46,   46,   46,   88,
    0,   90,   91,   92,   93,   94,   95,   96,   97,   98,
   99,  100,    0,    0,    0,  104,    0,    0,    0,  108,
  109,   50,   50,   50,   50,   10,    0,    0,    0,   11,
   12,   13,    0,    0,   14,   15,  113,  114,   61,   16,
   17,   18,    0,    0,    0,    0,    0,    0,   51,   51,
   51,   51,    0,    0,    0,    0,    0,  134,    0,   10,
  136,    0,    0,   11,   12,   13,    0,    0,   14,   15,
  143,  129,   10,   16,   17,   18,   11,   12,   13,    0,
    0,   14,   15,  145,    0,   10,   16,   17,   18,   11,
   12,   13,    0,    0,   14,   15,    0,    0,   10,   16,
   17,   18,   11,   12,   13,    0,    0,   60,   15,    0,
    0,    0,   16,   17,   18,
};
static const YYINT yycheck[] = {                         37,
   61,  276,   44,   41,   42,   43,   37,   45,   41,   47,
   41,   42,   43,   59,   45,   41,   47,   59,   61,   59,
   41,   59,   60,  275,   62,  277,  278,   37,   59,   60,
   91,   62,   42,   43,   37,   45,  258,   47,   59,   42,
   43,   37,   45,   40,   47,   41,   42,   43,   91,   45,
   60,   47,   62,   40,   40,   93,   59,   60,   91,   62,
   40,   40,   93,   37,   60,   91,   62,   41,   42,   43,
   37,   45,   93,   47,   41,   42,   43,   37,   45,   44,
   47,   59,   42,   93,   59,   41,   60,   47,   62,   59,
   15,   16,   37,   60,   59,   62,   41,   42,   43,   37,
   45,   91,   47,   59,   42,   43,   37,   45,   44,   47,
   44,   42,   43,  258,   45,   60,   47,   62,  275,  257,
  277,  278,   60,   59,   62,   59,  258,   91,   37,   60,
   40,   62,   41,   42,   43,   37,   45,   93,   47,   41,
   42,   43,   37,   45,   44,   47,   40,   42,   43,   93,
   45,   60,   47,   62,   91,   93,   59,  265,   60,   59,
   62,   59,   93,   37,  268,   60,  257,   62,   42,   43,
   37,   45,   91,   47,  257,   42,   43,   93,   45,   91,
   47,  106,  107,   59,   37,   59,   60,   93,   62,   42,
   43,   37,   45,   60,   47,   62,   42,   43,   93,   45,
   37,   47,  127,   91,   61,   42,   43,   60,   45,   62,
   47,   41,   59,   59,   60,   41,   62,   43,   59,   45,
   59,  257,  268,   60,   93,   62,   93,   41,   59,   59,
   60,   59,   62,   59,   60,   41,   62,   43,    0,   45,
   93,  279,  280,  281,  282,    0,    7,   41,  279,  280,
  281,  282,   -1,   59,   60,   -1,   62,   -1,  279,  280,
  257,  258,  259,   93,   -1,   59,   60,   93,   62,  279,
  280,  281,  282,   41,   -1,   -1,  279,  280,  281,  282,
   -1,   -1,   -1,  279,  280,  281,  282,   93,   -1,   -1,
   -1,   59,   60,   -1,   62,   -1,   -1,   -1,   -1,   93,
   41,   -1,   -1,   -1,   19,  279,  280,  281,  282,   -1,
   -1,   -1,  279,  280,  281,  282,   -1,   -1,   59,   60,
   -1,   62,   -1,  279,  280,   93,   41,   42,   -1,   -1,
   -1,   -1,   -1,   -1,  279,  280,  281,  282,   -1,   -1,
   -1,  279,  280,  281,  282,   -1,   -1,   -1,  279,  280,
  281,  282,   93,  258,   -1,   -1,   -1,  262,  263,  264,
   -1,  266,  267,  268,  269,   -1,   -1,  272,  273,  274,
  279,  280,  281,  282,   -1,   -1,   -1,  279,  280,  281,
  282,   -1,   -1,   37,  279,  280,  281,  282,   42,   43,
   -1,   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  116,  117,   -1,   -1,  279,  280,  281,  282,   -1,
   -1,   -1,  279,  280,  281,  282,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  138,   -1,   -1,  279,  280,  281,  282,
   -1,   -1,   -1,  279,  280,  281,  282,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  281,  282,   -1,   -1,   -1,  279,
  280,  281,  282,  279,  280,  281,  282,   -1,   -1,   -1,
   -1,   36,   37,   -1,   39,   40,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  279,  280,  281,  282,   -1,   53,   -1,
   -1,   -1,   -1,   -1,   -1,  279,  280,  281,  282,   64,
   -1,   66,   67,   68,   69,   70,   71,   72,   73,   74,
   75,   76,   -1,   -1,   -1,   80,   -1,   -1,   -1,   84,
   85,  279,  280,  281,  282,  258,   -1,   -1,   -1,  262,
  263,  264,   -1,   -1,  267,  268,  101,  102,  271,  272,
  273,  274,   -1,   -1,   -1,   -1,   -1,   -1,  279,  280,
  281,  282,   -1,   -1,   -1,   -1,   -1,  122,   -1,  258,
  125,   -1,   -1,  262,  263,  264,   -1,   -1,  267,  268,
  135,  270,  258,  272,  273,  274,  262,  263,  264,   -1,
   -1,  267,  268,  269,   -1,  258,  272,  273,  274,  262,
  263,  264,   -1,   -1,  267,  268,   -1,   -1,  258,  272,
  273,  274,  262,  263,  264,   -1,   -1,  267,  268,   -1,
   -1,   -1,  272,  273,  274,
};
#if YYBTYACC
static const YYINT yyctable[] = {                        -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,
};
#endif
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 282
#define YYUNDFTOKEN 302
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"$end",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'%'",0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,0,
"';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,"error","NUM","ID","STRR","TBEGIN","END","WRITE","READ","IF",
"THEN","ELSE","WHILE","DO","ENDIF","ENDWHILE","UNTILL","REPEAT","BREAK",
"CONTINUE","ENDDECL","DECL","INT","STR","NE","EQ","LE","GE","$accept","program",
"stmtlist","stmt","inputstmt","outputstmt","asgstmt","E","ifstmt","whilestmt",
"dowhilestmt","repeatuntillstmt","breakstmt","continuestmt","varlist",
"decllist","decl","declarations","type","illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : declarations stmtlist",
"program : declarations",
"declarations : DECL decllist ENDDECL ';'",
"declarations : DECL ENDDECL ';'",
"decllist : decllist decl",
"decllist : decl",
"decl : type varlist ';'",
"varlist : varlist ',' ID '[' NUM ']' '[' NUM ']'",
"varlist : varlist ',' ID '[' NUM ']'",
"varlist : varlist ',' ID",
"varlist : ID '[' NUM ']' '[' NUM ']'",
"varlist : ID '[' NUM ']'",
"varlist : ID",
"type : INT",
"type : STR",
"stmtlist : stmtlist stmt",
"stmtlist : stmt",
"stmt : inputstmt",
"stmt : outputstmt",
"stmt : asgstmt",
"stmt : ifstmt",
"stmt : whilestmt",
"stmt : dowhilestmt",
"stmt : repeatuntillstmt",
"stmt : breakstmt",
"stmt : continuestmt",
"ifstmt : IF '(' E ')' THEN stmtlist ELSE stmtlist ENDIF ';'",
"ifstmt : IF '(' E ')' THEN stmtlist ENDIF ';'",
"whilestmt : WHILE '(' E ')' DO stmtlist ENDWHILE ';'",
"repeatuntillstmt : REPEAT stmtlist UNTILL '(' E ')' ';'",
"dowhilestmt : DO stmtlist WHILE '(' E ')' ';'",
"inputstmt : READ '(' ID ')' ';'",
"inputstmt : READ '(' ID '[' E ']' ')' ';'",
"inputstmt : READ '(' ID '[' E ']' '[' E ']' ')' ';'",
"outputstmt : WRITE '(' E ')' ';'",
"asgstmt : ID '=' E ';'",
"asgstmt : ID '[' E ']' '=' E ';'",
"asgstmt : ID '[' E ']' '[' E ']' '=' E ';'",
"breakstmt : BREAK ';'",
"continuestmt : CONTINUE ';'",
"E : E '+' E",
"E : E '-' E",
"E : E '*' E",
"E : E '/' E",
"E : E '%' E",
"E : E '>' E",
"E : E '<' E",
"E : E NE E",
"E : E EQ E",
"E : E LE E",
"E : E GE E",
"E : '(' E ')'",
"E : NUM",
"E : STRR",
"E : ID '[' E ']' '[' E ']'",
"E : ID '[' E ']'",
"E : ID",

};
#endif

#if YYDEBUG
int      yydebug;
#endif

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;
int      yynerrs;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
YYLTYPE  yyloc; /* position returned by actions */
YYLTYPE  yylloc; /* position from the lexer */
#endif

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
#ifndef YYLLOC_DEFAULT
#define YYLLOC_DEFAULT(loc, rhs, n) \
do \
{ \
    if (n == 0) \
    { \
        (loc).first_line   = YYRHSLOC(rhs, 0).last_line; \
        (loc).first_column = YYRHSLOC(rhs, 0).last_column; \
        (loc).last_line    = YYRHSLOC(rhs, 0).last_line; \
        (loc).last_column  = YYRHSLOC(rhs, 0).last_column; \
    } \
    else \
    { \
        (loc).first_line   = YYRHSLOC(rhs, 1).first_line; \
        (loc).first_column = YYRHSLOC(rhs, 1).first_column; \
        (loc).last_line    = YYRHSLOC(rhs, n).last_line; \
        (loc).last_column  = YYRHSLOC(rhs, n).last_column; \
    } \
} while (0)
#endif /* YYLLOC_DEFAULT */
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#if YYBTYACC

#ifndef YYLVQUEUEGROWTH
#define YYLVQUEUEGROWTH 32
#endif
#endif /* YYBTYACC */

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#ifndef YYINITSTACKSIZE
#define YYINITSTACKSIZE 200
#endif

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE  *p_base;
    YYLTYPE  *p_mark;
#endif
} YYSTACKDATA;
#if YYBTYACC

struct YYParseState_s
{
    struct YYParseState_s *save;    /* Previously saved parser state */
    YYSTACKDATA            yystack; /* saved parser stack */
    int                    state;   /* saved parser state */
    int                    errflag; /* saved error recovery status */
    int                    lexeme;  /* saved index of the conflict lexeme in the lexical queue */
    YYINT                  ctry;    /* saved index in yyctable[] for this conflict */
};
typedef struct YYParseState_s YYParseState;
#endif /* YYBTYACC */
/* variables for the parser stack */
static YYSTACKDATA yystack;
#if YYBTYACC

/* Current parser state */
static YYParseState *yyps = 0;

/* yypath != NULL: do the full parse, starting at *yypath parser state. */
static YYParseState *yypath = 0;

/* Base of the lexical value queue */
static YYSTYPE *yylvals = 0;

/* Current position at lexical value queue */
static YYSTYPE *yylvp = 0;

/* End position of lexical value queue */
static YYSTYPE *yylve = 0;

/* The last allocated position at the lexical value queue */
static YYSTYPE *yylvlim = 0;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
/* Base of the lexical position queue */
static YYLTYPE *yylpsns = 0;

/* Current position at lexical position queue */
static YYLTYPE *yylpp = 0;

/* End position of lexical position queue */
static YYLTYPE *yylpe = 0;

/* The last allocated position at the lexical position queue */
static YYLTYPE *yylplim = 0;
#endif

/* Current position at lexical token queue */
static YYINT  *yylexp = 0;

static YYINT  *yylexemes = 0;
#endif /* YYBTYACC */
#line 341 "exptree.y"

int yyerror(char *s){
	printf("yyerror:%s\n",s);
	exit(1);
	return 0;
}
int main(int argc,char *argv[])
{
	if(argc<2)
	{
		printf("No input for filename\n");
		exit(1);
	}
	else
	{
		intermediate = fopen("ex2.xsm","w");
		fprintf(intermediate,"0\n2056\n0\n0\n0\n0\n0\n1\n");
		fprintf(intermediate,"MOV SP, 5000\n");
		fp = fopen(argv[1], "r");
		if(!fp)
		{
			printf("Invalid file specs");
			exit(1);
		}
		else
		{
			yyin=fp;
		}
	}
	yyparse();
	fprintf(intermediate,"INT 10\n");
	return 0;
}
#line 665 "y.tab.c"

/* For use in generated program */
#define yydepth (int)(yystack.s_mark - yystack.s_base)
#if YYBTYACC
#define yytrial (yyps->save)
#endif /* YYBTYACC */

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE *newps;
#endif

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    newps = (YYLTYPE *)realloc(data->p_base, newsize * sizeof(*newps));
    if (newps == 0)
        return YYENOMEM;

    data->p_base = newps;
    data->p_mark = newps + i;
#endif

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;

#if YYDEBUG
    if (yydebug)
        fprintf(stderr, "%sdebug: stack size increased to %d\n", YYPREFIX, newsize);
#endif
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    free(data->p_base);
#endif
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif /* YYPURE || defined(YY_NO_LEAKS) */
#if YYBTYACC

static YYParseState *
yyNewState(unsigned size)
{
    YYParseState *p = (YYParseState *) malloc(sizeof(YYParseState));
    if (p == NULL) return NULL;

    p->yystack.stacksize = size;
    if (size == 0)
    {
        p->yystack.s_base = NULL;
        p->yystack.l_base = NULL;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        p->yystack.p_base = NULL;
#endif
        return p;
    }
    p->yystack.s_base    = (YYINT *) malloc(size * sizeof(YYINT));
    if (p->yystack.s_base == NULL) return NULL;
    p->yystack.l_base    = (YYSTYPE *) malloc(size * sizeof(YYSTYPE));
    if (p->yystack.l_base == NULL) return NULL;
    memset(p->yystack.l_base, 0, size * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    p->yystack.p_base    = (YYLTYPE *) malloc(size * sizeof(YYLTYPE));
    if (p->yystack.p_base == NULL) return NULL;
    memset(p->yystack.p_base, 0, size * sizeof(YYLTYPE));
#endif

    return p;
}

static void
yyFreeState(YYParseState *p)
{
    yyfreestack(&p->yystack);
    free(p);
}
#endif /* YYBTYACC */

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab
#if YYBTYACC
#define YYVALID        do { if (yyps->save)            goto yyvalid; } while(0)
#define YYVALID_NESTED do { if (yyps->save && \
                                yyps->save->save == 0) goto yyvalid; } while(0)
#endif /* YYBTYACC */

int
YYPARSE_DECL()
{
    int yym, yyn, yystate, yyresult;
#if YYBTYACC
    int yynewerrflag;
    YYParseState *yyerrctx = NULL;
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE  yyerror_loc_range[3]; /* position of error start/end (0 unused) */
#endif
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
    if (yydebug)
        fprintf(stderr, "%sdebug[<# of symbols on state stack>]\n", YYPREFIX);
#endif
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    memset(yyerror_loc_range, 0, sizeof(yyerror_loc_range));
#endif

#if YYBTYACC
    yyps = yyNewState(0); if (yyps == 0) goto yyenomem;
    yyps->save = 0;
#endif /* YYBTYACC */
    yym = 0;
    /* yyn is set below */
    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base;
#endif
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
#if YYBTYACC
        do {
        if (yylvp < yylve)
        {
            /* we're currently re-reading tokens */
            yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylloc = *yylpp++;
#endif
            yychar = *yylexp++;
            break;
        }
        if (yyps->save)
        {
            /* in trial mode; save scanner results for future parse attempts */
            if (yylvp == yylvlim)
            {   /* Enlarge lexical value queue */
                size_t p = (size_t) (yylvp - yylvals);
                size_t s = (size_t) (yylvlim - yylvals);

                s += YYLVQUEUEGROWTH;
                if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL) goto yyenomem;
                if ((yylvals   = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL) goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                if ((yylpsns   = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL) goto yyenomem;
#endif
                yylvp   = yylve = yylvals + p;
                yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp   = yylpe = yylpsns + p;
                yylplim = yylpsns + s;
#endif
                yylexp  = yylexemes + p;
            }
            *yylexp = (YYINT) YYLEX;
            *yylvp++ = yylval;
            yylve++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            *yylpp++ = yylloc;
            yylpe++;
#endif
            yychar = *yylexp++;
            break;
        }
        /* normal operation, no conflict encountered */
#endif /* YYBTYACC */
        yychar = YYLEX;
#if YYBTYACC
        } while (0);
#endif /* YYBTYACC */
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)",
                            YYDEBUGSTR, yydepth, yystate, yychar, yys);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
            if (!yytrial)
#endif /* YYBTYACC */
                fprintf(stderr, " <%s>", YYSTYPE_TOSTRING(yychar, yylval));
#endif
            fputc('\n', stderr);
        }
#endif
    }
#if YYBTYACC

    /* Do we have a conflict? */
    if (((yyn = yycindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
        yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        YYINT ctry;

        if (yypath)
        {
            YYParseState *save;
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%s[%d]: CONFLICT in state %d: following successful trial parse\n",
                                YYDEBUGSTR, yydepth, yystate);
#endif
            /* Switch to the next conflict context */
            save = yypath;
            yypath = save->save;
            save->save = NULL;
            ctry = save->ctry;
            if (save->state != yystate) YYABORT;
            yyFreeState(save);

        }
        else
        {

            /* Unresolved conflict - start/continue trial parse */
            YYParseState *save;
#if YYDEBUG
            if (yydebug)
            {
                fprintf(stderr, "%s[%d]: CONFLICT in state %d. ", YYDEBUGSTR, yydepth, yystate);
                if (yyps->save)
                    fputs("ALREADY in conflict, continuing trial parse.\n", stderr);
                else
                    fputs("Starting trial parse.\n", stderr);
            }
#endif
            save                  = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (save == NULL) goto yyenomem;
            save->save            = yyps->save;
            save->state           = yystate;
            save->errflag         = yyerrflag;
            save->yystack.s_mark  = save->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy (save->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            save->yystack.l_mark  = save->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy (save->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            save->yystack.p_mark  = save->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy (save->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            ctry                  = yytable[yyn];
            if (yyctable[ctry] == -1)
            {
#if YYDEBUG
                if (yydebug && yychar >= YYEOF)
                    fprintf(stderr, "%s[%d]: backtracking 1 token\n", YYDEBUGSTR, yydepth);
#endif
                ctry++;
            }
            save->ctry = ctry;
            if (yyps->save == NULL)
            {
                /* If this is a first conflict in the stack, start saving lexemes */
                if (!yylexemes)
                {
                    yylexemes = (YYINT *) malloc((YYLVQUEUEGROWTH) * sizeof(YYINT));
                    if (yylexemes == NULL) goto yyenomem;
                    yylvals   = (YYSTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYSTYPE));
                    if (yylvals == NULL) goto yyenomem;
                    yylvlim   = yylvals + YYLVQUEUEGROWTH;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpsns   = (YYLTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYLTYPE));
                    if (yylpsns == NULL) goto yyenomem;
                    yylplim   = yylpsns + YYLVQUEUEGROWTH;
#endif
                }
                if (yylvp == yylve)
                {
                    yylvp  = yylve = yylvals;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp  = yylpe = yylpsns;
#endif
                    yylexp = yylexemes;
                    if (yychar >= YYEOF)
                    {
                        *yylve++ = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                        *yylpe++ = yylloc;
#endif
                        *yylexp  = (YYINT) yychar;
                        yychar   = YYEMPTY;
                    }
                }
            }
            if (yychar >= YYEOF)
            {
                yylvp--;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp--;
#endif
                yylexp--;
                yychar = YYEMPTY;
            }
            save->lexeme = (int) (yylvp - yylvals);
            yyps->save   = save;
        }
        if (yytable[yyn] == ctry)
        {
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                                YYDEBUGSTR, yydepth, yystate, yyctable[ctry]);
#endif
            if (yychar < 0)
            {
                yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp++;
#endif
                yylexp++;
            }
            if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                goto yyoverflow;
            yystate = yyctable[ctry];
            *++yystack.s_mark = (YYINT) yystate;
            *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            *++yystack.p_mark = yylloc;
#endif
            yychar  = YYEMPTY;
            if (yyerrflag > 0) --yyerrflag;
            goto yyloop;
        }
        else
        {
            yyn = yyctable[ctry];
            goto yyreduce;
        }
    } /* End of code dealing with conflicts */
#endif /* YYBTYACC */
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                            YYDEBUGSTR, yydepth, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        *++yystack.p_mark = yylloc;
#endif
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;
#if YYBTYACC

    yynewerrflag = 1;
    goto yyerrhandler;
    goto yyerrlab; /* redundant goto avoids 'unused label' warning */

yyerrlab:
    /* explicit YYERROR from an action -- pop the rhs of the rule reduced
     * before looking for error recovery */
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark -= yym;
#endif

    yynewerrflag = 0;
yyerrhandler:
    while (yyps->save)
    {
        int ctry;
        YYParseState *save = yyps->save;
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: ERROR in state %d, CONFLICT BACKTRACKING to state %d, %d tokens\n",
                            YYDEBUGSTR, yydepth, yystate, yyps->save->state,
                    (int)(yylvp - yylvals - yyps->save->lexeme));
#endif
        /* Memorize most forward-looking error state in case it's really an error. */
        if (yyerrctx == NULL || yyerrctx->lexeme < yylvp - yylvals)
        {
            /* Free old saved error context state */
            if (yyerrctx) yyFreeState(yyerrctx);
            /* Create and fill out new saved error context state */
            yyerrctx                 = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (yyerrctx == NULL) goto yyenomem;
            yyerrctx->save           = yyps->save;
            yyerrctx->state          = yystate;
            yyerrctx->errflag        = yyerrflag;
            yyerrctx->yystack.s_mark = yyerrctx->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy (yyerrctx->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yyerrctx->yystack.l_mark = yyerrctx->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy (yyerrctx->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yyerrctx->yystack.p_mark = yyerrctx->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy (yyerrctx->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yyerrctx->lexeme         = (int) (yylvp - yylvals);
        }
        yylvp          = yylvals   + save->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yylpp          = yylpsns   + save->lexeme;
#endif
        yylexp         = yylexemes + save->lexeme;
        yychar         = YYEMPTY;
        yystack.s_mark = yystack.s_base + (save->yystack.s_mark - save->yystack.s_base);
        memcpy (yystack.s_base, save->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
        yystack.l_mark = yystack.l_base + (save->yystack.l_mark - save->yystack.l_base);
        memcpy (yystack.l_base, save->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yystack.p_mark = yystack.p_base + (save->yystack.p_mark - save->yystack.p_base);
        memcpy (yystack.p_base, save->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
        ctry           = ++save->ctry;
        yystate        = save->state;
        /* We tried shift, try reduce now */
        if ((yyn = yyctable[ctry]) >= 0) goto yyreduce;
        yyps->save     = save->save;
        save->save     = NULL;
        yyFreeState(save);

        /* Nothing left on the stack -- error */
        if (!yyps->save)
        {
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%sdebug[%d,trial]: trial parse FAILED, entering ERROR mode\n",
                                YYPREFIX, yydepth);
#endif
            /* Restore state as it was in the most forward-advanced error */
            yylvp          = yylvals   + yyerrctx->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylpp          = yylpsns   + yyerrctx->lexeme;
#endif
            yylexp         = yylexemes + yyerrctx->lexeme;
            yychar         = yylexp[-1];
            yylval         = yylvp[-1];
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylloc         = yylpp[-1];
#endif
            yystack.s_mark = yystack.s_base + (yyerrctx->yystack.s_mark - yyerrctx->yystack.s_base);
            memcpy (yystack.s_base, yyerrctx->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yystack.l_mark = yystack.l_base + (yyerrctx->yystack.l_mark - yyerrctx->yystack.l_base);
            memcpy (yystack.l_base, yyerrctx->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yystack.p_mark = yystack.p_base + (yyerrctx->yystack.p_mark - yyerrctx->yystack.p_base);
            memcpy (yystack.p_base, yyerrctx->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yystate        = yyerrctx->state;
            yyFreeState(yyerrctx);
            yyerrctx       = NULL;
        }
        yynewerrflag = 1;
    }
    if (yynewerrflag == 0) goto yyinrecovery;
#endif /* YYBTYACC */

    YYERROR_CALL("syntax error");
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yyerror_loc_range[1] = yylloc; /* lookahead position is error start position */
#endif

#if !YYBTYACC
    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
#endif
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    fprintf(stderr, "%s[%d]: state %d, error recovery shifting to state %d\n",
                                    YYDEBUGSTR, yydepth, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                /* lookahead position is error end position */
                yyerror_loc_range[2] = yylloc;
                YYLLOC_DEFAULT(yyloc, yyerror_loc_range, 2); /* position of error span */
                *++yystack.p_mark = yyloc;
#endif
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    fprintf(stderr, "%s[%d]: error recovery discarding state %d\n",
                                    YYDEBUGSTR, yydepth, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                /* the current TOS position is the error start position */
                yyerror_loc_range[1] = *yystack.p_mark;
#endif
#if defined(YYDESTRUCT_CALL)
#if YYBTYACC
                if (!yytrial)
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    YYDESTRUCT_CALL("error: discarding state",
                                    yystos[*yystack.s_mark], yystack.l_mark, yystack.p_mark);
#else
                    YYDESTRUCT_CALL("error: discarding state",
                                    yystos[*yystack.s_mark], yystack.l_mark);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#endif /* defined(YYDESTRUCT_CALL) */
                --yystack.s_mark;
                --yystack.l_mark;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                --yystack.p_mark;
#endif
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, error recovery discarding token %d (%s)\n",
                            YYDEBUGSTR, yydepth, yystate, yychar, yys);
        }
#endif
#if defined(YYDESTRUCT_CALL)
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            YYDESTRUCT_CALL("error: discarding token", yychar, &yylval, &yylloc);
#else
            YYDESTRUCT_CALL("error: discarding token", yychar, &yylval);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#endif /* defined(YYDESTRUCT_CALL) */
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
    yym = yylen[yyn];
#if YYDEBUG
    if (yydebug)
    {
        fprintf(stderr, "%s[%d]: state %d, reducing by rule %d (%s)",
                        YYDEBUGSTR, yydepth, yystate, yyn, yyrule[yyn]);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
            if (yym > 0)
            {
                int i;
                fputc('<', stderr);
                for (i = yym; i > 0; i--)
                {
                    if (i != yym) fputs(", ", stderr);
                    fputs(YYSTYPE_TOSTRING(yystos[yystack.s_mark[1-i]],
                                           yystack.l_mark[1-i]), stderr);
                }
                fputc('>', stderr);
            }
#endif
        fputc('\n', stderr);
    }
#endif
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)

    /* Perform position reduction */
    memset(&yyloc, 0, sizeof(yyloc));
#if YYBTYACC
    if (!yytrial)
#endif /* YYBTYACC */
    {
        YYLLOC_DEFAULT(yyloc, &yystack.p_mark[-yym], yym);
        /* just in case YYERROR is invoked within the action, save
           the start of the rhs as the error start position */
        yyerror_loc_range[1] = yystack.p_mark[1-yym];
    }
#endif

    switch (yyn)
    {
case 1:
#line 71 "exptree.y"
	{
		yyval.no=yystack.l_mark[0].no;
		evaluate(yystack.l_mark[0].no);
		codegen(yystack.l_mark[0].no);
	}
#line 1342 "y.tab.c"
break;
case 2:
#line 77 "exptree.y"
	{
		yyval.no = NULL;
	}
#line 1349 "y.tab.c"
break;
case 3:
#line 83 "exptree.y"
	{

	     }
#line 1356 "y.tab.c"
break;
case 4:
#line 87 "exptree.y"
	{

	     }
#line 1363 "y.tab.c"
break;
case 5:
#line 92 "exptree.y"
	{

	}
#line 1370 "y.tab.c"
break;
case 6:
#line 96 "exptree.y"
	{

	}
#line 1377 "y.tab.c"
break;
case 7:
#line 101 "exptree.y"
	{

     }
#line 1384 "y.tab.c"
break;
case 8:
#line 107 "exptree.y"
	{
		install(yystack.l_mark[-6].name,currentType,yystack.l_mark[-4].no->val,yystack.l_mark[-1].no->val);
	}
#line 1391 "y.tab.c"
break;
case 9:
#line 111 "exptree.y"
	{
		 install(yystack.l_mark[-3].name,currentType,yystack.l_mark[-1].no->val,0);
	}
#line 1398 "y.tab.c"
break;
case 10:
#line 115 "exptree.y"
	{
		install(yystack.l_mark[0].name,currentType,1,0);
	}
#line 1405 "y.tab.c"
break;
case 11:
#line 119 "exptree.y"
	{
		install(yystack.l_mark[-6].name,currentType,yystack.l_mark[-4].no->val,yystack.l_mark[-1].no->val);
	}
#line 1412 "y.tab.c"
break;
case 12:
#line 123 "exptree.y"
	{
		install(yystack.l_mark[-3].name,currentType,yystack.l_mark[-1].no->val,0);
	}
#line 1419 "y.tab.c"
break;
case 13:
#line 127 "exptree.y"
	{
		install(yystack.l_mark[0].name,currentType,1,0);
	}
#line 1426 "y.tab.c"
break;
case 14:
#line 133 "exptree.y"
	{
	currentType = TYPE_INT;
     }
#line 1433 "y.tab.c"
break;
case 15:
#line 137 "exptree.y"
	{
	currentType = TYPE_STR;
     }
#line 1440 "y.tab.c"
break;
case 16:
#line 142 "exptree.y"
	{
		yyval.no = makeConnectorNode(yystack.l_mark[-1].no,yystack.l_mark[0].no);
	}
#line 1447 "y.tab.c"
break;
case 17:
#line 146 "exptree.y"
	{
		yyval.no = yystack.l_mark[0].no;
	}
#line 1454 "y.tab.c"
break;
case 18:
#line 152 "exptree.y"
	{
		yyval.no = yystack.l_mark[0].no;
	}
#line 1461 "y.tab.c"
break;
case 19:
#line 156 "exptree.y"
	{
		yyval.no = yystack.l_mark[0].no;
	}
#line 1468 "y.tab.c"
break;
case 20:
#line 160 "exptree.y"
	{
		yyval.no = yystack.l_mark[0].no;
	}
#line 1475 "y.tab.c"
break;
case 21:
#line 164 "exptree.y"
	{
		yyval.no = yystack.l_mark[0].no;
	}
#line 1482 "y.tab.c"
break;
case 22:
#line 168 "exptree.y"
	{
		yyval.no = yystack.l_mark[0].no;
	}
#line 1489 "y.tab.c"
break;
case 23:
#line 172 "exptree.y"
	{
		yyval.no = yystack.l_mark[0].no;
	}
#line 1496 "y.tab.c"
break;
case 24:
#line 176 "exptree.y"
	{
		yyval.no = yystack.l_mark[0].no;
	}
#line 1503 "y.tab.c"
break;
case 25:
#line 180 "exptree.y"
	{
		yyval.no = yystack.l_mark[0].no;
	}
#line 1510 "y.tab.c"
break;
case 26:
#line 184 "exptree.y"
	{
		yyval.no = yystack.l_mark[0].no;
	}
#line 1517 "y.tab.c"
break;
case 27:
#line 190 "exptree.y"
	{
		yyval.no = makeTreeNode(NODE_IF,yystack.l_mark[-7].no,yystack.l_mark[-4].no,yystack.l_mark[-2].no);
	}
#line 1524 "y.tab.c"
break;
case 28:
#line 194 "exptree.y"
	{
		yyval.no = makeTreeNode(NODE_IF,yystack.l_mark[-5].no,yystack.l_mark[-2].no,NULL);
	}
#line 1531 "y.tab.c"
break;
case 29:
#line 200 "exptree.y"
	{
		yyval.no = makeTreeNode(NODE_WHILE,yystack.l_mark[-5].no,yystack.l_mark[-2].no,NULL);
	}
#line 1538 "y.tab.c"
break;
case 30:
#line 206 "exptree.y"
	{
			yyval.no = makeTreeNode(NODE_REPEAT,yystack.l_mark[-2].no,yystack.l_mark[-5].no,NULL);
		}
#line 1545 "y.tab.c"
break;
case 31:
#line 212 "exptree.y"
	{
		yyval.no = makeTreeNode(NODE_DOWHILE,yystack.l_mark[-2].no,yystack.l_mark[-5].no,NULL);
	  }
#line 1552 "y.tab.c"
break;
case 32:
#line 218 "exptree.y"
	{
		gsymbol* sym = lookup(yystack.l_mark[-2].name);
		if(sym->size>1 || sym->size1 != 0)
		{
			yyerror("ERROR:Cannot accept array input as a whole.Use arr[i] to take input!");
		}
		yyval.no = makeReadNode(yystack.l_mark[-2].name);
	}
#line 1564 "y.tab.c"
break;
case 33:
#line 227 "exptree.y"
	{
		yyval.no = makeReadArrayNode(yystack.l_mark[-5].name,yystack.l_mark[-3].no);
	}
#line 1571 "y.tab.c"
break;
case 34:
#line 231 "exptree.y"
	{
		yyval.no = makeRead2DArrayNode(yystack.l_mark[-8].name,yystack.l_mark[-6].no,yystack.l_mark[-3].no);
	}
#line 1578 "y.tab.c"
break;
case 35:
#line 237 "exptree.y"
	{
		yyval.no = makeWriteNode(yystack.l_mark[-2].no);
	}
#line 1585 "y.tab.c"
break;
case 36:
#line 244 "exptree.y"
	{
		yyval.no = makeAssignmentNode(yystack.l_mark[-3].name,yystack.l_mark[-1].no);
	}
#line 1592 "y.tab.c"
break;
case 37:
#line 248 "exptree.y"
	{
		yyval.no = makeAssignmentArrayNode(yystack.l_mark[-6].name,yystack.l_mark[-4].no,yystack.l_mark[-1].no);
	}
#line 1599 "y.tab.c"
break;
case 38:
#line 252 "exptree.y"
	{
		yyval.no = makeAssignment2DArrayNode(yystack.l_mark[-9].name,yystack.l_mark[-7].no,yystack.l_mark[-4].no,yystack.l_mark[-1].no);
	}
#line 1606 "y.tab.c"
break;
case 39:
#line 258 "exptree.y"
	{
		yyval.no = makeBreakNode();
	}
#line 1613 "y.tab.c"
break;
case 40:
#line 264 "exptree.y"
	{
		yyval.no = makeContinueNode();
	}
#line 1620 "y.tab.c"
break;
case 41:
#line 271 "exptree.y"
	{
        yyval.no = makeOperatorNode('+', yystack.l_mark[-2].no, yystack.l_mark[0].no);
    }
#line 1627 "y.tab.c"
break;
case 42:
#line 275 "exptree.y"
	{
        yyval.no = makeOperatorNode('-', yystack.l_mark[-2].no, yystack.l_mark[0].no);
    }
#line 1634 "y.tab.c"
break;
case 43:
#line 279 "exptree.y"
	{
        yyval.no = makeOperatorNode('*', yystack.l_mark[-2].no, yystack.l_mark[0].no);
    }
#line 1641 "y.tab.c"
break;
case 44:
#line 283 "exptree.y"
	{
        yyval.no = makeOperatorNode('/', yystack.l_mark[-2].no, yystack.l_mark[0].no);
    }
#line 1648 "y.tab.c"
break;
case 45:
#line 287 "exptree.y"
	{
        yyval.no = makeOperatorNode('%', yystack.l_mark[-2].no, yystack.l_mark[0].no);
    }
#line 1655 "y.tab.c"
break;
case 46:
#line 291 "exptree.y"
	{
        yyval.no = makeOperatorNode('>', yystack.l_mark[-2].no, yystack.l_mark[0].no);
    }
#line 1662 "y.tab.c"
break;
case 47:
#line 295 "exptree.y"
	{
        yyval.no = makeOperatorNode('<', yystack.l_mark[-2].no, yystack.l_mark[0].no);
    }
#line 1669 "y.tab.c"
break;
case 48:
#line 299 "exptree.y"
	{
        yyval.no = makeOperatorNode('n', yystack.l_mark[-2].no, yystack.l_mark[0].no);
    }
#line 1676 "y.tab.c"
break;
case 49:
#line 303 "exptree.y"
	{
        yyval.no = makeOperatorNode('e', yystack.l_mark[-2].no, yystack.l_mark[0].no);
    }
#line 1683 "y.tab.c"
break;
case 50:
#line 307 "exptree.y"
	{
        yyval.no = makeOperatorNode('l', yystack.l_mark[-2].no, yystack.l_mark[0].no);
    }
#line 1690 "y.tab.c"
break;
case 51:
#line 311 "exptree.y"
	{
        yyval.no = makeOperatorNode('g', yystack.l_mark[-2].no, yystack.l_mark[0].no);
    }
#line 1697 "y.tab.c"
break;
case 52:
#line 315 "exptree.y"
	{
        yyval.no = yystack.l_mark[-1].no;
    }
#line 1704 "y.tab.c"
break;
case 53:
#line 319 "exptree.y"
	{
        yyval.no = yystack.l_mark[0].no;
    }
#line 1711 "y.tab.c"
break;
case 54:
#line 323 "exptree.y"
	{
	yyval.no =yystack.l_mark[0].no;
  }
#line 1718 "y.tab.c"
break;
case 55:
#line 327 "exptree.y"
	{
			yyval.no = make2DArrayNode(yystack.l_mark[-6].name,yystack.l_mark[-4].no,yystack.l_mark[-1].no);
	}
#line 1725 "y.tab.c"
break;
case 56:
#line 331 "exptree.y"
	{
		yyval.no = makeArrayNode(yystack.l_mark[-3].name,yystack.l_mark[-1].no);
  }
#line 1732 "y.tab.c"
break;
case 57:
#line 335 "exptree.y"
	{
		yyval.no = makeVariableNode(yystack.l_mark[0].name);
  }
#line 1739 "y.tab.c"
break;
#line 1741 "y.tab.c"
    default:
        break;
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark -= yym;
#endif
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
        {
            fprintf(stderr, "%s[%d]: after reduction, ", YYDEBUGSTR, yydepth);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
            if (!yytrial)
#endif /* YYBTYACC */
                fprintf(stderr, "result is <%s>, ", YYSTYPE_TOSTRING(yystos[YYFINAL], yyval));
#endif
            fprintf(stderr, "shifting from state 0 to final state %d\n", YYFINAL);
        }
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        *++yystack.p_mark = yyloc;
#endif
        if (yychar < 0)
        {
#if YYBTYACC
            do {
            if (yylvp < yylve)
            {
                /* we're currently re-reading tokens */
                yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylloc = *yylpp++;
#endif
                yychar = *yylexp++;
                break;
            }
            if (yyps->save)
            {
                /* in trial mode; save scanner results for future parse attempts */
                if (yylvp == yylvlim)
                {   /* Enlarge lexical value queue */
                    size_t p = (size_t) (yylvp - yylvals);
                    size_t s = (size_t) (yylvlim - yylvals);

                    s += YYLVQUEUEGROWTH;
                    if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL)
                        goto yyenomem;
                    if ((yylvals   = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL)
                        goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    if ((yylpsns   = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL)
                        goto yyenomem;
#endif
                    yylvp   = yylve = yylvals + p;
                    yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp   = yylpe = yylpsns + p;
                    yylplim = yylpsns + s;
#endif
                    yylexp  = yylexemes + p;
                }
                *yylexp = (YYINT) YYLEX;
                *yylvp++ = yylval;
                yylve++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                *yylpp++ = yylloc;
                yylpe++;
#endif
                yychar = *yylexp++;
                break;
            }
            /* normal operation, no conflict encountered */
#endif /* YYBTYACC */
            yychar = YYLEX;
#if YYBTYACC
            } while (0);
#endif /* YYBTYACC */
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)\n",
                                YYDEBUGSTR, yydepth, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
    {
        fprintf(stderr, "%s[%d]: after reduction, ", YYDEBUGSTR, yydepth);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
            fprintf(stderr, "result is <%s>, ", YYSTYPE_TOSTRING(yystos[yystate], yyval));
#endif
        fprintf(stderr, "shifting from state %d to state %d\n", *yystack.s_mark, yystate);
    }
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    *++yystack.p_mark = yyloc;
#endif
    goto yyloop;
#if YYBTYACC

    /* Reduction declares that this path is valid. Set yypath and do a full parse */
yyvalid:
    if (yypath) YYABORT;
    while (yyps->save)
    {
        YYParseState *save = yyps->save;
        yyps->save = save->save;
        save->save = yypath;
        yypath = save;
    }
#if YYDEBUG
    if (yydebug)
        fprintf(stderr, "%s[%d]: state %d, CONFLICT trial successful, backtracking to state %d, %d tokens\n",
                        YYDEBUGSTR, yydepth, yystate, yypath->state, (int)(yylvp - yylvals - yypath->lexeme));
#endif
    if (yyerrctx)
    {
        yyFreeState(yyerrctx);
        yyerrctx = NULL;
    }
    yylvp          = yylvals + yypath->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yylpp          = yylpsns + yypath->lexeme;
#endif
    yylexp         = yylexemes + yypath->lexeme;
    yychar         = YYEMPTY;
    yystack.s_mark = yystack.s_base + (yypath->yystack.s_mark - yypath->yystack.s_base);
    memcpy (yystack.s_base, yypath->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
    yystack.l_mark = yystack.l_base + (yypath->yystack.l_mark - yypath->yystack.l_base);
    memcpy (yystack.l_base, yypath->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base + (yypath->yystack.p_mark - yypath->yystack.p_base);
    memcpy (yystack.p_base, yypath->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
    yystate        = yypath->state;
    goto yyloop;
#endif /* YYBTYACC */

yyoverflow:
    YYERROR_CALL("yacc stack overflow");
#if YYBTYACC
    goto yyabort_nomem;
yyenomem:
    YYERROR_CALL("memory exhausted");
yyabort_nomem:
#endif /* YYBTYACC */
    yyresult = 2;
    goto yyreturn;

yyabort:
    yyresult = 1;
    goto yyreturn;

yyaccept:
#if YYBTYACC
    if (yyps->save) goto yyvalid;
#endif /* YYBTYACC */
    yyresult = 0;

yyreturn:
#if defined(YYDESTRUCT_CALL)
    if (yychar != YYEOF && yychar != YYEMPTY)
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        YYDESTRUCT_CALL("cleanup: discarding token", yychar, &yylval, &yylloc);
#else
        YYDESTRUCT_CALL("cleanup: discarding token", yychar, &yylval);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */

    {
        YYSTYPE *pv;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        YYLTYPE *pp;

        for (pv = yystack.l_base, pp = yystack.p_base; pv <= yystack.l_mark; ++pv, ++pp)
             YYDESTRUCT_CALL("cleanup: discarding state",
                             yystos[*(yystack.s_base + (pv - yystack.l_base))], pv, pp);
#else
        for (pv = yystack.l_base; pv <= yystack.l_mark; ++pv)
             YYDESTRUCT_CALL("cleanup: discarding state",
                             yystos[*(yystack.s_base + (pv - yystack.l_base))], pv);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
    }
#endif /* defined(YYDESTRUCT_CALL) */

#if YYBTYACC
    if (yyerrctx)
    {
        yyFreeState(yyerrctx);
        yyerrctx = NULL;
    }
    while (yyps)
    {
        YYParseState *save = yyps;
        yyps = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
    while (yypath)
    {
        YYParseState *save = yypath;
        yypath = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
#endif /* YYBTYACC */
    yyfreestack(&yystack);
    return (yyresult);
}
