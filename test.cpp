// ============================================================
// Test File for MyString Lab
// Uses Catch2 (single-header amalgamated version)
// ============================================================
// All tests in ONE file. Run per group using tags:
//   ./test_runner [group1]
//   ./test_runner [group2]
//   ...
//   ./test_runner           (runs all)
// ============================================================

#define main student_main
#include "MainProgram.cpp"
#undef main

#include "catch_amalgamated.hpp"

// ============================================================
// GROUP 1: Constructors and Getter (9 points)
// ============================================================

TEST_CASE("Constructor: Default constructor creates empty string", "[group1]") {
    MyString s;
    REQUIRE(s.getData() == "");
}

TEST_CASE("Constructor: std::string constructor", "[group1]") {
    MyString s(string("Hello"));
    REQUIRE(s.getData() == "Hello");
}

TEST_CASE("Constructor: C-string constructor", "[group1]") {
    MyString s("World");
    REQUIRE(s.getData() == "World");
}

TEST_CASE("Constructor: Empty string via std::string", "[group1]") {
    MyString s(string(""));
    REQUIRE(s.getData() == "");
}

TEST_CASE("Constructor: Empty C-string", "[group1]") {
    MyString s("");
    REQUIRE(s.getData() == "");
}

TEST_CASE("Constructor: String with spaces", "[group1]") {
    MyString s("Hello World");
    REQUIRE(s.getData() == "Hello World");
}

TEST_CASE("Constructor: String with special characters", "[group1]") {
    MyString s("C++ is #1!");
    REQUIRE(s.getData() == "C++ is #1!");
}

TEST_CASE("Getter: getData returns correct value", "[group1]") {
    MyString s("Test");
    REQUIRE(s.getData() == "Test");
}

TEST_CASE("Getter: getData on empty string", "[group1]") {
    MyString s;
    REQUIRE(s.getData() == "");
}

// ============================================================
// GROUP 2: Basic String Operations (12 points)
// ============================================================

TEST_CASE("length: Normal string", "[group2]") {
    MyString s("Hello");
    REQUIRE(s.length() == 5);
}

TEST_CASE("length: Empty string returns 0", "[group2]") {
    MyString s;
    REQUIRE(s.length() == 0);
}

TEST_CASE("length: String with spaces", "[group2]") {
    MyString s("Hi There");
    REQUIRE(s.length() == 8);
}

TEST_CASE("charAt: First character", "[group2]") {
    MyString s("Hello");
    REQUIRE(s.charAt(0) == 'H');
}

TEST_CASE("charAt: Last character", "[group2]") {
    MyString s("Hello");
    REQUIRE(s.charAt(4) == 'o');
}

TEST_CASE("charAt: Middle character", "[group2]") {
    MyString s("Hello");
    REQUIRE(s.charAt(2) == 'l');
}

TEST_CASE("charAt: Negative index throws", "[group2]") {
    MyString s("Hello");
    REQUIRE_THROWS_AS(s.charAt(-1), out_of_range);
}

TEST_CASE("charAt: Index equal to length throws", "[group2]") {
    MyString s("Hello");
    REQUIRE_THROWS_AS(s.charAt(5), out_of_range);
}

TEST_CASE("substring: Normal case from start", "[group2]") {
    MyString s("Hello World");
    REQUIRE(s.substring(0, 5).getData() == "Hello");
}

TEST_CASE("substring: From middle", "[group2]") {
    MyString s("Hello World");
    REQUIRE(s.substring(6, 5).getData() == "World");
}

TEST_CASE("substring: Invalid start throws", "[group2]") {
    MyString s("Hello");
    REQUIRE_THROWS_AS(s.substring(10, 2), out_of_range);
}

// ============================================================
// GROUP 3: String Manipulation (16 points)
// ============================================================

