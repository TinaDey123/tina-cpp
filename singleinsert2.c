#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    
};
struct node *head=NULL;
void insertatany(int data, int pos) {
    if(pos < 1) {
        printf("Invalid position\n");
        return;
    }
    
    struct node *newnode = malloc(sizeof(struct node));
    if(newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data = data;
    if(pos == 1) {
        newnode->next = head;
        head = newnode;
        return;
    }
    
    struct node *current = head;
    for(int i = 1; i < pos - 1 && current != NULL; i++) {
        current = current->next;
    }
    if(current == NULL) {
        printf("Invalid position\n");
        free(newnode);
        return;
    }
    
    newnode->next = current->next;
    current->next = newnode;
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
    insertatany(25,2);
    
    return 0;
}
