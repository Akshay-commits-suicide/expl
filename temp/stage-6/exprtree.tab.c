/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "exprtree.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exprtree.h"
#include "codegen.h"

int yylex();
void yyerror(const char* s);

tnode* root;

FILE* targetFile;
int nextFunctionLabel = 0;

#line 87 "exprtree.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "exprtree.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUM = 3,                        /* NUM  */
  YYSYMBOL_ID = 4,                         /* ID  */
  YYSYMBOL_PLUS = 5,                       /* PLUS  */
  YYSYMBOL_MINUS = 6,                      /* MINUS  */
  YYSYMBOL_MUL = 7,                        /* MUL  */
  YYSYMBOL_DIV = 8,                        /* DIV  */
  YYSYMBOL_MOD = 9,                        /* MOD  */
  YYSYMBOL_LT = 10,                        /* LT  */
  YYSYMBOL_GT = 11,                        /* GT  */
  YYSYMBOL_LE = 12,                        /* LE  */
  YYSYMBOL_GE = 13,                        /* GE  */
  YYSYMBOL_EQ = 14,                        /* EQ  */
  YYSYMBOL_NE = 15,                        /* NE  */
  YYSYMBOL_OR = 16,                        /* OR  */
  YYSYMBOL_AND = 17,                       /* AND  */
  YYSYMBOL_ADDRESS = 18,                   /* ADDRESS  */
  YYSYMBOL_TYPE = 19,                      /* TYPE  */
  YYSYMBOL_ENDTYPE = 20,                   /* ENDTYPE  */
  YYSYMBOL_ALLOC = 21,                     /* ALLOC  */
  YYSYMBOL_FREE = 22,                      /* FREE  */
  YYSYMBOL_T_NULL = 23,                    /* T_NULL  */
  YYSYMBOL_T_BEGIN = 24,                   /* T_BEGIN  */
  YYSYMBOL_T_END = 25,                     /* T_END  */
  YYSYMBOL_DECL = 26,                      /* DECL  */
  YYSYMBOL_ENDDECL = 27,                   /* ENDDECL  */
  YYSYMBOL_INT = 28,                       /* INT  */
  YYSYMBOL_STR = 29,                       /* STR  */
  YYSYMBOL_ASSIGN = 30,                    /* ASSIGN  */
  YYSYMBOL_SEMICOLON = 31,                 /* SEMICOLON  */
  YYSYMBOL_MAIN = 32,                      /* MAIN  */
  YYSYMBOL_RETURN = 33,                    /* RETURN  */
  YYSYMBOL_READ = 34,                      /* READ  */
  YYSYMBOL_WRITE = 35,                     /* WRITE  */
  YYSYMBOL_IF = 36,                        /* IF  */
  YYSYMBOL_THEN = 37,                      /* THEN  */
  YYSYMBOL_ELSE = 38,                      /* ELSE  */
  YYSYMBOL_ENDIF = 39,                     /* ENDIF  */
  YYSYMBOL_WHILE = 40,                     /* WHILE  */
  YYSYMBOL_DO = 41,                        /* DO  */
  YYSYMBOL_ENDWHILE = 42,                  /* ENDWHILE  */
  YYSYMBOL_REPEAT = 43,                    /* REPEAT  */
  YYSYMBOL_UNTIL = 44,                     /* UNTIL  */
  YYSYMBOL_BREAK = 45,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 46,                  /* CONTINUE  */
  YYSYMBOL_STRING = 47,                    /* STRING  */
  YYSYMBOL_UMINUS = 48,                    /* UMINUS  */
  YYSYMBOL_49_ = 49,                       /* '{'  */
  YYSYMBOL_50_ = 50,                       /* '}'  */
  YYSYMBOL_51_ = 51,                       /* ','  */
  YYSYMBOL_52_ = 52,                       /* '['  */
  YYSYMBOL_53_ = 53,                       /* ']'  */
  YYSYMBOL_54_ = 54,                       /* '('  */
  YYSYMBOL_55_ = 55,                       /* ')'  */
  YYSYMBOL_56_ = 56,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 57,                  /* $accept  */
  YYSYMBOL_Program = 58,                   /* Program  */
  YYSYMBOL_TypeDefBlock = 59,              /* TypeDefBlock  */
  YYSYMBOL_TypeDefList = 60,               /* TypeDefList  */
  YYSYMBOL_TypeDef = 61,                   /* TypeDef  */
  YYSYMBOL_62_1 = 62,                      /* $@1  */
  YYSYMBOL_FieldDeclList = 63,             /* FieldDeclList  */
  YYSYMBOL_FieldDecl = 64,                 /* FieldDecl  */
  YYSYMBOL_FieldType = 65,                 /* FieldType  */
  YYSYMBOL_GDeclBlock = 66,                /* GDeclBlock  */
  YYSYMBOL_GDeclList = 67,                 /* GDeclList  */
  YYSYMBOL_GDecl = 68,                     /* GDecl  */
  YYSYMBOL_TypeName = 69,                  /* TypeName  */
  YYSYMBOL_FType = 70,                     /* FType  */
  YYSYMBOL_VarList = 71,                   /* VarList  */
  YYSYMBOL_Variable = 72,                  /* Variable  */
  YYSYMBOL_Field = 73,                     /* Field  */
  YYSYMBOL_FDefBlock = 74,                 /* FDefBlock  */
  YYSYMBOL_FDef = 75,                      /* FDef  */
  YYSYMBOL_76_2 = 76,                      /* $@2  */
  YYSYMBOL_ParamList = 77,                 /* ParamList  */
  YYSYMBOL_Param = 78,                     /* Param  */
  YYSYMBOL_LdeclBlock = 79,                /* LdeclBlock  */
  YYSYMBOL_LDecList = 80,                  /* LDecList  */
  YYSYMBOL_LDecl = 81,                     /* LDecl  */
  YYSYMBOL_IdList = 82,                    /* IdList  */
  YYSYMBOL_ArgList = 83,                   /* ArgList  */
  YYSYMBOL_Body = 84,                      /* Body  */
  YYSYMBOL_ReturnStmt = 85,                /* ReturnStmt  */
  YYSYMBOL_MainBlock = 86,                 /* MainBlock  */
  YYSYMBOL_87_3 = 87,                      /* $@3  */
  YYSYMBOL_Slist = 88,                     /* Slist  */
  YYSYMBOL_Stmt = 89,                      /* Stmt  */
  YYSYMBOL_InputStmt = 90,                 /* InputStmt  */
  YYSYMBOL_OutputStmt = 91,                /* OutputStmt  */
  YYSYMBOL_AsgStmt = 92,                   /* AsgStmt  */
  YYSYMBOL_IfStmt = 93,                    /* IfStmt  */
  YYSYMBOL_WhileStmt = 94,                 /* WhileStmt  */
  YYSYMBOL_BreakStmt = 95,                 /* BreakStmt  */
  YYSYMBOL_ContinueStmt = 96,              /* ContinueStmt  */
  YYSYMBOL_RepeatStmt = 97,                /* RepeatStmt  */
  YYSYMBOL_DoWhileStmt = 98,               /* DoWhileStmt  */
  YYSYMBOL_E = 99                          /* E  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   608

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  121
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  280

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   303


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      54,    55,     2,     2,    51,     2,    56,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    52,     2,    53,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,     2,    50,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    92,    92,    93,    94,    97,    98,   101,   102,   105,
     105,   115,   116,   119,   130,   131,   132,   141,   141,   143,
     143,   145,   174,   175,   176,   186,   187,   203,   219,   231,
     246,   257,   273,   283,   296,   305,   324,   338,   351,   363,
     366,   370,   373,   378,   381,   386,   386,   388,   388,   397,
     407,   410,   414,   423,   436,   436,   438,   438,   440,   444,
     463,   474,   486,   494,   503,   517,   518,   521,   522,   524,
     527,   527,   549,   552,   556,   559,   562,   565,   568,   571,
     574,   577,   580,   583,   586,   589,   592,   596,   599,   604,
     608,   611,   616,   619,   623,   627,   631,   635,   639,   643,
     646,   649,   652,   655,   658,   661,   664,   667,   670,   673,
     676,   679,   682,   685,   688,   691,   694,   697,   700,   703,
     706,   709
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUM", "ID", "PLUS",
  "MINUS", "MUL", "DIV", "MOD", "LT", "GT", "LE", "GE", "EQ", "NE", "OR",
  "AND", "ADDRESS", "TYPE", "ENDTYPE", "ALLOC", "FREE", "T_NULL",
  "T_BEGIN", "T_END", "DECL", "ENDDECL", "INT", "STR", "ASSIGN",
  "SEMICOLON", "MAIN", "RETURN", "READ", "WRITE", "IF", "THEN", "ELSE",
  "ENDIF", "WHILE", "DO", "ENDWHILE", "REPEAT", "UNTIL", "BREAK",
  "CONTINUE", "STRING", "UMINUS", "'{'", "'}'", "','", "'['", "']'", "'('",
  "')'", "'.'", "$accept", "Program", "TypeDefBlock", "TypeDefList",
  "TypeDef", "$@1", "FieldDeclList", "FieldDecl", "FieldType",
  "GDeclBlock", "GDeclList", "GDecl", "TypeName", "FType", "VarList",
  "Variable", "Field", "FDefBlock", "FDef", "$@2", "ParamList", "Param",
  "LdeclBlock", "LDecList", "LDecl", "IdList", "ArgList", "Body",
  "ReturnStmt", "MainBlock", "$@3", "Slist", "Stmt", "InputStmt",
  "OutputStmt", "AsgStmt", "IfStmt", "WhileStmt", "BreakStmt",
  "ContinueStmt", "RepeatStmt", "DoWhileStmt", "E", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-116)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -18,    27,    58,    17,    14,     6,  -116,  -116,    68,    49,
      70,  -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,   120,
    -116,     9,    48,    49,    96,   128,    70,  -116,  -116,   221,
    -116,  -116,    71,   146,   -22,   108,  -116,   273,  -116,  -116,
    -116,  -116,  -116,    38,  -116,   170,   241,   223,   275,  -116,
      85,   281,   223,  -116,  -116,   300,   279,   113,   -14,  -116,
     223,   126,   329,  -116,    20,  -116,   282,  -116,   358,   223,
    -116,    35,   362,   223,   309,   340,  -116,   378,  -116,  -116,
    -116,   330,    80,   223,   124,   361,   338,   335,   339,  -116,
     121,  -116,   386,   219,  -116,   382,   342,   340,  -116,   390,
    -116,   350,   -17,  -116,  -116,   355,   130,   356,   123,   359,
     365,   366,   367,   473,   473,   381,   383,    -7,     0,   384,
     382,  -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,
    -116,  -116,   361,   371,   426,  -116,   427,   123,  -116,   217,
    -116,   274,   123,   130,  -116,  -116,   123,   374,   376,   537,
     130,   123,   123,   123,   495,   404,  -116,  -116,    47,   430,
     115,   431,  -116,   412,  -116,   391,  -116,   389,   394,   331,
     176,   374,    87,    29,  -116,  -116,   177,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
    -116,   174,   265,   190,   203,   254,   398,   399,   400,   550,
    -116,   402,   577,  -116,  -116,  -116,   405,   440,   407,   435,
     436,  -116,   171,   363,  -116,   316,   316,  -116,  -116,  -116,
     248,   248,   248,   248,   306,   306,   293,   228,   437,   445,
     447,   423,   420,   123,   123,   424,  -116,   428,  -116,   459,
     448,   123,  -116,  -116,   123,  -116,  -116,  -116,  -116,   473,
     473,   267,   280,   450,   453,   452,   441,   344,   363,   360,
     429,   -19,   457,  -116,  -116,  -116,   479,  -116,   473,   458,
     467,  -116,  -116,   462,   451,  -116,  -116,  -116,   469,  -116
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       6,     0,     0,     0,     0,     0,     8,     1,     0,     0,
       0,     4,     9,     5,     7,    24,    18,    22,    23,     0,
      20,     0,     0,    22,    25,     0,     0,    46,     3,     0,
      17,    19,    32,     0,     0,     0,    26,     0,    45,     2,
      16,    14,    15,     0,    12,     0,     0,    51,    34,    21,
       0,     0,    51,    10,    11,     0,     0,     0,     0,    50,
      51,    31,     0,    70,     0,    13,    30,    52,     0,     0,
      36,     0,     0,    51,    33,     0,    47,     0,    53,    49,
      38,     0,     0,    51,     0,     0,     0,     0,    29,    35,
       0,    55,     0,     0,    57,     0,     0,     0,    28,     0,
      37,    64,     0,    54,    56,    39,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    71,     0,     0,     0,    58,     0,     0,    42,     0,
     114,    39,     0,     0,   116,   115,     0,   118,   119,     0,
       0,     0,     0,     0,     0,     0,    95,    96,     0,     0,
       0,     0,    68,     0,    72,     0,    27,     0,    59,     0,
      39,     0,     0,     0,   104,   117,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      69,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      43,     0,     0,    44,    67,    48,    62,     0,    40,     0,
       0,   120,     0,    66,   105,    99,   100,   101,   102,   103,
     106,   107,   108,   109,   110,   111,   112,   113,     0,     0,
       0,     0,     0,     0,     0,     0,    90,     0,    91,     0,
       0,     0,    85,    86,     0,   121,    87,    88,    89,     0,
       0,     0,     0,     0,     0,     0,    60,     0,    65,     0,
       0,     0,     0,    83,    84,    63,     0,    41,     0,     0,
       0,    98,    97,     0,     0,    93,    94,    61,     0,    92
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -116,  -116,  -116,  -116,   498,  -116,  -116,   461,  -116,  -116,
    -116,   487,    -2,  -116,  -116,   -95,   -93,  -116,   484,  -116,
     -45,   442,   415,  -116,   432,  -116,  -116,   388,   401,    67,
    -116,  -110,  -115,  -116,  -116,  -116,  -116,  -116,  -116,  -116,
    -116,  -116,   -73
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     5,     6,    29,    43,    44,    45,    10,
      19,    20,    57,    25,    34,   147,   148,    26,    27,    86,
      58,    59,    85,    93,    94,   102,   212,    96,   119,    11,
      75,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   149
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     117,     1,   118,   154,   155,   164,    21,    64,    24,    49,
       4,   138,   271,    32,   135,    71,    33,    21,   117,   117,
     118,   118,   250,   158,    24,   117,    13,   118,    82,    50,
     160,     4,   140,   141,   136,   142,   106,    69,    90,   164,
     164,    70,    40,     8,   171,     9,   172,   143,   175,   159,
     140,   141,   144,   142,   106,   191,   161,   192,     7,   117,
     117,   118,   118,    12,   169,   143,    41,    42,   198,   174,
     144,    69,    15,   176,    15,    76,   145,    28,   193,   194,
     195,    22,    92,   146,   211,   199,    69,   202,    53,    61,
      80,    92,    62,    39,   145,    16,    17,    18,    23,    18,
     213,   146,    35,    36,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,    67,   140,   141,
      68,   142,   106,    46,    15,    47,   140,   141,    15,   142,
     106,    69,    37,   143,   105,    89,   201,   106,   144,   259,
     260,   143,   210,   161,   164,   164,   144,    30,    17,    18,
      48,    91,    17,    18,   117,   117,   118,   118,   274,   164,
     251,   252,   145,    51,   117,   117,   118,   118,   257,   146,
     145,   258,    69,   117,    55,   118,   100,   146,    72,   117,
      73,   118,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   170,   244,    15,   106,    40,   245,    15,   137,   228,
     159,   209,   214,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    56,   230,   103,    17,    18,    41,
      42,    17,    18,   177,   178,   179,   180,   181,   231,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   232,
     189,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     229,   161,   261,   179,   180,   181,   137,    52,   173,    60,
      63,    65,    66,    74,    77,   262,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,    78,    83,   105,    81,    84,   106,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,    87,   107,    88,   208,    95,   105,    97,    98,   106,
     101,    99,   131,   133,   109,   110,   111,   267,   268,   269,
     112,   113,   134,   114,   107,   115,   116,   137,   105,   162,
     139,   106,   156,   150,   157,   108,   109,   110,   111,   151,
     152,   153,   112,   113,   166,   114,   107,   115,   116,   167,
     159,   168,   161,   105,   200,   203,   106,   204,   109,   110,
     111,   205,   206,   240,   112,   113,   207,   114,   197,   115,
     116,   107,   233,   234,   235,   105,   237,   239,   106,   241,
     249,   250,   255,   109,   110,   111,   242,   243,   246,   112,
     113,   270,   114,   107,   115,   116,   247,   105,   248,   253,
     106,   263,   273,   254,   264,   109,   110,   111,   272,   275,
     278,   112,   113,   266,   114,   107,   115,   116,   276,   105,
     279,   256,   106,    14,    54,   265,    31,   109,   110,   111,
      38,    79,   132,   112,   113,   277,   114,   107,   115,   116,
     165,   163,     0,     0,     0,   104,     0,     0,     0,   109,
     110,   111,     0,     0,     0,   196,   113,     0,   114,     0,
     115,   116,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   236,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   238
};

static const yytype_int16 yycheck[] =
{
      95,    19,    95,   113,   114,   120,     8,    52,    10,    31,
       4,   106,    31,     4,    31,    60,     7,    19,   113,   114,
     113,   114,    41,    30,    26,   120,    20,   120,    73,    51,
      30,     4,     3,     4,    51,     6,     7,    51,    83,   154,
     155,    55,     4,    26,   139,    28,   139,    18,   143,    56,
       3,     4,    23,     6,     7,   150,    56,   150,     0,   154,
     155,   154,   155,    49,   137,    18,    28,    29,    21,   142,
      23,    51,     4,   146,     4,    55,    47,    10,   151,   152,
     153,    32,    84,    54,    55,   158,    51,   160,    50,     4,
      55,    93,     7,    26,    47,    27,    28,    29,    28,    29,
     173,    54,    54,     7,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,     4,     3,     4,
       7,     6,     7,    52,     4,    54,     3,     4,     4,     6,
       7,    51,     4,    18,     4,    55,    21,     7,    23,   249,
     250,    18,    55,    56,   259,   260,    23,    27,    28,    29,
       4,    27,    28,    29,   249,   250,   249,   250,   268,   274,
     233,   234,    47,    55,   259,   260,   259,   260,   241,    54,
      47,   244,    51,   268,     4,   268,    55,    54,    52,   274,
      54,   274,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,     4,    51,     4,     7,     4,    55,     4,    52,    55,
      56,    55,    55,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,     3,    55,    27,    28,    29,    28,
      29,    28,    29,     5,     6,     7,     8,     9,    55,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    55,
      17,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      55,    56,    55,     7,     8,     9,    52,    54,    54,    54,
      49,    31,    53,     4,    52,    55,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,     4,    54,     4,     3,    26,     7,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,     3,    22,    53,    53,    24,     4,    49,    53,     7,
       4,    52,    50,     3,    34,    35,    36,    53,    38,    39,
      40,    41,    52,    43,    22,    45,    46,    52,     4,    25,
      54,     7,    31,    54,    31,    33,    34,    35,    36,    54,
      54,    54,    40,    41,    53,    43,    22,    45,    46,     3,
      56,     4,    56,     4,     4,     4,     7,    25,    34,    35,
      36,    50,    53,     3,    40,    41,    52,    43,    44,    45,
      46,    22,    54,    54,    54,     4,    54,    52,     7,    52,
      37,    41,     3,    34,    35,    36,    31,    31,    31,    40,
      41,    42,    43,    22,    45,    46,    31,     4,    31,    55,
       7,    31,     3,    55,    31,    34,    35,    36,    31,    31,
      39,    40,    41,    52,    43,    22,    45,    46,    31,     4,
      31,    53,     7,     5,    43,    53,    19,    34,    35,    36,
      26,    69,    97,    40,    41,    53,    43,    22,    45,    46,
     132,   120,    -1,    -1,    -1,    93,    -1,    -1,    -1,    34,
      35,    36,    -1,    -1,    -1,    40,    41,    -1,    43,    -1,
      45,    46,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    19,    58,    59,     4,    60,    61,     0,    26,    28,
      66,    86,    49,    20,    61,     4,    27,    28,    29,    67,
      68,    69,    32,    28,    69,    70,    74,    75,    86,    62,
      27,    68,     4,     7,    71,    54,     7,     4,    75,    86,
       4,    28,    29,    63,    64,    65,    52,    54,     4,    31,
      51,    55,    54,    50,    64,     4,     3,    69,    77,    78,
      54,     4,     7,    49,    77,    31,    53,     4,     7,    51,
      55,    77,    52,    54,     4,    87,    55,    52,     4,    78,
      55,     3,    77,    54,    26,    79,    76,     3,    53,    55,
      77,    27,    69,    80,    81,    24,    84,    49,    53,    52,
      55,     4,    82,    27,    81,     4,     7,    22,    33,    34,
      35,    36,    40,    41,    43,    45,    46,    72,    73,    85,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    50,    79,     3,    52,    31,    51,    52,    72,    54,
       3,     4,     6,    18,    23,    47,    54,    72,    73,    99,
      54,    54,    54,    54,    88,    88,    31,    31,    30,    56,
      30,    56,    25,    85,    89,    84,    53,     3,     4,    99,
       4,    72,    73,    54,    99,    72,    99,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      31,    72,    73,    99,    99,    99,    40,    44,    21,    99,
       4,    21,    99,     4,    25,    50,    53,    52,    53,    55,
      55,    55,    83,    99,    55,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    55,    55,
      55,    55,    55,    54,    54,    54,    31,    54,    31,    52,
       3,    52,    31,    31,    51,    55,    31,    31,    31,    37,
      41,    99,    99,    55,    55,     3,    53,    99,    99,    88,
      88,    55,    55,    31,    31,    53,    52,    53,    38,    39,
      42,    31,    31,     3,    88,    31,    31,    53,    39,    31
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    57,    58,    58,    58,    59,    59,    60,    60,    62,
      61,    63,    63,    64,    65,    65,    65,    66,    66,    67,
      67,    68,    69,    69,    69,    70,    70,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    72,
      72,    72,    72,    73,    73,    74,    74,    76,    75,    77,
      77,    77,    78,    78,    79,    79,    80,    80,    81,    82,
      82,    82,    82,    82,    82,    83,    83,    84,    84,    85,
      87,    86,    88,    88,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    90,    90,    91,
      92,    92,    93,    93,    94,    95,    96,    97,    98,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,     2,     3,     0,     2,     1,     0,
       5,     2,     1,     3,     1,     1,     1,     3,     2,     2,
       1,     3,     1,     1,     1,     1,     2,     9,     7,     6,
       4,     3,     1,     4,     2,     6,     4,     7,     5,     1,
       4,     7,     2,     3,     3,     2,     1,     0,    10,     3,
       1,     0,     2,     3,     3,     2,     2,     1,     3,     3,
       6,     9,     4,     7,     1,     3,     1,     4,     3,     3,
       0,     9,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     6,     6,     5,     5,     5,     5,     5,
       4,     4,    10,     8,     8,     2,     2,     7,     7,     3,
       3,     3,     3,     3,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     2,     1,     1,
       3,     4
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Program: TypeDefBlock GDeclBlock FDefBlock MainBlock  */
#line 92 "exprtree.y"
                                                      { (yyval.node) = (yyvsp[0].node); }
