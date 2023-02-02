stb: stb.o
	g++ stb.o -o stb -lm -lncurses -ltinfo

stb.o: stb.cpp
	g++ -Wall -Werror -g stb.cpp -c

clean:
	rm -f *.o stb
