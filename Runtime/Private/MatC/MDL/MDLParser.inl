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
    FRACT_LITERAL = 393,
    FLOATING_LITERAL = 394,
    DOUBLE_LITERAL = 395
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
#define FRACT_LITERAL 393
#define FLOATING_LITERAL 394
#define DOUBLE_LITERAL 395

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

#line 414 "../../Private/MatC/MDL/MDLParser.inl" /* yacc.c:358  */
/* Unqualified %code blocks.  */
#line 13 "../../Private/MatC/MDL/MDLParser.y" /* yacc.c:359  */

    int yylex(union YYSTYPE *lvalp, YYLTYPE *llocp, void *pUserData, void *pScanner);
    void yyerror(YYLTYPE *llocp, void *pUserData, void *pScanner, const char *s);

#line 421 "../../Private/MatC/MDL/MDLParser.inl" /* yacc.c:359  */

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
#define YYLAST   5271

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  141
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  101
/* YYNRULES -- Number of rules.  */
#define YYNRULES  397
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  711

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   395

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
     135,   136,   137,   138,   139,   140
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   168,   168,   169,   170,   171,   172,   173,   174,   175,
     177,   179,   180,   182,   183,   185,   186,   188,   189,   191,
     192,   194,   195,   196,   197,   199,   200,   202,   203,   204,
     205,   206,   207,   208,   209,   211,   212,   214,   216,   217,
     219,   221,   222,   224,   226,   227,   229,   231,   232,   234,
     235,   236,   237,   238,   239,   241,   242,   243,   244,   245,
     246,   247,   248,   250,   251,   253,   255,   256,   258,   259,
     260,   261,   263,   264,   265,   267,   269,   270,   271,   272,
     274,   275,   277,   278,   279,   280,   282,   283,   284,   285,
     287,   288,   290,   291,   292,   293,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   334,   335,   336,   337,   339,   340,   342,   343,
     345,   346,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   363,   364,   365,   366,
     368,   369,   370,   372,   373,   375,   376,   378,   379,   380,
     381,   383,   384,   386,   388,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   416,
     418,   420,   422,   423,   425,   426,   428,   429,   430,   431,
     433,   435,   436,   438,   439,   441,   442,   444,   445,   446,
     447,   449,   450,   452,   453,   455,   457,   459,   460,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   476,   477,   479,   480,   482,   483,   485,   486,
     488,   489,   491,   492,   494,   495,   496,   498,   499,   500,
     501,   502,   504,   505,   506,   507,   509,   510,   511,   513,
     514,   515,   516,   518,   519,   520,   521,   522,   523,   524,
     525,   527,   528,   530,   531,   533,   534,   535,   536,   537,
     538,   540,   541,   542,   543,   545,   547,   548,   550,   551,
     552,   553,   555,   556,   558,   559,   560,   562,   563,   564,
     566,   567,   569,   571,   572,   573,   575,   576,   578,   579,
     580,   581,   582,   583,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   597,   598,   600,   601,   602,
     603,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   628,   629,   630,   631,   632,   633,
     634,   635,   636,   637,   638,   639,   640,   641,   642,   643,
     644,   645,   646,   647,   648,   649,   650,   651,   652,   653,
     654,   655,   656,   657,   658,   660,   661,   663
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
  "INTEGER_LITERAL", "FRACT_LITERAL", "FLOATING_LITERAL", "DOUBLE_LITERAL",
  "$accept", "mdl", "mdl_version", "import_declarations",
  "global_declarations", "variable_declarations", "import_declaration",
  "qualified_imports", "qualified_import_prefix", "unqualified_import",
  "qualified_import", "unqualified_import_simple_names",
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
  "parameter", "annotation_block", "annotations", "annotation",
  "annotation_qualified_name", "argument_list", "named_arguments",
  "positional_arguments", "named_argument", "positional_argument",
  "comma_expression", "assignment_expression", "conditional_expression",
  "logical_or_expression", "logical_and_expression",
  "inclusive_or_expression", "exclusive_or_expression", "and_expression",
  "equality_expression", "relational_expression", "shift_expression",
  "additive_expression", "multiplicative_expression", "unary_expression",
  "postfix_expression", "let_expression", "rvalue_postfix_expression",
  "rvalue_primary_expression", "cast_expression", "constructor_expression",
  "literal_expression", "lvalue_expression",
  "lvalue_expression_with_index_operation",
  "lvalue_expression_without_index_operation", "boolean_literal",
  "integer_literal", "floating_literal", "string_literal", "type",
  "array_type", "array_type_or_lvalue", "simple_type", "builtin_type",
  "type_or_variable_qualified_name", "simple_name", YY_NULLPTR
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
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395
};
# endif

#define YYPACT_NINF -410

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-410)))

