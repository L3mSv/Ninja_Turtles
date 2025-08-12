#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../bibliotecas/arvore.h"
#undef max

/*
A arvore servira para armazenar os viloes, ranqueando-os por nivel
to fazendo ainda, n passei tudo
*/

int height(AVL *node){// isso é pra altura de um nodo, -1 se nulo
    if(!node) return -1;

    return node->height;
}

int max(int a, int b){
    return(a > b) ? a : b;
}

void update_height(AVL* node) {
    node->height = 1 + max(height(node->left), height(node->right));
}

int balancing_test(AVL* node) {
    return height(node->right) - height(node->left);
}

AVL *left_rotation(AVL* x) {
    AVL* y = x->right;
    x->right = y->left;
    y->left = x;
    update_height(x);
    update_height(y);
    return y;
}

AVL* right_rotation(AVL* y) {
    AVL* x = y->left;
    y->left = x->right;
    x->right = y;
    update_height(y);
    update_height(x);
    return x;
}

AVL* balancing(AVL* node) {
    update_height(node);
    int flag = balancing_test(node);

    if (flag > 1) {
        if (balancing_test(node->right) < 0)
            node->right = right_rotation(node->right);
        return left_rotation(node);
    }
    if (flag < -1) {
        if (balancing_test(node->left) > 0)
            node->left = left_rotation(node->left);
        return right_rotation(node);
    }

    return node; // já balanceado
}

AVL* create_node(char *name, int level, char* wkp){
    AVL *newnode = (AVL*)malloc(sizeof(AVL));
    if(!newnode){
        printf("Error Alocating memory for tree's node.\n");
        return NULL;
    }
    newnode->name = (char*)malloc(strlen(name) + 1);
    if(!newnode->name){
        printf("Error alocating memory for newnode's name.\n");
        return NULL;
    }
    strcpy(newnode->name, name);
    newnode->wkp = (char*)malloc(strlen(wkp) + 1);
    if(!newnode->wkp){
        printf("Error alocating memory for weak point.\n");
        return NULL;
    }
    strcpy(newnode->wkp, wkp);
    newnode->level = level;
    newnode->right = newnode->left = NULL;
    newnode->height = 0;

    return newnode;
}

AVL* insert_node(AVL *root, char *name, int level, char *wkp){
    if(!root){
        return create_node(name, level, wkp);
    }

    if(strcmp(root->name, name) > 0){
        root->left = insert_node(root->left, name, level, wkp);
    }else 
    if(strcmp(root->name, name) < 0){
        root->right = insert_node(root->right, name, level, wkp);
    }else{
        return root;
    }

    root = balancing(root);

    return root;
}

AVL* search(AVL* root, char name[]){
    if(!root){
        return NULL;
    }

    if(strcmp(root->name, name) == 0){
        return root;
    }
    else if(strcmp(root->name, name) > 0){
        return search(root->left, name);
    }
    else{
        return search(root->right, name);
    }
}

AVL* minValueNode(AVL* node){
    AVL* temp = node;

    while(temp->left){
        temp = temp->left;
    }
    return temp;
}

AVL* remove_AVL_node(AVL *root, char* name){

    if(strcmp(name, root->name) < 0){
        root->left = remove_AVL_node(root->left, name);
    }else if(strcmp(name, root->name) > 0){
        root->right = remove_AVL_node(root->right, name);
    }else{ 
        //nodo encontrado
        if(root->left == NULL || root->right == NULL){
            AVL* temp = NULL;
            if(root->left){
                temp = root->left;
            }else{
                temp = root->right;
            }

            if(!temp){ //sem fulhos
                temp = root;
                root = NULL;
            }else{ // um filho
                *root = *temp;
            }
            free(temp);
        } else{
            AVL* temp = minValueNode(root->right);
            strcpy(root->name, temp->name);
            root->right = remove_AVL_node(root->right, temp->name);
        }
    }
    
    
    if(!root){
        return root;
    }
    
    update_height(root);
    balancing(root);

    return root;
}
