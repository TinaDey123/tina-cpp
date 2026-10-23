
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void create()
{
    struct Node *first, *second, *third;

    first = malloc(sizeof(struct Node));
    second = malloc(sizeof(struct Node));
    third = malloc(sizeof(struct Node));

    first->data = 10;
    first->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = first;

    head = first;
}
void deletebeginning()
{
    struct Node *temp, *last;

    temp = head;
    last = head;

    while(last->next != head)
        last = last->next;

    head = head->next;
    last->next = head;

    free(temp);
}


void traversal()
{
    struct Node *temp = head;

    if(temp != NULL)
    {
        do
        {
            printf("%d ->", temp->data);
            temp = temp->next;
        }
        while(temp != head);
    }
}
int main()
{
    create();
       deletebeginning();
    traversal();

    return 0;
}
