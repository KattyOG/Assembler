#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "function.h"

void test_delete()
{
	int err_cnt = 0;
	{
		int size = 3;
		goods *test_goods;
		malloc_for_module(&test_goods, size);
		creat_field(&test_goods, 0, "LIPSTICK", "o", 0);
		creat_field(&test_goods, 1, "LIPSTICKS", "auto", 0);
		creat_field(&test_goods, 2, "LIPSTICK", "o", 1);
		delete(&test_goods, &size);
		if (size != 2 || strcmp((test_goods)[0].article, "LIPSTICKS") != 0 || strcmp((test_goods)[1].article, "LIPSTICK") != 0)
			err_cnt++;
		for (int i = 0; i < size; i++)
		{
			free((test_goods)[i].article);
			free((test_goods)[i].name);
			free((test_goods)[i].quantity);
		}
		free(test_goods);
	}
	{
		int size = 3;
		goods *test_goods;
		malloc_for_module(&test_goods, size);
		creat_field(&test_goods, 0, "FF", "o", 0);
		creat_field(&test_goods, 1, "LIPSTICKS", "auto", 0);
		creat_field(&test_goods, 2, "HH", "o", 1);
		delete(&test_goods, &size);
		if (size != 3 || strcmp((test_goods)[0].article, "FF") != 0 || strcmp((test_goods)[1].article, "LIPSTICKS") != 0 || strcmp((test_goods)[2].article, "HH") != 0)
			err_cnt++;
		for (int i = 0; i < size; i++)
		{
			free((test_goods)[i].article);
			free((test_goods)[i].name);
			free((test_goods)[i].quantity);
		}
		free(test_goods);
	}
	{
		int size = 3;
		goods *test_goods;
		malloc_for_module(&test_goods, size);
		creat_field(&test_goods, 0, "LIPSTICK", "o", 0);
		creat_field(&test_goods, 1, "LIPSTICK", "auto", 0);
		creat_field(&test_goods, 2, "LIPSTICK", "o", 0);
		delete(&test_goods, &size);
		if (size != 0)
			err_cnt++;
		for (int i = 0; i < size; i++)
		{
			free((test_goods)[i].article);
			free((test_goods)[i].name);
			free((test_goods)[i].quantity);
		}
		free(test_goods);
	}
	printf("%s: %s\n", __func__, err_cnt ? "FAILED" : "OK");
}
void test_add_name()
{
	int err_cnt = 0;
	{
		int size = 3;
		goods *test_goods;
		malloc_for_module(&test_goods, size);
		creat_field(&test_goods, 0, "LIPSTIC", "o", 0);
		creat_field(&test_goods, 1, "STICK", "auto", 0);
		creat_field(&test_goods, 2, "LIPSTICK", "or", 0);
		add_name(&test_goods, size);
		if (size != 3 || strcmp((test_goods)[0].article, "LIPSTICO") != 0 || strcmp((test_goods)[1].article, "STICKAUTO") != 0 || strcmp((test_goods)[2].article, "LIPSTICKOR") != 0)
			err_cnt++;
		for (int i = 0; i < size; i++)
		{
			free((test_goods)[i].article);
			free((test_goods)[i].name);
			free((test_goods)[i].quantity);
		}
		free(test_goods);
	}
	printf("%s: %s\n", __func__, err_cnt ? "FAILED" : "OK");
}

