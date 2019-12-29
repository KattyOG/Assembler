#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"
#define ERROR -1

node_struct* insert_node(node_struct **head, request_struct* val)
{
    node_struct *temp;
    node_struct* p = *head;
    temp = (node_struct*)malloc(sizeof(node_struct));


    temp->value = val;
    temp->next = NULL;
    if (*head == NULL)
    {
        *head = temp;
    }
    else{
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
    return temp;
}

request_struct* pop(node_struct **head)
{
    request_struct* value = (*head)->value;
    node_struct *temp;
    temp = *head;
    *head = (*head)->next;
    free(temp);
    return value;
}


 int count(node_struct *head)
 {
     int i = 0;
     while (head != NULL) {
         i ++;
         head = head->next;
     }
     return i;
 }

 float average(node_struct *p)
 {
     if (p != NULL) {
         int average = 0;
         int num = 0;
         while (p != NULL) {
             average += p->value->counter;
             num++;
             p = p->next;
         }
         return average/num;
     }
     else {
         return 0;
     }
 }


