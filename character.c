#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "character.h"

Character* createCharacter(const char* name, char* status, const char* type, int level)
{   
    Character* newCharacter = (Character*) malloc(sizeof(Character));
    newCharacter->name = name;
    newCharacter->status = status;
    newCharacter->type = type;
    newCharacter->level = level;

    return newCharacter;
}