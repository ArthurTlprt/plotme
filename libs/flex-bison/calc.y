%{

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

extern int yylex();
extern int yyparse();
extern FILE* yyin;

void yyerror(const char* s);
%}

%union {
	int ival;
	float fval;
}

%token<fval> FLOAT
%token PLUS MINUS MULTIPLY DIVIDE LEFT RIGHT EQUAL
%token NEWLINE QUIT
%token FUNCTION X VARIABLE
%token PI EXP SIN COS TAN ARCTAN ARCSIN ARCOS
%left PLUS MINUS
%left MULTIPLY DIVIDE

%type<fval> mixed_expression

%start calculation

%%

calculation:
	   | calculation line
;

line: NEWLINE
    | mixed_expression NEWLINE { printf("\tResult: %f\n", $1);}
    | QUIT NEWLINE { printf("bye!\n"); exit(0); }
;

mixed_expression: X { $$ = 42 }
		|	PI { $$ = PI }
		|	FUNCTION EQUAL mixed_expression	{ $$ = $3; }
		| VARIABLE EQUAL mixed_expression { $$ = $3; }
		| FLOAT                 		 { $$ = $1; }
	  | mixed_expression PLUS mixed_expression	 { $$ = $1 + $3; }
	  | mixed_expression MINUS mixed_expression	 { $$ = $1 - $3; }
	  | mixed_expression MULTIPLY mixed_expression { $$ = $1 * $3; }
	  | mixed_expression DIVIDE mixed_expression	 { $$ = $1 / $3; }
	  | LEFT mixed_expression RIGHT		 { $$ = $2; }
	  /*| expression PLUS mixed_expression	 	 { $$ = $1 + $3; }
	  | expression MINUS mixed_expression	 	 { $$ = $1 - $3; }
	  | expression MULTIPLY mixed_expression 	 { $$ = $1 * $3; }
	  | expression DIVIDE mixed_expression	 { $$ = $1 / $3; }
	  | mixed_expression PLUS expression	 	 { $$ = $1 + $3; }
	  | mixed_expression MINUS expression	 	 { $$ = $1 - $3; }
	  | mixed_expression MULTIPLY expression 	 { $$ = $1 * $3; }
	  | mixed_expression DIVIDE expression	 { $$ = $1 / $3; }
	  | expression DIVIDE expression		 { $$ = $1 / (float)$3; }*/
;

/*expression: INT				{ $$ = $1; }
	  | expression PLUS expression	{ $$ = $1 + $3; }
	  | expression MINUS expression	{ $$ = $1 - $3; }
	  | expression MULTIPLY expression	{ $$ = $1 * $3; }
	  | LEFT expression RIGHT		{ $$ = $2; }
;*/

%%

int main() {
	yyin = stdin;

	do {
		yyparse();
	} while(!feof(yyin));

	return 0;
}

void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
}
