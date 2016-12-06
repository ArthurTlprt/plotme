%option noyywrap

%{
#define YY_DECL int yylex()

#include "parser.tab.hpp"
#include <cstdio>
#include <iostream>
#include <fstream>

using namespace std;


void yyerror(const char *s);

%}


%%

[ \t]	; // ignore all whitespace
"x" {return X;}
"y" {return Y;}
"title" {return TITLE;}
"pi" { return MPI; }
"sin" { return SIN; }
"cos" { return  COS; }
"exp" { return EXP; }
"ln" { return LN; }
"log" { return LOG; }
"tan" { return TAN; }
"draw" { return DRAW; }
"sqrt" { return SQRT; }
"^"  { return POW; }
"abs" { return ABS; }
"arcsin" { return ARCSIN; }
"arcos" { return ARCOS; }
"arctan" { return ARCTAN; }
"quit"		{return QUIT;}
"exit"		{return QUIT;}
","   {return COMA;}
"["   {return BRACKETL;}
"]"   {return BRACKETR;}
"-"		{return MINUS;}
\n		{return NEWLINE;}
"+"		{return PLUS;}
"*"		{return MULTIPLY;}
"/"		{return DIVIDE;}
"("		{return LEFT;}
")"		{return RIGHT;}
"="   {return EQUAL;}
(([0-9])+(\.[0-9]+)?) 	{yylval.fval = atof(yytext); return FLOAT;}
("#"[A-Fa-f0-9]{6})|("blue"|"red"|"yellow"|"green"|"black"|"purple"|"pink"|"white"|"orange") { yylval.sval = strdup(yytext); return COLOR; }
([A-Za-z]|_|[0-9])+ { yylval.sval = strdup(yytext);printf("lex: %s\n", yytext); return VARIABLE;}



%%
