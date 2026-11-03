#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};


struct Node *head = NULL;


void insertAtEnd(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

void displayList() {
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


void deleteFromEnd() {
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
    struct Node *prev = NULL;
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = head;
    free(temp);
}

int main() {
    
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40);

    printf("Original Circular Linked List:\n");
    displayList();

    printf("\nDeleting from end.\n");
    deleteFromEnd();
    displayList();
     
    printf("\nDeleting from end.\n");
    deleteFromEnd();
    displayList();

    return 0;
}
