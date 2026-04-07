# Strings, Function Overloading & Operator Overloading in C++

## 1. Concept Overview

In this lab you build a **MyString** class that wraps `std::string` and exposes custom operations. The two central C++ mechanisms you will practice are:

- **Function Overloading** — defining multiple functions with the *same name* but *different parameter lists*. The compiler automatically selects the correct version based on the arguments you pass.
- **Operator Overloading** — giving custom meaning to built-in operators (`+`, `==`, `[]`, `<<`, etc.) so they work naturally with your own class, just like they already work with `int` or `std::string`.

Together, these features allow you to write expressive, readable code:
```cpp
MyString greeting = MyString("Hello") + MyString(" World");
cout << greeting[0];  // 'H'
```

---

## 2. Key Concepts

- **Function overloading** is resolved at **compile time** based on the number and types of arguments.
- The **return type alone** cannot distinguish overloaded functions.
- **Operator overloading** uses the keyword `operator` followed by the symbol (e.g., `operator+`, `operator==`).
- Binary operators like `+` can be **member functions** (left operand is `this`) or **free/friend functions**.
- Stream operators `<<` and `>>` are typically implemented as **friend functions** because the left operand is `ostream`/`istream`, not your class.
- **`const` correctness** is important: operations that do not modify the object should be marked `const`.
- Throw `std::out_of_range` for invalid index access to follow the standard library convention.

---

## 3. Important Keywords

| Keyword / Term         | Explanation |
|------------------------|-------------|
| **Function Overloading** | Multiple functions sharing the same name but differing in parameter types or count |
| **Operator Overloading** | Defining custom behavior for C++ operators on user-defined types |
| **`const` member function** | A member function that promises not to modify the object's state |
| **`friend` function** | A non-member function granted access to a class's private members |
| **`std::out_of_range`** | Standard exception for index-out-of-bounds errors |
| **Lexicographic comparison** | Comparing strings character by character using ASCII values (how `<` and `>` work on strings) |
| **`std::to_string()`** | Converts a number to its string representation |
| **`std::transform()`** | Applies a function to each element in a range (useful for case conversion) |

---

## 4. Common Mistakes

1. **Confusing overload resolution with return type**
   ```cpp
   // WRONG: These two are NOT valid overloads
   int    compute(int x);
   double compute(int x);  // Error: same parameter list
   ```

2. **Forgetting `const` on non-modifying methods**
   ```cpp
   // WRONG: Can't call length() on a const MyString reference
   int length() { return data.length(); }

   // CORRECT:
   int length() const { return data.length(); }
   ```

3. **Not returning a reference from `operator<<`**
   ```cpp
   // WRONG: Breaks chaining (cout << a << b)
   void operator<<(ostream& os, const MyString& s);

   // CORRECT:
   ostream& operator<<(ostream& os, const MyString& s);
   ```

4. **Modifying `this` instead of returning a new object**
   ```cpp
   // WRONG: toUpperCase should not change the original
   MyString toUpperCase() const {
       // Don't do: transform(data.begin(), ...)  ← data is const!
       string result = data;
       transform(result.begin(), result.end(), result.begin(), ::toupper);
       return MyString(result);
   }
   ```

5. **Infinite loop in string replace**
   ```cpp
   // If you replace "a" with "ab", you must advance past the replacement
   pos += newStr.length();  // Skip past what we just inserted
   ```

---

## 5. Mini Examples

### Function Overloading
```cpp
MyString s("Score: ");

s.append(MyString("100"));   // "Score: 100"   — MyString version
s.append("pts");             // "Score: pts"   — C-string version
s.append('!');               // "Score: !"     — char version
s.append(42);                // "Score: 42"    — int version
```

### Operator Overloading
```cpp
MyString a("C++");
MyString b("C++");
MyString c("Java");

a + c;      // "C++Java"          operator+
a == b;     // true                operator==
a != c;     // true                operator!=
c < a;      // false (J > C)       operator<
a[0];       // 'C'                 operator[]
a * 2;      // "C++C++"            operator*
cout << a;  // prints "C++"        operator<<
```

### Stream Input
```cpp
MyString name;
istringstream iss("Alice Bob");
iss >> name;   // name is now "Alice"
```

---

## 6. When to Use This

- **Function overloading**: When you need a single operation that can accept different input types (e.g., a `print` function that works for `int`, `double`, and `string`).
- **Operator overloading**: When your class represents a value type (strings, vectors, complex numbers, matrices) and you want natural mathematical or logical syntax.
- **Custom string class**: In embedded systems, game engines, or performance-critical code where `std::string` may not meet specific requirements.
- **General principle**: Use overloading to make your API intuitive — callers should not need to remember `appendString()`, `appendChar()`, `appendInt()` separately.
