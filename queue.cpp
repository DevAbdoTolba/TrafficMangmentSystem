#include "queue.h"
#include <stdio.h>
#include<stdlib.h>

void init_queue(Queue *q) {
  q->front = -1;
  q->rear = -1;
}

int is_empty(Queue *q) { return (q->front == -1 && q->rear == -1); }

int is_full(Queue *q) { return (q->rear + 1) % MAX_QUEUE_SIZE == q->front; }

void enqueue(Queue *q, Car car) {
  if (is_full(q)) {
    printf("Error: queue is full\n");
    return;
  }
  if (is_empty(q)) {
    q->front = 0;
    q->rear = 0;
  } else {
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
  }
  q->cars[q->rear] = car;
}

Car dequeue(Queue *q) {
  if (is_empty(q)) {
    printf("Error: queue is empty\n");
    Car null_car = {0, 0, ' '};
    return null_car;
  }
  Car dequeued_car = q->cars[q->front];
  if (q->front == q->rear) {
    q->front = -1;
    q->rear = -1;
  } else {
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
  }
  return dequeued_car;
}

void display_queue(Queue *q) {
  if (is_empty(q)) {
    printf("Queue is empty\n");
    return;
  }
  printf("Cars waiting at intersection:\n");
  int i = q->front;
  while (i != q->rear) {
    printf("Car %d\tArrival Time: %d\tDestination: %c\n", q->cars[i].id,
           q->cars[i].arrival_time, q->cars[i].destination);
    i = (i + 1) % MAX_QUEUE_SIZE;
  }
  printf("Car %d\tArrival Time: %d\tDestination: %c\n", q->cars[i].id,
         q->cars[i].arrival_time, q->cars[i].destination);
}