#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
    int i,*k,n,x,test=1,count;
    printf("\nEnter the number of elements.");
    scanf("%d",&n);
    k=(int *)malloc(sizeof(int)*n);
    printf("\nEnter the values of the array:\n");
    for (i=0;i<n;i++)
    {
        scanf("%d",&k[i]);
    }
    while(test==1)
    {
        count=0;
         printf("\nEnter the value to search: ");
        scanf("%d",&x);
        for(i=0;i<n;i++)
        {
            if(k[i]==x)
            {
                printf("\nData found at %d in position %d",k[i],i);
                ++count;
                break;
            }
        }
        if(count==0)
        {
            printf("\nSearch Unsuccessful");
        }
        printf("\nExit? Press 1 to continue.\n");
        scanf("%d",&test);
    }
}
