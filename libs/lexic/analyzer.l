

%{

#include <vector>



%}
%%

[a-zA-Z0-9]+ {

}

y = {

}

-?[1-9]([0-9]?)+(.[0-9]+)? {

}

[a-zA-Z](x) {

}

+ {

}

sin {
	
}

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
