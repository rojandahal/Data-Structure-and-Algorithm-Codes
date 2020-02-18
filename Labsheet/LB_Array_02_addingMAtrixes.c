#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int i,j,k;

void askValue(int **a,int r, int c)
{
    printf("Enter the values for matrix:\n ");
    for (i=0;i<r;i++){
        for (j=0;j<c;j++){
            scanf("%d",&a[i][j]);
        }
    }

}
void printMatrix(int **x,int r,int c){
    printf("The matrix is:\n");
    for (i=0;i<r;i++){
        for (j=0;j<c;j++){
            printf("\t%d",x[i][j]);
        }
        printf("\n");
    }

}

int main ()
{
    int **a,**b,**c,**d,r1,c1,r2,c2;
    printf ("Enter the value of row and column for first matrix:\n");
    scanf("%d%d",&r1,&c1);
    printf("Enter the value of row and column for second matrix:\n");
    scanf("%d%d",&r2,&c2);

    printf("\nFor first matrix:\n");
    a = (int **)malloc (r1*sizeof(int*));
    for (i=0;i<r1;i++){
        a[i]=(int *)malloc(c1*sizeof(int));
    }

    askValue(a,r1,c1);



    printf("\nFor second matrix:\n");
    b = (int **)malloc (r2*sizeof(int*));
    for (i=0;i<r2;i++){
        b[i]=(int *)malloc(c2*sizeof(int));
    }

    askValue(b,r2,c2);



    printMatrix(a,r1,c1);
    printMatrix(b,r2,c2);

    c=(int**)malloc(r1*sizeof(int*));
    for (i=0;i<r1;i++)
    {
        c[i]=(int* )malloc(c2*sizeof(int));
    }

    d=(int**)malloc(c2*sizeof(int*));
    for (i=0;i<c2;i++)
    {
        d[i]=(int* )malloc(r1*sizeof(int));
    }

    if (r1==r2 && c1==c2){
    for (i=0;i<r1;i++){
        for (j=0;j<c2;j++){
            c[i][j]=0;
            c[i][j]+=a[i][j]+b[i][j];
        }
    }

    for (i=0;i<c1;i++){
        for (j=0;j<r1;j++){
            d[i][j]=c[j][i];
        }
    }
    printf("The product of matrix is:\n");
    printMatrix(c,r1,c2);

    printf("\nThe transpose of the matrix is: \n");
    printMatrix(d,c2,r1);
    }else
    {
        printf("Invalid addition.");
    }
    getch();

}

