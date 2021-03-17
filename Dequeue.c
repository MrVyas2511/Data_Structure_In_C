#include<conio.h>
#include<stdio.h>
#define max 5
int queue[max];
int front=-1,rear=-1;
void insert_left()
{
    int n;
    printf("\nEnter the value : ");
    scanf("%d",&n);
    if(rear==max-1 && front ==0 || front == rear+1)
    {
        printf("\n---Queue OVERFLOW");
    }
    else
    {
    if(front==-1)
        rear=front = 0;
    else if(front==0)
        front=max-1;
    else
        front--;
    queue[front]=n;
    printf("\n-----Insertion Done-----");
    }
}

void insert_right()
{
     int n;
    printf("\nEnter the value : ");
    scanf("%d",&n);
    if(rear==max-1&&front ==0 || front ==rear+1)
    {
        printf("\n---Queue OVERFLOW---");
    }
    else
    {
    if(front==-1)
        rear=front = 0;
    else if(rear==max-1)
        rear=0;
    else
        rear++;
    queue[rear]=n;
    printf("\n-----Insertion Done-----");
    }
}
void delete_right()
{
    if(rear==-1 && front == -1)
    {
        printf("\n---Queue Is EMPTY---");
    }
    else
    {
        printf("\nDeleted element is %d",queue[rear]);
        if(front==rear)
            front=rear=-1;
        else if(rear==0)
             rear = max-1;
        else
            rear--;
        printf("\n ----Deletion Done---");
    }

}
void delete_left()
{
    if(rear==-1 && front == -1)
    {
        printf("\n---Queue Is EMPTY---");
    }
    else
    {
        printf("\nDeleted element is %d",queue[front]);
        if(front==rear)
            front=rear=-1;
        else if(front==max-1)
             rear = 0;
        else
            front++;
        printf("\n ----Deletion Done---");
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
          printf("  %d  ",queue[i]);
        }
    }
    else
    {
        for(int i=front;i<=(max-1);i++)
        {
            printf(" %d  ",queue[i]);
        }
        for(int i=0;i<=rear;i++)
        {
            printf(" %d  ",queue[i]);
        }
    }

}
void input_restriction()
{
    int i;
    system("cls");
    while(i!=5)
    {
    printf("\n------Input restriction queue-----");
    printf("\n1. insert element from left");
    printf("\n2. delete element from left");
    printf("\n3. delete element from right");
    printf("\n4. display element");
    printf("\n5. go to main menu");
    printf("\n\n---------------------------------");
    printf("\nEnter the number :");
    scanf("%d",&i);
    switch(i)
    {
    case 1:
        insert_left();
        break;
    case 2:
        delete_left();
        break;
    case 3:
        delete_right();
        break;
    case 4:
        display();
        break;
    case 5:

        break;
    }
    printf("\n---Press any key---");
    getch();
    system("cls");

    }

}
void output_restriction()
{
    int i;
    system("cls");
    while(i!=5)
    {
    printf("\n------Input restriction queue-----");
    printf("\n1. insert element from left");
    printf("\n2. insert element from right");
    printf("\n3. delete element from right");
    printf("\n4. display element");
    printf("\n5. go to main menu");
    printf("\n\n---------------------------------");
    printf("\nEnter the number :");
    scanf("%d",&i);
    switch(i)
    {
    case 1:
        insert_left();
        break;
    case 2:
        insert_right();
        break;
    case 3:
        delete_right();
        break;
    case 4:
        display();
        break;
    case 5:

        break;
    }
    printf("\n---Press any key---");
    getch();
    system("cls");
    }
}
main()
{
    int n,i;
    while(n!=3)
    {
        LOOP:
    printf("\n--------------Dequeue--------------");
    printf("\n\n1. Input restriction queue");
    printf("\n\n2. output restriction queue");
    printf("\n\n3. Exit");
    printf("\n-----------------------------------");
    printf("\nEnter the choice : ");
    scanf("%d",&n);

    switch(n)
    {
    case 1:
       input_restriction();
       break;
    case 2:
        output_restriction();
        break;
    }
    }
}
