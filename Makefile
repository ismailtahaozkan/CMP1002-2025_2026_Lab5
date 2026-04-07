CXX = g++
CXXFLAGS = -Wall --std=c++17
TARGET = program
TEST_TARGET = test_runner

# Default: Build the student program
all: $(TARGET)

$(TARGET): MainProgram.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) MainProgram.cpp

# Build the test runner (once)
$(TEST_TARGET): test.cpp MainProgram.cpp catch_amalgamated.cpp catch_amalgamated.hpp
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) test.cpp catch_amalgamated.cpp

# ============================================================
# Run ALL tests
# ============================================================
test: $(TEST_TARGET)
	@echo ""
	@echo "========================================="
	@echo "  RUNNING ALL TESTS"
	@echo "========================================="
	./$(TEST_TARGET)

# ============================================================
# Run individual groups (by Catch2 tag)
# ============================================================

test_group1: $(TEST_TARGET)
	@echo ""
	@echo "===== GROUP 1: Constructors & Getter (9 pts) ====="
	./$(TEST_TARGET) [group1]

test_group2: $(TEST_TARGET)
	@echo ""
	@echo "===== GROUP 2: Basic String Operations (12 pts) ====="
	./$(TEST_TARGET) [group2]

test_group3: $(TEST_TARGET)
	@echo ""
	@echo "===== GROUP 3: String Manipulation (16 pts) ====="
	./$(TEST_TARGET) [group3]

test_group4: $(TEST_TARGET)
	@echo ""
	@echo "===== GROUP 4: Search Operations (8 pts) ====="
	./$(TEST_TARGET) [group4]

test_group5: $(TEST_TARGET)
	@echo ""
	@echo "===== GROUP 5: Function Overloading - append (12 pts) ====="
	./$(TEST_TARGET) [group5]

test_group6: $(TEST_TARGET)
	@echo ""
	@echo "===== GROUP 6: Function Overloading - replace (10 pts) ====="
	./$(TEST_TARGET) [group6]

test_group7: $(TEST_TARGET)
	@echo ""
	@echo "===== GROUP 7: Operator Overloading (25 pts) ====="
	./$(TEST_TARGET) [group7]

test_group8: $(TEST_TARGET)
	@echo ""
	@echo "===== GROUP 8: Stream Operators (8 pts) ====="
	./$(TEST_TARGET) [group8]

# ============================================================
# Clean
# ============================================================
clean:
	rm -f $(TARGET) $(TEST_TARGET)

.PHONY: all test clean test_group1 test_group2 test_group3 test_group4 test_group5 test_group6 test_group7 test_group8
