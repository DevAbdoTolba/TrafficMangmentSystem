
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

void stack_init(stack* v)
{
    v->capacity = stack_INIT_CAPACITY;
    v->top = 0;
    v->items = (int *)malloc(sizeof(void*) * 4);
}


int gettop(stack* v)
{
    return v->top;

}


void push(stack* v, int item)
{
    if (v->top <= v->capacity-1) { v->items[v->top] = item; v->top++; }
    

    }

void  isempty(stack* v)
{
    if (v->top == 0)
        printf("the stack is empty");
    else
        printf("tthe stack isn't empty");
       
    }

  int stack_get(stack* v, int index)
  {
      if (v->top >= index) {
          return v->items[index];
      }
  
  }
 
  int findmin(stack* v) {
      int min=0;
      for (int i = 0; i < v->capacity; i++) {
          if (min > v->items[i])
              min = v->items[i];
      }
      return min;
  
  }

    

    void pop(stack * v)
    {
        if (  v->top==0)
            return;

        v->items[v->top] = NULL;

     

        v->top--;


        }
    void isfull(stack* v) {
        if (v->top == v->capacity - 1)
            printf("stack is full");
        else
            printf("stack is not full");

    }

