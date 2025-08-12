#ifndef BATTLE_H
#define BATTLE_H

    #include "jogo.h"
    #include "team.h"
    #include "weapon.h"

    float teamForce(Team* team);
    void battleResolution(Team* team, struct Mission* mission);

#endif 