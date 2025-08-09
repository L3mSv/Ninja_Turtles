 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include "../bibliotecas/lista.h"

 //node* character_list;
 //node* weapon_list; 

 void createList_weapon(Weapon** head){
    *head = NULL;
 }

 void createList_character(Character** head){
    *head = NULL;
 }

 void add_node_character(Character **head, char* name, char* status, int level){
    Character *newnode = (Character*)malloc(sizeof(Character));
    
    if(!newnode){
        printf("Erro ao alocar memória para newnode.\n");
        return;
    }

    newnode->name = (char*)malloc(strlen(name) + 1);
    if(!newnode->name){
        printf("Error alocating memory for newnode's name.\n");
        return;
    }
    strcpy(newnode->name, name);

    newnode->status = (char*)malloc(strlen(status) + 1);
    if(!newnode->status){
        printf("Error alocating memory for newnode's status.\n");
        return;
    }
    strcpy(newnode->status, status);

    newnode->level = level;
    newnode->next = NULL;

    if(!(*head)){
        *head = newnode;
        return;
    }
    Character *temp = *head;

    while(temp->next){
        temp = temp->next;
    }
    temp->next = newnode;
    return;
 }

 void add_node_weapon(Weapon **head, char* name){
    Weapon *newnode = (Weapon*)malloc(sizeof(Weapon));
    
    if(!newnode){
        printf("Erro ao alocar memória para newnode.\n");
        return;
    }

    newnode->name = (char*)malloc(strlen(name) + 1);
    if(!newnode->name){
        printf("Error alocating memory for newnode's name.\n");
        return;
    }
    strcpy(newnode->name, name);
    newnode->next = NULL;

    if(!(*head)){
        *head = newnode;
        return;
    }
    Weapon *temp = *head;

    while(temp->next){
        temp = temp->next;
    }
    temp->next = newnode;
    return;
 }

 void add_to_team(Team **head, char* name, char* status, char* weapon, int level){
    Team *newnode = (Team*)malloc(sizeof(Team));
    
    if(!newnode){
        printf("Erro ao alocar memória para newnode.\n");
        return;
    }

    newnode->name = (char*)malloc(strlen(name) + 1);
    if(!newnode->name){
        printf("Error alocating memory for newnode's name.\n");
        return;
    }
    strcpy(newnode->name, name);

    newnode->status = (char*)malloc(strlen(status) + 1);
    if(!newnode->status){
        printf("Error alocating memory for newnode's status.\n");
        return;
    }
    strcpy(newnode->status, status);

    newnode->weapon = (char*)malloc(strlen(weapon) + 1);
    if(!newnode->weapon){
        printf("Error alocating memory for newnode's weapon.\n");
        return;
    }
    strcpy(newnode->weapon, weapon);

    newnode->level = level;
    newnode->next = NULL;

    if(!(*head)){
        *head = newnode;
        return;
    }
    Team *temp = *head;

    while(temp->next){
        temp = temp->next;
    }
    temp->next = newnode;
    return;
 }


 void print_list_character(Character *head){
    if(!head){
        printf("Error, head is NULL\n");
        return;
    }
    int i = 1;
    while(head){
        printf("%d -%s -> Status: %s ; Level: %d\n", i, head->name, head->status, head->level);
        head = head->next;
        i++;
    }

    return;
 }

  void print_list_weapon(Weapon *head){
    if(!head){
        printf("Error, head is NULL\n");
        return;
    }
    printf("Weapons:\n");

    while(head){
        printf("-%s\n", head->name);
        head = head->next;
    }

    return;
 }

 void print_list_team(Team *head){
    if(!head){
        printf("Error, head is NULL\n");
        return;
    }
    int i = 1;
    while(head){
        printf("%d -%s ; Level : %d ; Current status: %s ; Weapon: %s\n", i, head->name, head->level, head->status, head->weapon);
        head = head->next;
        i++;
    }

    return;
 }

 void free_list_character(Character **head){
    if(*head == NULL) return;

    Character *temp;

    while(*head != NULL){
        temp = *head;
        *head = (*head)->next;
        free(temp->name);
        free(temp->status);
        free(temp);
    }
    return;
}

void free_list_weapon(Weapon **head){
    if(*head == NULL) return;

    Weapon *temp;

    while(*head != NULL){
        temp = *head;
        *head = (*head)->next;
        free(temp->name);
        free(temp);
    }
    return;
}

void free_list_team(Team **head){
    if(*head == NULL) return;

    Team *temp;

    while(*head != NULL){
        temp = *head;
        *head = (*head)->next;
        free(temp->name);
        free(temp->status);
        free(temp->weapon);
        free(temp);
    }
    return;
}

void remove_character_by_name(Character **head, char* name){
    if(*head == NULL) return;

    Character *temp = *head;

    if(strcmp(temp->name, name)== 0) {
        Character *old = *head;
        *head = old->next;
        free(old);
        return;
    }

    while(strcmp(temp->name, name) != 0){
        temp = temp->next;
    }
    Character *temp2 = temp->next;
    temp->next = temp->next->next;
    free(temp2->name);
    free(temp2->status);
    free(temp2);

    return;
}

void remove_weapon(Weapon **head, char* name){
    if(*head == NULL) return;

    Weapon *temp = *head;

    if(strcmp(temp->name, name)== 0) {
        Weapon *old = *head;
        *head = old->next;
        free(old);
        return;
    }

    while(strcmp(temp->name, name) != 0){
        temp = temp->next;
    }
    Weapon *temp2 = temp->next;
    temp->next = temp->next->next;
    free(temp2->name);
    free(temp2);

    return;
}

void remove_from_team(Team **head, char* name){
    if(*head == NULL) return;

    Team *temp = *head;

    if(strcmp(temp->name, name)== 0) {
        Team *old = *head;
        *head = old->next;
        free(old->name);
        free(old->status);
        free(old->weapon);
        free(old);
        return;
    }

    while(strcmp(temp->name, name) != 0){
        temp = temp->next;
    }

    Team *temp2 = temp->next;
    temp->next = temp->next->next;
    free(temp2->name);
    free(temp2->status);
    free(temp2);

    return;
}


/* acho que não vão ser necessárias
void remove_node_by_value(node **head, const char* n){ // removes all nodes that contain that specified value
    if(!(*head)) return;

    node *temp = *head;
    int *indexes = NULL;
    int j = 0, i = 0; //counters: j=generic index ; i=size of the vector

    while(temp){
        if(temp->data == n){
            int *tmp = realloc(indexes, (i+1)*sizeof *tmp);
            if (!tmp) {
              free(indexes);
              return;
            }
            indexes = tmp;
            indexes[i] = j;
            i++;
        }
        temp = temp->next;
        j++;
    }
    for(int k = i -1; k >= 0; k--){
        remove_node_by_index(head, indexes[k]);
    }

    free(indexes);

}
*/