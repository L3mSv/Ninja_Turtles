#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <time.h>
//#include <unistd.h> //Para sleep no Linux
#include <windows.h> //Para Sleep no Windows
#include <ctype.h>
#include <conio.h> // Para getch() no Windows
#include "bibliotecas/pilha.h"
#include "utils/utils.h"
#include "bibliotecas/heap.h"
#include "bibliotecas/lista.h"
#include "bibliotecas/arvore.h"
#include "character.h"
#include "weapon.h"
#include "villains.h"
#include "jogo.h"
#include "team.h"

const char* DESCRIPTIONS_PATH = "descriptions.txt";
const char* LOCALS_PATH = "locals.txt";
const char* VILLAINS_PATH = "villains.txt";

Team *team = NULL;
Character *character_list = NULL;
Weapon *weapon_list = NULL;
AVL* villains = NULL;
Heap* Panel;

//pilha-> diario de bordo
int numMissions;


// Função para aceitar apenas 'y' ou 'n' (minúsculo), sem ecoar na tela
char getYN() {
    char c;
    while (1) {
        c = getch();
        c = tolower(c);
        if (c == 'y' || c == 'n') {
            //printf("%c\n", c); //Mostra a escolha do usuário
            return c;
        }
        if(c == 27) // 27 ascii code to esc
        {
            back(); 
        }
    }
}

// Função mais genérica para obter uma escolha
char getChoice(int min_char, int max_char)
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
            commandCentral();
        }
    }
}

// Função para aceitar apenas numeros de 1 a 5, sem ecoar na tela
int getModuleChoice() {
    char c;
    int choice;

    while (1) {
        c = getch(); // Captura a tecla imediatamente
        if (c >= '1' && c <= '5') {
            choice = c - '0'; // Converte o caractere para o número inteiro correspondente
            // printf("%d\n", choice); // Opcional: Mostra a escolha do usuário na tela
            return choice;
        }
        if(c == 27) // 27 ascii code to esc
        {
            back(); 
        }
    }
}

// Função para aceitar apenas numeros de 1 a 10 para escolher a missao ou esc para sair, sem ecoar na tela --cara talvez precise só aquela função de getchoice mais generica, ela ta bem boa, da pra usar pra maioria das coisas acho
int getMission() {
    char c;
    int choice;

    while (1) {
        c = getch(); // Captura a tecla imediatamente
        if (c >= '1' && c <= '9') {
            choice = c - '0'; // Converte o caractere para o número inteiro correspondente
            // printf("%d\n", choice); // Opcional: Mostra a escolha do usuário na tela
            return choice;
        }
        if(c == 27) // 27 ascii code to esc
        {
            back(); 
        }
    }
}

void tutorial()
{
    printf("\n\033[95mDonatello\033[0m: Welcome to the tutorial!\n");
    // ... aqui pode colocar o conteúdo do tutorial ...
}

void commandCentral()
{
    cleanTerminal();

    while(1)
    {
        printf("-- Command Central --\n\n");
        printf("[1]. Mission Alerts Panel\n");
        printf("[2]. Villains DataBase\n");
        printf("[3]. Master Splinter's Logbook\n");
        printf("[4]. Arsenal and the Action Plan\n\n");
        printf("[5]. Leave\n\n");

        char choice_modules = getChoice('1', '5');

        if(choice_modules == '1')
            missionPanel();
        else if(choice_modules == '2')
            villain_database();
        else if(choice_modules == '4')
        {
            arsenal();
        }
        else if(choice_modules == '5')
        {
            leave();
        }
    }
}

void leave()
{
    cleanTerminal();

    printf("Are you really want exit ?\n\n");
    printf("[Y] Yes | [N] No\n\n");
    char exitChoice = getChoice('n', 'y');
    if(exitChoice == 'y')
    {
        cleanTerminal();
        printf("\nExiting program...\n");
        Sleep(3);

        free_list_character(&character_list);
        free_list_team(&team);
        free_list_weapon(&weapon_list);
        
        exit(0);
    }
    if(exitChoice == 'n'){
        commandCentral();
    }
}

void back()
{
    commandCentral();
}

