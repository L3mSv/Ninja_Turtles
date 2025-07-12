#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "bibliotecas/pilha.h"

int main(){
    Pilha* pilha;
    inicializaPilha(pilha);

    push(pilha, 2);
    push(pilha, 43);
    push(pilha, 32);

    imprimePilha(pilha);
}