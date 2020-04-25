/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         mdl_yyparse
#define yylex           mdl_yylex
#define yyerror         mdl_yyerror
#define yydebug         mdl_yydebug
#define yynerrs         mdl_yynerrs


/* Copy the first part of user declarations.  */

#line 73 "../../Private/MatC/MDL/MDLParser.inl" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int mdl_yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    STRING_LITERAL = 258,
    SEMICOLON = 259,
    COMMA = 260,
    MDL = 261,
    IMPORT = 262,
    USING = 263,
    MODULE = 264,
    EXPORT = 265,
    UNIFORM = 266,
    VARYING = 267,
    BOOL = 268,
    BOOL2 = 269,
    BOOL3 = 270,
    BOOL4 = 271,
    INT = 272,
    INT2 = 273,
    INT3 = 274,
    INT4 = 275,
    FLOAT = 276,
    FLOAT2 = 277,
    FLOAT3 = 278,
    FLOAT4 = 279,
    FLOAT2X2 = 280,
    FLOAT2X3 = 281,
    FLOAT2X4 = 282,
    FLOAT3X2 = 283,
    FLOAT3X3 = 284,
    FLOAT3X4 = 285,
    FLOAT4X2 = 286,
    FLOAT4X3 = 287,
    FLOAT4X4 = 288,
    DOUBLE = 289,
    DOUBLE2 = 290,
    DOUBLE3 = 291,
    DOUBLE4 = 292,
    DOUBLE2X2 = 293,
    DOUBLE2X3 = 294,
    DOUBLE2X4 = 295,
    DOUBLE3X2 = 296,
    DOUBLE3X3 = 297,
    DOUBLE3X4 = 298,
    DOUBLE4X2 = 299,
    DOUBLE4X3 = 300,
    DOUBLE4X4 = 301,
    COLOR = 302,
    STRING = 303,
    SDF = 304,
    EDF = 305,
    VDF = 306,
    LIGHT_PROFILE = 307,
    MATERIAL = 308,
    MATERIAL_EMISSION = 309,
    MATERIAL_GEOMETRY = 310,
    MATERIAL_SURFACE = 311,
    MATERIAL_VOLUME = 312,
    TEXTURE_2D = 313,
    TEXTURE_3D = 314,
    TEXTURE_CUBE = 315,
    TEXTURE_PTEX = 316,
    BSDF_MEASUREMENT = 317,
    INTENSITY_MODE = 318,
    INTENSITY_RADIANT_EXITANCE = 319,
    INTENSITY_POWER = 320,
    HAIR_BSDF = 321,
    TRUE = 322,
    FALSE = 323,
    LET = 324,
    IN = 325,
    ANNOTATION = 326,
    CONST = 327,
    TYPEDEF = 328,
    STRUCT = 329,
    ENUM = 330,
    IF = 331,
    ELSE = 332,
    SWITCH = 333,
    CASE = 334,
    DEFAULT = 335,
    WHILE = 336,
    DO = 337,
    FOR = 338,
    BREAK = 339,
    CONTINUE = 340,
    RETURN = 341,
    CAST = 342,
    ASSIGN_OP = 343,
    BITWISE_OR_ASSIGN_OP = 344,
    BITWISE_AND_ASSIGN_OP = 345,
    BITWISE_XOR_ASSIGN_OP = 346,
    SHIFT_LEFT_ASSIGN_OP = 347,
    SHIFT_RIGHT_ASSIGN_OP = 348,
    UNSIGNED_SHIFT_RIGHT_ASSIGN_OP = 349,
    MULTIPLY_ASSIGN_OP = 350,
    DIVIDE_ASSIGN_OP = 351,
    MODULO_ASSIGN_OP = 352,
    PLUS_ASSIGN_OP = 353,
    MINUS_ASSIGN_OP = 354,
    CONDITIONAL_OP = 355,
    LOGICAL_OR_OP = 356,
    LOGICAL_AND_OP = 357,
    BITWISE_OR_OP = 358,
    BITWISE_XOR_OP = 359,
    BITWISE_AND_OP = 360,
    EQUAL_OP = 361,
    NOT_EQUAL_OP = 362,
    LESS_OR_EQUAL_OP = 363,
    GREATER_OR_EQUAL_OP = 364,
    SHIFT_LEFT_OP = 365,
    SHIFT_RIGHT_OP = 366,
    UNSIGNED_SHIFT_RIGHT_OP = 367,
    DIVIDE_OP = 368,
    MODULO_OP = 369,
    BITWISE_COMPLEMENT_OP = 370,
    LOGICAL_NOT_OP = 371,
    POSITIVE_OP = 372,
    NEGATIVE_OP = 373,
    INCREMENT_OP = 374,
    DECREMENT_OP = 375,
    DOT = 376,
    DOTDOT = 377,
    SCOPE = 378,
    STAR = 379,
    COLON = 380,
    ANNOTATION_BLOCK_BEGIN = 381,
    ANNOTATION_BLOCK_END = 382,
    LEFT_PARENTHESIS = 383,
    RIGHT_PARENTHESIS = 384,
    LEFT_SQUARE_BRACKET = 385,
    RIGHT_SQUARE_BRACKET = 386,
    LEFT_ANGLE_BRACKET = 387,
    RIGHT_ANGLE_BRACKET = 388,
    LEFT_CURLY_BRACE = 389,
    RIGHT_CURLY_BRACE = 390,
    IDENT = 391,
    INTEGER_LITERAL = 392,
    FLOATING_LITERAL = 393
  };
