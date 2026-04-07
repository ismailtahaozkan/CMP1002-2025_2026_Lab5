# Grading Rubric — MyString Lab (100 Points Total)

## Group 1: Constructors & Getter (9 points)

| Test | Points |
|------|--------|
| Default constructor creates empty string | 1 |
| std::string constructor | 1 |
| C-string constructor | 1 |
| Empty string via std::string | 1 |
| Empty C-string | 1 |
| String with spaces | 1 |
| String with special characters | 1 |
| getData returns correct value | 1 |
| getData on empty string | 1 |

## Group 2: Basic String Operations (12 points)

| Test | Points |
|------|--------|
| length: Normal string | 2 |
| length: Empty string returns 0 | 1 |
| length: String with spaces | 1 |
| charAt: First character | 1 |
| charAt: Last character | 1 |
| charAt: Middle character | 1 |
| charAt: Negative index throws | 1 |
| charAt: Index equal to length throws | 1 |
| substring: Normal case from start | 1 |
| substring: From middle | 1 |
| substring: Invalid start throws | 1 |

## Group 3: String Manipulation (16 points)

| Test | Points |
|------|--------|
| toUpperCase: Normal mixed case | 2 |
| toUpperCase: Already uppercase | 1 |
| toUpperCase: All lowercase | 1 |
| toUpperCase: Empty string | 1 |
| toLowerCase: Normal mixed case | 2 |
| toLowerCase: Already lowercase | 1 |
| toLowerCase: Empty string | 1 |
| trim: Leading and trailing spaces | 2 |
| trim: Only whitespace returns empty | 1 |
| trim: Tabs and newlines | 1 |
| trim: No whitespace to trim | 1 |
| reverse: Normal string | 1 |
| reverse: Empty string | 1 |

## Group 4: Search Operations (8 points)

| Test | Points |
|------|--------|
| find: Target found at start | 1 |
| find: Target found in middle | 1 |
| find: Target not found returns -1 | 1 |
| find: Empty target returns 0 | 1 |
| count: Character appears multiple times | 1 |
| count: Character appears once | 1 |
| count: Character not present returns 0 | 1 |
| count: Empty string returns 0 | 1 |

## Group 5: Function Overloading — append (12 points)

| Test | Points |
|------|--------|
| append(MyString): Normal case | 2 |
| append(MyString): Append empty string | 1 |
| append(C-str): Normal case | 2 |
| append(C-str): Append empty C-string | 1 |
| append(char): Normal character | 2 |
| append(char): Append space | 1 |
| append(int): Positive number | 1 |
| append(int): Zero | 1 |
| append(int): Negative number | 1 |

## Group 6: Function Overloading — replace (10 points)

| Test | Points |
|------|--------|
| replace(char,char): Replace existing char | 2 |
| replace(char,char): Char not found — no change | 1 |
| replace(char,char): Multiple occurrences | 1 |
| replace(char,char): Empty string | 1 |
| replace(str,str): Normal replacement | 2 |
| replace(str,str): Multiple occurrences | 1 |
| replace(str,str): Pattern not found | 1 |
| replace(str,str): Replace with empty string | 1 |

## Group 7: Operator Overloading (25 points)

| Test | Points |
|------|--------|
| operator+: Normal concatenation | 2 |
| operator+: Concatenate with empty | 1 |
| operator+: Both empty | 1 |
| operator==: Equal strings | 2 |
| operator==: Different strings | 1 |
| operator==: Case sensitive | 1 |
| operator!=: Different strings | 1 |
| operator!=: Equal strings | 1 |
| operator<: Lexicographic less | 2 |
| operator<: Not less when equal | 1 |
| operator<: Not less when greater | 1 |
| operator>: Lexicographic greater | 2 |
| operator>: Not greater when equal | 1 |
| operator[]: Valid index first char | 1 |
| operator[]: Valid index last char | 1 |
| operator[]: Negative index throws | 1 |
| operator[]: Index out of bounds throws | 1 |
| operator*: Repeat 3 times | 2 |
| operator*: Repeat 1 time | 1 |
| operator*: Repeat 0 times returns empty | 1 |
| operator*: Negative times returns empty | 1 |

## Group 8: Stream Operators (8 points)

| Test | Points |
|------|--------|
| operator<<: Output normal string | 2 |
| operator<<: Output empty string | 1 |
| operator<<: Chain output | 1 |
| operator>>: Read single word | 2 |
| operator>>: Read first word from sentence | 1 |
| operator>>: Read multiple words sequentially | 1 |

---

**Grand Total: 100 points**
