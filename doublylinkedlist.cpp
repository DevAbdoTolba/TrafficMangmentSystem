#include"doublylinkedlist.h"

#include<stdio.h>
#include<stdlib.h>


void insertLast(struct Node** head, int data);
void insertStart(struct Node** head, int data);

int calcSize(struct Node* node)
{
    int size = 0;

    while (node != NULL)
    {
        node = node->next;
        size++;
    }
    return size;
}

void insertPosition(int pos, int data, struct Node** head)
{
    int size = calcSize(*head);

    if (pos < 0 || size < pos)
    {
        printf("Can't insert, %d is not a valid position\n", pos);
        return;
    }

    if (pos == 0)
        insertStart(head, data);

    else if (pos == size)
        insertLast(head, data);

    else
    {
        struct Node* temp = *head;
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;
        while (--pos)
            temp = temp->next;
        struct Node* temp2 = temp->next;
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next = newNode;
        temp2->prev = newNode;
    }
}

void insertLast(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        newNode->prev = NULL;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void insertStart(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    newNode->prev = NULL;
    if (*head != NULL)
        (*head)->prev = newNode;
    *head = newNode;
}
void display (struct Node *node)
{
  struct Node *end = NULL; 
  printf ("List in Forward direction: ");
  while (node != NULL)
    {
      printf (" %d ", node->data);
      end = node;
      node = node->next;
    }
  printf ("\nList in backward direction: ");
  while (end != NULL)
    {
      printf (" %d ", end->data);
      end = end->prev;
    }
}


