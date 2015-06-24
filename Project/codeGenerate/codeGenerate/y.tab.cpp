/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "cd_yacc_cgen.y" /* yacc.c:339  */

    #define UC 
	#include "cd_yacc_node.h"
#ifdef UC
        #include "./Project/codeGenerate/codeGenerate/codeGenerate.h"
#endif
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <iostream>
        #include <vector>
        #include <string>
        #define YYSTYPE char*
        using namespace std;


        extern int line_no;
	    program_s program;
        bool finished = false;

        extern "C"{
              int yyerror(const char *s);
              extern int yylex(void);
        }

        inline int str2int(const string& str)
        {
            int ret(0);
            int len(str.length());
            for(int i = 0;i < len;++i)
            {
                if('0'<=str[i]&&str[i]<='9')
                    ret += str[i]-'0';
                else
                    yyerror("invalid convertion from string to int");
                ret *= 10;
            }
            return ret/10;
        }

        inline char str2char(const string& str)
        {
            if(str.length()!=1)
            {
                yyerror("invalid convertion from string to char");
                return '\0';
            }
            return str[0];
        }

#line 117 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    _LP = 258,
    _RP = 259,
    _LB = 260,
    _RB = 261,
    _DOT = 262,
    _COLON = 263,
    _COMMA = 264,
    _SEMI = 265,
    _MOD = 266,
    _MUL = 267,
    _PLUS = 268,
    _GE = 269,
    _GT = 270,
    _LE = 271,
    _LT = 272,
    _EQUAL = 273,
    _DIV = 274,
    _ASSIGN = 275,
    _SYS_FUNC = 276,
    _SYS_PROC = 277,
    _SYS_CON = 278,
    _SYS_TYPE = 279,
    _UNEQUAL = 280,
    _DO = 281,
    _TO = 282,
    _IF = 283,
    _OR = 284,
    _OF = 285,
    _END = 286,
    _FOR = 287,
    _VAR = 288,
    _NOT = 289,
    _AND = 290,
    _ELSE = 291,
    _READ = 292,
    _CASE = 293,
    _THEN = 294,
    _GOTO = 295,
    _ARRAY = 296,
    _BEGIN = 297,
    _UNTIL = 298,
    _WHILE = 299,
    _CONST = 300,
    _REPEAT = 301,
    _RECORD = 302,
    _DOWNTO = 303,
    _PROGRAM = 304,
    _PROCEDURE = 305,
    _FUNCTION = 306,
    _ID = 307,
    _INTEGER_NUM = 308,
    _REAL_NUM = 309,
    _CHAR_NUM = 310,
    _STRING_NUM = 311,
    _MINUS = 312,
    _TYPE = 313
  };
#endif
/* Tokens.  */
#define _LP 258
#define _RP 259
#define _LB 260
#define _RB 261
#define _DOT 262
#define _COLON 263
#define _COMMA 264
#define _SEMI 265
#define _MOD 266
#define _MUL 267
#define _PLUS 268
#define _GE 269
#define _GT 270
#define _LE 271
#define _LT 272
#define _EQUAL 273
#define _DIV 274
#define _ASSIGN 275
#define _SYS_FUNC 276
#define _SYS_PROC 277
#define _SYS_CON 278
#define _SYS_TYPE 279
#define _UNEQUAL 280
#define _DO 281
#define _TO 282
#define _IF 283
#define _OR 284
#define _OF 285
#define _END 286
#define _FOR 287
#define _VAR 288
#define _NOT 289
#define _AND 290
#define _ELSE 291
#define _READ 292
#define _CASE 293
#define _THEN 294
#define _GOTO 295
#define _ARRAY 296
#define _BEGIN 297
#define _UNTIL 298
#define _WHILE 299
#define _CONST 300
#define _REPEAT 301
#define _RECORD 302
#define _DOWNTO 303
#define _PROGRAM 304
#define _PROCEDURE 305
#define _FUNCTION 306
#define _ID 307
#define _INTEGER_NUM 308
#define _REAL_NUM 309
#define _CHAR_NUM 310
#define _STRING_NUM 311
#define _MINUS 312
#define _TYPE 313

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 284 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   331

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  122
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  257

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   313

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    60,    60,    67,    72,    78,    85,    92,    95,   101,
     107,   111,   115,   120,   126,   132,   134,   138,   143,   148,
     154,   160,   166,   171,   178,   186,   212,   226,   240,   249,
     255,   262,   267,   272,   279,   284,   290,   297,   301,   306,
     312,   320,   326,   332,   339,   344,   349,   355,   363,   369,
     376,   383,   387,   392,   398,   405,   412,   417,   422,   428,
     438,   443,   446,   453,   460,   473,   486,   499,   512,   525,
     538,   551,   564,   579,   589,   599,   610,   618,   626,   634,
     642,   651,   658,   661,   664,   673,   679,   689,   692,   697,
     706,   710,   716,   722,   729,   734,   740,   746,   752,   758,
     764,   770,   778,   784,   790,   796,   804,   810,   816,   822,
     828,   836,   847,   858,   869,   880,   890,   900,   910,   920,
     930,   942,   946
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_LP", "_RP", "_LB", "_RB", "_DOT",
  "_COLON", "_COMMA", "_SEMI", "_MOD", "_MUL", "_PLUS", "_GE", "_GT",
  "_LE", "_LT", "_EQUAL", "_DIV", "_ASSIGN", "_SYS_FUNC", "_SYS_PROC",
  "_SYS_CON", "_SYS_TYPE", "_UNEQUAL", "_DO", "_TO", "_IF", "_OR", "_OF",
  "_END", "_FOR", "_VAR", "_NOT", "_AND", "_ELSE", "_READ", "_CASE",
  "_THEN", "_GOTO", "_ARRAY", "_BEGIN", "_UNTIL", "_WHILE", "_CONST",
  "_REPEAT", "_RECORD", "_DOWNTO", "_PROGRAM", "_PROCEDURE", "_FUNCTION",
  "_ID", "_INTEGER_NUM", "_REAL_NUM", "_CHAR_NUM", "_STRING_NUM", "_MINUS",
  "_TYPE", "$accept", "program", "program_head", "routine", "routine_head",
  "const_part", "const_expr_list", "const_value", "type_part",
  "type_decl_list", "type_definition", "type_decl", "simple_type_decl",
  "array_type_decl", "record_type_decl", "field_decl_list", "field_decl",
  "name_list", "var_part", "var_decl_list", "var_decl", "routine_part",
  "function_decl", "function_head", "procedure_decl", "procedure_head",
  "parameters", "para_decl_list", "para_type_list", "var_para_list",
  "val_para_list", "routine_body", "compound_stmt", "stmt_list", "stmt",
  "non_label_stmt", "assign_stmt", "proc_stmt", "if_stmt", "else_clause",
  "repeat_stmt", "while_stmt", "for_stmt", "direction", "case_stmt",
  "case_expr_list", "case_expr", "goto_stmt", "expression", "expr", "term",
  "factor", "args_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313
};
# endif