#define YYTABLE_NINF -398

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      30,  -122,    62,  3668,    67,  -410,   137,    16,  3794,  5081,
    5081,  -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,
    -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,
    -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,
    -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,
    -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,
    -410,  -410,  -410,  -410,  -410,   -25,  4957,  4957,   -25,   -25,
    5135,  -410,  3668,  3921,  -410,  3921,  -410,  -410,  -410,  -410,
    -410,  -410,  -410,  -410,   108,  -410,  -410,  -410,    -1,   133,
    -410,    36,    47,  -410,  -410,   246,  -410,   -25,   -95,   -25,
      82,  -410,  -410,   -20,   203,   137,  -410,  -410,  -410,  -410,
    -410,  -410,  -410,  -410,   126,   -25,   -25,   -49,    76,   132,
     152,  3921,  -410,  3921,  4047,  -410,  3921,   -25,   148,  1606,
     147,  1736,  -410,  -410,  -410,   137,    82,   156,    82,    82,
     -84,  -410,   151,  -410,    49,  -410,   103,  -410,   289,   -25,
     -95,   -25,   175,  4355,    51,   308,  -410,   -31,   311,  4411,
     191,   186,   193,  1866,  1996,  3921,   226,  4173,    27,  -410,
    -410,  -410,  4537,   215,  3406,  3406,  3406,  3406,  3406,  3406,
    5135,  3406,  -410,   -25,  -410,  -410,  -410,  -410,   231,   233,
     264,   265,   273,   275,   276,   138,   219,   270,   243,  -410,
    -410,  -410,   230,  -410,  -410,  -410,  -410,  -410,  -410,   277,
    -410,  -410,  -410,   393,   266,   165,   266,   180,  -410,  -410,
     -25,   274,   399,  -410,   511,  -410,  -410,  -410,  -410,  -410,
    -410,  -410,   103,   -20,  -410,   278,  2126,  -410,   -42,   175,
     175,   175,   -25,  -410,     3,  -410,   -25,  -410,   402,  -410,
     -25,  3406,   283,  -410,   406,  4593,  -410,   -25,  4719,   407,
      -2,  -410,    40,   255,  -410,   -25,   282,  -410,   -25,   284,
    4229,    64,   287,  -410,    86,   104,  3406,  1202,  -410,    11,
    4957,   348,   -25,  4957,  -410,  -410,  -410,  -410,  -410,  -410,
     225,   291,   288,  -410,  3406,  3406,  3406,  3406,  3406,  3406,
    3406,  3406,  3406,  3406,  3406,  3406,  3406,  3406,  3406,  3406,
    3406,  3406,  3406,  3406,  -410,  -410,   -25,  3406,  -410,   -25,
    -410,  -410,   -25,  3406,  -410,   292,  -410,  3406,  3406,  3406,
    3406,  3406,  3406,  3406,  3406,  3406,  3406,  3406,  3406,  3406,
    -410,  -410,  -410,  -410,   297,     5,    19,  -410,  -410,  -410,
     299,  -410,   422,   423,  -410,  4957,  -410,    77,  -410,  -410,
     283,  -410,  -410,   429,  -410,    10,   432,  4775,  -410,   -25,
     433,  3406,  -410,   434,     4,   306,  -410,   307,  -410,   313,
    -410,   123,   127,  3406,  -410,    17,    98,  -410,  3406,  -410,
      61,  -410,  3406,  -410,    75,   439,  -410,   317,   319,   320,
    1478,   321,   446,   447,  3406,  -410,  -410,  -410,  -410,  -410,
    1340,  -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,
    -410,  -410,  -410,  -410,  -410,  -410,   448,   266,   266,  -410,
    3406,  -410,  4901,  -410,  3406,   388,  -410,   -75,   322,  -410,
     323,   328,   264,   265,   273,   275,   276,   138,   138,   219,
     219,   219,   219,   270,   270,   270,   243,   243,  -410,  -410,
    -410,  -410,   326,  -410,  -410,   327,   330,  -410,  -410,  -410,
    -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,
     -25,  -410,  3534,  -410,  3406,  -410,   -25,  -410,  3406,  -410,
    -410,  -410,  -410,  3406,   458,  -410,   459,  -410,  -410,   283,
    -410,   460,   334,   337,   139,  -410,  3406,  -410,    80,  -410,
    3406,  -410,    87,   465,  -410,  3406,  -410,  3406,   384,   469,
    -410,  3406,  -410,   472,  -410,  3406,  -410,  -410,  3406,  3406,
    3406,   396,   398,   950,  -410,  -410,   476,  -410,  -410,  -410,
     477,   412,  -410,  -410,  -410,   -25,  3406,  -410,   283,   356,
    -410,  3406,  -410,  -410,  -410,  -410,    25,  -410,  -410,  -410,
     283,    54,  -410,  -410,  -410,  -410,  -410,  -410,  3406,   397,
     482,  -410,  3406,  -410,   483,  -410,  3406,  -410,  -410,   484,
     488,  3406,  -410,   492,  -410,   493,   369,   370,   371,   373,
     376,  2254,  2382,   501,  -410,  -410,  3406,  -410,   283,  -410,
    3406,  -410,  -410,  -410,  -410,   507,   508,  3406,  -410,   509,
    -410,   510,  -410,  -410,   512,  -410,  -410,  1478,   381,  1478,
    3406,  3406,  2510,   513,  2638,   515,  2766,  -410,  -410,   392,
    -410,  -410,   516,  -410,  -410,  -410,  -410,   450,   -68,  -410,
    -410,   400,   403,  1478,   404,  2894,  1478,   409,  3022,  3150,
     521,  -410,  -410,  1478,  3406,   410,  -410,   143,  -410,   532,
     535,  -410,  -410,  1478,  1478,   413,  -410,  -410,  1478,  1478,
     414,  1478,   416,  3278,  -410,  -410,   421,  1478,  -410,  -410,
    -410,  -410,  -410,  -410,  -410,  -410,  1478,  -410,  -410,  -410,
    -410,  1478,  -410,  -410,  1478,  1478,   419,  1478,  -410,  -410,
    -410,  -410,  -410,  -410,  -410,  -410,  -410,  1478,  -410,  -410,
    -410
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     9,     0,     1,     0,     0,     0,     0,
       0,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,     0,     0,     0,     0,     0,
       0,   396,     6,     8,    12,     7,    14,    59,    60,    61,
      72,    73,    74,    62,     0,   320,   334,   323,   339,   340,
      10,     0,     0,    40,   397,     0,    20,     0,     0,     0,
      34,    42,    45,     0,     0,     0,    55,    56,    57,    58,
     319,   322,   318,   321,     0,     0,     0,     0,     0,   337,
     338,     3,    11,     5,     0,    13,     4,     0,     0,     0,
       0,     0,    37,    39,    17,     0,    31,     0,    32,    33,
       0,    30,     0,   216,     0,   212,     0,    44,     0,     0,
       0,     0,    24,     0,     0,     0,    67,     0,     0,     0,
       0,     0,     0,     0,     0,     2,     0,     0,     0,   317,
     310,   311,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   331,     0,   312,   313,   314,   315,     0,   243,
     245,   247,   249,   251,   253,   256,   261,   265,   268,   272,
     279,   280,   281,   290,   291,   292,   293,   282,   302,   303,
     298,   299,   300,   301,     0,   306,     0,   309,   395,   333,
       0,     0,   228,   241,   282,    19,    27,    38,    28,    29,
      43,    41,     0,     0,   210,     0,     0,   214,     0,    21,
      22,    23,     0,   203,     0,   205,     0,    64,     0,    65,
       0,     0,    69,    75,     0,     0,    81,     0,     0,     0,
       0,    91,    95,     0,   326,     0,     0,   328,     0,     0,
       0,     0,     0,   107,     0,     0,     0,     0,   119,     0,
       0,     0,     0,     0,   273,   274,   275,   276,   277,   278,
     308,     0,     0,   330,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   285,   286,     0,     0,   288,     0,
     316,   296,     0,     0,   297,     0,   336,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     213,   211,   215,   220,   396,     0,     0,   222,   224,   226,
       0,    26,     0,    25,    36,     0,   202,   209,    63,    66,
      71,    68,    79,     0,    80,     0,     0,     0,    89,     0,
       0,     0,    94,     0,     0,     0,   325,     0,   335,     0,
     101,     0,     0,     0,   113,     0,     0,   105,     0,   117,
       0,   106,     0,   118,     0,     0,   155,     0,     0,     0,
       0,     0,     0,     0,     0,   137,   153,   144,   143,   142,
       0,   139,   140,   141,   145,   156,   146,   147,   157,   148,
     158,   149,   159,   150,   151,   152,     0,   320,   323,   104,
       0,   116,     0,    16,     0,     0,    48,    54,     0,   294,
       0,     0,   244,   246,   248,   250,   252,   254,   255,   258,
     259,   257,   260,   262,   263,   264,   266,   267,   270,   271,
     269,   287,     0,   307,   304,     0,     0,   227,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
       0,   218,     0,   219,     0,    18,     0,   204,     0,   208,
      70,    77,    85,     0,     0,    78,     0,    90,    87,    93,
      88,     0,     0,     0,     0,    99,     0,   111,     0,   100,
       0,   112,     0,     0,    98,     0,   110,     0,     0,     0,
     102,     0,   114,     0,   103,     0,   115,   131,     0,     0,
       0,     0,     0,     0,   199,   200,     0,   136,   138,   154,
       0,     0,    15,   283,    46,     0,     0,    53,    50,     0,
     329,     0,   289,   305,   332,   221,     0,   223,   225,    35,
     207,     0,    84,    76,    92,    86,   324,   327,     0,     0,
       0,    96,     0,   108,     0,    97,     0,   109,   125,     0,
       0,     0,   129,     0,   130,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   201,   128,     0,    47,    52,    49,
       0,   242,   217,   206,    83,     0,     0,     0,   123,     0,
     124,     0,   122,   135,     0,   126,   127,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   284,    51,     0,
      82,   133,     0,   120,   121,   134,   161,   140,     0,   171,
     172,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   295,   132,     0,     0,     0,   164,     0,   166,     0,
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
    -410,  -410,  -410,  -410,   125,  -410,   485,  -410,  -410,  -410,
     426,  -410,   436,   444,   461,   221,  -104,   496,  -168,  -410,
      24,   -48,    48,    20,  -410,   314,   116,  -410,  -410,   312,
    -253,  -410,   302,   202,    94,  -149,  -410,  -409,  -109,   163,
    -410,  -410,  -410,  -410,   -85,  -410,  -410,  -410,  -410,  -410,
    -410,  -410,  -410,  -410,   100,  -410,   218,   -58,  -410,   343,
     437,  -128,    96,  -410,   101,   102,   -98,     7,   -16,  -410,
     285,   293,   286,   290,   294,    99,    71,    78,    93,  -129,
    -410,  -410,  -410,  -410,  -410,  -410,  -410,   587,  -410,  -410,
    -410,  -410,  -410,  -410,    14,    -3,   780,    34,    -9,   676,
     391
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    72,    73,   432,    74,    95,   148,   352,
      96,   353,    97,    98,    99,   100,   141,    75,   406,   435,
     436,    76,    77,   407,   155,   156,   408,    80,    81,   255,
     256,    82,   260,   261,    83,   409,   410,   411,   412,   413,
     414,   415,   416,   657,   658,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   154,   244,   245,   104,   144,   145,
     146,   321,   345,   346,   347,   348,   426,   222,   223,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   224,   208,   209,
     210,   211,   212,   213,   282,   214,   215,   216,    88,   217,
     101
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      85,   538,   364,   369,   281,    85,   110,   112,   355,   369,
     480,   654,   655,   546,   492,   429,     4,    84,   237,   278,
     102,   514,    84,    78,   482,   125,   127,   137,   107,   252,
     480,   273,   226,   221,   228,   229,     1,    87,   274,   275,
     230,    94,    87,   111,   113,   284,   285,   286,   287,   288,
     289,   103,    94,   236,   233,   247,   106,   251,   604,   160,
     162,   119,     5,    85,    85,   520,   269,   656,   380,    85,
      85,    90,    85,   125,   318,   381,   382,   103,   125,   524,
     115,   116,   351,   291,   571,   159,    84,    84,   324,    84,
     387,   575,    78,    78,    94,    78,   248,   236,   493,   430,
      87,    87,   109,   142,   340,   515,    87,    87,   391,    87,
     279,    94,   433,   188,   364,   276,   143,   125,    85,    79,
      85,    85,   384,    85,   108,   389,   393,   505,   371,   129,
     431,   509,   356,   370,   481,    84,   103,    84,    84,   501,
      84,    78,   103,    78,   107,   277,    78,   266,   483,   521,
      85,   277,   383,   103,   602,    87,    85,    87,    87,   132,
      87,   277,    85,   525,    85,   488,   103,   246,   572,    85,
     133,   119,   106,   257,   388,   576,   234,   103,   395,    84,
     103,   246,   458,   459,   460,    78,   517,    87,    79,    79,
     103,    79,   392,    87,   361,   277,   441,   121,   277,    87,
     126,    87,   103,   103,   372,   140,    87,   147,   636,   277,
     161,   506,   103,   385,   277,   510,   390,   394,   109,   462,
     277,   277,   654,   655,   103,   465,   235,   568,   168,   467,
     103,   236,   507,   511,   103,   360,   516,    79,   277,    79,
     108,   522,    79,   349,    94,   526,   302,   303,   165,   103,
     134,   135,    85,   103,   153,    85,   130,   277,    91,    92,
      93,   277,   163,   131,   542,   103,   271,    85,   698,   257,
     304,   305,   257,    94,   427,   130,   167,    85,   678,   227,
      85,    79,   164,   218,   246,   513,   322,   143,   708,    87,
     519,   531,    87,  -334,   523,   323,   238,   438,   242,   489,
     324,  -334,   490,   130,    87,   543,   536,   494,  -340,   548,
     131,   428,   249,   250,    87,   253,  -340,    87,   136,   138,
     139,   259,    94,   508,   512,   258,   152,   263,   518,   306,
     307,   308,   540,   294,   295,   468,   469,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   283,   130,   314,
     315,   316,    85,  -338,   270,   164,   311,   312,   236,   573,
     317,  -338,   293,   577,    85,   592,   296,   313,   297,   246,
     239,   240,   241,   449,   450,   451,   452,   298,   499,   547,
     299,   257,   300,   301,   453,   454,   455,   309,   310,    87,
     373,    94,   544,   545,   236,   561,   320,   427,   319,   447,
     448,    87,   456,   457,   327,   326,   358,   427,   570,   103,
     362,   368,   574,   376,   342,   378,   386,   579,   434,   580,
     439,   440,  -397,   583,   484,   466,   485,   585,   486,    85,
     586,   587,   588,   491,   428,   593,   495,   498,   500,   502,
     503,   564,   504,   527,   428,   528,   569,   529,   530,   533,
     534,   535,   539,   551,   550,   549,   114,   552,   553,   117,
     118,   554,   562,   563,   565,   566,    87,   627,   567,   578,
     606,   629,   581,   582,   609,   128,   584,   589,   611,   590,
     594,   595,   596,   614,   600,   607,   608,   610,   612,   349,
     599,   558,   613,   623,   625,   560,   615,   616,   617,   618,
     619,   620,   603,   605,   621,   626,   157,   158,   637,   632,
     639,   630,   631,   633,   634,   638,   635,   645,   166,   648,
     652,   651,   641,   642,   644,   673,   647,   653,   650,   659,
     427,   231,   660,   663,   661,   677,   680,   666,   668,   681,
     628,   149,   686,   691,   674,   694,   697,   665,   707,   150,
     670,   672,   262,   598,   682,   684,   676,   122,   601,   687,
     689,   225,   692,   532,   359,   374,   151,   428,   123,   597,
     367,   497,   679,   487,   292,   696,   341,   699,   556,   232,
     442,   555,   701,   444,   557,   703,   705,     0,   445,   443,
       0,     0,     0,   446,     0,     0,     0,     0,   709,   328,
     329,   330,   331,   332,   333,   334,   335,   336,   337,   338,
     339,   325,     0,     0,   427,     0,   427,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   350,     0,   354,
       0,     0,     0,   231,     0,     0,     0,   357,     0,     0,
     427,   157,     0,   427,     0,     0,     0,     0,   365,     0,
     427,   428,     0,   428,   262,     0,   375,     0,     0,   377,
     427,   427,     0,     0,     0,   427,   427,     0,   427,     0,
       0,     0,     0,   437,   427,     0,     0,   428,     0,    89,
     428,     0,     0,   427,    89,    89,    89,   428,   427,     0,
       0,   427,   427,     0,   427,     0,     0,   428,   428,     0,
       0,     0,   428,   428,   427,   428,     0,   461,     0,     0,
     463,   428,     0,   464,     0,     0,   207,     0,     0,     0,
     428,     0,     0,     0,     0,   428,     0,     0,   428,   428,
       0,   428,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   428,    89,    89,     0,     0,   120,     0,    89,    89,
     207,    89,     0,     0,     0,     0,     0,     0,     0,     0,
     262,   207,   207,   207,   207,   207,   207,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   640,    86,     0,     0,     0,     0,    86,    86,
      86,     0,     0,     0,     0,     0,     0,    89,     0,    89,
      89,     0,    89,     0,     0,     0,   662,     0,     0,   667,
       0,     0,     0,     0,     0,     0,   675,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   683,   685,     0,    89,
       0,   688,   690,     0,   693,    89,     0,     0,   207,     0,
       0,    89,     0,    89,     0,     0,    86,    86,    89,   700,
       0,     0,    86,    86,   702,    86,   290,   704,   706,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     710,   350,     0,   350,     0,     0,     0,   559,     0,     0,
       0,     0,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,    86,     0,    86,    86,     0,    86,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    89,     0,    86,    89,     0,   437,     0,     0,    86,
       0,     0,     0,     0,     0,    86,    89,    86,     0,     0,
       0,     0,    86,   169,   591,     0,    89,     0,     0,    89,
       0,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,   170,   171,   172,
       0,   207,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    89,     0,     0,     0,    86,     0,   173,    86,     0,
       0,     0,     0,    89,     0,     0,     0,     0,     0,     0,
      86,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      86,     0,     0,    86,     0,   174,   175,   176,   177,   178,
     179,     0,     0,   180,     0,     0,     0,     0,   181,     0,
       0,     0,     0,     0,     0,     0,    71,   184,   185,   186,
     187,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    86,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   207,     0,     0,     0,   207,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   169,   396,     0,     0,     0,
       0,     0,    86,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,   170,
     171,   172,     0,     0,    66,    67,    68,    69,   397,     0,
     398,     0,     0,   399,   400,   401,   402,   403,   404,   173,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   174,   175,   176,
     177,   178,   179,     0,     0,   180,     0,     0,     0,     0,
     181,     0,     0,     0,     0,     0,   277,   405,    71,   184,
     185,   186,   187,   169,   396,     0,     0,     0,     0,     0,
       0,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,   170,   171,   172,
       0,     0,    66,    67,    68,    69,   397,     0,   398,     0,
       0,   399,   400,   401,   402,   403,   404,   173,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   174,   175,   176,   177,   178,
     179,     0,     0,   180,     0,     0,     0,     0,   181,     0,
       0,     0,     0,     0,   277,   537,    71,   184,   185,   186,
     187,   169,   396,     0,     0,     0,     0,     0,     0,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,   170,   171,   172,     0,     0,
      66,    67,    68,    69,   397,     0,   398,     0,     0,   399,
     400,   401,   402,   403,   404,   173,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   174,   175,   176,   177,   178,   179,     0,
       0,   180,     0,     0,     0,     0,   181,     0,     0,   169,
       0,     0,   277,     0,    71,   184,   185,   186,   187,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,   170,   171,   172,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   173,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   174,   175,   176,   177,   178,   179,     0,     0,   180,
       0,     0,     0,     0,   181,     0,     0,   182,   183,   169,
       0,     0,    71,   184,   185,   186,   187,     0,     0,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,   170,   171,   172,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   173,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   174,   175,   176,   177,   178,   179,     0,     0,   180,
       0,     0,     0,     0,   181,     0,     0,   219,   220,   169,
       0,     0,    71,   184,   185,   186,   187,     0,     0,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,   170,   171,   172,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   173,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   174,   175,   176,   177,   178,   179,     0,     0,   180,
       0,     0,     0,     0,   181,     0,     0,   264,   265,   169,
       0,     0,    71,   184,   185,   186,   187,     0,     0,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,   170,   171,   172,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   173,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   174,   175,   176,   177,   178,   179,     0,     0,   180,
       0,     0,     0,     0,   181,     0,     0,   267,   268,   169,
       0,     0,    71,   184,   185,   186,   187,     0,     0,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,   170,   171,   172,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   173,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   174,   175,   176,   177,   178,   179,     0,     0,   180,
       0,     0,     0,     0,   181,   343,     0,   169,   622,     0,
       0,     0,   344,   184,   185,   186,   187,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,   170,   171,   172,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   173,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   174,
     175,   176,   177,   178,   179,     0,     0,   180,     0,     0,
       0,     0,   181,     0,     0,   169,   624,     0,     0,     0,
      71,   184,   185,   186,   187,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,   170,
     171,   172,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   173,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   174,   175,   176,
     177,   178,   179,     0,     0,   180,     0,     0,     0,     0,
     181,     0,     0,   169,     0,     0,     0,     0,    71,   184,
     185,   186,   187,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,   170,   171,   172,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   173,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   174,   175,   176,   177,   178,
     179,     0,     0,   180,     0,     0,     0,     0,   181,   643,
       0,   169,     0,     0,     0,     0,    71,   184,   185,   186,
     187,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,   170,   171,   172,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   173,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   174,   175,   176,   177,   178,   179,     0,
       0,   180,     0,     0,     0,     0,   181,   646,     0,   169,
     649,     0,     0,     0,    71,   184,   185,   186,   187,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,   170,   171,   172,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   173,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   174,   175,   176,   177,   178,   179,     0,     0,   180,
       0,     0,     0,     0,   181,     0,     0,   169,     0,     0,
       0,     0,    71,   184,   185,   186,   187,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,   170,   171,   172,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   173,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   174,
     175,   176,   177,   178,   179,     0,     0,   180,     0,     0,
       0,     0,   181,   664,     0,   169,     0,     0,     0,     0,
      71,   184,   185,   186,   187,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,   170,
     171,   172,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   173,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   174,   175,   176,
     177,   178,   179,     0,     0,   180,     0,     0,     0,     0,
     181,   669,     0,   169,     0,     0,     0,     0,    71,   184,
     185,   186,   187,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,   170,   171,   172,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   173,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   174,   175,   176,   177,   178,
     179,     0,     0,   180,     0,     0,     0,     0,   181,   671,
       0,   169,     0,     0,     0,     0,    71,   184,   185,   186,
     187,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,   170,   171,   172,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   173,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   174,   175,   176,   177,   178,   179,     0,
       0,   180,     0,     0,     0,     0,   181,   695,     0,   169,
       0,     0,     0,     0,    71,   184,   185,   186,   187,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,   170,   171,   172,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   173,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   174,   175,   176,   177,   178,   179,     0,     0,   180,
       0,     0,     0,     0,   181,     0,     0,   169,     0,     0,
       0,     0,    71,   184,   185,   186,   187,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,   170,   171,   172,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   173,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   174,
     175,   176,   177,   178,   179,     0,     0,   180,     0,     0,
       0,     0,   181,     0,     0,     0,     0,     0,     0,     0,
     344,   184,   185,   186,   187,     6,     0,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,     0,     0,     0,     0,    65,
      66,    67,    68,    69,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    70,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   105,     0,    71,     9,    10,    11,    12,    13,
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
      71,   124,     9,    10,    11,    12,    13,    14,    15,    16,
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
       0,     0,     0,     0,     0,     0,     0,    71,     9,    10,
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
       0,     0,     0,    71,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    70,   272,     0,     0,
       0,     0,   243,     0,     0,     0,     0,     0,     0,    71,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    70,   379,     0,     0,     0,     0,   243,     0,
       0,     0,     0,     0,     0,    71,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    70,     0,
       0,     0,     0,     0,   243,     0,     0,     0,     0,     0,
       0,    71,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    70,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   254,    71,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      70,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   280,     0,    71,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    70,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   363,    71,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    70,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   366,    71,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    70,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     496,    71,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    70,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   541,    71,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      70,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    71,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,     0,     0,    70,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    71,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    71
};

