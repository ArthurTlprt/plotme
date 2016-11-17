all:
	bison -d parser.ypp
	flex -o scanner.cpp scanner.l
	node-gyp configure build

clean:
	rm parser.tab.cpp
	rm parser.tab.hpp
	rm scanner.cpp
	rm -r build
	rm run
