# Makefile for CMSC 313 Hw 8: Matrix Library

CXX       = g++
CXXFLAGS  = -Wall -std=c++17

# Target executable
TARGET    = driver

# Object files
OBJS      = matrix.o driver.o

# Default rule: build the driver
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

# Compile matrix.cpp
matrix.o: matrix.cpp matrix.h
	$(CXX) $(CXXFLAGS) -c matrix.cpp

# Compile driver.cpp
driver.o: driver.cpp matrix.h
	$(CXX) $(CXXFLAGS) -c driver.cpp

# Clean up build artifacts
.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)

# Convenience to run the test driver
.PHONY: run
run: $(TARGET)
	./$(TARGET)
