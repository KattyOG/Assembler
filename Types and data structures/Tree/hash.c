#include "hash.h"

int hash_func(int elem, int size)
{
    return elem % size ;
}

void insert_node(node_struct_hash **head, node_struct_hash *node)
{
    if (*head)
    {
        node_struct_hash *temp = *head;
        while(temp->next)
        {
            temp = temp->next;
        }
        temp->next = node;
    }
    else
        *head = node;
}

node_struct_hash* create_hash_node(int value)
{
    node_struct_hash *node = malloc(sizeof(node_struct_hash));
    node->value = value;
    node->next = NULL;

    return node;
}
int len(node_struct_hash* head)
{
    node_struct_hash* current = head;
    int count = 0;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}
int insert_open_hash_table(node_struct_hash ***array, size_t size, int max)
{
    FILE *file;
    int value;
    int position;

    *array = malloc(size * sizeof(node_struct_hash*));
    for (int i = 0; i < (int)size; i++)
        (*array)[i] = NULL;
    file = fopen("value.txt", "r");

    while(fscanf(file, "%d", &value) == 1)
    {
        position = hash_func(value, (int)size);
        insert_node(&((*array)[position]), create_hash_node(value));
    }
    for (int i = 0; i < (int)size; i++) {
        if (len((*array)[i]) > max) {
            return EXIT_FAILURE;
        }
    }
    fclose(file);
    return EXIT_SUCCESS;
}
void create_table(node_struct_hash ***array_op, int *size, int *max)
{
    FILE *file;
    int value;
    int temp;
    file = fopen("value.txt", "r");
    while(fscanf(file, "%d", &value) == 1)
        *size = *size + 1;
    fclose(file);
    printf("Input max compare: ");
    scanf("%d", max);

    temp = insert_open_hash_table(array_op, (size_t)*size, *max);
    printf("Initial table: \n");
    print_open_hash_table(*array_op, *size);

    if (temp == EXIT_FAILURE) {
        free_open_table(*array_op, (size_t)*size);
        *array_op = NULL;
        *size = 1;
        while (insert_open_hash_table(array_op, (size_t)*size, *max) == EXIT_FAILURE) {
            *size = *size * 2;
        }
    }
}
int find_num_in_open_hash_table(node_struct_hash **array, int size, int value, int *count)
{
    int i = hash_func(value, size);
    node_struct_hash *arr = array[i];
    while(arr)
    {
        (*count)++;
        if (arr->value == value)
        {
            return 1;
        }
        arr = arr->next;
    }

    return 0;
}

void print_open_hash_table(node_struct_hash **array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", i);
        node_struct_hash *temp = array[i];
        if (temp)
        {
            while(temp->next)
            {
                printf (" -> %d", temp->value);
                temp = temp->next;
            }
            printf (" -> %d", temp->value);
            printf(" -> NULL\n");
        }
        else printf(" -> NULL\n");
        printf("\n");
    }
    printf("\n");
}

void free_open_table(node_struct_hash **array, size_t size)
{
    node_struct_hash *temp;
    for(int i = 0; i < (int)size; i++)
    {
        while((array)[i] != NULL)
        {
            temp = (array)[i];
            (array)[i] = (array)[i]->next;
            free(temp);
        }
    }
    free(array);
}

