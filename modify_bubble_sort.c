#include<stdio.h>
void bubble_sort(int arr[],int size)
{
  for(int step=0;step<size-1;step++)
   {
       int swap=0;
        for(int i=0;i<size-step-1;i++)
          {
              if(arr[i]>arr[i+1])
                  {
                      int temp=arr[i];
                        arr[i]=arr[i+1];
                         arr[i+1]=temp;
                        swap++;
                       }
                    }
                       if(swap==0)
                       { 
                          break;
                         }
                         for(int i=0;i<size;i++)
                          {
                              printf("%d",arr[i]);
                            }
                             printf("\n");
              }
}
  int main()
{
   int data[]={1,6,3,9,2};
   int size=sizeof(data)/sizeof(data[0]);
    bubble_sort(data,size);
     printf("sorted array");
     for(int i=0;i<size;i++)
         {
            printf("%d",data[i]);
          }
     return 0;
}
          
