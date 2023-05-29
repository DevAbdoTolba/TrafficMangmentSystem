#ifndef DOUBLYLINKEDLIST_H

#define DOUBLYLINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

void insertLast(struct Node** head, int data);
void insertStart(struct Node** head, int data);
void insertPosition(int pos, int data, struct Node** head);
int calcSize(struct Node* node);
void display (struct Node *node);


#endif 