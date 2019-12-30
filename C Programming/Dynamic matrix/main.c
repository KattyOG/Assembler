#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "function.h"
#define MAX_SIZE 20

int main()
{
	matrix my_matrix;
	matrix my_matrix2;
	int p, y;

	printf("row = ");
	if (scanf("%d", &(my_matrix.row)) != 1 || my_matrix.row <= 0 || my_matrix.row > MAX_SIZE)
	{
		printf("Input error\n");
		return EXIT_FAILURE;
	}
	printf("column = ");
	if (scanf("%d", &(my_matrix.column)) != 1 || my_matrix.column <= 0 || my_matrix.column > MAX_SIZE)
	{
		printf("Input error\n");
		return EXIT_FAILURE;
	}
	if (init_matrix(&my_matrix) == EXIT_FAILURE)
	{
		free_matrix(&my_matrix);
		return EXIT_FAILURE;
	}
	for (int i = 0; i < my_matrix.row; i++)
	{
		for (int j = 0; j < my_matrix.column; j++)
		{
			printf("Input element: ");
			if (scanf("%lli", &(my_matrix.ptr[i][j])) != 1)
			{
				free_matrix(&my_matrix);
				return EXIT_FAILURE;
			}
		}
	}
	printf("\n");

	if (my_matrix.row > my_matrix.column)
	{
		while (my_matrix.row > my_matrix.column)
		{
			delete_row(&my_matrix, min_in_row_i(&my_matrix));
		}
	}
	else
	{
		while (my_matrix.row < my_matrix.column)
		{
			delete_column(&my_matrix, min_in_row_j(&my_matrix));
		}
	}

	printf("row = ");
	if (scanf("%d", &(my_matrix2.row)) != 1 || my_matrix2.row <= 0 || my_matrix2.row > MAX_SIZE)
	{
		printf("Input error\n");
		free_matrix(&my_matrix);
		return EXIT_FAILURE;
	}
	printf("column = ");
	if (scanf("%d", &(my_matrix2.column)) != 1 || my_matrix2.column <= 0 || my_matrix2.column > MAX_SIZE)
	{
		printf("Input error\n");
		free_matrix(&my_matrix);
		return EXIT_FAILURE;
	}
	if (init_matrix(&my_matrix2) == EXIT_FAILURE)
	{
		free_matrix(&my_matrix);
		free_matrix(&my_matrix2);
		return EXIT_FAILURE;
	}
	for (int i = 0; i < my_matrix2.row; i++)
	{
		for (int j = 0; j < my_matrix2.column; j++)
		{
			printf("Input element: ");
			if (scanf("%lli", &(my_matrix2.ptr[i][j])) != 1)
			{
				free_matrix(&my_matrix);
				free_matrix(&my_matrix2);
				return EXIT_FAILURE;
			}
		}
	}

	if (my_matrix2.row > my_matrix2.column)
	{
		while (my_matrix2.row > my_matrix2.column)
		{
			delete_row(&my_matrix2, min_in_row_i(&my_matrix2));
		}
	}
	else
	{
		while (my_matrix2.row < my_matrix2.column)
		{
			delete_column(&my_matrix2, min_in_row_j(&my_matrix2));
		}
	}

	int temp = fmax(my_matrix.row, my_matrix2.row);
	while (temp > my_matrix.row)
		add_row(&my_matrix, (my_matrix.row - 1));
	while (temp > my_matrix.column)
		add_column(&my_matrix, (my_matrix.column - 1));
	while (temp > my_matrix2.row)
		add_row(&my_matrix2, (my_matrix2.row - 1));
	while (temp > my_matrix2.column)
		add_column(&my_matrix2, (my_matrix2.column - 1));

	printf("p = ");
	if (scanf("%d", &p) != 1 || p < 0 || p > MAX_SIZE)
	{
		free_matrix(&my_matrix);
		free_matrix(&my_matrix2);
		return EXIT_FAILURE;
	}
	printf("y = ");
	if (scanf("%d", &y) != 1 || y < 0 || y > MAX_SIZE)
	{
		free_matrix(&my_matrix);
		free_matrix(&my_matrix2);
		return EXIT_FAILURE;
	}
	power_matrix(&my_matrix, p);
	power_matrix(&my_matrix2, y);
	multip_matrix(&my_matrix, &my_matrix2);
	printf("Multiplication matrix\n");
	print_matrix(my_matrix);
	free_matrix(&my_matrix2);
	free_matrix(&my_matrix);
}
