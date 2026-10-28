#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertend(int data) {
    struct Node *newNode = malloc(sizeof(struct Node));

    if(newNode == NULL)
        return;

    newNode->data = data;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
        return;
    }

    struct Node *current = head;

    while(current->next != NULL)
        current = current->next;

    current->next = newNode;
}

void insertposition(int data, int position) {
    if(position < 1) {
        printf("Invalid position\n");
        return;
    }

    if(position == 1) {
        struct Node *newNode = malloc(sizeof(struct Node));

        if(newNode == NULL)
            return;

        newNode->data = data;
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node *current = head;

    for(int i = 1; i < position - 1 && current != NULL; i++)
        current = current->next;

    if(current == NULL) {
        printf("Invalid position\n");
        return;
    }

    struct Node *newNode = malloc(sizeof(struct Node));

    if(newNode == NULL)
        return;

    newNode->data = data;
    newNode->next = current->next;
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
    insertend(40);

    insertposition(30, 3);

    display();

    return 0;
}
