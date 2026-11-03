#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};


struct Node* head = NULL;

void insertEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
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

void displayList() {
    if (head == NULL) {
        printf("List is Empty\n");
        return;
    }
    struct Node* temp = head;
    printf("Current List: NULL <-> ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void deleteBeginning() {
    struct Node *temp;
    if (head == NULL) {
        printf("List is Empty\n");
        return;
    }
    temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
}

int main() {
    
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    
    printf("Initial list status:\n");
    displayList();
    
    
    printf("\nDeleting first node.\n");
    deleteBeginning();
    displayList();
    
    printf("\nDeleting next node.\n");
    deleteBeginning();
    displayList();
    
    printf("\nDeleting final node.\n");
    deleteBeginning();
    displayList();

    printf("\nTrying to delete from an empty list:\n");
    deleteBeginning();

    return 0;
}
