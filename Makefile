all:
	g++ -o mleko main.cpp Matrix.cpp Pawn.cpp -lncurses -pthread -std=c++11
