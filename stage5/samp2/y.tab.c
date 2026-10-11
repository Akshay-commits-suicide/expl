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
	int currentType = -1;
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 12 "exptree.y"
typedef union YYSTYPE {
	struct tnode* no;
	char* name;
	int type;
	Param* param;
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
#define RETURN 262
#define WRITE 263
#define READ 264
#define IF 265
#define THEN 266
#define ELSE 267
#define WHILE 268
#define DO 269
#define ENDIF 270
#define ENDWHILE 271
#define UNTILL 272
#define REPEAT 273
#define BREAK 274
#define CONTINUE 275
#define ENDDECL 276
#define DECL 277
#define INT 278
#define STR 279
#define NE 280
#define EQ 281
#define LE 282
#define GE 283
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,   14,   14,   27,   13,   16,   16,   16,   17,
   21,   21,   19,   19,   20,   20,   18,   18,   18,   18,
   18,   18,   18,   18,   24,   24,   24,   26,   26,   23,
   23,   22,   28,   28,   28,   28,   28,   28,   28,   28,
   25,   25,    1,    1,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    7,    7,    8,   10,    9,    3,
    3,    3,    3,    4,    5,    5,    5,    5,   11,   12,
    6,    6,    6,    6,    6,    6,    6,    6,    6,    6,
    6,    6,    6,    6,    6,    6,    6,    6,    6,    6,
   15,   15,   15,
};
static const YYINT yylen[] = {                            2,
    2,    1,    2,    0,    0,   13,    3,    1,    0,    2,
    4,    3,    2,    1,    3,    6,    9,    6,    4,    3,
    7,    4,    2,    1,    4,    3,    0,    1,    0,    2,
    1,    3,    9,    6,    4,    3,    7,    4,    2,    1,
    1,    1,    2,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    3,   10,    8,    8,    7,    7,    5,
    6,    8,   11,    5,    4,    5,    7,   10,    2,    2,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    1,    1,    7,    4,    2,    2,    1,    4,
    0,    1,    3,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    4,    0,   41,   42,    0,   14,    0,
    3,    0,    0,   28,   12,    0,   13,    0,    0,    0,
    0,   11,    0,    0,   23,    0,   15,    0,    0,    8,
    0,    0,    0,    0,    0,    0,    0,   10,    0,    0,
   19,    0,   16,    7,    0,    0,    5,    0,    0,    0,
   21,    0,    0,    0,    0,    0,   31,    0,    0,    0,
   17,   26,    0,   30,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   44,
   45,   46,   47,   48,   49,   50,   51,   52,   53,   25,
    0,   39,    0,   32,    0,    0,   83,    0,   84,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   69,
   70,    0,    0,   43,    0,    0,    0,    0,    0,    0,
    0,   87,    0,   88,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   54,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   35,    0,   65,
    0,    0,    0,   82,    0,    0,    0,    0,    0,    0,
    0,    0,   73,   74,   75,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    6,    0,    0,    0,    0,   90,
    0,    0,   64,   60,    0,    0,    0,    0,    0,    0,
   66,    0,    0,    0,    0,    0,    0,    0,   61,    0,
    0,    0,    0,   37,    0,    0,   67,    0,    0,    0,
    0,    0,    0,   59,   58,    0,    0,   85,   62,    0,
    0,   56,   57,   33,    0,    0,    0,   68,    0,   55,
   63,
};
#if defined(YYDESTRUCT_CALL) || defined(YYSTYPE_TOSTRING)
static const YYINT yystos[] = {                           0,
  277,  285,  299,  306,  276,  278,  279,  304,  305,  310,
  298,  310,  299,   59,  311,  276,  305,  258,   42,  303,
  258,  311,   40,   91,  258,   44,   59,   40,  301,  302,
  310,  257,  258,   42,  301,   41,   44,  258,   93,   91,
  258,   41,   59,  302,   91,  257,  123,  257,   93,  312,
   93,   91,  277,  309,  257,  276,  307,  308,  310,  260,
   93,  311,  276,  307,  258,   42,  313,  258,  262,  263,
  264,  265,  268,  269,  273,  274,  275,   42,  286,  287,
  288,  289,  290,  292,  293,  294,  295,  296,  297,  311,
   91,  258,   44,   59,   91,   61,  257,  258,  259,   42,
   40,   38,  291,   40,   40,   40,   40,  286,  286,   59,
   59,  258,  261,  287,  257,  258,   42,  291,  291,   40,
   91,  258,  291,  258,  280,  281,   60,   62,  282,  283,
   43,   45,   42,   47,   37,   59,  291,  258,   42,  291,
  291,  268,  272,   61,  311,   93,   91,  258,   93,   59,
  291,  300,  291,   41,  291,  291,  291,  291,  291,  291,
  291,  291,  291,  291,  291,   41,   41,   91,  258,   41,
   41,   40,   40,  291,  125,   91,  257,   91,   61,   41,
   44,   93,   59,   59,  291,   41,  266,  269,  291,  291,
   59,  257,   93,  291,  291,  291,   91,   93,   59,  286,
  286,   41,   41,   93,   91,   93,   59,  291,   41,   91,
  267,  270,  271,   59,   59,  257,   61,   93,   59,  291,
  286,   59,   59,   93,  291,   93,  270,   59,   41,   59,
   59,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
static const YYINT yydgoto[] = {                          2,
   79,   80,   81,   82,   83,  103,   84,   85,   86,   87,
   88,   89,   11,    3,  152,   29,   30,   20,    8,    9,
    4,   57,   58,   54,   31,   15,   50,   67,
};
static const YYINT yysindex[] = {                      -275,
  108,    0, -135,    0,  -15,    0,    0,  150,    0,  -31,
    0, -208, -135,    0,    0,  -15,    0,   -3, -198,   37,
   42,    0, -135, -171,    0,  -30,    0, -135,   13,    0,
 -167,    5,   20, -109,  139,   95, -135,    0,   70,  -91,
    0,   56,    0,    0,  -67,  111,    0,  116,  138,  -64,
    0,  -40,  173,  -25,  166,  -15,    0,  265,   19,  322,
    0,    0,  -15,    0,  170,   10,   45,  -43,  377,  201,
  229,  232,  238,  322,  322,  231,  233,   39,  246,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   43,    0,   36,    0,  377,  377,    0,   -1,    0,   51,
  377,   53,   -7,  377,   38,  377,  377,  336,  260,    0,
    0,  261,  -15,    0,  243,  230,   85,    4,   25,  377,
  377,    0,   32,    0,  377,  377,  377,  377,  377,  377,
  377,  377,  377,  377,  377,    0,   58,  -20,   98,   65,
   72,  297,  311,  377,  240,  272,  101,    0,    2,    0,
  282,  276,   79,    0,  346,  346,  578,  578,  578,  578,
  100,  100,    0,    0,    0,  312,  320,  377,  340,  119,
  121,  377,  377,   86,    0,  135,  301,  377,  377,    0,
  377,  309,    0,    0,   93,  342,  322,  322,  115,  122,
    0,  306,  318,  131,  152,  282,  377,   -8,    0,  228,
  284,  -39,  357,    0,  161,  359,    0,  163,  371,  377,
  322,  372,  382,    0,    0,  343,  377,    0,    0,  256,
  308,    0,    0,    0,  189,  407,  398,    0,  403,    0,
    0,
};
static const YYINT yyrindex[] = {                         1,
    0,    0,  463,    0,    3,    0,    0,    0,    0,    0,
    0,    0,  474,    0,    0,    3,    0,  126,    0,    0,
    0,    0,  287,    0,    0,    0,    0,  287,    0,    0,
    0,    0,  137,    0,    0,    0,    0,    0,  143,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  144,  215,
    0,    0,    0,    0,    0,  216,    0,    0,    0,    0,
    0,    0,  216,    0,  148,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -37,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  352,    0,    0,  203,    0,    0,    0,  291,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  245,    0,    0,    0,    0,
  366,    0,    0,    0,  157,  174,  178,  198,  406,  423,
  -17,  380,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -28,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  251,    0,    0,  412,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,
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
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,
};
#endif
static const YYINT yygindex[] = {                         0,
  146,  -50,    0,    0,    0,  512,    0,    0,    0,    0,
    0,    0,    0,  480,    0,  459,  451,    0,    0,  481,
    0,  436,    0,    0,  369,  267,    0,    0,
};
#define YYTABLESIZE 729
static const YYINT yytable[] = {                         89,
    4,    1,   29,   89,   89,   89,   89,   89,   86,   89,
   19,   34,   86,   86,   86,   86,   86,   96,   86,  214,
  167,   89,   89,   71,   89,   71,   71,   71,  114,  135,
   86,   86,  209,   86,  133,  131,   23,  132,  120,  134,
  135,   71,   71,   14,   71,  133,  131,   95,  132,   21,
  134,  136,  127,   36,  128,   89,   37,  114,  114,   25,
   66,  135,  179,  127,   86,  128,  133,  131,  135,  132,
  168,  134,  154,  133,  131,   71,  132,  117,  134,  139,
   26,   28,  210,  150,  127,   32,  128,   24,   93,  121,
   38,  127,  178,  128,  135,   27,  149,   39,  166,  133,
  131,  135,  132,   94,  134,  170,  133,  131,  135,  132,
   40,  134,  171,  133,  131,  135,  132,  127,  134,  128,
  133,  131,  135,  132,  127,  134,  128,  133,  131,  135,
  132,  127,  134,  128,  133,  131,  135,  132,  127,  134,
  128,  133,    6,    7,  191,  127,  134,  128,   41,  114,
  114,  135,  127,   43,  128,  202,  133,  131,  135,  132,
   45,  134,  203,  133,  131,   46,  132,  135,  134,   24,
  114,  182,  133,  131,  127,  132,  128,  134,   47,   42,
   20,  127,   37,  128,   24,  198,   22,   18,  135,   48,
  127,   40,  128,  133,  131,   20,  132,   78,  134,  135,
   78,   22,   18,   49,  133,  131,   40,  132,   51,  134,
  207,  127,   53,  128,   79,   78,   55,   79,   77,  108,
  109,   77,  127,  206,  128,  135,   18,   33,   52,  188,
  133,  131,   79,  132,   60,  134,   77,   77,   76,   77,
  104,   76,   89,   89,   89,   89,   36,  228,  127,   78,
  128,   86,   86,   86,   86,  218,   76,   76,   61,   76,
   91,   36,   71,   71,   71,   71,   79,   92,  105,   78,
   77,  106,  125,  126,  129,  130,   65,  107,    4,    4,
   29,   29,   22,  125,  126,  129,  130,   78,   38,  110,
   76,  111,  135,  116,   34,  138,  112,  133,  131,  115,
  132,   78,  134,   38,  125,  126,  129,  130,  122,   34,
  124,  125,  126,  129,  130,  127,  180,  128,  135,  181,
  147,  144,   62,  133,  131,   78,  132,    9,  134,   90,
    9,   91,  200,  201,   91,  146,  172,  125,  126,  129,
  130,  127,  148,  128,  125,  126,  129,  130,  226,   78,
  173,  125,  126,  129,  130,  169,  221,  177,  125,  126,
  129,  130,  176,   78,  175,  125,  126,  129,  130,   10,
  183,   12,  125,  126,  129,  130,   10,   78,  184,  145,
  186,   12,  135,    5,  187,    6,    7,  133,  131,  188,
  132,  192,  134,  193,  125,  126,  129,  130,  204,  197,
  199,  125,  126,  129,  130,  127,   92,  128,  205,   92,
  125,  126,  129,  130,  102,  215,  101,  216,  100,  217,
   72,   59,   72,   72,   72,   16,   59,    6,    7,  219,
  222,  125,  126,  129,  130,  224,   78,   78,   72,   72,
  223,   72,  125,  126,  129,  130,   80,  229,   56,   80,
    6,    7,   93,   79,   79,   93,  230,   77,   77,   77,
   77,  231,    2,   81,   80,   80,   81,   80,  125,  126,
  129,  130,   72,    1,   27,   29,   29,   76,   76,   76,
   76,   81,   81,   13,   81,   68,   35,   44,   17,   69,
   70,   71,   72,   64,  211,   73,   74,  212,   80,    0,
   75,   76,   77,   68,    0,    0,  113,   69,   70,   71,
   72,    0,    0,   73,   74,   81,    0,   68,   75,   76,
   77,   69,   70,   71,   72,    0,    0,   73,   74,    0,
    0,  143,   75,   76,   77,  125,  126,  129,  130,    0,
   63,   68,    6,    7,    0,   69,   70,   71,   72,    0,
    0,   73,   74,    0,  213,    0,   75,   76,   77,    0,
    0,  125,  126,  129,  130,   68,    0,    0,    0,   69,
   70,   71,   72,    0,    0,   73,   74,  227,    0,   68,
   75,   76,   77,   69,   70,   71,   72,    0,    0,   73,
   74,    0,    0,   68,   75,   76,   77,   69,   70,   71,
   72,    0,    0,  142,   74,    0,  118,  119,   75,   76,
   77,    0,  123,    0,  135,  137,    0,  140,  141,  133,
  131,    0,  132,    0,  134,    0,    0,  129,  130,    0,
    0,  151,  153,   97,   98,   99,  155,  156,  157,  158,
  159,  160,  161,  162,  163,  164,  165,    0,    0,    0,
    0,    0,    0,    0,    0,  174,    0,    0,    0,   72,
   72,   72,   72,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  185,
    0,    0,    0,  189,  190,   80,   80,   80,   80,  194,
  195,    0,  196,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   81,   81,   81,   81,    0,    0,  208,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  220,    0,    0,    0,    0,    0,    0,  225,
};
static const YYINT yycheck[] = {                         37,
    0,  277,    0,   41,   42,   43,   44,   45,   37,   47,
   42,   42,   41,   42,   43,   44,   45,   61,   47,   59,
   41,   59,   60,   41,   62,   43,   44,   45,   79,   37,
   59,   60,   41,   62,   42,   43,   40,   45,   40,   47,
   37,   59,   60,   59,   62,   42,   43,   91,   45,  258,
   47,   59,   60,   41,   62,   93,   44,  108,  109,  258,
   42,   37,   61,   60,   93,   62,   42,   43,   37,   45,
   91,   47,   41,   42,   43,   93,   45,   42,   47,   42,
   44,   40,   91,   59,   60,  257,   62,   91,   44,   91,
  258,   60,   91,   62,   37,   59,   93,   93,   41,   42,
   43,   37,   45,   59,   47,   41,   42,   43,   37,   45,
   91,   47,   41,   42,   43,   37,   45,   60,   47,   62,
   42,   43,   37,   45,   60,   47,   62,   42,   43,   37,
   45,   60,   47,   62,   42,   43,   37,   45,   60,   47,
   62,   42,  278,  279,   59,   60,   47,   62,  258,  200,
  201,   37,   60,   59,   62,   41,   42,   43,   37,   45,
   91,   47,   41,   42,   43,  257,   45,   37,   47,   44,
  221,   93,   42,   43,   60,   45,   62,   47,  123,   41,
   44,   60,   44,   62,   59,   93,   44,   44,   37,  257,
   60,   44,   62,   42,   43,   59,   45,   41,   47,   37,
   44,   59,   59,   93,   42,   43,   59,   45,   93,   47,
   59,   60,  277,   62,   41,   59,  257,   44,   41,   74,
   75,   44,   60,   93,   62,   37,  258,  258,   91,  269,
   42,   43,   59,   45,  260,   47,   59,   60,   41,   62,
   40,   44,  280,  281,  282,  283,   44,   59,   60,   93,
   62,  280,  281,  282,  283,   93,   59,   60,   93,   62,
   91,   59,  280,  281,  282,  283,   93,  258,   40,   42,
   93,   40,  280,  281,  282,  283,  258,   40,  278,  279,
  278,  279,   16,  280,  281,  282,  283,   42,   44,   59,
   93,   59,   37,  258,   44,  258,  258,   42,   43,  257,
   45,   42,   47,   59,  280,  281,  282,  283,  258,   59,
  258,  280,  281,  282,  283,   60,   41,   62,   37,   44,
   91,   61,   56,   42,   43,   42,   45,   41,   47,   63,
   44,   41,  187,  188,   44,   93,   40,  280,  281,  282,
  283,   60,  258,   62,  280,  281,  282,  283,   93,   42,
   40,  280,  281,  282,  283,  258,  211,  257,  280,  281,
  282,  283,   91,   42,  125,  280,  281,  282,  283,    1,
   59,    3,  280,  281,  282,  283,    8,   42,   59,  113,
   41,   13,   37,  276,  266,  278,  279,   42,   43,  269,
   45,  257,   47,   93,  280,  281,  282,  283,   93,   91,
   59,  280,  281,  282,  283,   60,   41,   62,   91,   44,
  280,  281,  282,  283,   38,   59,   40,  257,   42,   61,
   41,   53,   43,   44,   45,  276,   58,  278,  279,   59,
   59,  280,  281,  282,  283,   93,  280,  281,   59,   60,
   59,   62,  280,  281,  282,  283,   41,   41,  276,   44,
  278,  279,   41,  280,  281,   44,   59,  280,  281,  282,
  283,   59,    0,   41,   59,   60,   44,   62,  280,  281,
  282,  283,   93,    0,  260,  260,  125,  280,  281,  282,
  283,   59,   60,    4,   62,  258,   28,   37,    8,  262,
  263,  264,  265,   58,  267,  268,  269,  270,   93,   -1,
  273,  274,  275,  258,   -1,   -1,  261,  262,  263,  264,
  265,   -1,   -1,  268,  269,   93,   -1,  258,  273,  274,
  275,  262,  263,  264,  265,   -1,   -1,  268,  269,   -1,
   -1,  272,  273,  274,  275,  280,  281,  282,  283,   -1,
  276,  258,  278,  279,   -1,  262,  263,  264,  265,   -1,
   -1,  268,  269,   -1,  271,   -1,  273,  274,  275,   -1,
   -1,  280,  281,  282,  283,  258,   -1,   -1,   -1,  262,
  263,  264,  265,   -1,   -1,  268,  269,  270,   -1,  258,
  273,  274,  275,  262,  263,  264,  265,   -1,   -1,  268,
  269,   -1,   -1,  258,  273,  274,  275,  262,  263,  264,
  265,   -1,   -1,  268,  269,   -1,   95,   96,  273,  274,
  275,   -1,  101,   -1,   37,  104,   -1,  106,  107,   42,
   43,   -1,   45,   -1,   47,   -1,   -1,  282,  283,   -1,
   -1,  120,  121,  257,  258,  259,  125,  126,  127,  128,
  129,  130,  131,  132,  133,  134,  135,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  144,   -1,   -1,   -1,  280,
  281,  282,  283,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  168,
   -1,   -1,   -1,  172,  173,  280,  281,  282,  283,  178,
  179,   -1,  181,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  280,  281,  282,  283,   -1,   -1,  197,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  210,   -1,   -1,   -1,   -1,   -1,   -1,  217,
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
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
};
#endif
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 283
#define YYUNDFTOKEN 314
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"$end",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'%'","'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,0,
"';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,
"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,"error","NUM","ID","STRR","TBEGIN","END","RETURN",
"WRITE","READ","IF","THEN","ELSE","WHILE","DO","ENDIF","ENDWHILE","UNTILL",
"REPEAT","BREAK","CONTINUE","ENDDECL","DECL","INT","STR","NE","EQ","LE","GE",
"$accept","program","stmtlist","stmt","inputstmt","outputstmt","asgstmt","E",
"ifstmt","whilestmt","dowhilestmt","repeatuntillstmt","breakstmt",
"continuestmt","function","functionlist","arglist","paramlist","param",
"varlist","decllist","decl","declarations","localdecl","localdecllist",
"localdeclarations","type","optsemi","$$1","localvarlist","illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : declarations functionlist",
"program : functionlist",
"functionlist : functionlist function",
"functionlist :",
"$$1 :",
"function : type ID '(' paramlist ')' '{' $$1 localdeclarations TBEGIN stmtlist END optsemi '}'",
"paramlist : paramlist ',' param",
"paramlist : param",
"paramlist :",
"param : type ID",
"declarations : DECL decllist ENDDECL optsemi",
"declarations : DECL ENDDECL optsemi",
"decllist : decllist decl",
"decllist : decl",
"decl : type varlist ';'",
"decl : type ID '(' paramlist ')' ';'",
"varlist : varlist ',' ID '[' NUM ']' '[' NUM ']'",
"varlist : varlist ',' ID '[' NUM ']'",
"varlist : varlist ',' '*' ID",
"varlist : varlist ',' ID",
"varlist : ID '[' NUM ']' '[' NUM ']'",
"varlist : ID '[' NUM ']'",
"varlist : '*' ID",
"varlist : ID",
"localdeclarations : DECL localdecllist ENDDECL optsemi",
"localdeclarations : DECL ENDDECL optsemi",
"localdeclarations :",
"optsemi : ';'",
"optsemi :",
"localdecllist : localdecllist localdecl",
"localdecllist : localdecl",
"localdecl : type localvarlist ';'",
"localvarlist : localvarlist ',' ID '[' NUM ']' '[' NUM ']'",
"localvarlist : localvarlist ',' ID '[' NUM ']'",
"localvarlist : localvarlist ',' '*' ID",
"localvarlist : localvarlist ',' ID",
"localvarlist : ID '[' NUM ']' '[' NUM ']'",
"localvarlist : ID '[' NUM ']'",
"localvarlist : '*' ID",
"localvarlist : ID",
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
"stmt : RETURN E ';'",
"ifstmt : IF '(' E ')' THEN stmtlist ELSE stmtlist ENDIF ';'",
"ifstmt : IF '(' E ')' THEN stmtlist ENDIF ';'",
"whilestmt : WHILE '(' E ')' DO stmtlist ENDWHILE ';'",
"repeatuntillstmt : REPEAT stmtlist UNTILL '(' E ')' ';'",
"dowhilestmt : DO stmtlist WHILE '(' E ')' ';'",
"inputstmt : READ '(' ID ')' ';'",
"inputstmt : READ '(' '*' ID ')' ';'",
"inputstmt : READ '(' ID '[' E ']' ')' ';'",
"inputstmt : READ '(' ID '[' E ']' '[' E ']' ')' ';'",
"outputstmt : WRITE '(' E ')' ';'",
"asgstmt : ID '=' E ';'",
"asgstmt : '*' ID '=' E ';'",
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
"E : '*' ID",
"E : '&' ID",
"E : ID",
"E : ID '(' arglist ')'",
"arglist :",
"arglist : E",
"arglist : arglist ',' E",

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
#line 408 "exptree.y"

int yyerror(char *s)
{
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

	intermediate=fopen("ex2.xsm","w");

	fprintf(intermediate,"0\n2056\n0\n0\n0\n0\n0\n1\n");
	fprintf(intermediate,"MOV SP, 5000\n");

	fp=fopen(argv[1],"r");

	if(!fp)
	{
		printf("Invalid file specs");
		exit(1);
	}

	yyin=fp;
	yyparse();

	//fprintf(intermediate,"INT 10\n");

	fclose(fp);
	fclose(intermediate);

	return 0;
}
#line 801 "y.tab.c"

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
#line 44 "exptree.y"
	{
		yyval.no = yystack.l_mark[0].no;
		resolveAllCalls(yystack.l_mark[0].no);
		codegenFunctions();
		codegen(yystack.l_mark[0].no);
	}
#line 1479 "y.tab.c"
break;
case 2:
#line 51 "exptree.y"
	{
		yyval.no = yystack.l_mark[0].no;
		resolveAllCalls(yystack.l_mark[0].no);
		codegenFunctions();
		codegen(yystack.l_mark[0].no);
	}
#line 1489 "y.tab.c"
break;
case 3:
#line 60 "exptree.y"
	{
		yyval.no = makeConnectorNode(yystack.l_mark[-1].no,yystack.l_mark[0].no);
	}
#line 1496 "y.tab.c"
break;
case 4:
#line 64 "exptree.y"
	{
		yyval.no = NULL;
	}
#line 1503 "y.tab.c"
break;
case 5:
#line 71 "exptree.y"
	{
		/*
		 * The function may already have been declared
		 * in the global declaration section.
		 */
		installFunction(yystack.l_mark[-4].name,yystack.l_mark[-5].type,yystack.l_mark[-2].param);
		beginFunction(lookupFunction(yystack.l_mark[-4].name));
	}
#line 1515 "y.tab.c"
break;
case 6:
#line 80 "exptree.y"
	{
		gsymbol *f = currentFunction;
		yyval.no = makeFunctionNode(f,yystack.l_mark[-3].no);
		endFunction();
	}
#line 1524 "y.tab.c"
break;
case 7:
#line 88 "exptree.y"
	{
		yyval.param = appendParam(yystack.l_mark[-2].param,yystack.l_mark[0].param);
	}
#line 1531 "y.tab.c"
break;
case 8:
#line 92 "exptree.y"
	{
		yyval.param = yystack.l_mark[0].param;
	}
#line 1538 "y.tab.c"
break;
case 9:
#line 96 "exptree.y"
	{
		yyval.param = NULL;
	}
#line 1545 "y.tab.c"
break;
case 10:
#line 102 "exptree.y"
	{
		yyval.param = makeParam(yystack.l_mark[0].name,yystack.l_mark[-1].type);
	}
#line 1552 "y.tab.c"
break;
case 11:
#line 108 "exptree.y"
	{
		yyval.no = NULL;
	}
#line 1559 "y.tab.c"
break;
case 12:
#line 112 "exptree.y"
	{
		yyval.no = NULL;
	}
#line 1566 "y.tab.c"
break;
case 13:
#line 118 "exptree.y"
	{
		yyval.no = NULL;
	}
#line 1573 "y.tab.c"
break;
case 14:
#line 122 "exptree.y"
	{
		yyval.no = NULL;
	}
#line 1580 "y.tab.c"
break;
case 15:
#line 129 "exptree.y"
	{
		yyval.no = NULL;
	}
#line 1587 "y.tab.c"
break;
case 16:
#line 133 "exptree.y"
	{
		installFunction(yystack.l_mark[-4].name,yystack.l_mark[-5].type,yystack.l_mark[-2].param);
		yyval.no = NULL;
	}
#line 1595 "y.tab.c"
break;
case 17:
#line 140 "exptree.y"
	{
		install(yystack.l_mark[-6].name,currentType,yystack.l_mark[-4].no->val,yystack.l_mark[-1].no->val);
		yyval.no=NULL;
	}
#line 1603 "y.tab.c"
break;
case 18:
#line 145 "exptree.y"
	{
		install(yystack.l_mark[-3].name,currentType,yystack.l_mark[-1].no->val,0);
		yyval.no=NULL;
	}
#line 1611 "y.tab.c"
break;
case 19:
#line 150 "exptree.y"
	{
		install(yystack.l_mark[0].name,currentType,1,-1);
		yyval.no=NULL;
	}
#line 1619 "y.tab.c"
break;
case 20:
#line 155 "exptree.y"
	{
		install(yystack.l_mark[0].name,currentType,1,0);
		yyval.no=NULL;
	}
#line 1627 "y.tab.c"
break;
case 21:
#line 160 "exptree.y"
	{
		install(yystack.l_mark[-6].name,currentType,yystack.l_mark[-4].no->val,yystack.l_mark[-1].no->val);
		yyval.no=NULL;
	}
#line 1635 "y.tab.c"
break;
case 22:
#line 165 "exptree.y"
	{
		install(yystack.l_mark[-3].name,currentType,yystack.l_mark[-1].no->val,0);
		yyval.no=NULL;
	}
#line 1643 "y.tab.c"
break;
case 23:
#line 170 "exptree.y"
	{
		install(yystack.l_mark[0].name,currentType,1,-1);
		yyval.no=NULL;
	}
#line 1651 "y.tab.c"
break;
case 24:
#line 175 "exptree.y"
	{
		install(yystack.l_mark[0].name,currentType,1,0);
		yyval.no=NULL;
	}
#line 1659 "y.tab.c"
break;
case 25:
#line 182 "exptree.y"
	{
		yyval.no=NULL;
	}
#line 1666 "y.tab.c"
break;
case 26:
#line 186 "exptree.y"
	{
		yyval.no=NULL;
	}
#line 1673 "y.tab.c"
break;
case 27:
#line 190 "exptree.y"
	{
		yyval.no=NULL;
	}
#line 1680 "y.tab.c"
break;
case 28:
#line 196 "exptree.y"
	{
		yyval.no=NULL;
	}
#line 1687 "y.tab.c"
break;
case 29:
#line 200 "exptree.y"
	{
		yyval.no=NULL;
	}
#line 1694 "y.tab.c"
break;
case 30:
#line 206 "exptree.y"
	{
		yyval.no=NULL;
	}
#line 1701 "y.tab.c"
break;
case 31:
#line 210 "exptree.y"
	{
		yyval.no=NULL;
	}
#line 1708 "y.tab.c"
break;
case 32:
#line 216 "exptree.y"
	{
		yyval.no=NULL;
	}
#line 1715 "y.tab.c"
break;
case 33:
#line 222 "exptree.y"
	{
		installLocal(yystack.l_mark[-6].name,currentType,yystack.l_mark[-4].no->val,yystack.l_mark[-1].no->val);
	}
#line 1722 "y.tab.c"
break;
case 34:
#line 226 "exptree.y"
	{
		installLocal(yystack.l_mark[-3].name,currentType,yystack.l_mark[-1].no->val,0);
	}
#line 1729 "y.tab.c"
break;
case 35:
#line 230 "exptree.y"
	{
		installLocal(yystack.l_mark[0].name,currentType,1,-1);
	}
#line 1736 "y.tab.c"
break;
case 36:
#line 234 "exptree.y"
	{
		installLocal(yystack.l_mark[0].name,currentType,1,0);
	}
#line 1743 "y.tab.c"
break;
case 37:
#line 238 "exptree.y"
	{
		installLocal(yystack.l_mark[-6].name,currentType,yystack.l_mark[-4].no->val,yystack.l_mark[-1].no->val);
	}
#line 1750 "y.tab.c"
break;
case 38:
#line 242 "exptree.y"
	{
		installLocal(yystack.l_mark[-3].name,currentType,yystack.l_mark[-1].no->val,0);
	}
#line 1757 "y.tab.c"
break;
case 39:
#line 246 "exptree.y"
	{
		installLocal(yystack.l_mark[0].name,currentType,1,-1);
	}
#line 1764 "y.tab.c"
break;
case 40:
#line 250 "exptree.y"
	{
		installLocal(yystack.l_mark[0].name,currentType,1,0);
	}
#line 1771 "y.tab.c"
break;
case 41:
#line 256 "exptree.y"
	{
		currentType=TYPE_INT;
		yyval.type=TYPE_INT;
	}
#line 1779 "y.tab.c"
break;
case 42:
#line 261 "exptree.y"
	{
		currentType=TYPE_STR;
		yyval.type=TYPE_STR;
	}
#line 1787 "y.tab.c"
break;
case 43:
#line 268 "exptree.y"
	{
		yyval.no=makeConnectorNode(yystack.l_mark[-1].no,yystack.l_mark[0].no);
	}
#line 1794 "y.tab.c"
break;
case 44:
#line 272 "exptree.y"
	{
		yyval.no=yystack.l_mark[0].no;
	}
#line 1801 "y.tab.c"
break;
case 45:
#line 277 "exptree.y"
	{yyval.no=yystack.l_mark[0].no;}
#line 1806 "y.tab.c"
break;
case 46:
#line 278 "exptree.y"
	{yyval.no=yystack.l_mark[0].no;}
#line 1811 "y.tab.c"
break;
case 47:
#line 279 "exptree.y"
	{yyval.no=yystack.l_mark[0].no;}
#line 1816 "y.tab.c"
break;
case 48:
#line 280 "exptree.y"
	{yyval.no=yystack.l_mark[0].no;}
#line 1821 "y.tab.c"
break;
case 49:
#line 281 "exptree.y"
	{yyval.no=yystack.l_mark[0].no;}
#line 1826 "y.tab.c"
break;
case 50:
#line 282 "exptree.y"
	{yyval.no=yystack.l_mark[0].no;}
#line 1831 "y.tab.c"
break;
case 51:
#line 283 "exptree.y"
	{yyval.no=yystack.l_mark[0].no;}
#line 1836 "y.tab.c"
break;
case 52:
#line 284 "exptree.y"
	{yyval.no=yystack.l_mark[0].no;}
#line 1841 "y.tab.c"
break;
case 53:
#line 285 "exptree.y"
	{yyval.no=yystack.l_mark[0].no;}
#line 1846 "y.tab.c"
break;
case 54:
#line 286 "exptree.y"
	{yyval.no=makeReturnNode(yystack.l_mark[-1].no);}
#line 1851 "y.tab.c"
break;
case 55:
#line 290 "exptree.y"
	{
		yyval.no=makeTreeNode(NODE_IF,yystack.l_mark[-7].no,yystack.l_mark[-4].no,yystack.l_mark[-2].no);
	}
#line 1858 "y.tab.c"
break;
case 56:
#line 294 "exptree.y"
	{
		yyval.no=makeTreeNode(NODE_IF,yystack.l_mark[-5].no,yystack.l_mark[-2].no,NULL);
	}
#line 1865 "y.tab.c"
break;
case 57:
#line 300 "exptree.y"
	{
		yyval.no=makeTreeNode(NODE_WHILE,yystack.l_mark[-5].no,yystack.l_mark[-2].no,NULL);
	}
#line 1872 "y.tab.c"
break;
case 58:
#line 306 "exptree.y"
	{
		yyval.no=makeTreeNode(NODE_REPEAT,yystack.l_mark[-2].no,yystack.l_mark[-5].no,NULL);
	}
#line 1879 "y.tab.c"
break;
case 59:
#line 312 "exptree.y"
	{
		yyval.no=makeTreeNode(NODE_DOWHILE,yystack.l_mark[-2].no,yystack.l_mark[-5].no,NULL);
	}
#line 1886 "y.tab.c"
break;
case 60:
#line 318 "exptree.y"
	{
		yyval.no=makeReadNode(yystack.l_mark[-2].name);
	}
#line 1893 "y.tab.c"
break;
case 61:
#line 322 "exptree.y"
	{
		yyval.no=makeReadPointerNode(yystack.l_mark[-2].name);
	}
#line 1900 "y.tab.c"
break;
case 62:
#line 326 "exptree.y"
	{
		yyval.no=makeReadArrayNode(yystack.l_mark[-5].name,yystack.l_mark[-3].no);
	}
#line 1907 "y.tab.c"
break;
case 63:
#line 330 "exptree.y"
	{
		yyval.no=makeRead2DArrayNode(yystack.l_mark[-8].name,yystack.l_mark[-6].no,yystack.l_mark[-3].no);
	}
#line 1914 "y.tab.c"
break;
case 64:
#line 336 "exptree.y"
	{
		yyval.no=makeWriteNode(yystack.l_mark[-2].no);
	}
#line 1921 "y.tab.c"
break;
case 65:
#line 342 "exptree.y"
	{
		yyval.no=makeAssignmentNode(yystack.l_mark[-3].name,yystack.l_mark[-1].no);
	}
#line 1928 "y.tab.c"
break;
case 66:
#line 346 "exptree.y"
	{
		yyval.no=makePointerAssignmentNode(yystack.l_mark[-3].name,yystack.l_mark[-1].no);
	}
#line 1935 "y.tab.c"
break;
case 67:
#line 350 "exptree.y"
	{
		yyval.no=makeAssignmentArrayNode(yystack.l_mark[-6].name,yystack.l_mark[-4].no,yystack.l_mark[-1].no);
	}
#line 1942 "y.tab.c"
break;
case 68:
#line 354 "exptree.y"
	{
		yyval.no=makeAssignment2DArrayNode(yystack.l_mark[-9].name,yystack.l_mark[-7].no,yystack.l_mark[-4].no,yystack.l_mark[-1].no);
	}
#line 1949 "y.tab.c"
break;
case 69:
#line 360 "exptree.y"
	{
		yyval.no=makeBreakNode();
	}
#line 1956 "y.tab.c"
break;
case 70:
#line 366 "exptree.y"
	{
		yyval.no=makeContinueNode();
	}
#line 1963 "y.tab.c"
break;
case 71:
#line 371 "exptree.y"
	{yyval.no=makeOperatorNode('+',yystack.l_mark[-2].no,yystack.l_mark[0].no);}
#line 1968 "y.tab.c"
break;
case 72:
#line 372 "exptree.y"
	{yyval.no=makeOperatorNode('-',yystack.l_mark[-2].no,yystack.l_mark[0].no);}
#line 1973 "y.tab.c"
break;
case 73:
#line 373 "exptree.y"
	{yyval.no=makeOperatorNode('*',yystack.l_mark[-2].no,yystack.l_mark[0].no);}
#line 1978 "y.tab.c"
break;
case 74:
#line 374 "exptree.y"
	{yyval.no=makeOperatorNode('/',yystack.l_mark[-2].no,yystack.l_mark[0].no);}
#line 1983 "y.tab.c"
break;
case 75:
#line 375 "exptree.y"
	{yyval.no=makeOperatorNode('%',yystack.l_mark[-2].no,yystack.l_mark[0].no);}
#line 1988 "y.tab.c"
break;
case 76:
#line 376 "exptree.y"
	{yyval.no=makeOperatorNode('>',yystack.l_mark[-2].no,yystack.l_mark[0].no);}
#line 1993 "y.tab.c"
break;
case 77:
#line 377 "exptree.y"
	{yyval.no=makeOperatorNode('<',yystack.l_mark[-2].no,yystack.l_mark[0].no);}
#line 1998 "y.tab.c"
break;
case 78:
#line 378 "exptree.y"
	{yyval.no=makeOperatorNode('n',yystack.l_mark[-2].no,yystack.l_mark[0].no);}
#line 2003 "y.tab.c"
break;
case 79:
#line 379 "exptree.y"
	{yyval.no=makeOperatorNode('e',yystack.l_mark[-2].no,yystack.l_mark[0].no);}
#line 2008 "y.tab.c"
break;
case 80:
#line 380 "exptree.y"
	{yyval.no=makeOperatorNode('l',yystack.l_mark[-2].no,yystack.l_mark[0].no);}
#line 2013 "y.tab.c"
break;
case 81:
#line 381 "exptree.y"
	{yyval.no=makeOperatorNode('g',yystack.l_mark[-2].no,yystack.l_mark[0].no);}
#line 2018 "y.tab.c"
break;
case 82:
#line 382 "exptree.y"
	{yyval.no=yystack.l_mark[-1].no;}
#line 2023 "y.tab.c"
break;
case 83:
#line 383 "exptree.y"
	{yyval.no=yystack.l_mark[0].no;}
#line 2028 "y.tab.c"
break;
case 84:
#line 384 "exptree.y"
	{yyval.no=yystack.l_mark[0].no;}
#line 2033 "y.tab.c"
break;
case 85:
#line 385 "exptree.y"
	{yyval.no=make2DArrayNode(yystack.l_mark[-6].name,yystack.l_mark[-4].no,yystack.l_mark[-1].no);}
#line 2038 "y.tab.c"
break;
case 86:
#line 386 "exptree.y"
	{yyval.no=makeArrayNode(yystack.l_mark[-3].name,yystack.l_mark[-1].no);}
#line 2043 "y.tab.c"
break;
case 87:
#line 387 "exptree.y"
	{yyval.no=makeDeReferenceNode(yystack.l_mark[0].name);}
#line 2048 "y.tab.c"
break;
case 88:
#line 388 "exptree.y"
	{yyval.no=makeAddressNode(yystack.l_mark[0].name);}
#line 2053 "y.tab.c"
break;
case 89:
#line 389 "exptree.y"
	{yyval.no=makeVariableNode(yystack.l_mark[0].name);}
#line 2058 "y.tab.c"
break;
case 90:
#line 390 "exptree.y"
	{yyval.no=makeCallNode(yystack.l_mark[-3].name,yystack.l_mark[-1].no,countArguments(yystack.l_mark[-1].no));}
#line 2063 "y.tab.c"
break;
case 91:
#line 394 "exptree.y"
	{
		yyval.no=NULL;
	}
#line 2070 "y.tab.c"
break;
case 92:
#line 398 "exptree.y"
	{
		yyval.no=yystack.l_mark[0].no;
	}
#line 2077 "y.tab.c"
break;
case 93:
#line 402 "exptree.y"
	{
		yyval.no=makeConnectorNode(yystack.l_mark[-2].no,yystack.l_mark[0].no);
	}
#line 2084 "y.tab.c"
break;
#line 2086 "y.tab.c"
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
