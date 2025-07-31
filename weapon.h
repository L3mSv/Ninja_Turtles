#ifndef WEAPON_H
#define WEAPON_H

typedef struct Weapon
{
    const char* name;
}Weapon;

Weapon* createWeapon(const char* name);

#endif;