#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "villains.h"
#include "utils/utils.h"
#include "bibliotecas/arvore.h"

extern AVL* villains;

void get_villains_from_file(AVL **root){
    FILE *file1 = fopen("villains.txt", "r");
        if(!file1){
            perror("fopen");
            return;
        }
     
    char name_buffer[100], wkp_buffer[100];
    int level_buffer;

    while(fscanf(file1, "\n%99[^,], %d, %99[^\n]", name_buffer, &level_buffer, wkp_buffer) == 3){

        wkp_buffer[strcspn(wkp_buffer, "\n")] = '\0'; //apenas certificando que não vai ter um "\n" ao final da descrição

        *root = insert_node(*root, name_buffer, level_buffer, wkp_buffer);
    }
        fclose(file1);
    return;
}

void add_villain(){
    char villain_name_buffer[50], weak_point_buffer[100], level_buffer[10];;
    int level;

    printf("---------------------------\n");
    printf("Add the new villain:\n");
    printf("---------------------------\n");
    printf("-Name of the villain: ");
        fgets(villain_name_buffer, 50, stdin);
        villain_name_buffer[strcspn(villain_name_buffer, "\n")] = '\0';
    printf("-Threat level: ");
        fgets(level_buffer, 10, stdin); // tive de usar o fgets, o scanf tava dando problema com o "\n" na hora de ler a fraqueza do vilão
        sscanf(level_buffer, "%d", &level); //o sscanf é pra ler dados de uma string, no caso o "level_buffer" que vai ter o numero e o "\n"

    printf("-Villain's weak point: ");
        fgets(weak_point_buffer, 100, stdin);
        weak_point_buffer[strcspn(weak_point_buffer, "\n")] = '\0';

    printf("Adding your villain ");
    print_lento(". . . ", 500);

    villains = insert_node(villains, villain_name_buffer, level, weak_point_buffer);

    return;    
}

void search_villain(){
    char villain_name[50];

    if(!villains){
        printf("No villain have being registered yet");
        return;
    }
    
    printf("Enter the name of the villain you want to search for: ");
        fgets(villain_name, 50, stdin);
        villain_name[strcspn(villain_name, "\n")] = '\0';
    
    AVL *temp = search(villains, villain_name);
    
    if(!temp){
        printf("Villain not found.\n");
        printf("Press any key to proceed.\n");
        char c = getch();
        c++; //coloquei essa operação aqui só pro programa compilar, ele tava dizendo que c não estava sendo usado.
        
        return;
    }else{
        printf("Villain found!\n");
        printf("Name: %s\n", temp->name);
        printf("Threat level: %d\n", temp->level);
        printf("Weakness: %s\n", temp->wkp);

        printf("Press any key to proceed.\n");
        char c = getch();
        c++;//coloquei essa operação aqui só pro programa compilar, ele tava dizendo que c não estava sendo usado.

        return;
    }
}