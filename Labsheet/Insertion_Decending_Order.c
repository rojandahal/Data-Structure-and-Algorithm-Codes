#include <stdio.h>
#include<conio.h>
#include<limits.h>

int main()
{
    int i,k[10],temp,ptr;
    k[0]=INT_MIN;
     printf("\nEnter the elements:\n");
    for(i=1;i<10;i++){
        scanf("%d",&k[i]);
    }

    for(i=2;i<10;i++)
    {
        temp=k[i];
        ptr=i-1;
        while(temp>k[ptr])
        {
            k[ptr+1]=k[ptr];
            ptr=ptr-1;
        }
        k[ptr+1]=temp;
    }
    printf("\nThe sorted numbers is: \n");
     for(i=1;i<10;i++){
        printf("\t%d",k[i]);
    }
    getch();

}
