

%{

#include "stdio.h"


%}
%%

(-?[1-9]([0-9])*(\.[0-9]+)?) {
	printf("number ");
}
[a-zA-Z]+"(x)" {
	printf("function ");
}
([A-Za-z]|_)+([A-Za-z]|_|[0-9])+ {
	printf("variable ");
}
"(" {
	printf("\"(\"" );
}
")" {
	printf("\")\"" );
}
\+ {
	printf("plus ");
}
\- {
	printf("minus ");
}
\* {
	printf("multiplication  ");
}
\/ {
	printf("division ");
}
\= {
	printf("equal ");
}


%%


int main()
{
	// flex -o exo1.c exo1.l
	// cc -o exo1.out exo1.c -ll
	// ./exo1.out < text
	// cat text | ./exo1.out
	yylex();
	printf("hello world");
}
