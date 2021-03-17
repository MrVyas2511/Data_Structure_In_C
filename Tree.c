#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node          //create the node of LL
{
    struct node *left;
    int data;
    struct node *right;
};

struct node *root = NULL; //root node global declaration

void insert()
{
    int x,y;
    struct node *prntptr = (struct node*)malloc(sizeof(struct node));
    struct node *nodeptr = (struct node*)malloc(sizeof(struct node));
    struct node *newnode =  (struct node*)malloc(sizeof(struct node));

    printf("\nEnter the data :");
    scanf("%d",&x);            //user input the value for newnode

    newnode->data = x;
    newnode->left = NULL;
    newnode->right = NULL;

    if(root == NULL)        // new node inserting condition checking for root = null
    {
        root = newnode;
    }
    else
    {
        nodeptr = root;     //temp. node declaration
        prntptr = NULL;     //parent node declaration

    while(nodeptr!=NULL)     // searching for parent node
    {
        prntptr = nodeptr;

        if(x>nodeptr->data)
            nodeptr = nodeptr->right;
        else
            nodeptr = nodeptr->left;
    }

    if(x>prntptr->data)    //linking the newnode with its parent node
        prntptr->right = newnode;
    else
        prntptr->left = newnode;

    }
    printf("\n\n-------INSERTION DONE---------");
}
 int inorder_display(struct node *tree)  //function for in order traversing
 {
      if(tree==NULL)
      {
          return  0;
      }

        inorder_display(tree->left);
        printf("  %d  ",tree->data);
        inorder_display(tree->right);
 }
 int preorder_display(struct node *tree)  //function for preorder traversing
 {
      if(tree==NULL)
      {
          return  0;
      }

        printf("  %d  ",tree->data);
        preorder_display(tree->left);
        preorder_display(tree->right);
 }
 int postorder_display(struct node *tree)   //function for postorder traversing
 {

      if(tree==NULL)
      {
          return  0;
      }

        postorder_display(tree->left);
        postorder_display(tree->right);
        printf("  %d  ",tree->data);

 }
 void smallest_element( )
 {
     struct node *ptr = (struct node*)malloc(sizeof(struct node));
      ptr = root;
      while(ptr->left!=NULL)   // traversing to left leaf node
      {
          ptr = ptr->left;
      }
      printf("\n Largest number is = %d",ptr->data);  //printing leaf/smallest node
 }
 int largest_element()
 {
      struct node *ptr = (struct node*)malloc(sizeof(struct node));
      ptr = root;

      while(ptr->right!=NULL)  //traversing to right leaf node
      {
          ptr = ptr->right;
      }
      printf("\n Largest number is = %d",ptr->data);  //printing leaf/largest node
 }
struct node *largest_node(struct node *root)    //*function to find largest node #extra//
{
        if(root==NULL||root->right==NULL)
            return root;                         //return largest node
         return largest_node(root->right);
}
struct node * minValueNode(struct node* root) // function to find smallest node
{
    if(root==NULL||root->left==NULL)
            return root;                         //return smallest node
         return largest_node(root->left);
}

struct node* delete_node(struct node* root, int x)
{

  if (root == NULL)
        return root;

    // If the key to be deleted is smaller than the
    // root's key, then it lies in left subtree
    if ( x < root->data )
        root->left = delete_node(root->left, x);

    // If the key to be deleted is greater than the
    // root's key, then it lies in right subtree
    else if( x > root->data )
        root->right = delete_node(root->right, x);

    // if key is same as root's key, then This is
    // the node to be deleted
    else
    {
        // node with only one child or no child
        if( (root->left == NULL) || (root->right == NULL) )
        {
            struct node *temp = root->left ? root->left :
                                             root->right;

            // No child case
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
             *root = *temp; // Copy the contents of
                            // the non-empty child
            free(temp);
        }
        else
        {
            // node with two children: Get the inorder
            // successor (smallest in the right subtree)
            struct node* temp = minValueNode(root->right);

            // Copy the inorder successor's data to this node
            root->data = temp->data;

            // Delete the inorder successor
            root->right = delete_node(root->right, temp->data);
        }
    }
    return root;
}

int count_node(struct node *root)
{

    if(root==NULL)
    {
        return 0;
    }
    else
     return count_node(root->left)+count_node(root->right)+1;

}

