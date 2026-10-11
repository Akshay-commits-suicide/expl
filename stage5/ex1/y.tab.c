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
#line 15 "exptree.y"
typedef union YYSTYPE {
    struct tnode* no;
    char* name;
    int type;
    Param* param;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 50 "y.tab.c"

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
    0,    0,   15,   15,   28,   14,   29,   14,   17,   17,
   17,   18,   18,   22,   22,   20,   20,   21,   21,   21,
   19,   19,   19,   19,   19,   19,   19,   19,   25,   25,
   25,   27,   27,   24,   24,   23,   30,   30,   30,   30,
   30,   30,   30,   30,   26,   26,    1,    1,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    3,
    8,    8,    9,   11,   10,    4,    4,    4,    4,    5,
    6,    6,    6,    6,   12,   13,    7,    7,    7,    7,
    7,    7,    7,    7,    7,    7,    7,    7,    7,    7,
    7,    7,    7,    7,    7,    7,   16,   16,   16,
};
static const YYINT yylen[] = {                            2,
    2,    1,    2,    0,    0,   13,    0,   14,    3,    1,
    0,    2,    3,    4,    3,    2,    1,    3,    6,    7,
    9,    6,    4,    3,    7,    4,    2,    1,    4,    3,
    0,    1,    0,    2,    1,    3,    9,    6,    4,    3,
    7,    4,    2,    1,    1,    1,    2,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    3,    1,    5,
   10,    8,    8,    7,    7,    5,    6,    8,   11,    5,
    4,    5,    7,   10,    2,    2,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    1,    1,
    7,    4,    2,    2,    1,    4,    0,    1,    3,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    4,    0,   45,   46,    0,   17,    0,
    3,    0,    0,   32,   15,    0,   16,    0,    0,    0,
    0,    0,   14,    0,    0,    0,    0,   18,    0,    0,
    0,   10,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   12,    0,    0,    0,    0,   23,    0,    0,   19,
    9,   13,    0,    0,    0,    5,    0,    0,   20,    0,
    0,    7,   25,    0,    0,    0,    0,    0,    0,   35,
    0,    0,    0,    0,   21,   30,    0,   34,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   48,   59,   49,   50,   51,   52,   53,
   54,   55,   56,   57,    0,   29,    0,   43,    0,   36,
    0,    0,    0,   89,    0,   90,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   75,   76,    0,    0,
   47,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   93,    0,   94,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   58,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   39,    0,
    0,    0,   71,    0,    0,   88,    0,    0,    0,    0,
    0,    0,    0,    0,   79,   80,   81,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    6,    0,    0,    0,
   60,    0,    0,    0,   96,    0,   70,   66,    0,    0,
    0,    0,    0,    0,   72,    8,    0,    0,    0,    0,
    0,    0,   67,    0,    0,    0,    0,   41,    0,    0,
   73,    0,    0,    0,    0,    0,    0,   65,   64,    0,
    0,   91,   68,    0,    0,   62,   63,   37,    0,    0,
    0,   74,    0,   61,   69,
};
#if defined(YYDESTRUCT_CALL) || defined(YYSTYPE_TOSTRING)
static const YYINT yystos[] = {                           0,
  277,  285,  300,  307,  276,  278,  279,  305,  306,  311,
  299,  311,  300,   59,  312,  276,  306,  258,   42,  304,
  258,   42,  312,   40,   91,  258,   44,   59,   40,  258,
  302,  303,  311,  257,   40,  258,   42,  302,   40,   41,
   44,  258,   42,   93,  302,   91,  258,   41,  302,   59,
  303,  258,   91,   41,  257,  123,   41,  257,   59,   93,
  313,  123,   93,   91,  277,  310,  314,  257,  276,  308,
  309,  311,  260,  310,   93,  312,  276,  308,  258,   42,
  315,  258,  262,  263,  264,  265,  268,  269,  273,  274,
  275,   42,  286,  287,  288,  289,  290,  291,  293,  294,
  295,  296,  297,  298,  260,  312,   91,  258,   44,   59,
   40,   91,   61,  257,  258,  259,   42,   40,   38,  292,
   40,   40,   40,   40,  286,  286,   59,   59,  258,  261,
  287,  286,  257,  258,   42,  292,  301,  292,  292,   40,
   91,  258,  292,  258,  280,  281,   60,   62,  282,  283,
   43,   45,   42,   47,   37,   59,  292,  258,   42,  292,
  292,  268,  272,   61,  312,  261,   93,   91,  258,   41,
   44,   93,   59,  301,  292,   41,  292,  292,  292,  292,
  292,  292,  292,  292,  292,  292,  292,   41,   41,   91,
  258,   41,   41,   40,   40,  292,  125,  312,   91,  257,
   59,  292,   91,   61,   41,   93,   59,   59,  292,   41,
  266,  269,  292,  292,   59,  125,  257,   93,  292,  292,
   91,   93,   59,  286,  286,   41,   41,   93,   91,   93,
   59,  292,   41,   91,  267,  270,  271,   59,   59,  257,
   61,   93,   59,  292,  286,   59,   59,   93,  292,   93,
  270,   59,   41,   59,   59,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
static const YYINT yydgoto[] = {                          2,
   93,   94,   95,   96,   97,   98,  136,   99,  100,  101,
  102,  103,  104,   11,    3,  137,   31,   32,   20,    8,
    9,    4,   70,   71,   66,   33,   15,   61,   67,   81,
};
static const YYINT yysindex[] = {                      -275,
   52,    0, -221,    0,  -22,    0,    0,  106,    0,  -31,
    0,  -30, -221,    0,    0,  -22,    0,   20, -214,   -5,
   10, -199,    0, -221, -194,   53,   19,    0, -221,   56,
  139,    0,   36,    5, -221,   59, -172,  248, -221,   78,
 -221,    0, -111,   60,  412,  -96,    0,   47,  433,    0,
    0,    0,  -86,  143,   92,    0,   67,  111,    0,  118,
  -64,    0,    0,  -36,  150,  -19,  -64,  136,  -22,    0,
  173,   38,  336,   -1,    0,    0,  -22,    0,  170,   11,
   45,  126,  377,  232,  250,  255,  269,  336,  336,  241,
  264,   74,  246,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  336,    0,   76,    0,   39,    0,
  377,  377,  377,    0,   51,    0,   85,  377,   98,   -7,
  377,   46,  377,  377,  350,  260,    0,    0,  273,  -22,
    0,  284,  258,  266,  100,  282,  443,    4,   25,  377,
  377,    0,   32,    0,  377,  377,  377,  377,  377,  377,
  377,  377,  377,  377,  377,    0,   58,  -20,  105,   65,
   72,  325,  330,  377,  247,  -22,  288,  123,    0,  327,
  377,  -43,    0,  500,   79,    0,  346,  346,  596,  596,
  596,  596,  107,  107,    0,    0,    0,  328,  331,  377,
  353,  133,  132,  377,  377,   86,    0,  275,  159,  314,
    0,  282,  377,  377,    0,  329,    0,    0,   93,  359,
  336,  336,  115,  122,    0,    0,  334,  340,  131,  152,
  377,   -8,    0,  228,  308,  -39,  363,    0,  179,  387,
    0,  163,  382,  377,  336,  398,  403,    0,    0,  370,
  377,    0,    0,  256,  322,    0,    0,    0,  189,  434,
  417,    0,  429,    0,    0,
};
static const YYINT yyrindex[] = {                         1,
    0,    0,  489,    0,    3,    0,    0,    0,    0,    0,
    0,    0,  494,    0,    0,    3,    0,  137,    0,    0,
    0,    0,    0,  510,    0,  144,    0,    0,  510,    0,
    0,    0,    0,    0,  510,  148,    0,    0,  510,    0,
    0,    0,    0,  176,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  203,
  240,    0,    0,    0,    0,    0,  240,    0,  245,    0,
    0,    0,    0,    0,    0,    0,  245,    0,  224,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  534,    0,    0,    0,  -37,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  381,
    0,    0,    0,  276,    0,  562,    0,    0,    0,  534,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  381,  277,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  157,  174,  178,  198,
  406,  423,  -17,  380,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  576,    0,    0,    0,  -28,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  278,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,
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
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,
};
#endif
static const YYINT yygindex[] = {                         0,
  438,  185,    0,    0,    0,    0,  572,    0,    0,    0,
    0,    0,    0,    0,  508,  373,  342,  476,    0,    0,
  522,    0,  460,    0,  473,  629,   13,    0,    0,    0,
};
#define YYTABLESIZE 813
static const YYINT yytable[] = {                         95,
    4,    1,   33,   95,   95,   95,   95,   95,   92,   95,
   19,   22,   92,   92,   92,   92,   92,  204,   92,  238,
  189,   95,   95,   77,   95,   77,   77,   77,   23,  155,
   92,   92,  233,   92,  153,  151,   14,  152,   27,  154,
  155,   77,   77,   26,   77,  153,  151,  203,  152,   29,
  154,  156,  147,   28,  148,   95,    6,    7,   30,   24,
   37,  155,   34,  147,   92,  148,  153,  151,  155,  152,
  190,  154,  176,  153,  151,   77,  152,   43,  154,   80,
  135,   76,  234,  173,  147,   47,  148,  159,  109,  106,
  140,  147,   35,  148,  155,   39,  172,   44,  188,  153,
  151,  155,  152,  110,  154,  192,  153,  151,  155,  152,
   25,  154,  193,  153,  151,  155,  152,  147,  154,  148,
  153,  151,  155,  152,  147,  154,  148,  153,  151,  155,
  152,  147,  154,  148,  153,  151,   50,  152,  147,  154,
  148,  141,  165,  155,  215,  147,   52,  148,  153,   46,
   53,  155,  147,  154,  148,  226,  153,  151,  155,  152,
   55,  154,  227,  153,  151,  111,  152,  155,  154,   56,
   58,  206,  153,  151,  147,  152,  148,  154,  198,   40,
   28,  147,   41,  148,   60,  222,  113,   27,  155,   62,
  147,   24,  148,  153,  151,   28,  152,   84,  154,  155,
   84,   59,   27,   63,  153,  151,   24,  152,   64,  154,
  231,  147,   65,  148,   85,   84,  112,   85,   83,   26,
   68,   83,  147,  230,  148,  155,   18,   21,   75,  212,
  153,  151,   85,  152,   26,  154,   83,   83,   82,   83,
   73,   82,   95,   95,   95,   95,   22,  252,  147,   84,
  148,   92,   92,   92,   92,  242,   82,   82,  105,   82,
  107,   22,   77,   77,   77,   77,   85,   44,  108,   92,
   83,  121,  145,  146,  149,  150,   36,  131,    4,    4,
   33,   33,   44,  145,  146,  149,  150,   92,   48,  122,
   82,   41,  155,   42,  123,   79,  134,  153,  151,  127,
  152,   92,  154,  158,  145,  146,  149,  150,  124,  131,
  131,  145,  146,  149,  150,  147,  131,  148,  155,   40,
   42,   38,  128,  153,  151,   92,  152,    5,  154,    6,
    7,  129,  133,  164,   40,   42,   38,  145,  146,  149,
  150,  147,  142,  148,  145,  146,  149,  150,  250,   92,
  167,  145,  146,  149,  150,  144,  168,  169,  145,  146,
  149,  150,  191,   92,  194,  145,  146,  149,  150,  195,
   38,  197,  145,  146,  149,  150,   45,   92,  199,  200,
   49,   16,  155,    6,    7,  201,  207,  153,  151,  208,
  152,   92,  154,  210,  145,  146,  149,  150,  211,  216,
  212,  145,  146,  149,  150,  147,  218,  148,  131,  131,
  145,  146,  149,  150,  119,  217,  118,  223,  117,  221,
   78,  239,   78,   78,   78,   69,  228,    6,    7,  131,
  229,  145,  146,  149,  150,  240,   84,   84,   78,   78,
  243,   78,  145,  146,  149,  150,   86,  241,   77,   86,
    6,    7,   54,   85,   85,   41,  246,   83,   83,   83,
   83,  247,  248,   87,   86,   86,   87,   86,  145,  146,
  149,  150,   78,   57,  253,  254,   41,   82,   82,   82,
   82,   87,   87,  170,   87,   82,  171,  255,    2,   83,
   84,   85,   86,    1,  235,   87,   88,  236,   86,   31,
   89,   90,   91,   82,   33,   33,  130,   83,   84,   85,
   86,   13,  174,   87,   88,   87,   51,   82,   89,   90,
   91,   83,   84,   85,   86,  125,  126,   87,   88,   17,
   78,  163,   89,   90,   91,  145,  146,  149,  150,   74,
  205,   82,  132,  171,  166,   83,   84,   85,   86,    0,
   11,   87,   88,   11,    0,    0,   89,   90,   91,    0,
    0,  145,  146,  149,  150,   82,    0,    0,    0,   83,
   84,   85,   86,    0,   97,   87,   88,   97,  237,   82,
   89,   90,   91,   83,   84,   85,   86,    0,    0,   87,
   88,  251,    0,   82,   89,   90,   91,   83,   84,   85,
   86,    0,   98,   87,   88,   98,    0,   82,   89,   90,
   91,   83,   84,   85,   86,    0,   99,  162,   88,   99,
    0,    0,   89,   90,   91,    0,    0,  149,  150,   10,
    0,   12,  155,  114,  115,  116,   10,  153,  151,    0,
  152,   12,  154,    0,    0,    0,    0,    0,  224,  225,
    0,    0,    0,    0,  120,    0,    0,    0,    0,   78,
   78,   78,   78,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  245,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  138,  139,   86,   86,   86,   86,  143,
    0,    0,  157,   72,  160,  161,    0,    0,    0,   72,
    0,    0,   87,   87,   87,   87,    0,    0,    0,    0,
    0,    0,  175,    0,    0,    0,  177,  178,  179,  180,
  181,  182,  183,  184,  185,  186,  187,    0,    0,    0,
    0,    0,    0,    0,    0,  196,    0,    0,    0,    0,
    0,    0,  202,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  209,    0,    0,    0,  213,  214,    0,    0,    0,
    0,    0,    0,    0,  219,  220,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  232,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  244,    0,    0,    0,    0,
    0,    0,  249,
};
static const YYINT yycheck[] = {                         37,
    0,  277,    0,   41,   42,   43,   44,   45,   37,   47,
   42,   42,   41,   42,   43,   44,   45,   61,   47,   59,
   41,   59,   60,   41,   62,   43,   44,   45,   16,   37,
   59,   60,   41,   62,   42,   43,   59,   45,   44,   47,
   37,   59,   60,  258,   62,   42,   43,   91,   45,   40,
   47,   59,   60,   59,   62,   93,  278,  279,  258,   40,
   42,   37,  257,   60,   93,   62,   42,   43,   37,   45,
   91,   47,   41,   42,   43,   93,   45,   42,   47,   42,
   42,   69,   91,   59,   60,  258,   62,   42,   44,   77,
   40,   60,   40,   62,   37,   40,   93,   93,   41,   42,
   43,   37,   45,   59,   47,   41,   42,   43,   37,   45,
   91,   47,   41,   42,   43,   37,   45,   60,   47,   62,
   42,   43,   37,   45,   60,   47,   62,   42,   43,   37,
   45,   60,   47,   62,   42,   43,   59,   45,   60,   47,
   62,   91,  130,   37,   59,   60,  258,   62,   42,   91,
   91,   37,   60,   47,   62,   41,   42,   43,   37,   45,
  257,   47,   41,   42,   43,   40,   45,   37,   47,  123,
  257,   93,   42,   43,   60,   45,   62,   47,  166,   41,
   44,   60,   44,   62,   93,   93,   61,   44,   37,  123,
   60,   44,   62,   42,   43,   59,   45,   41,   47,   37,
   44,   59,   59,   93,   42,   43,   59,   45,   91,   47,
   59,   60,  277,   62,   41,   59,   91,   44,   41,   44,
  257,   44,   60,   93,   62,   37,  258,  258,   93,  269,
   42,   43,   59,   45,   59,   47,   59,   60,   41,   62,
  260,   44,  280,  281,  282,  283,   44,   59,   60,   93,
   62,  280,  281,  282,  283,   93,   59,   60,  260,   62,
   91,   59,  280,  281,  282,  283,   93,   44,  258,   42,
   93,   40,  280,  281,  282,  283,  258,   93,  278,  279,
  278,  279,   59,  280,  281,  282,  283,   42,   41,   40,
   93,   44,   37,  258,   40,  258,  258,   42,   43,   59,
   45,   42,   47,  258,  280,  281,  282,  283,   40,  125,
  126,  280,  281,  282,  283,   60,  132,   62,   37,   44,
   44,   44,   59,   42,   43,   42,   45,  276,   47,  278,
  279,  258,  257,   61,   59,   59,   59,  280,  281,  282,
  283,   60,  258,   62,  280,  281,  282,  283,   93,   42,
   93,  280,  281,  282,  283,  258,   91,  258,  280,  281,
  282,  283,  258,   42,   40,  280,  281,  282,  283,   40,
   29,  125,  280,  281,  282,  283,   35,   42,   91,  257,
   39,  276,   37,  278,  279,   59,   59,   42,   43,   59,
   45,   42,   47,   41,  280,  281,  282,  283,  266,  125,
  269,  280,  281,  282,  283,   60,   93,   62,  224,  225,
  280,  281,  282,  283,   38,  257,   40,   59,   42,   91,
   41,   59,   43,   44,   45,  276,   93,  278,  279,  245,
   91,  280,  281,  282,  283,  257,  280,  281,   59,   60,
   59,   62,  280,  281,  282,  283,   41,   61,  276,   44,
  278,  279,   41,  280,  281,   44,   59,  280,  281,  282,
  283,   59,   93,   41,   59,   60,   44,   62,  280,  281,
  282,  283,   93,   41,   41,   59,   44,  280,  281,  282,
  283,   59,   60,   41,   62,  258,   44,   59,    0,  262,
  263,  264,  265,    0,  267,  268,  269,  270,   93,  260,
  273,  274,  275,  258,  260,  125,  261,  262,  263,  264,
  265,    4,  140,  268,  269,   93,   41,  258,  273,  274,
  275,  262,  263,  264,  265,   88,   89,  268,  269,    8,
   71,  272,  273,  274,  275,  280,  281,  282,  283,   67,
   41,  258,  105,   44,  261,  262,  263,  264,  265,   -1,
   41,  268,  269,   44,   -1,   -1,  273,  274,  275,   -1,
   -1,  280,  281,  282,  283,  258,   -1,   -1,   -1,  262,
  263,  264,  265,   -1,   41,  268,  269,   44,  271,  258,
  273,  274,  275,  262,  263,  264,  265,   -1,   -1,  268,
  269,  270,   -1,  258,  273,  274,  275,  262,  263,  264,
  265,   -1,   41,  268,  269,   44,   -1,  258,  273,  274,
  275,  262,  263,  264,  265,   -1,   41,  268,  269,   44,
   -1,   -1,  273,  274,  275,   -1,   -1,  282,  283,    1,
   -1,    3,   37,  257,  258,  259,    8,   42,   43,   -1,
   45,   13,   47,   -1,   -1,   -1,   -1,   -1,  211,  212,
   -1,   -1,   -1,   -1,   83,   -1,   -1,   -1,   -1,  280,
  281,  282,  283,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  235,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  112,  113,  280,  281,  282,  283,  118,
   -1,   -1,  121,   65,  123,  124,   -1,   -1,   -1,   71,
   -1,   -1,  280,  281,  282,  283,   -1,   -1,   -1,   -1,
   -1,   -1,  141,   -1,   -1,   -1,  145,  146,  147,  148,
  149,  150,  151,  152,  153,  154,  155,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  164,   -1,   -1,   -1,   -1,
   -1,   -1,  171,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  190,   -1,   -1,   -1,  194,  195,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  203,  204,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  221,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  234,   -1,   -1,   -1,   -1,
   -1,   -1,  241,
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
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,
};
#endif
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 283
#define YYUNDFTOKEN 316
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
"$accept","program","stmtlist","stmt","callstmt","inputstmt","outputstmt",
"asgstmt","E","ifstmt","whilestmt","dowhilestmt","repeatuntillstmt","breakstmt",
"continuestmt","function","functionlist","arglist","paramlist","param",
"varlist","decllist","decl","declarations","localdecl","localdecllist",
"localdeclarations","type","optsemi","$$1","$$2","localvarlist",
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : declarations functionlist",
"program : functionlist",
"functionlist : functionlist function",
"functionlist :",
"$$1 :",
"function : type ID '(' paramlist ')' '{' $$1 localdeclarations TBEGIN stmtlist END optsemi '}'",
"$$2 :",
"function : type '*' ID '(' paramlist ')' '{' $$2 localdeclarations TBEGIN stmtlist END optsemi '}'",
"paramlist : paramlist ',' param",
"paramlist : param",
"paramlist :",
"param : type ID",
"param : type '*' ID",
"declarations : DECL decllist ENDDECL optsemi",
"declarations : DECL ENDDECL optsemi",
"decllist : decllist decl",
"decllist : decl",
"decl : type varlist ';'",
"decl : type ID '(' paramlist ')' ';'",
"decl : type '*' ID '(' paramlist ')' ';'",
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
"stmt : callstmt",
"callstmt : ID '(' arglist ')' ';'",
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
#line 741 "exptree.y"


int yyerror(char *s)
{
    printf("yyerror:%s\n",s);
    exit(1);
    return 0;
}


int main(int argc,char *argv[])
{
    if(argc < 2)
    {
        printf("No input for filename\n");
        exit(1);
    }

    intermediate = fopen("ex2.xsm","w");

    fprintf(intermediate,"0\n2056\n0\n0\n0\n0\n0\n1\n");
    fprintf(intermediate,"MOV SP, 5000\n");

    fp = fopen(argv[1],"r");

    if(!fp)
    {
        printf("Invalid file specs");
        exit(1);
    }

    yyin = fp;

    yyparse();

    fclose(fp);
    fclose(intermediate);

    return 0;
}
#line 849 "y.tab.c"

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
#line 69 "exptree.y"
	{
          yyval.no = yystack.l_mark[0].no;
          resolveAllCalls(yystack.l_mark[0].no);
          codegenFunctions();
          codegen(yystack.l_mark[0].no);
      }
#line 1527 "y.tab.c"
break;
case 2:
#line 77 "exptree.y"
	{
          yyval.no = yystack.l_mark[0].no;
          resolveAllCalls(yystack.l_mark[0].no);
          codegenFunctions();
          codegen(yystack.l_mark[0].no);
      }
#line 1537 "y.tab.c"
break;
case 3:
#line 92 "exptree.y"
	{
          yyval.no = makeConnectorNode(yystack.l_mark[-1].no,yystack.l_mark[0].no);
      }
#line 1544 "y.tab.c"
break;
case 4:
#line 97 "exptree.y"
	{
          yyval.no = NULL;
      }
#line 1551 "y.tab.c"
break;
case 5:
#line 112 "exptree.y"
	{
          installFunction(yystack.l_mark[-4].name, yystack.l_mark[-5].type, yystack.l_mark[-2].param, 0);
          beginFunction(lookupFunction(yystack.l_mark[-4].name));
      }
#line 1559 "y.tab.c"
break;
case 6:
#line 117 "exptree.y"
	{
          gsymbol *f = currentFunction;
          yyval.no = makeFunctionNode(f,yystack.l_mark[-3].no);
          endFunction();
      }
#line 1568 "y.tab.c"
break;
case 7:
#line 127 "exptree.y"
	{
          installFunction(yystack.l_mark[-4].name, yystack.l_mark[-6].type, yystack.l_mark[-2].param, 1);
          beginFunction(lookupFunction(yystack.l_mark[-4].name));
      }
#line 1576 "y.tab.c"
break;
case 8:
#line 132 "exptree.y"
	{
          gsymbol *f = currentFunction;
          yyval.no = makeFunctionNode(f,yystack.l_mark[-3].no);
          endFunction();
      }
#line 1585 "y.tab.c"
break;
case 9:
#line 146 "exptree.y"
	{
          yyval.param = appendParam(yystack.l_mark[-2].param,yystack.l_mark[0].param);
      }
#line 1592 "y.tab.c"
break;
case 10:
#line 151 "exptree.y"
	{
          yyval.param = yystack.l_mark[0].param;
      }
#line 1599 "y.tab.c"
break;
case 11:
#line 156 "exptree.y"
	{
          yyval.param = NULL;
      }
#line 1606 "y.tab.c"
break;
case 12:
#line 164 "exptree.y"
	{
          yyval.param = makeParam(yystack.l_mark[0].name,yystack.l_mark[-1].type,0);
      }
#line 1613 "y.tab.c"
break;
case 13:
#line 169 "exptree.y"
	{
          yyval.param = makeParam(yystack.l_mark[0].name,yystack.l_mark[-2].type,1);
      }
#line 1620 "y.tab.c"
break;
case 14:
#line 181 "exptree.y"
	{
          yyval.no = NULL;
      }
#line 1627 "y.tab.c"
break;
case 15:
#line 186 "exptree.y"
	{
          yyval.no = NULL;
      }
#line 1634 "y.tab.c"
break;
case 16:
#line 194 "exptree.y"
	{
          yyval.no = NULL;
      }
#line 1641 "y.tab.c"
break;
case 17:
#line 199 "exptree.y"
	{
          yyval.no = NULL;
      }
#line 1648 "y.tab.c"
break;
case 18:
#line 209 "exptree.y"
	{
          yyval.no = NULL;
      }
#line 1655 "y.tab.c"
break;
case 19:
#line 216 "exptree.y"
	{
          installFunction(yystack.l_mark[-4].name,yystack.l_mark[-5].type,yystack.l_mark[-2].param,0);
          yyval.no = NULL;
      }
#line 1663 "y.tab.c"
break;
case 20:
#line 224 "exptree.y"
	{
          installFunction(yystack.l_mark[-4].name,yystack.l_mark[-6].type,yystack.l_mark[-2].param,1);
          yyval.no = NULL;
      }
#line 1671 "y.tab.c"
break;
case 21:
#line 237 "exptree.y"
	{
          install(yystack.l_mark[-6].name,currentType,yystack.l_mark[-4].no->val,yystack.l_mark[-1].no->val);
          yyval.no = NULL;
      }
#line 1679 "y.tab.c"
break;
case 22:
#line 243 "exptree.y"
	{
          install(yystack.l_mark[-3].name,currentType,yystack.l_mark[-1].no->val,0);
          yyval.no = NULL;
      }
#line 1687 "y.tab.c"
break;
case 23:
#line 249 "exptree.y"
	{
          install(yystack.l_mark[0].name,currentType,1,-1);
          yyval.no = NULL;
      }
#line 1695 "y.tab.c"
break;
case 24:
#line 255 "exptree.y"
	{
          install(yystack.l_mark[0].name,currentType,1,0);
          yyval.no = NULL;
      }
#line 1703 "y.tab.c"
break;
case 25:
#line 261 "exptree.y"
	{
          install(yystack.l_mark[-6].name,currentType,yystack.l_mark[-4].no->val,yystack.l_mark[-1].no->val);
          yyval.no = NULL;
      }
#line 1711 "y.tab.c"
break;
case 26:
#line 267 "exptree.y"
	{
          install(yystack.l_mark[-3].name,currentType,yystack.l_mark[-1].no->val,0);
          yyval.no = NULL;
      }
#line 1719 "y.tab.c"
break;
case 27:
#line 273 "exptree.y"
	{
          install(yystack.l_mark[0].name,currentType,1,-1);
          yyval.no = NULL;
      }
#line 1727 "y.tab.c"
break;
case 28:
#line 279 "exptree.y"
	{
          install(yystack.l_mark[0].name,currentType,1,0);
          yyval.no = NULL;
      }
#line 1735 "y.tab.c"
break;
case 29:
#line 292 "exptree.y"
	{
          yyval.no = NULL;
      }
#line 1742 "y.tab.c"
break;
case 30:
#line 297 "exptree.y"
	{
          yyval.no = NULL;
      }
#line 1749 "y.tab.c"
break;
case 31:
#line 302 "exptree.y"
	{
          yyval.no = NULL;
      }
#line 1756 "y.tab.c"
break;
case 32:
#line 310 "exptree.y"
	{
          yyval.no = NULL;
      }
#line 1763 "y.tab.c"
break;
case 33:
#line 315 "exptree.y"
	{
          yyval.no = NULL;
      }
#line 1770 "y.tab.c"
break;
case 34:
#line 323 "exptree.y"
	{
          yyval.no = NULL;
      }
#line 1777 "y.tab.c"
break;
case 35:
#line 328 "exptree.y"
	{
          yyval.no = NULL;
      }
#line 1784 "y.tab.c"
break;
case 36:
#line 336 "exptree.y"
	{
          yyval.no = NULL;
      }
#line 1791 "y.tab.c"
break;
case 37:
#line 348 "exptree.y"
	{
          installLocal(yystack.l_mark[-6].name,currentType,yystack.l_mark[-4].no->val,yystack.l_mark[-1].no->val);
      }
#line 1798 "y.tab.c"
break;
case 38:
#line 353 "exptree.y"
	{
          installLocal(yystack.l_mark[-3].name,currentType,yystack.l_mark[-1].no->val,0);
      }
#line 1805 "y.tab.c"
break;
case 39:
#line 358 "exptree.y"
	{
          installLocal(yystack.l_mark[0].name,currentType,1,-1);
      }
#line 1812 "y.tab.c"
break;
case 40:
#line 363 "exptree.y"
	{
          installLocal(yystack.l_mark[0].name,currentType,1,0);
      }
#line 1819 "y.tab.c"
break;
case 41:
#line 368 "exptree.y"
	{
          installLocal(yystack.l_mark[-6].name,currentType,yystack.l_mark[-4].no->val,yystack.l_mark[-1].no->val);
      }
#line 1826 "y.tab.c"
break;
case 42:
#line 373 "exptree.y"
	{
          installLocal(yystack.l_mark[-3].name,currentType,yystack.l_mark[-1].no->val,0);
      }
#line 1833 "y.tab.c"
break;
case 43:
#line 378 "exptree.y"
	{
          installLocal(yystack.l_mark[0].name,currentType,1,-1);
      }
#line 1840 "y.tab.c"
break;
case 44:
#line 383 "exptree.y"
	{
          installLocal(yystack.l_mark[0].name,currentType,1,0);
      }
#line 1847 "y.tab.c"
break;
case 45:
#line 395 "exptree.y"
	{
          currentType = TYPE_INT;
          yyval.type = TYPE_INT;
      }
#line 1855 "y.tab.c"
break;
case 46:
#line 401 "exptree.y"
	{
          currentType = TYPE_STR;
          yyval.type = TYPE_STR;
      }
#line 1863 "y.tab.c"
break;
case 47:
#line 414 "exptree.y"
	{
          yyval.no = makeConnectorNode(yystack.l_mark[-1].no,yystack.l_mark[0].no);
      }
#line 1870 "y.tab.c"
break;
case 48:
#line 419 "exptree.y"
	{
          yyval.no = yystack.l_mark[0].no;
      }
#line 1877 "y.tab.c"
break;
case 49:
#line 427 "exptree.y"
	{
          yyval.no = yystack.l_mark[0].no;
      }
#line 1884 "y.tab.c"
break;
case 50:
#line 432 "exptree.y"
	{
          yyval.no = yystack.l_mark[0].no;
      }
#line 1891 "y.tab.c"
break;
case 51:
#line 437 "exptree.y"
	{
          yyval.no = yystack.l_mark[0].no;
      }
#line 1898 "y.tab.c"
break;
case 52:
#line 442 "exptree.y"
	{
          yyval.no = yystack.l_mark[0].no;
      }
#line 1905 "y.tab.c"
break;
case 53:
#line 447 "exptree.y"
	{
          yyval.no = yystack.l_mark[0].no;
      }
#line 1912 "y.tab.c"
break;
case 54:
#line 452 "exptree.y"
	{
          yyval.no = yystack.l_mark[0].no;
      }
#line 1919 "y.tab.c"
break;
case 55:
#line 457 "exptree.y"
	{
          yyval.no = yystack.l_mark[0].no;
      }
#line 1926 "y.tab.c"
break;
case 56:
#line 462 "exptree.y"
	{
          yyval.no = yystack.l_mark[0].no;
      }
#line 1933 "y.tab.c"
break;
case 57:
#line 467 "exptree.y"
	{
          yyval.no = yystack.l_mark[0].no;
      }
#line 1940 "y.tab.c"
break;
case 58:
#line 472 "exptree.y"
	{
          yyval.no = makeReturnNode(yystack.l_mark[-1].no);
      }
#line 1947 "y.tab.c"
break;
case 59:
#line 477 "exptree.y"
	{
          yyval.no = yystack.l_mark[0].no;
      }
#line 1954 "y.tab.c"
break;
case 60:
#line 486 "exptree.y"
	{
          yyval.no = makeCallStmtNode(yystack.l_mark[-4].name,yystack.l_mark[-2].no,countArguments(yystack.l_mark[-2].no));
      }
#line 1961 "y.tab.c"
break;
case 61:
#line 498 "exptree.y"
	{
          yyval.no = makeTreeNode(NODE_IF,yystack.l_mark[-7].no,yystack.l_mark[-4].no,yystack.l_mark[-2].no);
      }
#line 1968 "y.tab.c"
break;
case 62:
#line 503 "exptree.y"
	{
          yyval.no = makeTreeNode(NODE_IF,yystack.l_mark[-5].no,yystack.l_mark[-2].no,NULL);
      }
#line 1975 "y.tab.c"
break;
case 63:
#line 511 "exptree.y"
	{
          yyval.no = makeTreeNode(NODE_WHILE,yystack.l_mark[-5].no,yystack.l_mark[-2].no,NULL);
      }
#line 1982 "y.tab.c"
break;
case 64:
#line 519 "exptree.y"
	{
          yyval.no = makeTreeNode(NODE_REPEAT,yystack.l_mark[-2].no,yystack.l_mark[-5].no,NULL);
      }
#line 1989 "y.tab.c"
break;
case 65:
#line 527 "exptree.y"
	{
          yyval.no = makeTreeNode(NODE_DOWHILE,yystack.l_mark[-2].no,yystack.l_mark[-5].no,NULL);
      }
#line 1996 "y.tab.c"
break;
case 66:
#line 539 "exptree.y"
	{
          yyval.no = makeReadNode(yystack.l_mark[-2].name);
      }
#line 2003 "y.tab.c"
break;
case 67:
#line 544 "exptree.y"
	{
          yyval.no = makeReadPointerNode(yystack.l_mark[-2].name);
      }
#line 2010 "y.tab.c"
break;
case 68:
#line 549 "exptree.y"
	{
          yyval.no = makeReadArrayNode(yystack.l_mark[-5].name,yystack.l_mark[-3].no);
      }
#line 2017 "y.tab.c"
break;
case 69:
#line 554 "exptree.y"
	{
          yyval.no = makeRead2DArrayNode(yystack.l_mark[-8].name,yystack.l_mark[-6].no,yystack.l_mark[-3].no);
      }
#line 2024 "y.tab.c"
break;
case 70:
#line 562 "exptree.y"
	{
          yyval.no = makeWriteNode(yystack.l_mark[-2].no);
      }
#line 2031 "y.tab.c"
break;
case 71:
#line 574 "exptree.y"
	{
          yyval.no = makeAssignmentNode(yystack.l_mark[-3].name,yystack.l_mark[-1].no);
      }
#line 2038 "y.tab.c"
break;
case 72:
#line 579 "exptree.y"
	{
          yyval.no = makePointerAssignmentNode(yystack.l_mark[-3].name,yystack.l_mark[-1].no);
      }
#line 2045 "y.tab.c"
break;
case 73:
#line 584 "exptree.y"
	{
          yyval.no = makeAssignmentArrayNode(yystack.l_mark[-6].name,yystack.l_mark[-4].no,yystack.l_mark[-1].no);
      }
#line 2052 "y.tab.c"
break;
case 74:
#line 589 "exptree.y"
	{
          yyval.no = makeAssignment2DArrayNode(yystack.l_mark[-9].name,yystack.l_mark[-7].no,yystack.l_mark[-4].no,yystack.l_mark[-1].no);
      }
#line 2059 "y.tab.c"
break;
case 75:
#line 601 "exptree.y"
	{
          yyval.no = makeBreakNode();
      }
#line 2066 "y.tab.c"
break;
case 76:
#line 609 "exptree.y"
	{
          yyval.no = makeContinueNode();
      }
#line 2073 "y.tab.c"
break;
case 77:
#line 621 "exptree.y"
	{
          yyval.no = makeOperatorNode('+',yystack.l_mark[-2].no,yystack.l_mark[0].no);
      }
#line 2080 "y.tab.c"
break;
case 78:
#line 626 "exptree.y"
	{
          yyval.no = makeOperatorNode('-',yystack.l_mark[-2].no,yystack.l_mark[0].no);
      }
#line 2087 "y.tab.c"
break;
case 79:
#line 631 "exptree.y"
	{
          yyval.no = makeOperatorNode('*',yystack.l_mark[-2].no,yystack.l_mark[0].no);
      }
#line 2094 "y.tab.c"
break;
case 80:
#line 636 "exptree.y"
	{
          yyval.no = makeOperatorNode('/',yystack.l_mark[-2].no,yystack.l_mark[0].no);
      }
#line 2101 "y.tab.c"
break;
case 81:
#line 641 "exptree.y"
	{
          yyval.no = makeOperatorNode('%',yystack.l_mark[-2].no,yystack.l_mark[0].no);
      }
#line 2108 "y.tab.c"
break;
case 82:
#line 646 "exptree.y"
	{
          yyval.no = makeOperatorNode('>',yystack.l_mark[-2].no,yystack.l_mark[0].no);
      }
#line 2115 "y.tab.c"
break;
case 83:
#line 651 "exptree.y"
	{
          yyval.no = makeOperatorNode('<',yystack.l_mark[-2].no,yystack.l_mark[0].no);
      }
#line 2122 "y.tab.c"
break;
case 84:
#line 656 "exptree.y"
	{
          yyval.no = makeOperatorNode('n',yystack.l_mark[-2].no,yystack.l_mark[0].no);
      }
#line 2129 "y.tab.c"
break;
case 85:
#line 661 "exptree.y"
	{
          yyval.no = makeOperatorNode('e',yystack.l_mark[-2].no,yystack.l_mark[0].no);
      }
#line 2136 "y.tab.c"
break;
case 86:
#line 666 "exptree.y"
	{
          yyval.no = makeOperatorNode('l',yystack.l_mark[-2].no,yystack.l_mark[0].no);
      }
#line 2143 "y.tab.c"
break;
case 87:
#line 671 "exptree.y"
	{
          yyval.no = makeOperatorNode('g',yystack.l_mark[-2].no,yystack.l_mark[0].no);
      }
#line 2150 "y.tab.c"
break;
case 88:
#line 676 "exptree.y"
	{
          yyval.no = yystack.l_mark[-1].no;
      }
#line 2157 "y.tab.c"
break;
case 89:
#line 681 "exptree.y"
	{
          yyval.no = yystack.l_mark[0].no;
      }
#line 2164 "y.tab.c"
break;
case 90:
#line 686 "exptree.y"
	{
          yyval.no = yystack.l_mark[0].no;
      }
#line 2171 "y.tab.c"
break;
case 91:
#line 691 "exptree.y"
	{
          yyval.no = make2DArrayNode(yystack.l_mark[-6].name,yystack.l_mark[-4].no,yystack.l_mark[-1].no);
      }
#line 2178 "y.tab.c"
break;
case 92:
#line 696 "exptree.y"
	{
          yyval.no = makeArrayNode(yystack.l_mark[-3].name,yystack.l_mark[-1].no);
      }
#line 2185 "y.tab.c"
break;
case 93:
#line 701 "exptree.y"
	{
          yyval.no = makeDeReferenceNode(yystack.l_mark[0].name);
      }
#line 2192 "y.tab.c"
break;
case 94:
#line 706 "exptree.y"
	{
          yyval.no = makeAddressNode(yystack.l_mark[0].name);
      }
#line 2199 "y.tab.c"
break;
case 95:
#line 711 "exptree.y"
	{
          yyval.no = makeVariableNode(yystack.l_mark[0].name);
      }
#line 2206 "y.tab.c"
break;
case 96:
#line 716 "exptree.y"
	{
          yyval.no = makeCallNode(yystack.l_mark[-3].name,yystack.l_mark[-1].no,countArguments(yystack.l_mark[-1].no));
      }
#line 2213 "y.tab.c"
break;
case 97:
#line 724 "exptree.y"
	{
          yyval.no = NULL;
      }
#line 2220 "y.tab.c"
break;
case 98:
#line 729 "exptree.y"
	{
          yyval.no = yystack.l_mark[0].no;
      }
#line 2227 "y.tab.c"
break;
case 99:
#line 734 "exptree.y"
	{
          yyval.no = makeConnectorNode(yystack.l_mark[-2].no,yystack.l_mark[0].no);
      }
#line 2234 "y.tab.c"
break;
#line 2236 "y.tab.c"
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
