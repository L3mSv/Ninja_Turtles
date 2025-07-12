CC = gcc
CFLAGS = -Wall -g
LIBS = -lm

all: jogo.o pilha.o
	$(CC) $(CFLAGS) -o all jogo.o pilha.o $(LIBS)

jogo.o: jogo.c bibliotecas/pilha.h
	$(CC) $(CFLAGS) -c jogo.c

pilha.o: fonte/pilha.c bibliotecas/pilha.h
	$(CC) $(CFLAGS) -c fonte/pilha.c

clean:
	del /Q *.o *.exe *~ all
	rm -rf *.o *.exe *~ all