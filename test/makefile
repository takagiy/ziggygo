.PHONY: clean CLEAN run

run: test
	./test

test: test.cpp test_line.hpp catch.hpp
	g++ test.cpp -o test -I. -I../include -std=c++11

catch.hpp:
	wget https://github.com/catchorg/Catch2/releases/download/v2.7.2/catch.hpp

clean:
	rm -f test

CLEAN: clean
	rm -f catch.hpp
