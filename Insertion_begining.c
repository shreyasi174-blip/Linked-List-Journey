#include <stdio.h>
#include <stdlib.h>

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
    struct Node *first = malloc(sizeof(struct Node));
    struct Node *second = malloc(sizeof(struct Node));
    struct Node *third = malloc(sizeof(struct Node));

    if (first == NULL || second == NULL || third == NULL) {
        printf("Memory allocation failed.\n");
        free(first);
        free(second);
        free(third);
        return 1;
    }

    first->data = 10;
    first->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    head = first;

    printf("Original Linked List:\n");
    display();

    
    insert_beginning(5);

    printf("After Insertion at Beginning:\n");
    display();

    
    while (head != NULL) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
