#include "system.h"
#include "random.h"

void insert_first_request(system_struct* system)
{
    system->len_sum_first += count(&(system->first_queue));
    system->len_count_sum_first += 1;
    system->num_insert_first_request++;
    void* temp =(void*)insert_request(&(system->first_queue), create_first_request());
    if (system->need_print_adress) {
        printf("added- %p\n", temp);
    }
    return;

}

void insert_second_request(system_struct* system)
{
    system->len_sum_second += count(&(system->second_queue));
    system->len_count_sum_second += 1;
    system->num_insert_second_request++;
    void* temp = (void*)insert_request(&(system->second_queue), create_second_request());
    if (system->need_print_adress) {
        printf("added- %p\n", temp);
    }
    return;

}




request_struct* get_request_from_ques(system_struct *system) {
    request_struct* get = NULL;
    if (system->first_queue.count == 0 )
    {
        if (system->second_queue.count != 0) {
            if (system->need_print_adress) {
                printf("deleted- %p\n", (void*) (system->second_queue.requests));
            }
            system->len_sum_second += count(&(system->second_queue));
            system->len_count_sum_second += 1;
            get = pop(&(system->second_queue));
        }
    }
    else
    {
        if (system->need_print_adress) {
            printf("deleted- %p\n", (void*)system->first_queue.requests);
        }
        system->len_sum_first += count(&(system->first_queue));
        system->len_count_sum_first += 1;
        get = pop(&(system->first_queue));
    }

    return get;

}



void tick(system_struct *system)
{

    while (system->second_spawn == 0) {
        system->second_spawn = rand() % SPAWN_T2;
        insert_second_request(system);
    }

    system->time = system->time + 1;

    for (int i = 0; i < system->first_queue.count; i++) {
        system->first_queue.requests[i]->counter =  system->first_queue.requests[i]->counter + 1;
    }

    for (int i = 0; i < system->second_queue.count; i++) {
        system->second_queue.requests[i]->counter =  system->second_queue.requests[i]->counter + 1;
    }


    if (system->in_process == NULL) {
        request_struct *temp = get_request_from_ques(system);
        while (temp != NULL) {
            if (temp->work_time == 0) {
                free_request(temp, system);
                temp = get_request_from_ques(system);
            }
            else {
                break;
            }
        }
        system->in_process = temp;
    }
    if (system->in_process != NULL) {
        system->in_process->work_time = system->in_process->work_time - 1;
        if (system->in_process->work_time == 0) {
            free_request(system->in_process, system);
            system->in_process = NULL;
        }
    }

    system->first_spawn--;
    system->second_spawn--;

    if (system->first_spawn == 0) {
        insert_first_request(system);
        system->first_spawn = rand() % SPAWN_T1 + 1;
    }

    if (system->second_spawn == 0) {
        insert_second_request(system);
        system->second_spawn = rand() % SPAWN_T2;
    }
}


void print_info(system_struct* system){
    //    printf("\033[H\033[J");
    printf("\n");
    printf(" === %d sec === \n", system->time);
    printf("\n");
    printf("Number of ready first requests: %d\n", system->ready1);
    printf("Number of ready second requests: %d\n", system->ready2);
    printf("\n");
    printf("First current queue : %d\n", count(&(system->first_queue)));
    printf("Second current queue : %d\n", count(&(system->second_queue)));
    printf("\n");
    printf("Average time of waiting first: %f\n", (double) system->len_sum_first / system->len_count_sum_first);
    printf("Average time of waiting second: %f\n", (double) system->len_sum_second / system->len_count_sum_second);
    printf("\n");
    printf("Number of created first requests : %d\n", system->num_insert_first_request);
    printf("Number of created second requests : %d\n", system->num_insert_second_request);
    printf("\n");
    printf("Estimated simulation time of first(input) : %d\n", 3 * system->num_insert_first_request);
    printf("Estimated simulation time of second(input) : %f\n", 1.5 * system->num_insert_second_request);
    printf("Estimated simulation time of first(output) : %d\n", 2 * system->ready1);
    printf("Estimated simulation time of second (output): %f\n", 0.5 * system->ready2);
    printf("\n");


}

void free_request(request_struct* request, system_struct* system) {
    if (request->type == 0) {
        system->ready1 = system->ready1 + 1;
        if (system->ready1 % 100 == 0)
        {
            print_info(system);
        }
    }
    else {
        system->ready2 = system->ready2 + 1;
    }
    free(request);
}
