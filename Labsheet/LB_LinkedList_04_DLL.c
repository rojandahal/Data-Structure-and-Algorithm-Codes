#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *prev, *next;
};
struct node *start=NULL,*last=NULL;

void menu()
{
    printf("\n0.Print Menu");
    printf("\n1.Insert at beginning");
    printf("\n2.Insert at last");
    printf("\n3.Delete at beginning");
    printf("\n4.Delete at last");
    printf("\n5.Display all nodes");
    printf("\n6.Exit");
}
void insert_beg()
{
    struct node *nnode,*temp;
    int item;
    nnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data to insert: ");
    scanf("%d",&item);
    nnode->info=item;
    if(start==NULL)
    {
        nnode->prev=NULL;
        nnode->next=NULL;
        last=nnode;
        start=nnode;
        return;
    }
    nnode->prev=NULL;
    nnode->next=start;
    start->prev=nnode;
    start=nnode;
}

void insert_atLast()
{
    struct node *nnode,*temp;
    int item;
    nnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data to insert: ");
    scanf("%d",&item);
    nnode->info=item;
    if(last==NULL)
    {
        nnode->prev=NULL;
        nnode->next=NULL;
        start=nnode;
        last=nnode;
        return;
    }
    nnode->next=NULL;
    nnode->prev=last;
    last->next=nnode;
    last=nnode;
}

void delete_atBeg()
{
    struct node *temp;
    if(start==NULL)
    {
        printf("\nList Empty");
        return;
    }
    else if (start->next==NULL)
    {
        temp=start;
        start=NULL;
        last=NULL;
        printf("\n%d is deleted",temp->info);
        return;
    }
    temp=start;
    start=start->next;
    start->prev=NULL;
    printf("\n%d item is deleted",temp->info);
    free(temp);

}

void delete_atLast()
{
    struct node *temp;
    if(start==NULL)
    {
        printf("\nList is empty.");
        return;
    }
    if(last->prev==NULL)
    {
        temp=last;
        start=last=NULL;
        printf("\n%d is deleted",temp->info);
        return;
    }
    temp=last;
    last=last->prev;
    last->next=NULL;
    printf("\n%d is deleted",temp->info);
    free(temp);
}

void display()
{
    struct node *temp;
    temp=start;
    if (start==NULL){
        printf("\nList Empty.");
        return;
    }
    printf("\nThe list elements are: \n");
    while (temp!=NULL){
           printf("\n%x--------->%d ......(data)",temp->next,temp->info);
           temp=temp->next;
    }
}


int main()
{
    int ch;
    menu();
    while(1)
    {
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0:
                menu();
                break;
            case 1:
                insert_beg();
                break;
            case 2:
                insert_atLast();
                break;
            case 3:
                delete_atBeg();
                break;
            case 4:
                delete_atLast();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(1);
            default:
                printf("\nInvalid Choice.");
        }
    }

}




