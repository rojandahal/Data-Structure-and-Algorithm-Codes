#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};

struct node *start=NULL;

void menu()
{
    printf("0.To print menu");
    printf ("\n1.To push in stack. ");
    printf ("\n2.To pop from stack. ");
    printf ("\n3.To show Top of Stack. ");
    printf ("\n4. Display all Stack. ");
    printf("\n5.Exit");
}

int push()                      //To push into the linked list stack
{
    struct node *temp; int value;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the value to push in stack: ");
    scanf("%d",&value);
    temp->info = value;
    if(start==NULL)
    {
        temp->next=NULL;
        start=temp;
        return value;                   //Returned to be displayed
    }

        temp->next = start;
        start = temp;

    return value;

}

int pop()                       //To pop from the front of the linked list stack
{
    struct node *temp; int value;
    if(start==NULL)                     //If first pointer is null then the linked list is also null
    {
        printf ("\nThe stack is empty.");
        return -1;
    }
    else if (start->next==NULL)
    {
        temp=start;
        value=start->info;
        start=NULL;
        free(temp);
        return value;
    }

        value=start->info;
        temp=start;
        start=start->next;
        free(temp);
        return value;


}

void display()                      //To display all the values in the stack
{
    struct node *temp;
    if (start==NULL)
    {
        printf ("\nStack is Empty.");
        return;
    }
    else if (start->next==NULL)
    {
        printf ("\n %x----->%d ",start,start->info);
        return;
    }

    temp = start;
    while (temp!=NULL)                          //Traverse through the linked list
    {
        printf ("\n %x----->%d ",temp,temp->info);
        temp=temp->next;
    }

}

int  main ()
{
    int ch,data;
    menu();
    while (1)
    {
        printf("\nEnter your choice: ");
        scanf ("%d",&ch);
        switch(ch)
        {
            case 0:
                menu();
                break;
            case 1:
                data=push();                            //Return and store the value that is pushed to be displayed
                printf ("\n%d : value pushed to stack.",data);
                break;
            case 2:
                data = pop();                           //Return and store the value that is pushed to be displayed
                if (data==-1)
                    break;
                printf("\n%d: data is popped from stack.",data);
                break;
            case 3:
                if (start==NULL)
                {
                    printf("\nStack is Empty!!!");
                    break;
                }
                data= start->info;
                printf ("\nTop of stack is: %d",data);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(1);
            default:
                printf("\nInvalid choice!!!");


        }
    }

    getch();
}