TEST_CASE("toUpperCase: Normal mixed case", "[group3]") {
    MyString s("Hello World");
    REQUIRE(s.toUpperCase().getData() == "HELLO WORLD");
}

TEST_CASE("toUpperCase: Already uppercase", "[group3]") {
    MyString s("ABC");
    REQUIRE(s.toUpperCase().getData() == "ABC");
}

TEST_CASE("toUpperCase: All lowercase", "[group3]") {
    MyString s("xyz");
    REQUIRE(s.toUpperCase().getData() == "XYZ");
}

TEST_CASE("toUpperCase: Empty string", "[group3]") {
    MyString s("");
    REQUIRE(s.toUpperCase().getData() == "");
}

TEST_CASE("toLowerCase: Normal mixed case", "[group3]") {
    MyString s("Hello World");
    REQUIRE(s.toLowerCase().getData() == "hello world");
}

TEST_CASE("toLowerCase: Already lowercase", "[group3]") {
    MyString s("abc");
    REQUIRE(s.toLowerCase().getData() == "abc");
}

TEST_CASE("toLowerCase: Empty string", "[group3]") {
    MyString s("");
    REQUIRE(s.toLowerCase().getData() == "");
}

TEST_CASE("trim: Leading and trailing spaces", "[group3]") {
    MyString s("   Hello   ");
    REQUIRE(s.trim().getData() == "Hello");
}

TEST_CASE("trim: Only whitespace returns empty", "[group3]") {
    MyString s("     ");
    REQUIRE(s.trim().getData() == "");
}

TEST_CASE("trim: Tabs and newlines", "[group3]") {
    MyString s("\t\n  Hi  \n\t");
    REQUIRE(s.trim().getData() == "Hi");
}

TEST_CASE("trim: No whitespace to trim", "[group3]") {
    MyString s("Hello");
    REQUIRE(s.trim().getData() == "Hello");
}

TEST_CASE("reverse: Normal string", "[group3]") {
    MyString s("Hello");
    REQUIRE(s.reverse().getData() == "olleH");
}

TEST_CASE("reverse: Empty string", "[group3]") {
    MyString s("");
    REQUIRE(s.reverse().getData() == "");
}

// ============================================================
// GROUP 4: Search Operations (8 points)
// ============================================================

TEST_CASE("find: Target found at start", "[group4]") {
    MyString s("Hello World");
    REQUIRE(s.find(MyString("Hello")) == 0);
}

TEST_CASE("find: Target found in middle", "[group4]") {
    MyString s("Hello World");
    REQUIRE(s.find(MyString("World")) == 6);
}

TEST_CASE("find: Target not found returns -1", "[group4]") {
    MyString s("Hello World");
    REQUIRE(s.find(MyString("xyz")) == -1);
}

TEST_CASE("find: Empty target returns 0", "[group4]") {
    MyString s("Hello");
    REQUIRE(s.find(MyString("")) == 0);
}

TEST_CASE("count: Character appears multiple times", "[group4]") {
    MyString s("Hello World");
    REQUIRE(s.count('l') == 3);
}

TEST_CASE("count: Character appears once", "[group4]") {
    MyString s("Hello");
    REQUIRE(s.count('H') == 1);
}

TEST_CASE("count: Character not present returns 0", "[group4]") {
    MyString s("Hello");
    REQUIRE(s.count('z') == 0);
}

TEST_CASE("count: Empty string returns 0", "[group4]") {
    MyString s("");
    REQUIRE(s.count('a') == 0);
}

// ============================================================
// GROUP 5: Function Overloading - append (12 points)
// ============================================================

TEST_CASE("append(MyString): Normal case", "[group5]") {
    MyString s("Hello");
    MyString other(" World");
    REQUIRE(s.append(other).getData() == "Hello World");
}

TEST_CASE("append(MyString): Append empty string", "[group5]") {
    MyString s("Hello");
    MyString empty("");
    REQUIRE(s.append(empty).getData() == "Hello");
}

