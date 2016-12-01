all:
	bison -W -d parser.ypp
	flex -o scanner.cpp scanner.l
	g++ -o run scanner.cpp parser.tab.cpp
	node-gyp configure build

clean:
	rm parser.tab.cpp
	rm parser.tab.hpp
	rm scanner.cpp
	rm -r build
