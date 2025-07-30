#ifndef linked_list_h
#define linked_list_h

typedef struct Node{
    int data;
    struct Node *next;
 }node;

void add_node(node **head, int n);
void print_list(node *head);
void free_list(node **head);
void remove_node_by_index(node **head, int index);
void remove_node_by_value(node **head, int n);

#endif