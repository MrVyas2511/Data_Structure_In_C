#include<conio.h>
#include<stdio.h>
#define max 10
int top=-1,i;
void push(int arr[])
{
    if(top==max)
    {
        printf("\n--Stack is overflow--\n");
    }
    else
    {
    top++;
    printf("Enter value : ");
    scanf("%d",&arr[top]);
    }
}
void display(int arr[])
{

    if(top==(-1))
        printf("\nStack is empty\n");
    else
    {
        for(i=top;i>=0;i--)
        {
            printf("%d\n",arr[i]);
        }
    }
}
void count(int top)
{
    printf("Number of membert = %d ",top+1);
}
void pop(int arr[])
{
    if(top==(-1))
        printf("Stack is empty");
    else
    {
    printf("value %d deleted",arr[top]);
    top--;
    }
}
void peep(int arr[])
{
    if(top==(-1))
        printf("Stack is empty");
    else
    printf("value at top = %d",arr[top]);
}


main()
{
    int stack[max],n;
     while(n!=6)
    {
    printf("\n----Operation on stack-----");
    printf("\n1. display stack.");
    printf("\n2. push stack");
    printf("\n3. pop stack");
    printf("\n4. peep stack");
    printf("\n5. count number of member");
    printf("\n6. exit");
    printf("\n-----------------------------");
    printf("\nEnter the number :- ");
    scanf("%d",&n);

        switch(n)
        {
            case 1:
                display(stack);
                break;
            case 2:
                push(stack);
                break;
            case 3:
                pop(stack);
                break;
            case 4:
                peep(stack);
                break;
            case 5:
                count(top);
                break;
        }
        printf("//Press any key to go to main menu//");
        getch();
        system("cls");
    }



}
