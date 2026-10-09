#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertatbeggining(int data)
{
    struct node *newnode = malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed");
        return;
    }

    newnode->data = data;
    newnode->next = head;
    head = newnode;
}

int main()
{
    struct node *first = malloc(sizeof(struct node));
    struct node *second = malloc(sizeof(struct node));
    struct node *third = malloc(sizeof(struct node));

    if (first == NULL || second == NULL || third == NULL)
    {
        printf("Memory allocation failed");
        return 1;
    }

    first->data = 10;
    second->data = 20;
    third->data = 30;

    first->next = second;
    second->next = third;
    third->next = NULL;

    head = first;

    insertatbeggining(40);

    struct node *temp = head;

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL");

    return 0;
}

