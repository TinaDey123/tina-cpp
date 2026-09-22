#include<stdio.h>
int selection_sort(int arr[],int size)
{
for(int step=0;step<size-1;step++)
{
   int  min_idx=step;
    int max_idx=step
    for(int i=step;i<size-step;i++)
    {
        if(arr[i]<arr[min_idx])
        {
          min_idx=i;
          if(arr[i]>arr[max_idx])
          {
           max_idx=i;
         }
       }
if(max_idx==step)
 {
    max_idx=min_idx;
  }
 int temp=arr[max_idx];
arr[max_idx]=arr[size-1-step];
arr[size-1-step]=temp;
for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
     printf("\n");
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
