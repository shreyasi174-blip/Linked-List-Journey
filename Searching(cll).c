#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert(int value) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    
    if (head == NULL) {
        head = newNode;
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void search (int key){
    if (head == NULL){
        printf("Empty");
        return;
    }
    struct node *temp = head;
    int position = 1;
    while (temp != NULL){
        if (temp->data == key){
            printf("Element found at %d",position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Elements Not Found");
}

int main() {
    
    insert(20);
    insert(30);
    insert(40);
    insert(50);

    int searchKey = 40;
    printf("Searching for %d:\n", searchKey);
    search(searchKey);
    
    printf("\n\nSearching for 99:\n");
    search(99);

    return 0;
}
