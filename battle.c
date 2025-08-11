#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "battle.h"

float teamForceCalculation(Team* team){
    float totalForce = 0;
    int numMembers = 0;
    while(team->next != NULL)
    {
        if(strcmp("Katana", team->weapon) && strcmp("Leonardo", team->name))
        {
            totalForce += 0.5;     
        }
        if(strcmp("Sai", team->weapon) && strcmp("Rafael", team->name))
        {
            totalForce += 0.5;         
        }
        if(strcmp("Staff", team->weapon) && strcmp("Donatello", team->name))
        {
            totalForce += 0.5;        
        }
        if(strcmp("Nunchaku", team->weapon) && strcmp("Michelangelo", team->name))
        {
            totalForce += 0.5;       
        }
        totalForce = team->level;
        numMembers++;

        team = team->next;
    }

    return totalForce/numMembers;
}

float battleResolution(Team* team, struct Mission* mission){
    float result = 0;
    float team_force = teamForceCalculation(team);

    result = team_force - mission->level + (rand() % (2 - (-2) + 1)) + (-2) - (rand() % (1 - 0 + 1) + (0));

    return result;
}