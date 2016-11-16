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

void yyerror(const char *s);

%}


%%

[ \t]	; // ignore all whitespace
"pi" { return MPI; }
"sin" { return SIN; }
"cos" { return  COS; }
"exp" { return EXP; }
"tan" { return TAN; }
"draw" { return DRAW; }
"sqrt" { return SQRT; }
"arcsin" { return ARCSIN; }
"arcos" { return ARCOS; }
"arctan" { return ARCTAN; }
(blue|red|yellow|green) { yylval.sval = yytext; return COLOR; }
"x" {return X;}
(-?([0-9])*(\.[0-9]+)?) 	{yylval.fval = atof(yytext); return FLOAT;}
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
