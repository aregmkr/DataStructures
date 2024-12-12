# Variables
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Source and header files
SRC = main.cpp
HEADERS = forwardlist.h forwardlist.hpp
OBJ = $(SRC:.cpp=.o)
TARGET = a.out

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

# Compile the source files into object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(OBJ) $(TARGET)
