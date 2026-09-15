#include<stdio.h>
void flag(int *X, int *Y);
void quick_sort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void flag(int*X,int *Y)
{
    int temp=*X;
    *X=*Y;
    *Y=temp;
}
void bubble_sort(int arr[],int size)
{
   for(int step=0;step<size-1;step++)
  {
      for(int i=0;i<size-step-1;i++)
       {
           int flag=0;
           if(arr[i]>arr[i+1])
           {
            int temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
               flag=1;
            }
            if(flag==1)
           {
              quick_sort(arr,0,size-1);
           }
        }
    }
}
void quick_sort(int arr[],int low,int high)
{
    if(low<high)
    {
        int pi=partition(arr,low,high);
        quick_sort(arr,low,pi-1);
        quick_sort(arr,pi+1,high);
    }
}
int partition(int arr[],int low,int high)
{
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<high;j++)
    {
       if(arr[j]<=pivot)
      {
          i++;
          int temp=arr[i];
          arr[i]=arr[j];
          arr[j]=temp;
      }
    }
    int temp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;
    return i+1;
}
int main()
{
    int data[]={1,6,3, 9,4,6};
    int size=sizeof(data)/sizeof(data[0]);
    bubble_sort(data,size);
    printf("sorted array:");
    for(int i=0;i<size;i++)
    {
        printf("%d",data[i]);
    }
   return 0;
}