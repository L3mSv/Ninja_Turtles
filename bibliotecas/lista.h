#ifndef linked_list_h
#define linked_list_h

typedef struct Node{
    const char* data;
    struct Node *next;
}node;

extern node* turtle_list;
extern node* weapon_list;

void createList(node **head);
void add_node(node **head, const char* n);
void print_list(node *head);
void free_list(node **head);
void remove_node_by_index(node **head, int index);
void remove_node_by_value(node **head, const char* n);

#endif