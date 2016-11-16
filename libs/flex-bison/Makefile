all:
	flex -o scanner.cpp scanner.l
	bison -d parser.ypp
	g++ -o run scanner.cpp parser.tab.cpp

clean:
	rm lex.yy.cc
	rm parser.cpp
	rm parser.tab.cpp
	rm parser.tab.hpp
	rm scanner.cpp
