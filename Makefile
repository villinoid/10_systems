all: main.o material.o
	gcc -o main main.o material.o
	
main.o: main.c material.h
	gcc -c main.c
	
material.o: material.h
	gcc -c material.c

run: 
	./main
	
clean:
	rm *.o