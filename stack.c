#include<stdio.h>
#define max 5
int stack[max];
int top=-1;
int isfull()
{
    return top==max-1;
}
int isempty()
{
    return top==-1;
}
void push(int value)
{
    if(isfull())
    {
        printf("stack overflow");
    }
    else
    {
        top++;
        stack[top]=value;
    }
}
int pop()
{
    if(isempty())
    {
        printf("no element to pop");
        return -1;
    }
    else
    {
        int popped_value=stack[top];
        top--;
        return popped_value;
    }
}
int peek()
{
    if(isempty())
    {
        printf("stack is empty");
        return -1;
    }
    else
    {
        return stack[top];
    }
}
void display()
{
    int i;
    if(isempty())
    {
        printf("stack is empty");
        return;
    }
    printf("stack elements\n");
    for(i=top;i>=0;i--)
    {
        printf("%d\n",stack[i]);
    }

}
int main()
{
    pop();
    push(10);
    push(20);
    push(30);
    display();
    printf("popped=%d\n",pop());
    printf("top element=%d\n",peek());
    return 0;
}
