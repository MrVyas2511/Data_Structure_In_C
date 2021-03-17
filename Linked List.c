#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
struct node
    {
      int data;
      struct node *next;
    };

void display(struct node *head)
    {
        struct node *ptr=(struct node*)malloc(sizeof(struct node));
        ptr=head;
        printf("\n---List of the data--\n");
        while(ptr!=NULL)
        {
            printf("Element = %d\n",*ptr);
            ptr=ptr->next;
        }
    }

struct node *addatfirst(struct node *head)
    {
        struct node *ptr = (struct node*)malloc(sizeof(struct node));

        printf("Enter value : ");
        scanf("%d",&ptr->data);

        ptr->next = head;

        printf("\n\n$---data added successfully---$\n\n");
        return ptr;


    }
struct node *addatmid(struct node *head)
    {
        int pos,i=0;
        struct node *p=head;
        struct node *ptr = (struct node*)malloc(sizeof(struct node));

        printf("Enter the position :");
        scanf("%d",&pos);
        printf("\nEnter value : ");
        scanf("%d",&ptr->data);

        while(i!=(pos-1))
        {

            p=p->next;
            i++;
        }

        ptr->next=p->next;
        p->next= ptr ;

        printf("\n\n$---data added successfully---$\n\n");
        return head;


    }
struct node *addatend(struct node *head)
    {
        struct node *p=head;
        struct node *ptr = (struct node*)malloc(sizeof(struct node));


        printf("Enter value  : ");
        scanf("%d",&ptr->data);
        while(p->next!=NULL)
            {
                p=p->next;
            }

        p->next=ptr;
        ptr->next=NULL;

        printf("\n\n$---data added successfully---$\n\n");
        return head;

    }
struct node *addafternode(struct node *head,struct node *nod)
    {

        struct node *ptr = (struct node*)malloc(sizeof(struct node));

        printf("Enter value : ");
        scanf("%d",&ptr->data);

        ptr->next = nod->next;
        nod->next = ptr;

        printf("\n\n$---data added successfully---$\n\n");
        return head;

    }

struct node *delfromfirst(struct node *head)
{
         struct node *ptr = (struct node*)malloc(sizeof(struct node));
         ptr=head;
         head = head->next;

         free(ptr);
         printf("\n\n&---Data deleted successfully---&\n\n");
         return head;

}
struct node *delfrommid(struct node *head)
{
        struct node *ptr = (struct node*)malloc(sizeof(struct node));
        struct node *p;
        int i=0,pos;

        p = head;
        printf("Enter the position :");
        scanf("%d",&pos);


        while(i!=(pos))
        {
            ptr=p;
            p=p->next;
            i++;
        }

        ptr->next=p->next;

        free(p);

        printf("\n\n&---Data deleted successfully---&\n\n");
        return head;



}
struct node *delfromlast(struct node *head)
{
        struct node *ptr = (struct node*)malloc(sizeof(struct node));
        struct node *prev;
        ptr = head;

        while(ptr->next!=NULL)
        {
            prev = ptr;
            ptr = ptr->next;
        }

        prev->next = NULL;

        free(ptr);

        printf("\n\n&---Data deleted successfully---&\n\n");
        return head;

}
struct node *delgivenval(struct node *head)
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    struct node *p;
    int data;
    ptr = head;

    printf("\n Enter value  :");
    scanf("%d",&data);

    while(ptr->data!=data)
    {
        p=ptr;
        ptr=ptr->next;
        if(ptr==NULL)
        {
            printf("---Data doesn't found---");
            break;
        }
    }
    p->next=ptr->next;

    free(ptr);

    return head;
}
 struct node *shortlist(struct node *head)
 {
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    int temp;
    struct node *p;
    ptr = head;
    while(ptr->next!=NULL)
    {
        p = ptr->next;
        while(p!=NULL)
        {
            if(ptr->data >= p->data )
            {
                temp = ptr->data;
                ptr->data = p->data;
                p->data = temp;

            }
            p=p->next;

        }
        ptr=ptr->next;

    }
    printf("\n\n&---Data shorted successfully---&\n\n");
    return head;
 }
 struct node *delbeforenode(struct node *head)
 {
     int x;
     struct node *ptr = (struct node*)malloc(sizeof(struct node));
     struct node *p= (struct node*)malloc(sizeof(struct node));
     ptr = head;
     printf("Enter the position:");
     scanf("%d",&x);
    for(int i=0;i<x;i++);
    {   p = ptr;
        ptr = ptr->next;
    }
    printf("\nDeleted element %d",ptr->data);
    p->next = ptr->next;
    return head;
    free(ptr);
}

main()
    {
        struct node *head = (struct node*)malloc(sizeof(struct node));
        struct node *first = (struct node*)malloc(sizeof(struct node));
        struct node *second = (struct node*)malloc(sizeof(struct node));
        struct node *third = (struct node*)malloc(sizeof(struct node));
        struct node *fourth = (struct node*)malloc(sizeof(struct node));
        struct node *fifth = (struct node*)malloc(sizeof(struct node));
        int i;

        head->data=16;
        head->next=first;

        first->data=127;
        first->next=second;

        second->data=17;
        second->next=third;

        third->data=14;
        third->next=fourth;

        fourth->data=10;
        fourth->next=fifth;

        fifth->data=16;
        fifth->next=NULL;

        while(i!=12)
        {
            printf("\n-------------operation_on_list---------------------");
            printf("\n\n 1.Display the whole list");
            printf("\n 2. Add data at the beginning of list.");
            printf("\n 3. Add data at after the mid or beetween the list.");
            printf("\n 4. Add data at the last of the list");
            printf("\n 5. Add data at the given position.");
            printf("\n 6. Delete data from beginning of the list.");
            printf("\n 7. Delete data from the beetween of the list.");
            printf("\n 8. Delete data from last of the list.");
            printf("\n 9. Delete the given value. ");
            printf("\n10. Delete befor given node");
            printf("\n 11. Short data in accending orders. ");
            printf("\n 12. exit");
            printf("\n --------------------------------------------------");
            printf("\n\n Enter the number :  ");
            scanf("%d",&i);

            switch(i)
                {
                case 1:
                    display(head);
                    break;
                case 2:
                    head = addatfirst(head);
                    break;
                case 3:
                    head = addatmid(head);
                    break;
                case 4:
                    head = addatend(head);
                    break;
                case 5:
                    head = addafternode(head,third);
                    break;
                case 6:
                    head = delfromfirst(head);
                    break;
                case 7:
                    head = delfrommid(head);
                    break;
                case 8:
                    head = delfromlast(head);
                    break;
                case 9:
                    head = delgivenval(head);
                    break;
                case 10:
                    head = delbeforenode(head);
                    break;
                case 11:
                    head = shortlist(head);
                    break;

                }
                printf("<<<---Press any key to go to main menu--->>>");
                getch();
                system("cls");
        }





    }
