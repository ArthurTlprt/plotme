/* déclarations Bison */
%{
/* déclarations C/C++ */
  #include <stdio.h>
  #define YYSTYPE double /* Le type de retour */
}%
%token NUMBER /* NUMBER est un token*/
%left '+' '-' /* associativité à gauche */
%left '*' '/' /* associativité à gauche */
%%
/* Règles de production + Actions */
program: /* empty */


%%
/* Code en C/C++ */
