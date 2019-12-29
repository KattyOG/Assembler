#include "tree.h"
#include "hash.h"
#include "system.h"
#include <time.h>
#include <unistd.h>
unsigned long long tic(void)
{
    unsigned long long tmp;
    __asm__ __volatile__ ("rdtsc" : "=A" (tmp));
    return tmp;
}

int main()
{
    int menu;
    int count_compare_ddp = 0;
    int count_compare_avl = 0;
    int count_compare_hash = 0;
    node_struct_hash **array_op = NULL;
    int *array = NULL;
    int size = 0;
    int max = 0;

    printf("\nChoose option\n"
           "Trees:\n"
           "\t1 - Print tree\n"
           "\t2 - Print balanced tree\n"
           "\t3 - Find in tree\n"
           "\t4 - Find in balanced tree\n"
           "Hash table:\n"
           "\t5 - Create hash table\n"
           "\t6 - Print hash table\n"
           "\t7 - Find in hash table\n"
           "\t----------------------\n"
           "\t8 - Efficiency\n\n");

    while(scanf("%d", &menu) == 1)
    {
        if (menu == 1)
        {
            print_tree();
        }
        else if (menu == 2)
        {
            print_balanced_tree();
        }
        else if (menu == 3)
        {
            find_in_tree(&count_compare_ddp);
            count_compare_ddp = 0;
        }
        else if (menu == 4)
        {
            find_in_balanced_tree(&count_compare_avl);
            count_compare_avl = 0;
        }
        else if (menu == 5)
        {
            create_table(&array_op, &size, &max);
        }
        else if (menu == 6)
        {
            print_open_hash_table(array_op, size);
        }
        else if (menu == 7)
        {
            int val;
            int temp;
            if (array_op == NULL)
            {
                create_table(&array_op, &size, &max);
            }

            printf("Input value to find: ");
            scanf("%d", &val);
            temp = find_num_in_open_hash_table(array_op, size, val, &count_compare_hash);
            if (temp)
            {
                printf("Count : %d\n", count_compare_hash);
                printf("FOUND\n");
            }
            else{
                printf("Count : %d\n", count_compare_hash);
                printf("NOT FOUND\n");
            }
            count_compare_hash = 0;

        }
        else if (menu == 8)
        {
            unsigned long long tm = 0, tms = 0;
            unsigned long long time_ddp = 0;
            unsigned long long time_avl = 0;
            unsigned long long time_hash = 0;
            unsigned long long time_file = 0;
            unsigned long long memory_ddp = 0;
            unsigned long long memory_avl = 0;
            unsigned long long memory_hash= 0;
            unsigned long long memory_file = 0;
            int count_compare_file = 0;
            int value;
            node_struct *head = NULL;
            int val;
            node_struct* node = NULL;

            printf("Input value to find: ");
            scanf("%d", &val);


//proverka na znazhenie
            FILE *file;
            int proverka = 0;
            file = fopen("value.txt", "r");
            while(fscanf(file, "%d", &value) == 1){
                if (val == value){
                    proverka++;
                    break;
                }
            }
            fclose(file);

            if (proverka == 0)
            {
                printf("NO SUCH NUMBER\n");
                return EXIT_FAILURE;
            }

//time ddp


            file = fopen("value.txt", "r");
            while(fscanf(file, "%d", &value) == 1)
                head = add_node(head, create_node(value), 0);
            tm = tic();
            node = find_node(head, val, &count_compare_ddp);
            tms = tic();
            fclose(file);
            free_tree(head);
            time_ddp = tms-tm;

//time avl

            head = NULL;
            file = fopen("value.txt", "r");
            while(fscanf(file, "%d", &value) == 1)
                head = add_node(head, create_node(value), 1);
            tm = tic();
            node = find_node(head, val, &count_compare_avl);
            tms = tic();
            fclose(file);
            free_tree(head);
            time_avl = tms-tm;


//time hash

            if (array_op != NULL)
            {
                free_open_table(array_op, (size_t)size);
                array_op = NULL;
                size = 0;
            }
            create_table(&array_op, &size, &max);
            time_hash = 0;
            tm = tic();
            find_num_in_open_hash_table(array_op, size, val, &count_compare_hash);
            tms = tic();
            time_hash = tms-tm;


//time file

            file = fopen("value.txt", "r");
            time_file = 0;
            tm = tic();
            while(fscanf(file, "%d", &value) == 1)
            {
                count_compare_file++;
                if (value == val)
                {
                    tms = tic();
                    break;
                }
            }

            fclose(file);
            time_file = tms-tm;

//count numbers in file
            unsigned long long count_num_in_file = 0;
            file = fopen("value.txt", "r");
            while(fscanf(file, "%d", &value) == 1)
                count_num_in_file++;
            fclose(file);
//memory
            memory_ddp = count_num_in_file * sizeof (node_struct);
            memory_avl = count_num_in_file * sizeof (node_struct);
            memory_hash = count_num_in_file * sizeof(node_struct_hash) + sizeof (array_op);
            memory_file = 0;
//print
            printf("\tDDP\tAVL\tHASH\tFILE\n");
            printf("TIME\t%llu\t%llu\t%llu\t%llu\n", time_ddp, time_avl, time_hash, time_file);
            printf("MEMORY\t%llu\t%llu\t%llu\t%llu\n", memory_ddp, memory_avl, memory_hash, memory_file);
            printf("COUNT\t%d\t%d\t%d\t%d\n", count_compare_ddp, count_compare_avl, count_compare_hash, count_compare_file);
            count_compare_ddp = 0;
            count_compare_avl = 0;
            count_compare_hash = 0;
            count_compare_file = 0;
        }
    }
    free_open_table(array_op, (size_t)size);
    free(array);
    return 0;
}
