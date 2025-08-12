#ifndef TEAM_h
#define TEAM_h

#undef max
#include "bibliotecas/lista.h"
#include "heap.h"

char getChoice_for_team_func(int min_char, int max_char);
void change_team();
void change_character_team();
void swap_characters(Team **team_head, Character **char_head, int team_index, int character_index);
void change_weapon();
void swap_weapon(Team **team_head, Weapon **weapon_head, int team_index, int weapon_index);
void initialize_team();
void check_team(Team *head, Mission* mission, int index);

#endif