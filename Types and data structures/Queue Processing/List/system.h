#ifndef SYSTEM_H
#define SYSTEM_H

#include "funcs.h"
#include <stdio.h>
#include <time.h>
typedef struct system {
    node_struct* first_queue;
    node_struct* second_queue;
    request_struct* in_process;

    int time;
    int num_insert_first_request;
    int num_insert_second_request;

    int ready1;
    int ready2;

    int first_spawn;
    int second_spawn;

    int need_print_adress;

    int len_sum_first;
    int len_sum_second;
    int len_count_sum_first;
    int len_count_sum_second;

}  system_struct;



void insert_first_request(system_struct* system);
void insert_second_request(system_struct* system);
request_struct* get_request_from_ques(system_struct *system);
void free_request(request_struct* request, system_struct* system);

void tick(system_struct *system);
void print_info(system_struct* system);

#endif // SYSTEM_H
