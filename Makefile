CC = gcc

CFLAGS = -Wall -Wextra -g

OBJ = main.o arbre.o pile.o

prog : $(OBJ)
	$(CC) $(OBJ) -o prog
	
main.o : main.c pile.h arbre.h
	$(CC) -c main.c $(CFLAGS)
	
arbre.o : arbre.c arbre.h
	$(CC) -c arbre.c $(CFLAGS)	

pile.o : pile.c pile.h 
	$(CC) -c pile.c $(CFLAGS)
	

 
