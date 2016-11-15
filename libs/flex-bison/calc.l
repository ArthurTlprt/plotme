%option noyywrap

%{
#include <stdio.h>

#define YY_DECL int yylex()

#include "calc.tab.h"

%}

%%

[ \t]	; // ignore all whitespace
"pi" { return PI; }
"sin" { return SIN; }
"cos" { return  COS; }
"exp" { return EXP; }
"tan" { return TAN; }
"arcsin" { return ARCSIN; }
"arcos" { return ARCOS; }
"arctan" { return ARCTAN; }
"x" {return X;}
(-?[1-9]([0-9])*(\.[0-9]+)?) 	{yylval.fval = atof(yytext); return FLOAT;}
[a-zA-Z]+"(x)" { return FUNCTION; }
([A-Za-z]|_)+([A-Za-z]|_|[0-9])+ { return VARIABLE; }
\n		{return NEWLINE;}
"+"		{return PLUS;}
"-"		{return MINUS;}
"*"		{return MULTIPLY;}
"/"		{return DIVIDE;}
"("		{return LEFT;}
")"		{return RIGHT;}
"="   {return EQUAL;}
"exit"		{return QUIT;}
"quit"		{return QUIT;}

%%