void introduction()
{
    print_lento
    ("\033[31mA cidade de Nova York esta um caos\033[0m!\n"
    " O Destruidor e Krang uniram forcas, e o Cla do Pe, junto com mutantes como Bebop" 
    "e Rocksteady, estao executando varios planos malignos ao mesmo tempo.\n"
    "As Tartarugas Ninja estao sobrecarregadas, portanto, para organizar a defesa da cidade, Donatello" 
    " decidiu criar um sistema de computador avancado: a \033[1m\"Central de Comando\"\033[0m.\n" 
    "Ela irá gerenciar as missoes, catalogar os viloes e otimizar as operacoes do time.\n"
    "\nSua missao e ajudar as Tartarugas Ninja a combater o mal sobre Nova York e restaurar a" 
    " paz atraves de ordens pela Central de Comando. \033[33mBoa sorte\033[0m\n" , 100);

    Sleep(3);
    cleanTerminal();

    Sleep(8);

    printf("\n\033[95mDonatello\033[0m: Hey, thanks god you got the Command Central and in the best time, things around here are not very good.\n");

    Sleep(5);

    printf("\n\033[95mDonatello\033[0m: While me and my brothers were in a special mission New York was ruined, There are villians all places!\n");

    Sleep(5);

    printf("\n\033[95mDonatello\033[0m: We are going to Sewer Liar to see if is okay.\n");

    Sleep(5);

    printf("\n\033[95mDonatello\033[0m: Do you want join to us?");
    printf("\nGo to Tutorial: [Y] yes | [N] no ");

    char tutorialChoice = getChoice('n', 'y');
    if (tutorialChoice == 'y') {
        tutorial();
    } else {
        printf("\n\033[95mDonatello\033[0m: So, see you later!\n");
        Sleep(3);
        cleanTerminal();
        commandCentral();
    }
}


void cleanTerminal()
{
    system("clear"); //limpa tela para Linux/macOS
    system("cls"); //Limpa tela para Windows
}

Mission* createMission(const char* local, const char* description)
{
    Mission* mission = (Mission*) malloc(sizeof(Mission));

    FILE* descriptionsFile = fopen(DESCRIPTIONS_PATH, "r");
    if(descriptionsFile == NULL)
    {
        perror("ERROR in try to open descriptions file");
        mission->description = NULL;
        mission->local = NULL;
        mission->level = 0;
        return mission;
    }

    FILE* localsFile = fopen(LOCALS_PATH, "r");
    if(localsFile == NULL)
    {
        perror("ERROR in try to open locals file");
        mission->description = NULL;
        mission->local = NULL;
        mission->level = 0;
        return mission;
    }

    char* descriptions[100];
    int descriptions_count = 0;
    char descriptions_linhas[256];

    char* locals[100];
    int locals_count = 0;
    char locals_linhas[256];

    while(fgets(descriptions_linhas, sizeof(descriptions_linhas), descriptionsFile))
    {
        descriptions[descriptions_count] = malloc(strlen(descriptions_linhas) + 1);
        if(descriptions[descriptions_count])
        {
            strcpy(descriptions[descriptions_count], descriptions_linhas);
            descriptions_count++;
        }
    }

    while(fgets(locals_linhas, sizeof(locals_linhas), localsFile))
    {
        locals[locals_count] = malloc(strlen(locals_linhas) + 1);
        if(locals[locals_count])
        {
            strcpy(locals[locals_count], locals_linhas);
            locals_count++;
        }
    }

    if(descriptions_count != 0 && locals_count != 0)
    {
        int description_choice = rand() % descriptions_count;
        int locals_choice = rand() % locals_count;
        int level_choice = (rand() % 10) + 1;

        mission->description = descriptions[description_choice];
        mission->local = locals[locals_choice];
        mission->level = level_choice;
    }

    return mission;
}

void missionPreparation(struct Mission* mission)
{
    cleanTerminal();
    char choice;

    printf("\n== MISSION ==\n");
    printf("Local: %s\n", mission->local);            
    printf("Description: %s", mission->description);
    printf("Level: %d\n", mission->level);
    printf("\nAre you want go to the arsenal before the mission [Y/N] or press [ESC] to go back:\n\n");
    choice = getChoice('n', 'y');
    if(choice == 'y'){
        cleanTerminal();
        arsenal();
    }else{
        //battle();
        printf("indo para batalha...");
    }

}

