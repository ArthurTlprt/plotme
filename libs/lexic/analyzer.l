

%{

#include <vector>

int num_lines = 0, num_chars = 0, num_words = 0;

%}
%%

\n ++num_lines; ++num_chars;
[a-zA-Z0-9]+ {
	++num_words;
	num_chars += strlen(yytext);
	printf("# %d est %s \n",num_words, yytext);
}
. ++num_chars;

%%
int main()
{
	// flex -o exo1.c exo1.l
	// cc -o exo1.out exo1.c -ll
	// ./exo1.out < text
	// cat text | ./exo1.out
	yylex();
	printf( "# of lines = %d, # of chars = %d, # of words = %d\n",
			num_lines, num_chars, num_words );
}
