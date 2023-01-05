#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *next;
    int data;
    struct node *pre;
};

void inFirst();
void inLast();
struct node *head;

void inFirst()
{  
    int value;
   struct node *ptr=(struct node *)malloc(sizeof(struct node));;  
    printf("\nEnter Item:");  
    scanf("%d",&value);      
   if(ptr == NULL)  
   {  
       printf("\nInsuffitient Memmory");  
   }  
   else  
   {  
    if(head==NULL)  
    {  
        ptr->next = NULL;  
        ptr->pre=NULL;  
        ptr->data=value;  
        head=ptr;  
    }  
    else   
    {  
        ptr->data=value;  
        ptr->pre=NULL;  
        ptr->next = head;  
        head->pre=ptr;  
        head=ptr;  
   }  
   printf("\nNode inserted\n");  
}  
     
}
void inLast()
{
    int value;
    struct node *ptr;
    struct node *new=(struct node *)malloc(sizeof(struct node));
    printf("Enter Value:\n");
    scanf("%d",&value);
    new->data=value;
    new->pre=NULL;
    new->next=NULL;
    if(head==NULL)
    {
        head=new;
    }
    else
    {
        ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=new;
        new->pre=ptr;
    }
}
void inAfterspecific(int value,int e)
{
    struct node *ptr;
    struct node *new=(struct node *)malloc(sizeof(struct node));
    new->data=value;
    new->pre=NULL;
    new->next=NULL;
    if(head==NULL)
    {
        head=new;
    }
    else
    {
        ptr=head;
        while(ptr->data!=e)
        {
            ptr=ptr->next;
        }
        new->next=ptr->next;
        new->pre=ptr;
        ptr->next->pre=new;
        ptr->next=new;
    }
}

void delFirst()
{
    struct node *ptr;
    if(head==NULL)
    {
        printf("UNDERFLOW\n");
    }
    else
    {
        ptr=head;
        head=head->next;
        ptr->next=NULL;
        head->pre=NULL;
        free(ptr);
    }
}

void delLast()
{
    struct node *ptr;
    if(head==NULL)
    {
        printf("UNDERFLOW");
    }
    else
    {
        ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->pre->next=NULL;
        ptr->pre=NULL;
        free(ptr);
    }
}

void delBetween(int e)
{
    struct node *ptr;
    if(head==NULL)
    {
        printf("UNDERFLOW");
    }
    else
    {
        ptr=head;
        while(ptr->data!=e)
        {
            ptr=ptr->next;
        }
        ptr->pre->next=ptr->next;
        ptr->next->pre=ptr->pre;
        ptr->next=NULL;
        ptr->pre=NULL;
        free(ptr);
    }
}

void display()
{
    struct node *ptr;
    if(head==NULL)
    {
        printf("Empty List \n");
    }
    else
    {
        ptr=head;
        printf("Elements Are:\n");
        while(ptr!=NULL)
        {
            printf("%d",ptr->data);
            ptr=ptr->next;
        }   
        printf("\n");
    }
}

void main()
{
    int value,e,choice;
    printf("1.INSERT BEGINNING\n2.INSERT LAST\n3.INSERT BETWEEN\n4.DELETE FIRST\n5.DELETE LAST\n6.DELETE BETWEEN\n7.DISPLAY\n8.EXIT\nEnter A Choice\n");
    scanf("%d",&choice);
    do
    {
        switch(choice)
        {
            case 1:
            inFirst(value);
            break;
            case 2:
            inLast(e);
            break;
            case 3:
            printf("Enter Element to After Insert:\n");
            scanf("%d",&e);
            printf("Enter Value:\n");
            scanf("%d",&value);
            inAfterspecific(value,e);
            break;
            case 4:
            delFirst();
            break;
            case 5:
            printf("Enter Element to After Insert:\n");
            scanf("%d",&e);
            delBetween(e);
            break;
            case 6:
            delLast();
            break;
            case 7:
            display();
            case 8:
            exit(0);
            default:
            printf("Please Enter a Valid option \n");
        }
    }
    while(choice!=8);
}

