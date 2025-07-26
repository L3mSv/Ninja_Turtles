 #include <stdio.h>
 #include <stdlib.h>

 typedef struct Node{
    int data;
    struct Node *next;
 }node;

 void addnode(node **list, int n){
    node *newnode = (node*)malloc(sizeof(node));
    
    if(!newnode){
        printf("Erro ao alocar memória para newnode./n");
        return;
    }

    newnode->data = n;
    newnode->next = NULL;

    if(!(*list)){
        *list = newnode;
        return;
    }
    node *temp = *list;
    while(!temp->next){
        temp = temp->next;
    }
    temp = newnode;
    return;
 }

 void printlist(node *list){
    if(!list){
        printf("Error, list is NULL\n");
        return;
    }
    while(list){
        printf("[%d]->", list->data);
        list = list->next;
    }
    printf("[NULL]\n");
    return;
 }

 void freelist(node **list){
    if(*list == NULL) return;

    node *temp;

    while(*list != NULL){
        temp = *list;
        *list = (*list)->next;
        free(temp);
    }
    return;
}