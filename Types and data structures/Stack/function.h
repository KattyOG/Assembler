#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_SIZE 10000
struct my_stack {
	float element[MAX_SIZE];
	float *top;
	float *top2;
} typedef stack;

struct my_list {
	float value;
	struct my_list *next;
} typedef list;

unsigned long long tick(void);
void insert_list(list **head);
int pop_list(list **head, void ***ptr, int *size);
int pop_list1(list **head, void ***ptr, int *size);
int print_list(list *head);
void init(stack *stk, int size);
int insert(stack *stk, int param);
float pop(stack *stk, int param, int size);
void print(stack *stk, int size);
void print_freeded(list **head, void **ptr, int size);
void time_memory();
