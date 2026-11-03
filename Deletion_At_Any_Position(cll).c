#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void deletePosition(int pos) {
    if (head == NULL) {
        printf("Empty");
        return;
    }

    if (pos < 1) {
        printf("Invalid position");
        return;
    }

    if (pos == 1) {
        struct Node* temp = head;

        if (head->next == head) {
            head = NULL;
            free(temp);
            return;
        }

        struct Node* current = head;

        while (current->next != head) {
            current = current->next;
        }

        head = head->next;
        current->next = head;
        free(temp);
        return;
    }

    struct Node *temp = head;
    struct Node *prev = NULL;

    for (int i = 1; i < pos && temp->next != head; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp->next == head && pos > 2) {
        printf("Invalid position");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void insertEnd(int val) {
    struct Node* newNode = malloc(sizeof(struct Node));

    if (newNode == NULL)
        return;

    newNode->data = val;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    struct Node* temp = head;

    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}

void displayList() {
    if (head == NULL) {
        printf("Empty List\n");
        return;
    }

    struct Node* temp = head;

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("HEAD\n");
}

int main() {
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);
    insertEnd(50);

    printf("Original List:\n");
    displayList();

    int pos = 3;

    printf("\nDeleting node at position %d.\n", pos);
    deletePosition(pos);

    printf("\nList after deletion:\n");
    displayList();

    return 0;
}
