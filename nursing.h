#ifndef NURSING_H
#define NURSING_H

#include "jogo.h"
#include "lista.h"
#include "character.h"
#include "battle.h"

<<<<<<< HEAD
void addInjuredMember(Team* team, float resultBattle);
void addInjuredTeam(Team* team, float resultBattle);
void VerifyRemoveInjuredMember(Team* injured_character_list);
void setConsequenceInjured(Team* injured_member, float resultBattle);
void removeInjuredMembersInjuredsList(Team* injured_member);
=======
void addInjuredMember(Team* team);
void addInjuredTeam(Team* team);
void removeInjuredMember(Character* injured_character_list);
>>>>>>> b1aadc87abecf174f834cb73a643e4ceae542319

#endif