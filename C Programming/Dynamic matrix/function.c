#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "function.h"
#define MAX_SIZE 50

int init_matrix(matrix *my_matrix)
{
	my_matrix->ptr = malloc(my_matrix->row * sizeof(long long int *));
	for (int i = 0; i < my_matrix->row; i++)
	{
		my_matrix->ptr[i] = malloc(my_matrix->column * sizeof(long long int));
		if (my_matrix->ptr[i] == NULL)
			return EXIT_FAILURE;
	}
	if (my_matrix->ptr == NULL)
		return EXIT_FAILURE;
	return EXIT_SUCCESS;
}

void free_matrix(matrix *my_matrix)
{
	for (int i = 0; i < my_matrix->row; i++)
	{
		free(my_matrix->ptr[i]);
	}
	free(my_matrix->ptr);
	my_matrix->row = 0;
	my_matrix->column = 0;
}

void print_matrix(matrix my_matrix)
{
	for (int i = 0; i < my_matrix.row; i++)
	{
		for (int j = 0; j < my_matrix.column; j++)
		{
			printf("%lli ", my_matrix.ptr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void delete_row(matrix *my_matrix, int num_row)
{
	for (int i = 0; i < my_matrix->column; i++)
	{
		for (int j = num_row; j < my_matrix->row - 1; j++)
		{
			my_matrix->ptr[j][i] = my_matrix->ptr[j + 1][i];
		}
	}
	free(my_matrix->ptr[my_matrix->row - 1]);
	my_matrix->row = my_matrix->row - 1;
	my_matrix->ptr = realloc(my_matrix->ptr, (my_matrix->row) * sizeof(long long *));
}

void delete_column(matrix *my_matrix, int num_column)
{
	for (int i = 0; i < my_matrix->row; i++)
	{
		for (int j = num_column; j < my_matrix->column - 1; j++)
		{
			my_matrix->ptr[i][j] = my_matrix->ptr[i][j + 1];
		}
		my_matrix->ptr[i] = realloc(my_matrix->ptr[i], (my_matrix->column - 1) * sizeof(long long *));
	}
	my_matrix->column = my_matrix->column - 1;
}
long long int min_row(matrix *my_matrix, int num)
{
	long long int min = my_matrix->ptr[num][0];
	for (int i = 0; i < my_matrix->column; i++)
	{
		if (my_matrix->ptr[num][i] < min)
		{
			min = my_matrix->ptr[num][i];
		}
	}
	return min;
}
void add_column(matrix *my_matrix, int num_column)
{
	for (int i = 0; i < my_matrix->row; i++)
	{
		my_matrix->ptr[i] = realloc(my_matrix->ptr[i], (my_matrix->column + num_column) * sizeof(long long *));
		for (int j = my_matrix->column; j < my_matrix->column + num_column; j++)
		{
			my_matrix->ptr[i][j] = min_row(my_matrix, i);
		}
	}
	my_matrix->column += num_column;
}
int geom_average(matrix *my_matrix, int num)
{
	int multip = 1;
	for (int i = 0; i < my_matrix->row; i++)
	{
		multip *= my_matrix->ptr[i][num];
	}
	return floor(pow(multip, (1.0 / my_matrix->row)));
}
void add_row(matrix *my_matrix, int num_row)
{
	my_matrix->ptr = realloc(my_matrix->ptr, (my_matrix->row + num_row) * sizeof(long long *));
	for (int i = my_matrix->row; i < my_matrix->row + num_row; i++)
	{
		my_matrix->ptr[i] = malloc(my_matrix->column * sizeof(long long int));
		for (int j = 0; j < my_matrix->column; j++)
			my_matrix->ptr[i][j] = geom_average(my_matrix, j);
	}
	my_matrix->row += num_row;
}

int min_in_row_i(matrix *my_matrix)
{
	long long int min = my_matrix->ptr[0][0];
	int temp = 0;
	for (int i = 0; i < my_matrix->row; i++)
	{
		for (int j = 0; j < my_matrix->column; j++)
		{
			if (my_matrix->ptr[i][j] <= min)
			{
				min = my_matrix->ptr[i][j];
				temp = i;
			}
		}
	}
	return temp;
}

int min_in_row_j(matrix *my_matrix)
{
	long long int min = my_matrix->ptr[0][0];
	int temp = 0;
	for (int i = 0; i < my_matrix->row; i++)
	{
		for (int j = 0; j < my_matrix->column; j++)
		{
			if (my_matrix->ptr[i][j] <= min)
			{
				min = my_matrix->ptr[i][j];
				temp = j;
			}
		}
	}
	return temp;
}

void power_matrix(matrix *my_matrix, int pow)
{
	if (pow == 0)
	{
		for (int i = 0; i < my_matrix->row; i++)
		{
			for (int j = 0; j < my_matrix->column; j++)
			{
				if (i == j)
					my_matrix->ptr[i][j] = 1;
				else
					my_matrix->ptr[i][j] = 0;
			}
		}
	}
	long long int **matrix_cp = malloc(my_matrix->row * sizeof(long long int *));
	for (int i = 0; i < my_matrix->row; i++)
	{
		matrix_cp[i] = malloc(my_matrix->column * sizeof(long long int));
		for (int j = 0; j < my_matrix->column; j++)
		{
			matrix_cp[i][j] = my_matrix->ptr[i][j];
		}
	}


	long long int **result = malloc(my_matrix->row * sizeof(long long int *));
	for (int i = 0; i < my_matrix->row; i++)
	{
		result[i] = malloc(my_matrix->column * sizeof(long long int));
	}

	for (int p = 1; p < pow; p++)
	{
		for (int i = 0; i < my_matrix->row; i++)
		{
			for (int j = 0; j < my_matrix->column; j++)
			{
				result[i][j] = 0;
			}
		}

		for (int i = 0; i < my_matrix->row; i++)
		{
			for (int j = 0; j < my_matrix->column; j++)
			{
				for (int k = 0; k < my_matrix->column; k++)
				{
					result[i][j] += matrix_cp[i][k] * my_matrix->ptr[k][j];
				}
			}
		}
		for (int i = 0; i < my_matrix->row; i++)
		{
			for (int j = 0; j < my_matrix->column; j++)
			{
				my_matrix->ptr[i][j] = result[i][j];
			}
		}
	}
	for (int i = 0; i < my_matrix->row; i++)
		free(matrix_cp[i]);
	free(matrix_cp);
	for (int i = 0; i < my_matrix->row; i++)
		free(result[i]);
	free(result);
}
void multip_matrix(matrix *my_matrix, matrix *my_matrix2)
{
	long long int **matrix_cp = malloc(my_matrix->row * sizeof(long long int *));
	for (int i = 0; i < my_matrix->row; i++)
	{
		matrix_cp[i] = malloc(my_matrix->column * sizeof(long long int));
		for (int j = 0; j < my_matrix->column; j++)
		{
			matrix_cp[i][j] = 0;
		}
	}
	for (int i = 0; i < my_matrix->row; i++)
	{
		for (int j = 0; j < my_matrix->column; j++)
		{
			for (int k = 0; k < my_matrix->column; k++)
			{
				matrix_cp[i][j] += my_matrix->ptr[i][k] * my_matrix2->ptr[k][j];
			}
		}
	}
	for (int i = 0; i < my_matrix->row; i++)
	{
		for (int j = 0; j < my_matrix->column; j++)
		{
			my_matrix->ptr[i][j] = matrix_cp[i][j];
		}
	}
	for (int i = 0; i < my_matrix->row; i++)
		free(matrix_cp[i]);
	free(matrix_cp);
}
