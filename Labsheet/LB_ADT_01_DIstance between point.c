#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct point
{
    int pnt[2];
    int cnt;
};

void set_Point(struct point *p,int i)
{
    int data;
    printf("\nEnter %d the point.",i+1);
    scanf("%d",&data);
    p->pnt[i]=data;
}

void distance(struct point *p)
{
    int i = p->pnt[0];
    int j = p->pnt[1];
    for (i;i<j;i++)
    {
        p->cnt++;
    }
}

void display(struct point *p)
{
    printf("\nThe distance between %d and %d = %d",p->pnt[0],p->pnt[1],p->cnt);
}

int main()
{
    struct point *p;
    p=(struct point *)malloc(sizeof(struct point));
    p->cnt=0;
    int pnt;
    set_Point(p,0);
    set_Point(p,1);
    distance(p);
    display(p);
    getch();
}
