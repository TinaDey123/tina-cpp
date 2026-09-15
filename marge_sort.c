#include<stdio.h>
void marge(int arr[],int p,int q,int r)
{
    int  n1=q-p+1;
    int n2=r-q;
    int l[n1],m[n2];
    for(int i=0;i<n1;i++)
    {
        l[i]=arr[p+i];
    }
    for(int j=0;j<n2;j++)
    {
        m[j]=arr[q+1+j];
        int i,j,k;
        i=0,j=0,k=p;
        while(i<n1&&j<n2)
        {
            if(l[i]<=m[j])
            {
           arr[k]=l[i];
           i++;
        }
         else
         {
            arr[k]=m[j];
            j++;
         }
         k++;
        }
            while(i<n1)
            {
                arr[k]=l[i];
                i++;
                k++;
            }
            while(j<n2)
            {
                arr[k]=l[j];
                j++;
                k++;
            }
        }
    }
    void marge_sort(int arr[],int l,int r)
    {
        if(l<r)
        {
            int m=l+(r-l)/2;
            marge_sort(arr,l,m);
            marge_sort(arr,m+1,r);
            marge(arr,l,m,r);
        }
    }
    int main()
    {
        int data[]={10,4,5,2,8};
        int size=sizeof(data)/sizeof(data[0]);
        marge_sort(data,0,size-1);
        for(int i=0;i<size;i++)
        {
            printf("%d ",data[i]);
        }
        return 0;
    }
