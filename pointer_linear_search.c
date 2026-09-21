#include<stdio.h>
int linear_search(int arr[],int size,int key)
{
 for(int i=0;i<size;i++)
  {
     if(*(arr+i)==key)
      {
         return i;
       }
    }
     return -1;
}

int main()
{ 
 int arr[5]={10,20,30,40,50};
 int key=30;
 int i;
 int size=sizeof(arr)/sizeof(arr[0]);
 int result=linear_search(arr,size,key);
  if(result!=1)
  {
  printf("element found at %d",result);
  }
  else
  {
   printf("element not found");
  }
 return 0;
}
