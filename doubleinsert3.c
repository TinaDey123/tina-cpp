#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *pvr;
    struct node *next;
};
struct node *head=NULL;
void insertatend(int data)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    if (head == NULL)
    {
        newnode->pvr = NULL;
      head = newnode; 
      return;
    }
     struct node *current=head;
    while(current->next!=NULL)
        {
            current=current->next;
        }
    current->next=newnode;
    newnode->pvr = current;
}
void display()
{
struct node *current = head;

while (current != NULL)
{
    printf("%d <-> ", current->data);
    current = current->next;
}

printf("NULL\n");

}
int main() {
struct node *first=malloc(sizeof(struct node));
    struct node *second=malloc(sizeof(struct node ));
    struct node *third=malloc(sizeof(struct node));
    first->data = 10;
    first->pvr = NULL;
    first->next = second; 
    second->data = 20;
    second->pvr = first; 
    second->next = third;
    third->data = 30; 
    third->pvr = second; 
    third->next = NULL;
    head=first;
    insertatend(40);
    display();
    return 0;
}
