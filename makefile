# # Makefile for C++ program

# # Compiler and compiler options
# CXX = g++
# CXXFLAGS = -Wall -g -std=c++11

# # Source files and object files
# SRCDIR = src
# SRCS = $(wildcard $(SRCDIR)/*.cpp)
# OBJDIR = build
# OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)


CXX = g++ -std=c++11
CC_FLAGS = -g
CC = ${CXX} ${CC_FLAGS} 
BUILD_DIR = build
HEADERS_DIR=include
SOURCE_DIR = src

all: futballFantasy.out

futballFantasy.out : $(BUILD_DIR)/Admin.o $(BUILD_DIR)/Exeptions.o $(BUILD_DIR)/FantasyTeam.o $(BUILD_DIR)/InputHandler.o $(BUILD_DIR)/main.o $(BUILD_DIR)/MainTeam.o $(BUILD_DIR)/Match.o $(BUILD_DIR)/Player.o $(BUILD_DIR)/System.o $(BUILD_DIR)/User.o $(BUILD_DIR)/Week.o $(BUILD_DIR)/DefenderPlayer.o $(BUILD_DIR)/ForwardPlayer.o $(BUILD_DIR)/GoalkeeperPlayer.o $(BUILD_DIR)/MidfielderPlayer.o
	$(CC) -o futballFantasy.out $(BUILD_DIR)/Admin.o $(BUILD_DIR)/Exeptions.o $(BUILD_DIR)/FantasyTeam.o $(BUILD_DIR)/InputHandler.o $(BUILD_DIR)/main.o $(BUILD_DIR)/MainTeam.o $(BUILD_DIR)/Match.o $(BUILD_DIR)/Player.o $(BUILD_DIR)/System.o $(BUILD_DIR)/User.o $(BUILD_DIR)/Week.o $(BUILD_DIR)/DefenderPlayer.o $(BUILD_DIR)/ForwardPlayer.o $(BUILD_DIR)/GoalkeeperPlayer.o $(BUILD_DIR)/MidfielderPlayer.o

$(BUILD_DIR)/Admin.o : $(SOURCE_DIR)/Admin.cpp $(HEADERS_DIR)/Consts.hpp
	$(CC) -c $(SOURCE_DIR)/Admin.cpp -o $(BUILD_DIR)/Admin.o

$(BUILD_DIR)/Exeptions.o : $(SOURCE_DIR)/Exeptions.cpp 
	$(CC) -c $(SOURCE_DIR)/Exeptions.cpp -o $(BUILD_DIR)/Exeptions.o

$(BUILD_DIR)/FantasyTeam.o : $(SOURCE_DIR)/FantasyTeam.cpp $(HEADERS_DIR)/Consts.hpp $(HEADERS_DIR)/Player.hpp $(HEADERS_DIR)/Exeptions.hpp
	$(CC) -c $(SOURCE_DIR)/FantasyTeam.cpp -o $(BUILD_DIR)/FantasyTeam.o

$(BUILD_DIR)/InputHandler.o : $(SOURCE_DIR)/InputHandler.cpp $(HEADERS_DIR)/Consts.hpp $(HEADERS_DIR)/System.hpp 
	$(CC) -c $(SOURCE_DIR)/InputHandler.cpp -o $(BUILD_DIR)/InputHandler.o

$(BUILD_DIR)/main.o : $(SOURCE_DIR)/main.cpp $(HEADERS_DIR)/System.hpp $(HEADERS_DIR)/InputHandler.hpp 
	$(CC) -c $(SOURCE_DIR)/main.cpp -o $(BUILD_DIR)/main.o	

$(BUILD_DIR)/MainTeam.o : $(SOURCE_DIR)/MainTeam.cpp $(HEADERS_DIR)/Player.hpp 
	$(CC) -c $(SOURCE_DIR)/MainTeam.cpp -o $(BUILD_DIR)/MainTeam.o

$(BUILD_DIR)/Match.o : $(SOURCE_DIR)/Match.cpp $(HEADERS_DIR)/Consts.hpp $(HEADERS_DIR)/MainTeam.hpp
	$(CC) -c $(SOURCE_DIR)/Match.cpp -o $(BUILD_DIR)/Match.o

$(BUILD_DIR)/Player.o : $(SOURCE_DIR)/Player.cpp $(HEADERS_DIR)/Consts.hpp 
	$(CC) -c $(SOURCE_DIR)/Player.cpp -o $(BUILD_DIR)/Player.o

$(BUILD_DIR)/System.o : $(SOURCE_DIR)/System.cpp $(HEADERS_DIR)/Consts.hpp $(HEADERS_DIR)/User.hpp $(HEADERS_DIR)/Admin.hpp $(HEADERS_DIR)/InputHandler.hpp $(HEADERS_DIR)/FantasyTeam.hpp $(HEADERS_DIR)/Match.hpp $(HEADERS_DIR)/Week.hpp
	$(CC) -c $(SOURCE_DIR)/System.cpp -o $(BUILD_DIR)/System.o

$(BUILD_DIR)/User.o : $(SOURCE_DIR)/User.cpp $(HEADERS_DIR)/FantasyTeam.hpp
	$(CC) -c $(SOURCE_DIR)/User.cpp -o $(BUILD_DIR)/User.o

$(BUILD_DIR)/Week.o : $(SOURCE_DIR)/Week.cpp $(HEADERS_DIR)/Consts.hpp $(HEADERS_DIR)/Match.hpp $(HEADERS_DIR)/MainTeam.hpp $(HEADERS_DIR)/Player.hpp $(HEADERS_DIR)/Admin.hpp
	$(CC) -c $(SOURCE_DIR)/Week.cpp -o $(BUILD_DIR)/Week.o	

$(BUILD_DIR)/DefenderPlayer.o : $(SOURCE_DIR)/DefenderPlayer.cpp $(HEADERS_DIR)/DefenderPlayer.hpp $(HEADERS_DIR)/Player.hpp
	$(CC) -c $(SOURCE_DIR)/DefenderPlayer.cpp -o $(BUILD_DIR)/DefenderPlayer.o

$(BUILD_DIR)/ForwardPlayer.o : $(SOURCE_DIR)/ForwardPlayer.cpp $(HEADERS_DIR)/ForwardPlayer.hpp $(HEADERS_DIR)/Player.hpp
	$(CC) -c $(SOURCE_DIR)/ForwardPlayer.cpp -o $(BUILD_DIR)/ForwardPlayer.o

$(BUILD_DIR)/GoalkeeperPlayer.o : $(SOURCE_DIR)/GoalkeeperPlayer.cpp $(HEADERS_DIR)/GoalkeeperPlayer.hpp $(HEADERS_DIR)/Player.hpp	
	$(CC) -c $(SOURCE_DIR)/GoalkeeperPlayer.cpp -o $(BUILD_DIR)/GoalkeeperPlayer.o

$(BUILD_DIR)/MidfielderPlayer.o : $(SOURCE_DIR)/MidfielderPlayer.cpp $(HEADERS_DIR)/MidfielderPlayer.hpp $(HEADERS_DIR)/Player.hpp
	$(CC) -c $(SOURCE_DIR)/MidfielderPlayer.cpp -o $(BUILD_DIR)/MidfielderPlayer.o


clean:
	rm -rf build/ 
	mkdir $(BUILD_DIR)

run: futballFantasy.out
	./futballFantasy.out