CFLAGS = -Wall -Wextra -DDEBUG -g -std=c++14
l = lab3
s = Star
p = Planet
$(l):
	g++ $(CFLAGS) -c $(l).cpp
$(s): 
	g++ $(CFLAGS) -c $(s).cpp
$(p):
	g++ $(CFLAGS) -c $(p).cpp
all: $(p) $(s) $(l)
	g++ $(p).o $(s).o $(l).o -o $(l)

clean:
	rm -rf *.o 
	rm -rf $(l)
run: all 
	./$(l)