#define YYPACT_NINF -145

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-145)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -35,   -20,    62,    30,    67,  -145,    33,    81,    40,    47,
    -145,    86,    63,  -145,  -145,  -145,  -145,    91,    79,   228,
      90,   120,   116,    91,  -145,    92,    -4,  -145,  -145,  -145,
    -145,   139,   228,   147,    46,  -145,   102,   152,    46,   103,
      46,  -145,    38,   151,  -145,   157,  -145,  -145,  -145,  -145,
    -145,  -145,  -145,  -145,  -145,    73,  -145,  -145,    27,    92,
    -145,   109,   118,    -4,  -145,   158,  -145,   164,  -145,   170,
      46,    46,   180,    46,   106,    46,  -145,     9,    -7,   134,
    -145,   168,   132,   255,  -145,   261,   159,    46,    46,   137,
      46,   210,  -145,    92,  -145,   187,    92,   191,   228,   197,
     184,  -145,  -145,  -145,    73,   148,  -145,   203,   203,  -145,
    -145,    30,    30,  -145,   279,    56,   161,    46,  -145,    46,
      46,   155,  -145,    46,    46,    46,    46,    46,    46,    40,
      46,    46,    46,    46,    46,    46,    46,    46,   204,   259,
      40,    46,    59,   243,   190,   279,  -145,    60,    83,   -15,
    -145,    82,   206,   209,   211,  -145,   207,  -145,   -23,  -145,
     214,   213,   216,  -145,    46,  -145,    74,    75,   249,  -145,
      -7,    -7,    -7,    -7,    -7,    -7,   188,   134,   134,   134,
    -145,  -145,  -145,  -145,     3,  -145,   220,   226,     0,  -145,
    -145,   279,  -145,   221,    46,  -145,   230,  -145,  -145,    73,
     192,   233,   228,  -145,    92,   242,    29,  -145,   245,   290,
      83,  -145,  -145,   279,  -145,  -145,  -145,    40,  -145,  -145,
    -145,    46,   193,   193,  -145,  -145,    46,   279,   271,   292,
    -145,   263,  -145,   242,  -145,   -23,    83,    83,  -145,  -145,
     274,   293,   311,   279,    73,  -145,   228,  -145,  -145,  -145,
    -145,    40,  -145,  -145,  -145,  -145,  -145
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     7,     0,     1,     0,     0,     0,    15,
       3,     0,     6,     2,    61,     4,    58,     0,    37,     0,
       0,     0,     0,    14,    17,     0,    45,    10,    11,    12,
      13,     0,     0,    78,     0,    59,     0,     0,     0,     0,
       0,    61,    76,     0,    66,     0,    63,    64,    65,    67,
      68,    69,    70,    71,    72,     0,    16,    35,     0,    36,
      39,     0,     0,     5,    43,     0,    44,     0,     9,     0,
       0,     0,   113,     0,   111,     0,   115,     0,   101,   105,
     110,     0,     0,     0,    94,     0,     0,     0,     0,     0,
       0,     0,    60,     0,    22,     0,     0,    23,     0,     0,
       0,    19,    20,    21,     0,     0,    38,    51,    51,    41,
      42,     7,     7,     8,   122,     0,     0,     0,   117,     0,
       0,     0,   118,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    73,    62,     0,     0,     0,
      32,     0,     0,     0,     0,    18,     0,    34,     0,    49,
       0,     0,     0,    79,     0,   116,     0,     0,     0,   120,
      95,    96,    97,    98,    99,   100,    83,   102,   104,   103,
     108,   106,   107,   109,     0,    80,     0,     0,     0,    91,
      85,    84,    77,     0,     0,    28,     0,    30,    31,     0,
       0,     0,     0,    40,     0,    57,     0,    53,     0,     0,
       0,    46,    48,   121,   114,   112,   119,     0,    81,    87,
      88,     0,     0,     0,    89,    90,     0,    75,     0,     0,
      24,     0,    25,    56,    50,     0,     0,     0,    47,    82,
       0,     0,     0,    74,     0,    33,     0,    26,    52,    54,
      55,     0,    93,    92,    29,    27,    86
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -145,  -145,  -145,    12,  -145,  -145,  -145,   -17,  -145,  -145,
     299,  -103,  -144,  -145,  -145,  -145,   174,   -88,  -145,  -145,
     265,  -145,   262,  -145,   264,  -145,   218,  -145,    93,  -145,
    -145,  -145,    -8,   288,  -128,   239,  -145,  -145,  -145,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,   143,  -145,   -31,   182,
     -13,   -62,   -75
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     7,     8,     9,    12,    76,    18,    23,
      24,   100,   101,   102,   103,   149,   150,    58,    26,    59,
      60,    63,    64,    65,    66,    67,   159,   206,   207,   208,
     209,    15,    44,    21,    45,    46,    47,    48,    49,   218,
      50,    51,    52,   221,    53,   188,   189,    54,   114,    78,
      79,    80,   115
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      16,   156,    31,    77,   196,   147,   130,    83,   151,    85,
     204,   118,   142,   122,     1,    69,   197,   123,   124,   125,
     126,   127,   131,   123,   124,   125,   126,   127,   128,    57,
     219,   224,     4,   234,   128,   104,   105,    57,    99,   235,
     116,    87,   166,    88,   167,    89,    61,    62,   129,    71,
     132,   220,   186,    27,    28,    29,    30,   143,    90,   145,
     163,   151,     5,   192,   195,   164,   238,    72,   164,   105,
     205,   180,   181,   182,   183,     6,    93,    10,   214,   215,
      73,   153,    14,   164,   164,    11,    93,    99,    13,   168,
     199,   105,   249,   250,   241,   242,   229,    94,    74,    27,
      28,    29,    30,    75,    19,    17,   184,    94,    32,   119,
     191,   120,    25,   121,    95,    20,   233,   177,   178,   179,
      96,   176,   187,   161,   162,    97,    27,    28,    29,    30,
      98,    99,   190,   213,    55,    97,    27,    28,    29,    30,
      98,   254,    33,    22,    57,   133,   134,   205,    34,    68,
      70,    35,    36,   135,    81,    82,    84,    37,    38,    91,
      39,   107,    14,   227,    40,   165,    41,    92,   111,   136,
     108,   187,    42,    43,   112,   123,   124,   125,   126,   127,
     113,    33,    99,   117,   138,   232,   128,    34,   137,   144,
     240,    36,   148,    99,   155,   243,    37,    38,   152,    39,
     157,    14,   141,    40,   154,    41,   158,   169,   185,   239,
     194,    42,    43,   200,   247,    33,   201,   203,   202,    99,
      99,    34,   210,   211,   217,    36,   212,    99,   222,   255,
      37,    38,    33,    39,   223,    14,   228,    40,    34,    41,
     231,   226,    36,   256,   230,    42,    43,    37,    38,   193,
      39,   105,    14,   236,    40,   216,    41,   123,   124,   125,
     126,   127,    42,   123,   124,   125,   126,   127,   128,   123,
     124,   125,   126,   127,   128,   123,   124,   125,   126,   127,
     128,    27,    28,    29,    30,   139,   128,   140,   123,   124,
     125,   126,   127,   123,   124,   125,   126,   127,   237,   128,
     251,   244,   245,   252,   128,   170,   171,   172,   173,   174,
     175,   186,    27,    28,    29,    30,    27,    28,    29,    30,
     246,   253,    56,   198,   106,   109,   160,   110,   248,    86,
     146,   225
};

