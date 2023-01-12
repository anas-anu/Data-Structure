#include<stdio.h>
#include<stdlib.h>
void insertion();
void deletion();
void display();
int front=-1,rear=-1,item,size=3,a[10];
void main()
{
int opt;
do
{
printf("Enter your option:\n 1.insertion\n 2.deletion\n 3.display\n 4.exit\n");
scanf("%d",&opt);
switch(opt)
{
case 1:insertion();
break;
case 2:deletion();
break;
case 3:display();
break;
case 4:exit(0);
break;
default:printf("invalid entry\n");
}
}while(opt!=4);
}
void insertion()
{
if(front==(rear+1)%size)
{
printf("Queue is full");
}
else
{
printf("Enter the item to be inserted:");
scanf("%d",&item);
if(front==-1 && rear==-1)
{
front=0;
rear=0;
a[rear]=item;
}
else
{
rear=(rear+1)%size;
a[rear]=item;
}
}
}
void deletion()
{
if(front==-1)
{
printf("No elements");
}
else if(front==rear)
{
printf("The element to be deleted is %d",a[front]);
front=rear=-1;
}
else
{
printf("The element to be deleted is %d",a[front]);
front=(front+1)%size;
}
}
void display()
{
int i;
if((front==-1)&&(rear==-1))
{
printf("no elements");
}
else
{ 
printf("Elements are :\n");
if (front<rear)
{
for(i=front;i<=rear;i++)
printf("%d",a[i]);
}
else
{
for(i=front;i<size;i++)
printf("%d",a[i]);
for(i=0;i<=rear;i++)
printf("%d",a[i]);
}
}
}






