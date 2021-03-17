#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#define max 4
int queue[max];
int front,rear;
void insert()
{
    int x;
    printf("\nEnter the value");
    scanf("%d",&x);
    if(rear==max-1 && front == 0||front==rear+1)
    {
        printf("\nQUEUE OVERFLOW");
    }
    else{
    if(front==-1&&rear==-1)
    {
        front=0;
        rear=0;
    }
    else if(rear==max-1&&front!=0)
    {
        rear = 0;
    }
    else
        rear++;
    queue[rear]=x;
    printf("\n\n-----DATA INSERTED------");
    }
}
void display()
{
    if(rear==-1 && front==-1)
    {
     printf("\nQUEUE IS EMPTY");
    }
   else if(front <=rear)
    {
        for(int i=front;i<=rear;i++)
        {
          printf("\nElement : %d",queue[i]);
        }
    }
    else
    {
        for(int i=front;i<=(max-1);i++)
        {
            printf("\nElement : %d",queue[i]);
        }
        for(int i=0;i<=rear;i++)
        {
            printf("\nElement : %d",queue[i]);
        }
    }
}
void peek()
{
   if(rear==-1 && front==-1)
    {
     printf("\nQUEUE IS EMPTY");
    }
    else if(rear>front)
    {
        printf("\ntop element is %d",queue[rear]);
    }
    else
        printf("\ntop element is %d",queue[rear]);
}
void deletion()
{
    if(rear==-1 && front==-1)
    {
     printf("\nQUEUE IS EMPTY");
    }
    else
    {
        printf("\n\nDeleted element = %d",queue[front]);
        if(front==rear)
        rear=front=-1;
    else if(front==max-1)
        front=0;
    else
        front++;
    }
}

int main()
{
    int n;
    front=-1;
    rear=-1;
    while(n!=5)
    {
    printf("\n---------Circular Queue---------\n");
    printf("\n1. Insert element");
    printf("\n2. Delete element");
    printf("\n3. Peek element");
    printf("\n4. display queue");
    printf("\n5. Exit");
    printf("\n--------------------------------\n");
    printf("\n\nEnter choice : ");
    scanf("%d",&n);

    switch(n)
    {
    case 1:
        insert();
        break;
    case 2:
        deletion();
        break;
    case 3:
       peek();
        break;
    case 4:
        display();
        break;
    }
    printf("\n\n-----Enter any key------");
    getch();
    system("cls");
    }
}
