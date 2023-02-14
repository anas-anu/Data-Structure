#include<stdio.h>
#include<stdlib.h>
struct node 
{
    struct node *next;
    int data;
};
struct node *head,*ptr;

void insBeg(int);
void insLast(int);
void insBet(int);
void delBeg();
void delLast();
void delBet(int);
void search(int);
void display();

void main()
{
    int op,ele,key,val;
    do
    {
        printf("\n1.Insert Beginning\n2.Insert Last\n3.Insert Between\n4.Delete Beginning\n5.Delete Last\n6.Delete Between\n7.Search\n8.Display\n9.Exit\nChoose An Option:\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                printf("Enter Element To Insert:\n");
                scanf("%d",&ele);
                insBeg(ele);
                break;
            case 2:
                printf("Enter Element To Insert:\n");
                scanf("%d",&ele);
                insLast(ele);
                break;
            case 3:
                printf("Enter Element To Insert:\n");
                scanf("%d",&ele);
                insBet(ele);
                break;
            case 4:
                delBeg();
                break;
            case 5:
                delLast();
                break;
            case 6:
                printf("Enter Element To Delete:\n");
                scanf("%d",&key);
                delBet(key);
                break;
            case 7:
                printf("Enter Element To Search:\n");
                scanf("%d",&val);
                search(val);
                break;
            case 8:
                printf("Elements Are:");
                display();
                break;
            case 9:
                exit(0);
        }

    }
    while(op!=9);
}
void insBeg(int ele)
{
    struct node *new;
    new=(struct node *)malloc(sizeof(struct node));
    if(new==NULL)
    {
        printf("OVERFLOW");
    }
    else
    {
        if(head==NULL)
        {
            head=new;
            new->data=ele;
            new->next=NULL;
        }
        else
        {
            ptr=head;
            head=new;
            new->data=ele;
            new->next=ptr;
        }
        printf("Insertion Successfull");
    }
}
void insLast(int ele)
{

}
void insBet(int ele)
{

}
void delBeg()
{

}
void delLast()
{

}
void delBet(int key)
{

}
void search(int val)
{

}
void display()
{

}