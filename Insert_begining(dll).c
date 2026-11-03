#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node * insertBeginning (struct Node *head, int data){
    struct Node *newNode;
    newNode = (struct Node *) malloc (sizeof(struct Node));
    if (newNode == NULL) {
        printf ("Memory allocation Failed");
        return head;
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
    return head;
}

void printList(struct Node *head) {
    struct Node *temp = head;
    struct Node *last = NULL;

    printf("Forward traversal:  ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        last = temp;
        temp = temp->next;
    }
    printf("NULL\n");

    printf("Backward traversal: ");
    while (last != NULL) {
        printf("%d -> ", last->data);
        last = last->prev;
    }
    printf("NULL\n\n");
}

int main() {
    
    struct Node *head = NULL;

    head = insertBeginning(head, 30);
    printList(head);

    head = insertBeginning(head, 20);
    printList(head);

    head = insertBeginning(head, 10);
    printList(head);
    
    struct Node *current = head;
    struct Node *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}
