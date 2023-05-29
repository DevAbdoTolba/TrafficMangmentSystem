#ifndef VECTORARR_H
#define VECTORARR_H

#define VECTOR_INIT_CAPACITY 4

typedef struct vector {
    int* items;
    int capacity;
    int total;
} vector;

void vector_init(vector*);
int vector_total(vector*);

void vector_add(vector*, int);
void vector_set(vector*, int, int);
int vector_get(vector*, int);
void vector_delete(vector*, int);
#endif

