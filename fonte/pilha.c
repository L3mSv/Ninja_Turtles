#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "../bibliotecas/pilha.h"

Nodo* createNodo(struct Mission* mission){
    Nodo* newNodo = (Nodo*) malloc(sizeof(Nodo));
    newNodo->locals = strdup(mission->local);
    newNodo->level = mission->level;
    newNodo->descriptions = strdup(mission->description);
    newNodo->prox = NULL;
    return newNodo;
}

void stackInicialization(Pilha* p){
    p->top = NULL;
}

int stackVoid(Pilha* p){
    return p->top == NULL;
}

void push(Pilha* p, struct Mission* mission){
    Nodo* newNodo = createNodo(mission);

    if(!newNodo){
        printf("\nMemory allocation failed!");
        return;
    }

    newNodo->prox = p->top;
    p->top = newNodo;
}

void pop(Pilha* p){
    if (stackVoid(p)) {
            printf("\nEmpty Stack!");
            return;
        }
        Nodo* temp = p->top;
        p->top = p->top->prox;
        free(temp->locals);
        free(temp->descriptions);
        free(temp);
}

void freeStack(Pilha* p){
    while(p->top != NULL)
    {
        pop(p);
    }
    printf("\nReleased Stack!");
}

/*
NAO PARECE TER UTILIDADE AGORA, MAS POR VIA DE DUVIDA DEIXA Ai

Nodo* catchStackTop(Pilha* p){
    if(!stackVoid(p))
    {
        return p->top->valor;
    }
    else{
        printf("\nStack is void!");
        return INT_MIN;
    }
}
*/

void stackPrint(Pilha* p){
    if (stackVoid(p)) {
            printf("\nSorry, but there is no mission history!\n");
            return;
        }
        Nodo* temp = p->top;
        while (temp != NULL) {
            printf("---------------------------\n");
            printf("Mission:\n");
            printf("Local: %s", temp->locals);
            printf("Level: %d\n", temp->level);
            printf("Description: %s\n", temp->descriptions);
            printf("---------------------------\n");

            temp = temp->prox;
        }
}