#ifndef STACK_H
#define STACK_H

#define stack_INIT_CAPACITY 4

typedef struct stack {
    int* items;
    int capacity;
    int top;
} stack;

void stack_init(stack*);
int gettop(stack*);

void push(stack*, int);
void stack_set(stack*);
int stack_get(stack*, int);
void pop(stack*);
int findmin(stack*);
void isfull(stack*);
#endif

