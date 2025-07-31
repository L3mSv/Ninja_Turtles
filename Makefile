CC = gcc
CFLAGS = -Wall -g
LIBS = -lm

all: jogo.o pilha.o heap.o utils.o lista.o character.o weapon.o
	$(CC) $(CFLAGS) -o all jogo.o pilha.o lista.o heap.o utils.o character.o weapon.o $(LIBS)

jogo.o: jogo.c jogo.h bibliotecas/pilha.h utils/utils.h bibliotecas/lista.h character.h
	$(CC) $(CFLAGS) -c jogo.c

pilha.o: fonte/pilha.c bibliotecas/pilha.h
	$(CC) $(CFLAGS) -c fonte/pilha.c

heap.o: fonte/heap.c bibliotecas/heap.h 
	$(CC) $(CFLAGS) -c fonte/heap.c 

lista.o: fonte/lista.c bibliotecas/lista.h 
	$(CC) $(CFLAGS) -c fonte/lista.c 

utils.o: utils/utils.c utils/utils.h
	$(CC) $(CFLAGS) -c utils/utils.c

character.o: character.c character.h bibliotecas/lista.h 
	$(CC) $(CFLAGS) -c character.c 

weapon.o: weapon.c weapon.h bibliotecas/lista.h
	$(CC) $(CFLAGS) -c weapon.c 

clean:
	-del /Q *.o *.exe *~ all
	-rm -rf *.o *.exe *~ all