#endif
/* Tokens.  */
#define STRING_LITERAL 258
#define SEMICOLON 259
#define COMMA 260
#define MDL 261
#define IMPORT 262
#define USING 263
#define MODULE 264
#define EXPORT 265
#define UNIFORM 266
#define VARYING 267
#define BOOL 268
#define BOOL2 269
#define BOOL3 270
#define BOOL4 271
#define INT 272
#define INT2 273
#define INT3 274
#define INT4 275
#define FLOAT 276
#define FLOAT2 277
#define FLOAT3 278
#define FLOAT4 279
#define FLOAT2X2 280
#define FLOAT2X3 281
#define FLOAT2X4 282
#define FLOAT3X2 283
#define FLOAT3X3 284
#define FLOAT3X4 285
#define FLOAT4X2 286
#define FLOAT4X3 287
#define FLOAT4X4 288
#define DOUBLE 289
#define DOUBLE2 290
#define DOUBLE3 291
#define DOUBLE4 292
#define DOUBLE2X2 293
#define DOUBLE2X3 294
#define DOUBLE2X4 295
#define DOUBLE3X2 296
#define DOUBLE3X3 297
#define DOUBLE3X4 298
#define DOUBLE4X2 299
#define DOUBLE4X3 300
#define DOUBLE4X4 301
#define COLOR 302
#define STRING 303
#define SDF 304
#define EDF 305
#define VDF 306
#define LIGHT_PROFILE 307
#define MATERIAL 308
#define MATERIAL_EMISSION 309
#define MATERIAL_GEOMETRY 310
#define MATERIAL_SURFACE 311
#define MATERIAL_VOLUME 312
#define TEXTURE_2D 313
#define TEXTURE_3D 314
#define TEXTURE_CUBE 315
#define TEXTURE_PTEX 316
#define BSDF_MEASUREMENT 317
#define INTENSITY_MODE 318
#define INTENSITY_RADIANT_EXITANCE 319
#define INTENSITY_POWER 320
#define HAIR_BSDF 321
#define TRUE 322
#define FALSE 323
#define LET 324
#define IN 325
#define ANNOTATION 326
#define CONST 327
#define TYPEDEF 328
#define STRUCT 329
#define ENUM 330
#define IF 331
#define ELSE 332
#define SWITCH 333
#define CASE 334
#define DEFAULT 335
#define WHILE 336
#define DO 337
#define FOR 338
#define BREAK 339
#define CONTINUE 340
#define RETURN 341
#define CAST 342
#define ASSIGN_OP 343
#define BITWISE_OR_ASSIGN_OP 344
#define BITWISE_AND_ASSIGN_OP 345
#define BITWISE_XOR_ASSIGN_OP 346
#define SHIFT_LEFT_ASSIGN_OP 347
#define SHIFT_RIGHT_ASSIGN_OP 348
#define UNSIGNED_SHIFT_RIGHT_ASSIGN_OP 349
#define MULTIPLY_ASSIGN_OP 350
#define DIVIDE_ASSIGN_OP 351
#define MODULO_ASSIGN_OP 352
#define PLUS_ASSIGN_OP 353
#define MINUS_ASSIGN_OP 354
#define CONDITIONAL_OP 355
#define LOGICAL_OR_OP 356
#define LOGICAL_AND_OP 357
#define BITWISE_OR_OP 358
#define BITWISE_XOR_OP 359
#define BITWISE_AND_OP 360
#define EQUAL_OP 361
#define NOT_EQUAL_OP 362
#define LESS_OR_EQUAL_OP 363
#define GREATER_OR_EQUAL_OP 364
#define SHIFT_LEFT_OP 365
#define SHIFT_RIGHT_OP 366
#define UNSIGNED_SHIFT_RIGHT_OP 367
#define DIVIDE_OP 368
#define MODULO_OP 369
#define BITWISE_COMPLEMENT_OP 370
#define LOGICAL_NOT_OP 371
#define POSITIVE_OP 372
#define NEGATIVE_OP 373
#define INCREMENT_OP 374
#define DECREMENT_OP 375
#define DOT 376
#define DOTDOT 377
#define SCOPE 378
#define STAR 379
#define COLON 380
#define ANNOTATION_BLOCK_BEGIN 381
#define ANNOTATION_BLOCK_END 382
#define LEFT_PARENTHESIS 383
#define RIGHT_PARENTHESIS 384
#define LEFT_SQUARE_BRACKET 385
#define RIGHT_SQUARE_BRACKET 386
#define LEFT_ANGLE_BRACKET 387
#define RIGHT_ANGLE_BRACKET 388
#define LEFT_CURLY_BRACE 389
#define RIGHT_CURLY_BRACE 390
#define IDENT 391
#define INTEGER_LITERAL 392
#define FLOATING_LITERAL 393

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif



int mdl_yyparse (void *pUserData, void *pScanner);



/* Copy the second part of user declarations.  */

#line 410 "../../Private/MatC/MDL/MDLParser.inl" /* yacc.c:358  */
/* Unqualified %code blocks.  */
#line 13 "../../Private/MatC/MDL/MDLParser.y" /* yacc.c:359  */

    int yylex(union YYSTYPE *lvalp, YYLTYPE *llocp, void *pUserData, void *pScanner);
    void yyerror(YYLTYPE *llocp, void *pUserData, void *pScanner, const char *s);

#line 417 "../../Private/MatC/MDL/MDLParser.inl" /* yacc.c:359  */

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYLAST   4584

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  139
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  97
/* YYNRULES -- Number of rules.  */
#define YYNRULES  376
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  671

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   393

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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   166,   166,   167,   168,   169,   170,   171,   172,   173,
     175,   177,   178,   180,   181,   183,   184,   186,   187,   189,
     190,   192,   193,   194,   195,   197,   198,   200,   201,   202,
     203,   204,   205,   206,   207,   209,   210,   212,   214,   215,
     217,   219,   220,   222,   224,   225,   227,   229,   230,   232,
     233,   234,   235,   236,   237,   239,   240,   241,   242,   243,
     244,   245,   246,   248,   249,   251,   253,   254,   256,   257,
     258,   259,   261,   262,   263,   265,   267,   268,   269,   270,
     272,   273,   275,   276,   277,   278,   280,   281,   282,   283,
     285,   286,   288,   289,   290,   291,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   332,   333,   334,   335,   337,   338,   340,   341,
     343,   344,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   361,   362,   363,   364,
     366,   367,   368,   370,   371,   373,   374,   376,   377,   378,
     379,   381,   382,   384,   386,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   414,
     416,   418,   420,   421,   423,   424,   426,   427,   428,   429,
     431,   433,   434,   436,   437,   439,   441,   442,   443,   444,
     446,   447,   449,   450,   452,   454,   459,   460,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   476,   477,   479,   480,   482,   483,   485,   486,   488,
     489,   491,   492,   494,   495,   496,   498,   499,   500,   501,
     502,   504,   505,   506,   507,   509,   510,   511,   513,   514,
     515,   516,   518,   519,   520,   521,   522,   523,   524,   525,
     527,   528,   530,   531,   532,   533,   534,   535,   536,   538,
     539,   540,   541,   543,   544,   545,   546,   547,   549,   551,
     553,   554,   556,   557,   558,   559,   561,   562,   564,   566,
     568,   569,   571,   572,   573,   575,   576,   577,   578,   580,
     581,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   625,   626,   627,   628,   629,   630,   631,
     632,   633,   634,   635,   636,   637,   639
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "STRING_LITERAL", "SEMICOLON", "COMMA",
  "MDL", "IMPORT", "USING", "MODULE", "EXPORT", "UNIFORM", "VARYING",
  "BOOL", "BOOL2", "BOOL3", "BOOL4", "INT", "INT2", "INT3", "INT4",
  "FLOAT", "FLOAT2", "FLOAT3", "FLOAT4", "FLOAT2X2", "FLOAT2X3",
  "FLOAT2X4", "FLOAT3X2", "FLOAT3X3", "FLOAT3X4", "FLOAT4X2", "FLOAT4X3",
  "FLOAT4X4", "DOUBLE", "DOUBLE2", "DOUBLE3", "DOUBLE4", "DOUBLE2X2",
  "DOUBLE2X3", "DOUBLE2X4", "DOUBLE3X2", "DOUBLE3X3", "DOUBLE3X4",
  "DOUBLE4X2", "DOUBLE4X3", "DOUBLE4X4", "COLOR", "STRING", "SDF", "EDF",
  "VDF", "LIGHT_PROFILE", "MATERIAL", "MATERIAL_EMISSION",
  "MATERIAL_GEOMETRY", "MATERIAL_SURFACE", "MATERIAL_VOLUME", "TEXTURE_2D",
  "TEXTURE_3D", "TEXTURE_CUBE", "TEXTURE_PTEX", "BSDF_MEASUREMENT",
  "INTENSITY_MODE", "INTENSITY_RADIANT_EXITANCE", "INTENSITY_POWER",
  "HAIR_BSDF", "TRUE", "FALSE", "LET", "IN", "ANNOTATION", "CONST",
  "TYPEDEF", "STRUCT", "ENUM", "IF", "ELSE", "SWITCH", "CASE", "DEFAULT",
  "WHILE", "DO", "FOR", "BREAK", "CONTINUE", "RETURN", "CAST", "ASSIGN_OP",
  "BITWISE_OR_ASSIGN_OP", "BITWISE_AND_ASSIGN_OP", "BITWISE_XOR_ASSIGN_OP",
  "SHIFT_LEFT_ASSIGN_OP", "SHIFT_RIGHT_ASSIGN_OP",
  "UNSIGNED_SHIFT_RIGHT_ASSIGN_OP", "MULTIPLY_ASSIGN_OP",
  "DIVIDE_ASSIGN_OP", "MODULO_ASSIGN_OP", "PLUS_ASSIGN_OP",
  "MINUS_ASSIGN_OP", "CONDITIONAL_OP", "LOGICAL_OR_OP", "LOGICAL_AND_OP",
  "BITWISE_OR_OP", "BITWISE_XOR_OP", "BITWISE_AND_OP", "EQUAL_OP",
  "NOT_EQUAL_OP", "LESS_OR_EQUAL_OP", "GREATER_OR_EQUAL_OP",
  "SHIFT_LEFT_OP", "SHIFT_RIGHT_OP", "UNSIGNED_SHIFT_RIGHT_OP",
  "DIVIDE_OP", "MODULO_OP", "BITWISE_COMPLEMENT_OP", "LOGICAL_NOT_OP",
  "POSITIVE_OP", "NEGATIVE_OP", "INCREMENT_OP", "DECREMENT_OP", "DOT",
  "DOTDOT", "SCOPE", "STAR", "COLON", "ANNOTATION_BLOCK_BEGIN",
  "ANNOTATION_BLOCK_END", "LEFT_PARENTHESIS", "RIGHT_PARENTHESIS",
  "LEFT_SQUARE_BRACKET", "RIGHT_SQUARE_BRACKET", "LEFT_ANGLE_BRACKET",
  "RIGHT_ANGLE_BRACKET", "LEFT_CURLY_BRACE", "RIGHT_CURLY_BRACE", "IDENT",
  "INTEGER_LITERAL", "FLOATING_LITERAL", "$accept", "mdl", "mdl_version",
  "import_declarations", "global_declarations", "variable_declarations",
  "import_declaration", "qualified_imports", "qualified_import_prefix",
  "unqualified_import", "qualified_import",
  "unqualified_import_simple_names",
  "qualified_import_prefix_relative_current",
  "qualified_import_prefix_relative_parent",
  "qualified_import_prefix_absolute", "qualified_name_infix",
  "qualified_import_suffix", "module_declaration", "variable_declaration",
  "variable_declarators", "variable_declarator", "global_declaration",
  "annotation_declaration", "constant_declaration", "constant_declarators",
  "constant_declarator", "type_declaration", "alias_type_declaration",
  "struct_type_declaration", "struct_field_declarators",
  "struct_field_declarator", "enum_type_declaration",
  "enum_value_declarators", "enum_value_declarator",
  "function_declaration", "compound_statement", "statements", "statement",
  "matched_statement", "unmatched_statement", "matched_if_statement",
  "unmatched_if_statement", "switch_statement", "switch_cases",
  "switch_case", "matched_while_statement", "unmatched_while_statement",
  "matched_do_statement", "unmatched_do_statement",
  "matched_for_statement", "unmatched_for_statement", "break_statement",
  "continue_statement", "return_statement", "parameter_list", "parameters",
  "parameter", "annotation_block", "annotations", "qualified_name",
  "annotation", "argument_list", "named_arguments", "positional_arguments",
  "named_argument", "positional_argument", "comma_expression",
  "assignment_expression", "conditional_expression",
  "logical_or_expression", "logical_and_expression",
  "inclusive_or_expression", "exclusive_or_expression", "and_expression",
  "equality_expression", "relational_expression", "shift_expression",
  "additive_expression", "multiplicative_expression", "unary_expression",
  "postfix_expression", "matched_postfix_expression",
  "matched_primary_expression", "unmatched_postfix_expression",
  "unmatched_primary_expression", "cast_expression", "let_expression",
  "literal_expression", "boolean_literal", "integer_literal",
  "floating_literal", "string_literal", "type", "array_type",
  "simple_type", "relative_type", "simple_name", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393
};
# endif