#line 1422 "exprtree.tab.c"
    break;

  case 3: /* Program: TypeDefBlock GDeclBlock MainBlock  */
#line 93 "exprtree.y"
                                                      { (yyval.node) = (yyvsp[0].node); }
#line 1428 "exprtree.tab.c"
    break;

  case 4: /* Program: TypeDefBlock MainBlock  */
#line 94 "exprtree.y"
                                                      { (yyval.node) = (yyvsp[0].node); }
#line 1434 "exprtree.tab.c"
    break;

  case 9: /* $@1: %empty  */
#line 105 "exprtree.y"
                 {
            if (TBeginDefinition((yyvsp[-1].str)) == NULL) {
                fprintf(stderr, "Error: type '%s' is already defined or cannot be started\n", (yyvsp[-1].str));
                exit(1);
            }
        }
#line 1445 "exprtree.tab.c"
    break;

  case 10: /* TypeDef: ID '{' $@1 FieldDeclList '}'  */
#line 110 "exprtree.y"
                            {
            TFinishDefinition(TCurrentDefinition());
        }
#line 1453 "exprtree.tab.c"
    break;

  case 13: /* FieldDecl: FieldType ID SEMICOLON  */
#line 119 "exprtree.y"
                                   {
              Typetable *owner = TCurrentDefinition();
              if (owner == NULL ||
                  FInstall(owner, (yyvsp[-1].str), (yyvsp[-2].type), owner->size) == NULL) {
                  fprintf(stderr, "Error: duplicate field '%s' or invalid field declaration\n", (yyvsp[-1].str));
                  exit(1);
              }
              owner->size++;
          }
