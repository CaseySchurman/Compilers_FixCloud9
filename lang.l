%{
// lang lexer definition file
//
// Author: Casey Schurman

#include "cSymbolTable.h"
#include "lex.h"

#define RETURN(a) return Return(a);
//static int Return(int val);

%}

%option noyywrap
%option noinput
%option nounput
%option yylineno


	/* definitions */
punct		[()\[\];,\.]
operators	[\+\-\*\/\%\=\!\<]	
identifiers	[a-zA-Z][a-zA-Z0-9_]*
integer		[-]?[0-9]+
float		[-]?[0-9]+\.[0-9]+
junk		.

%%

	/* rules */

{punct}		return yytext[0];
{operators}	return yytext[0];

"{"             {
                    symbolTableRoot->IncreaseScope();
                    return yytext[0];
                }
"}"             {
                    symbolTableRoot->DecreaseScope();
                    return yytext[0];
                }

"//".*		//No comments!
[ \t\n\r]	//No whitespace!

"if"		return (IF);
"else"		return (ELSE);
"while"		return (WHILE);
"print"		return (PRINT);
"scan"		return (SCAN);
"int"		return (INT);
"float"		return (FLOAT);
"char"		return (CHAR);
"struct"	return (STRUCT);
"return"	return (RETURN_TOK);

{identifiers}	{
                    if(symbolTableRoot->CurLookup(yytext) == nullptr)
                    {
                        yylval.symbol = new cSymbol(yytext);
                        symbolTableRoot->InsertSymbol(yytext,yylval.symbol);
                    }
                    else
                    {
                        yylval.symbol = symbolTableRoot->CurLookup(yytext);
                    }
                    return (IDENTIFIER);
                }
{integer}	return (INT_VAL);
{float}		return (FLOAT_VAL);
	 	
{junk}		return (JUNK_TOKEN);	
%%

// This function allows us to do extra processing on each token
//static int Return(int val)
//{
//    printf("Scanned '%s': %d\n", yytext, val);
//    return val;
//}

