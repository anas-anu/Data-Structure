#include<stdio.h>
#include<stdlib.h>
void push();
void display();
void pop();

struct node
{	
	struct node *next;
	int data;
};

	struct node *top;
	void main()
	{
		int choice,item;
		do
		{
			printf("\n1.PUSH\n2.DISPLAY\n3.POP\n4.EXIT\nENTER YOUR CHOICE:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:
					printf("Enter the Elements:\n");
					scanf("%d",&item);
					push(item);
					break;
				case 2:
					display();
					break;
				case 3:
					pop();
					break;
				case 4:
					exit(0);
				default:
					printf("Please Enter a Valid Choice: ");
			}
		}
		while(choice!=4);
	}
	void push(int item)
	{
		struct node *ptr=(struct node *)malloc(sizeof(struct node *));
		if(ptr==NULL)
		{
			printf("OVERFLOW");
		}
		else
		{
			ptr->data=item;
			ptr->next=top;
			top=ptr;
			printf("PUSH is Successfull");		
		}
	}
	void display()
	{
		struct node *ptr;
		ptr=top;
		if(ptr==NULL)
		{
			printf("Insuffitient Memory:");
		}
		else
		{
			printf("Elements Are:");
			while(ptr!=NULL)
			{
				printf("%d",ptr->data);
				ptr=ptr->next;
			}
		}
	}
	void pop()
	{
		struct node *ptr;
		if(top==NULL)
		{
			printf("Stack Underflow");
		}
		else
		{
			int item; 
			item=top->data;
			ptr=top;
			top=top->next;
			printf("Item poped Successfully :%d",ptr->data);
		}
	}

		

	
	

