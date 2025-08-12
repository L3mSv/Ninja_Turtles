#ifndef BATTLE_H
#define BATTLE_H

    #include "jogo.h"
    #include "team.h"
    #include "weapon.h"
    #include "nursing.h"
    #include "bibliotecas/pilha.h"
    #include "utils/utils.h"

    float teamForceCalculation(Team* team);
    void battleResolution(Team* team, struct Mission* mission);
    Team* randomMember(Team* team);

#endif 