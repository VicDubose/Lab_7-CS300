# Compiler
CXX = g++
TARGET = Event_Planner

BASE_SRC = Base.cpp
USER_SRC = user.cpp
BASE_OBJ = $(BASE_SRC:.cpp=.o)
USER_OBJ = $(USER_SRC:.cpp=.o)
HEADER = Base.h user.h

# All target
all: $(TARGET)

# Linking the executable
$(TARGET): $(BASE_OBJ) $(USER_OBJ)
	$(CXX) $(BASE_OBJ) $(USER_OBJ) -o $@

# Compile object files
$(BASE_OBJ): $(BASE_SRC) $(HEADER)
	$(CXX) -c $(BASE_SRC)

$(USER_OBJ): $(USER_SRC) $(HEADER)
	$(CXX) -c $(USER_SRC)

run: $(TARGET)
	./$(TARGET)

# Clean target
clean:
	rm -f $(BASE_OBJ) $(USER_OBJ) $(TARGET)
