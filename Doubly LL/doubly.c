#include<stdio.h>
#include<stdlib.h>
void begins();
void lastins();
void betweenins();
void begdel();
void lastdel();
void betweendel();
void display();
void search();

struct node
{
	struct node *pre;
	int data;
	struct node *next;
};
	struct node *head;
	void main()
	{
		int choice;
		do
		{
			printf("\n1.INSERT BEGINNING\n2.INSERT LAST\n3.INSERT SPECIFIED\n4.DELETE BEGINNING\n5.DELETE LAST\n6.DELETE SPECIFIED\n7.DISPLAY\n8.SEARCH\n9.EXIT\nENTER YOUR CHOICE:\n");
			scanf("%d",&choice);

			switch(choice)
			{
				case 1:
				begins();
				break;
				case 2:
				lastins();
				break;
				case 3:
				betweenins();
				break;
				case 4:
				begdel();
				break;
				case 5:
				lastdel();
				break;
				case 6:
				betweendel();
				break;
				case 7:
				display();
				break;
				case 8:
				search();
				break;
				case 9:
				exit(0);
				default:
				printf("Please Enter a valid choice:");
			}
		}
		while(choice!=10);
	}
	void begins()
	{
		struct node *new=(struct node *)malloc(sizeof(struct node *));
		int item;
		
		if(new == NULL)
		{
			printf("\nOVERFLOW\n");
		}
		else
		{
			printf("Enter Item:\n");
			scanf("%d",&item);
			if(head==NULL)
			{
				new->next=NULL;
				new->pre==NULL;
				new->data=item;
				head=new;
			}
			else
			{
				new->data=item;
				new->pre==NULL;
				new->next=head;
				head=new;
				printf("\nNode Inserted Successfullt\n");			
			}
		}
	}	
	void lastins()
	{
		struct node *ptr;
		struct node *new;
		int item;
		
		if(new == NULL)
		{
			printf("\nOVERFLOW\n");
		}
		else
		{
			new=(struct node *)malloc(sizeof(struct node *));
			printf("Enter Item:\n");
			scanf("%d",&item);
			new->data=item;
			if(head==NULL)
			{
				new->next=NULL;
				new->pre=NULL;
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
				new->next=NULL;		
			}
			printf("\nNode Inserted Successfullt\n");
		}
	}

	void betweenins()
	{
		struct node *new,*ptr;
		int item,loc,i;
		new=(struct node *)malloc(sizeof(struct node *));
		
		if(new == NULL)
		{
			printf("\nOVERFLOW\n");
		}
		else
		{
			ptr=head;
			printf("Enter the Location:\n");
			scanf("%d",&loc);
			for(i=0;i<loc;i++)
			{
				ptr=ptr->next;
				if(ptr==NULL)
				{
					printf("There Are less than %d elements",loc);
					return;
				}
			}
			printf("Enter Item:\n");
			scanf("%d",&item);
			
			new->data=item;
			new->next=ptr->next;
			new->pre=ptr;
			ptr->next=new;
			ptr->next->pre=new;
			printf("\nNode Inserted Successfullt\n");
		}
	}
	void begdel()
	{
		struct node *ptr;
		
		if(head == NULL)
		{
			printf("\nUNDERFLOW\n");
		}
		else if(head->next==NULL)
		{
			head=NULL;
			free(head);
			printf("\nNode Deleted Successfuly\n");
		}
		else
		{
			ptr=head;
			head=head->next;
			head->pre=NULL;
			free(ptr);	
			printf("\nNode Deleted Successfuly\n");	
		}
	}
	void lastdel()
	{
		struct node *ptr,*last;
		
		if(head == NULL)
		{
			printf("\nUNDERFLOW\n");
		}
		else if(head->next==NULL)
		{
			head=NULL;
			free(head);
			printf("\nNode Deleted Successfuly\n");
		}
		else
		{
			ptr=head;
			while(ptr->next->next!=NULL)
			{
				ptr=ptr->next;
			}
			last=ptr->next;
			ptr->next=NULL;
			free(last);	
			printf("\nNode Deleted Successfuly\n");	
		}
	}
	void betweendel()
	{
		struct node *ptr,*temp;
		int val;
		
		printf("Enter the Key After Which the node to be Deleted:\n");
		scanf("%d",&val);
		ptr=head;
		while(ptr->data!=val)
		{
			ptr=ptr->next;
		}
		if(ptr->next==NULL)
		{
			printf("Can NotD elete Node\n");
		}
		else if(ptr->next->next==NULL)
		{
			ptr->next=NULL;
		}
		else
		{
			temp=ptr->next;
			ptr->next=temp->next;
			temp->next->pre=ptr;
			free(temp);
			printf("\nNode Deleted Successfuly\n");
		}
	}	
	void search()
	{
		struct node *ptr;
		int item,i=0;
		ptr=head;
		if(ptr == NULL)
		{
			printf("\nEMPTY LIST\n");
		}
		else
		{
			printf("Enter the Value to Search:\n");
			scanf("%d",&item);
			while(ptr!=NULL)
			{
				if(ptr->data==item)
				{
					printf("\nItem Found At Location:\n%d",i+1);
				}
				i++;
				ptr=ptr->next;
			}
		}
	}
	void display()
	{
		struct node *ptr;
		ptr=head;
        printf("\nElements Are:\n");
		while(ptr!=NULL)
		{
			printf("%d",ptr->data);
			ptr=ptr->next;
		}
	}
		

	
	

