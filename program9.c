#include<stdio.h>
int delete(int a[],int n,int pos)
{
    for(int i=pos;i<n-1;i++)
    {
        a[i]=a[i+1];
    }
    n--;
    return n;
}

int main()
{
    int a[6]={10,20,30,40,50};
    int n=5;
    int pos=2;
    delete(a,n,pos);
   printf("after deletion:");
    for(int i=0;i<n;i++)
    {
        printf("%d",a[i]);
    } 
return 0;
}