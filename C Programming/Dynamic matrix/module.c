#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "function.h"
#define MAX_SIZE 50
#define EPS 1e-6

void test_delete_row(void)
{
	int err_cnt = 0;
	{
		matrix test_matrix;
		test_matrix.row = 2;
		test_matrix.column = 2;
		init_matrix(&test_matrix);
		test_matrix.ptr[0][0] = 0;
		test_matrix.ptr[0][1] = 1;
		test_matrix.ptr[1][0] = 2;
		test_matrix.ptr[1][1] = 3;
		delete_row(&test_matrix, 0);
		if (test_matrix.row != 1 || test_matrix.ptr[0][0] != 2 || test_matrix.ptr[0][1] != 3)
			err_cnt++;
		free_matrix(&test_matrix);
	}
	{
		matrix test_matrix;
		test_matrix.row = 2;
		test_matrix.column = 2;
		init_matrix(&test_matrix);
		test_matrix.ptr[0][0] = -2;
		test_matrix.ptr[0][1] = -1;
		test_matrix.ptr[1][0] = -6;
		test_matrix.ptr[1][1] = -8;
		delete_row(&test_matrix, 1);
		if (test_matrix.row != 1 || test_matrix.ptr[0][0] != -2 || test_matrix.ptr[0][1] != -1)
			err_cnt++;
		free_matrix(&test_matrix);
	}
	{
		matrix test_matrix;
		test_matrix.row = 2;
		test_matrix.column = 2;
		init_matrix(&test_matrix);
		test_matrix.ptr[0][0] = 1;
		test_matrix.ptr[0][1] = 1;
		test_matrix.ptr[1][0] = 1;
		test_matrix.ptr[1][1] = 1;
		delete_row(&test_matrix, 1);
		if (test_matrix.row != 1 || test_matrix.ptr[0][0] != 1 || test_matrix.ptr[0][1] != 1)
			err_cnt++;
		free_matrix(&test_matrix);
	}
	printf("%s: %s\n", __func__, err_cnt ? "FAILED" : "OK");
}
void test_delete_column()
{
	int err_cnt = 0;
	{
		matrix test_matrix;
		test_matrix.row = 2;
		test_matrix.column = 2;
		init_matrix(&test_matrix);
		test_matrix.ptr[0][0] = 0;
		test_matrix.ptr[0][1] = 1;
		test_matrix.ptr[1][0] = 2;
		test_matrix.ptr[1][1] = 3;
		delete_column(&test_matrix, 0);
		if (test_matrix.column != 1 || test_matrix.ptr[0][0] != 1 || test_matrix.ptr[1][0] != 3)
			err_cnt++;
		free_matrix(&test_matrix);
	}
	{
		matrix test_matrix;
		test_matrix.row = 2;
		test_matrix.column = 2;
		init_matrix(&test_matrix);
		test_matrix.ptr[0][0] = -5;
		test_matrix.ptr[0][1] = -5;
		test_matrix.ptr[1][0] = 2;
		test_matrix.ptr[1][1] = 3;
		delete_column(&test_matrix, 1);
		if (test_matrix.column != 1 || test_matrix.ptr[0][0] != -5 || test_matrix.ptr[1][0] != 2)
			err_cnt++;
		free_matrix(&test_matrix);
	}
	printf("%s: %s\n", __func__, err_cnt ? "FAILED" : "OK");
}
void test_min_row(void)
{
	int err_cnt = 0;
	{
		matrix test_matrix;
		test_matrix.row = 2;
		test_matrix.column = 2;
		init_matrix(&test_matrix);
		test_matrix.ptr[0][0] = -5;
		test_matrix.ptr[0][1] = -5;
		test_matrix.ptr[1][0] = 2;
		test_matrix.ptr[1][1] = 3;
		long long int temp = min_row(&test_matrix, 0);
		if (temp != -5)
			err_cnt++;
		free_matrix(&test_matrix);
	}
	{
		matrix test_matrix;
		test_matrix.row = 2;
		test_matrix.column = 2;
		init_matrix(&test_matrix);
		test_matrix.ptr[0][0] = -5;
		test_matrix.ptr[0][1] = -5;
		test_matrix.ptr[1][0] = 2;
		test_matrix.ptr[1][1] = 3;
		long long int temp = min_row(&test_matrix, 1);
		if (temp != 2)
			err_cnt++;
		free_matrix(&test_matrix);
	}
	{
		matrix test_matrix;
		test_matrix.row = 2;
		test_matrix.column = 2;
		init_matrix(&test_matrix);
		test_matrix.ptr[0][0] = -5;
		test_matrix.ptr[0][1] = -5;
		test_matrix.ptr[1][0] = 4;
		test_matrix.ptr[1][1] = 3;
		long long int temp = min_row(&test_matrix, 1);
		if (temp != 3)
			err_cnt++;
		free_matrix(&test_matrix);
	}
	printf("%s: %s\n", __func__, err_cnt ? "FAILED" : "OK");
}
void test_add_column(void)
{
	int err_cnt = 0;
	{
		matrix test_matrix;
		test_matrix.row = 2;
		test_matrix.column = 2;
		init_matrix(&test_matrix);
		test_matrix.ptr[0][0] = -5;
		test_matrix.ptr[0][1] = -5;
		test_matrix.ptr[1][0] = 4;
		test_matrix.ptr[1][1] = 3;
		add_column(&test_matrix, 1);
		if (test_matrix.column != 3 || test_matrix.ptr[0][2] != -5 || test_matrix.ptr[1][2] != 3)
			err_cnt++;
		free_matrix(&test_matrix);
	}
	{
		matrix test_matrix;
		test_matrix.row = 2;
		test_matrix.column = 2;
		init_matrix(&test_matrix);
		test_matrix.ptr[0][0] = 4;
		test_matrix.ptr[0][1] = 4;
		test_matrix.ptr[1][0] = 4;
		test_matrix.ptr[1][1] = 4;
		add_column(&test_matrix, 1);
		if (test_matrix.column != 3 || test_matrix.ptr[0][2] != 4 || test_matrix.ptr[1][2] != 4)
			err_cnt++;
		free_matrix(&test_matrix);
	}
	{
		matrix test_matrix;
		test_matrix.row = 2;
		test_matrix.column = 2;
		init_matrix(&test_matrix);
		test_matrix.ptr[0][0] = 1;
		test_matrix.ptr[0][1] = 2;
		test_matrix.ptr[1][0] = 3;
		test_matrix.ptr[1][1] = 4;
		add_column(&test_matrix, 1);
		if (test_matrix.column != 3 || test_matrix.ptr[0][2] != 1 || test_matrix.ptr[1][2] != 3)
			err_cnt++;
		free_matrix(&test_matrix);
	}
	printf("%s: %s\n", __func__, err_cnt ? "FAILED" : "OK");
}
void test_power_matrix(void)
{
	int err_cnt = 0;
	{
		matrix test_matrix;
		test_matrix.row = 2;
		test_matrix.column = 2;
		init_matrix(&test_matrix);
		test_matrix.ptr[0][0] = 1;
		test_matrix.ptr[0][1] = 2;
		test_matrix.ptr[1][0] = 3;
		test_matrix.ptr[1][1] = 4;
		power_matrix(&test_matrix, 2);
		if (test_matrix.ptr[0][0] != 7 || test_matrix.ptr[0][1] != 10 || test_matrix.ptr[1][0] != 15 || test_matrix.ptr[1][1] != 22)
			err_cnt++;
		free_matrix(&test_matrix);
	}
	{
		matrix test_matrix;
		test_matrix.row = 2;
		test_matrix.column = 2;
		init_matrix(&test_matrix);
		test_matrix.ptr[0][0] = 1;
		test_matrix.ptr[0][1] = 2;
		test_matrix.ptr[1][0] = 3;
		test_matrix.ptr[1][1] = 4;
		power_matrix(&test_matrix, 3);
		if (test_matrix.ptr[0][0] != 37 || test_matrix.ptr[0][1] != 54 || test_matrix.ptr[1][0] != 81 || test_matrix.ptr[1][1] != 118)
			err_cnt++;
		free_matrix(&test_matrix);
	}
	{
		matrix test_matrix;
		test_matrix.row = 2;
		test_matrix.column = 2;
		init_matrix(&test_matrix);
		test_matrix.ptr[0][0] = -1;
		test_matrix.ptr[0][1] = -2;
		test_matrix.ptr[1][0] = -3;
		test_matrix.ptr[1][1] = -4;
		power_matrix(&test_matrix, 2);
		if (test_matrix.ptr[0][0] != 7 || test_matrix.ptr[0][1] != 10 || test_matrix.ptr[1][0] != 15 || test_matrix.ptr[1][1] != 22)
			err_cnt++;
		free_matrix(&test_matrix);
	}
	printf("%s: %s\n", __func__, err_cnt ? "FAILED" : "OK");
}
void test_multip_matrix(void)
{
	int err_cnt = 0;
	{
		matrix test_matrix;
		test_matrix.row = 2;
		test_matrix.column = 2;
		init_matrix(&test_matrix);
		test_matrix.ptr[0][0] = -1;
		test_matrix.ptr[0][1] = -2;
		test_matrix.ptr[1][0] = -3;
		test_matrix.ptr[1][1] = -4;
		matrix test_matrix2;
		test_matrix2.row = 2;
		test_matrix2.column = 2;
		init_matrix(&test_matrix2);
		test_matrix2.ptr[0][0] = 4;
		test_matrix2.ptr[0][1] = 3;
		test_matrix2.ptr[1][0] = 6;
		test_matrix2.ptr[1][1] = 1;
		multip_matrix(&test_matrix, &test_matrix2);
		if (test_matrix.ptr[0][0] != -16 || test_matrix.ptr[0][1] != -5 || test_matrix.ptr[1][0] != -36 || test_matrix.ptr[1][1] != -13)
			err_cnt++;
		free_matrix(&test_matrix);
		free_matrix(&test_matrix2);
	}
	{
		matrix test_matrix;
		test_matrix.row = 2;
		test_matrix.column = 2;
		init_matrix(&test_matrix);
		test_matrix.ptr[0][0] = 1;
		test_matrix.ptr[0][1] = 2;
		test_matrix.ptr[1][0] = 3;
		test_matrix.ptr[1][1] = 4;
		matrix test_matrix2;
		test_matrix2.row = 2;
		test_matrix2.column = 2;
		init_matrix(&test_matrix2);
		test_matrix2.ptr[0][0] = 4;
		test_matrix2.ptr[0][1] = 3;
		test_matrix2.ptr[1][0] = 6;
		test_matrix2.ptr[1][1] = 1;
		multip_matrix(&test_matrix, &test_matrix2);
		if (test_matrix.ptr[0][0] != 16 || test_matrix.ptr[0][1] != 5 || test_matrix.ptr[1][0] != 36 || test_matrix.ptr[1][1] != 13)
			err_cnt++;
		free_matrix(&test_matrix);
		free_matrix(&test_matrix2);
	}
}
int main()
{
	test_delete_row();
	test_delete_column();
	test_min_row();
	test_add_column();
	test_power_matrix();
	test_multip_matrix();
	return 0;
}
