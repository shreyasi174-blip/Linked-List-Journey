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

void deletebegining() {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;
    free(temp);
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

    deletebegining();

    display();

    return 0;
}
