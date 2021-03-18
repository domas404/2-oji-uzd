main: calculations.o testing.o
	g++ -o main main.cpp calculations.o testing.o
fun:
	g++ -c calculations.cpp testing.cpp