#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "weapon.h"

Weapon* createWeapon(const char* name)
{
    Weapon* newWeapon = (Weapon*) malloc(sizeof(Weapon));
    newWeapon->name = name;

    return newWeapon;
}