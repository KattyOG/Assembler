#include "function.h"

unsigned long long tick(void)
{
	unsigned long long tmp;
	__asm__ __volatile__ ("rdtsc" : "=A" (tmp));
	return tmp;
}
void insert_list(list **head)
{
	srand(time(NULL));
	list *temp;
	temp = (list*)malloc(sizeof(list));
	temp->next = *head;
	temp->value = 1 + rand() % 100;
	*head = temp;
}
int pop_list(list **head, void ***ptr, int *size)
{
	list *temp;
	if (*head == NULL)
	{
		return EXIT_FAILURE;
	}

	if (*ptr == NULL) {
		*ptr = (void**)malloc(sizeof(void*));
		(*size)++;
	}
	else {
		(*size)++;
		*ptr = realloc(*ptr, (*size)*sizeof(void*));
	}
	temp = *head;
	(*ptr)[(*size)-1] = (void*)temp;
	*head = temp->next;
	printf("Freed: %p\n", (void*)temp);
	free(temp);
	return EXIT_SUCCESS;
}
int pop_list1(list **head, void ***ptr, int *size)
{
	list *temp;
	if (*head == NULL)
	{
		return EXIT_FAILURE;
	}

	if (*ptr == NULL) {
		*ptr = (void**)malloc(sizeof(void*));
		(*size)++;
	}
	else {
		(*size)++;
		*ptr = realloc(*ptr, (*size)*sizeof(void*));
	}
	temp = *head;
	(*ptr)[(*size)-1] = (void*)temp;
	*head = temp->next;
	free(temp);
	return EXIT_SUCCESS;
}
int print_list(list *head)
{
	list *p;
	if (head == NULL)
	{
		return EXIT_FAILURE;
	}
	p = head;
	do {
		printf("%f - %p ", p->value, (void*)p);
		p = p->next;
	} while (p != NULL);
	printf("\n");
	return EXIT_SUCCESS;
}

void init(stack *stk, int size)
{
	stk->top = stk->element - 1;
	stk->top2 = stk->element + size;
	for (int i = 0; i < size; i++)
		stk->element[i] = 0;
}

int insert(stack *stk, int param)
{
	srand(time(NULL));
	if (param && (stk->top + 1 < stk->top2))
	{
		(stk->top)++;
		*(stk->top) = 1 + rand() % 100;
	}
	else if (stk->top2 -1 > stk->top)
	{
		(stk->top2)--;
		*(stk->top2) = 1 + rand() % 100;
	}
	else
		return EXIT_FAILURE;
	return EXIT_SUCCESS;
}

float pop(stack *stk, int param, int size)
{
	float elem;
	if(param)
	{
		if (stk->top >= stk->element)
		{
			elem = *(stk->top);
			(stk->top)--;
			return(elem);
		}
		else
			return EXIT_FAILURE;
	}
	else
	{
		if (stk->top2 < stk->element + size)
		{
			elem = *(stk->top2);
			(stk->top2)++;
			return(elem);
		}
		else
			return EXIT_FAILURE;
	}
}
void print(stack *stk, int size)
{
	float *i = stk->element;
	float *j = stk->top2;
	while (i <= stk->top)
	{
		printf("%f ", *(i));
		(i)++;
	}
	printf("|");
	while (j < stk->element + size)
	{
		printf("%f ", *(j));
		(j)++;
	}
	printf("\n");
}
void print_freeded(list **head, void **ptr, int size)
{
	for(int i = 0; i < size; i++)
	{
		printf("%p\n", (ptr)[i]);
	}
}
void time_memory()
{
	stack temp;
	void** ptr = NULL;
	list* head = NULL;
	unsigned long long tm, tms;
	init(&temp, 10000);
	tms = 0;
	for (int i = 0; i < 10000; i++) {
		tm = tick();
		insert(&temp, 0);
		tm = tick() - tm;
		tms += tm;
	}
	printf("\nArray insert  = %llu }\n", tms);
	printf("\nArray size = %ld B \n", sizeof(stack)*100);
	tms = 0;
	for (int i = 0; i < 10000; i++) {
		tm = tick();
		pop(&temp, 1, 10000);
		tm = tick() - tm;
		tms += tm;
	}
	printf("\nArray pop  = %llu }\n", tms);

	tms = 0;
	for (int i = 0; i < 100000; i++) {
		tm = tick();
		insert_list(&head);
		tm = tick() - tm;
		tms += tm;
	}
	printf("\nList insert  = %llu }\n", tms);
	printf("\nList size = %ld B \n", sizeof(list) * 10000);
	tms = 0;
	int size = 0;
	for (int i = 0; i < 10000; i++) {
		tm = tick();
		pop_list1(&head, &ptr, &size);
		tm = tick() - tm;
		tms += tm;
	}
	free(head);
	free(ptr);
	printf("\nList pop  = %llu }\n", tms);
}
