#include "request.h"
#include "random.h"
request_struct *create_first_request() {
    request_struct *s =  (request_struct*) malloc(sizeof(request_struct));
    s->counter = 0;
    s->work_time = rand() % SERVSE_T3;
    s->type = 0;
    return s;
}

request_struct *create_second_request() {
    request_struct *s =  (request_struct*) malloc(sizeof(request_struct));
    s->counter = 0;
    s->work_time = rand() % SERVSE_T4;
    s->type = 1;
    return s;
}
