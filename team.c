#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "team.h"
#include "bibliotecas/lista.h"
#include "jogo.h"

extern Character *character_list;
extern Team *team;
extern Weapon *weapon_list;

char getChoice_for_team_func(int min_char, int max_char) //a mesma função de get choice genérica, porem ela não volta para a central de comando, mas sim para funcoes de time
{
    char c;
    while(1){
        c = getch();
        c = tolower(c);

        if(c >= min_char && c <= max_char)
        {
            return c;
        }

        if(c == 27)
        {
            arsenal();
            
        }
    }
}

void change_team(){
    cleanTerminal(); 

    printf("ESC to go back\n\n");

    printf("Characters available: \n");
    print_list_character(character_list);
    
    printf("\nWeapons available:\n");
    print_list_weapon(weapon_list);

    printf("\nYour team: \n");
    print_list_team(team);

    printf("\nDo you want to change a member[M] or a weapon[W]?\n");

    char c = getChoice_for_team_func('m', 'w');

    if(c == 'm'){
        change_character_team();
    }else if(c == 'w'){
        change_weapon();
    }else{
        arsenal();
    }
    

}

void change_character_team(){
    int team_member_code, character_code;

    cleanTerminal();
    printf("\n\n");
    print_list_character(character_list);
    printf("\n");
    print_list_team(team);

    printf("\nWhich one do you want to swap?\n");
    printf("\nTeam's member code: ");
        scanf(" %d", &team_member_code);
        if(team_member_code > 4){
            printf("Invalid index for team!!\n");
            printf("Press any key to proceed.");
            getch();

            change_character_team();
        }
    printf("\nCharacter's code: ");
        scanf(" %d", &character_code);

    swap_characters(&team, &character_list, team_member_code, character_code);

}

void swap_characters(Team **team_head, Character **char_head, int team_index, int character_index){
    if(team_index < 1 || character_index < 1){
        printf("Indices must be >= 1\nPress any key to proceed.");
        getch();
        change_team();
    }

    Character *temp_char = *char_head;
    Team *temp_team = *team_head;

    int i = 1;
    while (i < team_index && temp_team != NULL) {
        temp_team = temp_team->next;
        ++i;
    }

    if (temp_team == NULL) {
        printf("Invalid team index!\n");
        printf("Press any key to proceed.\n");
        getch();
        change_team();
    }

    int j = 1;
    while (j < character_index && temp_char != NULL) {
        temp_char = temp_char->next;
        ++j;
    }

    if (temp_char == NULL) {
        printf("Invalid character index!\n");
        printf("Press any key to proceed.\n");
        getch();
        change_team();
    }
    

    //char *team_weapon = temp_team->weapon ? temp_team->weapon : "null";
    //char *team_status = temp_team->status ? temp_team->status : "null";


   
    add_node_character_index(char_head, temp_team->name, temp_team->status, temp_team->level, character_index);
    add_to_team_index(team_head, temp_char->name, temp_char->status, temp_team->weapon, temp_char->level, team_index);
    remove_character_by_name(char_head, temp_char->name);
    remove_from_team(team_head, temp_team->name);

    printf("Successfully swappped!!\n");

    printf("Press any key to proceed.");
    getch();

    change_team();
}


void change_weapon(){
    char team_member_code_buffer;
    int team_member_code, weapon_code;

    cleanTerminal();
    printf("\nESC to go back\n\n");
    print_list_weapon(weapon_list);
    printf("\n");
    print_list_team(team);

    printf("\nWhich one do you want to swap?\n");
    printf("\nTeam's member code: ");
        scanf(" %c", &team_member_code_buffer);
                team_member_code = team_member_code_buffer - '0'; //converte o char para int
        
    printf("\nWeapons's code: ");
        scanf(" %d", &weapon_code);

    swap_weapon(&team, &weapon_list, team_member_code, weapon_code);
        
}


void swap_weapon(Team **team_head, Weapon **weapon_head, int team_index, int weapon_index){
    Weapon *temp_weapon = *weapon_head;
    Team *temp_team = *team_head;

    for(int i = 0; i < team_index - 1; i++){
        if(!temp_team->next){
            printf("Invalid index for team!!\n");
            printf("Press any key to proceed.");
            char c = getch();
            c++;//só fazendo uma operação qualquer para não dar "variavel não utilizada"

            change_character_team();
        }else{
            temp_team = temp_team->next;
        }
    }
    if(strcmp(temp_team->name, "Empty") == 0){
        printf("\nYou cannot give a weapon to a person that doesnt exist!!\n");
        getch();
        change_team();
    }

    for(int j = 0; j < weapon_index - 1; j++){
        if(!temp_weapon->next){
            printf("Invalid index for weapon!!\n");
            printf("Press any key to proceed.");
            char c = getch();
            c++;//só fazendo uma operação qualquer para não dar "variavel não utilizada"

            change_character_team();
        }else{
            temp_weapon = temp_weapon->next;
        }
    }
    add_node_weapon(weapon_head, temp_team->weapon);
    strcpy(temp_team->weapon, temp_weapon->name);
    remove_weapon(weapon_head, temp_weapon->name);

    printf("Successfully swappped!!\n");

    printf("Press any key to proceed.");
        getch();
    change_team();
}

void initialize_team(){
    add_to_team(&team, "Empty", "null", "null", 0);
    add_to_team(&team, "Empty", "null", "null", 0);
    add_to_team(&team, "Empty", "null", "null", 0);
    add_to_team(&team, "Empty", "null", "null", 0);
}

void check_team(Team *head, struct Mission* mission, int index){
    int count_members = 0, count_weapons = 0, injured = 0;
    while(head){
        if(strcmp(head->status, "injured") == 0){
            injured++;
        }
        if(strcmp(head->name, "Empty") == 0){
            count_members++;
        }
        if(strcmp(head->weapon, "null") == 0){
            count_weapons++;
        }
        head = head->next;
    }
    if(injured != 0){
        printf("You can't enter a mission with a member injured!!\n");
        printf("Press any key to proceed.\n");
        getch();
        missionPreparation(mission, index);
    }
    if(count_members > 2){
        printf("You cannot have less than 2 members per mission!!");
        printf("Press any key to proceed.\n");
        getch();
        missionPreparation(mission, index);
    }
    if(count_weapons < 2){
        printf("You cannot have more than 2 members equipping weapons!!!\n");
        printf("Press any key to proceed.\n");
        getch();
        missionPreparation(mission, index);
    }

    return;
}