#line 1467 "exprtree.tab.c"
    break;

  case 14: /* FieldType: INT  */
#line 130 "exprtree.y"
                { (yyval.type) = TLookup("int"); }
#line 1473 "exprtree.tab.c"
    break;

  case 15: /* FieldType: STR  */
#line 131 "exprtree.y"
                { (yyval.type) = TLookup("str"); }
#line 1479 "exprtree.tab.c"
    break;

  case 16: /* FieldType: ID  */
#line 132 "exprtree.y"
               {
              (yyval.type) = TLookup((yyvsp[0].str));
              if ((yyval.type) == NULL || !IsUserDefinedType((yyval.type))) {
                  fprintf(stderr, "Error: field type '%s' is undefined or not declarable here\n", (yyvsp[0].str));
                  exit(1);
              }
          }
#line 1491 "exprtree.tab.c"
    break;

  case 21: /* GDecl: TypeName VarList SEMICOLON  */
#line 145 "exprtree.y"
                                   {
    // if i have like 
    // int a, b;
    // int c, d; (in two lines)
    // the varlist gon be like two diff linked lists, and each time reduction is done, we traverse thru
    VarList* temp = (yyvsp[-1].varlist);

    while (temp != NULL) {
        Typetable *varType = (yyvsp[-2].type);
        if (temp->isPointer) {
            varType = PointerType((yyvsp[-2].type));
            if (varType == NULL) {
                fprintf(stderr, "Error: pointer declarations are supported only for int and str\n");
                exit(1);
            }
        }

        if (temp->isFunction) {
            Install(temp->name, varType, 0, 0, 0, 0, temp->paramlist,
                    nextFunctionLabel++);
        } else {
            Install(temp->name, varType, temp->size, temp->rows, temp->cols,
                    temp->isArray,
                    NULL, -1);
        }
        temp = temp->next;
    }
}
#line 1524 "exprtree.tab.c"
    break;

  case 22: /* TypeName: INT  */
