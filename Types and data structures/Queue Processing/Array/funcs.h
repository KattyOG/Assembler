#ifndef FUNCS_H
#define FUNCS_H

#include "request.h"

typedef struct queue {
    request_struct* requests[500];
    int count;
}  queue_struct;

request_struct** insert_request(queue_struct *queue, request_struct* val);
request_struct* pop(queue_struct *queue);
int count(queue_struct *queue);
float average(queue_struct *queue);

#endif // FUNCS_H
