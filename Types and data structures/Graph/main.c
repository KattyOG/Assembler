#include "graph.h"
#include <time.h>
int main()
{
    srand((unsigned int) time(NULL));
    FILE *file;
    int *array = NULL;
    int **matrix = NULL;
    int row;
    int column;


    file = fopen("in.txt", "r");
    if (fscanf(file, "%d", &row) != 1)
        return EXIT_FAILURE;
    if (fscanf(file, "%d", &column) != 1)
        return EXIT_FAILURE;

    init_matrix(&matrix, row, column);
    scanf_matrix(matrix, row, column, file);
    //    print_matrix(matrix, row, column, array);
    fclose(file);
    free_matrix(&matrix, row);
    matrix = NULL;

    int min[column];

    for (int i = 0; i < column; i++) {
        min[i] = 1;
    }

    int min_count = column;

    for (int c = 0; c < 100; c++) {
        file = fopen("in.txt", "r");
        if (fscanf(file, "%d", &row) != 1)
            return EXIT_FAILURE;
        if (fscanf(file, "%d", &column) != 1)
            return EXIT_FAILURE;

        init_matrix(&matrix, row, column);
        scanf_matrix(matrix, row, column, file);
        fclose(file);



//        printf("\nTRY %d:\n", c+1);
        printf("\n");
        while (row != 2) {
            join_edge(&matrix, &column, &row, rand()%row , rand()%row);
        }


//        print_matrix(matrix, row, column, array);

        int temp = 0;
        for (int z = 0; z < column; z++) {
            if (matrix[0][z] == 1) {
                temp++;
            }
        }

        if (temp <= min_count) {
            min_count = temp;
            for (int z = 0; z < column; z++) {
                if (matrix[0][z] == 1) {
                    min[z] = 1;
                }
                else {
                    min[z] = 0;
                }
            }
        }
        printf("To delete: ");
        for (int i = 0; i < column; i++) {
            if (min[i] == 1) {
                printf("%d ", i+1);
            }
        }
        free_matrix(&matrix, row);
        matrix = NULL;
    }

    printf("\nFinish result minimum to delete: ");
    for (int i = 0; i < column; i++) {
        if (min[i] == 1) {
            printf("%d ", i+1);
        }
    }
    printf("\n");
    file = fopen("in.txt", "r");
    if (fscanf(file, "%d", &row) != 1)
        return EXIT_FAILURE;
    if (fscanf(file, "%d", &column) != 1)
        return EXIT_FAILURE;

    init_matrix(&matrix, row, column);
    scanf_matrix(matrix, row, column, file);
    fclose(file);
    print_matrix(matrix, row, column);
    free_matrix(&matrix, row);
    matrix = NULL;
    return EXIT_SUCCESS;
}
