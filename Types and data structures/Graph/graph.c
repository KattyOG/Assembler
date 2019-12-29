#include "graph.h"

int init_matrix(int ***matrix, int row, int column)
{
    *matrix = malloc((size_t)row * sizeof(int*));
    for (int i = 0; i < row; i++)
    {
        (*matrix)[i] = malloc((size_t)column * sizeof(int));
        if ((*matrix)[i] == NULL)
            return EXIT_FAILURE;
    }
    if ((*matrix) == NULL)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int scanf_matrix(int **matrix, int row, int column, FILE *file)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (fscanf(file, "%d", &(matrix[i][j])) != 1)
                return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}

void print_matrix(int **matrix, int row, int column)
{
    FILE* f = fopen("input.dot", "w");
    fprintf(f,  "graph { \n\trankdir=LR; \n");
    for (int i = 0; i < column; i++) {
        int count = 0;
        for (int j = 0; j < row; j++) {
            if (matrix[j][i] == 1 && count == 0){
                fprintf(f, "\t%d -- ", j+1);
                count++;
            }
            else if (matrix[j][i] == 1 && count == 1)
            {
                fprintf(f, " %d[label=%d]\n", j+1, i+1);
            }
        }
    }
    fprintf(f, "}\n");
    fclose(f);
    system("dot -Tpng input.dot > output.png");
    system("xviewer output.png ");
}

void join_edge(int ***matrix, int *column, int *row, int first, int second)
{
    if (first == second) {
        return;
    }
        for (int i = 0; i < *column; i++)
        {
                if ((*matrix)[second][i] && (*matrix)[first][i]) {
                    for (int j = 0; j < *column; j++)
                    {
                            if ((*matrix)[second][j] && (*matrix)[first][j]) {
                                (*matrix)[second][j] = 0;
                            }
                            else {
                            (*matrix)[second][j] = (*matrix)[first][j] || (*matrix)[second][j];
                            }
                    }

                    delete_row(matrix, row, first);
                    break;
                }
        }
}

void delete_row(int ***matrix, int *row, int num_row)
{
    free((*matrix)[num_row]);
    for (int i = num_row; i < *row -1; i++)
    {
        (*matrix)[i] = (*matrix)[i+1];
    }
    *row = *row - 1;
    (*matrix) = realloc((*matrix), (size_t)(*row) * sizeof(long long *));
}

void free_matrix(int ***matrix, int row)
{
    for (int i = 0; i < row; i++)
    {
        free((*matrix)[i]);
    }
    free((*matrix));
}

