#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <time.h>
#include <unistd.h> //Para sleep no Linux
#include <windows.h> //Para sleep no Windows
#include <ctype.h>
#include <conio.h> // Para getch() no Windows
#include "bibliotecas/pilha.h"
#include "utils/utils.h"
#include "bibliotecas/heap.h"
#include "jogo.h"

const char* DESCRIPTIONS_PATH = "descriptions.txt";
const char* LOCALS_PATH = "locals.txt";


// Função para aceitar apenas 'y' ou 'n' (minúsculo), sem ecoar na tela
char getYN() {
    char c;
    while (1) {
        c = getch();
        c = tolower(c);
        if (c == 'y' || c == 'n') {
            printf("%c\n", c); // Mostra a escolha do usuário
            return c;
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
    printf("-- Command Central --\n\n");
    printf("[1]. Mission Alerts Panel\n");
    printf("[2]. Villains DataBase\n");
    printf("[3]. Master Splinter's Logbook\n");
    printf("[4]. Arsenal and the Action Plan\n\n");
}

void introduction()
{
    print_lento
    ("\033[31mA cidade de Nova York esta um caos\033[0m!\n"
    " O Destruidor e Krang uniram forcas, e o Cla do Pe, junto com mutantes como Bebop" 
    "e Rocksteady, estao executando varios planos malignos ao mesmo tempo.\n"
    "As Tartarugas Ninja estao sobrecarregadas, para organizar a defesa da cidade, Donatello" 
    " decidiu criar um sistema de computador avancado, a \033[1m\"Central de Comando\"\033[0m,\n" 
    "para gerenciar as missoes, catalogar os viloes e otimizar as operacoes do time.\n"
    "\nSua missao e ajudar as Tartarugas Ninja a combater o mal sobre Nova York e restaurar a" 
    " paz atraves de ordens pela Central de Comando. \033[33mBoa sorte\033[0m\n" , 100);

    sleep(3);
    cleanTerminal();

    sleep(8);

    printf("\n\033[95mDonatello\033[0m: Hey, thanks god you got the Command Central and in the best time, things around here are not very good.\n");

    sleep(5);

    printf("\n\033[95mDonatello\033[0m: While me and my brothers were in a special mission New York was ruined, There are villians all places!\n");

    sleep(5);

    printf("\n\033[95mDonatello\033[0m: We are going to Sewer Liar to see if is okay.\n");

    sleep(5);

    printf("\n\033[95mDonatello\033[0m: Are you want join to us?");
    printf("\nGo to Tutorial: [Y] yes | [N] no ");

    char tutorialChoice = getYN();
    if (tutorialChoice == 'y') {
        tutorial();
    } else {
        printf("\n\033[95mDonatello\033[0m: So, see you later!\n");
        sleep(3);
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
        srand(time(NULL));
        int description_choice = rand() % descriptions_count;
        int locals_choice = rand() % locals_count;
        int level_choice = (rand() % 10) + 1;

        mission->description = descriptions[description_choice];
        mission->local = locals[locals_choice];
        mission->level = level_choice;
    }

    return mission;
}

void missionPanel()
{
    cleanTerminal();

    int missions_count = 0;

    Mission* mission = (Mission*) malloc(sizeof(Mission));
    mission = createMission(LOCALS_PATH, DESCRIPTIONS_PATH);
    missions_count++;

    printf("+-----------------------------------------------------------------------+\n");
    printf("|MISSION PANEL                                                          |\n");

    if(missions_count == 0)
    {
        printf("+-----------------------------------------------------------------------+\n");
        printf("|Sorry, but we don't have any mission... 🐢                             |\n");
        printf("+-----------------------------------------------------------------------+\n");
    }
    else
    {
        printf("+-----------------------------------------------------------------------+\n");
        printf("|                                                                       |\n");
        printf(" [%d]                                                                      \n", missions_count);
        printf(" Local: %s                                                                 \n", mission->local);
        printf(" Description: %s                                                           \n", mission->description);
        printf(" Level: %d                                                                 \n", mission->level);
        printf("|                                                                       |\n");
        printf("+-----------------------------------------------------------------------+\n");       
    }


}

int main(){

    cleanTerminal();

    missionPanel();
    return 0;
}