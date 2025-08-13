#ifndef linked_list_h
#define linked_list_h

typedef struct Node_character{
    char* name;
    char* status;
    float level;
    int rounds_injured;
    struct Node_character *next;
}Character;

typedef struct Node_weapon{
    char* name;
    struct Node_weapon *next;
}Weapon;

typedef struct Node_team{
    char* name, *status, *weapon;
    float level;
    int rounds_injured;
    struct Node_team *next;
}Team;
//extern node* character_list;
//extern node* weapon_list;

void createList_character(Character **head);
void createList_weapon(Weapon **head);
int find_character_index_by_name(Character *head, const char *name);
void add_node_character(Character **head, char* name, char* status, float level);
void add_node_character_index(Character **head, char* name, char* status, float level, int index);
void add_node_weapon(Weapon **head, char* name);
void add_to_team(Team **head, char* name, char* status, char* weapon, float level);
void add_to_team_index(Team **head, char* name, char* status, char* weapon, float level, int index);
void print_list_character(Character *head);
void print_list_weapon(Weapon *head);
void print_list_team(Team *head);
void remove_character_by_name(Character **head, char* name);
void remove_weapon(Weapon **head, char* name);
void remove_from_team(Team **head, char *name);
void free_list_character(Character **head);
void free_list_weapon(Weapon **head);
void free_list_team(Team **head);

//void remove_node_by_index(node **head, int index); //acho que essas duas não vao ser necessarias
//void remove_node_by_value(node **head, const char* n);

#endif