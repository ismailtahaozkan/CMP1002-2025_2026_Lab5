// ============================================================
// Test File for MyString Lab
// Uses Catch2 (single-header amalgamated version)
// ============================================================
// Compile: g++ -Wall --std=c++17 -o test test.cpp catch_amalgamated.cpp
// Run:     ./test
// ============================================================

// Handle main() conflict with student's MainProgram.cpp
#define main student_main
#include "MainProgram.cpp"
#undef main

#include "catch_amalgamated.hpp"

// ============================================================
// GROUP 1: Constructors and Getter (9 points)
// ============================================================

TEST_CASE("Constructor: Default constructor creates empty string", "[constructor][1pt]") {
    MyString s;
    REQUIRE(s.getData() == "");
}

TEST_CASE("Constructor: std::string constructor", "[constructor][1pt]") {
    MyString s(string("Hello"));
    REQUIRE(s.getData() == "Hello");
}

TEST_CASE("Constructor: C-string constructor", "[constructor][1pt]") {
    MyString s("World");
    REQUIRE(s.getData() == "World");
}

TEST_CASE("Constructor: Empty string via std::string", "[constructor][1pt]") {
    MyString s(string(""));
    REQUIRE(s.getData() == "");
}

TEST_CASE("Constructor: Empty C-string", "[constructor][1pt]") {
    MyString s("");
    REQUIRE(s.getData() == "");
}

TEST_CASE("Constructor: String with spaces", "[constructor][1pt]") {
    MyString s("Hello World");
    REQUIRE(s.getData() == "Hello World");
}

TEST_CASE("Constructor: String with special characters", "[constructor][1pt]") {
    MyString s("C++ is #1!");
    REQUIRE(s.getData() == "C++ is #1!");
}

TEST_CASE("Getter: getData returns correct value", "[getter][1pt]") {
    MyString s("Test");
    REQUIRE(s.getData() == "Test");
}

TEST_CASE("Getter: getData on empty string", "[getter][1pt]") {
    MyString s;
    REQUIRE(s.getData() == "");
}

// ============================================================
// GROUP 2: Basic String Operations (12 points)
// ============================================================

// --- length ---
TEST_CASE("length: Normal string", "[length][2pt]") {
    MyString s("Hello");
    REQUIRE(s.length() == 5);
}

TEST_CASE("length: Empty string returns 0", "[length][1pt]") {
    MyString s;
    REQUIRE(s.length() == 0);
}

TEST_CASE("length: String with spaces", "[length][1pt]") {
    MyString s("Hi There");
    REQUIRE(s.length() == 8);
}

// --- charAt ---
TEST_CASE("charAt: First character", "[charAt][1pt]") {
    MyString s("Hello");
    REQUIRE(s.charAt(0) == 'H');
}

TEST_CASE("charAt: Last character", "[charAt][1pt]") {
    MyString s("Hello");
    REQUIRE(s.charAt(4) == 'o');
}

TEST_CASE("charAt: Middle character", "[charAt][1pt]") {
    MyString s("Hello");
    REQUIRE(s.charAt(2) == 'l');
}

TEST_CASE("charAt: Negative index throws", "[charAt][1pt]") {
    MyString s("Hello");
    REQUIRE_THROWS_AS(s.charAt(-1), out_of_range);
}

TEST_CASE("charAt: Index equal to length throws", "[charAt][1pt]") {
    MyString s("Hello");
    REQUIRE_THROWS_AS(s.charAt(5), out_of_range);
}

// --- substring ---
TEST_CASE("substring: Normal case from start", "[substring][1pt]") {
    MyString s("Hello World");
    REQUIRE(s.substring(0, 5).getData() == "Hello");
}

TEST_CASE("substring: From middle", "[substring][1pt]") {
    MyString s("Hello World");
    REQUIRE(s.substring(6, 5).getData() == "World");
}

TEST_CASE("substring: Invalid start throws", "[substring][1pt]") {
    MyString s("Hello");
    REQUIRE_THROWS_AS(s.substring(10, 2), out_of_range);
}

// ============================================================
// GROUP 3: String Manipulation (16 points)
// ============================================================

// --- toUpperCase ---
TEST_CASE("toUpperCase: Normal mixed case", "[toUpperCase][2pt]") {
    MyString s("Hello World");
    REQUIRE(s.toUpperCase().getData() == "HELLO WORLD");
}

