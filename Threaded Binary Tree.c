#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
 struct node
 {
    int lflag;
   struct node *left;
   int data;
   struct node *right;
    int rflag;
 };
 struct node *root = NULL;
 struct node *create_node()
 {
        struct node *newptr = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data");
        scanf("%d",newptr->data);
        newptr->left = newptr->right = NULL;
        newptr->lflag = newptr->rflag = 1;
        return newptr;
 }
 struct node *inorder_succesor(struct node *ptr,struct node *root)
 {
     if(root==NULL)
        return ;
    do
    {
        inorder_succesor( ptr, root->left);
        inorder_succesor(  ptr,  root->right);
    }while(ptr->data!=root->data);
    return root;
 }
  struct node *inorder_predecsor(struct node *ptr,struct node *root)
 {
     struct node *temp ;
     if(root==NULL)
        return ;
   while(ptr!=root)
    {
        temp = root;
        inorder_succesor(ptr,root->left);
        inorder_succesor(ptr,root->right);
    }
    return root;
 }
 struct node insert(struct node *ptr,struct node *root)
 {
     if(root == NULL)
     {
         root = ptr;
         ptr->right = inorder_succesor(ptr,root);
         ptr->left  = inorder_predecsor(ptr,root);

     }
     else if(ptr->data > root->data)
     {
         insert(ptr,root->right);
     }
     else
        insert(ptr,root->left);
 }
 struct node add_node()
 {
     struct node *temp;
    temp =  create_node();
     insert(temp,root);
     printf("\nInsertion done ");
 }
 struct node* leftmost(struct node *n)
{
    if (n == NULL)
       return NULL;

    while (n->left != NULL)
        n = n->left;

    return n;
}

// C code to do inorder traversal in a threaded binary tree
struct node inorder(struct node *root)
{
    struct node *ptr = leftmost(root);
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);

        // If this node is a thread node, then go to
        // inorder successor
        if (ptr->rflag)
            ptr = ptr->right;
        else // Else go to the leftmost child in right subtree
            ptr = leftmost(ptr->right);
    }
}
main()
{
    add_node();
    add_node();
    add_node();
    add_node();
    add_node();
    add_node();
    inorder(root);

}