static const yytype_uint8 yycheck[] =
{
       8,   104,    19,    34,   148,    93,    13,    38,    96,    40,
      33,    73,    87,    75,    49,    32,    31,    14,    15,    16,
      17,    18,    29,    14,    15,    16,    17,    18,    25,    52,
      27,    31,    52,     4,    25,     8,     9,    52,    55,    10,
      71,     3,   117,     5,   119,     7,    50,    51,    39,     3,
      57,    48,    52,    53,    54,    55,    56,    88,    20,    90,
       4,   149,     0,     4,     4,     9,   210,    21,     9,     9,
     158,   133,   134,   135,   136,    45,     3,    10,     4,     4,
      34,    98,    42,     9,     9,    52,     3,   104,     7,   120,
       8,     9,   236,   237,   222,   223,   199,    24,    52,    53,
      54,    55,    56,    57,    18,    58,   137,    24,    18,     3,
     141,     5,    33,     7,    41,    52,   204,   130,   131,   132,
      47,   129,   139,   111,   112,    52,    53,    54,    55,    56,
      57,   148,   140,   164,    18,    52,    53,    54,    55,    56,
      57,   244,    22,    52,    52,    11,    12,   235,    28,    10,
       3,    31,    32,    19,    52,     3,    53,    37,    38,     8,
      40,    52,    42,   194,    44,     4,    46,    10,    10,    35,
      52,   188,    52,    53,    10,    14,    15,    16,    17,    18,
      10,    22,   199,     3,    52,   202,    25,    28,    20,    52,
     221,    32,     5,   210,    10,   226,    37,    38,     7,    40,
      52,    42,    43,    44,     7,    46,     3,    52,     4,   217,
      20,    52,    53,     7,   231,    22,     7,    10,     7,   236,
     237,    28,     8,    10,    36,    32,    10,   244,     8,   246,
      37,    38,    22,    40,     8,    42,     6,    44,    28,    46,
       7,    20,    32,   251,    52,    52,    53,    37,    38,     6,
      40,     9,    42,     8,    44,     6,    46,    14,    15,    16,
      17,    18,    52,    14,    15,    16,    17,    18,    25,    14,
      15,    16,    17,    18,    25,    14,    15,    16,    17,    18,
      25,    53,    54,    55,    56,    30,    25,    26,    14,    15,
      16,    17,    18,    14,    15,    16,    17,    18,     8,    25,
      26,    30,    10,    10,    25,   123,   124,   125,   126,   127,
     128,    52,    53,    54,    55,    56,    53,    54,    55,    56,
      57,    10,    23,   149,    59,    63,   108,    63,   235,    41,
      91,   188
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    49,    60,    61,    52,     0,    45,    62,    63,    64,
      10,    52,    65,     7,    42,    90,    91,    58,    67,    18,
      52,    92,    52,    68,    69,    33,    77,    53,    54,    55,
      56,    66,    18,    22,    28,    31,    32,    37,    38,    40,
      44,    46,    52,    53,    91,    93,    94,    95,    96,    97,
      99,   100,   101,   103,   106,    18,    69,    52,    76,    78,
      79,    50,    51,    80,    81,    82,    83,    84,    10,    66,
       3,     3,    21,    34,    52,    57,    66,   107,   108,   109,
     110,    52,     3,   107,    53,   107,    92,     3,     5,     7,
      20,     8,    10,     3,    24,    41,    47,    52,    57,    66,
      70,    71,    72,    73,     8,     9,    79,    52,    52,    81,
      83,    10,    10,    10,   107,   111,   107,     3,   110,     3,
       5,     7,   110,    14,    15,    16,    17,    18,    25,    39,
      13,    29,    57,    11,    12,    19,    35,    20,    52,    30,
      26,    43,   111,   107,    52,   107,    94,    76,     5,    74,
      75,    76,     7,    66,     7,    10,    70,    52,     3,    85,
      85,    62,    62,     4,     9,     4,   111,   111,   107,    52,
     108,   108,   108,   108,   108,   108,    91,   109,   109,   109,
     110,   110,   110,   110,   107,     4,    52,    66,   104,   105,
      91,   107,     4,     6,    20,     4,    71,    31,    75,     8,
       7,     7,     7,    10,    33,    76,    86,    87,    88,    89,
       8,    10,    10,   107,     4,     4,     6,    36,    98,    27,
      48,   102,     8,     8,    31,   105,    20,   107,     6,    70,
      52,     7,    66,    76,     4,    10,     8,     8,    71,    91,
     107,    93,    93,   107,    30,    10,    57,    66,    87,    71,
      71,    26,    10,    10,    70,    66,    91
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    60,    61,    62,    63,    64,    64,    65,    65,
      66,    66,    66,    66,    67,    67,    68,    68,    69,    70,
      70,    70,    71,    71,    71,    71,    71,    71,    71,    72,
      73,    74,    74,    75,    76,    76,    77,    77,    78,    78,
      79,    80,    80,    80,    80,    80,    81,    82,    83,    84,
      85,    85,    86,    86,    87,    87,    88,    89,    90,    91,
      92,    92,    93,    93,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    95,    95,    95,    96,    96,    96,    96,
      96,    97,    98,    98,    99,   100,   101,   102,   102,   103,
     104,   104,   105,   105,   106,   107,   107,   107,   107,   107,
     107,   107,   108,   108,   108,   108,   109,   109,   109,   109,
     109,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   111,   111
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     2,     4,     2,     0,     5,     4,
       1,     1,     1,     1,     2,     0,     2,     1,     4,     1,
       1,     1,     1,     1,     4,     4,     5,     6,     3,     6,
       3,     2,     1,     4,     3,     1,     2,     0,     2,     1,
       4,     2,     2,     1,     1,     0,     4,     5,     4,     3,
       3,     0,     3,     1,     3,     3,     2,     1,     1,     3,
       3,     0,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     6,     5,     1,     4,     1,     4,
       4,     5,     2,     0,     4,     4,     8,     1,     1,     5,
       2,     1,     4,     4,     2,     3,     3,     3,     3,     3,
       3,     1,     3,     3,     3,     1,     3,     3,     3,     3,
       1,     1,     4,     1,     4,     1,     3,     2,     2,     4,
       3,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 60 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
        ////printf("program reduced.\n");
        finished = true;
	    (yyval) = (char*)&program;
        ((program_s*)(yyval))->ID = ((program_head_s*)(yyvsp[-2]))->ID;
	    ((program_s*)(yyval))->routine = (routine_s*)(yyvsp[-1]);
}
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 67 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
        ////printf("program_head %s reduced.\n",$2);
        (yyval) = (char*)(new program_head_s);
        ((program_head_s*)(yyval))->ID = string((yyvsp[-1]));
}
#line 1581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 72 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
        ////printf("routine reduced.\n");
        (yyval) = (char*)(new routine_s);
        ((routine_s*)(yyval))->routine_head = (routine_head_s*)(yyvsp[-1]);
        ((routine_s*)(yyval))->routine_body = (routine_body_s*)(yyvsp[0]);
}
#line 1592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 78 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
	    (yyval) = (char*)(new routine_head_s);
        ((routine_head_s*)(yyval))->const_part = (const_part_s*)(yyvsp[-3]);
        ((routine_head_s*)(yyval))->type_part = (type_part_s*)(yyvsp[-2]);
        ((routine_head_s*)(yyval))->var_part = (var_part_s*)(yyvsp[-1]);
        ((routine_head_s*)(yyval))->routine_part = (routine_part_s*)(yyvsp[0]);
}
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 85 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
        (yyval) = (char*)(new const_part_s);
        vector<const_expr_list_s*>& lst = ((const_part_s*)(yyval))->const_expr_list;
        lst.clear();
        for(const_expr_list_s* p = (const_expr_list_s*)(yyvsp[0]); p; p=p->next)
             lst.push_back(p);
     }
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 92 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
         (yyval) = NULL; 
}
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 95 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            (yyval) = (char*)(new const_expr_list_s);
            ((const_expr_list_s*)(yyval))->next = (const_expr_list_s*)(yyvsp[-4]);
            ((const_expr_list_s*)(yyval))->ID = string((yyvsp[-3]));
            ((const_expr_list_s*)(yyval))->const_value = (const_value_s*)(yyvsp[-1]);
        }
#line 1635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 101 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            (yyval) = (char*)(new const_expr_list_s);
            ((const_expr_list_s*)(yyval))->next = NULL;
            ((const_expr_list_s*)(yyval))->ID = string((yyvsp[-3]));
            ((const_expr_list_s*)(yyval))->const_value = (const_value_s*)(yyvsp[-1]);
}
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 108 "cd_yacc_cgen.y" /* yacc.c:1646  */
    { (yyval) = (char*)(new const_value_s); ((const_value_s*)(yyval))->VALUE = string((yyvsp[0])); ((const_value_s*)(yyval))->TYPE = const_value_s::INTEGER;
                    //printf("const value (INTEGER %s) reduced.\n",((const_value_s*)$$)->VALUE.c_str()); 
                    }
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 112 "cd_yacc_cgen.y" /* yacc.c:1646  */
    { (yyval) = (char*)(new const_value_s); ((const_value_s*)(yyval))->VALUE = string((yyvsp[0])); ((const_value_s*)(yyval))->TYPE = const_value_s::REAL;
                    //printf("const value (REAL %s) reduced.\n",((const_value_s*)$$)->VALUE.c_str()); 
                    }
#line 1662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 116 "cd_yacc_cgen.y" /* yacc.c:1646  */
    { (yyval) = (char*)(new const_value_s); ((const_value_s*)(yyval))->TYPE = const_value_s::CHAR;
                  string strtmp = string((yyvsp[0]));((const_value_s*)(yyval))->VALUE = strtmp.substr(1,strtmp.size()-2);
                    //printf("const value (CHAR %s) reduced.\n",((const_value_s*)$$)->VALUE.c_str()); 
                    }
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 121 "cd_yacc_cgen.y" /* yacc.c:1646  */
    { (yyval) = (char*)(new const_value_s); ((const_value_s*)(yyval))->TYPE = const_value_s::STRING;
                  string strtmp = string((yyvsp[0]));((const_value_s*)(yyval))->VALUE = strtmp.substr(1,strtmp.size()-2);
                    //printf("const value (STRING %s) reduced.\n",((const_value_s*)$$)->VALUE.c_str()); 
                    }
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 126 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
              (yyval) = (char*)(new type_part_s);
              vector<type_definition_s*>& lst = ((type_part_s*)(yyval))->type_definition;
              for(type_decl_list_s* p = (type_decl_list_s*)(yyvsp[0]); p; p=p->next)
                lst.push_back(p->type_definition);
            }
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 132 "cd_yacc_cgen.y" /* yacc.c:1646  */
    { (yyval) = NULL; 
}
#line 1698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 134 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
        (yyval) = (char*)(new type_decl_list_s);
        ((type_decl_list_s*)(yyval))->next = (type_decl_list_s*)(yyvsp[-1]);
        ((type_decl_list_s*)(yyval))->type_definition = (type_definition_s*)(yyvsp[0]); }
