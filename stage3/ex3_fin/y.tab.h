#ifndef _yy_defines_h_
#define _yy_defines_h_

#define NUM 257
#define ID 258
#define TBEGIN 259
#define END 260
#define WRITE 261
#define READ 262
#define IF 263
#define THEN 264
#define ELSE 265
#define WHILE 266
#define DO 267
#define ENDIF 268
#define ENDWHILE 269
#define UNTILL 270
#define REPEAT 271
#define BREAK 272
#define CONTINUE 273
#define NE 274
#define EQ 275
#define LE 276
#define GE 277
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union YYSTYPE {
	struct tnode* no;
	char* name;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;

#endif /* _yy_defines_h_ */
