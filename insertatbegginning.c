#include <stdio.h>
#include <stdlib.h>

struct Node
{
int data;
struct Node *next;
};

struct Node *head = NULL;

void insertatbeginning(int data);
void display();

int main()
{
struct Node *first = malloc(sizeof(struct Node));
struct Node *second = malloc(sizeof(struct Node));
struct Node *third = malloc(sizeof(struct Node));
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

insertatbeginning(5);
display();

return 0;


}

void insertatbeginning(int data)
{
struct Node *newnode = malloc(sizeof(struct Node));


if (newnode == NULL)
{
    printf("Memory allocation failed\n");
    return;
}

newnode->data = data;
newnode->next = head;
head = newnode;

}

void display()
{
struct Node *temp = head;
while (temp != NULL)
{
    printf("%d -> ", temp->data);
    temp = temp->next;
}

printf("NULL\n");


}

