# Lab: Strings and String Operations with Function & Operator Overloading

## Topic
C++ String Operations, Function Overloading, and Operator Overloading

## Course
Object-Oriented Programming for Engineers — 2nd Year

## Duration
70 minutes

---

## Learning Objectives

By the end of this lab, students will be able to:

1. Design and implement a custom string class wrapping `std::string`
2. Implement common string operations (search, manipulate, transform)
3. Apply **function overloading** by writing multiple versions of `append()` and `replace()` with different parameter types
4. Apply **operator overloading** to enable natural syntax for concatenation (`+`), comparison (`==`, `!=`, `<`, `>`), indexing (`[]`), repetition (`*`), and streaming (`<<`, `>>`)
5. Handle edge cases (empty strings, out-of-range indices) with proper exceptions

---

## Prerequisites

- Basic C++ syntax (variables, loops, conditionals)
- Understanding of classes, constructors, and member functions
- Familiarity with `std::string` basics
- Basic understanding of function signatures and parameter types

---

## File Structure

```
lab/
├── MainProgram.cpp          ← Your work goes here (single file)
├── test.cpp                 ← Catch2 test file (do not modify)
├── catch_amalgamated.hpp    ← Catch2 header (do not modify)
├── catch_amalgamated.cpp    ← Catch2 source (do not modify)
├── Makefile                 ← Build system
├── README.md                ← This file
├── explain.txt              ← Quick revision sheet
└── explain.md               ← Detailed concept guide
```

---

## Instructions

### Step 1: Read the Concept Guides
Read `explain.txt` for a quick overview (2–3 minutes), then optionally `explain.md` for more depth.

### Step 2: Open `MainProgram.cpp`
Look for `// TODO` comments. Each marks a function you need to implement.

### Step 3: Implement Functions
Work through the TODOs in order:
1. Constructors and getter
2. Basic operations: `length()`, `charAt()`, `substring()`
3. Manipulation: `toUpperCase()`, `toLowerCase()`, `trim()`, `reverse()`
4. Search: `find()`, `count()`
5. Function overloading: `append()` (4 versions), `replace()` (2 versions)
6. Operator overloading: `+`, `==`, `!=`, `<`, `>`, `[]`, `*`
7. Stream operators: `<<`, `>>`

### Step 4: Compile and Run Your Program

```bash
make
./program
```

### Step 5: Run the Tests

```bash
make test
```

All tests should pass if your implementation is correct.

### Step 6: Clean Up

```bash
make clean
```

---

## Submission Instructions

1. Submit **only** `MainProgram.cpp`
2. Ensure your code compiles without errors using `make`
3. Ensure all tests pass using `make test`
4. Do **not** modify `test.cpp`, `catch_amalgamated.hpp`, or `catch_amalgamated.cpp`

---

## Grading

| Category                     | Points |
|------------------------------|--------|
| Constructors & Getter        | 9      |
| Basic Operations             | 12     |
| String Manipulation          | 16     |
| Search Operations            | 8      |
| Function Overloading: append | 12     |
| Function Overloading: replace| 10     |
| Operator Overloading         | 25     |
| Stream Operators             | 8      |
| **Total**                    | **100**|

---

## Common Mistakes

1. **Forgetting `static_cast<int>`** when comparing `int` with `string::length()` (which returns `size_t`)
2. **Not throwing `out_of_range`** in `charAt()`, `substring()`, and `operator[]` for invalid indices
3. **Modifying the original object** instead of returning a new `MyString` — all manipulation functions should be `const`
4. **Using `==` to compare C-strings** instead of `std::string` comparison
5. **Forgetting to handle negative or zero** in `operator*`
6. **Not handling empty strings** as edge cases
7. **Infinite loop in `replace(string, string)`** when `newStr` contains `oldStr` — advance position past replacement

---

## Academic Integrity

This is an individual assignment. You may consult the course textbook, lecture notes, and C++ documentation. You must write your own code. Sharing or copying code is a violation of academic integrity policy.
