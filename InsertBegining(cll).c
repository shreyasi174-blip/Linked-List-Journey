#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;


void insertBeginning (int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }
    struct Node *temp = head; // temp = 1200
    while (temp->next != head) { // temp->next = 1111
        temp = temp->next; // 1 temp = 1111
    }
    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head: %d)\n", head->data);
}

int main() {
    insertBeginning(40);
    insertBeginning(30);
    insertBeginning(20);
    insertBeginning(10);
    
    
    displayList();
    insertBeginning(5);
    displayList();

    return 0;
}
