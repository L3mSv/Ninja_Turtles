CC = gcc
CFLAGS = -Wall -g
LIBS = -lm

all: jogo.o pilha.o utils.o
	$(CC) $(CFLAGS) -o all jogo.o pilha.o utils.o $(LIBS)

jogo.o: jogo.c jogo.h bibliotecas/pilha.h utils/utils.h
	$(CC) $(CFLAGS) -c jogo.c

pilha.o: fonte/pilha.c bibliotecas/pilha.h
	$(CC) $(CFLAGS) -c fonte/pilha.c

utils.o: utils/utils.c utils/utils.h
	$(CC) $(CFLAGS) -c utils/utils.c


clean:
	del /Q *.o *.exe *~ all
	rm -rf *.o *.exe *~ all