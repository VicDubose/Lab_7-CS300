# Compiler
CXX = g++

# Source files
SRCS = Labyrinth.cpp Main.cpp MazeGenerator.cpp

# Target executable
TARGET = Labyrinth

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Linking the target
$(TARGET): $(OBJS)
	$(CXX) -g -o $@ $^  # Added -g flag here

# Compiling source files
%.o: %.cpp
	$(CXX) -g -c $< -o $@  # Added -g flag here

# Clean up
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean
