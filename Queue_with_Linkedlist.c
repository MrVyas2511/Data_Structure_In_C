 #include<conio.h>
 #include<stdio.h>
 #include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *front=NULL;
struct node*rear=NULL;
void insert()
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    printf("\n\nEnter the value : ");
    scanf("%d",&ptr->data);
    ptr->next = NULL;
    if(front==NULL&&rear==NULL)
    {
        front= ptr;
        rear=ptr;

    }
    else
    {
        rear->next = ptr;
        rear=ptr;

    }
    printf("\n----Insertion done-------");
}
void display()
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr = front;
    if(ptr==NULL)
    {
        printf("--Queue is empty");
    }
    else
    while(ptr!=NULL)
    {

        printf("\nelement = %d",ptr->data);
        ptr=ptr->next;
    }
}
void deletion()
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr = front;
    if(front==NULL || front>rear)
    {
        printf("--Queue is empty");
    }
    else
    {
        front = front->next;
        free(ptr);
    }
    printf("\n----deletion done-------");

}
void peek()
{
    printf("\nTop element is %d",rear->data);
}

 main()
 {
    int i;
    while(i!=5)
    {
    printf("\n *****MAIN MENU*****");
    printf("\n 1. INSERT");
    printf("\n 2. DELETE");
    printf("\n 3. PEEK");
    printf("\n 4. DISPLAY");
    printf("\n 5. EXIT");
    printf("\n *******************");

    printf("\n Enter your option : ");
    scanf("%d", &i);
    switch(i)
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

    printf("\n\n----Press any key-----");
    getch();
    system("cls");
    }
 }
