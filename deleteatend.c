#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head=NULL;

void deleteatend()
{
    if(head==NULL)
    {
        printf("not found ");
    }
    if(head->next==NULL)
    {
        free(head);
            head=NULL;
        return;
    }
    struct node*temp=head;
    while (temp->next->next!=NULL)
        {
            temp=temp->next;
        }
    free(temp->next);
    temp->next=NULL;
        
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
    deleteatend();
    display ();
    return 0;
}