void test_sort()
{
	int err_cnt = 0;
	{
		int size = 3;
		goods *test_goods;
		malloc_for_module(&test_goods, size);
		creat_field(&test_goods, 0, "LIPSTICK", "o", 3);
		creat_field(&test_goods, 1, "LIPSTICK", "auto", 1);
		creat_field(&test_goods, 2, "LIPSTICK", "or", 2);
		sort(size, &test_goods, compare_article);
		if (size != 3 || *((test_goods)[0].quantity) != 3 || *((test_goods)[1].quantity) != 1 || *((test_goods)[2].quantity) != 2)
			err_cnt++;
		for (int i = 0; i < size; i++)
		{
			free((test_goods)[i].article);
			free((test_goods)[i].name);
			free((test_goods)[i].quantity);
		}
		free(test_goods);
	}
	{
		int size = 3;
		goods *test_goods;
		malloc_for_module(&test_goods, size);
		creat_field(&test_goods, 0, "NQIW", "o", 3);
		creat_field(&test_goods, 1, "AAA", "auto", 1);
		creat_field(&test_goods, 2, "DD", "or", 2);
		sort(size, &test_goods, compare_article);
		if (size != 3 || *((test_goods)[0].quantity) != 1 || *((test_goods)[1].quantity) != 2 || *((test_goods)[2].quantity) != 3)
			err_cnt++;
		for (int i = 0; i < size; i++)
		{
			free((test_goods)[i].article);
			free((test_goods)[i].name);
			free((test_goods)[i].quantity);
		}
		free(test_goods);
	}
	{
		int size = 3;
		goods *test_goods;
		malloc_for_module(&test_goods, size);
		creat_field(&test_goods, 0, "NQIW", "o", 3);
		creat_field(&test_goods, 1, "AAA", "auto", 1);
		creat_field(&test_goods, 2, "DD", "or", 2);
		sort(size, &test_goods, compare_name);
		if (size != 3 || *((test_goods)[0].quantity) != 1 || *((test_goods)[1].quantity) != 3 || *((test_goods)[2].quantity) != 2)
			err_cnt++;
		for (int i = 0; i < size; i++)
		{
			free((test_goods)[i].article);
			free((test_goods)[i].name);
			free((test_goods)[i].quantity);
		}
		free(test_goods);
	}
	{
		int size = 3;
		goods *test_goods;
		malloc_for_module(&test_goods, size);
		creat_field(&test_goods, 0, "NQIW", "ab", 3);
		creat_field(&test_goods, 1, "AAA", "aaa", 1);
		creat_field(&test_goods, 2, "DD", "ab", 2);
		sort(size, &test_goods, compare_name);
		if (size != 3 || *((test_goods)[0].quantity) != 1 || *((test_goods)[1].quantity) != 3 || *((test_goods)[2].quantity) != 2)
			err_cnt++;
		for (int i = 0; i < size; i++)
		{
			free((test_goods)[i].article);
			free((test_goods)[i].name);
			free((test_goods)[i].quantity);
		}
		free(test_goods);
	}
	{
		int size = 3;
		goods *test_goods;
		malloc_for_module(&test_goods, size);
		creat_field(&test_goods, 0, "NQIW", "ab", 3);
		creat_field(&test_goods, 1, "AAA", "ab", 1);
		creat_field(&test_goods, 2, "DD", "ab", 2);
		sort(size, &test_goods, compare_name);
		if (size != 3 || *((test_goods)[0].quantity) != 3 || *((test_goods)[1].quantity) != 1 || *((test_goods)[2].quantity) != 2)
			err_cnt++;
		for (int i = 0; i < size; i++)
		{
			free((test_goods)[i].article);
			free((test_goods)[i].name);
			free((test_goods)[i].quantity);
		}
		free(test_goods);
	}
	{
		int size = 3;
		goods *test_goods;
		malloc_for_module(&test_goods, size);
		creat_field(&test_goods, 0, "NQIW", "ab", 3);
		creat_field(&test_goods, 1, "AAA", "aaa", 1);
		creat_field(&test_goods, 2, "DD", "ab", 2);
		sort(size, &test_goods, compare_quantity);
		if (size != 3 || *((test_goods)[0].quantity) != 1 || *((test_goods)[1].quantity) != 2 || *((test_goods)[2].quantity) != 3)
			err_cnt++;
		for (int i = 0; i < size; i++)
		{
			free((test_goods)[i].article);
			free((test_goods)[i].name);
			free((test_goods)[i].quantity);
		}
		free(test_goods);
	}
	{
		int size = 3;
		goods *test_goods;
		malloc_for_module(&test_goods, size);
		creat_field(&test_goods, 0, "NQIW", "ab", 1);
		creat_field(&test_goods, 1, "AAA", "aaa", 1);
		creat_field(&test_goods, 2, "DD", "ab", 2);
		sort(size, &test_goods, compare_quantity);
		if (size != 3 || strcmp((test_goods)[0].article, "NQIW") != 0 || strcmp((test_goods)[1].article, "AAA") != 0 || strcmp((test_goods)[2].article, "DD") != 0)
			err_cnt++;
		for (int i = 0; i < size; i++)
		{
			free((test_goods)[i].article);
			free((test_goods)[i].name);
			free((test_goods)[i].quantity);
		}
		free(test_goods);
	}
	{
		int size = 3;
		goods *test_goods;
		malloc_for_module(&test_goods, size);
		creat_field(&test_goods, 0, "NQIW", "ab", 1);
		creat_field(&test_goods, 1, "AAA", "aaa", 1);
		creat_field(&test_goods, 2, "DD", "ab", 1);
		sort(size, &test_goods, compare_quantity);
		if (size != 3 || strcmp((test_goods)[0].article, "NQIW") != 0 || strcmp((test_goods)[1].article, "AAA") != 0 || strcmp((test_goods)[2].article, "DD") != 0)
			err_cnt++;
		for (int i = 0; i < size; i++)
		{
			free((test_goods)[i].article);
			free((test_goods)[i].name);
			free((test_goods)[i].quantity);
		}
		free(test_goods);
	}
	{
		int size = 3;
		goods *test_goods;
		malloc_for_module(&test_goods, size);
		creat_field(&test_goods, 0, "NQIW", "ab", 3);
		creat_field(&test_goods, 1, "AAA", "aaa", 1);
		creat_field(&test_goods, 2, "DD", "ab", 2);
		sort(size, &test_goods, compare_quantity);
		if (size != 3 || strcmp((test_goods)[0].article, "AAA") != 0 || strcmp((test_goods)[1].article, "DD") != 0 || strcmp((test_goods)[2].article, "NQIW") != 0)
			err_cnt++;
		for (int i = 0; i < size; i++)
		{
			free((test_goods)[i].article);
			free((test_goods)[i].name);
			free((test_goods)[i].quantity);
		}
		free(test_goods);
	}
	printf("%s: %s\n", __func__, err_cnt ? "FAILED" : "OK");
}
int main()
{
	test_delete();
	test_add_name();
	test_sort();
	return 0;
}
