#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    char song[50];
    struct node *prev;
    struct node *next;
};
struct node *head = NULL;
struct node *current = NULL;
struct node *deletedHead = NULL;
void insertBeginning(char song[])
{
    struct node *newnode = malloc(sizeof(struct node));

    if(newnode == NULL)
        return;

    strcpy(newnode->song, song);

    if(head == NULL)
    {
        head = newnode;
        newnode->next = head;
        newnode->prev = head;
        current = head;
    }
    else
    {
        struct node *last = head->prev;

        newnode->next = head;
        newnode->prev = last;

        last->next = newnode;
        head->prev = newnode;

        head = newnode;
    }
}
void insertEnd(char song[])
{
    struct node *newnode = malloc(sizeof(struct node));

    if(newnode == NULL)
        return;

    strcpy(newnode->song, song);

    if(head == NULL)
    {
        head = newnode;
        newnode->next = head;
        newnode->prev = head;
        current = head;
    }
    else
    {
        struct node *last = head->prev;

        newnode->next = head;
        newnode->prev = last;

        last->next = newnode;
        head->prev = newnode;
    }
}
void insertPosition(char song[], int pos)
{
    struct node *newnode = malloc(sizeof(struct node));

    if(newnode == NULL || pos < 1)
        return;

    strcpy(newnode->song, song);

    if(pos == 1)
    {
        free(newnode);
        insertBeginning(song);
        return;
    }

    if(head == NULL)
    {
        free(newnode);
        printf("Invalid position\n");
        return;
    }

    struct node *temp = head;

    for(int i = 1; i < pos-1 && temp->next != head; i++)
    {
        temp = temp->next;
    }

    if(pos > 1 && temp->next == head && pos > 2)
    {
        if(temp == head->prev && pos != 2)
        {
            free(newnode);
            printf("Invalid position\n");
            return;
        }
    }

    newnode->next = temp->next;
    newnode->prev = temp;

    temp->next->prev = newnode;
    temp->next = newnode;
}
void deleteBeginning()
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;

    if(head->next == head)
    {
        head = NULL;
        current = NULL;
    }
    else
    {
        struct node *last = head->prev;

        head = head->next;
        head->prev = last;
        last->next = head;

        if(current == temp)
            current = head;
    }
    temp->next = temp;
    temp->prev = temp;

    if(deletedHead == NULL)
    {
        deletedHead = temp;
    }
    else
    {
        struct node *last = deletedHead->prev;

        temp->next = deletedHead;
        temp->prev = last;

        last->next = temp;
        deletedHead->prev = temp;
    }

    printf("Song deleted\n");
}
void deleteEnd()
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head->prev;

    if(head->next == head)
    {
        head = NULL;
        current = NULL;
    }
    else
    {
        temp->prev->next = head;
        head->prev = temp->prev;

        if(current == temp)
            current = head;
    }

    temp->next = temp;
    temp->prev = temp;

    if(deletedHead == NULL)
    {
        deletedHead = temp;
    }
    else
    {
        struct node *last = deletedHead->prev;

        temp->next = deletedHead;
        temp->prev = last;

        last->next = temp;
        deletedHead->prev = temp;
    }

    printf("Song deleted\n");
}
void deletePosition(int pos)
{
    if(head == NULL || pos < 1)
    {
        printf("Invalid position\n");
        return;
    }

    if(pos == 1)
    {
        deleteBeginning();
        return;
    }

    struct node *temp = head;

    for(int i = 1; i < pos && temp->next != head; i++)
    {
        temp = temp->next;
    }

    if(temp == head || pos < 2)
    {
        printf("Invalid position\n");
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    if(current == temp)
        current = temp->next;

    temp->next = temp;
    temp->prev = temp;

    if(deletedHead == NULL)
    {
        deletedHead = temp;
    }
    else
    {
        struct node *last = deletedHead->prev;

        temp->next = deletedHead;
        temp->prev = last;

        last->next = temp;
        deletedHead->prev = temp;
    }

    printf("Song deleted\n");
}
void search(char song[])
{
    if(head == NULL)
    {
        printf("Playlist is empty\n");
        return;
    }

    struct node *temp = head;
    int pos = 1;

    do
    {
        if(strcmp(temp->song, song) == 0)
        {
            printf("Song found at position %d\n", pos);
            return;
        }

        temp = temp->next;
        pos++;

    }while(temp != head);

    printf("Song not found\n");
}

// Display Playlist
void display()
{
    if(head == NULL)
    {
        printf("Playlist is empty\n");
        return;
    }

    struct node *temp = head;

    printf("\nSpotify Playlist:\n");

    do
    {
        printf("%s\n", temp->song);
        temp = temp->next;

    }while(temp != head);
}
void nextSong()
{
    if(head == NULL)
    {
        printf("Playlist is empty\n");
        return;
    }

    if(current == NULL)
        current = head;
    else
        current = current->next;

    printf("Now Playing: %s\n", current->song);
}
void previousSong()
{
    if(head == NULL)
    {
        printf("Playlist is empty\n");
        return;
    }

    if(current == NULL)
        current = head;
    else
        current = current->prev;

    printf("Now Playing: %s\n", current->song);
}
void restoreSong()
{
    if(deletedHead == NULL)
    {
        printf("No deleted songs available!\n");
        return;
    }

    struct node *temp = deletedHead;

    if(deletedHead->next == deletedHead)
    {
        deletedHead = NULL;
    }
    else
    {
        deletedHead = deletedHead->next;
        deletedHead->prev = temp->prev;
        temp->prev->next = deletedHead;
    }

    if(head == NULL)
    {
        head = temp;
        temp->next = head;
        temp->prev = head;
        current = head;
    }
    else
    {
        struct node *last = head->prev;

        temp->next = head;
        temp->prev = last;

        last->next = temp;
        head->prev = temp;
    }
    printf("%s restored successfully!\n", temp->song);
}
int main()
{
    int choice, pos;
    char song[50];
    do
    {
        printf("\nSPOTIFY MENU\n");
        printf("1. Insert Beginning\n");
        printf("2. Insert End\n");
        printf("3. Insert Position\n");
        printf("4. Delete Beginning\n");
        printf("5. Delete End\n");
        printf("6. Delete Position\n");
        printf("7. Search Song\n");
        printf("8. Display Playlist\n");
        printf("9. Next Song\n");
        printf("10. Previous Song\n");
        printf("11. Restore Deleted Song\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter song name: ");
                scanf(" %49[^\n]", song);
                insertBeginning(song);
                break;
            case 2:
                printf("Enter song name: ");
                scanf(" %49[^\n]", song);
                insertEnd(song);
                break;
            case 3:
                printf("Enter song name: ");
                scanf(" %49[^\n]", song);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertPosition(song, pos);
                break;
            case 4:
                deleteBeginning();
                break;
            case 5:
                deleteEnd();
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deletePosition(pos);
                break;
            case 7:
                printf("Enter song name: ");
                scanf(" %49[^\n]", song);
                search(song);
                break;
            case 8:
                display();
                break;
            case 9:
                nextSong();
                break;
            case 10:
                previousSong();
                break;
            case 11:
                restoreSong();
                break;
            case 12:
                printf("Exiting Spotify...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    }while(choice != 12);
    return 0;
}
