#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node * insertMiddle(struct Node *head, int data, int position){
    if (position <= 1){
        printf("Invalid Position\n");
        return head;
    }
    else {
        struct Node *newNode;
        struct Node *current;
        newNode = (struct Node*) malloc(sizeof(struct Node));
        if (newNode == NULL){
            printf("Memory allocation failed.");
            return head;
        }
        newNode->data = data;
        current = head;
        
        for (int i = 1; i < position - 1 && current != NULL; i++){
            current = current->next;
        }
        if (current == NULL){
            printf("Invalid Middle position.");
            free(newNode);
            return (head);
        }
        
        newNode->prev = current;
        newNode->next = current->next;
        current->next = newNode;
        newNode->next->prev = newNode;
        return head;
    }
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) return NULL;
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    struct Node* last = NULL;
    
    printf("Forward:  ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        last = temp;
        temp = temp->next;
    }
    printf("NULL\n");
    
    printf("Backward: ");
    while (last != NULL) {
        printf("%d -> ", last->data);
        last = last->prev;
    }
    printf("NULL\n\n");
}


int main() {
  
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->prev = head;
    
    head->next->next = createNode(30);
    head->next->next->prev = head->next;
    
    head->next->next->next = createNode(40);
    head->next->next->next->prev = head->next->next;

    printf("Initial List:\n");
    printList(head);

    
    int newData = 25;
    int position = 3;
    printf("Inserting %d at position %d:\n", newData, position);
    head = insertMiddle(head, newData, position);
    printList(head);

  
    struct Node* current = head;
    while (current != NULL) {
        struct Node* next = current->next;
        free(current);
        current = next;
    }

    return 0;
}
