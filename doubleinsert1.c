#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *pvr;
    struct node *next;
};
struct node *head=NULL;
void insertatbeg(int data)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=data;
    newnode->pvr=NULL;
    newnode->next=head;
    head=newnode;
    if(head!=NULL)
    {
        head->pvr=newnode;
        
    }
    head=newnode;
}
void display()
{
    struct node *current =head;
    while(current!=NULL)
        {
            printf("%d ->",current->data);
            current=current->next;
        }
    printf("NULL\n");
}
int main() {
struct node *first=malloc(sizeof(struct node));
    struct node *second=malloc(sizeof(struct node));
     struct node *third=malloc(sizeof(struct node));
    first->data=10;
    second->data=20;
    third->data=30;
    first->next=second;
    second->next=third;
    third->next=NULL;
    head=first;
    insertatbeg(5);
    display();
    
    return 0;
}
