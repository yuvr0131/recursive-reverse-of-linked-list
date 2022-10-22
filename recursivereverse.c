#define NULL 0

#include <stdio.h>
#include <stdlib.h>
//#define NULL 0

struct node
{
    int INFO;
    struct node *LINK;
};

struct node *INSERTBEG(struct node *START, int ITEM)
{
    struct node *NEW = (struct node *)malloc(sizeof(struct node));

    NEW->INFO = ITEM;
    NEW->LINK = START;
    START = NEW;
    return (START);
}
void TRAVERSE(struct node *START)
{
    struct node *PTR = START;

    while (PTR != NULL)
    {
        printf("%d ", PTR->INFO);

        PTR = PTR->LINK;
    }
}
struct node*reverse(struct node*START)
{
    if(START==NULL || START->LINK==NULL)
    return START;

struct node* newSTART=reverse(START->LINK);

START->LINK->LINK=START;
START->LINK=NULL;
return newSTART;
}
 
    

void main()
{
    struct node *START = NULL;
    int ITEM, choice = 1;

    while (choice!=3)
    {
        printf("press 1 for insert\n press 2 for traverse\n press 3 for reverse\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter the element\n");
            scanf("%d", &ITEM);
            START = INSERTBEG(START, ITEM);
            break;

        case 2:
            TRAVERSE(START);
            break;
        case 3: START=reverse(START)  ;
                TRAVERSE(START);
             break;
        }
    }
}