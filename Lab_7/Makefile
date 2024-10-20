# Target executable
TARGET = Labyrinth

# Source files
SRCS = $(wildcard *.cpp)  # Automatically find all .cpp files

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

# Run the target
run: all
	./$(TARGET)

# Clean up
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean run
