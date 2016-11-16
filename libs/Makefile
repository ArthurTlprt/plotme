all:
	flex -o scanner.cpp scanner.l
	bison -d parser.ypp
	node-gyp configure build

clean:
	rm parser.tab.cpp
	rm parser.tab.hpp
	rm scanner.cpp
	rm -r build
	rm run
