#ifndef HASH_H
#define HASH_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

typedef struct node_h {
    int value;
    struct node_h *next;
}  node_struct_hash;

int hash_func(int elem, int size);
int len(node_struct_hash* head);
void create_table(node_struct_hash ***array_op, int *size, int *max);
void insert_node(node_struct_hash **head, node_struct_hash *node);
node_struct_hash* create_hash_node(int value);
int insert_open_hash_table(node_struct_hash ***array, size_t size, int max);
void print_open_hash_table(node_struct_hash **array, int size);
void free_open_table(node_struct_hash **array, size_t size);
int find_num_in_open_hash_table(node_struct_hash **array, int size, int value, int *count);

#endif // HASH_H
