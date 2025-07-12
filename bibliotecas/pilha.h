#ifndef PILHA_H
#define PILHA_H

typedef struct Nodo{
    int valor;
    struct Nodo* prox;
}Nodo;

Nodo* criaNodo(int novoValor);

typedef struct Pilha{
    Nodo* topo;
}Pilha;

void inicializaPilha(Pilha* p);
void push(Pilha* p, int valor);
void pop(Pilha* p);
int pilhaVazia(Pilha* p);
void liberaPilha(Pilha* p ); 
void imprimePilha(Pilha* p);
int pegaTopoPilha(Pilha* p);


#endif