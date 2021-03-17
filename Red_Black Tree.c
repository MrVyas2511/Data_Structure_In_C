 #include<stdlib.h>
 #include<stdio.h>

struct node
{
    int color;
    struct node *left;
    struct node *right;
    struct node  *parent;
    int data;
};
struct node *root;
struct node *create_node(int x)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->color = 0;
    newnode->parent = NULL;
    return newnode;
}
struct node *search(struct node *root,int x)
{
    struct  node *temp = root;
    struct node *temp1;
     while(temp!=NULL)
     {
            temp1 = temp;
    if(x > temp->data)
        temp = temp->right;
    else
        temp = temp->left;
     }
     return temp1;

}
struct node *grand_parent(struct node *n)
{
        if((n!=NULL)&&(n->parent!=NULL))
            return n->parent->parent;
        else
            return NULL;
}
struct node *uncle_of(struct node *n)
{
    struct node *gp;
    gp = grand_parent(n);
    if(gp == NULL)
        return NULL;
    if(n->parent == gp->left)
        return gp->right;
    else
        return gp->left;
}

struct node *rotate_left(struct node *root , struct node *x)
{
    //y stored pointer of right child of x
    struct node *y = x->right;

    //store y's left subtree's pointer as x's right child
    x->right = y->left;

    //update parent pointer of x's right
    if (x->right != NULL)
        x->right->parent = x;

    //update y's parent pointer
    y->parent = x->parent;
     // if x's parent is null make y as root of tree
    if (x->parent == NULL  )
        root = y;

    // store y at the place of x
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    // make x as left child of y
    y->left = x;

    //update parent pointer of x
    x->parent = y;
    return root;
}

struct node *rotate_right(struct node *root,struct node *y)
{
    struct node *x = y->left ;
     y->left = x->right;
    if (x->right != NULL)
        x->right->parent = y;
    x->parent =y->parent;
    if (x->parent == NULL)
        root = y;
    else if (y == y->parent->left)
        y->parent->left = x;
    else y->parent->right = x;
    x->right = y;
    y->parent = x;
    x->parent = y;
    return root;
}
struct node *fixRR(struct node *root, struct node *n)
{
    if(n->parent == NULL)
        n->color = 1;
    else
    {
        if(n->parent->color == 1)
            n->parent->color =1;
        else
        {
           struct node *uncle,*gp;
           uncle = uncle_of(n);
           gp = grand_parent(n);

           if((uncle!=NULL)&&(uncle->color == 0))
           {
               n->parent->color = 1;
               uncle->color = 1;
               gp->color = 0;
               fixRR(root , gp);
           }
           else
           {
                if((n==n->parent->right)&&(n->parent == gp->left))
               {

                   root =rotate_left(root,n->parent);
                   n = n->left;
               }
               else if((n==n->parent->left)&&(n->parent == gp->right))
               {
                   root= rotate_right(root,n->parent);
                    n=n->right;
               }
               if((n==n->parent->left)&&(n->parent == gp->left))
               {
                   root= rotate_right(root,gp);
                    n->parent->color = 1;
                    gp->color = 0;
               }
               else if((n==n->parent->right)&&(n->parent == gp->right))
               {
                  root=   rotate_left(root,gp);
                     n->parent->color = 1;
                    gp->color = 0;
               }

           }
        }
    }
    return root;
    // display(root);
}
struct node *insert(struct node *root,int x)
{
    struct node *newnode = create_node(x);
    struct node *temp ;
    if(root == NULL)
    {
        root = newnode;
        root->color = 1;
    }
    else
    {

        temp = search(root,x);
        if(temp->data == x)
        {
            printf("--Duplicate data found");
            return root;
        }
        newnode->parent = temp;
        if(x>temp->data)
        temp->right = newnode;
        else
            temp->left = newnode;
    }

   root =  fixRR(root,newnode);

     return root;
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
    struct node *temp,*child;
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
            child = root;
            temp = root->left ? root->left :root->right;

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
void display(struct node *root)
{
    if(root!=NULL)
    {
        display(root->left);
        printf("%d - %d || ",root->data,root->color );
        if(root->parent==NULL)
            printf("0\n");
        else
            printf("%d\n",root->parent->data);
        display(root->right);
    }
}

main()
{

    root = insert(root,16);
    root = insert(root,9);
    root = insert(root,27);
    root = insert(root,7);
    root = insert(root,11);
    root = insert(root,8);
    root = insert(root,21);
    root = insert(root,45);
    root = insert(root,36);
    root = insert(root,63);
    root = insert(root,55);
    root = insert(root,65);

    root = delete_node(root,45);
    display(root);
}
