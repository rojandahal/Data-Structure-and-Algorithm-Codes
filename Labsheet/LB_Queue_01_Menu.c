#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 10
struct lqueue
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

void enqueue(struct lqueue *que)
{
    int data;
    if(que->rear==max){
        printf("\nQueue is full.");
        return;
    }
    printf("\nEnter the value to enqueue: ");
    scanf("%d",&que->item[que->rear]);
    printf("\n%d Enqueued\n",que->item[que->rear]);
    que->rear++;
}

void dequeue(struct lqueue *que)
{
    int i;
    if(que->rear==que->front){
        printf("\nQueue is empty.");
        return;
    }
    printf("\n%d dequeued\n",que->item[que->front]);
    for(i=0;i<que->rear-1;i++){
        que->item[i]=que->item[i+1];
    }
    que->rear--;
}

void display(struct lqueue *que)
{
    int i;
    if(que->front==que->rear){
        printf("\nQueue is empty.");
        return;
    }
    for (i=que->front;i<que->rear;i++){
        printf("\n%d",que->item[i]);
    }
}

int main()
{
    struct lqueue *que;
    que=(struct lqueue*)malloc(sizeof(struct lqueue));
    que->front=0;
    que->rear=0;
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
