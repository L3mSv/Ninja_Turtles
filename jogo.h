#ifndef JOGO_H
#define JOGO_H

#include "bibliotecas/heap.h"

void introduction(); 
void tutorial();
void commandCentral();
void cleanTerminal();
Mission* createMission(const char* local, const char* description);
void missionPanel(Heap* heap, int numMissions);
Heap* createPanel();
int addMissionToPanel(Heap* heap, int numMissions);
void showMissions(Heap* heap);

#endif 
