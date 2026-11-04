#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void search(int key)
{
    int pos = 1;
    struct node *current = head;

    while(current != NULL)
    {
        if(current->data == key)
        {
            printf("Found at position %d", pos);
            return;
        }

        current = current->next;
        pos++;
    }

    printf("Not found");
}

int main()
{
    struct node *first = malloc(sizeof(struct node));
    struct node *second = malloc(sizeof(struct node));
    struct node *third = malloc(sizeof(struct node));

    first->data = 10;
    second->data = 20;
    third->data = 30;

    first->next = second;
    second->next = third;
    third->next = NULL;

    head = first;

    search(20);

    free(first);
    free(second);
    free(third);

    return 0;
}