void missionPanel()
{
    cleanTerminal();

    while(1) 
    {
        printf("+-----------------------------------------------------------------------+\n");
        printf("|MISSION PANEL                                                          |\n");
        printf("+-----------------------------------------------------------------------+\n\n");

        if (Panel->size == 0) {
            printf("Sorry, but we don't have any mission... 🐢\n");
            printf("\nPress [ESC] to go back.\n");
            char c;
            do{
                c = getch();
            }while(c != 27);
            back();
            return;
        }

        showMissions();
        printf("\n\nSelect a mission to begin or press [ESC] to go back: ");

        // Loop para garantir que o usuário insere uma escolha válida
        char choice_char = getChoice('0', '9');

        if (choice_char == 27) {
            back(); // Chama a função para voltar
            return; // Retorna da função missionPanel
        }

        int choice_int = choice_char - '0';

        if (choice_int >= 0 && choice_int < Panel->size) {
            // A escolha é válida, então prossiga para a batalha
            selectMission(choice_int);
            missionPreparation(&Panel->array[choice_int]);
            // Após a batalha e a exclusão da missão, saia do loop
            return;
        } else {
            // A escolha é inválida, imprime um erro e o loop recomeça
            printf("\nInvalid mission index! Please try again.\n");
            Sleep(1);
            cleanTerminal();
            missionPanel();
        }
    }

}

void createPanel(){
    Panel = createHeap(10);
}

int addMissionToPanel(){

    Mission* mission = createMission(LOCALS_PATH, DESCRIPTIONS_PATH);

    if(Panel->size < Panel->capacity)
    {
        if(mission != NULL && (mission->description != NULL || mission->local != NULL))
        {
            insertHeap(Panel, mission);
            return Panel->size;
        }
    }
    else
    {
        printf("Error creating mission. Not adding to Panel.\n");
        if(mission != NULL)
        {
            free(mission);
        }
    }

    return numMissions;
}

void showMissions(){
    printHeap(Panel);
}

void selectMission(int choiceMission){

    while(1)
    {
        if(choiceMission < 0 || choiceMission >= Panel->size)
        {
            printf("\nInvalid mission index!\n");
        }
        break;
    }
    battle(Panel->array[choiceMission]);
    deleteKey(Panel, choiceMission);
}

void battle(struct Mission mission){
    cleanTerminal();
    printf("\nin working...\n\n");
}

void arsenal(){
    cleanTerminal();

    printf("+-----------------------------------------------------------------------+\n");
    printf("|ARSENAL AND THE ACTION PLAN                                            |\n");
    printf("+-----------------------------------------------------------------------+\n\n");
    printf("\n[ESC] Back\n");

    printf("\n~Turtles~:\n");
    print_list_character(character_list);

    printf("\n");
    print_list_weapon(weapon_list);

    printf("\nYour team:\n");
    printf("--------------------\n");
    print_list_team(team);
    printf("--------------------\n");

    printf("\nWould you like to organize your team? [Y/N] ");
    char choice = getChoice('n','y');
    
    if(choice == 'y'){
        change_team();
    }else{
        commandCentral();
    }
}

void villain_database(){
    
    cleanTerminal();
        
    printf("+-----------------------------------------------------------------------+\n");
    printf("|VILLAINS DATABASE                                                      |\n");
    printf("+-----------------------------------------------------------------------+\n\n");
    printf("\n[ESC] Back\n");

    printf("\n\033[95mDonatello\033[0m: This is our villains archive!! Here you can search for a specific villain."); 
    printf("\nAnd of course, you can add new ones if needed!!\n");

    printf("\n[1] - Search for a villain.\n");
    printf("[2] - Add new villain.\n");

    char choice_module = getChoice('1', '2');

    if(choice_module == '1'){
        cleanTerminal();
        search_villain();
        villain_database();        
    }else if(choice_module == '2'){
        cleanTerminal();
        add_villain();
        villain_database();
    }
   
    back();
}

int main(){
    
    srand(time(NULL));
    initialize_team();
    getting_weapon_from_file(&weapon_list);
    getting_characters_from_file(&character_list);
    get_villains_from_file(&villains);
    cleanTerminal(); 
    //introduction();

    commandCentral();
    

    

    return 0;
}