#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h> 
#include <time.h>
#include "battle.h"

int numMembers = 0;

void VerifyRemoveInjuredMember(Team* team){
    Team* temp = team;

    while(temp != NULL){
        Team* next = temp->next;
        if(temp->rounds_injured == 0)
        {
            temp->status = strdup("available");
        }
        else{
            temp->rounds_injured--;
        }
        temp = next;
    }
}

float teamForceCalculation(Team* team){
    float totalForce = 0;
    FILE *file1 = fopen("bench", "w");
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

    /*
    float team_force = teamForceCalculation(team);
    srand(time(NULL));
    result = team_force - mission->level + (rand() % (2 - (-2) + 1) + (-2)) - (rand() % (1 - 0 + 1) + (0));
    */

    float team_force = teamForceCalculation(team);
    float team_score = team_force / 10.0f; 
    float mission_score = mission->level / 6.0f;
    float luck = ((rand() % 21) - 10) / 100.0f; 

    result = (team_score - mission_score) * 5 + luck * 2;

    print_lento("\nBattle in course...\n", 100);

    Sleep(3);
    printf("\nResult: %.2f\n", result);

    print_lento("\nThe mission was ", 200);

    Sleep(10);

    if(result > 3){
        team->level += 0.3;
        printf("PERFECT!\n");
    }
    else if(result <= 3 && result >= 0){   
        printf("VICTORY WITH COST!\n");        
        Team* member = randomMember(team);
        member->status = strdup("injured"); 
        member->rounds_injured = 2;
            
        Team* temp = team;
        while(temp != NULL)
        {
            if(strcmp(temp->status, "injured") != 0)
            {
                temp->level += 0.2;

            }
            temp = temp->next;
        }
    }
    else{
        printf("DEFEAT\n");
        espera(10);
        cleanTerminal();
        printf("GAME OVER!\n");
        exit(1);
    }


    VerifyRemoveInjuredMember(team);

    espera(15);

    battleStatistics(team, result);

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
        if(strcmp(temp->name, "Empty") != 0)
            count++;
        temp = temp->next;
    }

    if(count == 0) return NULL;

    srand(time(NULL));
    int random_index = rand() % count;

    temp = team;
    int i = 0;
    while(temp != NULL)
    {
        if(strcmp(temp->name, "Empty") != 0)
        {
            if(i == random_index)
                return temp;
            i++;
        }
        temp = temp->next;
    }

    return NULL;
}



void battleStatistics(Team* team, float resultBattle){
        cleanTerminal();
        printf("+-----------------------------------------------------------------------+\n");
        printf("|MISSION STATISTICS                                                     |\n");
        printf("+-----------------------------------------------------------------------+\n\n");
        printf("\nResult: %.2f\n", resultBattle);
        printf("[ESC] Back\n");
        
        int injuredCount = 0;
        Team* temp = team;

        printf("\nTeam Experience==========\n");
        while(temp != NULL)
        {
            if(resultBattle > 3)
            {
                if(strcmp(temp->name, "Empty") != 0)
                    printf("\n%s received 0.3 exp .............\n", temp->name);
            }
            else if(resultBattle <=  3 && resultBattle >= 0)
            {
                if(strcmp(temp->status, "available") == 0 && strcmp(temp->name, "Empty") != 0)
                {
                    printf("\n%s received 0.2 exp .............\n", temp->name);
                }
                if(strcmp(temp->status, "injured") == 0 && strcmp(temp->name, "Empty") != 0)
                {
                    printf("\n%s didn't received exp >_<\n", temp->name);
                    injuredCount++;
                }
            }
            else{
                if(strcmp(temp->name, "Empty") != 0)
                    printf("\n%s didn't received exp >_<\n", temp->name);
            }

            temp = temp->next;
        }

        printf("\nBro's Status==========\n");
        {
            printf("\nInjured Bro's: %d/%d", injuredCount, numMembers);
            printf("\nHealthy Bro's: %d/%d\n", (numMembers - injuredCount), numMembers);
        }


        while(1){
        char c = getch();
        if (c == 27) { 
            break;
            }
        }

        back(); 
    }
