#ifndef NURSING_H
#define NURSING_H

#include "jogo.h"
#include "lista.h"
#include "character.h"
#include "battle.h"

void addInjuredMember(Team* team, float resultBattle);
void addInjuredTeam(Team* team, float resultBattle);
void VerifyRemoveInjuredMember(Team* injured_character_list);
void setConsequenceInjured(Team* injured_member, float resultBattle);
void removeInjuredMembersInjuredsList(Team* injured_member);
void print_list_injureds(Team *head);

#endif