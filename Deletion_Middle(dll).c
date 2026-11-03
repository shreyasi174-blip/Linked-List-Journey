#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* prev;
    int data;
    struct Node* next;
};

struct Node* head = NULL;


void deleteMiddle(int position) {
    struct Node *current;
    if (head == NULL) {
        printf("List is Empty\n");
        return;
    }
    current = head;
    for (int i = 1; i < position && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Invalid position\n");
        return;
    }
    if (current->prev == NULL || current->next == NULL) {
        printf("Not a Middle position\n");
        return;
    }
    current->prev->next = current->next;
    current->next->prev = current->prev;
    free(current);
}

void insert(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
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

void printList() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Current List: NULL <-> ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(40);

    printList();
    deleteMiddle(1);
    deleteMiddle(3);
    printList();

    deleteMiddle(2);
    printList();

    
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
