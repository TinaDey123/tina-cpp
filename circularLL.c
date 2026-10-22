#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertatend(int data)
{
    struct node *newnode = malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    newnode->data = data;

    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
        return;
    }

    struct node *current = head;

    while (current->next != head)
    {
        current = current->next;
    }

    current->next = newnode;
    newnode->next = head;
}

void display()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node *current = head;

    do
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    while (current != head);

    printf("(back to head)\n");
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
    third->next = first;

    head = first;

    insertatend(40);

    display();

    return 0;
}