#line 174 "exprtree.y"
               { (yyval.type) = TLookup("int"); }
#line 1530 "exprtree.tab.c"
    break;

  case 23: /* TypeName: STR  */
#line 175 "exprtree.y"
               { (yyval.type) = TLookup("str"); }
#line 1536 "exprtree.tab.c"
    break;

  case 24: /* TypeName: ID  */
#line 176 "exprtree.y"
               {
             Typetable *resolvedType = TLookup((yyvsp[0].str));
             if (resolvedType == NULL || !IsUserDefinedType(resolvedType)) {
                 fprintf(stderr, "Error: type '%s' is not defined yet\n", (yyvsp[0].str));
                 exit(1);
             }
             (yyval.type) = resolvedType;
         }
#line 1549 "exprtree.tab.c"
    break;

  case 25: /* FType: TypeName  */
#line 186 "exprtree.y"
                 { (yyval.type) = (yyvsp[0].type); }
#line 1555 "exprtree.tab.c"
    break;

  case 26: /* FType: TypeName MUL  */
#line 187 "exprtree.y"
                     {
          (yyval.type) = PointerType((yyvsp[-1].type));
          if ((yyval.type) == NULL) {
              fprintf(stderr, "Error: pointer types are supported only for int and str\n");
              exit(1);
          }
      }
