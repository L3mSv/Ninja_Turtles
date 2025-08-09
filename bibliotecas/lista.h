#ifndef linked_list_h
#define linked_list_h

typedef struct Node_character{
    char* name;
    char* status;
    int level;
    struct Node *next;
}Character;

typedef struct Node_weapon{
    char* name;
    struct Node *next;
}Weapon;
//extern node* character_list;
//extern node* weapon_list;

void createList_character(Character **head);
void createList_weapon(Weapon **head);
void add_node_character(Character **head, char* name, char* status, int level);
void add_node_weapon(Weapon **head, char* name);
void print_list_character(Character *head);
void print_list_weapon(Weapon *head);
void free_list_character(Character **head);
void free_list_weapon(Weapon **head);
//void remove_node_by_index(node **head, int index); //acho que essas duas não vao ser necessarias
//void remove_node_by_value(node **head, const char* n);

#endif