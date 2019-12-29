#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"
#define ERROR -1

request_struct** insert_request(queue_struct *queue, request_struct* val)
{
    queue->requests[queue->count] = val;
    queue->count = queue->count + 1;
    return &(queue->requests[queue->count -1]);
}

request_struct* pop(queue_struct *queue)
{
    if (queue->count == 0) {
        return NULL;
    }
    request_struct* value = queue->requests[0];
    for (int i = 0; i < queue->count -1; i++) {
        queue->requests[i] = queue->requests[i+1];
    }
    queue->count = queue->count - 1;
    return value;
}


int count(queue_struct *queue)
 {
     return queue->count;
 }

float average(queue_struct *queue)
 {
     if (queue->count) {
         int average = 0;
         int num = 0;
        for (int i =0; i < queue->count; i++) {
             average += queue->requests[i]->counter;
             num++;
         }
         return average/num;
     }
     else {
         return 0;
     }
 }

