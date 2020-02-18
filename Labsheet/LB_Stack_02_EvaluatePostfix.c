#include <stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int main ()
{
    char postFix[20],po;
    int Vstack[20];
    int res,i,sVal,tos=-1;
    int opnd2,opnd1;
    printf("\nEnter the postfix expression:\n");
    gets(postFix);

    for (i=0;postFix[i]!='\0';i++)
    {
        po=postFix[i];
        if(isalpha(po))
        {
            printf("\nEnter the corresponding value of the operand: %c \n",postFix[i]);
            scanf("%d",&sVal);
            Vstack[++tos]=sVal;
        }
        else
        {
            opnd2 = Vstack[tos--];
            opnd1 = Vstack[tos--];
             switch(postFix[i])
    {
        case '+' :  res= opnd2+opnd1;
                    return res;
                    break;

        case '-' :res= opnd2-opnd1;
                    return res;
                    break;

        case '*' : res= opnd2*opnd1;
                    return res;
                    break;

        case '/' : res=(int) opnd2/opnd1;
                    return res;
                    break;

        case '$' : res= pow(opnd1,opnd2);
                    return res;
                    break;

        default:    printf("Invalid");



    }
            Vstack[++tos] = res;

        }
    }

    printf("\nThe Evaluated value is: %d ",Vstack[tos]);

    getch();



}










