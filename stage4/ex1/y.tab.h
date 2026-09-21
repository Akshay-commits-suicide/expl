#ifndef _yy_defines_h_
#define _yy_defines_h_

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
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union YYSTYPE {
	struct tnode* no;
	char* name;
	int type;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;

#endif /* _yy_defines_h_ */
