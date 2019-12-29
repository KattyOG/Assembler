#include "tree.h"
#include "hash.h"

void print_tree()
{
    FILE *file;
    int value;
    node_struct *head = NULL;
    file = fopen("value.txt", "r");
    while(fscanf(file, "%d", &value) == 1)
        head = add_node(head, create_node(value), 0);
    walk_tree(head, NULL);
    fclose(file);
    printf("Inorder :");
    inorder(head);
    printf("\n------------------------------\n");
    printf("Preorder :");
    preorder(head);
    printf("\n------------------------------\n");
    printf("Postorder :");
    postorder(head);
    printf("\n------------------------------\n");
    free_tree(head);
}

void print_balanced_tree()
{
    FILE *file;
    int value;
    node_struct *head = NULL;
    file = fopen("value.txt", "r");
    while(fscanf(file, "%d", &value) == 1)
        head = add_node(head, create_node(value), 1);
    walk_tree(head, NULL);
    fclose(file);
    printf("Inorder :");
    inorder(head);
    printf("\n------------------------------\n");
    printf("Preorder :");
    preorder(head);
    printf("\n------------------------------\n");
    printf("Postorder :");
    postorder(head);
    printf("\n------------------------------\n");
    free_tree(head);
}

int find_in_tree(int *count_compare_ddp)
{
    FILE *file;
    int value;
    node_struct *head = NULL;
    int val;
    printf("Input value to find: ");
    scanf("%d", &val);
    file = fopen("value.txt", "r");
    while(fscanf(file, "%d", &value) == 1)
        head = add_node(head, create_node(value), 0);
    node_struct *temp = find_node(head, val, count_compare_ddp);
    if (temp == NULL)
    {
        printf("Count compare : %d\n", *count_compare_ddp);
        free_tree(head);
        return EXIT_FAILURE;
    }
    walk_tree(head, temp);
    fclose(file);
    printf("Count compare : %d\n", *count_compare_ddp);
    free_tree(head);
    return EXIT_SUCCESS;
}

int find_in_balanced_tree(int *count_compare_avl)
{
    FILE *file;
    int value;
    node_struct *head = NULL;
    int val;
    printf("Input value to find: ");
    scanf("%d", &val);
    file = fopen("value.txt", "r");
    while(fscanf(file, "%d", &value) == 1)
        head = add_node(head, create_node(value), 1);
    node_struct *temp = find_node(head, val, count_compare_avl);
    if (temp == NULL)
    {
        printf("Count compare : %d\n", *count_compare_avl);
        free_tree(head);
        return EXIT_FAILURE;
    }
    walk_tree(head, temp);
    fclose(file);
    printf("Count compare : %d\n", *count_compare_avl);
    free_tree(head);
    return EXIT_SUCCESS;
}
