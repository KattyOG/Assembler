#ifndef GRAPH_H
#define GRAPH_H
#include <stdio.h>
#include <stdlib.h>

int init_matrix(int ***matrix, int row, int column);
int scanf_matrix(int **matrix, int row, int column, FILE *file);
void print_matrix(int **matrix, int row, int column);
void join_edge(int ***matrix, int *column, int *row, int first, int second);
void delete_row(int ***matrix, int *row, int num_row);
void free_matrix(int ***matrix, int row);
#endif // GRAPH_H
