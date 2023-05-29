#include "vectorarr.h"

#include <stdio.h>
#include <stdlib.h>


void vector_init(vector* v)
{
    v->capacity = VECTOR_INIT_CAPACITY;
    v->total = 0;
    v->items = (int *)malloc(sizeof(void*) * 4);// allocation 4 places for items
}


int vector_total(vector* v)
{
    return v->total;

}


void vector_add(vector* v, int item)
{
    if (v->total <= v->capacity) { v->items[v->total] = item; v->total++; }
    

    }

  void  vector_set(vector * v, int index, int item)
    {
        if (index >= 0 && index < v->total)
            v->items[index] = item;

    }

  int vector_get(vector* v, int index)
  {
      if (v->total >= index) {
          return v->items[index];
      }
  
  }
 
       

    

    void vector_delete(vector * v, int index)
    {
        if (index < 0 || index >= v->total)
            return;

        v->items[index] = NULL;

        for (int i = index; i <= v->total; i++) {
            v->items[i] = v->items[i + 1];
            
        }

        v->total--;


        }