static const yytype_int16 yycheck[] =
{
       3,   410,   255,     5,   172,     8,     9,    10,     5,     5,
       5,    79,    80,    88,     4,     4,   138,     3,   146,   168,
       4,     4,     8,     3,     5,    73,    84,   122,     8,   157,
       5,     4,   136,   131,   138,   139,     6,     3,    11,    12,
     124,   136,     8,     9,    10,   174,   175,   176,   177,   178,
     179,   126,   136,   128,     5,     4,     8,    88,     4,   117,
     118,    70,     0,    66,    67,     4,   164,   135,     4,    72,
      73,     4,    75,   121,   202,    11,    12,   126,   126,     4,
      66,    67,   124,   181,     4,   134,    72,    73,   216,    75,
       4,     4,    72,    73,   136,    75,   154,   128,    88,    88,
      66,    67,     8,   123,   232,    88,    72,    73,     4,    75,
     168,   136,   280,   129,   367,    88,   136,   165,   121,     3,
     123,   124,   271,   126,     8,   274,   275,     4,    88,   130,
     279,     4,   129,   135,   129,   121,   126,   123,   124,   135,
     126,   121,   126,   123,   124,   134,   126,   163,   129,    88,
     153,   134,    88,   126,   129,   121,   159,   123,   124,   123,
     126,   134,   165,    88,   167,    88,   126,   153,    88,   172,
     123,   180,   124,   159,    88,    88,   127,   126,   276,   165,
     126,   167,   311,   312,   313,   165,    88,   153,    72,    73,
     126,    75,    88,   159,   252,   134,   294,    72,   134,   165,
      75,   167,   126,   126,   262,   123,   172,     4,   617,   134,
     134,    88,   126,   271,   134,    88,   274,   275,   124,   317,
     134,   134,    79,    80,   126,   323,   123,    88,   128,   327,
     126,   128,   381,   382,   126,   251,   385,   121,   134,   123,
     124,   390,   126,   236,   136,   394,   108,   109,   123,   126,
       4,     5,   255,   126,   128,   258,   123,   134,   121,   122,
     123,   134,   130,   130,   432,   126,   166,   270,   677,   255,
     132,   133,   258,   136,   277,   123,   128,   280,   135,   123,
     283,   165,   130,   136,   270,   383,   121,   136,   697,   255,
     388,   400,   258,   128,   392,   130,     7,   283,   123,   357,
     428,   136,   360,   123,   270,   434,   404,   365,   128,   437,
     130,   277,     4,     5,   280,     4,   136,   283,    97,    98,
      99,   135,   136,   381,   382,   134,   105,   134,   386,   110,
     111,   112,   430,   100,   101,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   132,   123,   119,
     120,   121,   355,   128,   128,   130,   113,   114,   128,   508,
     130,   136,   131,   512,   367,   533,   102,   124,   103,   355,
     149,   150,   151,   302,   303,   304,   305,   104,   371,   437,
     105,   367,   106,   107,   306,   307,   308,   117,   118,   355,
     135,   136,     4,     5,   128,   493,     3,   400,   121,   300,
     301,   367,   309,   310,     5,   131,     4,   410,   506,   126,
       4,     4,   510,   131,   136,   131,   129,   515,    70,   517,
     129,   133,   125,   521,   125,   133,     4,   525,     5,   432,
     528,   529,   530,     4,   400,   533,     4,     4,     4,   133,
     133,   499,   129,     4,   410,   128,   504,   128,   128,   128,
       4,     4,     4,   125,   131,   133,    65,   131,   131,    68,
      69,   131,     4,     4,     4,   131,   432,   596,   131,     4,
     568,   600,    88,     4,   572,    84,     4,    81,   576,    81,
       4,     4,    70,   581,   128,    88,     4,     4,     4,   482,
     548,   484,     4,   591,   592,   488,     4,     4,   129,   129,
     129,   128,   560,   561,   128,     4,   115,   116,   617,   607,
     619,     4,     4,     4,     4,   134,     4,     4,   127,     4,
       4,   129,   620,   621,   622,     4,   624,    77,   626,   129,
     533,   140,   129,   129,   643,   125,     4,   646,   129,     4,
     598,   105,   129,   129,   653,   129,   125,   645,   129,   105,
     648,   649,   161,   546,   663,   664,   654,    72,   551,   668,
     669,   135,   671,   400,   250,   263,   105,   533,    72,   545,
     258,   369,   657,   355,   183,   673,   233,   686,   482,   142,
     295,   480,   691,   297,   482,   694,   695,    -1,   298,   296,
      -1,    -1,    -1,   299,    -1,    -1,    -1,    -1,   707,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   220,    -1,    -1,   617,    -1,   619,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,    -1,   238,
      -1,    -1,    -1,   242,    -1,    -1,    -1,   246,    -1,    -1,
     643,   250,    -1,   646,    -1,    -1,    -1,    -1,   257,    -1,
     653,   617,    -1,   619,   263,    -1,   265,    -1,    -1,   268,
     663,   664,    -1,    -1,    -1,   668,   669,    -1,   671,    -1,
      -1,    -1,    -1,   282,   677,    -1,    -1,   643,    -1,     3,
     646,    -1,    -1,   686,     8,     9,    10,   653,   691,    -1,
      -1,   694,   695,    -1,   697,    -1,    -1,   663,   664,    -1,
      -1,    -1,   668,   669,   707,   671,    -1,   316,    -1,    -1,
     319,   677,    -1,   322,    -1,    -1,   129,    -1,    -1,    -1,
     686,    -1,    -1,    -1,    -1,   691,    -1,    -1,   694,   695,
      -1,   697,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   707,    66,    67,    -1,    -1,    70,    -1,    72,    73,
     163,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     369,   174,   175,   176,   177,   178,   179,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   619,     3,    -1,    -1,    -1,    -1,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,   121,    -1,   123,
     124,    -1,   126,    -1,    -1,    -1,   643,    -1,    -1,   646,
      -1,    -1,    -1,    -1,    -1,    -1,   653,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   663,   664,    -1,   153,
      -1,   668,   669,    -1,   671,   159,    -1,    -1,   251,    -1,
      -1,   165,    -1,   167,    -1,    -1,    66,    67,   172,   686,
      -1,    -1,    72,    73,   691,    75,   180,   694,   695,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     707,   480,    -1,   482,    -1,    -1,    -1,   486,    -1,    -1,
      -1,    -1,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   121,    -1,   123,   124,    -1,   126,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   255,    -1,   153,   258,    -1,   545,    -1,    -1,   159,
      -1,    -1,    -1,    -1,    -1,   165,   270,   167,    -1,    -1,
      -1,    -1,   172,     3,     4,    -1,   280,    -1,    -1,   283,
      -1,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,   434,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   355,    -1,    -1,    -1,   255,    -1,    87,   258,    -1,
      -1,    -1,    -1,   367,    -1,    -1,    -1,    -1,    -1,    -1,
     270,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     280,    -1,    -1,   283,    -1,   115,   116,   117,   118,   119,
     120,    -1,    -1,   123,    -1,    -1,    -1,    -1,   128,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   136,   137,   138,   139,
     140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   432,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   355,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   367,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   596,    -1,    -1,    -1,   600,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    -1,    -1,
      -1,    -1,   432,    11,    12,    13,    14,    15,    16,    17,
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
     128,    -1,    -1,    -1,    -1,    -1,   134,   135,   136,   137,
     138,   139,   140,     3,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    11,    12,    13,    14,    15,    16,    17,    18,    19,
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
      -1,    -1,    -1,    -1,   134,   135,   136,   137,   138,   139,
     140,     3,     4,    -1,    -1,    -1,    -1,    -1,    -1,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    -1,    -1,
      72,    73,    74,    75,    76,    -1,    78,    -1,    -1,    81,
      82,    83,    84,    85,    86,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   115,   116,   117,   118,   119,   120,    -1,
      -1,   123,    -1,    -1,    -1,    -1,   128,    -1,    -1,     3,
      -1,    -1,   134,    -1,   136,   137,   138,   139,   140,    13,
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
      -1,    -1,    -1,    -1,   128,    -1,    -1,   131,   132,     3,
      -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,    13,
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
      -1,    -1,    -1,    -1,   128,    -1,    -1,   131,   132,     3,
      -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,    13,
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
      -1,    -1,    -1,    -1,   128,    -1,    -1,   131,   132,     3,
      -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,    13,
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
      -1,    -1,    -1,    -1,   128,    -1,    -1,   131,   132,     3,
      -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,    13,
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
      -1,    -1,    -1,    -1,   128,   129,    -1,     3,     4,    -1,
      -1,    -1,   136,   137,   138,   139,   140,    13,    14,    15,
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
      -1,    -1,   128,    -1,    -1,     3,     4,    -1,    -1,    -1,
     136,   137,   138,   139,   140,    13,    14,    15,    16,    17,
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
     128,    -1,    -1,     3,    -1,    -1,    -1,    -1,   136,   137,
     138,   139,   140,    13,    14,    15,    16,    17,    18,    19,
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
     120,    -1,    -1,   123,    -1,    -1,    -1,    -1,   128,   129,
      -1,     3,    -1,    -1,    -1,    -1,   136,   137,   138,   139,
     140,    13,    14,    15,    16,    17,    18,    19,    20,    21,
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
      -1,   123,    -1,    -1,    -1,    -1,   128,   129,    -1,     3,
       4,    -1,    -1,    -1,   136,   137,   138,   139,   140,    13,
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
      -1,    -1,    -1,    -1,   128,    -1,    -1,     3,    -1,    -1,
      -1,    -1,   136,   137,   138,   139,   140,    13,    14,    15,
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
      -1,    -1,   128,   129,    -1,     3,    -1,    -1,    -1,    -1,
     136,   137,   138,   139,   140,    13,    14,    15,    16,    17,
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
     128,   129,    -1,     3,    -1,    -1,    -1,    -1,   136,   137,
     138,   139,   140,    13,    14,    15,    16,    17,    18,    19,
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
     120,    -1,    -1,   123,    -1,    -1,    -1,    -1,   128,   129,
      -1,     3,    -1,    -1,    -1,    -1,   136,   137,   138,   139,
     140,    13,    14,    15,    16,    17,    18,    19,    20,    21,
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
      -1,   123,    -1,    -1,    -1,    -1,   128,   129,    -1,     3,
      -1,    -1,    -1,    -1,   136,   137,   138,   139,   140,    13,
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
      -1,    -1,    -1,    -1,   128,    -1,    -1,     3,    -1,    -1,
      -1,    -1,   136,   137,   138,   139,   140,    13,    14,    15,
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
      -1,    -1,   128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     136,   137,   138,   139,   140,     7,    -1,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     8,    -1,   136,    11,    12,    13,    14,    15,
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
     136,    10,    11,    12,    13,    14,    15,    16,    17,    18,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    11,    12,
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
      -1,    -1,    -1,   136,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,   123,   124,    -1,    -1,
      -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,   136,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,
      -1,    -1,    -1,    -1,    -1,   136,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,   123,    -1,
      -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,
      -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   123,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   135,   136,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
     123,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   134,    -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   123,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,   136,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,   123,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   135,   136,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     135,   136,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,   123,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   135,   136,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     123,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   136,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    -1,   123,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   136
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,   142,   143,   138,     0,     7,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    71,    72,    73,    74,    75,
     123,   136,   144,   145,   147,   158,   162,   163,   164,   167,
     168,   169,   172,   175,   235,   236,   237,   238,   239,   240,
       4,   121,   122,   123,   136,   148,   151,   153,   154,   155,
     156,   241,     4,   126,   198,     8,   163,   164,   167,   175,
     236,   238,   236,   238,   241,   235,   235,   241,   241,   239,
     240,   145,   147,   158,    10,   162,   145,   198,   241,   130,
     123,   130,   123,   123,     4,     5,   156,   122,   156,   156,
     123,   157,   123,   136,   199,   200,   201,     4,   149,   153,
     154,   155,   156,   128,   195,   165,   166,   241,   241,   134,
     198,   134,   198,   130,   130,   145,   241,   128,   195,     3,
      67,    68,    69,    87,   115,   116,   117,   118,   119,   120,
     123,   128,   131,   132,   137,   138,   139,   140,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   236,   237,   238,   240,   136,   131,
     132,   207,   208,   209,   228,   151,   157,   123,   157,   157,
     124,   241,   201,     5,   127,   123,   128,   202,     7,   156,
     156,   156,   123,   129,   196,   197,   235,     4,   198,     4,
       5,    88,   202,     4,   135,   170,   171,   235,   134,   135,
     173,   174,   241,   134,   131,   132,   209,   131,   132,   207,
     128,   195,   124,     4,    11,    12,    88,   134,   176,   198,
     134,   159,   235,   132,   220,   220,   220,   220,   220,   220,
     240,   207,   241,   131,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   132,   133,   110,   111,   112,   117,
     118,   113,   114,   124,   119,   120,   121,   130,   202,   121,
       3,   202,   121,   130,   202,   241,   131,     5,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     202,   200,   136,   129,   136,   203,   204,   205,   206,   208,
     241,   124,   150,   152,   241,     5,   129,   241,     4,   166,
     209,   198,     4,   135,   171,   241,   135,   170,     4,     5,
     135,    88,   198,   135,   173,   241,   131,   241,   131,   124,
       4,    11,    12,    88,   176,   198,   129,     4,    88,   176,
     198,     4,    88,   176,   198,   207,     4,    76,    78,    81,
      82,    83,    84,    85,    86,   135,   159,   164,   167,   176,
     177,   178,   179,   180,   181,   182,   183,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   207,   236,   238,     4,
      88,   176,   146,   159,    70,   160,   161,   241,   235,   129,
     133,   207,   211,   212,   213,   214,   215,   216,   216,   217,
     217,   217,   217,   218,   218,   218,   219,   219,   220,   220,
     220,   241,   207,   241,   241,   207,   133,   207,   208,   208,
     208,   208,   208,   208,   208,   208,   208,   208,   208,   208,
       5,   129,     5,   129,   125,     4,     5,   197,    88,   198,
     198,     4,     4,    88,   198,     4,   135,   174,     4,   208,
       4,   135,   133,   133,   129,     4,    88,   176,   198,     4,
      88,   176,   198,   207,     4,    88,   176,    88,   198,   207,
       4,    88,   176,   207,     4,    88,   176,     4,   128,   128,
     128,   179,   180,   128,     4,     4,   207,   135,   178,     4,
     207,   135,   159,   220,     4,     5,    88,   198,   202,   133,
     131,   125,   131,   131,   131,   205,   203,   206,   208,   241,
     208,   207,     4,     4,   198,     4,   131,   131,    88,   198,
     207,     4,    88,   176,   207,     4,    88,   176,     4,   207,
     207,    88,     4,   207,     4,   207,   207,   207,   207,    81,
      81,     4,   159,   207,     4,     4,    70,   161,   208,   198,
     128,   208,   129,   198,     4,   198,   207,    88,     4,   207,
       4,   207,     4,     4,   207,     4,     4,   129,   129,   129,
     128,   128,     4,   207,     4,   207,     4,   220,   198,   220,
       4,     4,   207,     4,     4,     4,   178,   179,   134,   179,
     180,   207,   207,   129,   207,     4,   129,   207,     4,     4,
     207,   129,     4,    77,    79,    80,   135,   184,   185,   129,
     129,   179,   180,   129,   129,   207,   179,   180,   129,   129,
     207,   129,   207,     4,   179,   180,   207,   125,   135,   185,
       4,     4,   179,   180,   179,   180,   129,   179,   180,   179,
     180,   129,   179,   180,   129,   129,   207,   125,   178,   179,
     180,   179,   180,   179,   180,   179,   180,   129,   178,   179,
     180
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   141,   142,   142,   142,   142,   142,   142,   142,   142,
     143,   144,   144,   145,   145,   146,   146,   147,   147,   148,
     148,   149,   149,   149,   149,   150,   150,   151,   151,   151,
     151,   151,   151,   151,   151,   152,   152,   153,   154,   154,
     155,   156,   156,   157,   158,   158,   159,   160,   160,   161,
     161,   161,   161,   161,   161,   162,   162,   162,   162,   162,
     162,   162,   162,   163,   163,   164,   165,   165,   166,   166,
     166,   166,   167,   167,   167,   168,   169,   169,   169,   169,
     170,   170,   171,   171,   171,   171,   172,   172,   172,   172,
     173,   173,   174,   174,   174,   174,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   176,   176,   177,   177,
     178,   178,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   180,   180,   180,   180,
     181,   182,   182,   183,   183,   184,   184,   185,   185,   185,
     185,   186,   187,   188,   189,   190,   190,   190,   190,   190,
     190,   190,   190,   190,   190,   190,   190,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   192,
     193,   194,   195,   195,   196,   196,   197,   197,   197,   197,
     198,   199,   199,   200,   200,   201,   201,   202,   202,   202,
     202,   203,   203,   204,   204,   205,   206,   207,   207,   208,
     208,   208,   208,   208,   208,   208,   208,   208,   208,   208,
     208,   208,   209,   209,   210,   210,   211,   211,   212,   212,
     213,   213,   214,   214,   215,   215,   215,   216,   216,   216,
     216,   216,   217,   217,   217,   217,   218,   218,   218,   219,
     219,   219,   219,   220,   220,   220,   220,   220,   220,   220,
     220,   221,   221,   222,   222,   223,   223,   223,   223,   223,
     223,   224,   224,   224,   224,   225,   226,   226,   227,   227,
     227,   227,   228,   228,   229,   229,   229,   230,   230,   230,
     231,   231,   232,   233,   233,   233,   234,   234,   235,   235,
     235,   235,   235,   235,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   237,   237,   238,   238,   238,
     238,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   240,   240,   241
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
       3,     3,     1,     3,     2,     3,     1,     5,     3,     3,
       2,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     5,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     2,     2,     2,     2,     2,     2,     1,
       1,     1,     1,     4,     6,     2,     2,     3,     2,     4,
       1,     1,     1,     1,     3,     7,     2,     2,     1,     1,
       1,     1,     1,     1,     3,     4,     1,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     2,     2,
       1,     2,     2,     1,     7,     5,     4,     7,     4,     6,
       4,     3,     6,     3,     1,     5,     4,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1
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
#line 168 "../../Private/MatC/MDL/MDLParser.y" /* yacc.c:1646  */
    { (yyval._null) = NULL; }
#line 3088 "../../Private/MatC/MDL/MDLParser.inl" /* yacc.c:1646  */
    break;

  case 3:
#line 169 "../../Private/MatC/MDL/MDLParser.y" /* yacc.c:1646  */
    { (yyval._null) = NULL; }
#line 3094 "../../Private/MatC/MDL/MDLParser.inl" /* yacc.c:1646  */
    break;

  case 4:
#line 170 "../../Private/MatC/MDL/MDLParser.y" /* yacc.c:1646  */
    { (yyval._null) = NULL; }
#line 3100 "../../Private/MatC/MDL/MDLParser.inl" /* yacc.c:1646  */
    break;

  case 5:
#line 171 "../../Private/MatC/MDL/MDLParser.y" /* yacc.c:1646  */
    { (yyval._null) = NULL; }
#line 3106 "../../Private/MatC/MDL/MDLParser.inl" /* yacc.c:1646  */
    break;

  case 6:
#line 172 "../../Private/MatC/MDL/MDLParser.y" /* yacc.c:1646  */
    { (yyval._null) = NULL; }
#line 3112 "../../Private/MatC/MDL/MDLParser.inl" /* yacc.c:1646  */
    break;

  case 7:
#line 173 "../../Private/MatC/MDL/MDLParser.y" /* yacc.c:1646  */
    { (yyval._null) = NULL; }
#line 3118 "../../Private/MatC/MDL/MDLParser.inl" /* yacc.c:1646  */
    break;

  case 8:
#line 174 "../../Private/MatC/MDL/MDLParser.y" /* yacc.c:1646  */
    { (yyval._null) = NULL; }
#line 3124 "../../Private/MatC/MDL/MDLParser.inl" /* yacc.c:1646  */
    break;

  case 9:
#line 175 "../../Private/MatC/MDL/MDLParser.y" /* yacc.c:1646  */
    { (yyval._null) = NULL; }
#line 3130 "../../Private/MatC/MDL/MDLParser.inl" /* yacc.c:1646  */
    break;

  case 17:
#line 188 "../../Private/MatC/MDL/MDLParser.y" /* yacc.c:1646  */
    { (yyval._decl) = NULL; }
#line 3136 "../../Private/MatC/MDL/MDLParser.inl" /* yacc.c:1646  */
    break;

  case 18:
#line 189 "../../Private/MatC/MDL/MDLParser.y" /* yacc.c:1646  */
    { (yyval._decl) = NULL; }
#line 3142 "../../Private/MatC/MDL/MDLParser.inl" /* yacc.c:1646  */
    break;


#line 3146 "../../Private/MatC/MDL/MDLParser.inl" /* yacc.c:1646  */
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
