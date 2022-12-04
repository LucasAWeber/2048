2048: main.o
	gcc -Wall -std=c99 main.o -o 2048
main.o: main.c
	gcc -Wall -std=c99 -c main.c
clean:
	rm *.o 2048