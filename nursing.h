#ifndef NURSING_H
#define NURSING_H

#include "jogo.h"
#include "lista.h"
#include "character.h"

void addInjuredMember(Team* team);
void addInjuredTeam(Team* team);
void removeInjuredMember(Character* injured_character_list);

#endif