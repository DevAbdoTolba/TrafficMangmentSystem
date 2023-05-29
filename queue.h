#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE_SIZE 12

typedef struct Car {
  int id;
  int arrival_time;
  char destination;
} Car;

typedef struct Queue {
  Car cars[MAX_QUEUE_SIZE];
  int front, rear;
} Queue;

void init_queue(Queue *q);
int is_empty(Queue *q);
int is_full(Queue *q);
void enqueue(Queue *q, Car car);
Car dequeue(Queue *q);
void display_queue(Queue *q);

#endif