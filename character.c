#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "character.h"
#include "bibliotecas/lista.h"

extern Character *character_list;
/*
void createCharacter(const char* name, char* status, int level)
{   
    Character* newCharacter = (Character*) malloc(sizeof(Character));
    newCharacter->name = name;
    newCharacter->status = status;
    newCharacter->level = level;

    add_node(&character_list, newCharacter->name);
}*/

void verifyStatus(Character* character){
    if (character == NULL || character->status == NULL){
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

void getting_characters_from_file(){
    FILE *file1 = fopen("character.txt", "r");
        if(!file1){
            perror("fopen");
            return;
        }
    
    char name_buffer[100], status_buffer[100];
    int level_buffer;

    while(fscanf(file1, "\n%99[^,], %99[^,], %d", name_buffer, status_buffer, &level_buffer) == 3){
        add_node_character(&character_list, name_buffer, status_buffer, level_buffer);
    }
    
    return;
}

