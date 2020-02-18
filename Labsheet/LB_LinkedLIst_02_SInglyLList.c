#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *next;
};
struct node *start=NULL;

void menu()
{
    printf("\n0.Print Menu");
    printf("\n1.Insert at first.");
    printf("\n2.Insert at last.");
    printf("\n3.Insert at nth position.");
    printf("\n4.Delete from first.");
    printf("\n5.Delete from last.");
    printf("\n6.Delete from nth position.");
    printf("\n7.Search any value.");
    printf("\n8.Display the list.");
    printf("\n9.Exit");
}

void insert_atBeg(int value)                //Inserting values at the beginning
{
    struct node *nnode;
    nnode=(struct node *)malloc(sizeof(struct node));       //Memory allocation for the structure
    nnode->info = value;
    if(start==NULL){
        nnode->next=start;
        start=nnode;
        return;
    }
    nnode->next=start;                      //Applicable for all the nodes
    start = nnode;
}

void insert_atLast(int val)                 //Inserting value at last node and defining the inserted node at last
{
    struct node *temp,*nnode;
    nnode=(struct node *)malloc(sizeof(struct node));
    nnode->info=val;
    nnode->next=NULL;                           //Last node next is always null
    temp=start;
    if (start == NULL){
        start=nnode;
        return;
    }
    while(temp->next!=NULL)                     //Loop until the value pointed by temp is null and inserting at that position
    {
        temp=temp->next;                        //Traverse through the linked list
    }

    temp->next=nnode;
}

void insert_atPOS(int pos)                  //Inserting at nth position of the linked List
{
    int cnt,i,val;
    struct node *temp,*nnode;
    cnt=getList_size();
    if(pos>cnt || pos<=0)
    {
        printf("\nInvalid Position to add.");
        return;
    }
    else{
        temp=start;
        i=1;
        while(i!=pos-1){
            temp=temp->next;
            i++;
        }
        nnode=(struct node *)malloc(sizeof(struct node));
        printf("\nEnter the data to add: ");
        scanf("%d",&val);
        nnode->info=val;
        nnode->next=temp->next;
        temp->next=nnode;
    }

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
    while (temp!=NULL){                                                     //Loop through the linked list until the list is null to display until null
           printf("\n%x--------->%d ......(data)",temp->next,temp->info);
           temp=temp->next;
    }
}

void delete_fromFirst()                     //Deleting the first node of the linked list
{
    struct node *temp;
    temp=start;
    start=start->next;
    printf("\nThe value %d is deleted.",temp->info);
    free(temp);                                                     //freeing memory of the temporary variable
}

int getList_size()
{
    int cnt=0;
    struct node *temp;
    temp=start;
    while(temp!=NULL){
        temp=temp->next;
        cnt++;
    }
    return cnt;

}

void delete_from_last()                 //Delete from last
{
    struct node *temp,*temp1;
    temp=start;
    if(start->next==NULL)
       {
            temp=start;
            start=NULL;
            printf("\nDeleted item is: %d",temp->info);
            free(temp);
            return;
       }

    while(temp->next->next!=NULL)           //Traverse to second last structure
    {
        temp=temp->next;
    }
    temp1=temp->next;
    temp->next=NULL;
    printf("\nDeleted item is: %d",temp1->info);
    free(temp1);

}

void delete_atPOS(int pos)              //THis function traverses through the list and finds the position and delete the node
{
    int cnt = getList_size(),i;          //and makes the previous  node to the pointer of the next node
    struct node *temp,*temp1;
    if(start==NULL){
        printf("\nList is Empty! ");
        return;
    }
    else if (pos>cnt || pos<=0){
        printf("\nInvalid Position to delete! ");
        return;
    }
    else{
            if(pos==1){
                temp=start;
                start=start->next;
                printf("\nDeleted Item: %d",temp->info);
                free(temp);
                return;
            }
        temp=start;
        i=1;
        while(i!=pos-1){
            temp=temp->next;
            i++;
        }
        temp1=temp->next;
        temp->next=temp->next->next;
        printf("\nDeleted Item: %d",temp1->info);
        free(temp1);
    }
}

int searching(int num)
{
    struct node *temp;
    temp=start;
    if(temp==NULL){
        printf("\nList is empty");
        return -1;
    }
    while(temp!=NULL){
        if(temp->info==num){
            return temp->info;
        }
        temp=temp->next;
    }
    return -1;
}



int main ()
{
    int data,pos,ch,temp;
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
            printf("\nEnter the data to add: ");
            scanf("%d",&data);
            insert_atBeg(data);
            break;
        case 2:
            printf("\nEnter the data to add: ");
            scanf("%d",&data);
            insert_atLast(data);
            break;
        case 3:
            printf("\nEnter the position to store data.");
            scanf("%d",&pos);
            if(start==NULL && pos!=1){
                    printf("\nList is that big!");
                    break;
                }
            else if (pos==1){
                    printf("\nEnter the data to add: ");
                    scanf("%d",&data);
                    insert_atBeg(data);
                    break;
                }

            insert_atPOS(pos);
            break;
        case 4:
            delete_fromFirst();
            break;
        case 5:
            delete_from_last();
            break;
        case 6:
            printf("\nEnter the position to delete data.");
            scanf("%d",&pos);
            delete_atPOS(pos);
            break;
        case 7:
            printf("\nEnter the data to search: ");
            scanf("%d",&data);
            temp=searching(data);
            if(temp==-1)
                printf("\nItem not found in the list.");
            else
                printf("\n%d item found in the list",temp);
            break;
        case 8:
            display();
            break;
        case 9:
            exit(1);
            break;

        }

    }









}
