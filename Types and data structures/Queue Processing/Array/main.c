#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "system.h"
#include "random.h"
#include <time.h>
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
    system.first_queue.count = 0;
    system.second_queue.count = 0;
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
    printf("\n");
    //    printf("Size of 1 queue: %ld\n", sizeof(system.first_queue));
    //    printf("+ 500 request: %ld\n", 500 * sizeof(request_struct));
    printf("Size of queue | 10 | 50   | 100 | 300 | 500  \n");
    printf("---------------------------------------------\n");
    printf("Memory(B)     |%ld| %ld | %ld| %ld| %ld \n", sizeof(system.first_queue) + sizeof(request_struct)*10, sizeof(system.first_queue) + sizeof(request_struct)*50, sizeof(system.first_queue) + sizeof(request_struct)*100, sizeof(system.first_queue) + sizeof(request_struct) * 300, sizeof(system.first_queue) + sizeof(request_struct)*500);
    printf("\n");
    int i = 0;
    while(system.first_queue.count > i)
    {
        free(system.first_queue.requests[i]);
        i++;
    }
    i = 0;
    while(system.second_queue.count > i)
    {
        free(system.second_queue.requests[i]);
        i++;
    }
    return 0;
}
