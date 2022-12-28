#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root,*ptr;
struct node *create(struct node *,int);
void insert();
void createNew();
void inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);

int main()
{
    struct node *root=NULL;
    int ch,item,n,i;

    do
    {
        printf ("\n1.Create BST\n2.Inorder Traversal\n3.Preorder Traversal\n4.Postorder Traversal\n5.Insert\n6.Exit\nEnter A Choice:\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            root=NULL;
            printf("Enter the Number of Nodes:\n");
            scanf("%d",&n);
            for(i=1;i<=n;i++)
            {
                printf("Enter the data of node %d:\n",i);
                scanf("%d",&item);
                root=create(root,item);
            }
            printf("BST Created Successfully\n");
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            preorder(root);
            break;
        case 4:
            postorder(root);
            break;
        case 5:
            insert(root);
            break;
        case 6:
            exit(0);
        default:
            printf("Please Enter a Valid Choice \n");
            break;
        }
    }  
    while(ch!=6);
}   
struct node *create(struct node *root,int item)
{
    struct node *ptr;
    struct node *new=(struct node *)malloc(sizeof(struct node));
    if(root==NULL)
    {
        root=new;
        root->left=root->right=NULL;
        root->data=item;
        return root;
    }
    else
    {
        ptr=root;
        if(item<ptr->data)
        {
            ptr->left=create(ptr->left,item);
        }
        else if(item>ptr->data)
        {
            ptr->right=create(ptr->right,item);
        }
        else
        {
            printf("Item Already Excist \n");
        }
        return(ptr);
    }
}
void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }

}
void preorder(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
    
}
void postorder(struct node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);
    }
}
void insert(struct node *root)
{
    int value;
    struct node *new,*temp,*ptr;
    new=(struct node *)malloc(sizeof(struct node));
    temp=(struct node *)malloc(sizeof(struct node));
    printf("Enter A Value to insert:\n");
    scanf("%d",&value);
    if(new==NULL)
    {
        printf("Insuffitient Memmory");
    }
    else
    {
        new->right=NULL;
        new->left=NULL;
        new->data=value;
        if(root==NULL)
        {
            root=new;
        }
        else
        {
            ptr=root;
            while(ptr!=NULL)
            {
                if(value==ptr->data)
                {
                    printf("Value Already Exist\n");
                }
                else if(value>ptr->data)
                {
                    temp=ptr;
                    ptr=ptr->right;
                }
                else
                {
                    temp=ptr;
                    ptr=ptr->left;
                }
            }
            if(ptr==NULL)
            {
                if(value>temp->data)
                {
                    temp->right=new;
                }
                else
                {
                    temp->left=new;
                }
            }
        }
    }
}


