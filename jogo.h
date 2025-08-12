#ifndef JOGO_H
#define JOGO_H

#include "bibliotecas/heap.h"
#include "bibliotecas/pilha.h"
#include "team.h"
#include "character.h"
#include "weapon.h"
#include "villains.h"
#include "bibliotecas/arvore.h"
#include "utils/utils.h"
#include "bibliotecas/lista.h"
#include "battle.h"

extern const char* DESCRIPTIONS_PATH;
extern const char* LOCALS_PATH;
extern const char* VILLAINS_PATH;

extern Pilha* logbook;
extern Team *team;
extern Character *character_list;
extern Character *injured_character_list;
extern Weapon *weapon_list;
extern AVL* villains;
extern Heap* Panel;
extern int numMissions;

void introduction(); 
void tutorial();
void commandCentral();
void cleanTerminal();
Mission* createMission(const char* local, const char* description);
void missionPanel();
void createPanel();
int addMissionToPanel();
void showMissions();
void selectMission(int choiceMission);
void arsenal();
void leave();
void back();
void missionPreparation(struct Mission* mission, int index);
char getChoice(int min_char, int max_char);
void villain_database();
void splinterLogbook();

#endif 