#define YYPACT_NINF -348

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-348)))

#define YYTABLE_NINF -319

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       7,   -91,    59,  2981,    80,  -348,   -87,    10,  3107,  4394,
    4394,  -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,
    -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,
    -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,
    -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,
    -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,
    -348,  -348,  -348,  -348,  -348,   -46,  4270,  4270,   -46,   -46,
    4448,  -348,  2981,  3234,  -348,   -19,  3234,  -348,  -348,  -348,
    -348,  -348,  -348,  -348,  -348,   -27,  -348,   -23,  -348,  -348,
    -348,   -12,   103,  -348,   307,  -348,   -46,   -47,   -46,   105,
    -348,    85,   228,   -87,  -348,  -348,  -348,  -348,  -348,  -348,
     128,   -46,   -46,    88,   124,  -348,  3234,  -348,  3234,  3360,
    -348,   -46,  3234,   -46,   148,  1204,  -348,  -348,  -348,   -87,
     105,   116,   105,   105,  -121,  -348,   -46,   -19,    43,   163,
    -348,  -348,   246,   -46,   -47,   -46,   -19,  3668,    27,   320,
    -348,   -61,   299,  3724,   182,   137,   184,  3234,  -348,   192,
    3486,    54,  -348,  -348,  -348,  3850,   190,  2849,  2849,  2849,
    2849,  2849,  2849,  2849,  -348,   -46,  -348,  -348,   202,   229,
     245,   248,   255,   244,   230,    84,   233,   250,   168,  -348,
    -348,   159,  -348,   220,  -348,  -348,  -348,  -348,  -348,  -348,
    -348,   351,   242,  -348,  -348,  -348,  -348,  -348,  -348,   -19,
      85,  -348,  1456,  -348,   -92,   -19,   -19,   -19,  -348,    20,
    -348,   -46,  -348,   370,  -348,   -46,  2849,   253,  -348,   372,
    3906,  -348,   -46,  4032,   390,    46,  -348,   119,   263,  3542,
      70,   271,  -348,    12,    26,  2849,   694,  -348,    13,  4270,
     333,   -46,  4270,  -348,  -348,  -348,  -348,  -348,  -348,   276,
     404,  -348,   419,   291,  -348,  2849,  2849,  2849,  2849,  2849,
    2849,  2849,  2849,  2849,  2849,  2849,  2849,  2849,  2849,  2849,
    2849,  2849,  2849,  2849,  2849,  -348,  -348,   -46,  2849,  -348,
    -348,  -348,   -46,  -348,  -348,  1583,  -348,  -348,    48,    71,
    -348,  -348,  -348,   300,  -348,   422,   423,  -348,  4270,  -348,
     121,  -348,  -348,   253,  -348,  -348,   425,  -348,     0,   427,
    4088,  -348,   -46,   431,  2849,  -348,   433,    52,   298,  -348,
      39,    57,  2849,  -348,    29,   125,  -348,  2849,  -348,    35,
    -348,  2849,  -348,    42,   435,  -348,   314,   319,   321,   950,
     324,   449,   450,  2849,  -348,  -348,  -348,  -348,  -348,   822,
    -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,
    -348,  -348,  -348,  -348,  -348,   451,   -74,  -348,  2849,  -348,
    4214,  -348,  2849,   403,  -348,   -20,   326,  -348,  2849,  2849,
    2849,  2849,  2849,  2849,  2849,  2849,  2849,  2849,  2849,  2849,
    2849,   334,   339,   245,   248,   255,   244,   230,    84,    84,
     233,   233,   233,   233,   250,   250,   250,   168,   168,  -348,
    -348,  -348,  -348,   335,  -348,  -348,   338,   -46,  -348,  2849,
    -348,  2849,  -348,   -46,  -348,  2849,  -348,  -348,  -348,  -348,
    2849,   466,  -348,   469,  -348,  -348,   253,  -348,   470,   131,
    -348,  2849,  -348,    91,  -348,  2849,  -348,   101,   472,  -348,
    2849,  -348,  2849,   389,   475,  -348,  2849,  -348,   476,  -348,
    2849,  -348,  -348,  2849,  2849,  2849,   401,   402,  1078,  -348,
    -348,   481,  -348,  -348,  -348,  1330,   483,   418,  -348,  -348,
    -348,   -46,  2849,  -348,   253,   361,  -348,  -348,  -348,  -348,
    -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,
    2849,  -348,  -348,  -348,   300,    74,  -348,  -348,  -348,   253,
      56,  -348,  -348,  -348,  -348,  2849,   405,   487,  -348,  2849,
    -348,   490,  -348,  2849,  -348,  -348,   491,   493,  2849,  -348,
     494,  -348,   495,   375,   376,   392,   373,   394,  1709,  1835,
     519,  -348,   388,   395,  -348,  2849,  -348,   253,  -348,  2849,
    -348,  -348,  -348,  -348,   521,   523,  2849,  -348,   524,  -348,
     525,  -348,  -348,   526,  -348,  -348,   950,   398,   950,  2849,
    2849,  1961,   529,  2088,   530,  2215,   399,  -348,  -348,   407,
    -348,  -348,   534,  -348,  -348,  -348,  -348,   462,   -39,  -348,
    -348,   411,   413,   950,   414,  2341,   950,   416,  2468,  2595,
     542,  -348,  -348,   950,  2849,   424,  -348,   -25,  -348,   543,
     544,  -348,  -348,   950,   950,   421,  -348,  -348,   950,   950,
     426,   950,   428,  2722,  -348,  -348,   434,   950,  -348,  -348,
    -348,  -348,  -348,  -348,  -348,  -348,   950,  -348,  -348,  -348,
    -348,   950,  -348,  -348,   950,   950,   429,   950,  -348,  -348,
    -348,  -348,  -348,  -348,  -348,  -348,  -348,   950,  -348,  -348,
    -348
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     9,     0,     1,     0,     0,     0,     0,
       0,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,     0,     0,     0,     0,     0,
       0,   376,     6,     8,    12,   375,     7,    14,    59,    60,
      61,    72,    73,    74,    62,     0,   314,   318,   320,    42,
      10,     0,     0,    40,     0,    20,     0,     0,     0,    34,
      45,     0,     0,     0,    55,    56,    57,    58,   313,   312,
       0,     0,     0,     0,     0,   319,     3,    11,     5,     0,
      13,     0,     4,     0,     0,     0,    37,    39,    17,     0,
      31,     0,    32,    33,     0,    30,     0,   214,     0,     0,
     212,    44,     0,     0,     0,     0,    24,     0,     0,     0,
      67,     0,     0,     0,     0,     0,     0,     2,    41,     0,
       0,     0,   311,   306,   307,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   317,     0,   308,   309,     0,   242,
     244,   246,   248,   250,   252,   255,   260,   264,   267,   271,
     278,   280,   287,   281,   297,   288,   279,   291,   302,   303,
     304,   305,   298,    19,    27,    38,    28,    29,    43,   213,
       0,   210,     0,   215,     0,    21,    22,    23,   203,     0,
     205,     0,    64,     0,    65,     0,     0,    69,    75,     0,
       0,    81,     0,     0,     0,     0,    91,    95,     0,     0,
       0,     0,   107,     0,     0,     0,     0,   119,     0,     0,
       0,     0,     0,   272,   273,   274,   275,   276,   277,     0,
     227,   240,   242,     0,   316,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   282,   283,     0,     0,   285,
     293,   294,     0,   296,   310,     0,   211,   219,     0,     0,
     221,   223,   225,    42,    26,     0,    25,    36,     0,   202,
     209,    63,    66,    71,    68,    79,     0,    80,     0,     0,
       0,    89,     0,     0,     0,    94,     0,     0,     0,   101,
       0,     0,     0,   113,     0,     0,   105,     0,   117,     0,
     106,     0,   118,     0,     0,   155,     0,     0,     0,     0,
       0,     0,     0,     0,   137,   153,   144,   143,   142,     0,
     139,   140,   141,   145,   156,   146,   147,   157,   148,   158,
     149,   159,   150,   151,   152,     0,   298,   104,     0,   116,
       0,    16,     0,     0,    48,    54,     0,   292,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   243,   245,   247,   249,   251,   253,   254,
     257,   258,   256,   259,   261,   262,   263,   265,   266,   269,
     270,   268,   284,     0,   295,   290,     0,     0,   217,     0,
     218,     0,    18,     0,   204,     0,   208,    70,    77,    85,
       0,     0,    78,     0,    90,    87,    93,    88,     0,     0,
      99,     0,   111,     0,   100,     0,   112,     0,     0,    98,
       0,   110,     0,     0,     0,   102,     0,   114,     0,   103,
       0,   115,   131,     0,     0,     0,     0,     0,     0,   199,
     200,     0,   136,   138,   154,     0,     0,     0,    15,   300,
      46,     0,     0,    53,    50,     0,   226,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   315,
       0,   286,   289,   220,     0,     0,   222,   224,    35,   207,
       0,    84,    76,    92,    86,     0,     0,     0,    96,     0,
     108,     0,    97,     0,   109,   125,     0,     0,     0,   129,
       0,   130,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   201,   290,     0,   128,     0,    47,    52,    49,     0,
     241,   216,   206,    83,     0,     0,     0,   123,     0,   124,
       0,   122,   135,     0,   126,   127,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   289,   301,    51,     0,
      82,   133,     0,   120,   121,   134,   161,   140,     0,   171,
     172,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   299,   132,     0,     0,     0,   164,     0,   166,     0,
       0,   186,   198,     0,     0,     0,   178,   190,     0,     0,
       0,     0,     0,     0,   160,   162,     0,   170,   163,   165,
     173,   174,   185,   197,   184,   196,     0,   177,   189,   176,
     188,     0,   182,   194,     0,     0,     0,   168,   169,   183,
     195,   175,   187,   181,   193,   180,   192,     0,   167,   179,
     191
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -348,  -348,  -348,  -348,   176,  -348,   479,  -348,  -348,  -348,
     432,  -348,   453,   457,   459,   268,   153,   480,  -157,  -348,
      62,   -45,     3,    21,  -348,   340,    83,  -348,  -348,   330,
    -110,  -348,   328,   247,    79,  -119,  -348,  -347,  -183,  -271,
    -348,  -348,  -348,  -348,   -53,  -348,  -348,  -348,  -348,  -348,
    -348,  -348,  -348,  -348,   -79,  -348,   259,   -76,  -348,  -348,
     358,  -141,   141,  -348,   144,   145,  -147,  -129,  -124,  -123,
     306,   309,   310,   308,   311,   143,    23,   111,   136,  -149,
    -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,
    -348,  -348,   384,   412,    -3,   509,    63
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    72,    73,   380,    74,    94,   142,   305,
      95,   306,    96,    97,    98,    75,   135,    76,   355,   383,
     384,    77,    78,   356,   149,   150,   357,    81,    82,   230,
     231,    83,   235,   236,    84,   358,   359,   360,   361,   362,
     363,   364,   365,   617,   618,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   148,   219,   220,   102,   138,   139,
     140,   213,   298,   299,   300,   301,   375,   260,   261,   262,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   251,    86,   202,    88,    89
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      87,   178,   179,   208,   439,    87,    87,    87,   250,   123,
     227,   104,   483,     1,   100,    71,   336,   377,   253,   254,
     255,   256,   257,   258,    79,   308,   259,   226,   120,   105,
     340,   222,   304,   459,    91,    92,    93,   154,   156,   465,
     614,   615,   247,   450,    71,   161,   469,     4,   210,    71,
     289,   322,   293,   427,   614,   615,   485,   322,   242,     5,
     563,   454,  -318,    87,    87,   243,   244,   212,   492,    87,
      87,   120,   223,    87,   329,   131,   429,   120,   477,   427,
     240,   330,   331,   302,    90,   248,    80,   107,   440,    71,
      71,   106,   381,    79,    79,   528,   616,    79,   344,   101,
     337,   378,   313,   179,   121,   532,   101,   125,   212,    71,
     638,   126,   120,    87,   341,    87,    87,   460,   402,    87,
     317,   333,   104,   466,   338,   342,   101,   451,   110,   379,
     470,   113,   114,   419,   420,   421,   101,    79,   101,    79,
     105,   423,   245,    79,    87,   455,   246,   246,   124,   309,
      87,   314,   101,   101,    87,    80,    80,    87,   332,    80,
     246,   325,    87,   246,   334,   101,   476,   339,   343,   246,
     211,   426,   179,   246,   151,   152,   246,   428,    79,   529,
     101,   323,   101,   101,   158,   458,   159,   448,   246,   533,
     464,   246,   273,   274,   468,   446,   101,   158,   107,    80,
     430,    80,   106,   561,   246,    80,   481,   324,   136,   435,
     317,   452,   456,   462,   101,   461,   275,   276,   237,   525,
     467,    71,   153,   488,   471,   246,   127,    87,   134,   596,
      87,   486,   141,   489,   436,   246,    87,   437,   263,   205,
      80,   496,   441,   376,   494,   101,    87,   101,   116,    87,
     101,   101,   122,   214,   453,   457,   147,   101,   155,   463,
     497,   498,   499,   500,   501,   502,   503,   504,   505,   506,
     507,   508,   234,    71,    99,   303,   160,   307,   285,   286,
     287,   282,   283,   204,   310,   206,   207,   212,   151,   288,
     658,   212,   284,   520,   157,   318,   410,   411,   412,   413,
     302,   237,   517,   228,   527,    87,   519,   600,   531,   493,
     668,   128,   129,   536,   385,   537,   233,    87,   238,   540,
     239,   549,   252,   542,   224,   225,   543,   544,   545,   265,
     266,   550,   622,   264,   530,   627,   271,   272,   534,   290,
     291,   292,   635,   277,   278,   279,   376,   267,   212,   270,
     422,   268,   643,   645,   294,   424,   376,   648,   650,   269,
     653,   553,   179,   557,   130,   132,   133,   280,   281,   137,
     523,   146,   295,   526,   311,   660,   315,    87,   565,   101,
     662,   560,   568,   664,   666,   237,   570,    85,   414,   415,
     416,   573,    85,   597,   321,   599,   670,    99,   326,    71,
     335,   582,   584,   382,   209,   387,   587,   490,   491,   388,
     589,   215,   216,   217,   408,   409,   417,   418,   558,   592,
     621,   108,   109,   626,   401,   431,   432,   449,   433,   438,
     634,   442,   601,   602,   604,   445,   607,   447,   610,   472,
     642,   644,   473,   562,   564,   647,   649,   474,   652,   475,
     111,   112,   478,   479,   480,   484,    85,    85,   625,   495,
      85,   630,   632,   659,   510,   509,   511,   636,   661,   512,
     521,   663,   665,   522,   524,   376,   535,   538,   137,   539,
     541,   588,   546,   547,   669,   551,   656,   554,   555,   559,
     514,   567,   303,   566,   569,   571,   518,   572,   574,   575,
      85,   579,    85,    85,   576,   577,    85,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,   400,   265,
     266,   578,   580,   585,  -317,   590,   586,   591,   593,   594,
     595,   221,   598,   605,   608,  -316,   611,   232,   612,   613,
     619,    85,   620,   623,   221,   628,   633,   640,   641,   637,
     646,   117,   118,   556,   385,   651,   143,   654,   667,   657,
     144,   203,   145,   320,   639,   312,   327,   434,   296,   444,
     515,   513,   403,   376,   516,   376,   404,   406,   405,   115,
       0,   407,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     376,     0,     0,   376,     0,     0,     0,     0,     0,     0,
     376,     0,     0,     0,   232,     0,     0,   232,     0,     0,
     376,   376,     0,   221,     0,   376,   376,     0,   376,     0,
       0,     0,     0,     0,   376,     0,   386,     0,     0,     0,
       0,     0,     0,   376,     0,     0,     0,     0,   376,     0,
       0,   376,   376,     0,   376,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   376,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   221,     0,     0,     0,     0,   162,   345,     0,
       0,     0,     0,     0,   232,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,   163,   164,   165,     0,     0,    66,    67,    68,    69,
     346,     0,   347,     0,     0,   348,   349,   350,   351,   352,
     353,   166,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   167,
     168,   169,   170,   171,   172,     0,     0,    70,     0,     0,
       0,     0,   173,     0,     0,   162,   345,     0,   246,   354,
      71,   176,   177,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,   163,
     164,   165,     0,     0,    66,    67,    68,    69,   346,     0,
     347,     0,     0,   348,   349,   350,   351,   352,   353,   166,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   167,   168,   169,
     170,   171,   172,     0,     0,    70,     0,     0,     0,     0,
     173,     0,     0,   162,   345,     0,   246,   482,    71,   176,
     177,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,   163,   164,   165,
       0,     0,    66,    67,    68,    69,   346,     0,   347,     0,
       0,   348,   349,   350,   351,   352,   353,   166,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   167,   168,   169,   170,   171,
     172,     0,     0,    70,     0,     0,     0,     0,   173,     0,
       0,   162,   548,     0,   246,     0,    71,   176,   177,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,   163,   164,   165,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   166,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   167,   168,   169,   170,   171,   172,     0,
       0,    70,     0,     0,     0,     0,   173,   162,     0,     0,
       0,     0,     0,     0,    71,   176,   177,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,   163,   164,   165,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   166,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   167,
     168,   169,   170,   171,   172,     0,     0,    70,     0,     0,
       0,     0,   173,   162,     0,   174,   175,     0,     0,     0,
      71,   176,   177,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,   163,   164,   165,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   166,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   167,   168,   169,   170,   171,
     172,     0,     0,    70,     0,     0,     0,     0,   173,   162,
       0,   552,   175,     0,     0,     0,    71,   176,   177,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,   163,   164,   165,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   166,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   167,   168,   169,   170,   171,   172,     0,     0,    70,
       0,     0,     0,     0,   173,   297,   162,     0,     0,     0,
       0,     0,    71,   176,   177,     0,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
     163,   164,   165,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     166,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   167,   168,
     169,   170,   171,   172,     0,     0,    70,     0,     0,     0,
       0,   173,   162,   581,   425,     0,     0,     0,     0,    71,
     176,   177,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,   163,   164,   165,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   166,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   167,   168,   169,   170,   171,   172,
       0,     0,    70,     0,     0,     0,     0,   173,   162,   583,
       0,     0,     0,     0,     0,    71,   176,   177,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,   163,   164,   165,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   166,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     167,   168,   169,   170,   171,   172,     0,     0,    70,     0,
       0,     0,     0,   173,   162,     0,     0,     0,     0,     0,
       0,    71,   176,   177,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,   163,   164,
     165,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   166,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   167,   168,   169,   170,
     171,   172,     0,     0,    70,     0,     0,     0,     0,   173,
     603,   162,     0,     0,     0,     0,     0,    71,   176,   177,
       0,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,   163,   164,   165,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   166,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   167,   168,   169,   170,   171,   172,     0,
       0,    70,     0,     0,     0,     0,   173,   606,   162,   609,
       0,     0,     0,     0,    71,   176,   177,     0,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,   163,   164,   165,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   166,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     167,   168,   169,   170,   171,   172,     0,     0,    70,     0,
       0,     0,     0,   173,   162,     0,     0,     0,     0,     0,
       0,    71,   176,   177,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,   163,   164,
     165,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   166,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   167,   168,   169,   170,
     171,   172,     0,     0,    70,     0,     0,     0,     0,   173,
     624,   162,     0,     0,     0,     0,     0,    71,   176,   177,
       0,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,   163,   164,   165,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   166,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   167,   168,   169,   170,   171,   172,     0,
       0,    70,     0,     0,     0,     0,   173,   629,   162,     0,
       0,     0,     0,     0,    71,   176,   177,     0,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,   163,   164,   165,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   166,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     167,   168,   169,   170,   171,   172,     0,     0,    70,     0,
       0,     0,     0,   173,   631,   162,     0,     0,     0,     0,
       0,    71,   176,   177,     0,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,   163,
     164,   165,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   166,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   167,   168,   169,
     170,   171,   172,     0,     0,    70,     0,     0,     0,     0,
     173,   655,   162,     0,     0,     0,     0,     0,    71,   176,
     177,     0,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,   163,   164,   165,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   166,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   167,   168,   169,   170,   171,   172,
       0,     0,    70,     0,     0,     0,     0,   173,     0,     0,
       0,     0,     0,     0,     0,    71,   176,   177,     6,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,     0,     0,
       0,     0,    65,    66,    67,    68,    69,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    70,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   103,     0,    71,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,     0,     0,     0,     0,    65,    66,
      67,    68,    69,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      70,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    71,   119,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,     0,     0,     0,     0,    65,    66,    67,    68,    69,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    70,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      71,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,     0,     0,     0,
       0,    65,    66,    67,    68,    69,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    70,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    71,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    70,
     241,     0,     0,     0,     0,   218,     0,     0,     0,     0,
       0,     0,    71,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    70,   328,     0,     0,     0,
       0,   218,     0,     0,     0,     0,     0,     0,    71,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    70,     0,     0,     0,     0,     0,   218,     0,     0,
       0,     0,     0,     0,    71,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    70,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   229,
      71,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    70,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   249,     0,    71,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    70,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   316,    71,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    70,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   319,    71,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    70,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   443,    71,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    70,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   487,
      71,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    70,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    71,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,     0,     0,    70,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      71,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    71
};

