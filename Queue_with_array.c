#include<conio.h>
#include<stdio.h>
int queue[100];
int front=-1 ,rear = -1;
void insertion()
{
    int value;
    printf("\nEnter the value :");
    scanf("%d",&value);
        if(rear==99)
        {
            printf("Queue Overflow");
        }
        else if(front==-1 && rear==-1)
        {
            front++;
            rear++;
            queue[rear]=value;
        }
        else
        {
            rear++;
            queue[rear]=value;
        }
    printf("\n\n-----Insertion done------ ");

}
void deletion()
{
    if(front==-1||front>rear)
    {
        printf("Queue ni underflow");
    }
    else
    {
    printf("\n--deleted element is  %d",queue[front]);
    front++;
    }
}
void peek()
{

    if(front==-1||front>rear)
    {
        printf("Queue is empty");
    }
    else
        printf("\nTop element is %d",queue[rear]);
}
void display()
{
    if(front==-1||front>rear)
    {
        printf("Queue is empty");
    }
    else
    {
        for(int i=front;i<=rear;i++)
        {
            printf("\nElement = %d",queue[i]);

        }
    }
}
main()
{
    int i;
    while(i!=5)
    {
    printf("\n------------Operation On Queue----------\n");
    printf("\n\n1. Display queue . ");
    printf("\n2. Insert element in queue.");
    printf("\n3. delete element from queue. ");
    printf("\n4. display the peek value.");
    printf("\n5. exit");
    printf("\n----------------------------------------\n");
    printf("\n\n->Enter the choice : ");
    scanf("%d",&i);

    switch(i)
    {
    case 1:
        display();
        break;
    case 2:
        insertion();
        break;
    case 3:
        deletion();
        break;
    case 4:
        peek();
        break;
    }
    printf("\n\nPress any key to continue --->>");
    getch();
    system("cls");
    }
}
