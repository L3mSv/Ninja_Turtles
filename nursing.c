#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nursing.h"

void addInjuredMember(Team* team, float resultBattle)
{
    Team* member = randomMember(team);
    member->status = strdup("injured");
    remove_from_team(&team, member->name);
    add_to_team(&injured_character_list, member->name, member->status, NULL, member->level);
    setConsequenceInjured(member, resultBattle);

}

void addInjuredTeam(Team* team, float resultBattle){
    team->status = "injured";

    Team* temp = team;
    while(temp != NULL)
    {
        Team* next = temp->next;
        setConsequenceInjured(temp, resultBattle);
        remove_from_team(&team, temp->name);
        temp = next;
    }
}

void setConsequenceInjured(Team* injured_member, float resultBattle){
    if(resultBattle <= 3.0 && resultBattle >= 0.0)
    {
        injured_member->rounds_injured = 2;
    }
    else if(resultBattle < 0.0)
    {
        cleanTerminal();
        printf("\nGAME OVER!\n");
        exit(1);
    }

    return;
}

void VerifyRemoveInjuredMember(Team* injured_character_list){
    Team* temp = injured_character_list;

    while(temp != NULL){
        Team* next = temp->next;
        if(temp->rounds_injured == 0)
        {
            removeInjuredMembersInjuredsList(temp);
        }
        temp = next;
    }
}

void removeInjuredMembersInjuredsList(Team* injured_member){
    injured_member->status = strdup("avaiable");
    add_node_character(&character_list, injured_member->name, injured_member->status, injured_member->level);
    remove_from_team(&injured_character_list, injured_member->name);
}