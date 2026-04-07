CXX = g++
CXXFLAGS = -Wall --std=c++17
TARGET = program
TEST_TARGET = test_runner

# Default: Build the student program
all: $(TARGET)

$(TARGET): MainProgram.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) MainProgram.cpp

# Build and run tests
test: $(TEST_TARGET)
	./$(TEST_TARGET)

$(TEST_TARGET): test.cpp MainProgram.cpp catch_amalgamated.cpp catch_amalgamated.hpp
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) test.cpp catch_amalgamated.cpp

# Clean build artifacts
clean:
	rm -f $(TARGET) $(TEST_TARGET)

.PHONY: all test clean