TEST_CASE("toUpperCase: Already uppercase", "[toUpperCase][1pt]") {
    MyString s("ABC");
    REQUIRE(s.toUpperCase().getData() == "ABC");
}

TEST_CASE("toUpperCase: All lowercase", "[toUpperCase][1pt]") {
    MyString s("xyz");
    REQUIRE(s.toUpperCase().getData() == "XYZ");
}

TEST_CASE("toUpperCase: Empty string", "[toUpperCase][1pt]") {
    MyString s("");
    REQUIRE(s.toUpperCase().getData() == "");
}

// --- toLowerCase ---
TEST_CASE("toLowerCase: Normal mixed case", "[toLowerCase][2pt]") {
    MyString s("Hello World");
    REQUIRE(s.toLowerCase().getData() == "hello world");
}

TEST_CASE("toLowerCase: Already lowercase", "[toLowerCase][1pt]") {
    MyString s("abc");
    REQUIRE(s.toLowerCase().getData() == "abc");
}

TEST_CASE("toLowerCase: Empty string", "[toLowerCase][1pt]") {
    MyString s("");
    REQUIRE(s.toLowerCase().getData() == "");
}

// --- trim ---
TEST_CASE("trim: Leading and trailing spaces", "[trim][2pt]") {
    MyString s("   Hello   ");
    REQUIRE(s.trim().getData() == "Hello");
}

TEST_CASE("trim: Only whitespace returns empty", "[trim][1pt]") {
    MyString s("     ");
    REQUIRE(s.trim().getData() == "");
}

TEST_CASE("trim: Tabs and newlines", "[trim][1pt]") {
    MyString s("\t\n  Hi  \n\t");
    REQUIRE(s.trim().getData() == "Hi");
}

TEST_CASE("trim: No whitespace to trim", "[trim][1pt]") {
    MyString s("Hello");
    REQUIRE(s.trim().getData() == "Hello");
}

// --- reverse ---
TEST_CASE("reverse: Normal string", "[reverse][1pt]") {
    MyString s("Hello");
    REQUIRE(s.reverse().getData() == "olleH");
}

TEST_CASE("reverse: Empty string", "[reverse][1pt]") {
    MyString s("");
    REQUIRE(s.reverse().getData() == "");
}

// ============================================================
// GROUP 4: Search Operations (8 points)
// ============================================================

// --- find ---
TEST_CASE("find: Target found at start", "[find][1pt]") {
    MyString s("Hello World");
    REQUIRE(s.find(MyString("Hello")) == 0);
}

TEST_CASE("find: Target found in middle", "[find][1pt]") {
    MyString s("Hello World");
    REQUIRE(s.find(MyString("World")) == 6);
}

TEST_CASE("find: Target not found returns -1", "[find][1pt]") {
    MyString s("Hello World");
    REQUIRE(s.find(MyString("xyz")) == -1);
}

TEST_CASE("find: Empty target returns 0", "[find][1pt]") {
    MyString s("Hello");
    REQUIRE(s.find(MyString("")) == 0);
}

// --- count ---
TEST_CASE("count: Character appears multiple times", "[count][1pt]") {
    MyString s("Hello World");
    REQUIRE(s.count('l') == 3);
}

TEST_CASE("count: Character appears once", "[count][1pt]") {
    MyString s("Hello");
    REQUIRE(s.count('H') == 1);
}

TEST_CASE("count: Character not present returns 0", "[count][1pt]") {
    MyString s("Hello");
    REQUIRE(s.count('z') == 0);
}

TEST_CASE("count: Empty string returns 0", "[count][1pt]") {
    MyString s("");
    REQUIRE(s.count('a') == 0);
}

// ============================================================
// GROUP 5: Function Overloading - append (12 points)
// ============================================================

// --- append(MyString) ---
TEST_CASE("append(MyString): Normal case", "[append][2pt]") {
    MyString s("Hello");
    MyString other(" World");
    REQUIRE(s.append(other).getData() == "Hello World");
}

TEST_CASE("append(MyString): Append empty string", "[append][1pt]") {
    MyString s("Hello");
    MyString empty("");
    REQUIRE(s.append(empty).getData() == "Hello");
}

