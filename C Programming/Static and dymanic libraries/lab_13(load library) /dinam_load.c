#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "function.h"

double *my_malloc(int size)
{
	double *array;
	array = (double*)malloc(size * sizeof(double));
	if (array == NULL)
		return NULL;
	return array;
}
double my_average(double *start, double *end)
{
	double temp = 0;
	int len = 0;
	while (start < end)
	{
		temp += *start;
		start++;
		len++;
	}
	temp = temp / len;
	return temp;
}

int delete(double **array, int *size, double average)
{
	int old = *size;
	double max = 0, max_1 = 0;
	int max_i = 0, max_1_i = 0;
	int count_max = 0;
	int count_max_1 = 0;
	for (int i = 0; i < old; i++)
	{
		if ((fabs(average - (*array)[i]) >= max))
		{
			max = fabs(average - (*array)[i]);
			max_i = i;
			count_max++;
		}
	}
	for (int i = 0; i < old; i++)
	{
		if ((fabs(average - (*array)[i]) >= max_1) && (fabs(average - (*array)[i]) <= max) && max_i != i)
		{
			max_1 = fabs(average - (*array)[i]);
			max_1_i = i;
			count_max_1++;
		}
	}
	if (count_max == 0 && count_max_1 == 0)
		return EXIT_FAILURE;
	if (count_max != 0 && count_max_1 != 0)
	{
		for (int i = 0; i < *size; i++)
		{
			if ((i == max_i) || (i == max_1_i))
			{
				for (int j = i; j < (*size) - 1; j++)
				{
					(*array)[j] = (*array)[j + 1];
				}
				max_i--;
				max_1_i--;
				i--;
			}
		}
		*size -= 2;
		*array = realloc(*array, (*size) * sizeof(double));
	}
	if (count_max != 0 && count_max_1 == 0)
	{
		for (int i = 0; i < *size; i++)
		{
			if ((i == max_i))
			{
				for (int j = i; j < (*size) - 1; j++)
				{
					(*array)[j] = (*array)[j + 1];
				}
				max_i--;
				max_1_i--;
				i--;
			}
		}
		*size -= 1;
		*array = realloc(*array, (*size) * sizeof(double));
	}

	if (array == NULL)
		return EXIT_FAILURE;
	return EXIT_SUCCESS;
}

double max_el(double *array, double *start, double *end)
{
	double max_el = array[0];
	for (; start < end; start++)
	{
		if (*start > max_el)
			max_el = *start;
	}
	return max_el;
}

int insert(double **array, int *size, double max_elem, int p, int new_size)
{
	if (p >= *size)
		return EXIT_FAILURE;

	*size += new_size;

	double *temp = realloc(*array, (*size) * sizeof(double));

	if (temp == NULL)
		return EXIT_FAILURE;

	*array = temp;
	for (int i = *size - (new_size - 1); i >= p; i--)
	{
		(*array)[i + 1] = (*array)[i];
	}
	(*array)[p] = max_elem;
	for (int i = *size - (new_size - 1); i >= 0; i--)
	{
		(*array)[i + 1] = (*array)[i];
	}
	(*array)[*size - 1] = max_elem;
	(*array)[0] = max_elem;

	return EXIT_SUCCESS;
}