#line 1707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 138 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
        (yyval) = (char*)(new type_decl_list_s);
        ((type_decl_list_s*)(yyval))->next = NULL;
        ((type_decl_list_s*)(yyval))->type_definition = (type_definition_s*)(yyvsp[0]);
}
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 143 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
        (yyval) = (char*)(new type_definition_s);
        ((type_definition_s*)(yyval))->ID = string((yyvsp[-3]));
        ((type_definition_s*)(yyval))->type_decl = (type_decl_s*)(yyvsp[-1]);
}
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 148 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
        (yyval) = (char*)(new type_decl_s);
        ((type_decl_s*)(yyval))->simple_type_decl = (simple_type_decl_s*)(yyvsp[0]);
        ((type_decl_s*)(yyval))->array_type_decl = NULL;
        ((type_decl_s*)(yyval))->record_type_decl = NULL;
          }
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 154 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
        (yyval) = (char*)(new type_decl_s);
        ((type_decl_s*)(yyval))->simple_type_decl = NULL;
        ((type_decl_s*)(yyval))->array_type_decl = (array_type_decl_s*)(yyvsp[0]);
        ((type_decl_s*)(yyval))->record_type_decl = NULL;
            }
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 160 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
        (yyval) = (char*)(new type_decl_s);
        ((type_decl_s*)(yyval))->simple_type_decl = NULL;
        ((type_decl_s*)(yyval))->array_type_decl = NULL;
        ((type_decl_s*)(yyval))->record_type_decl = (record_type_decl_s*)(yyvsp[0]);
}
#line 1760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 166 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
                    (yyval) = (char*)(new simple_type_decl_s);
                    ((simple_type_decl_s*)(yyval))->TYPE = simple_type_decl_s::SYS_TYPE;
                    ((simple_type_decl_s*)(yyval))->SYS_TYPE_NAME = string((yyvsp[0]));
                 }
#line 1770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 171 "cd_yacc_cgen.y" /* yacc.c:1646  */
    { 
                    (yyval) = (char*)(new simple_type_decl_s);
                    ((simple_type_decl_s*)(yyval))->TYPE = simple_type_decl_s::ID_TYPE;
                    vector<string>& lstID = ((simple_type_decl_s*)(yyval))->ID;
                    lstID.clear();
                    lstID.push_back(string((yyvsp[0])));
                 }
#line 1782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 178 "cd_yacc_cgen.y" /* yacc.c:1646  */
    { 
                    (yyval) = (char*)(new simple_type_decl_s);
                    ((simple_type_decl_s*)(yyval))->TYPE = simple_type_decl_s::RANGE_TYPE;
                    vector<string>& lstID = ((simple_type_decl_s*)(yyval))->ID;
                    lstID.clear();
                    lstID.push_back(string((yyvsp[-3])));
                    lstID.push_back(string((yyvsp[0])));
                 }
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 186 "cd_yacc_cgen.y" /* yacc.c:1646  */
    { 
                    (yyval) = (char*)(new simple_type_decl_s);
                    ((simple_type_decl_s*)(yyval))->TYPE = simple_type_decl_s::RANGE_TYPE;

                    const_value_s 
                        *a = (const_value_s*)(yyvsp[-3]), *b = (const_value_s*)(yyvsp[0]);
                    if(a->TYPE!=b->TYPE)
                        yyerror("different type in RANGE declaration");
                    else if(a->TYPE==const_value_s::REAL)
                        yyerror("REAL is no allowed in RANGE declaration");
                    else if(a->TYPE==const_value_s::STRING)
                        yyerror("STRING is no allowed in RANGE declaration");
                    else if(a->TYPE==const_value_s::INTEGER)
                    {
                        ((simple_type_decl_s*)(yyval))->MIN = str2int(a->VALUE);
                        ((simple_type_decl_s*)(yyval))->MAX = str2int(b->VALUE);
                        ((simple_type_decl_s*)(yyval))->isChar = 0;

                    }
                    else if(a->TYPE==const_value_s::CHAR)
                    {
                        ((simple_type_decl_s*)(yyval))->MIN = (int)str2char(a->VALUE);
                        ((simple_type_decl_s*)(yyval))->MAX = (int)str2char(b->VALUE);
                        ((simple_type_decl_s*)(yyval))->isChar = 1;
                    }
                 }
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 212 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
                    (yyval) = (char*)(new simple_type_decl_s);
                    ((simple_type_decl_s*)(yyval))->TYPE = simple_type_decl_s::RANGE_TYPE;

                    const_value_s *a = (const_value_s*)(yyvsp[-3]), *b = (const_value_s*)(yyvsp[0]);
                    if(a->TYPE!=b->TYPE) yyerror("different type in RANGE declaration");
                    if(a->TYPE==const_value_s::INTEGER)
                    {
                        ((simple_type_decl_s*)(yyval))->MIN = -str2int(a->VALUE);
                        ((simple_type_decl_s*)(yyval))->MAX = str2int(b->VALUE);
                        ((simple_type_decl_s*)(yyval))->isChar = 0;
                    }
                    else yyerror("expect integer");
                 }
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 226 "cd_yacc_cgen.y" /* yacc.c:1646  */
    { 
                    (yyval) = (char*)(new simple_type_decl_s);
                    ((simple_type_decl_s*)(yyval))->TYPE = simple_type_decl_s::RANGE_TYPE;

                    const_value_s *a = (const_value_s*)(yyvsp[-4]), *b = (const_value_s*)(yyvsp[0]);
                    if(a->TYPE!=b->TYPE) yyerror("different type in RANGE declaration");
                    if(a->TYPE==const_value_s::INTEGER)
                    {
                        ((simple_type_decl_s*)(yyval))->MIN = -str2int(a->VALUE);
                        ((simple_type_decl_s*)(yyval))->MAX = -str2int(b->VALUE);
                        ((simple_type_decl_s*)(yyval))->isChar = 0;
                    }
                    else yyerror("expect integer");
                 }
#line 1864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 240 "cd_yacc_cgen.y" /* yacc.c:1646  */
    { 
                    (yyval) = (char*)(new simple_type_decl_s);
                    ((simple_type_decl_s*)(yyval))->TYPE = simple_type_decl_s::ENUM_TYPE;
                    vector<string>& lstID = ((simple_type_decl_s*)(yyval))->ID;
                    lstID.clear();
                    for(name_list_s* p = (name_list_s*)(yyvsp[-1]); p; p=p->next)
                        lstID.push_back(p->ID);
                        
}
#line 1878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 249 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
                (yyval) = (char*)(new array_type_decl_s);
                ((array_type_decl_s*)(yyval))->simple_type_decl = (simple_type_decl_s*)(yyvsp[-3]);
                ((array_type_decl_s*)(yyval))->type_decl = (type_decl_s*)(yyvsp[0]);
}
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 255 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
                (yyval) = (char*)(new record_type_decl_s);
                vector<field_decl_s*>& lst = ((record_type_decl_s*)(yyval))->field_decl;
                lst.clear();
                for(field_decl_list_s* p = (field_decl_list_s*)(yyvsp[-1]); p; p=p->next)
                    lst.push_back(p->field_decl);
}
#line 1900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 262 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
                    (yyval) = (char*)(new field_decl_list_s);
                    ((field_decl_list_s*)(yyval))->next = (field_decl_list_s*)(yyvsp[-1]);
                    ((field_decl_list_s*)(yyval))->field_decl = (field_decl_s*)(yyvsp[0]);
                }
#line 1910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 267 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
                    (yyval) = (char*)(new field_decl_list_s);
                    ((field_decl_list_s*)(yyval))->next = NULL;
                    ((field_decl_list_s*)(yyval))->field_decl = (field_decl_s*)(yyvsp[0]);
}
#line 1920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 272 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
                    (yyval) = (char*)(new field_decl_s);
                    ((field_decl_s*)(yyval))->type_decl = (type_decl_s*)(yyvsp[-1]);
                    vector<string>& lst = ((field_decl_s*)(yyval))->name_list;
                    for(name_list_s* p = (name_list_s*)(yyvsp[-3]); p; p=p->next)
                        lst.push_back(p->ID);
}
#line 1932 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 279 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
                    (yyval) = (char*)(new name_list_s);
                    ((name_list_s*)(yyval))->next = (name_list_s*)(yyvsp[-2]);
                    ((name_list_s*)(yyval))->ID = string((yyvsp[0]));
             }
#line 1942 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 284 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
                    (yyval) = (char*)(new name_list_s);
                    ((name_list_s*)(yyval))->next = NULL;
                    ((name_list_s*)(yyval))->ID = string((yyvsp[0]));
}
#line 1952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 290 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            (yyval) = (char*)(new var_part_s);
            vector<var_decl_s*>& lst = ((var_part_s*)(yyval))->var_decl;
            lst.clear();
            for(var_decl_list_s* p = (var_decl_list_s*)(yyvsp[0]); p; p=p->next)
                lst.push_back(p->var_decl);
         }
#line 1964 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 297 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
             (yyval) = NULL; 
}
#line 1972 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 301 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            (yyval) = (char*)(new var_decl_list_s);
            ((var_decl_list_s*)(yyval))->next = (var_decl_list_s*)(yyvsp[-1]);
            ((var_decl_list_s*)(yyval))->var_decl = (var_decl_s*)(yyvsp[0]);
                }
