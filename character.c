#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "character.h"
#include "bibliotecas/lista.h"

void createCharacter(const char* name, char* status, const char* type, int level)
{   
    Character* newCharacter = (Character*) malloc(sizeof(Character));
    newCharacter->name = name;
    newCharacter->status = status;
    newCharacter->type = type;
    newCharacter->level = level;

    add_node(&turtle_list, newCharacter->name);
}

void verifyStatus(Character* character){
    if (character == NULL || character->status == NULL) {
        printf("Erro: nothing character.\n");
        return;
    }

    char lowerStatus[50]; 
    strcpy(lowerStatus, character->status); 

    for (int i = 0; lowerStatus[i]; i++) {
        lowerStatus[i] = tolower(lowerStatus[i]);
    }
    
    if (strcmp(lowerStatus, "available") == 0)
    {
        printf("%s - ", character->name);
    }
}
