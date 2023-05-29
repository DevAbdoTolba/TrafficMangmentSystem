#ifndef SINGLYLINKEDLIST
#define SINGLYLINKEDLIST_H

struct Node {
  int data;
  struct Node* next;
};

void insertAtBeginning(struct Node** head_ref, int new_data);
void insertAfter(struct Node* prev_node, int new_data);
void insertAtEnd(struct Node** head_ref, int new_data);
void deleteNode(struct Node** head_ref, int key);
int searchNode(struct Node** head_ref, int key);
void sortLinkedList(struct Node** head_ref);
void printList(struct Node* node);

#endif  // LINKED_LIST_H
