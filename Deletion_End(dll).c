#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* prev;
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void deleteEnd() {
    struct Node *current;
    if (head == NULL) {
        printf("List is Empty");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    
    current = head; 
    while (current->next != NULL) {
        current = current->next;
    }
    current->prev->next = NULL;
    free(current);
}

void insertEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }
    
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void printList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    
    printf("Before deletion:\n");
    printList();
    deleteEnd();
    printList();
    deleteEnd();
    
    printf("\nAfter second deletion:\n");
    printList();
    
    return 0;
}
