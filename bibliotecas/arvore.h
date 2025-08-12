#ifndef tree_h
#define tree_h

#undef max
typedef struct node{
    char* name, *wkp;
    int level, height;
    struct node *left, *right;
} AVL;

int height(AVL *node);
int max(int a, int b);
void update_height(AVL* node);
int balancing_test(AVL* node);
AVL *left_rotation(AVL* x);
AVL* right_rotation(AVL* y);
AVL* balancing(AVL* node);
AVL* create_node(char *name, int level, char* wkp);
AVL* insert_node(AVL *root, char *name, int level, char* wkp);
AVL* search(AVL* root, char name[]);
AVL* remove_AVL_node(AVL *root, char* name);


#endif