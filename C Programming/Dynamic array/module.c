#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "function.h"

#define EPS 1e-6
typedef double *array_t;
void test_average()
{
	int err_cnt = 0;
	{
		int size = 3;
		array_t array;
		array = (array_t)my_malloc(size);
		array[0] = 0;
		array[1] = 0;
		array[2] = 0;
		if (my_average(array, array + size) != 0.0)
			err_cnt++;
		free(array);
		array = NULL;
	}
	{
		int size = 1;
		array_t array;
		array = (array_t)my_malloc(size);
		array[0] = 3;
		if (my_average(array, array + size) != 3)
			err_cnt++;
		free(array);
		array = NULL;
	}
	{
		int size = 3;
		array_t array;
		array = (array_t)my_malloc(size);
		array[0] = -5;
		array[1] = -1;
		array[2] = -3;
		if (my_average(array, array + size) != -3)
			err_cnt++;
		free(array);
		array = NULL;
	}
	printf("%s: %s\n", __func__, err_cnt ? "FAILED" : "SUCCESSFULLY");
}
void test_delete()
{
	int err_cnt = 0;
	{
		int size = 5;
		array_t array;
		array = (array_t)my_malloc(size);
		array[0] = 2;
		array[1] = 2;
		array[2] = 2;
		array[3] = 50;
		array[4] = 50;
		delete(&array, &size, 21.2);
		for (int i = 0; i < size; i++)
		{
			if (array[i] != 2)
				err_cnt++;
		}
		free(array);
		array = NULL;
	}
	{
		int size = 3;
		array_t array;
		array = (array_t)my_malloc(size);
		array[0] = 2;
		array[1] = 2;
		array[2] = 2;
		delete(&array, &size, 2);
		for (int i = 0; i < size; i++)
		{
			if (array[i] != 2 && size != 1)
				err_cnt++;
		}
		free(array);
		array = NULL;
	}
	{
		int size = 6;
		array_t array;
		array = (array_t)my_malloc(size);
		array[0] = 1;
		array[1] = 1;
		array[2] = 2;
		array[3] = 2;
		array[4] = 3;
		array[5] = 3;
		delete(&array, &size, 2);
		if (array[0] != 2 && array[1] != 2 && array[2] != 3 && array[3] != 3)
			err_cnt++;
		free(array);
		array = NULL;
	}
	printf("%s: %s\n", __func__, err_cnt ? "FAILED" : "SUCCESSFULLY");
}
void test_insert()
{
	int err_cnt = 0;
	{
		int size = 3;
		array_t array;
		array = (array_t)my_malloc(size);
		array[0] = 13;
		array[1] = 9;
		array[2] = 21;
		insert(&array, &size, 21, 0, 3);
		if (array[0] != 21 && size != 6 && array[1] != 21 && array[4] != 21 && array[5] != 21)
			err_cnt++;
		free(array);
		array = NULL;
	}
	{
		int size = 3;
		array_t array;
		array = (array_t)my_malloc(size);
		array[0] = 13;
		array[1] = 9;
		array[2] = 21;
		insert(&array, &size, 21, 1, 3);
		if (array[0] != 21 && size != 6 && array[2] != 21 && array[4] != 21 && array[5] != 21)
			err_cnt++;
		free(array);
		array = NULL;
	}
	printf("%s: %s\n", __func__, err_cnt ? "FAILED" : "SUCCESSFULLY");
}
int main()
{
	test_insert();
	test_average();
	test_delete();
}
