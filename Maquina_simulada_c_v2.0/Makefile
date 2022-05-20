all:
	gcc instru_gener/instru_gener.c -o generator -Wall -lm
	./generator
	gcc *.c -c -Wall
	gcc *.o -o exec -Wall

run:
	make
	./exec

clear:
	rm *.o exec generator instructions.txt
	clear