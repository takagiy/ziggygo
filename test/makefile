# Copyright (c) TakagiY 2019
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE or copy at http://boost.org/LICENSE_1_0.txt)

.PHONY: clean CLEAN run

run: test
	./test

test: test.cpp test_line.hpp  test_path.hpp catch.hpp
	g++ test.cpp -o test -I. -I../include -std=c++11

catch.hpp:
	wget https://github.com/catchorg/Catch2/releases/download/v2.7.2/catch.hpp

clean:
	rm -f test

CLEAN: clean
	rm -f catch.hpp