#line 1982 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 306 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            (yyval) = (char*)(new var_decl_list_s);
            ((var_decl_list_s*)(yyval))->next = NULL;
            ((var_decl_list_s*)(yyval))->var_decl = (var_decl_s*)(yyvsp[0]);
}
#line 1992 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 312 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            (yyval) = (char*)(new var_decl_s);                    
            vector<string>& lst = ((var_decl_s*)(yyval))->name_list;
            for(name_list_s* p = (name_list_s*)(yyvsp[-3]); p; p=p->next)
                lst.push_back(p->ID);
            ((var_decl_s*)(yyval))->type_decl = (type_decl_s*)(yyvsp[-1]);
}
#line 2004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 320 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
                (yyval) = (char*)(new routine_part_s);
                ((routine_part_s*)(yyval))->next = (routine_part_s*)(yyvsp[-1]);
                ((routine_part_s*)(yyval))->procedure_decl = NULL;
                ((routine_part_s*)(yyval))->function_decl = (function_decl_s*)(yyvsp[0]);
             }
#line 2015 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 326 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
                (yyval) = (char*)(new routine_part_s);
                ((routine_part_s*)(yyval))->next = (routine_part_s*)(yyvsp[-1]);
                ((routine_part_s*)(yyval))->procedure_decl = (procedure_decl_s*)(yyvsp[0]);
                ((routine_part_s*)(yyval))->function_decl = NULL;
             }
#line 2026 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 332 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
                //printf("function_decl reduced.\n");
                (yyval) = (char*)(new routine_part_s);
                ((routine_part_s*)(yyval))->next = NULL;
                ((routine_part_s*)(yyval))->procedure_decl = NULL;
                ((routine_part_s*)(yyval))->function_decl = (function_decl_s*)(yyvsp[0]);
             }
#line 2038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 339 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
                (yyval) = (char*)(new routine_part_s);
                ((routine_part_s*)(yyval))->next = NULL;
                ((routine_part_s*)(yyval))->procedure_decl = (procedure_decl_s*)(yyvsp[0]);
                ((routine_part_s*)(yyval))->function_decl = NULL;
             }
#line 2049 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 344 "cd_yacc_cgen.y" /* yacc.c:1646  */
    { (yyval) = NULL;
}
#line 2056 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 349 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
                (yyval) = (char*)(new function_decl_s);
                ((function_decl_s*)(yyval))->function_head = (function_head_s*)(yyvsp[-3]);
                ((function_decl_s*)(yyval))->routine = (routine_s*)(yyvsp[-1]);
}
#line 2066 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 355 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
                //printf("function_head reduced.\n");
                (yyval) = (char*)(new function_head_s);
                ((function_head_s*)(yyval))->ID = string((yyvsp[-3]));
                ((function_head_s*)(yyval))->parameters = (parameters_s*)(yyvsp[-2]);
                ((function_head_s*)(yyval))->simple_type_decl = (simple_type_decl_s*)(yyvsp[0]);
}
#line 2078 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 363 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
                (yyval) = (char*)(new procedure_decl_s);
                ((procedure_decl_s*)(yyval))->procedure_head = (procedure_head_s*)(yyvsp[-3]);
                ((procedure_decl_s*)(yyval))->routine = (routine_s*)(yyvsp[-1]);
}
#line 2088 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 369 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
                (yyval) = (char*)(new procedure_head_s);
                ((procedure_head_s*)(yyval))->ID = string((yyvsp[-1]));
                ((procedure_head_s*)(yyval))->parameters = (parameters_s*)(yyvsp[0]);
}
#line 2098 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 376 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
                (yyval) = (char*)(new parameters_s);
                vector<para_type_list_s*>& lst = ((parameters_s*)(yyval))->para_decl_list;
                lst.clear();
                for(para_decl_list_s* p = ((para_decl_list_s*)(yyvsp[-1])); p; p=p->next)
                    lst.push_back(p->para_type_list);
           }
#line 2110 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 383 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            (yyval) = NULL;
}
#line 2118 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 387 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            (yyval) = (char*)(new para_decl_list_s);
            ((para_decl_list_s*)(yyval))->next = (para_decl_list_s*)(yyvsp[-2]);
            ((para_decl_list_s*)(yyval))->para_type_list = (para_type_list_s*)(yyvsp[0]);
                 }
#line 2128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 392 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            (yyval) = (char*)(new para_decl_list_s);
            ((para_decl_list_s*)(yyval))->next = NULL;
            ((para_decl_list_s*)(yyval))->para_type_list = (para_type_list_s*)(yyvsp[0]);
}
#line 2138 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 398 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            (yyval) = (char*)(new para_type_list_s);
            ((para_type_list_s*)(yyval))->var_para_list = (var_para_list_s*)(yyvsp[-2]);
            ((para_type_list_s*)(yyval))->val_para_list = NULL;
            ((para_type_list_s*)(yyval))->simple_type_decl = (simple_type_decl_s*)(yyvsp[0]);

               }
#line 2150 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 405 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            (yyval) = (char*)(new para_type_list_s);
            ((para_type_list_s*)(yyval))->val_para_list = (val_para_list_s*)(yyvsp[-2]);
            ((para_type_list_s*)(yyval))->var_para_list = NULL;
            ((para_type_list_s*)(yyval))->simple_type_decl = (simple_type_decl_s*)(yyvsp[0]);
}
#line 2161 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 412 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            (yyval) = (char*)(new var_para_list_s);
            ((var_para_list_s*)(yyval))->name_list = (name_list_s*)(yyvsp[0]);
}
#line 2170 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 417 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            (yyval) = (char*)(new val_para_list_s);
            ((val_para_list_s*)(yyval))->name_list = (name_list_s*)(yyvsp[0]);
}
#line 2179 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 422 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            ////printf("routine_body reduced.\n");
            (yyval) = (char*)(new routine_body_s);
            ((routine_body_s*)(yyval))->compound_stmt = (compound_stmt_s*)(yyvsp[0]);
}
#line 2189 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 428 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            ////printf("compound_stmt reduced.\n");
            (yyval) = (char*)(new compound_stmt_s);
            vector<stmt_s*> &lst = ((compound_stmt_s*)(yyval))->stmt;
            lst.clear();
            for(stmt_list_s* p = (stmt_list_s*)(yyvsp[-1]); p; p=p->next)
                lst.push_back(p->stmt);
            ////printf("[compound_stmt]the number of stmt: %d\n",(int)lst.size());
}
#line 2203 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 438 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            ////printf("stmt_list reduced.\n");
            (yyval) = (char*)(new stmt_list_s);
            ((stmt_list_s*)(yyval))->next = (stmt_list_s*)(yyvsp[-2]);
            ((stmt_list_s*)(yyval))->stmt = (stmt_s*)(yyvsp[-1]); }
#line 2213 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 443 "cd_yacc_cgen.y" /* yacc.c:1646  */
    { (yyval) = NULL;
}
#line 2220 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 446 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            ////printf("stmt reduced.\n");
            (yyval) = (char*)(new stmt_s);
            ((stmt_s*)(yyval))->INTEGER = new int;
            *(((stmt_s*)(yyval))->INTEGER) = str2int(string((yyvsp[-2])));
            ////printf("[stmt]label:%d\n",*((stmt_s*)$$)->INTEGER);
            ((stmt_s*)(yyval))->non_label_stmt = (non_label_stmt_s*)(yyvsp[0]);
       }
#line 2233 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 453 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            ////printf("stmt reduced.\n");
            (yyval) = (char*)(new stmt_s);
            ((stmt_s*)(yyval))->INTEGER = NULL;
            ((stmt_s*)(yyval))->non_label_stmt = (non_label_stmt_s*)(yyvsp[0]);
}
#line 2244 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 460 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
               ////printf("non_label_stmt reduced.\n");
               (yyval) = (char*)(new non_label_stmt_s);
               ((non_label_stmt_s*)(yyval))->assign_stmt = (assign_stmt_s*)(yyvsp[0]);
               ((non_label_stmt_s*)(yyval))->proc_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->compound_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->if_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->repeat_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->while_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->for_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->case_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->goto_stmt = NULL;
 }
