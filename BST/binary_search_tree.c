#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root,*ptr,*parent;
struct node *create(struct node *,int);
void insert();
void createNew();
void inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);
void search(struct node *,int);
int getinordersuccessor(struct node *);
struct node *delete(struct node *,int);

int main()
{
    struct node *root=NULL;
    int ch,item,n,i,key,value;

    do
    {
        printf ("\n1.Create BST\n2.Inorder Traversal\n3.Preorder Traversal\n4.Postorder Traversal\n5.Insert\n6.Search\n7.Delete\n8.Exit\nEnter A Choice:\n");
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
            printf("Enter the Element To Search:\n");
            scanf("%d",&key);
            search(root,key);
            break;
        case 7:
            printf("Enter the Element To Delete:\n");
            scanf("%d",&value);
            delete(root,value);
            break;
        case 8:
            exit(0);
        default:
            printf("Please Enter a Valid Choice \n");
            break;
        }
    }  
    while(ch!=8);
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

void search(struct node *root,int key)
{
    if(root==NULL)
    {
        printf("Value Does not Exist");
    }
    else if(key==root->data)
    {
        printf("Value Found");
    }
    else if (key<root->data)
    {
        search(root->left,key);
    }
    else
    {
        search(root->right,key);
    }
}
void delete(struct node *root)
{
	if(root==NULL)
	{
		printf("Empty Tree\n");
		return;
	}
	else
	{
		parent=NULL;
		ptr=root;
	}
	while(ptr!=NULL)
	{
		if(ptr->data==value)
		{
			break;
		}
		parent=ptr;
		else if(value>ptr->data)
		{
			ptr=ptr->right;
		}
		else
		{
			ptr=ptr->left;
		}
	}
	if(ptr==NULL)
	{
		printf("Item Not Present");
	}
	else
	{
		if(ptr->right==NULL && ptr->left==NULL)
		{
			if(parent==NULL)
			{
				root=NULL;
			}
			else if(parent->right==ptr)
			{
				parent->right=NULL;
			}
			else
			{
				parent->left=NULL;
			}
			printf("Element Deleted\n");
			free(ptr);
		}
		else if(ptr->right!=NULL && ptr->left!=NULL)
		{
			p=ptr->right;
			while(p->left!=NULL)
			{
				p=p->left;
			}
			dat=p->data;
			delete(p->data);
			ptr->data=dat;
		}
		else
		{
			if(parent==NULL)
			{
				if(ptr->right==NULL)
				{
					root=ptr->left;
				}
				else
				{
					root=ptr->right;
				}
			}	
			else
			{
				if(parent->right==NULL);
				if(ptr->right==NULL);
			}
		}
	}
}


