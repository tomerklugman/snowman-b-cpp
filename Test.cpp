/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 *
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: Tomer Klugman
 *
 * Date: 2021-02
 */

#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

TEST_CASE("Good snowman code") { // checks all test cases for each row at least once - (1,2,3,4) every part being checked
	CHECK(snowman(11114411) == string("\n _===_\n (.,.) \n ( : ) \n ( : )\n"));
	CHECK(snowman(21111111) == string("\n  ___ \n .....\n (.,.) \n<( : )>\n ( : )\n"));
	CHECK(snowman(12111111) == string("\n _===_\n (...) \n<( : )>\n ( : )\n"));
	CHECK(snowman(11211111) == string("\n _===_\n (o,.) \n<( : )>\n ( : )\n"));
	CHECK(snowman(11121111) == string("\n _===_\n (.,o) \n<( : )>\n ( : )\n"));
	CHECK(snowman(11112111) == string("\n _===_\n\\(.,.) \n ( : )>\n ( : )\n"));
	CHECK(snowman(11111211) == string("\n _===_\n (.,.)/\n<( : ) \n ( : )\n"));
	CHECK(snowman(11111121) == string("\n _===_\n (.,.) \n<(] [)>\n ( : )\n"));
	CHECK(snowman(11111112) == string("\n _===_\n (.,.) \n<( : )>\n (\" \")\n"));
	CHECK(snowman(11111111) == string("\n _===_\n (.,.) \n<( : )>\n ( : )\n"));
	CHECK(snowman(22222222) == string("\n  ___ \n .....\n\\(o.o)/\n (] [) \n (\" \")\n"));
	CHECK(snowman(33333333) == string("\n   - \n  /_\\ \n (O_O) \n/(> <)\\\n (___)\n"));
	CHECK(snowman(44444444) == string("\n  ___\n (_*_)\n (- -) \n (   ) \n (   )\n"));
}

TEST_CASE("Bad snowman code") {
	CHECK_THROWS(snowman(555));
	CHECK_THROWS(snowman(55555555));
	CHECK_THROWS(snowman(-1-1-1-1-1-1-1-1));
	CHECK_THROWS(snowman(00000000));
	//CHECK_THROWS(snowman(''));
    //CHECK_THROWS(snowman('abc')); //just chars
	//CHECK_THROWS(snowman('214abc')); //int start then chars
}

TEST_CASE("int string less then 8 but int between 1-4") { // more bad snowman code
	CHECK_THROWS(snowman(1)); //need exactly 8 int string a/10000000=0
	CHECK_THROWS(snowman(11));
	CHECK_THROWS(snowman(111));
	CHECK_THROWS(snowman(1111));
	CHECK_THROWS(snowman(11111));
	CHECK_THROWS(snowman(111111));
	CHECK_THROWS(snowman(1111111));
}

TEST_CASE("int string more then 8 but int between 1-4") { // more bad snowman code
	CHECK_THROWS(snowman(111111111)); //need exactly 8 int string a/10000000=1
	CHECK_THROWS(snowman(111111110)); //need exactly 8 int string a/10000000=10
	CHECK_THROWS(snowman(1111111110)); //need exactly 8 int string a/10000000=110
}