#line 2262 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 473 "cd_yacc_cgen.y" /* yacc.c:1646  */
    { 
               ////printf("non_label_stmt reduced.\n");
               (yyval) = (char*)(new non_label_stmt_s);
               ((non_label_stmt_s*)(yyval))->assign_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->proc_stmt = (proc_stmt_s*)(yyvsp[0]);
               ((non_label_stmt_s*)(yyval))->compound_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->if_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->repeat_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->while_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->for_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->case_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->goto_stmt = NULL;
}
#line 2280 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 486 "cd_yacc_cgen.y" /* yacc.c:1646  */
    { 
               ////printf("non_label_stmt reduced.\n");
               (yyval) = (char*)(new non_label_stmt_s);
               ((non_label_stmt_s*)(yyval))->assign_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->proc_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->compound_stmt = (compound_stmt_s*)(yyvsp[0]);
               ((non_label_stmt_s*)(yyval))->if_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->repeat_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->while_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->for_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->case_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->goto_stmt = NULL;
}
#line 2298 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 499 "cd_yacc_cgen.y" /* yacc.c:1646  */
    { 
               ////printf("non_label_stmt reduced.\n");
               (yyval) = (char*)(new non_label_stmt_s);
               ((non_label_stmt_s*)(yyval))->assign_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->proc_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->compound_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->if_stmt = (if_stmt_s*)(yyvsp[0]);
               ((non_label_stmt_s*)(yyval))->repeat_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->while_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->for_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->case_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->goto_stmt = NULL;
}
#line 2316 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 512 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
               ////printf("non_label_stmt reduced.\n");    
               (yyval) = (char*)(new non_label_stmt_s);
               ((non_label_stmt_s*)(yyval))->assign_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->proc_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->compound_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->if_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->repeat_stmt = (repeat_stmt_s*)(yyvsp[0]);
               ((non_label_stmt_s*)(yyval))->while_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->for_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->case_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->goto_stmt = NULL;
 }
#line 2334 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 525 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
               ////printf("non_label_stmt reduced.\n");
               (yyval) = (char*)(new non_label_stmt_s);
               ((non_label_stmt_s*)(yyval))->assign_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->proc_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->compound_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->if_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->repeat_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->while_stmt = (while_stmt_s*)(yyvsp[0]);
               ((non_label_stmt_s*)(yyval))->for_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->case_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->goto_stmt = NULL;
 }
#line 2352 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 538 "cd_yacc_cgen.y" /* yacc.c:1646  */
    { 
               ////printf("non_label_stmt reduced.\n");
               (yyval) = (char*)(new non_label_stmt_s);
               ((non_label_stmt_s*)(yyval))->assign_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->proc_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->compound_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->if_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->repeat_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->while_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->for_stmt = (for_stmt_s*)(yyvsp[0]);
               ((non_label_stmt_s*)(yyval))->case_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->goto_stmt = NULL;
}
#line 2370 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 551 "cd_yacc_cgen.y" /* yacc.c:1646  */
    { 
               ////printf("non_label_stmt reduced.\n");
               (yyval) = (char*)(new non_label_stmt_s);
               ((non_label_stmt_s*)(yyval))->assign_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->proc_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->compound_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->if_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->repeat_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->while_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->for_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->case_stmt = (case_stmt_s*)(yyvsp[0]);
               ((non_label_stmt_s*)(yyval))->goto_stmt = NULL;
}
#line 2388 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 564 "cd_yacc_cgen.y" /* yacc.c:1646  */
    { 
               ////printf("non_label_stmt reduced.\n");
               (yyval) = (char*)(new non_label_stmt_s);
               ((non_label_stmt_s*)(yyval))->assign_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->proc_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->compound_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->if_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->repeat_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->while_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->for_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->case_stmt = NULL;
               ((non_label_stmt_s*)(yyval))->goto_stmt = (goto_stmt_s*)(yyvsp[0]);
}
#line 2406 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 579 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
               ////printf("assign_stmt reduced.\n");
               (yyval) = (char*)(new assign_stmt_s);
               ((assign_stmt_s*)(yyval))->ID = string((yyvsp[-2]));
               ((assign_stmt_s*)(yyval))->expression_idx = NULL;
               ((assign_stmt_s*)(yyval))->expression = (expression_s*)(yyvsp[0]);
               ((assign_stmt_s*)(yyval))->ID_DOT_ID = NULL;
               ((assign_stmt_s*)(yyval))->TYPE = 0;
               ////printf("[assign_stmt]%s := expression\n", $1);
            }
#line 2421 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 589 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
               ////printf("assign_stmt reduced.\n");
               (yyval) = (char*)(new assign_stmt_s);
               ((assign_stmt_s*)(yyval))->ID = string((yyvsp[-5]));
               ((assign_stmt_s*)(yyval))->expression_idx = (expression_s*)(yyvsp[-3]);
               ((assign_stmt_s*)(yyval))->expression = (expression_s*)(yyvsp[0]);
               ((assign_stmt_s*)(yyval))->ID_DOT_ID = NULL;
               ((assign_stmt_s*)(yyval))->TYPE = 1;
               ////printf("[assign_stmt]%s[expression] := expression\n", $1);
}
#line 2436 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 599 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
               ////printf("assign_stmt reduced.\n");
               (yyval) = (char*)(new assign_stmt_s);
               //((assign_stmt_s*)$$)->ID = string($1);
               ((assign_stmt_s*)(yyval))->expression_idx = NULL;
               ((assign_stmt_s*)(yyval))->expression = (expression_s*)(yyvsp[-1]);
               ((assign_stmt_s*)(yyval))->ID_DOT_ID = new pair<string,string>(string((yyvsp[-4])),string((yyvsp[-2])));
               ((assign_stmt_s*)(yyval))->TYPE = 2;
               ////printf("[assign_stmt]%s.%s := expression\n", $1, $3);
}
#line 2451 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 610 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
             ////printf("proc_stmt reduced.\n");    
             (yyval) = (char*)(new proc_stmt_s);
             ((proc_stmt_s*)(yyval))->ID = string((yyvsp[0]));
             ((proc_stmt_s*)(yyval))->args_list = NULL;
             ((proc_stmt_s*)(yyval))->readID = "";
             ////printf("[proc_stmt]%s\n", $1);             
        }
#line 2464 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 618 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
             ////printf("proc_stmt reduced.\n");                
             (yyval) = (char*)(new proc_stmt_s);
             ((proc_stmt_s*)(yyval))->ID = string((yyvsp[-3]));
             ((proc_stmt_s*)(yyval))->args_list = (args_list_s*)(yyvsp[-1]);
             ((proc_stmt_s*)(yyval))->readID = "";
             ////printf("[proc_stmt]%s(args_list)\n", $1);                          
        }
#line 2477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 626 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
             ////printf("proc_stmt reduced.\n");                
             (yyval) = (char*)(new proc_stmt_s);
             ((proc_stmt_s*)(yyval))->ID = string((yyvsp[0]));
             ((proc_stmt_s*)(yyval))->args_list = NULL;
             ((proc_stmt_s*)(yyval))->readID = "";
             ////printf("[proc_stmt]%s--SYS_PROC\n", $1);                                       
        }
#line 2490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 634 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
             ////printf("proc_stmt reduced.\n");                
             (yyval) = (char*)(new proc_stmt_s);
             ((proc_stmt_s*)(yyval))->ID = string((yyvsp[-3]));
             ((proc_stmt_s*)(yyval))->args_list = (args_list_s*)(yyvsp[-1]);
             ((proc_stmt_s*)(yyval))->readID = "";
             ////printf("[proc_stmt]%s(args_list)--SYS_PROC\n", $1);                                                    
        }
#line 2503 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 642 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
             ////printf("proc_stmt reduced.\n");                
             (yyval) = (char*)(new proc_stmt_s);
             ((proc_stmt_s*)(yyval))->ID = "read";
             ((proc_stmt_s*)(yyval))->args_list = NULL;
             ((proc_stmt_s*)(yyval))->readID = string((yyvsp[-1]));
             ////printf("[proc_stmt]READ(%s)--READ\n", $1);                                                                 
}
#line 2516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 651 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
             (yyval) = (char*)(new if_stmt_s);
             ((if_stmt_s*)(yyval))->expression = (expression_s*)(yyvsp[-3]);
             ((if_stmt_s*)(yyval))->compound_stmt = (compound_stmt_s*)(yyvsp[-1]);
             ((if_stmt_s*)(yyval))->else_clause = (else_clause_s*)(yyvsp[0]);
}
#line 2527 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 658 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            (yyval) = (char*)(new else_clause_s);
            ((else_clause_s*)(yyval))->compound_stmt = (compound_stmt_s*)(yyvsp[0]);
        }
#line 2536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 661 "cd_yacc_cgen.y" /* yacc.c:1646  */
    { (yyval) = NULL;
}
#line 2543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 664 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            (yyval) = (char*)(new repeat_stmt_s);
            ((repeat_stmt_s*)(yyval))->expression = (expression_s*)(yyvsp[0]);
            vector<stmt_s*>& lst = ((repeat_stmt_s*)(yyval))->stmt;
            lst.clear();
            for(stmt_list_s* p = (stmt_list_s*)(yyvsp[-2]); p; p=p->next)
                lst.push_back(p->stmt);
}
#line 2556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 673 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            (yyval) = (char*)(new while_stmt_s);
            ((while_stmt_s*)(yyval))->expression = (expression_s*)(yyvsp[-2]);
            ((while_stmt_s*)(yyval))->compound_stmt = (compound_stmt_s*)(yyvsp[0]);
 }
