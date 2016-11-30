%option noyywrap

%{
#define YY_DECL int yylex()

#include "parser.tab.hpp"
#include <cstdio>
#include <iostream>

using namespace std;

// stuff from flex that bison needs to know about:
/*extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;*/
//[a-zA-Z]+"(x)" { return FUNCTION; }

void yyerror(const char *s);

////("rgb("([0-9]{3}","){2}[0-9]{3}")")
%}


%%

[ \t]	; // ignore all whitespace
"x" {return X;}
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
"-"		{return MINUS;}
","   {return COMA;}
"["   {return BRACKETL;}
"]"   {return BRACKETR;}
("#"?[A-Fa-f0-9]{6}|[a-fA-F0-9]{3})|("blue"|"red"|"yellow"|"green"|"black"|"purple"|"pink"|"white"|"orange") { yylval.sval = yytext; return COLOR; }
(([0-9])*(\.[0-9]+)?) 	{yylval.fval = atof(yytext); return FLOAT;}
([A-Za-z]|_|[0-9])+ { yylval.sval = yytext; return VARIABLE; }
\n		{return NEWLINE;}
"+"		{return PLUS;}
"*"		{return MULTIPLY;}
"/"		{return DIVIDE;}
"("		{return LEFT;}
")"		{return RIGHT;}
"="   {return EQUAL;}


%%
