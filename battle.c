#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h> 
#include <time.h>
#include "battle.h"
#include "bibliotecas/pilha.h"
#include "utils/utils.h"
#include "jogo.h"
#include "nursing.h"


float teamForceCalculation(Team* team){
    float totalForce = 0;
    FILE *file1 = fopen("bench", "w");
    int numMembers = 0;
    while(team != NULL)
    {
        if(!(strcmp("Katana", team->weapon) && strcmp("Leonardo", team->name)))
        {
            totalForce += 0.5;     
        }
        if(!(strcmp("Sai", team->weapon) && strcmp("Rafael", team->name)))
        {
            totalForce += 0.5;         
        }
        if(!(strcmp("Staff", team->weapon) && strcmp("Donatello", team->name)))
        {
            totalForce += 0.5;        
        }
        if(!(strcmp("Nunchaku", team->weapon) && strcmp("Michelangelo", team->name)))
        {
            totalForce += 0.5;       
        }
        totalForce += team->level;
        fprintf(file1, "totalForce : %f\n", totalForce);
        if(strcmp("Empty", team->name) != 0){
            numMembers++;
        }
       
        team = team->next;
    }
    fclose(file1);
    return totalForce/numMembers;
}

void battleResolution(Team* team, struct Mission* mission){
    float result = 0;
    float team_force = teamForceCalculation(team);

    srand(time(NULL));

    result = team_force - mission->level + (rand() % (2 - (-2) + 1) + (-2)) - (rand() % (1 - 0 + 1) + (0));

    print_lento("\nBattle in course...\n", 100);

    Sleep(3);

    printf("\nResult: %.2f\n", result);

    print_lento("\nThe mission was ", 200);

    Sleep(5);

    if(result > 3){
        team->level += 0.3;
        printf("PERFECT!\n");
    }
    else if(result <= 3 && result >= 0){
        addInjuredMember(team);    
        team->level += 0.2;
        printf("VICTORY WITH COST!\n");
    }
    else{
        team->status = "injured";
        addInjuredTeam(team);
        printf("DEFEAT\n");
    }

    char c;
    do{
        c = getch();
    }while(c != 27);
    back();

}

Team* randomMember(Team* team){
    if(team == NULL)
    {
        printf("\nThe list is void!\n");
        return NULL;
    }

    int count = 0;
    Team* temp = team;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    srand(time(NULL));
    int random_index = rand() % count;

    temp = team->next;
    for(int i = 0; i < random_index; ++i)
    {
        temp = temp->next;
    }

    return temp;
}

/*
void battleStatistics(){
        cleanTerminal();
        printf("+-----------------------------------------------------------------------+\n");
        printf("|MISSION STATISTICS                                                     |\n");
        printf("+-----------------------------------------------------------------------+\n\n");


}
*/