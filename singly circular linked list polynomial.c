#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//define the structure
//structure to represent the a node in polynomial linked list
struct node
{
    int coef;
    int expx,expy,expz;
    struct node *next;
};
//define the global variables
typedef struct node *NODE;
NODE header =NULL,temp=NULL;
//creating the header node
void createHeaderNode()
{
    header=(NODE)malloc(sizeof(struct node));
        header->coef=0;
        header->expx=-1;
        header->expy=-1;
        header->expz=-1;
        header->next=header;
}
//creating node
void createNode()
{
    temp=(NODE)malloc(sizeof(struct node));

    printf("Enter the coeffecient:");
    scanf("%d",&temp->coef);
    printf("Enter the exponential of x:");
    scanf("%d",&temp->expx);
    printf("Enter the exponential of y:");
    scanf("%d",&temp->expy);
    printf("Enter the exponential of z:");
    scanf("%d",&temp->expz);

    temp->next=temp;

    header->coef=(header->coef)+1;
}
//inserting in rare
void insertRear()
{
    NODE current;
    createNode();
    if(header->next==header)
    {
        header->next=temp;
    }
    else{
        current=header;
        while(current->next!=header)
        {
            current=current->next;
        }
        current->next=temp;
    }
    temp->next=header;
    printf("\nNumeber of terms=%d\n",header->coef);

}

//displaying
void display()
{
    NODE current;
    if(header->next==header)
    {
        printf("List is empty");
    }
    else{
        current=header->next;
        while(current!=header)
        {
            if(current->coef<0)
                printf("%d x^%d y^%d z^%d",current->coef,current->expx,current->expy,current->expz);
            else
                printf("+%d x^%d y^%d z^%d",current->coef,current->expx,current->expy,current->expz);
            current=current->next;
        }
    }
    printf("\nNumeber of terms=%d\n",header->coef);

}

//evaluate
void evaluate()
{
    double result=0;
    int x,y,z;
    NODE current;
    printf("Enter the value of x:");
    scanf("%d",&x);
    printf("Enter the value of y:");
    scanf("%d",&y);
    printf("Enter the value of z:");
    scanf("%d",&z);
    if(header->next==header)
        printf("List is empty");
    else
    {
        current=header->next;
        while(current!=header)
        {
            result +=current->coef*pow(x,current->expx)*pow(y,current->expy)*pow(z,current->expz);
            current=current->next;
        }
        printf("Polynomial Evaluation value=%2f",result);
    }
}
void main()
{
    int iterator,noofcoef;

    createHeaderNode();
    printf("Enter the number of terms in polynomial:");
    scanf("%d",&noofcoef);
    for(iterator=0;iterator<noofcoef;iterator++)
    insertRear();
    display();
    evaluate();

}


