#include<stdio.h>
#include<stdlib.h>
void insertion();
void deletion();
void display();
int front=-1,rear=-1,item,size=9,a[10];
void main()
{
int opt;
do
{
printf("\n 1.Insertion\n 2.Deletion\n 3.Display\n 4.Exit\nChoose a Operation:\n");
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
default:printf("\nPlease Choose a Valid Option\n");
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
printf("Enter the item to be Inserted:\n");
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
printf("The Element to be Deleted is:%d",a[front]);
front=rear=-1;
}
else
{
printf("The Element to be Deleted is:\n%d",a[front]);
front=(front+1)%size;
}
}
void display()
{
int i;
if((front==-1)&&(rear==-1))
{
printf("No elements");
}
else
{ 
printf("Elements are :\n");
if (front<rear)
{
for(i=front;i<=rear;i++)
printf("%d \n",a[i]);
}
else
{
for(i=front;i<size;i++)
printf("%d \n",a[i]);
for(i=0;i<=rear;i++)
printf("%d \n",a[i]);
}
}
}






