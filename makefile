$(CXX) = g++ -lSDL2
$(CC) = gcc

all: binary

debug: CXX += -ggdb
debug: CC += -ggdb
debug: binary

binary: main.cpp
	$(CXX) -o sdlgame main.cpp input.cpp create.cpp getError.cpp
