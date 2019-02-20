CFLAGS = -Wall -Wextra -DDEBUG -g -std=c++14
l = lab3
s = Star
p = Planet
compile: lab3.cpp Star.h Planet.cpp Planet.h
	

all: lab3.cpp Star.h Planet.cpp Planet.h
	g++ $(CFLAGS) -c Lab3.cpp -c Star.cpp -c Planet.cpp 
	g++ lab3.o Planet.o Star.o -o lab3
clean:
	rm -rf *.o 
	rm -rf $(l)
run: all 
	./$(l)

