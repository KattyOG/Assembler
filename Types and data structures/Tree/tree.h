#ifndef FUNCS_H
#define FUNCS_H
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int field;
    struct node *left;
    struct node *right;
}node_struct;

node_struct* find_node(node_struct *head, int key, int *count);
node_struct* add_node(node_struct *head, node_struct *new_node, int type);
node_struct *create_node(int elem);
node_struct* rotateright(node_struct* p);
node_struct* rotateleft(node_struct* q);
int bfactor(node_struct* head);
node_struct* balance(node_struct* p);
void walk_req(node_struct *head, FILE *f, node_struct* pointer);
void walk_tree(node_struct *head, node_struct* pointer);
void free_tree(node_struct *head);
void inorder(node_struct *p);
void preorder(node_struct *p);
void postorder(node_struct *p);

#endif // FUNCS_H
