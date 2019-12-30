#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funcs.h"
#define MAX_SIZE 5

int main()
{
	list *head = NULL;
	list *head2 = NULL;
	list *head3 = NULL;
	int size[2];
	int max_i = 0;
	int max_j = 0;
	char str[MAX_SIZE - 1];
	int temp = 0;
	if ((scanf("%s", str) != 1) && strlen(str) > MAX_SIZE - 1)
		return EXIT_FAILURE;

	if ((strcmp(str, "out") == 0))
	{
		if (scanf("%d", &max_i) != 1)
		{
			return EXIT_FAILURE;
		}
		if (scanf("%d", &max_j) != 1)
		{
			return EXIT_FAILURE;
		}
		if (max_i <= 0 || max_j <= 0)
		{
			return EXIT_FAILURE;
		}
		for (int i = 0; i < max_i; i++)
		{
			for (int j = 0; j < max_j; j++)
			{
				if (scanf("%d", &temp) == 1)
				{
					if (temp != 0)
						insert_list(&head, i, j, temp);
				}
				else
				{
					free_matrix(&head);
					return EXIT_FAILURE;
				}
			}
		}
		max_size(head, size);
		if (head != NULL)
		{
			print_matrix(&head, size[0] + 1, size[1] + 1);
		}
		else
			return EXIT_FAILURE;
	}
	else if ((strcmp(str, "add") == 0))
	{
		if (scanf("%d", &max_i) != 1)
		{
			return EXIT_FAILURE;
		}
		if (scanf("%d", &max_j) != 1)
		{
			return EXIT_FAILURE;
		}
		if (max_i <= 0 || max_j <= 0)
		{
			return EXIT_FAILURE;
		}
		for (int i = 0; i < max_i; i++)
		{
			for (int j = 0; j < max_j; j++)
			{
				if (scanf("%d", &temp) == 1)
				{
					if (temp != 0)
						insert_list(&head, i, j, temp);
				}
				else
				{
					free_matrix(&head);
					return EXIT_FAILURE;
				}
			}
		}
		if (scanf("%d", &max_i) != 1)
		{
			free_matrix(&head);
			return EXIT_FAILURE;
		}
		if (scanf("%d", &max_j) != 1)
		{
			free_matrix(&head);
			return EXIT_FAILURE;
		}
		for (int i = 0; i < max_i; i++)
		{
			for (int j = 0; j < max_j; j++)
			{
				if (scanf("%d", &temp) == 1)
				{
					if (temp != 0)
						insert_list(&head2, i, j, temp);
				}
				else
				{
					free_matrix(&head);
					free_matrix(&head2);
					return EXIT_FAILURE;
				}
			}
		}
		sum_matrix(&head, &head2, &head3);
		if (head3 != NULL)
		{
			max_size(head3, size);
			print_matrix(&head3, size[0] + 1, size[1] + 1);
		}
		else
			return EXIT_FAILURE;
	}
	else if ((strcmp(str, "mul") == 0))
	{
		if (scanf("%d", &max_i) != 1)
		{
			return EXIT_FAILURE;
		}
		if (scanf("%d", &max_j) != 1)
		{
			return EXIT_FAILURE;
		}
		if (max_i <= 0 || max_j <= 0)
		{
			return EXIT_FAILURE;
		}
		for (int i = 0; i < max_i; i++)
		{
			for (int j = 0; j < max_j; j++)
			{
				if (scanf("%d", &temp) == 1)
				{
					if (temp != 0)
						insert_list(&head, i, j, temp);
				}
				else
				{
					free_matrix(&head);
					return EXIT_FAILURE;
				}
			}
		}
		if (scanf("%d", &max_i) != 1)
		{
			free_matrix(&head);
			return EXIT_FAILURE;
		}
		if (scanf("%d", &max_j) != 1)
		{
			free_matrix(&head);
			return EXIT_FAILURE;
		}
		if (max_i <= 0 || max_j <= 0)
		{
			free_matrix(&head);
			return EXIT_FAILURE;
		}
		for (int i = 0; i < max_i; i++)
		{
			for (int j = 0; j < max_j; j++)
			{
				if (scanf("%d", &temp) == 1)
				{
					if (temp != 0)
						insert_list(&head2, i, j, temp);
				}
				else
				{
					free_matrix(&head);
					free_matrix(&head2);
					return EXIT_FAILURE;
				}
			}
		}
		head3 = multip_matrix(head, head2);
		if (head3 != NULL)
		{
			max_size(head3, size);
			print_matrix(&head3, size[0] + 1, size[1] + 1);
		}
		else
		{
			return EXIT_FAILURE;
		}
	}
	else if ((strcmp(str, "lin") == 0))
	{
		if (scanf("%d", &max_i) != 1)
		{
			return EXIT_FAILURE;
		}
		if (scanf("%d", &max_j) != 1)
		{
			return EXIT_FAILURE;
		}
		if (max_i <= 0 || max_j <= 0)
		{
			return EXIT_FAILURE;
		}
		for (int i = 0; i < max_i; i++)
		{
			for (int j = 0; j < max_j; j++)
			{
				if (scanf("%d", &temp) == 1)
				{
					if (temp != 0)
						insert_list(&head, i, j, temp);
				}
				else
				{
					free_matrix(&head);
					return EXIT_FAILURE;
				}
			}
		}
		if (head == NULL)
		{
			return EXIT_FAILURE;
		}
		delete_row(&head);
		if (head != NULL)
		{
			max_size(head, size);
			print_matrix(&head, size[0] + 1, size[1] + 1);
		}
		else
		{
			return EXIT_FAILURE;
		}
	}
	else
	{
		return EXIT_FAILURE;
	}
	free_matrix(&head);
	free_matrix(&head2);
	free_matrix(&head3);
	return 0;
}
