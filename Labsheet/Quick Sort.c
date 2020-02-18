#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<stdlib.h>

void quick_sort(int *K,int LB,int UB)
{
    int i,j,Key;
    bool flag = true;
    if(LB<UB){
            i=LB;
            j=UB+1;
            Key=K[LB];
            while(flag)
            {
                i=i+1;
                while(K[i]<Key){
                    i=i+1;
                    j=j-1;
                    while(K[j]>Key){
                        j=j-1;
                        if(i<j){
                            K[i]=K[j];
                        }else{
                            flag=false;
                        }
                    }
                    K[LB]=K[j];
                }
            }

            quick_sort(K,LB,j-1);
            quick_sort(K,j+1,UB);
        }
    }

int main ()
{
    int *K,N,i;
    printf("\nEnter the value of number of terms: ");
    scanf("%d",&N);
    K=(int *)malloc(N*sizeof(int));
    printf("\nEnter your values \n ");
    for(i=0;i<N;i++)
    {
        scanf("%d",&K[i]);

    }
    quick_sort(K,1,N);
    getch();


}
