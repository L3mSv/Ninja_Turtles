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

    printf("Characters available: \n");
    print_list_character(character_list);

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
    char team_member_code_buffer;
    int team_member_code, character_code;

    cleanTerminal();
    printf("ESC to go back\n");
    print_list_character(character_list);
    print_list_team(team);

    printf("\nWhich one do you want to swap?\n");
    printf("\nTeam's member code: ");
        scanf(" %c", &team_member_code);
        if(team_member_code_buffer == 27){
            change_team();
        }else{
            team_member_code = team_member_code_buffer - '0'; //converte o char para int
        }
    printf("\nCharacter's code: ");
        scanf(" %d", &character_code);

    swap_characters(&team, &character_list, team_member_code, character_code);

}

void swap_characters(Team **team_head, Character **char_head, int team_index, int character_index){
    Character *temp_char = *char_head;
    Team *temp_team = *team_head;

    for(int i = 0; i < team_index; i++){
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
    for(int i = 0; i < character_index; i++){
        if(!temp_char->next){
            printf("Invalid index for character!!\n");
            printf("Press any key to proceed.");
            char c = getch();
            c++;//só fazendo uma operação qualquer para não dar "variavel não utilizada"

            change_character_team();
        }else{
            temp_char = temp_char->next;
        }
    }
    add_node_character(&character_list, temp_team->name, temp_team->status, temp_team->level);
    add_to_team(&team, temp_char->name, temp_char->status, temp_team->weapon, temp_char->level);
    remove_from_team(&team, temp_team->name);
    remove_character_by_name(&character_list, temp_char->name);

    printf("Successfully swappped!!\n");

    printf("Press any key to proceed.");
            char c = getch();
            c++;
    change_team();

}


void change_weapon(){
    char team_member_code_buffer;
    int team_member_code, weapon_code;

    cleanTerminal();
    printf("\nESC to go back\n");
    print_list_weapon(weapon_list);
    print_list_team(team);

    printf("\nWhich one do you want to swap?\n");
    printf("\nTeam's member code: ");
        scanf(" %c", &team_member_code);
        if(team_member_code_buffer == 27){
            change_team();
        }else{
            team_member_code = team_member_code_buffer - '0'; //converte o char para int
        }
    printf("\nWeapons's code: ");
        scanf(" %d", &weapon_code);

    swap_weapon(&team, &weapon_list, team_member_code, weapon_code);
        
}

void swap_weapon(Team **team_head, Weapon **weapon_head, int team_index, int weapon_index){
    Weapon *temp_weapon = *weapon_head;
    Team *temp_team = *team_head;

    for(int i = 0; i < team_index; i++){
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
    for(int i = 0; i < weapon_index; i++){
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
    add_node_weapon(&weapon_list, temp_team->weapon);
    strcpy(temp_team->weapon, temp_weapon->name);
    remove_weapon(&weapon_list, temp_weapon->name);

    printf("Successfully swappped!!\n");

    printf("Press any key to proceed.");
            char c = getch();
            c++;
    change_team();
}

void initialize_team(){
    add_to_team(&team, "Empty", "null", "null", 0);
    add_to_team(&team, "Empty", "null", "null", 0);
    add_to_team(&team, "Empty", "null", "null", 0);
    add_to_team(&team, "Empty", "null", "null", 0);
}