static const yytype_int16 yycheck[] =
{
       3,   125,   125,   124,     4,     8,     9,    10,   165,    85,
     151,     8,   359,     6,     4,   136,     4,     4,   167,   168,
     169,   170,   171,   172,     3,     5,   173,    88,    73,     8,
       4,     4,   124,     4,   121,   122,   123,   113,   114,     4,
      79,    80,   161,     4,   136,   124,     4,   138,     5,   136,
     191,     5,   193,     5,    79,    80,   130,     5,     4,     0,
       4,     4,   136,    66,    67,    11,    12,   128,    88,    72,
      73,   116,   148,    76,     4,   122,     5,   122,   349,     5,
     159,    11,    12,   212,     4,   161,     3,     8,    88,   136,
     136,     8,   249,    72,    73,     4,   135,    76,   245,   126,
      88,    88,   226,   226,   123,     4,   126,   130,   128,   136,
     135,   123,   157,   116,    88,   118,   119,    88,   265,   122,
     230,   240,   119,    88,   243,   244,   126,    88,    65,   248,
      88,    68,    69,   282,   283,   284,   126,   116,   126,   118,
     119,   288,    88,   122,   147,    88,   134,   134,    85,   129,
     153,   227,   126,   126,   157,    72,    73,   160,    88,    76,
     134,   237,   165,   134,   240,   126,   349,   243,   244,   134,
     127,   295,   295,   134,   111,   112,   134,   129,   157,    88,
     126,   135,   126,   126,   121,   332,   123,   135,   134,    88,
     337,   134,   108,   109,   341,   324,   126,   134,   119,   116,
     129,   118,   119,   129,   134,   122,   353,    88,   123,    88,
     320,   330,   331,    88,   126,   334,   132,   133,   155,    88,
     339,   136,   134,   380,   343,   134,   123,   230,   123,   576,
     233,   378,     4,   382,   310,   134,   239,   313,   175,   123,
     157,   388,   318,   246,   385,   126,   249,   126,    72,   252,
     126,   126,    76,     7,   330,   331,   128,   126,   134,   335,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   135,   136,     6,   212,   128,   214,   119,   120,
     121,   113,   114,   130,   221,   132,   133,   128,   225,   130,
     637,   128,   124,   440,   118,   232,   273,   274,   275,   276,
     429,   238,   431,     4,   451,   308,   435,   578,   455,   385,
     657,     4,     5,   460,   251,   462,   134,   320,   134,   466,
     128,   478,   132,   470,     4,     5,   473,   474,   475,   100,
     101,   478,   603,   131,   453,   606,   106,   107,   457,   119,
     120,   121,   613,   110,   111,   112,   349,   102,   128,   105,
     287,   103,   623,   624,     3,   292,   359,   628,   629,   104,
     631,   485,   485,   492,    96,    97,    98,   117,   118,   101,
     446,   103,   130,   449,     4,   646,     4,   380,   525,   126,
     651,   510,   529,   654,   655,   322,   533,     3,   277,   278,
     279,   538,     8,   576,     4,   578,   667,   129,   135,   136,
     129,   548,   549,    70,   136,   129,   555,     4,     5,     5,
     559,   143,   144,   145,   271,   272,   280,   281,   494,   566,
     603,     9,    10,   606,   133,   125,     4,   129,     5,     4,
     613,     4,   579,   580,   581,     4,   583,     4,   585,     4,
     623,   624,   128,   519,   520,   628,   629,   128,   631,   128,
      66,    67,   128,     4,     4,     4,    72,    73,   605,   133,
      76,   608,   609,   646,   125,   131,   131,   614,   651,   131,
       4,   654,   655,     4,     4,   478,     4,    88,   210,     4,
       4,   557,    81,    81,   667,     4,   633,     4,    70,   128,
     427,     4,   429,    88,     4,     4,   433,     4,     4,     4,
     116,   128,   118,   119,   129,   129,   122,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   129,   128,     4,   136,     4,   131,     4,     4,     4,
       4,   147,   134,     4,     4,   136,   129,   153,     4,    77,
     129,   157,   129,   129,   160,   129,     4,     4,     4,   125,
     129,    72,    72,   491,   491,   129,   103,   129,   129,   125,
     103,   129,   103,   233,   617,   225,   238,   308,   210,   322,
     429,   427,   266,   576,   429,   578,   267,   269,   268,    70,
      -1,   270,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     603,    -1,    -1,   606,    -1,    -1,    -1,    -1,    -1,    -1,
     613,    -1,    -1,    -1,   230,    -1,    -1,   233,    -1,    -1,
     623,   624,    -1,   239,    -1,   628,   629,    -1,   631,    -1,
      -1,    -1,    -1,    -1,   637,    -1,   252,    -1,    -1,    -1,
      -1,    -1,    -1,   646,    -1,    -1,    -1,    -1,   651,    -1,
      -1,   654,   655,    -1,   657,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   667,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   308,    -1,    -1,    -1,    -1,     3,     4,    -1,
      -1,    -1,    -1,    -1,   320,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    -1,    72,    73,    74,    75,
      76,    -1,    78,    -1,    -1,    81,    82,    83,    84,    85,
      86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,
     116,   117,   118,   119,   120,    -1,    -1,   123,    -1,    -1,
      -1,    -1,   128,    -1,    -1,     3,     4,    -1,   134,   135,
     136,   137,   138,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    -1,    -1,    72,    73,    74,    75,    76,    -1,
      78,    -1,    -1,    81,    82,    83,    84,    85,    86,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,   116,   117,
     118,   119,   120,    -1,    -1,   123,    -1,    -1,    -1,    -1,
     128,    -1,    -1,     3,     4,    -1,   134,   135,   136,   137,
     138,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    -1,    72,    73,    74,    75,    76,    -1,    78,    -1,
      -1,    81,    82,    83,    84,    85,    86,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   115,   116,   117,   118,   119,
     120,    -1,    -1,   123,    -1,    -1,    -1,    -1,   128,    -1,
      -1,     3,     4,    -1,   134,    -1,   136,   137,   138,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   115,   116,   117,   118,   119,   120,    -1,
      -1,   123,    -1,    -1,    -1,    -1,   128,     3,    -1,    -1,
      -1,    -1,    -1,    -1,   136,   137,   138,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,
     116,   117,   118,   119,   120,    -1,    -1,   123,    -1,    -1,
      -1,    -1,   128,     3,    -1,   131,   132,    -1,    -1,    -1,
     136,   137,   138,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   115,   116,   117,   118,   119,
     120,    -1,    -1,   123,    -1,    -1,    -1,    -1,   128,     3,
      -1,   131,   132,    -1,    -1,    -1,   136,   137,   138,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   115,   116,   117,   118,   119,   120,    -1,    -1,   123,
      -1,    -1,    -1,    -1,   128,   129,     3,    -1,    -1,    -1,
      -1,    -1,   136,   137,   138,    -1,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,   116,
     117,   118,   119,   120,    -1,    -1,   123,    -1,    -1,    -1,
      -1,   128,     3,     4,   131,    -1,    -1,    -1,    -1,   136,
     137,   138,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    87,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   115,   116,   117,   118,   119,   120,
      -1,    -1,   123,    -1,    -1,    -1,    -1,   128,     3,     4,
      -1,    -1,    -1,    -1,    -1,   136,   137,   138,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     115,   116,   117,   118,   119,   120,    -1,    -1,   123,    -1,
      -1,    -1,    -1,   128,     3,    -1,    -1,    -1,    -1,    -1,
      -1,   136,   137,   138,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   115,   116,   117,   118,
     119,   120,    -1,    -1,   123,    -1,    -1,    -1,    -1,   128,
     129,     3,    -1,    -1,    -1,    -1,    -1,   136,   137,   138,
      -1,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   115,   116,   117,   118,   119,   120,    -1,
      -1,   123,    -1,    -1,    -1,    -1,   128,   129,     3,     4,
      -1,    -1,    -1,    -1,   136,   137,   138,    -1,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     115,   116,   117,   118,   119,   120,    -1,    -1,   123,    -1,
      -1,    -1,    -1,   128,     3,    -1,    -1,    -1,    -1,    -1,
      -1,   136,   137,   138,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   115,   116,   117,   118,
     119,   120,    -1,    -1,   123,    -1,    -1,    -1,    -1,   128,
     129,     3,    -1,    -1,    -1,    -1,    -1,   136,   137,   138,
      -1,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   115,   116,   117,   118,   119,   120,    -1,
      -1,   123,    -1,    -1,    -1,    -1,   128,   129,     3,    -1,
      -1,    -1,    -1,    -1,   136,   137,   138,    -1,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     115,   116,   117,   118,   119,   120,    -1,    -1,   123,    -1,
      -1,    -1,    -1,   128,   129,     3,    -1,    -1,    -1,    -1,
      -1,   136,   137,   138,    -1,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,   116,   117,
     118,   119,   120,    -1,    -1,   123,    -1,    -1,    -1,    -1,
     128,   129,     3,    -1,    -1,    -1,    -1,    -1,   136,   137,
     138,    -1,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    87,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   115,   116,   117,   118,   119,   120,
      -1,    -1,   123,    -1,    -1,    -1,    -1,   128,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   136,   137,   138,     7,    -1,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   123,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     8,    -1,   136,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    -1,    -1,    -1,    71,    72,
      73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     123,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   136,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     136,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    -1,    -1,
      -1,    71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   136,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,   123,
     124,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,
      -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   123,   124,    -1,    -1,    -1,
      -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,   136,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,   123,    -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,
      -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,
     136,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,   123,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   134,    -1,   136,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   135,   136,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,   123,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,   136,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   135,   136,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,   123,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,
     136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   136,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    -1,   123,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   136
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,   140,   141,   138,     0,     7,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    71,    72,    73,    74,    75,
     123,   136,   142,   143,   145,   154,   156,   160,   161,   162,
     165,   166,   167,   170,   173,   231,   232,   233,   234,   235,
       4,   121,   122,   123,   146,   149,   151,   152,   153,   154,
       4,   126,   196,     8,   161,   162,   165,   173,   232,   232,
     235,   231,   231,   235,   235,   234,   143,   145,   156,    10,
     160,   123,   143,   196,   235,   130,   123,   123,     4,     5,
     154,   122,   154,   154,   123,   155,   123,   154,   197,   198,
     199,     4,   147,   151,   152,   153,   154,   128,   193,   163,
     164,   235,   235,   134,   196,   134,   196,   143,   235,   235,
     128,   193,     3,    67,    68,    69,    87,   115,   116,   117,
     118,   119,   120,   128,   131,   132,   137,   138,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   233,   149,   155,   123,   155,   155,   124,   154,
       5,   127,   128,   200,     7,   154,   154,   154,   129,   194,
     195,   231,     4,   196,     4,     5,    88,   200,     4,   135,
     168,   169,   231,   134,   135,   171,   172,   235,   134,   128,
     193,   124,     4,    11,    12,    88,   134,   174,   196,   134,
     157,   231,   132,   218,   218,   218,   218,   218,   218,   205,
     206,   207,   208,   235,   131,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   132,   133,   110,   111,   112,
     117,   118,   113,   114,   124,   119,   120,   121,   130,   200,
     119,   120,   121,   200,     3,   130,   199,   129,   201,   202,
     203,   204,   206,   235,   124,   148,   150,   235,     5,   129,
     235,     4,   164,   207,   196,     4,   135,   169,   235,   135,
     168,     4,     5,   135,    88,   196,   135,   171,   124,     4,
      11,    12,    88,   174,   196,   129,     4,    88,   174,   196,
       4,    88,   174,   196,   205,     4,    76,    78,    81,    82,
      83,    84,    85,    86,   135,   157,   162,   165,   174,   175,
     176,   177,   178,   179,   180,   181,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   205,   233,     4,    88,   174,
     144,   157,    70,   158,   159,   235,   231,   129,     5,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   133,   205,   209,   210,   211,   212,   213,   214,   214,
     215,   215,   215,   215,   216,   216,   216,   217,   217,   218,
     218,   218,   235,   205,   235,   131,   207,     5,   129,     5,
     129,   125,     4,     5,   195,    88,   196,   196,     4,     4,
      88,   196,     4,   135,   172,     4,   206,     4,   135,   129,
       4,    88,   174,   196,     4,    88,   174,   196,   205,     4,
      88,   174,    88,   196,   205,     4,    88,   174,   205,     4,
      88,   174,     4,   128,   128,   128,   177,   178,   128,     4,
       4,   205,   135,   176,     4,   130,   205,   135,   157,   218,
       4,     5,    88,   196,   200,   133,   205,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   206,   131,
     125,   131,   131,   203,   235,   201,   204,   206,   235,   206,
     205,     4,     4,   196,     4,    88,   196,   205,     4,    88,
     174,   205,     4,    88,   174,     4,   205,   205,    88,     4,
     205,     4,   205,   205,   205,   205,    81,    81,     4,   157,
     205,     4,   131,   207,     4,    70,   159,   206,   196,   128,
     206,   129,   196,     4,   196,   205,    88,     4,   205,     4,
     205,     4,     4,   205,     4,     4,   129,   129,   129,   128,
     128,     4,   205,     4,   205,     4,   131,   218,   196,   218,
       4,     4,   205,     4,     4,     4,   176,   177,   134,   177,
     178,   205,   205,   129,   205,     4,   129,   205,     4,     4,
     205,   129,     4,    77,    79,    80,   135,   182,   183,   129,
     129,   177,   178,   129,   129,   205,   177,   178,   129,   129,
     205,   129,   205,     4,   177,   178,   205,   125,   135,   183,
       4,     4,   177,   178,   177,   178,   129,   177,   178,   177,
     178,   129,   177,   178,   129,   129,   205,   125,   176,   177,
     178,   177,   178,   177,   178,   177,   178,   129,   176,   177,
     178
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   139,   140,   140,   140,   140,   140,   140,   140,   140,
     141,   142,   142,   143,   143,   144,   144,   145,   145,   146,
     146,   147,   147,   147,   147,   148,   148,   149,   149,   149,
     149,   149,   149,   149,   149,   150,   150,   151,   152,   152,
     153,   154,   154,   155,   156,   156,   157,   158,   158,   159,
     159,   159,   159,   159,   159,   160,   160,   160,   160,   160,
     160,   160,   160,   161,   161,   162,   163,   163,   164,   164,
     164,   164,   165,   165,   165,   166,   167,   167,   167,   167,
     168,   168,   169,   169,   169,   169,   170,   170,   170,   170,
     171,   171,   172,   172,   172,   172,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   174,   174,   175,   175,
     176,   176,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   178,   178,   178,   178,
     179,   180,   180,   181,   181,   182,   182,   183,   183,   183,
     183,   184,   185,   186,   187,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   190,
     191,   192,   193,   193,   194,   194,   195,   195,   195,   195,
     196,   197,   197,   198,   198,   199,   200,   200,   200,   200,
     201,   201,   202,   202,   203,   204,   205,   205,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   207,   207,   208,   208,   209,   209,   210,   210,   211,
     211,   212,   212,   213,   213,   213,   214,   214,   214,   214,
     214,   215,   215,   215,   215,   216,   216,   216,   217,   217,
     217,   217,   218,   218,   218,   218,   218,   218,   218,   218,
     219,   219,   220,   220,   220,   220,   220,   220,   220,   221,
     221,   221,   221,   222,   222,   222,   222,   222,   223,   224,
     225,   225,   226,   226,   226,   226,   227,   227,   228,   229,
     230,   230,   231,   231,   231,   232,   232,   232,   232,   233,
     233,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   235
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     3,     3,     3,     2,     2,     2,     1,
       3,     2,     1,     2,     1,     2,     1,     3,     6,     3,
       1,     2,     2,     2,     1,     1,     1,     3,     3,     3,
       2,     2,     2,     2,     1,     3,     1,     2,     3,     2,
       1,     3,     1,     2,     3,     2,     3,     3,     1,     3,
       2,     4,     3,     2,     1,     2,     2,     2,     2,     1,
       1,     1,     1,     5,     4,     4,     3,     1,     3,     2,
       4,     3,     1,     1,     1,     4,     7,     6,     6,     5,
       2,     1,     6,     5,     4,     3,     7,     6,     6,     5,
       3,     1,     4,     3,     2,     1,     7,     7,     6,     6,
       6,     5,     6,     6,     5,     5,     5,     4,     7,     7,
       6,     6,     6,     5,     6,     6,     5,     5,     5,     4,
       9,     9,     8,     8,     8,     7,     8,     8,     7,     7,
       7,     6,    10,     9,     9,     8,     3,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       7,     5,     7,     7,     6,     2,     1,     4,     3,     3,
       2,     5,     5,     7,     7,     8,     7,     7,     6,     9,
       8,     8,     7,     8,     7,     7,     6,     8,     7,     7,
       6,     9,     8,     8,     7,     8,     7,     7,     6,     2,
       2,     3,     3,     2,     3,     1,     5,     4,     3,     2,
       3,     3,     1,     2,     1,     2,     5,     3,     3,     2,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     5,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     1,     2,     2,     2,     2,     2,     2,     1,     1,
       1,     1,     2,     2,     3,     2,     4,     1,     1,     4,
       3,     1,     3,     2,     2,     3,     2,     1,     1,     7,
       4,     6,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     2,     2,     1,     6,     4,     3,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
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
      yyerror (&yylloc, pUserData, pScanner, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location, pUserData, pScanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, void *pUserData, void *pScanner)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  YYUSE (pUserData);
  YYUSE (pScanner);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, void *pUserData, void *pScanner)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, pUserData, pScanner);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, void *pUserData, void *pScanner)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       , pUserData, pScanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, pUserData, pScanner); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, void *pUserData, void *pScanner)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (pUserData);
  YYUSE (pScanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void *pUserData, void *pScanner)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yychar = yylex (&yylval, &yylloc, pUserData, pScanner);
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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 166 "../../Private/MatC/MDL/MDLParser.y" /* yacc.c:1646  */
    { (yyval._null) = NULL; }
