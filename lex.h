#pragma once
#include "langparse.h"
#include "cSymbolTable.h"
#include "cSymbol.h"

int yyparse();
int yylex();
extern char *yytext;
extern int yylineno;
extern FILE *yyin;
extern cSymbolTable *symbolTableRoot;