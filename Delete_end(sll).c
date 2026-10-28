#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert(int data) {
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

void deleteend() {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    if(head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct Node *current = head;

    while(current->next->next != NULL)
        current = current->next;

    free(current->next);
    current->next = NULL;
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
    insert(10);
    insert(20);
    insert(30);

    deleteend();

    display();

    return 0;
}
