#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcs.h"

void insert_list(list *(*head), int i, int j, int val)
{
	list *temp;
	temp = (list*)malloc(sizeof(list));
	temp->next = NULL;
	temp->value[0] = i;
	temp->value[1] = j;
	temp->value[2] = val;

	list *p = *head;
	list *prev = NULL;

	if (p != NULL)
	{
		while (p != NULL)
		{
			if (p->value[0] > i || (p->value[0] == i && p->value[1] > j))
			{
				break;
			}
			prev = p;
			p = p->next;
		}

		if (prev != NULL)
		{
			prev->next = temp;
			temp->next = p;
		}
		else
		{
			temp->next = p;
			*head = temp;
		}
	}
	else
	{
		*head = temp;
	}
}

int max_size(list *head, int *size)
{
	list *p;
	int max_row = -1, max_col = -1;
	if (head == NULL)
	{
		return EXIT_FAILURE;
	}
	p = head;
	do
	{
		if (p->value[0] > max_row && p->value[1] <= max_col)
			max_row = p->value[0];
		else if (p->value[1] > max_col && p->value[0] <= max_row)
			max_col = p->value[1];
		else if (p->value[1] > max_col && p->value[0] > max_row)
		{
			max_row = p->value[0];
			max_col = p->value[1];
		}
		p = p->next;
	} while (p != NULL);
	size[0] = max_row;
	size[1] = max_col;
	return EXIT_SUCCESS;
}

void print_matrix(list **head, int size_i, int size_j)
{
	list *p;
	// for (int i = 0; i < size_i; i++)
	// {
	//      for (int j = 0; j < size_j; j++)
	//      {
	//              if (p != NULL) {
	//                      if(i == p->value[0] && j == p->value[1]) {
	//                              printf("%5d", p->value[2]);
	//                              p = p->next;
	//                      }
	//                      else {
	//                              printf("%5d", 0);
	//                      }
	//              }
	//              else {
	//                      printf("%5d", 0);
	//              }
	//      }
	//      printf("\n");
	// }
	// printf("\n");
	p = *head;
	for (int i = 0; i < size_i; i++)
	{
		for (int j = 0; j < size_j; j++)
		{
			if (p != NULL)
			{
				if (i == p->value[0] && j == p->value[1])
				{
					printf("%d %d %d ", p->value[0], p->value[1], p->value[2]);
					p = p->next;
				}
			}
		}
	}
	printf("\n");
}

void delete_row(list **head)
{
	list *p;
	list *prev;
	p = *head;
	int max = 0;
	int i;
	while (p != NULL)
	{
		if (p->value[2] > max)
		{
			max = p->value[2];
			i = p->value[0];
		}
		p = p->next;
	}

	p = *head;
	prev = NULL;
	while (p != NULL)
	{
		list *temp = p->next;
		if (p->value[0] == i)
		{
			if (prev != NULL)
			{
				prev->next = p->next;
			}
			else
			{
				*head = p->next;
			}
			free(p);
		}
		else
		{
			prev = p;
			if (p->value[0] > i)
			{
				p->value[0] -= 1;
			}
		}
		p = temp;
	}
}

void sum_matrix(list **head, list **head2, list **head3)
{
	list *p;
	p = *head;
	list *p2;
	p2 = *head2;

	while (p != NULL && p2 != NULL)
	{
		if (p->value[0] == p2->value[0] && p->value[1] == p2->value[1])
		{
			insert_list(head3, p->value[0], p->value[1], p->value[2] + p2->value[2]);
			p = p->next;
			p2 = p2->next;
		}
		else
		{
			if (p->value[0] < p2->value[0])
			{
				insert_list(head3, p->value[0], p->value[1], p->value[2]);
				p = p->next;
			}
			else if (p->value[0] == p2->value[0])
			{
				if (p->value[1] <= p2->value[1])
				{
					insert_list(head3, p->value[0], p->value[1], p->value[2]);
					p = p->next;
				}
				else
				{
					insert_list(head3, p2->value[0], p2->value[1], p2->value[2]);
					p2 = p2->next;
				}
			}
			else
			{
				insert_list(head3, p2->value[0], p2->value[1], p2->value[2]);
				p2 = p2->next;
			}
		}
	}

	p = p ? p : p2;
	while (p)
	{
		insert_list(head3, p->value[0], p->value[1], p->value[2]);
		p = p->next;
	}
}

list *find_in_list(list *head, int row, int column)
{
	while (head != NULL)
	{
		if (head->value[0] == row && head->value[1] == column)
		{
			return head;
		}
		head = head->next;
	}
	return NULL;
}

list *multip_matrix(list *head, list *head2)
{
	list *head3 = NULL;
	while (head != NULL)
	{
		list *temp = head2;
		while (temp != NULL)
		{
			if (head->value[1] == temp->value[0])
			{
				list *node = find_in_list(head3, head->value[0], temp->value[1]);
				if (node == NULL)
				{
					insert_list(&head3, head->value[0], temp->value[1], head->value[2] * temp->value[2]);
				}
				else
				{
					node->value[2] += head->value[2] * temp->value[2];
				}
			}
			temp = temp->next;
		}
		head = head->next;
	}
	return head3;
}

void free_matrix(list **head)
{
	list *temp;
	list *p;
	p = *head;
	while (p != NULL)
	{
		temp = p;
		p = p->next;
		free(temp);
	}
}