#line 1567 "exprtree.tab.c"
    break;

  case 27: /* VarList: VarList ',' ID '[' NUM ']' '[' NUM ']'  */
#line 203 "exprtree.y"
                                                 {
        VarList* newVar = calloc(1, sizeof(VarList));
        newVar->name = (yyvsp[-6].str);
        newVar->rows = (yyvsp[-4].num);
        newVar->cols = (yyvsp[-1].num);
        newVar->size = (yyvsp[-4].num) * (yyvsp[-1].num);
        newVar->isArray = 1;
        newVar->isPointer = 0;
        newVar->paramlist = NULL;
        newVar->next = NULL;

        VarList* temp = (yyvsp[-8].varlist);
        while (temp->next != NULL) temp = temp->next;
        temp->next = newVar;
        (yyval.varlist) = (yyvsp[-8].varlist);
    }
#line 1588 "exprtree.tab.c"
    break;

  case 28: /* VarList: ID '[' NUM ']' '[' NUM ']'  */
#line 219 "exprtree.y"
                                 { 
        VarList *newVar = calloc(1, sizeof(struct VarList));
        newVar->name = (yyvsp[-6].str);
        newVar->rows = (yyvsp[-4].num);
        newVar->cols = (yyvsp[-1].num);
        newVar->size = (yyvsp[-4].num) * (yyvsp[-1].num);
        newVar->isArray = 1;
        newVar->isPointer = 0;
        newVar->paramlist = NULL;
        newVar->next = NULL;
        (yyval.varlist) = newVar;
    }
#line 1605 "exprtree.tab.c"
    break;

  case 29: /* VarList: VarList ',' ID '[' NUM ']'  */
#line 231 "exprtree.y"
                                 { 
        VarList* newVar = calloc(1, sizeof(VarList));
        newVar->name = (yyvsp[-3].str);
        newVar->size = (yyvsp[-1].num); // array ayond size koduk
        newVar->rows = (yyvsp[-1].num);
        newVar->isArray = 1;
        newVar->isPointer = 0;
        newVar->paramlist = NULL;
        newVar->next = NULL;

        VarList* temp = (yyvsp[-5].varlist);
        while (temp->next != NULL) temp = temp->next;
        temp->next = newVar;
        (yyval.varlist) = (yyvsp[-5].varlist);
    }
#line 1625 "exprtree.tab.c"
    break;

  case 30: /* VarList: ID '[' NUM ']'  */
#line 246 "exprtree.y"
                     {
        VarList* newVar = calloc(1, sizeof(VarList));
        newVar->name = (yyvsp[-3].str);
        newVar->size = (yyvsp[-1].num);
        newVar->rows = (yyvsp[-1].num);
        newVar->isArray = 1;
        newVar->isPointer = 0;
        newVar->paramlist = NULL;
        newVar->next = NULL;
        (yyval.varlist) = newVar;
    }
#line 1641 "exprtree.tab.c"
    break;

  case 31: /* VarList: VarList ',' ID  */
#line 257 "exprtree.y"
                     {
        VarList* newVar = calloc(1, sizeof(VarList));
        newVar->name = (yyvsp[0].str);
        newVar->size = 1;
        newVar->isPointer = 0;
        newVar->paramlist = NULL;
        newVar->next = NULL;

        VarList* temp = (yyvsp[-2].varlist);
        while (temp->next) {
            temp = temp->next;
        }

        temp->next = newVar;
        (yyval.varlist) = (yyvsp[-2].varlist);
    }
#line 1662 "exprtree.tab.c"
    break;

  case 32: /* VarList: ID  */
#line 273 "exprtree.y"
         {
        VarList* newVar = calloc(1, sizeof(VarList));
        newVar->name = (yyvsp[0].str);
        newVar->size = 1;
        newVar->isPointer = 0;
        newVar->paramlist = NULL;
        newVar->next = NULL;

        (yyval.varlist) = newVar;
    }
#line 1677 "exprtree.tab.c"
    break;

  case 33: /* VarList: VarList ',' MUL ID  */
#line 283 "exprtree.y"
                         { // adds a pointer variable to the declaration list
        VarList* newVar = calloc(1, sizeof(VarList));
        newVar->name = (yyvsp[0].str);
        newVar->isPointer = 1;
        newVar->size = 1;
        newVar->paramlist = NULL;
        newVar->next = NULL;
        
        VarList *temp = (yyvsp[-3].varlist);
        while (temp->next != NULL) temp = temp->next;
        temp->next = newVar;
        (yyval.varlist) = (yyvsp[-3].varlist);
    }
#line 1695 "exprtree.tab.c"
    break;

  case 34: /* VarList: MUL ID  */
#line 296 "exprtree.y"
             {
        VarList *newVar = calloc(1, sizeof(VarList));
        newVar->name = (yyvsp[0].str);
        newVar->isPointer = 1;
        newVar->size = 1;
        newVar->paramlist = NULL;
        newVar->next = NULL;
        (yyval.varlist) = newVar;
    }
#line 1709 "exprtree.tab.c"
    break;

  case 35: /* VarList: VarList ',' ID '(' ParamList ')'  */
#line 305 "exprtree.y"
                                     {
        VarList *newVar = calloc(1, sizeof(VarList));

        newVar->name = (yyvsp[-3].str);
        newVar->size = 1;
        newVar->rows = 0;
        newVar->cols = 0;
        newVar->isPointer = 0;
        newVar->isFunction = 1;
        newVar->paramlist = (yyvsp[-1].paramlist);
        newVar->next = NULL;

        VarList *temp = (yyvsp[-5].varlist);
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newVar;
        (yyval.varlist) = (yyvsp[-5].varlist);
    }
#line 1733 "exprtree.tab.c"
    break;

  case 36: /* VarList: ID '(' ParamList ')'  */
#line 324 "exprtree.y"
                        {
        VarList *newVar = calloc(1, sizeof(VarList));

        newVar->name = (yyvsp[-3].str);
        newVar->size = 1;
        newVar->rows = 0;
        newVar->cols = 0;
        newVar->isPointer = 0;
        newVar->isFunction = 1;
        newVar->paramlist = (yyvsp[-1].paramlist);
        newVar->next = NULL;

        (yyval.varlist) = newVar;
    }
#line 1752 "exprtree.tab.c"
    break;

  case 37: /* VarList: VarList ',' MUL ID '(' ParamList ')'  */
#line 338 "exprtree.y"
                                           {
        VarList *newVar = calloc(1, sizeof(VarList));
        VarList *tail = (yyvsp[-6].varlist);

        newVar->name = (yyvsp[-3].str);
        newVar->isPointer = 1;
        newVar->isFunction = 1;
        newVar->paramlist = (yyvsp[-1].paramlist);

        while (tail->next != NULL) tail = tail->next;
        tail->next = newVar;
        (yyval.varlist) = (yyvsp[-6].varlist);
    }
#line 1770 "exprtree.tab.c"
    break;

  case 38: /* VarList: MUL ID '(' ParamList ')'  */