int count_extnode(struct node *root)
{

   if(root == NULL)
   {
       return 0;
   }
   else if((root->left==NULL) && (root->right==NULL))
      return 1;
   else
        return count_extnode(root->left)+count_extnode(root->right);

}

int count_intnode(struct node *root)
{

   if(root == NULL)
   {
       return 0;
   }
   else if((root->left==NULL) && (root->right==NULL))
      return 0;
   else
        return count_intnode(root->left)+count_intnode(root->right)+1;

}

int height(struct node *root)
{

    int right ,left;
    if(root == NULL)
    {
        return 0;
    }
    else
    {
    right = height(root->right);
    left = height(root->left);
    if(right>left)
        return  right+1;
    else return left+1;
    }

}

void mirror_img(struct node *root)
{

    struct node *temp ;

    if(root == NULL)
        return 0;
    else
    {
        mirror_img(root->left);          //traversing to the second last node
        mirror_img(root->right);
    }

    temp = root->left;               // swapping the left and right node
    root->left = root->right;
    root->right = temp;
}

void delete_tree(struct node *root)
{

    if(root!=NULL)
    {
        delete_tree(root->left);
        delete_tree(root->right);
        printf("\n\nDeleted element is %d",root->data);
        free(root);
    }
}

void display()
{
    int i;
    system("cls");
    while(i!=4)
    {
        printf("\n\n-----------ORDER LIST----------\n");
        printf("\n 1. Inorder Display");
        printf("\n 2. Preorder Display");
        printf("\n 3. Postorder Display");
        printf("\n 4. Back to main menu");
        printf("\n---------------------------------\n");
        printf("\nEnter your choice :");
        scanf("%d",&i);
        switch(i)
        {
        case 1:
            {
            printf("\n-> In order display of tree :\n");

             if(root==NULL)
                {
                    printf("\n||-----TREE IS EMPTY-----||");
                }

            inorder_display(root);
            }
            break;
        case 2:
            {
            printf("\n-> Pre order display of tree :\n");

             if(root==NULL)
                {
                    printf("\n||-----TREE IS EMPTY-----||");
                }

            preorder_display(root);
            }
            break;
        case 3:
            {
            printf("\n-> post order display of tree :\n");

            if(root==NULL)
                {
                    printf("\n||-----TREE IS EMPTY-----||");
                }

            postorder_display(root);
            }
            break;
        }
        printf("\n\n----PRESS ANY KEY TO GO TO MENU----");
        getch();
        system("cls");
    }

}
main()
{
    int i;
    while(i!=12)
    {
        printf("\n ********************MAIN MENU****************** \n");
        printf("\n 1. Insert Element");
        printf("\n 2. Display the Tree");
        printf("\n 3. Find the smallest element");
        printf("\n 4. Find the largest element");
        printf("\n 5. Delete an element");
        printf("\n 6. Count the total number of nodes");
        printf("\n 7. Count the total number of external nodes");
        printf("\n 8. Count the total number of internal nodes");
        printf("\n 9. Determine the height of the tree");
        printf("\n 10. Find the mirror image of the tree");
        printf("\n 11. Delete the tree");
        printf("\n 12. Exit");
        printf("\n *********************************************** \n");
        printf("\n\nEnter Your Choice = ");
        scanf("%d",&i);
     switch(i)
     {
        case 1:
            {
                int n=1;
                while(n!=0)
                {
                insert();
                printf("\nwould you wanna to insert another element? (1=Yes/0=No)\n");
                scanf("%d",&n);
                }
            }
                break;
        case 2:
            display();
            break;
        case 3:
            smallest_element();
            break;
        case 4:
            largest_element();
            break;
        case 5:
            {
            int x;
            printf("\nEnter the value :- ");
            scanf("%d",&x);
            delete_node(root,x);
            }
            break;
        case 6:
            printf("\nTotal Number of node is %d .",count_node(root));
            break;
        case 7:
            printf("\nTotal Number of external node is %d .",count_extnode(root));
            break;
        case 8:
            printf("\nTotal Number of internal node is %d .",count_intnode(root));
            break;
        case 9:
            printf("\nHeight of the Tree is %d",height(root));
            break;
        case 10:
            {
            mirror_img(root);
            printf("\n========Mirror image tree is done======\n");
            }
            break;
        case 11:
            delete_tree(root);
            break;
     }
     printf("\n\n------PRESS ANY KEY TO CONTINUE---------");
     getch();
     system("cls");


     }

}