TEST_CASE("append(C-str): Normal case", "[group5]") {
    MyString s("Hello");
    REQUIRE(s.append(" C++").getData() == "Hello C++");
}

TEST_CASE("append(C-str): Append empty C-string", "[group5]") {
    MyString s("Hello");
    REQUIRE(s.append("").getData() == "Hello");
}

TEST_CASE("append(char): Normal character", "[group5]") {
    MyString s("Hello");
    REQUIRE(s.append('!').getData() == "Hello!");
}

TEST_CASE("append(char): Append space", "[group5]") {
    MyString s("Hi");
    REQUIRE(s.append(' ').getData() == "Hi ");
}

TEST_CASE("append(int): Positive number", "[group5]") {
    MyString s("Value: ");
    REQUIRE(s.append(42).getData() == "Value: 42");
}

TEST_CASE("append(int): Zero", "[group5]") {
    MyString s("Zero: ");
    REQUIRE(s.append(0).getData() == "Zero: 0");
}

TEST_CASE("append(int): Negative number", "[group5]") {
    MyString s("Neg: ");
    REQUIRE(s.append(-5).getData() == "Neg: -5");
}

// ============================================================
// GROUP 6: Function Overloading - replace (10 points)
// ============================================================

TEST_CASE("replace(char,char): Replace existing char", "[group6]") {
    MyString s("Hello");
    REQUIRE(s.replace('l', 'r').getData() == "Herro");
}

TEST_CASE("replace(char,char): Char not found - no change", "[group6]") {
    MyString s("Hello");
    REQUIRE(s.replace('z', 'x').getData() == "Hello");
}

TEST_CASE("replace(char,char): Multiple occurrences", "[group6]") {
    MyString s("aabaa");
    REQUIRE(s.replace('a', 'x').getData() == "xxbxx");
}

TEST_CASE("replace(char,char): Empty string", "[group6]") {
    MyString s("");
    REQUIRE(s.replace('a', 'b').getData() == "");
}

TEST_CASE("replace(str,str): Normal replacement", "[group6]") {
    MyString s("Hello World");
    REQUIRE(s.replace(string("World"), string("C++")).getData() == "Hello C++");
}

TEST_CASE("replace(str,str): Multiple occurrences", "[group6]") {
    MyString s("abcabc");
    REQUIRE(s.replace(string("abc"), string("XY")).getData() == "XYXY");
}

TEST_CASE("replace(str,str): Pattern not found", "[group6]") {
    MyString s("Hello");
    REQUIRE(s.replace(string("xyz"), string("abc")).getData() == "Hello");
}

TEST_CASE("replace(str,str): Replace with empty string", "[group6]") {
    MyString s("Hello World");
    REQUIRE(s.replace(string(" World"), string("")).getData() == "Hello");
}

// ============================================================
// GROUP 7: Operator Overloading (25 points)
// ============================================================

TEST_CASE("operator+: Normal concatenation", "[group7]") {
    MyString a("Hello");
    MyString b(" World");
    REQUIRE((a + b).getData() == "Hello World");
}

TEST_CASE("operator+: Concatenate with empty", "[group7]") {
    MyString a("Hello");
    MyString b("");
    REQUIRE((a + b).getData() == "Hello");
}

TEST_CASE("operator+: Both empty", "[group7]") {
    MyString a("");
    MyString b("");
    REQUIRE((a + b).getData() == "");
}

TEST_CASE("operator==: Equal strings", "[group7]") {
    MyString a("Hello");
    MyString b("Hello");
    REQUIRE(a == b);
}

TEST_CASE("operator==: Different strings", "[group7]") {
    MyString a("Hello");
    MyString b("World");
    REQUIRE_FALSE(a == b);
}

TEST_CASE("operator==: Case sensitive", "[group7]") {
    MyString a("Hello");
    MyString b("hello");
    REQUIRE_FALSE(a == b);
}

