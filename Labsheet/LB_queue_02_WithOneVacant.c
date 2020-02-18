#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 10

struct cqueue
{
    int item[max];
    int front;
    int rear;
};

void menu()
{
    printf("\n0.Display Menu");
    printf("\n1.Enqueue data");
    printf("\n2.Dequeue data");
    printf("\n3.Display all data");
    printf("\n4.Exit");
}

void enqueue(struct cqueue *que)
{
    int data;
    if(que->front==((que->rear)+1)%10)
    {
        printf("\nThe queue is full.");
        return;
    }
    printf("\nEnter the data to enqueue: ");
    scanf("%d",&data);
    que->rear=(que->rear+1)%10;
    que->item[que->rear]=data;
}

void dequeue(struct cqueue *que)
{
    if (que->rear==que->front)
    {
        printf("\nThe queue is empty");
        return;
    }
    que->front=(que->front+1)%10;
    printf("\nDequeued item is: %d",que->item[que->front]);
}

void display(struct cqueue *que)
{
    int i;
    if(que->rear==que->front)
    {
        printf("\nQueue is empty.");
        return;
    }
    if(que->rear>que->front){
    for(i=que->front+1;i<=que->rear;i++)
    {
            printf("\t%d",que->item[i]);
            return;
    }}
    if(que->rear<que->front){
        for (i=que->front+1;i<max-1;i++){
            printf("\t%d",que->item[i]);
        }
        for(i=0;i<que->rear;i++){
            printf("\t%d",que->item[i]);
        }
    }
}
int main()
{
    struct cqueue *que;
    que=(struct cqueue*)malloc(sizeof(struct cqueue));
    que->front=max-1;
    que->rear=max-1;
    int ch;
    menu();
    while(1)
    {
        printf("\n\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0:
                menu();
                break;
            case 1:
                enqueue(que);
                break;
            case 2:
                dequeue(que);
                break;
            case 3:
                display(que);
                break;
            case 4:
                exit(1);
            default:
                printf("\nInvalid choice");
        }
    }

    getch();

}
