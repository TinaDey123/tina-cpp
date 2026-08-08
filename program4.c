#include<stdio.h>
int fact(int n)
{
    if(n==0||n==1)
    {
        return 1;
    }
    else
    {
        return n*fact(n-1);
    }
}
int main()
{
    int a=5;
    printf("%d!=%d",a,fact(a));
return 0;

}