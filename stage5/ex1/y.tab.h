#ifndef _yy_defines_h_
#define _yy_defines_h_

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
    Param* param;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;

#endif /* _yy_defines_h_ */