#line 351 "exprtree.y"
                               {
        VarList *newVar = calloc(1, sizeof(VarList));

        newVar->name = (yyvsp[-3].str);
        newVar->isPointer = 1;
        newVar->isFunction = 1;
        newVar->paramlist = (yyvsp[-1].paramlist);
        (yyval.varlist) = newVar;
    }
#line 1784 "exprtree.tab.c"
    break;

  case 39: /* Variable: ID  */
#line 363 "exprtree.y"
              {
        (yyval.node) = makeIdNode((yyvsp[0].str));
    }
#line 1792 "exprtree.tab.c"
    break;

  case 40: /* Variable: ID '[' E ']'  */
#line 366 "exprtree.y"
                   { // this is strictly for accessing array elements only, not declaration
        // also E aayond we can do like arr[i + 5 * 8] lol
        (yyval.node) = makeArrayNode((yyvsp[-3].str), (yyvsp[-1].node));
    }
#line 1801 "exprtree.tab.c"
    break;

  case 41: /* Variable: ID '[' E ']' '[' E ']'  */
#line 370 "exprtree.y"
                             {
        (yyval.node) = makeArray2DNode((yyvsp[-6].str), (yyvsp[-4].node), (yyvsp[-1].node));
    }
#line 1809 "exprtree.tab.c"
    break;

  case 42: /* Variable: MUL Variable  */
#line 373 "exprtree.y"
                   { // allows a dereferenced pointer as an assignment target
        (yyval.node) = makeDereferenceNode((yyvsp[0].node));
    }
#line 1817 "exprtree.tab.c"
    break;

  case 43: /* Field: Variable '.' ID  */
#line 378 "exprtree.y"
                        {
            (yyval.node) = makeFieldNode((yyvsp[-2].node), (yyvsp[0].str));
        }
#line 1825 "exprtree.tab.c"
    break;

  case 44: /* Field: Field '.' ID  */
#line 381 "exprtree.y"
                    {
            (yyval.node) = makeFieldNode((yyvsp[-2].node), (yyvsp[0].str));
        }
#line 1833 "exprtree.tab.c"
    break;

  case 47: /* $@2: %empty  */
#line 388 "exprtree.y"
                               {
        CheckFunctionDefinition((yyvsp[-3].str), (yyvsp[-4].type), (yyvsp[-1].paramlist));
        BeginFunctionScope((yyvsp[-1].paramlist));
    }
#line 1842 "exprtree.tab.c"
    break;

  case 48: /* FDef: FType ID '(' ParamList ')' $@2 '{' LdeclBlock Body '}'  */
#line 391 "exprtree.y"
                              {
        SaveFunctionAST((yyvsp[-8].str), finalizeBodyNode((yyvsp[-1].node), (yyvsp[-9].type), (yyvsp[-8].str)), 0);
        PrintLocalSymbolTable((yyvsp[-8].str));
        EndFunctionScope();
    }
#line 1852 "exprtree.tab.c"
    break;

  case 49: /* ParamList: ParamList ',' Param  */
#line 397 "exprtree.y"
                                {
        Paramstruct *temp = (yyvsp[-2].paramlist);

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = (yyvsp[0].paramlist);
        (yyval.paramlist) = (yyvsp[-2].paramlist);
    }
#line 1867 "exprtree.tab.c"
    break;

  case 50: /* ParamList: Param  */
#line 407 "exprtree.y"
            {
        (yyval.paramlist) = (yyvsp[0].paramlist);
    }
#line 1875 "exprtree.tab.c"
    break;

  case 51: /* ParamList: %empty  */
#line 410 "exprtree.y"
      { // param can be empty
        (yyval.paramlist) = NULL;
    }
#line 1883 "exprtree.tab.c"
    break;

  case 52: /* Param: TypeName ID  */
#line 414 "exprtree.y"
                    {
        Paramstruct *p = malloc(sizeof(Paramstruct));

        p->name = (yyvsp[0].str);
        p->type = (yyvsp[-1].type);
        p->next = NULL;

        (yyval.paramlist) = p;
    }
#line 1897 "exprtree.tab.c"
    break;

  case 53: /* Param: TypeName MUL ID  */
#line 423 "exprtree.y"
                      {
        Paramstruct *p = malloc(sizeof(Paramstruct));

        p->name = (yyvsp[0].str);
        p->type = PointerType((yyvsp[-2].type));
        if (p->type == NULL) {
            fprintf(stderr, "Error: pointer parameters are supported only for int and str\n");
            exit(1);
        }
        p->next = NULL;
        (yyval.paramlist) = p;
    }
#line 1914 "exprtree.tab.c"
    break;

  case 58: /* LDecl: TypeName IdList SEMICOLON  */
#line 440 "exprtree.y"
                                  {
        InstallLocalVariables((yyvsp[-1].varlist), (yyvsp[-2].type));
    }
#line 1922 "exprtree.tab.c"
    break;

  case 59: /* IdList: IdList ',' ID  */
#line 444 "exprtree.y"
                       {
        VarList* newNode = calloc(1, sizeof(VarList));

        newNode->name = strdup((yyvsp[0].str));
        newNode->size = 1;
        newNode->rows = 0;
        newNode->cols = 0;
        newNode->isPointer = 0;
        newNode->next = NULL;

        VarList *temp = (yyvsp[-2].varlist);

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
        (yyval.varlist) = (yyvsp[-2].varlist);
    }
#line 1946 "exprtree.tab.c"
    break;

  case 60: /* IdList: IdList ',' ID '[' NUM ']'  */
#line 463 "exprtree.y"
                                {
        VarList *newNode = calloc(1, sizeof(VarList));
        VarList *tail = (yyvsp[-5].varlist);
        newNode->name = strdup((yyvsp[-3].str));
        newNode->size = (yyvsp[-1].num);
        newNode->rows = (yyvsp[-1].num);
        newNode->isArray = 1;
        while (tail->next != NULL) tail = tail->next;
        tail->next = newNode;
        (yyval.varlist) = (yyvsp[-5].varlist);
    }
#line 1962 "exprtree.tab.c"
    break;

  case 61: /* IdList: IdList ',' ID '[' NUM ']' '[' NUM ']'  */
#line 474 "exprtree.y"
                                            {
        VarList *newNode = calloc(1, sizeof(VarList));
        VarList *tail = (yyvsp[-8].varlist);
        newNode->name = strdup((yyvsp[-6].str));
        newNode->rows = (yyvsp[-4].num);
        newNode->cols = (yyvsp[-1].num);
        newNode->size = (yyvsp[-4].num) * (yyvsp[-1].num);
        newNode->isArray = 1;
        while (tail->next != NULL) tail = tail->next;
        tail->next = newNode;
        (yyval.varlist) = (yyvsp[-8].varlist);
    }
#line 1979 "exprtree.tab.c"
    break;

  case 62: /* IdList: ID '[' NUM ']'  */
#line 486 "exprtree.y"
                     {
        VarList *newNode = calloc(1, sizeof(VarList));
        newNode->name = strdup((yyvsp[-3].str));
        newNode->size = (yyvsp[-1].num);
        newNode->rows = (yyvsp[-1].num);
        newNode->isArray = 1;
        (yyval.varlist) = newNode;
    }
