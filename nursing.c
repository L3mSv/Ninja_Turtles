#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nursing.h"

void addInjuredMember(Team* team)
{
    Character* member = randomMember(team);
    member->status = "injured";
    remove_character_by_name(character_list, member->name);
    remove_from_team(team, member->name);
    add_node_character(&injured_character_list, member->name, member->status, member->level);
}

void addInjuredTeam(Team* team){
    team->status = "injured";

    Team* temp = team;
    while(temp->next != NULL)
    {
        remove_character_by_name(character_list, temp->name);
        remove_from_team(team, team->name);
        
        temp = temp->next;
    }
}

void removeInjuredMember(Character* injured_character_list){
    
}