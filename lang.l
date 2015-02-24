%{
// lang lexer definition file
//
// Author: Casey Schurman

#include "lex.h"

#define RETURN(a) return Return(a);
static int Return(int val);

%}

%option noyywrap
%option noinput
%option nounput
%option yylineno


	/* definitions */
punct       [\.\,\;\[\]\{\}\(\)]
operators	[\+\-\*\/\%\=\!\<]	
identifiers	[a-zA-Z][a-zA-Z0-9_]*
integer		[-]?[0-9]+
float		[-]?[0-9]+\.[0-9]+
whitespace  [' '\t\n]+
comment     "//".*$
junk        .

%%

"if"                        RETURN(IF);
"else"                      RETURN(ELSE);
"while"                     RETURN(WHILE);
"print"                     RETURN(PRINT);
"scan"                      RETURN(SCAN);
"struct"                    RETURN(STRUCT);
"return"                    RETURN(RETURN_TOK);
"array"                     RETURN(ARRAY);

{identifiers}	{
                    yylval.symbol = symbolTableRoot->FullLookup(yytext);
                  
                    if(yylval.symbol != nullptr)
                    {
                        if(yylval.symbol->IsType())
                        {
                            RETURN(TYPE_ID);
                        }
                    }
                    else
                    {
                        yylval.symbol = new cSymbol(yytext);
                    }
                    
                    RETURN(IDENTIFIER);
                    
                }
{integer}	{   
                yylval.int_val = atoi(yytext);
                RETURN (INT_VAL);
            }
{float}		{
                yylval.float_val = atof(yytext);
                RETURN (FLOAT_VAL);
            }
{punct}		RETURN (yytext[0]);
{operators}	RETURN (yytext[0]);
{whitespace}                {};
{comment}                   {};
{junk}		RETURN (JUNK_TOKEN);

%%

//This function allows us to do extra processing on each token
static int Return(int val)
{
    //printf("Scanned '%s': %d\n", yytext, val);
    return val;
}