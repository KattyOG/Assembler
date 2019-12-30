#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "function.h"
#define MAX_STRING 256
#define SCANF_EXIT -1
int main()
{
	goods *new_goods;
	int size = 0;
	FILE *file;
	char buf_article[MAX_STRING];
	char buf_name[MAX_STRING];
	unsigned int buf_quantity;
	int temp = 0;
	int temp2;
	int temp3;
	new_goods = malloc(sizeof(goods));
	temp3 = my_scanf(buf_article, buf_name, &buf_quantity);
	if (temp3 == EXIT_FAILURE)
	{
		free_field(&new_goods, size);
		free(new_goods);
		return EXIT_FAILURE;
	}
	temp2 = creat_field(&new_goods, size, buf_article, buf_name, buf_quantity);
	while (temp2 == 0)
	{
		size++;
		new_goods = realloc(new_goods, (size + 2) * sizeof(goods));
		temp3 = my_scanf(buf_article, buf_name, &buf_quantity);
		if (temp3 == SCANF_EXIT)
			break;
		if (temp3 == EXIT_FAILURE)
		{
			free_field(&new_goods, size);
			free(new_goods);
			return EXIT_FAILURE;
		}
		temp2 = creat_field(&new_goods, size, buf_article, buf_name, buf_quantity);
	}
	if (size == 0)
	{
		free_field(&new_goods, size);
		free(new_goods);
		return EXIT_FAILURE;
	}
	if (temp2 == EXIT_FAILURE)
	{
		free_field(&new_goods, size);
		free(new_goods);
		return EXIT_FAILURE;
	}
	add_name(&new_goods, size);
	delete(&new_goods, &size);
	if (size == 0)
	{
		free_field(&new_goods, size);
		free(new_goods);
		return EXIT_FAILURE;
	}
	temp = key(new_goods, size);
	if (temp == EXIT_FAILURE)
	{
		free_field(&new_goods, size);
		free(new_goods);
		return EXIT_FAILURE;
	}
	file = fopen("stockpile.txt", "w");
	for (int i = 0; i < size; i++)
	{
		fprintf(file, "%s\n", new_goods[i].article);
		fprintf(file, "%s\n", new_goods[i].name);
		fprintf(file, "%u\n", (*(new_goods[i].quantity)));
	}
	fclose(file);
	free_field(&new_goods, size);
	free(new_goods);
	return 0;
}
