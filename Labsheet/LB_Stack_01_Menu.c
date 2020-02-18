#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Vstack
{
    int num[10];
    int tos;
};

void push(struct Vstack *vst)
{
    int data;
    if(vst->tos==9){
        printf("\nStack overflow.");
        return;
    }
    printf("\nEnter a data to push in stack: ");
    scanf("%d",&data);
    vst->tos=vst->tos+1;
    vst->num[vst->tos]=data;
    printf("\n%d pushed to stack.",data);
}

void pop(struct Vstack *vst)
{
    int data;
    if(vst->tos==-1){
        printf("\nStack underflow.");
        return;
    }
    data=vst->num[vst->tos];
    vst->tos=vst->tos-1;
    printf("\n%d popped from stack.",data);
}

void display(struct Vstack *vst)
{
    int i;
    if(vst->tos==-1){
        printf("\nStack Empty");
        return;
    }
    for(i=0;i<=vst->tos;i++){
        printf("\n%d",vst->num[i]);
    }
}

int main()
{
    int ch;
    struct Vstack *vst;
    vst=(struct Vstack *)malloc(sizeof(struct Vstack));
    vst->tos=-1;
    while(1){
        printf("\n\n1.Push to Stack.");
        printf("\n2.Pop from stack.");
        printf("\n3.Top of stack.");
        printf("\n4.Display all.");
        printf("\n5.Exit");
        printf("\nEnter your choice: \n");
        scanf("%d",&ch);
        switch(ch){
        case 1:
            push(vst);
            break;
        case 2:
            pop(vst);
            break;
        case 3:
            printf("\nTop of stack is: %d",vst->tos);
            break;
        case 4:
            display(vst);
            break;
        case 5:
            exit(1);
        default:
            printf("\nInvalid Choice");
            break;
        }
    }
    getch();
}
