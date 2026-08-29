#include<stdio.h>
int binary_search(int arr[],int x,int high,int low)
{
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(x==arr[mid])
        {
            return mid;
        }
        if(x>arr[mid])
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return -1;
}
int main()
{
    int array[6]={10,20,30,40,50};
int n=sizeof(array)/sizeof(array[0]);
int x=30;
int result=binary_search(array,x,n-1,0);
if(result==-1)
{
    printf("Element not found");
}
else{
printf("Element found at index %d",result);
}
return 0;
}