#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "character.h"
#include "bibliotecas/lista.h"

void createCharacter(const char* name, char* status, int level)
{   
    list* newCharacter = (list*) malloc(sizeof(list));
    newCharacter->name = name;
    newCharacter->status = status;
    newCharacter->level = level;

    add_node(&character_list, newCharacter->name);
}

void verifyStatus(list* character){
    if (character == NULL || character->status == NULL) {
        printf("Erro: nothing character.\n");
        return;
    }

    char lowerStatus[50];
    char lowerType[50];
    strcpy(lowerStatus, character->status); 

    for (int i = 0; lowerStatus[i]; ++i) 
        lowerStatus[i] = tolower(lowerStatus[i]);

    for(int i = 0; lowerType[i]; ++i)
        lowerType[i] = tolower(lowerType[i]);
    
    if (strcmp(lowerStatus, "available") == 0 && strcmp(lowerType, "hero") == 0)
    {
        printf("%s - ", character->name);
    }
}
