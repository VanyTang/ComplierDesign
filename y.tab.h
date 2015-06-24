/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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
    _COMMA_SIGN = 264,
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
#define _COMMA_SIGN 264
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
