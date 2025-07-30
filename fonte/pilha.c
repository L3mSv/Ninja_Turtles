#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../bibliotecas/pilha.h"

Nodo* criaNodo(const char* locals, int level, const char* descriptions){
    Nodo* novoNodo = (Nodo*) malloc(sizeof(Nodo));
    novoNodo->locals = locals;
    novoNodo->level = level;
    novoNodo->descriptions = descriptions;
    novoNodo->prox = NULL;
    return novoNodo;
}

void inicializaPilha(Pilha* p){
    p->topo = NULL;
}

int pilhaVazia(Pilha* p){
    return p->topo == NULL;
}

void push(Pilha* p, const char* locals, int level, const char* descriptions){
    Nodo* novoNodo = criaNodo(locals, level, descriptions);

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

/*
NAO PARECE TER UTILIDADE AGORA, MAS POR VIA DE DUVIDA DEIXA Ai

Nodo* pegaTopoPilha(Pilha* p){
    if(!pilhaVazia(p))
    {
        return p->topo->valor;
    }
    else{
        printf("\nPilha Vazia!");
        return INT_MIN;
    }
}
*/

void imprimePilha(Pilha* p){
    Nodo* temp = p->topo;
    printf("Pilha (de cima para baixo): ");
    while(temp->prox != NULL)
    {
        printf("\n%s ->", temp->locals);
        printf("\n%d ->", temp->level);
        printf("\n%s ->", temp->descriptions);
        temp = temp->prox;
    }
    printf("\n%s ", temp->locals);
    printf("\n%d ", temp->level);
    printf("\n%s ", temp->descriptions);
}