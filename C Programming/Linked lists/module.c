#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcs.h"
void test_delete_row()
{
	int error_counter = 0;
	{
		list *p1 = NULL;
		list *tmp = NULL;
		insert_list(&p1, 0, 0, 1);
		insert_list(&p1, 0, 1, 2);
		insert_list(&p1, 0, 2, 3);
		insert_list(&p1, 1, 0, 4);
		insert_list(&p1, 1, 1, 5);
		insert_list(&p1, 1, 2, 6);
		insert_list(&p1, 2, 2, 9);
		delete_row(&p1);
		tmp = p1;
		for (int i = 0; i < 2; i++)
		{
			if (tmp->value[2] != i + 1)
				error_counter++;
			tmp = tmp->next;
		}
		free_matrix(&p1);
	}
	{
		list *p1 = NULL;
		list *tmp = NULL;
		insert_list(&p1, 0, 0, 1);
		insert_list(&p1, 0, 1, 2);
		insert_list(&p1, 0, 2, 3);
		insert_list(&p1, 2, 2, 9);
		insert_list(&p1, 1, 0, 4);
		insert_list(&p1, 1, 1, 5);
		insert_list(&p1, 1, 2, 6);
		delete_row(&p1);
		tmp = p1;
		for (int i = 0; i < 2; i++)
		{
			if (tmp->value[2] != i + 1)
				error_counter++;
			tmp = tmp->next;
		}
		free_matrix(&p1);
	}
	{
		list *p1 = NULL;
		list *tmp = NULL;
		insert_list(&p1, 0, 0, 1);
		insert_list(&p1, 0, 1, 2);
		insert_list(&p1, 0, 2, 3);
		insert_list(&p1, 1, 1, 9);
		insert_list(&p1, 2, 0, 4);
		insert_list(&p1, 2, 1, 5);
		insert_list(&p1, 2, 2, 6);
		delete_row(&p1);
		tmp = p1;
		for (int i = 0; i < 2; i++)
		{
			if (tmp->value[2] != i + 1)
				error_counter++;
			tmp = tmp->next;
		}
		free_matrix(&p1);
	}
	printf("%s: %s\n", __func__, error_counter ? "FAILED" : "PASSED");
}

void test_insert_list()
{
	int error_counter = 0;
	{
		list *p = NULL;
		list *tmp = NULL;
		insert_list(&p, 0, 0, 1);
		insert_list(&p, 0, 1, 2);
		insert_list(&p, 0, 2, 3);
		tmp = p;
		if (tmp->value[0] != 0 || tmp->value[1] != 0 || tmp->value[2] != 1)
			error_counter++;
		tmp = tmp->next;
		if (tmp->value[0] != 0 || tmp->value[1] != 1 || tmp->value[2] != 2)
			error_counter++;
		tmp = tmp->next;
		if (tmp->value[0] != 0 || tmp->value[1] != 2 || tmp->value[2] != 3)
			error_counter++;
		free_matrix(&p);
	}
	printf("%s: %s\n", __func__, error_counter ? "FAILED" : "PASSED");
}


void test_multip_matrix()
{
	int error_counter = 0;
	{
		list *p1 = NULL;
		list *p2 = NULL;
		list *p3 = NULL;
		list *tmp = NULL;
		insert_list(&p1, 0, 0, 1);
		insert_list(&p1, 0, 1, 2);
		insert_list(&p1, 0, 2, 3);
		insert_list(&p1, 1, 0, 4);
		insert_list(&p1, 1, 1, 5);
		insert_list(&p1, 1, 2, 6);

		insert_list(&p2, 0, 0, 1);
		insert_list(&p2, 1, 0, 2);
		insert_list(&p2, 2, 0, 3);
		insert_list(&p2, 0, 1, 4);
		insert_list(&p2, 1, 1, 5);
		insert_list(&p2, 2, 1, 6);

		p3 = multip_matrix(p1, p2);
		tmp = p3;
		if (tmp->value[2] != 14)
			error_counter++;
		tmp = tmp->next;
		if (tmp->value[2] != 32)
			error_counter++;
		tmp = tmp->next;
		if (tmp->value[2] != 32)
			error_counter++;
		tmp = tmp->next;
		if (tmp->value[2] != 77)
			error_counter++;

		free_matrix(&p1);
		free_matrix(&p2);
		free_matrix(&p3);
	}
	{
		list *p1 = NULL;
		list *p2 = NULL;
		list *p3 = NULL;

		insert_list(&p2, 0, 0, 1);
		insert_list(&p2, 1, 0, 2);
		insert_list(&p2, 2, 0, 3);
		insert_list(&p2, 0, 1, 4);
		insert_list(&p2, 1, 1, 5);
		insert_list(&p2, 2, 1, 6);

		p3 = multip_matrix(p1, p2);

		if (p3 != NULL)
			error_counter++;

		free_matrix(&p1);
		free_matrix(&p2);
		free_matrix(&p3);
	}
	printf("%s: %s\n", __func__, error_counter ? "FAILED" : "PASSED");
}


