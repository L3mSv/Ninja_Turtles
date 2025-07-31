#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "weapon.h"
#include "bibliotecas/lista.h"

void createWeapon(const char* name)
{
    Weapon* newWeapon = (Weapon*) malloc(sizeof(Weapon));
    newWeapon->name = name;

    add_node(&weapon_list, newWeapon->name); 
}