#line 1992 "exprtree.tab.c"
    break;

  case 63: /* IdList: ID '[' NUM ']' '[' NUM ']'  */
#line 494 "exprtree.y"
                                 {
        VarList *newNode = calloc(1, sizeof(VarList));
        newNode->name = strdup((yyvsp[-6].str));
        newNode->rows = (yyvsp[-4].num);
        newNode->cols = (yyvsp[-1].num);
        newNode->size = (yyvsp[-4].num) * (yyvsp[-1].num);
        newNode->isArray = 1;
        (yyval.varlist) = newNode;
    }
#line 2006 "exprtree.tab.c"
    break;

  case 64: /* IdList: ID  */
#line 503 "exprtree.y"
         {
        VarList* newNode = calloc(1, sizeof(VarList));

        newNode->name = strdup((yyvsp[0].str));
        newNode->size = 1;
        newNode->rows = 0;
        newNode->cols = 0;
        newNode->isPointer = 0;
        newNode->next = NULL;

        (yyval.varlist) = newNode;
    }
#line 2023 "exprtree.tab.c"
    break;

  case 65: /* ArgList: ArgList ',' E  */
#line 517 "exprtree.y"
                        { (yyval.node) = appendArgNode((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2029 "exprtree.tab.c"
    break;

  case 66: /* ArgList: E  */
#line 518 "exprtree.y"
                        { (yyval.node) = makeArgListNode((yyvsp[0].node)); }
#line 2035 "exprtree.tab.c"
    break;

  case 67: /* Body: T_BEGIN Slist ReturnStmt T_END  */
#line 521 "exprtree.y"
                                      { (yyval.node) = makeBodyNode((yyvsp[-2].node), (yyvsp[-1].node)); }
#line 2041 "exprtree.tab.c"
    break;

  case 68: /* Body: T_BEGIN ReturnStmt T_END  */
#line 522 "exprtree.y"
                                      { (yyval.node) = makeBodyNode(NULL, (yyvsp[-1].node)); }
#line 2047 "exprtree.tab.c"
    break;

  case 69: /* ReturnStmt: RETURN E SEMICOLON  */
#line 524 "exprtree.y"
                                { (yyval.node) = makeReturnNode((yyvsp[-1].node)); }
#line 2053 "exprtree.tab.c"
    break;

  case 70: /* $@3: %empty  */
#line 527 "exprtree.y"
                                 {
        BeginFunctionScope(NULL);
    }
#line 2061 "exprtree.tab.c"
    break;

  case 71: /* MainBlock: INT MAIN '(' ')' '{' $@3 LdeclBlock Body '}'  */
#line 529 "exprtree.y"
                          {
        root = finalizeBodyNode((yyvsp[-1].node), TLookup("int"), "main");
        SaveFunctionAST("main", root, 1);
        PrintLocalSymbolTable("main");
        EndFunctionScope();
        (yyval.node) = NULL;
    }
#line 2073 "exprtree.tab.c"
    break;

  case 72: /* Slist: Slist Stmt  */
#line 549 "exprtree.y"
                   {
        (yyval.node) = makeConnectorNode((yyvsp[-1].node), (yyvsp[0].node));
    }
#line 2081 "exprtree.tab.c"
    break;

  case 73: /* Slist: Stmt  */
#line 552 "exprtree.y"
           {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2089 "exprtree.tab.c"
    break;

  case 74: /* Stmt: InputStmt  */
#line 556 "exprtree.y"
                 {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2097 "exprtree.tab.c"
    break;

  case 75: /* Stmt: OutputStmt  */
#line 559 "exprtree.y"
                 {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2105 "exprtree.tab.c"
    break;

  case 76: /* Stmt: AsgStmt  */
#line 562 "exprtree.y"
              {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2113 "exprtree.tab.c"
    break;

  case 77: /* Stmt: IfStmt  */
#line 565 "exprtree.y"
             {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2121 "exprtree.tab.c"
    break;

  case 78: /* Stmt: WhileStmt  */
#line 568 "exprtree.y"
                {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2129 "exprtree.tab.c"
    break;

  case 79: /* Stmt: BreakStmt  */
#line 571 "exprtree.y"
                {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2137 "exprtree.tab.c"
    break;

  case 80: /* Stmt: ContinueStmt  */
#line 574 "exprtree.y"
                   {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2145 "exprtree.tab.c"
    break;

  case 81: /* Stmt: RepeatStmt  */
#line 577 "exprtree.y"
                 {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2153 "exprtree.tab.c"
    break;

  case 82: /* Stmt: DoWhileStmt  */
#line 580 "exprtree.y"
                  {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2161 "exprtree.tab.c"
    break;

  case 83: /* Stmt: Variable ASSIGN ALLOC '(' ')' SEMICOLON  */
#line 583 "exprtree.y"
                                              {
        (yyval.node) = makeAllocNode((yyvsp[-5].node));
    }
#line 2169 "exprtree.tab.c"
    break;

  case 84: /* Stmt: Field ASSIGN ALLOC '(' ')' SEMICOLON  */
#line 586 "exprtree.y"
                                           {
        (yyval.node) = makeAllocNode((yyvsp[-5].node));
    }
#line 2177 "exprtree.tab.c"
    break;

  case 85: /* Stmt: FREE '(' ID ')' SEMICOLON  */
#line 589 "exprtree.y"
                                {
        (yyval.node) = makeFreeNode(makeIdNode((yyvsp[-2].str)));
    }
#line 2185 "exprtree.tab.c"
    break;

  case 86: /* Stmt: FREE '(' Field ')' SEMICOLON  */
#line 592 "exprtree.y"
                                   {
        (yyval.node) = makeFreeNode((yyvsp[-2].node));
    }
#line 2193 "exprtree.tab.c"
    break;

  case 87: /* InputStmt: READ '(' Variable ')' SEMICOLON  */
#line 596 "exprtree.y"
                                            { // u read into a var, like read(b);
        (yyval.node) = makeReadNode((yyvsp[-2].node));
    }
#line 2201 "exprtree.tab.c"
    break;

  case 88: /* InputStmt: READ '(' Field ')' SEMICOLON  */
#line 599 "exprtree.y"
                                   {
        (yyval.node) = makeReadNode((yyvsp[-2].node));
    }
#line 2209 "exprtree.tab.c"
    break;

  case 89: /* OutputStmt: WRITE '(' E ')' SEMICOLON  */
#line 604 "exprtree.y"
                                       { // u can write an expression like write(5+8);
        (yyval.node) = makeWriteNode((yyvsp[-2].node));
    }
#line 2217 "exprtree.tab.c"
    break;

  case 90: /* AsgStmt: Variable ASSIGN E SEMICOLON  */
#line 608 "exprtree.y"
                                      {
        (yyval.node) = makeAssignNode((yyvsp[-3].node), (yyvsp[-1].node));
    }
#line 2225 "exprtree.tab.c"
    break;

  case 91: /* AsgStmt: Field ASSIGN E SEMICOLON  */
#line 611 "exprtree.y"
                               {
        (yyval.node) = makeAssignNode((yyvsp[-3].node), (yyvsp[-1].node));
    }
#line 2233 "exprtree.tab.c"
    break;

  case 92: /* IfStmt: IF '(' E ')' THEN Slist ELSE Slist ENDIF SEMICOLON  */
#line 616 "exprtree.y"
                                                            {
        (yyval.node) = makeIfNode((yyvsp[-7].node), (yyvsp[-4].node), (yyvsp[-2].node));
    }
#line 2241 "exprtree.tab.c"
    break;

  case 93: /* IfStmt: IF '(' E ')' THEN Slist ENDIF SEMICOLON  */
#line 619 "exprtree.y"
                                              {
        (yyval.node) = makeIfNode((yyvsp[-5].node), (yyvsp[-2].node), NULL);
    }
#line 2249 "exprtree.tab.c"
    break;

  case 94: /* WhileStmt: WHILE '(' E ')' DO Slist ENDWHILE SEMICOLON  */
#line 623 "exprtree.y"
                                                        {
        (yyval.node) = makeWhileNode((yyvsp[-5].node), (yyvsp[-2].node));        
    }
#line 2257 "exprtree.tab.c"
    break;

  case 95: /* BreakStmt: BREAK SEMICOLON  */
#line 627 "exprtree.y"
                            {
        (yyval.node) = makeBreakNode();
    }
#line 2265 "exprtree.tab.c"
    break;

  case 96: /* ContinueStmt: CONTINUE SEMICOLON  */
#line 631 "exprtree.y"
                                  {
        (yyval.node) = makeContinueNode();
    }
#line 2273 "exprtree.tab.c"
    break;

  case 97: /* RepeatStmt: REPEAT Slist UNTIL '(' E ')' SEMICOLON  */
#line 635 "exprtree.y"
                                                    {
        (yyval.node) = makeRepeatNode((yyvsp[-5].node), (yyvsp[-2].node));
    }
#line 2281 "exprtree.tab.c"
    break;

  case 98: /* DoWhileStmt: DO Slist WHILE '(' E ')' SEMICOLON  */
#line 639 "exprtree.y"
                                                 {
        (yyval.node) = makeDoWhileNode((yyvsp[-5].node), (yyvsp[-2].node));
    }
#line 2289 "exprtree.tab.c"
    break;

  case 99: /* E: E PLUS E  */
#line 643 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode("+", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2297 "exprtree.tab.c"
    break;

  case 100: /* E: E MINUS E  */
#line 646 "exprtree.y"
                {
        (yyval.node) = makeOperatorNode("-", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2305 "exprtree.tab.c"
    break;

  case 101: /* E: E MUL E  */
#line 649 "exprtree.y"
              {
        (yyval.node) = makeOperatorNode("*", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2313 "exprtree.tab.c"
    break;

  case 102: /* E: E DIV E  */
#line 652 "exprtree.y"
              {
        (yyval.node) = makeOperatorNode("/", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2321 "exprtree.tab.c"
    break;

  case 103: /* E: E MOD E  */
#line 655 "exprtree.y"
              {
        (yyval.node) = makeOperatorNode("%", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2329 "exprtree.tab.c"
    break;

  case 104: /* E: MINUS E  */
#line 658 "exprtree.y"
                           {
        (yyval.node) = makeOperatorNode("-", makeNumNode(0), (yyvsp[0].node));
    }
#line 2337 "exprtree.tab.c"
    break;

  case 105: /* E: '(' E ')'  */
#line 661 "exprtree.y"
                {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2345 "exprtree.tab.c"
    break;

  case 106: /* E: E LT E  */
#line 664 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode("<", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2353 "exprtree.tab.c"
    break;

  case 107: /* E: E GT E  */
#line 667 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode(">", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2361 "exprtree.tab.c"
    break;

  case 108: /* E: E LE E  */
#line 670 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode("<=", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2369 "exprtree.tab.c"
    break;

  case 109: /* E: E GE E  */
#line 673 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode(">=", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2377 "exprtree.tab.c"
    break;

  case 110: /* E: E EQ E  */
#line 676 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode("==", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2385 "exprtree.tab.c"
    break;

  case 111: /* E: E NE E  */
#line 679 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode("!=", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2393 "exprtree.tab.c"
    break;

  case 112: /* E: E OR E  */
#line 682 "exprtree.y"
             {
        (yyval.node) = makeOperatorNode("||", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2401 "exprtree.tab.c"
    break;

  case 113: /* E: E AND E  */
#line 685 "exprtree.y"
              {
        (yyval.node) = makeOperatorNode("&&", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2409 "exprtree.tab.c"
    break;

  case 114: /* E: NUM  */
#line 688 "exprtree.y"
          {
        (yyval.node) = makeNumNode((yyvsp[0].num));
    }
#line 2417 "exprtree.tab.c"
    break;

  case 115: /* E: STRING  */
#line 691 "exprtree.y"
             {
        (yyval.node) = makeStrNode((yyvsp[0].str));
    }
#line 2425 "exprtree.tab.c"
    break;

  case 116: /* E: T_NULL  */
#line 694 "exprtree.y"
             {
        (yyval.node) = makeNullNode();
    }
#line 2433 "exprtree.tab.c"
    break;

  case 117: /* E: ADDRESS Variable  */
#line 697 "exprtree.y"
                       { // address-of operator returns the address of a variable
        (yyval.node) = makeAddressNode((yyvsp[0].node));
    }
#line 2441 "exprtree.tab.c"
    break;

  case 118: /* E: Variable  */
#line 700 "exprtree.y"
               {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2449 "exprtree.tab.c"
    break;

  case 119: /* E: Field  */
#line 703 "exprtree.y"
            {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2457 "exprtree.tab.c"
    break;

  case 120: /* E: ID '(' ')'  */
#line 706 "exprtree.y"
               {
        (yyval.node) = makeFunctionCallNode((yyvsp[-2].str), NULL);
    }
#line 2465 "exprtree.tab.c"
    break;

  case 121: /* E: ID '(' ArgList ')'  */
#line 709 "exprtree.y"
                      {
        (yyval.node) = makeFunctionCallNode((yyvsp[-3].str), (yyvsp[-1].node));
    }
#line 2473 "exprtree.tab.c"
    break;


#line 2477 "exprtree.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 713 "exprtree.y"


extern FILE* yyin; // it is file pointer of lexer. defaulted to "stdin"
int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <inputfile>\n", argv[0]);
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (yyin == NULL) {
        printf("Cannot open input file\n");
        return 1;
    }

    TypeTableCreate();
    if (yyparse() != 0) {
        fclose(yyin);
        return 1;
    }

    PrintTypeTable();
    PrintSymbolTable();
    targetFile = fopen("target.xsm", "w");
    if (targetFile == NULL) {
        fprintf(stderr, "Could not open target.xsm for writing\n");
        fclose(yyin);
        return 1;
    }
    generateProgram(FunctionASTHead);
    fclose(targetFile);
    fclose(yyin);
    return 0;
}

void yyerror(const char* s) {
    printf("%s\n", s);
}
