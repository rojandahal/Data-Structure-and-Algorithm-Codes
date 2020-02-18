#include <stdio.h>
#include<conio.h>
int Searching (int *k,int N,int x)
{
    int Low=1;
    int mid,High=N;
    while(Low<=High)
    {
        mid=(Low+High)/2;
        if(x<k[mid])
        {
            High= mid-1;
        }
        else if(x>k[mid])
        {
            Low=mid+1;
        }else{
            printf("\nSuccessfully searched.");
            return mid;
        }
    }
    printf("\nUnsuccessful search");
    return -1;
}

int main ()
{
    int *k;
    int N,i,res,x,NUM=1;
    char test='Y';
    printf("\nEnter the number of elements: ");
    scanf("%d",&N);
    k=(int *)malloc(sizeof(int)*N);
    printf("\nEnter the values of the numbers:\n");
    for (i=0;i<N;i++)
    {
        scanf("%d",&k[i]);
    }
    while(NUM==1)
    {
        printf("\nEnter the value to search :");
        scanf("%d",&x);
        res = Searching(k,N,x);
        if(res==-1)
        {
            printf("\nThe value was not found.");
        }else
            printf("\nThe %d value is present in %d position.",k[res],res);
        printf("\nExit? Press 1 to continue\n");
        scanf("%d",&NUM);
    }
    getch();


}
