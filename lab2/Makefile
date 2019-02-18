CFLAGS = -Wall -Wextra -DDEBUG -g -std=c++14
p = lab2
s = Star
$(p):
	g++ $(CFLAGS) -c $(p).cpp
$(s): 
	g++ $(CFLAGS) -c $(s).cpp

all: $(p) $(s)
	g++ $(s).o $(p).o -o $(p)

clean:
	rm -rf *.o $(p)
run: all 
	./$(p)
