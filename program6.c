#include<stdio.h>
int main()
{
    int a[5]={10,23,45,56,89 };
    int b[2][3]={{2,3,4},{4,7,8}};
    int i,j;
    printf("1-D array:");
    for(i=0;i<5;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n 2-D array:");
    for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d  ",b[i][j]);
        }
        printf("\n");
    }
return 0;
}
