#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "weapon.h"
#include "bibliotecas/lista.h"

extern Weapon *weapon_list;

/*
void createWeapon(const char* name)
{
    Weapon* newWeapon = (Weapon*) malloc(sizeof(Weapon));
    newWeapon->name = name;

    add_node(&weapon_list, newWeapon->name); 
}*/

void getting_weapon_from_file(Weapon **head){
    FILE *file1 = fopen("weapon.txt", "r");
        if(!file1){
            perror("fopen");
            return;
        }
    
    char name_buffer[100];

    while(fgets(name_buffer, 100, file1)){
        name_buffer[strcspn(name_buffer, "\n")] = '\0';
        add_node_weapon(head, name_buffer);
    }
    
    return;
}
