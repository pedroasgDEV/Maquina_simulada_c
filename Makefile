all:
	gcc -c main.c -Wall
	gcc *.o -o exec -Wall
	./exec