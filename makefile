CXX = g++
CC = gcc

CXXFLAGS = -lSDL2

all: binary

debug: CXX += -ggdb
debug: CC += -ggdb
debug: binary

binary: main.cpp
	$(CXX) $(CXXFLAGS) -o sdlgame main.cpp input.cpp create.cpp getError.cpp
