#include<stdio.h>
void insertion_sort(int arr[],int size)
{
    for(int step=1;step<size;step++)
    {
      int key=arr[step];
      int j=step-1;
      while(j>=0&&key<arr[j])
      {
        arr[j+1]=arr[j];
        --j;
      }
      arr[j+1]=key;
    }
}
int main()
{
    int data[]={10,4,9,5,11};
    int size=sizeof(data)/sizeof(data[0]);
    insertion_sort(data,size);
    printf("sorted array:");
    for(int i=0;i<size;i++)
    {
        printf("%d ",data[i]);
    }
    return 0;
}