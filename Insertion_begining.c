#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert_beginning(int data) {
    struct Node *new_node = malloc(sizeof(struct Node));

    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void display() {
    struct Node *current = head;

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

int main() {
    insert_beginning(30);
    insert_beginning(20);
    insert_beginning(10);

    display();

    return 0;
}
