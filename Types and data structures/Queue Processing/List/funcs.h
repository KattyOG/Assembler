#ifndef FUNCS_H
#define FUNCS_H

#include "request.h"
#include <time.h>
typedef struct node {
    request_struct* value;
    struct node *next;
}  node_struct;

node_struct* insert_node(node_struct **head, request_struct* val);
request_struct* pop(node_struct **head);
int count(node_struct *head);
float average(node_struct *p);

#endif // FUNCS_H
