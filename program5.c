#include<stdio.h>
#include<string.h>
int main()
{
    char data_structure[20];
    printf("enter data structure");
    scanf("%s",&data_structure);
    if(strcmp(data_structure,"Array")==0)
    {
        printf("type:linear ds");
    }
    else if(strcmp(data_structure,"LL")==0)
        {
        printf("type:linear ds");
    }
    else if(strcmp(data_structure,"tree")==0)
    {
        printf("type:non-linear ds");
    }
    else if(strcmp(data_structure,"graph")==0)
    {
        printf("type:non-linear ds");
    }
    else
    {
        printf("invalid data structure");
    }
return 0;
}