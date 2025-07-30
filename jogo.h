#ifndef JOGO_H
#define JOGO_H

#include "bibliotecas/heap.h"

void introduction(); 
void tutorial();
void commandCentral();
void cleanTerminal();
Mission* createMission(const char* local, const char* description);
void missionPanel();
void addMissionToPanel(int numMissions);
void showMissions();

#endif 
