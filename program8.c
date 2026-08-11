#include<stdio.h>
int insert(int a[],int n,int pos,int element)
{
    for(int i=n;i>pos;i--)
    {
       a[i]=a[i-1];

    }
    a[pos]=element;
    n++;
}
int main()
{

    int a[6]={10,20,40,50};
    int pos=2;
    int n=4;
    int element=30;
    insert(a,n,pos,element);
    printf("after insertion:");
    for(int i=0;i<=n;i++)
    {
        printf("%d",a[i]);
    }
    return 0;
}
