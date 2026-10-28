#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertend(int data) {
    struct Node *newNode = malloc(sizeof(struct Node));

    if(newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
        return;
    }

    struct Node *current = head;

    while(current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

void display() {
    struct Node *temp = head;

    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    insertend(10);
    insertend(20);
    insertend(30);

    display();

    return 0;
}
