#include<stdio.h>
#define max 5

int queue[max];
int front = -1;
int rear = -1;

void enqueue()
{
    int item;

    if(rear == max - 1)
    {
        printf("Queue Overflow\n");
        return;
    }

    printf("Enter an element:");
    scanf("%d", &item);

    if(front == -1)
    {
        front = 0;
    }

    rear = rear + 1;
    queue[rear] = item;

    printf("%d inserted into the queue\n", item);
}

void dequeue()
{
    if(front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        return;
    }

    printf("%d deleted from the queue\n", queue[front]);

    front = front + 1;

    if(front > rear)
    {
        front = -1;
        rear = -1;
    }
}

int main()
{
    int n, i;

    printf("How many elements do you want to insert? ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        enqueue();
    }

    printf("\nHow many elements do you want to delete? ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        dequeue();
    }

    return 0;
}
