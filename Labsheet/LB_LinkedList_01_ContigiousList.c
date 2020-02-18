#include<stdio.h>
#include<conio.h>
#define max 10
struct CList
{
    int item[max];
    int L_ind;
};

void menu()
{
    printf("\n0.Display Menu");
    printf("\n1.Inserting data");
    printf("\n2.Deleting data");
    printf("\n3.Display all data");
    printf("\n4.Search a value");
    printf("\n5.Exit");
}

void inserting(struct CList *lt)
{
    int i,pos,data;
    if(lt->L_ind==max-1){
        printf("\nList is Full.");
        return;
    }
    printf("\nEnter the position to enter data: ");
    scanf("%d",&pos);
    if(pos>(lt->L_ind)+1 || pos<0){
        printf("\nInvalid Position.");
        return;
    }
    printf("\nEnter the data to enter: ");
    scanf("%d",&data);
    i=lt->L_ind;
    while(i>=pos){
        lt->item[i+1]=lt->item[i];
        i--;
    }
    lt->item[pos]=data;
    lt->L_ind++;
}

void deleting(struct CList *lt)
{
    int i,pos,x;
    if(lt->L_ind==-1){
        printf("\nList Empty.");
        return;
    }
    printf("\nEnter the position to delete: ");
    scanf("%d",&pos);
    if(pos>lt->L_ind || pos<0){
        printf("\nInvalid Position!");
        return;
    }
    x=lt->item[pos];
    i=pos;
    while(i+1<=lt->L_ind){
        lt->item[i]=lt->item[i+1];
        i++;
    }
    lt->L_ind--;
    printf("\nDeleted item: %d",x);
}

void display(struct CList *lt)
{
    int i;
    if(lt->L_ind==-1){
        printf("\nList is empty.");
        return;
    }
    for(i=0;i<=lt->L_ind;i++){
        printf("\t%d",lt->item[i]);
    }
}

void searching(struct CList *lt)
{
    int i,data;
    if(lt->L_ind==-1){
        printf("\nList is empty.");
        return;
    }
    printf("\nEnter data to search: ");
    scanf("%d",&data);
    for(i=0;i<=lt->L_ind;i++){
        if(lt->item[i]==data){
            printf("\nYour item found in position %d = %d",i,lt->item[i]);
            return;
        }
    }
    printf("\nNot found in the list.");
}

int main()
{
    struct CList *lt;
    lt=(struct CList*)malloc(sizeof(struct CList));
    lt->L_ind=-1;
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
                inserting(lt);
                break;
            case 2:
                deleting(lt);
                break;
            case 3:
                display(lt);
                break;
            case 4:
                searching(lt);
                break;
            case 5:
                exit(1);
            default:
                printf("\nInvalid choice");
        }
    }
    getch();
}


