#include<stdio.h>
int linear_search(int arr[],int n,int element)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==element)
        {
            return n;
        }
    }
    return -1;
}
int main()
{
    int arr[6]={10,20,30,40,50};
    int n=5;
    int i;
    int element=20;
    n=linear_search(arr,n,element);
    if(n==-1)
    {
        printf("element not found");
        }
        else
        {
            printf("element found at index %d",n);
        }
        return 0;

}