#line 2566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 679 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            (yyval) = (char*)(new for_stmt_s);
            ((for_stmt_s*)(yyval))->ID = string((yyvsp[-6]));
            ((for_stmt_s*)(yyval))->direction = (for_stmt_s::directionEnum)((direction_s*)(yyvsp[-3]))->dir;
            ((for_stmt_s*)(yyval))->expression1 = (expression_s*)(yyvsp[-4]);
            ((for_stmt_s*)(yyval))->expression2 = (expression_s*)(yyvsp[-2]);
            ((for_stmt_s*)(yyval))->compound_stmt = (compound_stmt_s*)(yyvsp[0]);
            //printf("for_stmt reduced.\n");
 }
#line 2580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 689 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            (yyval) = (char*)(new direction_s);
            ((direction_s*)(yyval))->dir = 0;
         }
#line 2589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 692 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            (yyval) = (char*)(new direction_s);
            ((direction_s*)(yyval))->dir = 1;
}
#line 2598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 697 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            (yyval) = (char*)(new case_stmt_s);
            ((case_stmt_s*)(yyval))->expression = (expression_s*)(yyvsp[-3]);
            vector<case_expr_s*>& lst = ((case_stmt_s*)(yyval))->case_expr;
            lst.clear();
            for(case_expr_list_s* p = (case_expr_list_s*)(yyvsp[-1]); p; p=p->next)
                lst.push_back(p->case_expr);
}
#line 2611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 706 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            (yyval) = (char*)(new case_expr_list_s);
            ((case_expr_list_s*)(yyval))->next= (case_expr_list_s*)(yyvsp[-1]);
            ((case_expr_list_s*)(yyval))->case_expr = (case_expr_s*)(yyvsp[0]);
       }
#line 2621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 710 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            (yyval) = (char*)(new case_expr_list_s);
            ((case_expr_list_s*)(yyval))->next = NULL;
            ((case_expr_list_s*)(yyval))->case_expr = (case_expr_s*)(yyvsp[0]);
}
#line 2631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 716 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            (yyval) = (char*)(new case_expr_s);
            ((case_expr_s*)(yyval))->const_value = (const_value_s*)(yyvsp[-3]);
            ((case_expr_s*)(yyval))->stmt = (stmt_s*)(yyvsp[-1]);
            ((case_expr_s*)(yyval))->ID = NULL;

          }
#line 2643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 722 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            (yyval) = (char*)(new case_expr_s);
            ((case_expr_s*)(yyval))->ID = new string((yyvsp[-3]));
            ((case_expr_s*)(yyval))->const_value = NULL;
            ((case_expr_s*)(yyval))->stmt = (stmt_s*)(yyvsp[-1]);
}
#line 2654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 729 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            (yyval) = (char*)(new goto_stmt_s);
            ((goto_stmt_s*)(yyval))->INTEGER = str2int(string((yyvsp[0])));
}
#line 2663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 734 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            ////printf("expression GE reduced.\n");
            (yyval) = (char*)(new expression_s);
            ((expression_s*)(yyval))->TYPE = expression_s::GE;
            ((expression_s*)(yyval))->next = (expression_s*)(yyvsp[-2]);
            ((expression_s*)(yyval))->expr = (expr_s*)(yyvsp[0]);
         }
#line 2675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 740 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            ////printf("expression GT reduced.\n");
            (yyval) = (char*)(new expression_s);
            ((expression_s*)(yyval))->TYPE = expression_s::GT;
            ((expression_s*)(yyval))->next = (expression_s*)(yyvsp[-2]);
            ((expression_s*)(yyval))->expr = (expr_s*)(yyvsp[0]);
         }
#line 2687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 746 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            ////printf("expression LE reduced.\n");
            (yyval) = (char*)(new expression_s);
            ((expression_s*)(yyval))->TYPE = expression_s::LE;
            ((expression_s*)(yyval))->next = (expression_s*)(yyvsp[-2]);
            ((expression_s*)(yyval))->expr = (expr_s*)(yyvsp[0]);
         }
#line 2699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 752 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            ////printf("expression LT reduced.\n");
            (yyval) = (char*)(new expression_s);
            ((expression_s*)(yyval))->TYPE = expression_s::LT;
            ((expression_s*)(yyval))->next = (expression_s*)(yyvsp[-2]);
            ((expression_s*)(yyval))->expr = (expr_s*)(yyvsp[0]);
         }
#line 2711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 758 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            ////printf("expression EQUAL reduced.\n");
            (yyval) = (char*)(new expression_s);
            ((expression_s*)(yyval))->TYPE = expression_s::EQUAL;
            ((expression_s*)(yyval))->next = (expression_s*)(yyvsp[-2]);
            ((expression_s*)(yyval))->expr = (expr_s*)(yyvsp[0]);
         }
#line 2723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 764 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            ////printf("expression UNEQUAL reduced.\n");
            (yyval) = (char*)(new expression_s);
            ((expression_s*)(yyval))->TYPE = expression_s::UNEQUAL;
            ((expression_s*)(yyval))->next = (expression_s*)(yyvsp[-2]);
            ((expression_s*)(yyval))->expr = (expr_s*)(yyvsp[0]);
         }
#line 2735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 770 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            (yyval) = (char*)(new expression_s);
            ((expression_s*)(yyval))->TYPE = expression_s::NULL_OPERATOR;
            ((expression_s*)(yyval))->next = NULL;
            ((expression_s*)(yyval))->expr = (expr_s*)(yyvsp[0]);
            ////printf("expression (expr) reduced.\n");
}
#line 2747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 778 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            //printf("expr (+) reduced.\n");
            (yyval) = (char*)(new expr_s);
            ((expr_s*)(yyval))->TYPE = expr_s::PLUS;
            ((expr_s*)(yyval))->next = (expr_s*)(yyvsp[-2]);
            ((expr_s*)(yyval))->term = (term_s*)(yyvsp[0]);
    }
#line 2759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 784 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            //printf("expr (-) reduced.\n");
            (yyval) = (char*)(new expr_s);
            ((expr_s*)(yyval))->TYPE = expr_s::MINUS;
            ((expr_s*)(yyval))->next = (expr_s*)(yyvsp[-2]);
            ((expr_s*)(yyval))->term = (term_s*)(yyvsp[0]);
    }
#line 2771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 790 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            //printf("expr (OR) reduced.\n");            
            (yyval) = (char*)(new expr_s);
            ((expr_s*)(yyval))->TYPE = expr_s::OR;
            ((expr_s*)(yyval))->next = (expr_s*)(yyvsp[-2]);
            ((expr_s*)(yyval))->term = (term_s*)(yyvsp[0]);
    }
#line 2783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 796 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            //printf("expr (term) reduced.\n");
            (yyval) = (char*)(new expr_s);
            ((expr_s*)(yyval))->TYPE = expr_s::NULL_OPERATOR;
            ((expr_s*)(yyval))->next = NULL;
            ((expr_s*)(yyval))->term = (term_s*)(yyvsp[0]);
}
#line 2795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 804 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            //printf("term (*) reduced.\n");
            (yyval) = (char*)(new term_s);
            ((term_s*)(yyval))->TYPE = term_s::MUL;
            ((term_s*)(yyval))->next = (term_s*)(yyvsp[-2]);
            ((term_s*)(yyval))->factor = (factor_s*)(yyvsp[0]);
   }
#line 2807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 810 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            //printf("term (/) reduced.\n");            
            (yyval) = (char*)(new term_s);
            ((term_s*)(yyval))->TYPE = term_s::DIV;
            ((term_s*)(yyval))->next = (term_s*)(yyvsp[-2]);
            ((term_s*)(yyval))->factor = (factor_s*)(yyvsp[0]);
   }
#line 2819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 816 "cd_yacc_cgen.y" /* yacc.c:1646  */
    { 
            //printf("term (MOD) reduced.\n");            
            (yyval) = (char*)(new term_s);
            ((term_s*)(yyval))->TYPE = term_s::MOD;
            ((term_s*)(yyval))->next = (term_s*)(yyvsp[-2]);
            ((term_s*)(yyval))->factor = (factor_s*)(yyvsp[0]);
   }
#line 2831 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 822 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            //printf("term (AND) reduced.\n");                        
            (yyval) = (char*)(new term_s);
            ((term_s*)(yyval))->TYPE = term_s::AND;
            ((term_s*)(yyval))->next = (term_s*)(yyvsp[-2]);
            ((term_s*)(yyval))->factor = (factor_s*)(yyvsp[0]);
   }
