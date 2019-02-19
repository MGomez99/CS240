CFLAGS = -Wall -Wextra -DDEBUG -g -std=c++14
l = lab3
s = Star
p = Planet

$(l): 
	g++ $(CFLAGS) -c $(l).cpp -o $(l).o
$(s): 
	g++ $(CFLAGS) -c $(s).cpp -o $(s).o
$(p):
	g++ $(CFLAGS) -c $(p).cpp -o $(p).o

all: $(l) $(p) $(s) 
	g++ $(CFLAGS) $(p).o $(s).o $(l).o -o $(l)

clean:
	rm -rf *.o 
	rm -rf $(l)
run: all 
	./$(l)
