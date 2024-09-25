all: operacoes.o main.o
	gcc operacoes.o main.o -o main -std=c99 -Wall

operacoes.o:
	gcc -c operacoes.c -o operacoes.o	
	
main.o:
	gcc -c main.c -o main.o

run:
	./main
	 
clean:
	rm *.o main