#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct stack
{

    int data;
    struct stack *next;
};
struct stack *top=NULL;
void create_stack()
{
    struct stack *ptr= (struct stack*)malloc(sizeof(struct stack));
    printf("\nEnter first element :");
    scanf("%d",&ptr->data);
    ptr->next=NULL;
    top= ptr;
}
void push()
{
    struct stack *ptr= (struct stack*)malloc(sizeof(struct stack));
    printf("\nEnter element :");
    scanf("%d",&ptr->data);
    ptr->next=top;
    top= ptr;
    printf("\n\n||--data pushed successfully--||");
}
void pop()
{
    struct stack *ptr = top;
    if(top==NULL)
    {
        printf("\n--Stack is empty--");
    }
    else
    {
        printf("poped value : = %d",top->data);
        top=top->next;
        free(ptr);
    }
    printf("\n\n||--data poped successfully--||");
}
void peep()
{
    if(top==NULL)
    {
        printf("\n--Stack is empty--");
    }
    else
    {
        printf("top element = %d",top->data);
    }
}

void display(struct stack *top)
{
    struct stack *ptr = top;
    if(ptr==NULL)
    {
        printf("\n--Stack is empty--");
    }
    else
    {
        while(ptr!=NULL)
        {
            printf("\nElement = %d",ptr->data);
            ptr = ptr->next;
        }
    }

}

main()
{
    int i;
    top = NULL;
    while(i!=6)
    {
    printf("\n----------operation on stack----------\n");
    printf("\n1. create stack ");
    printf("\n2. push value");
    printf("\n3. pop value");
    printf("\n4. peek value");
    printf("\n5. display stack ");
    printf("\n6. print Revers the stack");
    printf("\n7. exit");
    printf("\n------------------------------------------");
    printf("\nEnter number : -");
    scanf("%d",&i);

    switch(i)
    {
    case 1:
        create_stack();
        break;
    case 2:
        push();
        break;
    case 3:
        pop();
        break;
    case 4:
        peep();
        break;

    case 5:
        display(top);
        break;
    }

    printf("\n\n\n\n\n//-Press any key to go main menu-//");
    getch();
    system("cls");
    }
}
