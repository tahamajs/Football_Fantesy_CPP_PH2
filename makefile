# Makefilefor C++ program

# Compiler and compiler options
CXX = g++
CXXFLAGS = -Wall -g -std=c++11

# Source files and object files
SRCDIR = src
SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJDIR = build
OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

# Header file directory
INCDIR = hpp

# Executable file name
EXEC = futballFantasy

# Default target
all: $(EXEC)

# Executable target
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC)

# Object file targets
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ -I $(INCDIR)

# Run target
run: $(EXEC)
	./$(EXEC)

# Clean target
clean:
	rm -rf $(OBJDIR) $(EXEC)
	mkdir $(OBJDIR)