#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "system.h"
#include "random.h"
unsigned long long tic(void)
{
    unsigned long long tmp;
    __asm__ __volatile__ ("rdtsc" : "=A" (tmp));
    return tmp;
}

int main()
{
    srand(time(NULL));
    unsigned long long tm, tms;


    system_struct system;
    system.first_queue = NULL;
    system.second_queue = NULL;
    system.in_process = NULL;

    system.time = 0;
    system.num_insert_first_request = 0;
    system.num_insert_second_request = 0;

    system.ready1 = 0;
    system.ready2 = 0;

    system.first_spawn = rand() % SPAWN_T1 + 1;
    system.second_spawn = rand() % SPAWN_T2;

    system.len_sum_first = 0;
    system.len_sum_second = 0;
    system.len_count_sum_first = 0;
    system.len_count_sum_second = 0;

    printf("Do you want to see adress ?\n 1 - yes\n 0 - no\n");
    scanf("%d", &system.need_print_adress);

    tm = tic();
    while(system.ready1 < 1000)
    {
        tick(&system);
    }
    tms = tic();
    printf("Ticks: %lld\n", tms-tm);
    //    printf("Size of 1 element queue: %ld\n", sizeof(node_struct));
    //    printf("+ 1 request: %ld\n", 1 * sizeof(request_struct));
    //    printf("* 500: %d\n", (16+12)*500);
    printf("\n");
    printf("Size of queue | 10 | 50   | 100 | 300 | 500  | 1000\n");
    printf("------------------------------------------------------\n");
    printf("Memory(B)     | %d| %d | %d| %d| %d| %d\n", 28*10, 28*50, 28*100, 28 * 300, 28*500, 28*1000);
    printf("\n");
    node_struct* temp;
    while (system.first_queue != NULL)
    {
        temp = system.first_queue;
        system.first_queue = system.first_queue->next;
        free(temp->value);
        free(temp);
    }
    while (system.second_queue != NULL)
    {
        temp = system.second_queue;
        system.second_queue = system.second_queue->next;
        free(temp->value);
        free(temp);
    }

    return 0;
}
