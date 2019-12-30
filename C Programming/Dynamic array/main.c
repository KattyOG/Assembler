#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "function.h"

int main()
{
	int size;
	double *array;
	int p;

	printf("Input size: \n");
	if (scanf("%d", &size) != 1 || size <= 0)
		return EXIT_FAILURE;


	array = (double*)my_malloc(size);
	if (array == NULL)
		return EXIT_FAILURE;
	for (int i = 0; i < size; i++)
	{
		printf("Input element: \n");
		if (scanf("%lf", &array[i]) != 1)
		{
			free(array);
			return EXIT_FAILURE;
		}
	}

	printf("Input p: \n");
	if (scanf("%d", &p) != 1 || p < 0)
	{
		free(array);
		return EXIT_FAILURE;
	}

	double average = my_average(array, array + size);

	int temp = delete(&array, &size, average);
	if (temp == EXIT_FAILURE)
	{
		free(array);
		return EXIT_FAILURE;
	}
	if (size == 0)
	{
		free(array);
		return EXIT_FAILURE;
	}
	double max_element = max_el(array, array, array + size);
	temp = insert(&array, &size, max_element, p, 3);
	if (temp == EXIT_FAILURE)
	{
		free(array);
		return EXIT_FAILURE;
	}
	for (int i = 0; i < size; i++)
	{
		printf("%f ", array[i]);
	}
	printf("\n");
	free(array);
}