// --- append(const char*) ---
TEST_CASE("append(C-str): Normal case", "[append][2pt]") {
    MyString s("Hello");
    REQUIRE(s.append(" C++").getData() == "Hello C++");
}

TEST_CASE("append(C-str): Append empty C-string", "[append][1pt]") {
    MyString s("Hello");
    REQUIRE(s.append("").getData() == "Hello");
}

// --- append(char) ---
TEST_CASE("append(char): Normal character", "[append][2pt]") {
    MyString s("Hello");
    REQUIRE(s.append('!').getData() == "Hello!");
}

TEST_CASE("append(char): Append space", "[append][1pt]") {
    MyString s("Hi");
    REQUIRE(s.append(' ').getData() == "Hi ");
}

// --- append(int) ---
TEST_CASE("append(int): Positive number", "[append][1pt]") {
    MyString s("Value: ");
    REQUIRE(s.append(42).getData() == "Value: 42");
}

TEST_CASE("append(int): Zero", "[append][1pt]") {
    MyString s("Zero: ");
    REQUIRE(s.append(0).getData() == "Zero: 0");
}

TEST_CASE("append(int): Negative number", "[append][1pt]") {
    MyString s("Neg: ");
    REQUIRE(s.append(-5).getData() == "Neg: -5");
}

// ============================================================
// GROUP 6: Function Overloading - replace (10 points)
// ============================================================

// --- replace(char, char) ---
TEST_CASE("replace(char,char): Replace existing char", "[replace][2pt]") {
    MyString s("Hello");
    REQUIRE(s.replace('l', 'r').getData() == "Herro");
}

TEST_CASE("replace(char,char): Char not found - no change", "[replace][1pt]") {
    MyString s("Hello");
    REQUIRE(s.replace('z', 'x').getData() == "Hello");
}

TEST_CASE("replace(char,char): Multiple occurrences", "[replace][1pt]") {
    MyString s("aabaa");
    REQUIRE(s.replace('a', 'x').getData() == "xxbxx");
}

TEST_CASE("replace(char,char): Empty string", "[replace][1pt]") {
    MyString s("");
    REQUIRE(s.replace('a', 'b').getData() == "");
}

// --- replace(string, string) ---
TEST_CASE("replace(str,str): Normal replacement", "[replace][2pt]") {
    MyString s("Hello World");
    REQUIRE(s.replace(string("World"), string("C++")).getData() == "Hello C++");
}

TEST_CASE("replace(str,str): Multiple occurrences", "[replace][1pt]") {
    MyString s("abcabc");
    REQUIRE(s.replace(string("abc"), string("XY")).getData() == "XYXY");
}

TEST_CASE("replace(str,str): Pattern not found", "[replace][1pt]") {
    MyString s("Hello");
    REQUIRE(s.replace(string("xyz"), string("abc")).getData() == "Hello");
}

TEST_CASE("replace(str,str): Replace with empty string", "[replace][1pt]") {
    MyString s("Hello World");
    REQUIRE(s.replace(string(" World"), string("")).getData() == "Hello");
}

// ============================================================
// GROUP 7: Operator Overloading (25 points)
// ============================================================

// --- operator+ ---
TEST_CASE("operator+: Normal concatenation", "[op+][2pt]") {
    MyString a("Hello");
    MyString b(" World");
    REQUIRE((a + b).getData() == "Hello World");
}

TEST_CASE("operator+: Concatenate with empty", "[op+][1pt]") {
    MyString a("Hello");
    MyString b("");
    REQUIRE((a + b).getData() == "Hello");
}

TEST_CASE("operator+: Both empty", "[op+][1pt]") {
    MyString a("");
    MyString b("");
    REQUIRE((a + b).getData() == "");
}

// --- operator== ---
TEST_CASE("operator==: Equal strings", "[op==][2pt]") {
    MyString a("Hello");
    MyString b("Hello");
    REQUIRE(a == b);
}

TEST_CASE("operator==: Different strings", "[op==][1pt]") {
    MyString a("Hello");
    MyString b("World");
    REQUIRE_FALSE(a == b);
}

TEST_CASE("operator==: Case sensitive", "[op==][1pt]") {
    MyString a("Hello");
    MyString b("hello");
    REQUIRE_FALSE(a == b);
}

