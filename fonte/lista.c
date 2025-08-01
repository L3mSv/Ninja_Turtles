 #include <stdio.h>
 #include <stdlib.h>
 #include "../bibliotecas/lista.h"

 node* character_list;
 node* weapon_list; 

 void createList(node** head){
    head = NULL;
 }

 void add_node(node **head, const char* n){
    node *newnode = (node*)malloc(sizeof(node));
    
    if(!newnode){
        printf("Erro ao alocar memória para newnode.\n");
        return;
    }

    newnode->data = n;
    newnode->next = NULL;

    if(!(*head)){
        *head = newnode;
        return;
    }
    node *temp = *head;

    while(temp->next){
        temp = temp->next;
    }
    temp->next = newnode;
    return;
 }

 void print_list(node *head){
    if(!head){
        printf("Error, head is NULL\n");
        return;
    }
    while(head){
        printf("[%s]->", head->data);
        head = head->next;
    }
    printf("[NULL]\n");
    return;
 }

 void free_list(node **head){
    if(*head == NULL) return;

    node *temp;

    while(*head != NULL){
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    return;
}

void remove_node_by_index(node **head, int index){
    if(*head == NULL) return;

    node *temp = *head;
    int i = 0;

    if (index == 0) {
        node *old = *head;
        *head = old->next;
        free(old);
        return;
    }

    while(i < index - 1 && temp->next){
        temp = temp->next;
        i++;
    }
    node *temp2 = temp->next;
    temp->next = temp->next->next;
    free(temp2);

    return;
}

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