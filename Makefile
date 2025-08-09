CC = gcc
CFLAGS = -Wall -g
LIBS = -lm

all: jogo.o pilha.o heap.o utils.o lista.o arvore.o character.o weapon.o villains.o
	$(CC) $(CFLAGS) -o all jogo.o pilha.o lista.o heap.o arvore.o utils.o character.o weapon.o villains.o $(LIBS)

jogo.o: jogo.c jogo.h bibliotecas/pilha.h utils/utils.h bibliotecas/lista.h bibliotecas/arvore.h character.h weapon.h villains.h
	$(CC) $(CFLAGS) -c jogo.c

pilha.o: fonte/pilha.c bibliotecas/pilha.h
	$(CC) $(CFLAGS) -c fonte/pilha.c

heap.o: fonte/heap.c bibliotecas/heap.h 
	$(CC) $(CFLAGS) -c fonte/heap.c 

lista.o: fonte/lista.c bibliotecas/lista.h 
	$(CC) $(CFLAGS) -c fonte/lista.c 

arvore.o: fonte/arvore.c bibliotecas/arvore.h 
	$(CC) $(CFLAGS) -c fonte/arvore.c 

utils.o: utils/utils.c utils/utils.h
	$(CC) $(CFLAGS) -c utils/utils.c

character.o: character.c character.h bibliotecas/lista.h 
	$(CC) $(CFLAGS) -c character.c 

weapon.o: weapon.c weapon.h bibliotecas/lista.h
	$(CC) $(CFLAGS) -c weapon.c 

villains.o: villains.c villains.h bibliotecas/arvore.h utils/utils.h
	$(CC) $(CFLAGS) -c villains.c

clean:
	-del /Q *.o *.exe *~ all
	-rm -rf *.o *.exe *~ all
