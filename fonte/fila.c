 #include <stdio.h>
 #include <stdlib.h>

 typedef struct Node{
    int data;
    struct Node *next;
 }node;

 void addnode_to_row(node **row, int n){
    node *newnode = (node*)malloc(sizeof(node));
    
    if(!newnode){
        printf("Erro ao alocar memória para newnode./n");
        return;
    }
    node *temp = *row;
    newnode->data = n;
    newnode->next = temp;
    (*row) = newnode;

    return;
 }

 void printrow(node *row){
    if(!row){
        printf("Error, row is NULL\n");
        return;
    }
    while(row){
        printf("[%d]->", row->data);
        row = row->next;
    }
    printf("[NULL]\n");
    return;
 }

 void freerow(node **row){
    if(*row == NULL) return;

    node *temp;

    while(*row != NULL){
        temp = *row;
        *row = (*row)->next;
        free(temp);
    }
    return;
}

void remove_from_row(node **row){
    node *temp = *row;
    node *aux = NULL;

    while(temp->next->next){
        temp = temp->next;    
    }
    aux = temp->next;
        temp->next = NULL;
        free(aux);
}