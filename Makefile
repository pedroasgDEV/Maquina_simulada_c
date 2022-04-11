all:
	gcc -c user.c -Wall
	gcc -c operations.c -Wall
	gcc -c core.c -Wall
	gcc -c main.c -Wall
	gcc *.o -o exec -Wall
	./exec
clear:
	rm *.o exec
	clear