void test_find_in_list()
{
	int error_counter = 0;
	{
		list *p1 = NULL;
		list *p2 = NULL;
		insert_list(&p1, 0, 0, 1);
		insert_list(&p1, 0, 1, 2);
		insert_list(&p1, 0, 2, 3);
		insert_list(&p1, 1, 0, 4);
		insert_list(&p1, 1, 1, 5);
		insert_list(&p1, 1, 2, 6);
		p2 = find_in_list(p1, 0, 0);
		if (p2->value[2] != 1)
			error_counter++;
		p2 = NULL;
		p2 = find_in_list(p1, 1, 2);
		if (p2->value[2] != 6)
			error_counter++;
		p2 = NULL;
		p2 = find_in_list(p1, 3, 3);
		if (p2 != NULL)
			error_counter++;
		free_matrix(&p1);
		free_matrix(&p2);
	}
	printf("%s: %s\n", __func__, error_counter ? "FAILED" : "PASSED");
}

void test_max_size()
{
	int error_counter = 0;
	{
		list *p1 = NULL;
		int last[2];
		insert_list(&p1, 0, 0, 1);
		insert_list(&p1, 0, 1, 2);
		insert_list(&p1, 0, 2, 3);
		insert_list(&p1, 2, 1, 1);
		insert_list(&p1, 1, 0, 4);
		insert_list(&p1, 1, 1, 5);
		insert_list(&p1, 1, 2, 6);
		max_size(p1, last);
		if (last[0] != 2 || last[1] != 2)
			error_counter++;
		free_matrix(&p1);
	}
	{
		list *p1 = NULL;
		int last[2];
		insert_list(&p1, 0, 5, 1);
		insert_list(&p1, 0, 1, 2);
		insert_list(&p1, 0, 2, 3);
		insert_list(&p1, 5, 1, 1);
		insert_list(&p1, 1, 0, 4);
		insert_list(&p1, 1, 1, 5);
		insert_list(&p1, 1, 2, 6);
		max_size(p1, last);
		if (last[0] != 5 || last[1] != 5)
			error_counter++;
		free_matrix(&p1);
	}
	printf("%s: %s\n", __func__, error_counter ? "FAILED" : "PASSED");
}

void test_sum_matrix()
{
	int error_counter = 0;
	{
		list *p1 = NULL;
		list *p2 = NULL;
		list *p3 = NULL;
		list *tmp = NULL;

		insert_list(&p1, 0, 1, 2);
		insert_list(&p1, 1, 1, 5);
		insert_list(&p2, 0, 0, 1);
		insert_list(&p2, 0, 2, 3);
		insert_list(&p2, 1, 0, 4);
		insert_list(&p2, 1, 2, 6);

		sum_matrix(&p1, &p2, &p3);
		tmp = p3;
		for (int i = 0; i < 6; i++)
		{
			if (tmp->value[2] != i + 1)
				error_counter++;
			tmp = tmp->next;
		}
		free_matrix(&p1);
		free_matrix(&p2);
		free_matrix(&p3);
	}
	{
		list *p1 = NULL;
		list *p2 = NULL;
		list *p3 = NULL;
		list *tmp = NULL;
		insert_list(&p1, 0, 0, 1);
		insert_list(&p1, 0, 1, 2);
		insert_list(&p1, 0, 2, 3);
		insert_list(&p1, 1, 0, 4);
		insert_list(&p1, 1, 1, 5);
		insert_list(&p1, 1, 2, 6);
		insert_list(&p2, 0, 0, 1);
		insert_list(&p2, 0, 1, 2);
		insert_list(&p2, 0, 2, 3);
		insert_list(&p2, 1, 0, 4);
		insert_list(&p2, 1, 1, 5);
		insert_list(&p2, 1, 2, 6);

		sum_matrix(&p1, &p2, &p3);
		tmp = p3;
		for (int i = 0; i < 6; i++)
		{
			if (tmp->value[2] != 2 * (i + 1))
				error_counter++;
			tmp = tmp->next;
		}
		free_matrix(&p1);
		free_matrix(&p2);
		free_matrix(&p3);
	}
	{
		list *p1 = NULL;
		list *p2 = NULL;
		list *p3 = NULL;
		list *tmp = NULL;
		insert_list(&p1, 0, 0, 1);

		insert_list(&p2, 1, 2, 2);

		sum_matrix(&p1, &p2, &p3);
		tmp = p3;
		for (int i = 0; i < 2; i++)
		{
			if (tmp->value[2] != i + 1)
				error_counter++;
			tmp = tmp->next;
		}
		free_matrix(&p1);
		free_matrix(&p2);
		free_matrix(&p3);
	}
	{
		list *p1 = NULL;
		list *p2 = NULL;
		list *p3 = NULL;
		list *tmp = NULL;
		insert_list(&p2, 0, 0, 1);

		insert_list(&p1, 1, 2, 2);

		sum_matrix(&p1, &p2, &p3);
		tmp = p3;
		for (int i = 0; i < 2; i++)
		{
			if (tmp->value[2] != i + 1)
				error_counter++;
			tmp = tmp->next;
		}
		free_matrix(&p1);
		free_matrix(&p2);
		free_matrix(&p3);
	}
	printf("%s: %s\n", __func__, error_counter ? "FAILED" : "PASSED");
}

int main()
{
	test_delete_row();
	test_sum_matrix();
	test_find_in_list();
	test_insert_list();
	test_max_size();
	test_multip_matrix();
	return 0;
}
