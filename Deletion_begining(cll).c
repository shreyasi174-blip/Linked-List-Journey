#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void deleteBeginning() {
    if (head == NULL) {
        printf("List is Empty\n");
        return;
    }
    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }
    struct Node *temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    struct Node *deleteNode = head;
    head = head->next;
    temp->next = head;
    free(deleteNode);
}

void insertEnd(int val) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }
    
    struct Node *temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
}


void printList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head: %d)\n", head->data);
}

int main() {
  
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);

    printf("Original Circular Linked List:\n");
    printList();

    
    printf("\nDeleting from beginning...\n");
    deleteBeginning();

    printf("List after first deletion:\n");
    printList();

    
    printf("\nDeleting from beginning...\n");
    deleteBeginning();

    printf("List after second deletion:\n");
    printList();

    return 0;
}
