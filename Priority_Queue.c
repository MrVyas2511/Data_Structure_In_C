#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    int priority;
    struct node *next;
};
struct node *head = NULL;
void insert()
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    struct node *p = head;
    printf("\nEnter the value : ");
    scanf("%d",&ptr->data);
    printf("\nEter the priority :");
    scanf("%d",&ptr->priority);
    if(p==NULL || ptr->priority < p->priority)
    {
        ptr->next = head;
        head = ptr;

    }
    else
    {
    while(p->next!=NULL && ptr->priority >= p->next->priority )
    {
        p = p->next;
    }
    ptr->next = p->next;
    p->next= ptr;
    }
    printf("\n---Data Inserted---");
}
void delete()
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr =  head;
    if(ptr==NULL)
    {
        printf("\n QUEUE is empty");
    }
    else
    {
    printf("\nDeleted data %d",head->data);
    head = head->next;
    free(ptr);
    }

}
void display()
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr =  head;
    if(ptr == NULL)
        printf("\n--queue Is Empty--");
    else
    while(ptr!=NULL)
    {
        printf(" %d ",ptr->data);
        ptr = ptr->next;
    }
}
main()
{
    int i;
    while(i!=4)
    {
        printf("\n--------Priority Queue--------");
        printf("\n1. Insert data");
        printf("\n2. Delete data");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\n------------------------------");
        printf("\n\nEnter the choice : ");
        scanf("%d",&i);
        switch(i)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        }
        printf("\n----Enter any key------");
        getch();
        system("cls");
    }

}
