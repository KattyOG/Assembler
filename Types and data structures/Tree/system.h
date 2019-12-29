#include "hash.h"
#ifndef SYSTEM_H
#define SYSTEM_H

void print_tree();
void print_balanced_tree();
void find_in_balanced_tree(int *count_compare_ddp);
void find_in_tree(int *count_compare_ddp);
void create_hash_tables(int *size, int *key, int *max, int *array, node_struct_hash **array_op);

#endif // SYSTEM_H
