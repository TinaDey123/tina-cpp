#include<stdio.h>
int selection_sort(int arr[],int size)
{
for(int step=0;step<size-1;step++)
{
   int  min_idx=step;
    for(int i=step+1;i<size;i++)
    {
        if(arr[i]<arr[min_idx])
        {
      min_idx=i;
     
         }
    }
int temp=arr[min_idx];
arr[min_idx]=arr[step];
arr[step]=temp;
for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}
}
int main()
{
int data[]={10,4,9,5,11};
    int size=sizeof(data)/sizeof(data[0]);
    selection_sort(data,size);
    printf("sorted array:");
    for(int i=0;i<size;i++)
    {
        printf("%d ",data[i]);
    }
    return 0;
}