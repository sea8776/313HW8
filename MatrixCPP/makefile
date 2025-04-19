CXX = g++
CXXFLAGS = -Wall -std=c++17

# Target executable
driver: matrix.o driver.o
	$(CXX) $(CXXFLAGS) matrix.o driver.o -o driver

# Object file for matrix.cpp
matrix.o: matrix.cpp matrix.h
	$(CXX) $(CXXFLAGS) -c matrix.cpp

# Object file for driver.cpp
driver.o: driver.cpp matrix.h
	$(CXX) $(CXXFLAGS) -c driver.cpp

# Clean command to remove object files and the executable
clean:
	rm -f *.o driver

# Run the test driver
run:
	./driver
