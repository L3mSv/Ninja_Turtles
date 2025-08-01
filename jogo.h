#ifndef JOGO_H
#define JOGO_H

#include "bibliotecas/heap.h"

void introduction(); 
void tutorial();
void commandCentral();
void cleanTerminal();
Mission* createMission(const char* local, const char* description);
void missionPanel();
void createPanel();
int addMissionToPanel();
void showMissions();
void selectMission();
void battle(struct Mission mission);
void arsenal();
void leave();
void back();

#endif 
