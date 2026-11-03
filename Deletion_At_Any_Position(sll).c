#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void deleteBeginning() {
    if (head == NULL) {
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
}

void deletePosition(int pos) {
    if (head == NULL) {
        printf("Empty");
        return;
    }
    if (pos == 1) {
        deleteBeginning();
        return;
    }
    
    struct Node *temp = head; 
    struct Node *prev = NULL;
    for (int i = 1; i < pos; i++) { 
        prev = temp; 
        temp = temp->next;
    }
    
    prev->next = temp->next;
    free(temp);
}

void insertEnd(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    
    if (head == NULL) {
        head = newNode;
        return;
    }
    
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void displayList() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
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
    printf("\nDeleting node at position %d. \n", pos);
    deletePosition(pos);
    
    printf("\nList after deletion:\n");
    displayList();
    
    return 0;
}
