#ifndef REQUEST_H
#define REQUEST_H

#include <stdlib.h>

typedef struct request
{
    int type; // first = 0 ; second = 1
    int counter;
    int work_time;
} request_struct;

request_struct* create_first_request(void);
request_struct* create_second_request(void);


#endif // REQUEST_H
