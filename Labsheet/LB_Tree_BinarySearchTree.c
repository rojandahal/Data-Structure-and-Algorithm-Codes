#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct BinarySearch
{
    struct BinarySearch *left;
    int info;
    struct BinarySearch *right;
};
struct BinarySearch *root=NULL;
void Menu()
{
    printf("\nMenu.");
    printf("\n1.Insert a node");
    printf("\n2.Delete a node");
    printf("\n3.Pre-order traversal");
    printf("\n4.Post-Order traversal");
    printf("\n5.In-order traversal");
    printf("\n6.Print list of leaf nodes");
    printf("\n7.Print list of the nodes with single child");
    printf("\n8.Print list of nodes with two children");
}

void InsertNode()
{
    struct BinarySearch *nnode,*temp;
    nnode=(struct BInarySearch*)malloc(sizeof(struct BinarySearch));
    printf("\nEnter the data to enter.");
    scanf("%d",&nnode->info);
    nnode->left=NULL;
    nnode->right=NULL;
    if(root==NULL){
        root=nnode;
        return;
    }
        temp=root;
    Lab: if(temp->info > nnode->info)
        {
            if(temp->left==NULL){
                temp->left=nnode;
            }else{
                temp=temp->left;
                goto Lab;
            }
        }else
            {
                if(temp->right==NULL){
                    temp->right=nnode;
                }else {
                    temp=temp->right;
                    goto Lab;
                }
            }
}

void preTraverse(struct BinarySearch *rt)
{
    if(rt==NULL)
        return;
    printf("\t %d",rt->info);
    preTraverse(rt->left);
    preTraverse(rt->right);
}

void postTraverse(struct BinarySearch *rt)
{
    if(rt==NULL)
        return;
    postTraverse(rt->left);
    postTraverse(rt->right);
    printf("\t %d",rt->info);
}

void InTraverse(struct BinarySearch *rt)
{
    if(rt==NULL)
        return;
    InTraverse(rt->left);
    printf("\t %d",rt->info);
    InTraverse(rt->right);
}

void printLeafNode()
{

}

int main()
{
    int ch;
    Menu();
    while(1)
    {
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0:
                Menu();
                break;
            case 1:
                InsertNode();
                break;
            case 2:
                printf("\nDelete function unavailable!");
                break;
            case 3:
                preTraverse(root);
                break;
            case 4:
                postTraverse(root);
                break;
            case 5:
                InTraverse(root);
                break;
        }
    }
}






