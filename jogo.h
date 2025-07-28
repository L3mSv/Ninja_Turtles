#ifndef JOGO_H
#define JOGO_H

#include "../bibliotecas/heap.h"

void introduction(); 
void tutorial();
void commandCentral();
void cleanTerminal();
Mission* createMission(const char* local, int level, const char* description);

#endif 
