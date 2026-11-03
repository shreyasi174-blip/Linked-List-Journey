#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char song[50];
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *current = NULL;

struct Node* createNode(char name[])
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    strcpy(newNode->song, name);

    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

void insertSong(char name[])
{
    struct Node *newNode = createNode(name);
    struct Node *temp;

    if(head == NULL)
    {
        head = newNode;
        head->next = head;
        head->prev = head;
        current = head;
        return;
    }

    temp = head->prev;

    temp->next = newNode;
    newNode->prev = temp;

    newNode->next = head;
    head->prev = newNode;

    printf("Song added successfully!\n");
}

void display()
{
    struct Node *temp;

    if(head == NULL)
    {
        printf("Playlist is empty!\n");
        return;
    }

    temp = head;

    printf("\n--- Spotify Playlist ---\n");

    do
    {
        printf("%s\n", temp->song);
        temp = temp->next;
    }
    while(temp != head);
}

void playSong()
{
    if(current == NULL)
    {
        printf("No song available!\n");
        return;
    }

    printf("\nNow Playing: %s\n", current->song);
}

void nextSong()
{
    if(current == NULL)
    {
        printf("Playlist is empty!\n");
        return;
    }

    current = current->next;
    playSong();
}

void previousSong()
{
    if(current == NULL)
    {
        printf("Playlist is empty!\n");
        return;
    }

    if(current->prev == NULL)
    {
        printf("Previous song is not available in CLL!\n");
        return;
    }

    current = current->prev;
    playSong();
}

void searchSong(char name[])
{
    struct Node *temp;

    if(head == NULL)
    {
        printf("Playlist is empty!\n");
        return;
    }

    temp = head;

    do
    {
        if(strcmp(temp->song, name) == 0)
        {
            printf("Song found: %s\n", temp->song);
            return;
        }

        temp = temp->next;

    }while(temp != head);

    printf("Song not found!\n");
}

void deleteSong(char name[])
{
    struct Node *temp;

    if(head == NULL)
    {
        printf("Playlist is empty!\n");
        return;
    }

    temp = head;

    do
    {
        if(strcmp(temp->song, name) == 0)
        {
            if(temp->next == temp)
            {
                head = NULL;
                current = NULL;
            }
            else
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;

                if(temp == head)
                    head = temp->next;

                if(temp == current)
                    current = temp->next;
            }

            free(temp);

            printf("Song deleted successfully!\n");
            return;
        }

        temp = temp->next;

    }while(temp != head);

    printf("Song not found!\n");
}

void convertToDLL()
{
    struct Node *last;

    if(head == NULL)
    {
        printf("Playlist is empty!\n");
        return;
    }

    last = head->prev;

    last->next = NULL;
    head->prev = NULL;

    printf("Converted to Doubly Linked List!\n");
}

void convertToDCLL()
{
    struct Node *temp;

    if(head == NULL)
    {
        printf("Playlist is empty!\n");
        return;
    }

    if(head->prev != NULL)
    {
        printf("Already in DCLL!\n");
        return;
    }

    temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = head;
    head->prev = temp;

    printf("Converted to Doubly Circular Linked List!\n");
}

void convertToCLL()
{
    struct Node *temp;

    if(head == NULL)
    {
        printf("Playlist is empty!\n");
        return;
    }

    temp = head;

    do
    {
        temp->prev = NULL;
        temp = temp->next;

    }while(temp != head);

    printf("Converted to Circular Linked List!\n");
}

int main()
{
    int choice;
    char name[50];

    do
    {
        printf("\n===== SPOTIFY CLONE =====\n");
        printf("1. Add Song\n");
        printf("2. Display Playlist\n");
        printf("3. Play Current Song\n");
        printf("4. Next Song\n");
        printf("5. Previous Song\n");
        printf("6. Search Song\n");
        printf("7. Delete Song\n");
        printf("8. Convert to DLL\n");
        printf("9. Convert to DCLL\n");
        printf("10. Convert to CLL\n");
        printf("11. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter song name: ");
                scanf(" %[^\n]", name);
                insertSong(name);
                break;

            case 2:
                display();
                break;

            case 3:
                playSong();
                break;

            case 4:
                nextSong();
                break;

            case 5:
                previousSong();
                break;

            case 6:
                printf("Enter song name to search: ");
                scanf(" %[^\n]", name);
                searchSong(name);
                break;

            case 7:
                printf("Enter song name to delete: ");
                scanf(" %[^\n]", name);
                deleteSong(name);
                break;

            case 8:
                convertToDLL();
                break;

            case 9:
                convertToDCLL();
                break;

            case 10:
                convertToCLL();
                break;

            case 11:
                printf("Exiting Spotify Clone...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    }while(choice != 11);

    return 0;
}
