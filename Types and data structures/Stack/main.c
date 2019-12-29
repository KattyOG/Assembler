#include "function.h"

int main()
{
	stack stk;
	void** ptr = NULL;
	int size = 0;
	list* head = NULL;
	init(&stk, MAX_SIZE);
	int temp;
	int temp2;
	int temp3 = 0;
	printf("Menu \n");
	printf("1 - Add one element to first stack\n");
	printf("2 - Delete one element from first stack\n");
	printf("3 - Add one element to second stack\n");
	printf("4 - Delete one element from second stack\n");
	printf("5 - Print stacks on the screen\n");
	printf("6 - Add one element to list\n");
	printf("7 - Delete one element from list\n");
	printf("8 - Print list on the screen\n");
	printf("9 - Print freeded adresses\n");
	printf("10 - Measure time and memory\n");
	printf("0 - Exit\n");

	while (scanf("%d", &temp) == 1 )
	{
		if (temp == 1)
		{
			temp2 = insert(&stk, 1);
			if (temp2 == EXIT_FAILURE)
			{
				printf("No place\n");
			}
		}
		else if (temp == 2)
		{
			if (pop(&stk, 1, MAX_SIZE) == EXIT_FAILURE)
			{
				printf("No elements to delete\n");
			}
		}
		else if (temp == 3)
		{
			temp2 = insert(&stk, 0);
			if (temp2 == EXIT_FAILURE)
			{
				printf("No place\n");
			}
		}
		else if (temp == 4)
		{
			if (pop(&stk, 0, MAX_SIZE) == EXIT_FAILURE)
			{
				printf("No elements to delete\n");
			}
		}
		else if (temp == 5)
		{
			print(&stk, MAX_SIZE);
		}
		else if (temp == 6)
		{
			insert_list(&head);
		}
		else if (temp == 7)
		{
			temp3 = pop_list(&head, &ptr, &size);
			if (temp3 == EXIT_FAILURE)
			{
				printf("No elements to delete\n");
			}
		}
		else if (temp == 8)
		{
			if (print_list(head) == EXIT_FAILURE)
			{
				printf("Nothing to output\n");
			}
		}
		else if (temp == 9)
		{
			print_freeded(&head, ptr, size);
		}
		else if (temp == 10)
		{
			time_memory();
		}
		else if (temp == 0)
		{
			while(pop_list(&head, &ptr, &size) != EXIT_FAILURE);
			free(head);
			free(ptr);
			return 0;
		}
	}
	printf("Input error\n");
	return EXIT_FAILURE;
}
