#ifndef PILHA_H
#define PILHA_H

typedef struct Nodo{
    const char* locals;
    int level;
    const char* descriptions;
    struct Nodo* prox;
}Nodo;

Nodo* criaNodo(const char* locals, int level, const char* descriptions);

typedef struct Pilha{
    Nodo* topo;
}Pilha;

void inicializaPilha(Pilha* p);
void push(Pilha* p, const char* locals, int level, const char* descriptions);
void pop(Pilha* p);
int pilhaVazia(Pilha* p);
void liberaPilha(Pilha* p ); 
void imprimePilha(Pilha* p);
int pegaTopoPilha(Pilha* p);

#endif