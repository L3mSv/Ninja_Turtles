#ifndef row_h
#define row_h

typedef struct Node{
    int data;
    struct Node *next;
 }node;

void addnode_to_row(node **row, int n);
void printrow(node *row);
void freerow(node **row);
void remove_from_row(node **row);

#endif