CFLAGS = -g -Wall -std=c++14

all: Star Planet List Vector program1
	g++ $(CFLAGS) Star.o Planet.o List.o Vector.o program1.o -o program1
Star:
	g++ $(CFLAGS) -c Star.cpp -o Star.o
Planet:
	g++ $(CFLAGS) -c Planet.cpp -o Planet.o
List:
	g++ $(CFLAGS) -c List.cpp -o List.o
Vector:
	g++ $(CFLAGS) -c Vector.cpp -o Vector.o
program1:
	g++ $(CFLAGS) -c program1.cpp -o program1.o
clean:
	rm -rf *.o
	rm -rf program1