#line 2923 "../../Private/MatC/MDL/MDLParser.inl" /* yacc.c:1646  */
    break;

  case 3:
#line 167 "../../Private/MatC/MDL/MDLParser.y" /* yacc.c:1646  */
    { (yyval._null) = NULL; }
#line 2929 "../../Private/MatC/MDL/MDLParser.inl" /* yacc.c:1646  */
    break;

  case 4:
#line 168 "../../Private/MatC/MDL/MDLParser.y" /* yacc.c:1646  */
    { (yyval._null) = NULL; }
#line 2935 "../../Private/MatC/MDL/MDLParser.inl" /* yacc.c:1646  */
    break;

  case 5:
#line 169 "../../Private/MatC/MDL/MDLParser.y" /* yacc.c:1646  */
    { (yyval._null) = NULL; }
#line 2941 "../../Private/MatC/MDL/MDLParser.inl" /* yacc.c:1646  */
    break;

  case 6:
#line 170 "../../Private/MatC/MDL/MDLParser.y" /* yacc.c:1646  */
    { (yyval._null) = NULL; }
#line 2947 "../../Private/MatC/MDL/MDLParser.inl" /* yacc.c:1646  */
    break;

  case 7:
#line 171 "../../Private/MatC/MDL/MDLParser.y" /* yacc.c:1646  */
    { (yyval._null) = NULL; }
