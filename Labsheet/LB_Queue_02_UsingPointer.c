#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define max 10

struct cqueue
{
    int item[max];
    int front;
    int rear;
    int count;
};

void menu()
{
    printf("\n0.Display Menu");
    printf("\n1.Enqueue data");
    printf("\n2.Dequeue data");
    printf("\n3.Display all data");
    printf("\n4.Counter variable");
    printf("\n5.Exit");
}

void enqueue(struct cqueue *que)
{
    int data;
    if(que->count==max-1)
    {
        printf("\nThe queue is full.");
        return;
    }
    printf("\nEnter the data to enqueue: ");
    scanf("%d",&data);
    que->rear=(que->rear+1)%10;
    que->item[que->rear]=data;
    que->count++;
}

void dequeue(struct cqueue *que)
{
    if (que->count==0)
    {
        printf("\nThe queue is empty");
        return;
    }
    printf("\nDequeued item is: %d",que->item[que->front]);
    que->front=(que->front+1)%10;
    que->count--;
}

void display(struct cqueue *que)
{
    int i;
    if(que->count==0)
    {
        printf("\nQueue is empty.");
        return;
    }
    for(i=0;i<que->count;i++)
    {
            printf("\t%d",que->item[(que->front)+i]);
    }
}
int main()
{
    struct cqueue *que;
    que=(struct cqueue*)malloc(sizeof(struct cqueue));
    que->count=0;
    que->front=0;
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
                printf("\nNo of item: %d",que->count);
                break;
            case 5:
                exit(1);
            default:
                printf("\nInvalid choice");
        }
    }

    getch();

}
