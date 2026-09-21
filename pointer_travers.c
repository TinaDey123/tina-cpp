#include<stdio.h>
int main()
{
int n;
printf("enter a number");
scanf("%d",&n);
int arr[5]={1,5,6,3,9};
printf("travers in array:");
for(int i=0;i<n;i++)
{
printf("%d",*(arr+i));
}
return 0;
}
