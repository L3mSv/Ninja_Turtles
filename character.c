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

    add_node(&character_list, newCharacter->name);
}

void verifyStatus(Character* character){
    if (character == NULL || character->status == NULL) {
        printf("Erro: nothing character.\n");
        return;
    }

    char lowerStatus[50];
    char lowerType[50];
    strcpy(lowerStatus, character->status); 
    strcpy(lowerType, character->type);

    for (int i = 0; lowerStatus[i]; ++i) 
        lowerStatus[i] = tolower(lowerStatus[i]);

    for(int i = 0; lowerType[i]; ++i)
        lowerType[i] = tolower(lowerType[i]);
    
    if (strcmp(lowerStatus, "available") == 0 && strcmp(lowerType, "hero") == 0)
    {
        printf("%s - ", character->name);
    }
}
