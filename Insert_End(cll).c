#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


struct Node* head = NULL;
 
void insertAtEnd (int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode -> data = value;
    if (head == NULL) {
        head = newNode;
        newNode -> next = head;
        return;
    }
    struct Node *temp = head;
    while (temp -> next != head) 
        temp = temp -> next;
    }
    temp -> next = newNode;
    newNode -> next = head;
}

void printList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    
    printf("(head: %d)\n", head->data);
}

int main() {
  
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40);
    insertAtEnd(50);
    printList();

    return 0;
}
