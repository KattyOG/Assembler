#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <dlfcn.h>

int main()
{
	int size;
	double *array;
	int p;
	void *ext_library;
	double (*average)(double *start, double *end);
	int (*delete)(double **array, int *size, double average);
	double (*max_el)(double *array, double *start, double *end);
	int (*insert)(double **array, int *size, double max_elem, int p, int new_size);

	ext_library = dlopen("dinam_load.so", RTLD_LAZY);
	if (!ext_library)
	{
		return EXIT_FAILURE;
	}
	printf("Input size: \n");
	if (scanf("%d", &size) != 1 || size <= 0)
		return EXIT_FAILURE;

	array = (double*)malloc(size * sizeof(double));
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
	average = dlsym(ext_library, "my_average");
	double average_num = (*average)(array, array + size);

	delete = dlsym(ext_library, "delete");
	int temp = (*delete)(&array, &size, average_num);

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
	max_el = dlsym(ext_library, "max_el");
	double max_element = (*max_el)(array, array, array + size);
	insert = dlsym(ext_library, "insert");
	temp = (*insert)(&array, &size, max_element, p, 3);
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
	dlclose(ext_library);
}