TEST_CASE("operator!=: Different strings", "[group7]") {
    MyString a("Hello");
    MyString b("World");
    REQUIRE(a != b);
}

TEST_CASE("operator!=: Equal strings", "[group7]") {
    MyString a("Hello");
    MyString b("Hello");
    REQUIRE_FALSE(a != b);
}

TEST_CASE("operator<: Lexicographic less", "[group7]") {
    MyString a("Apple");
    MyString b("Banana");
    REQUIRE(a < b);
}

TEST_CASE("operator<: Not less when equal", "[group7]") {
    MyString a("Hello");
    MyString b("Hello");
    REQUIRE_FALSE(a < b);
}

TEST_CASE("operator<: Not less when greater", "[group7]") {
    MyString a("Banana");
    MyString b("Apple");
    REQUIRE_FALSE(a < b);
}

TEST_CASE("operator>: Lexicographic greater", "[group7]") {
    MyString a("Banana");
    MyString b("Apple");
    REQUIRE(a > b);
}

TEST_CASE("operator>: Not greater when equal", "[group7]") {
    MyString a("Hello");
    MyString b("Hello");
    REQUIRE_FALSE(a > b);
}

TEST_CASE("operator_index: Valid index first char", "[group7]") {
    MyString s("Hello");
    REQUIRE(s[0] == 'H');
}

TEST_CASE("operator_index: Valid index last char", "[group7]") {
    MyString s("Hello");
    REQUIRE(s[4] == 'o');
}

TEST_CASE("operator_index: Negative index throws", "[group7]") {
    MyString s("Hello");
    REQUIRE_THROWS_AS(s[-1], out_of_range);
}

TEST_CASE("operator_index: Index out of bounds throws", "[group7]") {
    MyString s("Hello");
    REQUIRE_THROWS_AS(s[5], out_of_range);
}

TEST_CASE("operator*: Repeat 3 times", "[group7]") {
    MyString s("Ha");
    REQUIRE((s * 3).getData() == "HaHaHa");
}

TEST_CASE("operator*: Repeat 1 time", "[group7]") {
    MyString s("Hi");
    REQUIRE((s * 1).getData() == "Hi");
}

TEST_CASE("operator*: Repeat 0 times returns empty", "[group7]") {
    MyString s("Hi");
    REQUIRE((s * 0).getData() == "");
}

TEST_CASE("operator*: Negative times returns empty", "[group7]") {
    MyString s("Hi");
    REQUIRE((s * -2).getData() == "");
}

// ============================================================
// GROUP 8: Stream Operators (8 points)
// ============================================================

TEST_CASE("operator<<: Output normal string", "[group8]") {
    MyString s("Hello World");
    ostringstream oss;
    oss << s;
    REQUIRE(oss.str() == "Hello World");
}

TEST_CASE("operator<<: Output empty string", "[group8]") {
    MyString s("");
    ostringstream oss;
    oss << s;
    REQUIRE(oss.str() == "");
}

TEST_CASE("operator<<: Chain output", "[group8]") {
    MyString a("Hello");
    MyString b(" World");
    ostringstream oss;
    oss << a << b;
    REQUIRE(oss.str() == "Hello World");
}

TEST_CASE("operator>>: Read single word", "[group8]") {
    MyString s;
    istringstream iss("Hello");
    iss >> s;
    REQUIRE(s.getData() == "Hello");
}

TEST_CASE("operator>>: Read first word from sentence", "[group8]") {
    MyString s;
    istringstream iss("Hello World");
    iss >> s;
    REQUIRE(s.getData() == "Hello");
}

TEST_CASE("operator>>: Read multiple words sequentially", "[group8]") {
    MyString s1, s2;
    istringstream iss("Hello World");
    iss >> s1 >> s2;
    REQUIRE(s1.getData() == "Hello");
    REQUIRE(s2.getData() == "World");
}
