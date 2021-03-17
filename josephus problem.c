#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
void create_LL()
{

    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr= head;
    ptr->data = 1;
    ptr->next = NULL;
}
void insert()
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr= head;
    struct node *p = (struct node*)malloc(sizeof(struct node));
    p->data = 2;
    ptr->next = p;
    p->next = head;
    ptr = p;




}
void display()

{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr = head;
    while(ptr ->next!=head)
    {
        printf("\n%d",ptr->data);
        ptr = ptr->next;
    }
}
main()
{
    create_LL();
    printf("hello");
    display();
}
