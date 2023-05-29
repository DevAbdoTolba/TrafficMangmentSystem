#ifndef QUEUE_H
#define QUEUE_H

struct QNode {
    int key;
    struct QNode* next;
};

struct Queue {
    struct QNode* front;
    struct QNode* rear;
};

struct QNode* newNode(int);
struct Queue* createQueue();
void enQueue(struct Queue*, int);
void deQueue(struct Queue*);

#endif  // QUEUE_H



