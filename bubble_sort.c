#include<stdio.h>
int bubble_sort(int arr[],int size)
{
    for( int step=0;step<size-1;step++)
    {
        for( int i=0;i<size-1-step;i++)
        {
            if(arr[i]>arr[i+1])
            {
                int temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
    }
    return -1;
}
int main()
{
    int data[]={10,4,9,5,11};
    int size=sizeof(data)/sizeof(data[0]);
    bubble_sort(data,size);
    printf("sorted array:");
    for(int i=0;i<size;i++)
    {
        printf("%d ",data[i]);
    }
    return 0;
}