#line 2953 "../../Private/MatC/MDL/MDLParser.inl" /* yacc.c:1646  */
    break;

  case 8:
#line 172 "../../Private/MatC/MDL/MDLParser.y" /* yacc.c:1646  */
    { (yyval._null) = NULL; }
#line 2959 "../../Private/MatC/MDL/MDLParser.inl" /* yacc.c:1646  */
    break;

  case 9:
#line 173 "../../Private/MatC/MDL/MDLParser.y" /* yacc.c:1646  */
    { (yyval._null) = NULL; }
#line 2965 "../../Private/MatC/MDL/MDLParser.inl" /* yacc.c:1646  */
    break;

  case 17:
#line 186 "../../Private/MatC/MDL/MDLParser.y" /* yacc.c:1646  */
    { (yyval._decl) = NULL; }
#line 2971 "../../Private/MatC/MDL/MDLParser.inl" /* yacc.c:1646  */
    break;

  case 18:
#line 187 "../../Private/MatC/MDL/MDLParser.y" /* yacc.c:1646  */
    { (yyval._decl) = NULL; }
#line 2977 "../../Private/MatC/MDL/MDLParser.inl" /* yacc.c:1646  */
    break;


#line 2981 "../../Private/MatC/MDL/MDLParser.inl" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

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
      yyerror (&yylloc, pUserData, pScanner, YY_("syntax error"));
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
        yyerror (&yylloc, pUserData, pScanner, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc, pUserData, pScanner);
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

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp, pUserData, pScanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
  yyerror (&yylloc, pUserData, pScanner, YY_("memory exhausted"));
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
                  yytoken, &yylval, &yylloc, pUserData, pScanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp, pUserData, pScanner);
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
