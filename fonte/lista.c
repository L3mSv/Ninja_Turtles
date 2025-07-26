 #include <stdio.h>
 #include <stdlib.h>

 typedef struct Node{
    int data;
    struct Node *next;
 }node;

 void add_node(node **head, int n){
    node *newnode = (node*)malloc(sizeof(node));
    
    if(!newnode){
        printf("Erro ao alocar memória para newnode./n");
        return;
    }

    newnode->data = n;
    newnode->next = NULL;

    if(!(*head)){
        *head = newnode;
        return;
    }
    node *temp = *head;
    while(!temp->next){
        temp = temp->next;
    }
    temp = newnode;
    return;
 }

 void print_list(node *head){
    if(!head){
        printf("Error, head is NULL\n");
        return;
    }
    while(head){
        printf("[%d]->", head->data);
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
    while(i < index - 1){
        temp = temp->next;
    }
    node *temp2 = temp->next;
    temp->next = temp->next->next;
    free(temp2);

    return;
}

void remove_node_by_value(node **head, int n){ // removes all nodes that contain that specified value
    if(!(*head)) return;

    node *temp = *head;
    int *indexes = (int*)malloc(sizeof(int)); // array to store the indexes that the number appears
    int j = 0, i = 0; //counters: j=generic index ; i=size of the vector

    while(temp->next){
        if(temp->data == n){
            i++;
            realloc(indexes, i*sizeof(int));
            indexes[i] = j;
        }
        temp = temp->next;
        j++;
    }
    for(int k = 0; k < i; k++){
        remove_node_by_index(head, indexes[i]);
    }
}