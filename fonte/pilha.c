#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../bibliotecas/pilha.h"

Nodo* criaNodo(int novoValor){
    Nodo* novoNodo = (Nodo*) malloc(sizeof(Nodo));
    novoNodo->valor = novoValor;
    novoNodo->prox = NULL;
    return novoNodo;
}

void inicializaPilha(Pilha* p){
    p->topo = NULL;
}

int pilhaVazia(Pilha* p){
    return p->topo == NULL;
}

void push(Pilha* p, int valor){
    Nodo* novoNodo = criaNodo(valor);

    if(!novoNodo){
        printf("\nOverflow na pilha!");
        return;
    }

    novoNodo->prox = p->topo;
    p->topo = novoNodo;
}

void pop(Pilha* p){
    if(pilhaVazia(p))
    {
        printf("\nPilha Vazia!");
        return;
    }
    else{
        Nodo* temp = p->topo;
        p->topo = p->topo->prox;
        free(temp);
    }
}

void liberaPilha(Pilha* p){
    while(p->topo != NULL)
    {
        pop(p);
    }
    free(p);
    printf("\nPilha Liberada!");
}

int pegaTopoPilha(Pilha* p){
    if(!pilhaVazia(p))
    {
        return p->topo->valor;
    }
    else{
        printf("\nPilha Vazia!");
        return INT_MIN;
    }
}

void imprimePilha(Pilha* p){
    Nodo* temp = p->topo;
    printf("Pilha (de cima para baixo): ");
    while(temp->prox != NULL)
    {
        printf(" %d ->", temp->valor);
        temp = temp->prox;
    }
    printf(" %d ", temp->valor);
}