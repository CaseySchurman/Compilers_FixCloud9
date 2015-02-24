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

#ifndef YY_YY_LANGPARSE_H_INCLUDED
# define YY_YY_LANGPARSE_H_INCLUDED
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
    IDENTIFIER = 258,
    TYPE_ID = 259,
    INT_VAL = 260,
    FLOAT_VAL = 261,
    SCAN = 262,
    PRINT = 263,
    WHILE = 264,
    IF = 265,
    ELSE = 266,
    STRUCT = 267,
    ARRAY = 268,
    RETURN_TOK = 269,
    JUNK_TOKEN = 270
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 11 "lang.y" /* yacc.c:1909  */

    int             int_val;
    double          float_val;
    cAstNode*       ast_node;
    cSymbol*        symbol;
    cSymbolTable*   sym_table;
    BlockNode*      block_node;
    PrintNode*      print_node;
    StmtsNode*      stmts_node;
    StmtNode*       stmt_node;
    ExprNode*       expr_node;
    VarRef*         var_ref;
    DeclsNode*      decls_node;
    DeclNode*       decl_node;
    ArraySpec*      arrspec_node;
    VarPart*        var_part;
    ArrayVal*       arrval_node;
    FuncHeader*     fun_header;
    FuncCall*       fun_call;
    FuncPrefix*     fun_prefix;
    ParamNode*      param_node;
    ParamsNode*     params_node;
    ParamSpec*      param_spec;
    ParamsSpec*     params_spec;
    unordered_map<string,cSymbol*>* map_node;
    

#line 98 "langparse.h" /* yacc.c:1909  */
};
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


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_LANGPARSE_H_INCLUDED  */
