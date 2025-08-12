#ifndef PILHA_H
#define PILHA_H

typedef struct Nodo{
    char* locals;
    int level;
    char* descriptions;
    struct Nodo* prox;
}Nodo;

typedef struct Pilha{
    Nodo* top;
}Pilha;

#include "jogo.h"

Nodo* createNodo(struct Mission* mission);
void stackInicialization(Pilha* p);
void push(Pilha* p, struct Mission* mission);
void pop(Pilha* p);
int stackVoid(Pilha* p);
void freeStack(Pilha* p ); 
void stackPrint(Pilha* p);
int catchStackTop(Pilha* p);

#endif