// --- operator!= ---
TEST_CASE("operator!=: Different strings", "[op!=][1pt]") {
    MyString a("Hello");
    MyString b("World");
    REQUIRE(a != b);
}

TEST_CASE("operator!=: Equal strings", "[op!=][1pt]") {
    MyString a("Hello");
    MyString b("Hello");
    REQUIRE_FALSE(a != b);
}

// --- operator< ---
TEST_CASE("operator<: Lexicographic less", "[op<][2pt]") {
    MyString a("Apple");
    MyString b("Banana");
    REQUIRE(a < b);
}

TEST_CASE("operator<: Not less when equal", "[op<][1pt]") {
    MyString a("Hello");
    MyString b("Hello");
    REQUIRE_FALSE(a < b);
}

TEST_CASE("operator<: Not less when greater", "[op<][1pt]") {
    MyString a("Banana");
    MyString b("Apple");
    REQUIRE_FALSE(a < b);
}

// --- operator> ---
TEST_CASE("operator>: Lexicographic greater", "[op>][2pt]") {
    MyString a("Banana");
    MyString b("Apple");
    REQUIRE(a > b);
}

TEST_CASE("operator>: Not greater when equal", "[op>][1pt]") {
    MyString a("Hello");
    MyString b("Hello");
    REQUIRE_FALSE(a > b);
}

// --- operator[] ---
TEST_CASE("operator[]: Valid index first char", "[op_index][1pt]") {
    MyString s("Hello");
    REQUIRE(s[0] == 'H');
}

TEST_CASE("operator[]: Valid index last char", "[op_index][1pt]") {
    MyString s("Hello");
    REQUIRE(s[4] == 'o');
}

TEST_CASE("operator[]: Negative index throws", "[op_index][1pt]") {
    MyString s("Hello");
    REQUIRE_THROWS_AS(s[-1], out_of_range);
}

TEST_CASE("operator[]: Index out of bounds throws", "[op_index][1pt]") {
    MyString s("Hello");
    REQUIRE_THROWS_AS(s[5], out_of_range);
}

// --- operator* ---
TEST_CASE("operator*: Repeat 3 times", "[op*][2pt]") {
    MyString s("Ha");
    REQUIRE((s * 3).getData() == "HaHaHa");
}

TEST_CASE("operator*: Repeat 1 time", "[op*][1pt]") {
    MyString s("Hi");
    REQUIRE((s * 1).getData() == "Hi");
}

TEST_CASE("operator*: Repeat 0 times returns empty", "[op*][1pt]") {
    MyString s("Hi");
    REQUIRE((s * 0).getData() == "");
}

TEST_CASE("operator*: Negative times returns empty", "[op*][1pt]") {
    MyString s("Hi");
    REQUIRE((s * -2).getData() == "");
}

// ============================================================
// GROUP 8: Stream Operators (8 points)
// ============================================================

TEST_CASE("operator<<: Output normal string", "[stream][2pt]") {
    MyString s("Hello World");
    ostringstream oss;
    oss << s;
    REQUIRE(oss.str() == "Hello World");
}

TEST_CASE("operator<<: Output empty string", "[stream][1pt]") {
    MyString s("");
    ostringstream oss;
    oss << s;
    REQUIRE(oss.str() == "");
}

TEST_CASE("operator<<: Chain output", "[stream][1pt]") {
    MyString a("Hello");
    MyString b(" World");
    ostringstream oss;
    oss << a << b;
    REQUIRE(oss.str() == "Hello World");
}

TEST_CASE("operator>>: Read single word", "[stream][2pt]") {
    MyString s;
    istringstream iss("Hello");
    iss >> s;
    REQUIRE(s.getData() == "Hello");
}

TEST_CASE("operator>>: Read first word from sentence", "[stream][1pt]") {
    MyString s;
    istringstream iss("Hello World");
    iss >> s;
    REQUIRE(s.getData() == "Hello");
}

TEST_CASE("operator>>: Read multiple words sequentially", "[stream][1pt]") {
    MyString s1, s2;
    istringstream iss("Hello World");
    iss >> s1 >> s2;
    REQUIRE(s1.getData() == "Hello");
    REQUIRE(s2.getData() == "World");
}
