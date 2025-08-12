#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nursing.h"

extern Character *injured_character_list;

void injured_list_inicialization(Character *characters_to_count){
    int i = 0;
    while(characters_to_count->next){
        characters_to_count = characters_to_count->next;
        i++;
    }

    for(int j = 0; j < i; j++){
        add_node_character(&injured_character_list, "Empty", "null", 0.0);
    }

    return;
}

void addInjuredMember(Team** team, Character **injured_ones, float resultBattle)
{
    Team* member = randomMember(team);
    member->status = strdup("injured");

    Team *temp = *team;
    int count = 0;
    while(temp->next){ //conta quantos membros válidos há no time
        if(strcmp(temp->name, "Empty") != 0){
            count++;
        }
        temp = temp->next;
    }

    srand(time(NULL));
    int index_to_be_removed = rand() % count; //gera um numero aleatorio para ficar ferido

    temp = *team; // reseto o "temp" para pegar os dados do personagem no indice gerado
    int i = 1;
    while(temp->next != NULL && i < index_to_be_removed){
        temp = temp->next;
    }


    add_node_character(injured_ones, temp->name, temp->status, temp->level);
    
    remove_from_team(&team, member->name);
    
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