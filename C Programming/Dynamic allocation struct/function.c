#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "function.h"
#define MAX_STRING 256
#define SCANF_EXIT -1
int malloc_for_module(goods **new_goods, int size)
{
	*new_goods = malloc(size * sizeof(goods));
	if (*new_goods == NULL)
		return EXIT_FAILURE;
	return EXIT_SUCCESS;
}

int my_scanf(char *buf_article, char *buf_name, unsigned int *buf_quantity)
{
	char buf[MAX_STRING];
	int temp;
	printf("\narticle: ");
	if (scanf("%s", buf_article) != 1 || strlen(buf_article) >= MAX_STRING)
	{
		return EXIT_FAILURE;
	}
	strcpy(buf, buf_article);
	for (int i = 0; i < strlen(buf); i++)
	{
		buf[i] = tolower(buf[i]);
	}
	if (strcmp(buf, "nothing") == 0)
	{
		return SCANF_EXIT;
	}
	printf("name: ");
	if (scanf("%s", buf_name) != 1 || strlen(buf_name) >= MAX_STRING)
	{
		return EXIT_FAILURE;
	}
	printf("quantity : \n");
	if (scanf("%d", &temp) != 1 || temp < 0)
	{
		return EXIT_FAILURE;
	}
	else
		*buf_quantity = (unsigned int) temp;

	return EXIT_SUCCESS;
}
int creat_field(goods **new_goods, int num, char *buf_article, char *buf_name, unsigned int buf_quantity)
{
	for (int i = 0; i < strlen(buf_article); i++)
	{
		if (isupper(buf_article[i]) == 0)
		{
			return EXIT_FAILURE;
		}
	}
	(*new_goods)[num].article = malloc((strlen(buf_article) + 1) * sizeof(char));
	memcpy((*new_goods)[num].article, buf_article, (strlen(buf_article) + 1));

	for (int i = 0; i < strlen(buf_name); i++)
	{
		if ((buf_name[i] < 'A' || buf_name[i] > 'Z') && (buf_name[i] < 'a' || buf_name[i] > 'z'))
		{
			free((*new_goods)[num].article);
			return EXIT_FAILURE;
		}
	}
	(*new_goods)[num].name = malloc((strlen(buf_name) + 1) * sizeof(char));
	memcpy((*new_goods)[num].name, buf_name, (strlen(buf_name) + 1));

	(*new_goods)[num].quantity = malloc(sizeof(unsigned int));
	(*((*new_goods)[num].quantity)) = buf_quantity;
	return 0;
}
void free_field(goods **new_goods, int size)
{
	for (int i = 0; i < size; i++)
	{
		free((*new_goods)[i].article);
		free((*new_goods)[i].name);
		free((*new_goods)[i].quantity);
	}
}
void delete(goods **new_goods, int *size)
{
	for (int i = 0; i < *size; i++)
	{
		if (strcmp((*new_goods)[i].article, "LIPSTICK") == 0 && *((*new_goods)[i].quantity) == 0)
		{
			free((*new_goods)[i].article);
			free((*new_goods)[i].name);
			free((*new_goods)[i].quantity);
			for (int j = i; j < *size - 1; j++)
			{
				(*new_goods)[j] = (*new_goods)[j + 1];
			}
			i--;
			(*size)--;
			(*new_goods) = realloc(*new_goods, *size * sizeof(goods));
		}
	}
}
void add_name(goods **new_goods, int size)
{
	for (int i = 0; i < size; i++)
	{
		(*new_goods)[i].article = realloc((*new_goods)[i].article, (strlen((*new_goods)[i].name) + strlen((*new_goods)[i].article) + 1) * sizeof(char));
		strcat((*new_goods)[i].article, (*new_goods)[i].name);
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < strlen((*new_goods)[i].article); j++)
		{
			(*new_goods)[i].article[j] = toupper((*new_goods)[i].article[j]);
		}
	}
}

void sort(int size, goods **new_goods, int compare(goods, goods)) {
	goods temp;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (compare((*new_goods)[j], (*new_goods)[j + 1]) > 0)
			{
				temp = (*new_goods)[j];
				(*new_goods)[j] = (*new_goods)[j + 1];
				(*new_goods)[j + 1] = temp;
			}
		}
	}
}

int compare_article(goods first, goods second)
{
	return strcmp(first.article, second.article);
}

int compare_name(goods first, goods second)
{
	return strcmp(first.name, second.name);
}

int compare_quantity(goods first, goods second)
{
	if (*(first.quantity) == *(second.quantity))
	{
		return 0;
	}
	else if (*(first.quantity) > *(second.quantity))
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

int key(goods *new_goods, int size)
{
	printf("Input key ARTICLE/NAME/COUNT :\n");
	int size_array = 9;
	char temp[size_array];
	if (scanf("%s", temp) != 1 || strlen(temp) > size_array)
	{
		return EXIT_FAILURE;
	}
	if (strcmp(temp, "ARTICLE") == 0)
	{
		sort(size, &new_goods, compare_article);
	}
	else if (strcmp(temp, "NAME") == 0)
	{
		sort(size, &new_goods, compare_name);
	}
	else if (strcmp(temp, "COUNT") == 0)
	{
		sort(size, &new_goods, compare_quantity);
	}
	else if (strcmp(temp, "COUNT") != 0 && strcmp(temp, "NAME") != 0 && strcmp(temp, "ARTICLE") != 0)
		return EXIT_FAILURE;
	return 0;
}
