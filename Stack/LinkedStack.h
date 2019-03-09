#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H
#include "Item.h"
#include <stdbool.h>

typedef struct stack_struct
{
 int size;
 item* top;
 } stack;

void initialize(stack* s);
void push(stack* s,char* str);
void pop(stack* s, char* str);
void peek(stack* s, char* str);
bool is_empty(stack* s);
int get_length(stack* s);
void display(stack* s);

#endif