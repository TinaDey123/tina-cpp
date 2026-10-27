#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head=NULL;
void deleteatany(int pos)
{
   struct node *newnode=malloc (sizeof(struct node));
    if(pos<1||head==NULL)
    {
        printf("not found");
        return;
    }
    if(newnode==NULL)
    {
        printf ("memory is null");
        return;
    }
    if(pos==1)
    {
        newnode->next = head;
          head = newnode;
           return; 
        }
    struct node *current=head;
    for(int i=1;i<pos-1&&  current!=NULL;i++)
        {
            current=current ->next;
        }
    if(current==NULL||current->next==NULL)
    {
        printf ("invalid");
        free(newnode);
        return;
    }
    
    struct  node *temp=current->next;
    current ->next=temp->next;
    free(temp);
}
void display()
{
    struct node *current = head;

    while(current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf(" NULL\n");
}
int main() {
struct node *first=malloc (sizeof(struct node ));
    struct node *second=malloc(sizeof (struct node));
    struct node *third=malloc (sizeof(struct node));
    first->data=10;
        second ->data=20;
    third ->data=30;
    first->prev=NULL;
    second ->prev=first;
    third->prev=second;
    first->next=second;
    second->next=third;
    third->next=NULL;
    head=first;
    deleteatany(2);
    display ();
    return 0;
}
