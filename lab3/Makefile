CFLAGS = -Wall -Wextra -DDEBUG -g -std=c++14
l = lab3
s = Star
p = Planet
<<<<<<< HEAD
compile: lab3.cpp Star.h Planet.cpp Planet.h
	
=======

$(l): 
	g++ $(CFLAGS) -c $(l).cpp -o $(l).o
$(s): 
	g++ $(CFLAGS) -c $(s).cpp -o $(s).o
$(p):
	g++ $(CFLAGS) -c $(p).cpp -o $(p).o

all: $(l) $(p) $(s) 
	g++ $(CFLAGS) $(p).o $(s).o $(l).o -o $(l)
>>>>>>> 633422859072d3bcc0a291ef306f98e42b2f2adc

all: lab3.cpp Star.h Planet.cpp Planet.h
	g++ $(CFLAGS) -c Lab3.cpp -c Star.cpp -c Planet.cpp 
	g++ lab3.o Planet.o Star.o -o lab3
clean:
	rm -rf *.o 
	rm -rf $(l)
run: all 
	./$(l)