#line 2843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 828 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            //printf("term (factor) reduced.\n");                        
            (yyval) = (char*)(new term_s);
            ((term_s*)(yyval))->TYPE = term_s::NULL_OPERATOR;
            ((term_s*)(yyval))->next = NULL;
            ((term_s*)(yyval))->factor = (factor_s*)(yyvsp[0]);
}
#line 2855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 836 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            //printf("factor (ID) reduced.\n");                        
            (yyval) = (char*)(new factor_s);
            ((factor_s*)(yyval))->TYPE = factor_s::ID_TYPE;
            ((factor_s*)(yyval))->ID = string((yyvsp[0]));
            ((factor_s*)(yyval))->args_list = NULL;
            ((factor_s*)(yyval))->const_value = NULL;
            ((factor_s*)(yyval))->ID_DOT_ID = NULL;
            ((factor_s*)(yyval))->expression = NULL;
            ((factor_s*)(yyval))->next = NULL;
            //printf("[factor]%s\n",((factor_s*)$$)->ID.c_str());
     }
#line 2872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 847 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            ////printf("factor reduced.\n");                        
            (yyval) = (char*)(new factor_s);
            ((factor_s*)(yyval))->TYPE = factor_s::FUNCTION_WITH_ARGS;
            ((factor_s*)(yyval))->ID = string((yyvsp[-3]));
            ((factor_s*)(yyval))->args_list = (args_list_s*)(yyvsp[-1]);
            ((factor_s*)(yyval))->const_value = NULL;
            ((factor_s*)(yyval))->ID_DOT_ID = NULL;
            ((factor_s*)(yyval))->expression = NULL;
            ((factor_s*)(yyval))->next = NULL;
            ////printf("[factor]%s(args_list)\n",((factor_s*)$$)->ID.c_str());            
     }
#line 2889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 858 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            ////printf("factor reduced.\n");                        
            (yyval) = (char*)(new factor_s);
            ((factor_s*)(yyval))->TYPE = factor_s::SYS_FUNCT;
            ((factor_s*)(yyval))->ID = string((yyvsp[0]));
            ((factor_s*)(yyval))->args_list = NULL;
            ((factor_s*)(yyval))->const_value = NULL;
            ((factor_s*)(yyval))->ID_DOT_ID = NULL;
            ((factor_s*)(yyval))->expression = NULL;
            ((factor_s*)(yyval))->next = NULL;
            ////printf("[factor]%s---SYS_FUNC\n",((factor_s*)$$)->ID.c_str());                        
     }
#line 2906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 869 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            (yyval) = (char*)(new factor_s);
            ((factor_s*)(yyval))->TYPE = factor_s::SYS_FUNCT_WITH_ARGS;
            ((factor_s*)(yyval))->ID = string((yyvsp[-3]));
            ((factor_s*)(yyval))->args_list = (args_list_s*)(yyvsp[-1]);
            ((factor_s*)(yyval))->const_value = NULL;
            ((factor_s*)(yyval))->ID_DOT_ID = NULL;
            ((factor_s*)(yyval))->expression = NULL;
            ((factor_s*)(yyval))->next = NULL;
            ////printf("factor reduced.\n");
            ////printf("[factor]%s(args_list)---SYS_FUNC\n",((factor_s*)$$)->ID.c_str());                                    
     }
#line 2923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 880 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            (yyval) = (char*)(new factor_s);
            ((factor_s*)(yyval))->TYPE = factor_s::CONST_VALUE;
            //((factor_s*)$$)->ID = "nothing";
            ((factor_s*)(yyval))->args_list = NULL;
            ((factor_s*)(yyval))->const_value = (const_value_s*)(yyvsp[0]);
            ((factor_s*)(yyval))->ID_DOT_ID = NULL;
            ((factor_s*)(yyval))->expression = NULL;
            ((factor_s*)(yyval))->next = NULL;
            //printf("factor (const_value) reduced.\n");
     }
#line 2939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 890 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            (yyval) = (char*)(new factor_s);
            ((factor_s*)(yyval))->TYPE = factor_s::EXPRESSION;
            //((factor_s*)$$)->ID = "";
            ((factor_s*)(yyval))->args_list = NULL;
            ((factor_s*)(yyval))->const_value = NULL;
            ((factor_s*)(yyval))->ID_DOT_ID = NULL;
            ((factor_s*)(yyval))->expression = (expression_s*)(yyvsp[-1]);
            ((factor_s*)(yyval))->next = NULL;
            //printf("factor (expression) reduced.\n");            
     }
#line 2955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 900 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            (yyval) = (char*)(new factor_s);
            ((factor_s*)(yyval))->TYPE = factor_s::NOT_FACTOR;
            //((factor_s*)$$)->ID = "";
            ((factor_s*)(yyval))->args_list = NULL;
            ((factor_s*)(yyval))->const_value = NULL;
            ((factor_s*)(yyval))->ID_DOT_ID = NULL;
            ((factor_s*)(yyval))->expression = NULL;
            ((factor_s*)(yyval))->next = (factor_s*)(yyvsp[0]);
            ////printf("factor (NOT factor) reduced.\n");            
     }
#line 2971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 910 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            (yyval) = (char*)(new factor_s);
            ((factor_s*)(yyval))->TYPE = factor_s::NOT_FACTOR;
            //((factor_s*)$$)->ID = "";
            ((factor_s*)(yyval))->args_list = NULL;
            ((factor_s*)(yyval))->const_value = NULL;
            ((factor_s*)(yyval))->ID_DOT_ID = NULL;
            ((factor_s*)(yyval))->expression = NULL;
            ((factor_s*)(yyval))->next = (factor_s*)(yyvsp[0]);
            //printf("factor (-factor) reduced.\n");            
     }
#line 2987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 920 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            (yyval) = (char*)(new factor_s);
            ((factor_s*)(yyval))->TYPE = factor_s::ID_WITH_EXPRESSION;
            ((factor_s*)(yyval))->ID = string((yyvsp[-3]));
            ((factor_s*)(yyval))->args_list = NULL;
            ((factor_s*)(yyval))->const_value = NULL;
            ((factor_s*)(yyval))->ID_DOT_ID = NULL;
            ((factor_s*)(yyval))->expression = (expression_s*)(yyvsp[-1]);
            ((factor_s*)(yyval))->next = NULL;
            ////printf("factor %s[expression] reduced.\n",((factor_s*)$$)->ID.c_str());            
     }
#line 3003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 930 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            (yyval) = (char*)(new factor_s);
            ((factor_s*)(yyval))->TYPE = factor_s::ID_DOT_ID_TYPE;
            //((factor_s*)$$)->ID = string($1);
            ((factor_s*)(yyval))->args_list = NULL;
            ((factor_s*)(yyval))->const_value = NULL;
            ((factor_s*)(yyval))->ID_DOT_ID = new pair<string,string>(string((yyvsp[-2])),string((yyvsp[0])));
            ((factor_s*)(yyval))->expression = NULL;
            ((factor_s*)(yyval))->next = NULL;
            ////printf("factor %s.%s reduced.\n",((factor_s*)$$)->ID_DOT_ID->first.c_str(),((factor_s*)$$)->ID_DOT_ID->second.c_str());                        
}
#line 3019 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 942 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            (yyval) = (char*)(new args_list_s);
            ((args_list_s*)(yyval))->next = (args_list_s*)(yyvsp[-2]);
            ((args_list_s*)(yyval))->expression = (expression_s*)(yyvsp[0]);
         }
#line 3029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 946 "cd_yacc_cgen.y" /* yacc.c:1646  */
    {
            (yyval) = (char*)(new args_list_s);
            ((args_list_s*)(yyval))->next = NULL;
            ((args_list_s*)(yyval))->expression = (expression_s*)(yyvsp[0]);
}
#line 3039 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3043 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 952 "cd_yacc_cgen.y" /* yacc.c:1906  */



int yyerror(const char *s)
{
    //printf("line %d: %s\n",line_no,s);
    return 0;
}

int main(int argc, char* args[])
{
    extern FILE* yyin, *out;
    string filename;
    if(argc==1)
        cin >> filename;
    else
        filename = string(args[1]);
    yyin = fopen(filename.c_str(), "r");
    if (yyin == NULL) {
        //printf("cannot open pascal.pas\n");
        system("Pause");
        return 0;
    }
    yyparse();
    
    //yacc test
    extern void outputCode(program_s&);
    if(finished)
        outputCode(program);
    else
        printf("parse failed.\n");

#ifdef UC
    /*code generation*/
    codeGenerate cg(&program);
#endif
    
    fclose(yyin);
    return 0;
}
