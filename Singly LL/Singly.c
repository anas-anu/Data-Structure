#include<stdio.h>
#include<stdlib.h>
	struct node 
	{
	    int data;
	    struct node *next;
	};
	struct node *head,*ptr;
	
	void insBeg(int);
	void insLast(int);
	void insBet(int,int);
	void delBeg();
	void delLast();
	void delBet(int);
	void search(int);
	void display();
	
	void main()
	{
	    int op,ele,key,val,ne;
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
	                printf("Enter Element to Insert After:\n");
	                scanf("%d",&ne);
	                insBet(ele,ne);
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
	        printf("\nInsuffitient Memory\n");
	    }
	    else
	    {
	        if(head==NULL)
	        {
	            new->next=NULL;
	            new->data=ele;
	            head=new;
	        }
	        else
	        {
	            ptr=head;
	            new->data=ele;
	            new->next=ptr;
	            head=new;
	        }
	        printf("Insertion Successfull");
	    }
	}
	void insLast(int ele)
	{
	    struct node *new;
	    new=(struct node *)malloc(sizeof(struct node));
	    if(new==NULL)
	    {
	        printf("\nInsuffitient Memory\n");
	    }
	    else
	    {
	        if(head==NULL)
	        {
	            new->next=NULL;
	            new->data=ele;
	            head=new;
	        }
	        else
	        {
	            ptr=head;
	            while(ptr->next!=NULL)
	            {
	                ptr=ptr->next;
	            }
	            new->data=ele;
	            new->next=NULL;
	            ptr->next=new;
	        }
	        printf("Insertion Successfull");
	    }
	}
	void insBet(int ele,int ne)
	{
	    struct node *new;
	    new=(struct node *)malloc(sizeof(struct node));
	    if(new==NULL)
	    {
	        printf("\nInsuffitient Memory\n");
	    }
	    else
	    {
	        if(head==NULL)
	        {
	            new->next=NULL;
	            new->data=ele;
	            head=new;
	        }
	        else
	        {
	            ptr=head;
	            while(ptr->data!=ne)
	            {
	                ptr=ptr->next;
	            }
	            new->data=ele;
	            new->next=ptr->next;
	            ptr->next=new;
	        }
	        printf("Insertion Successfull");
	    }
	}
	void delBeg()
	{
	    if(head==NULL)
	    {
	        printf("\nUNDERFLOW\n");
	    }
	    else if(head->next==NULL)
	    {
	        head=NULL;
	        free(head);
	    }
	    else
	    {
	        ptr=head->next;
	        head=ptr;
	    }
	}
	void delLast()
	{
	    if(head==NULL)
	    {
	        printf("\nUNDERFLOW\n");
	    }
	    else if(head->next==NULL)
	    {
	        head=NULL;
	        free(head);
	    }
	    else
	    {
	        ptr=head;
	        while(ptr->next->next!=NULL)
	        {
	            ptr=ptr->next;
	        }
	        ptr->next=NULL;
	        free(ptr->next);
	    }
	}
	void delBet(int key)
	{
	    struct node *temp;
	    if(head==NULL)
	    {
	        printf("\nUNDERFLOW\n");
	    }
	    else if(head->next==NULL)
	    {
	        head=NULL;
	        free(head);
	    }
	    else
	    {
	        ptr=head;
	        while(ptr->next->data!=key)
	        {
	            ptr=ptr->next;
	        }
			ptr->next=ptr->next->next;
	    }
	}
	void search(int val)
	{
		struct node *ptr;
		ptr=head;
	    if(head==NULL)
		{
			printf("\nEmpty List\n");		
		}
		else
		{
			while(ptr!=NULL)
			{
				if(ptr->data==val)
				{
					printf("\nItem Found\n");
				}	
				else
				{
				}
				ptr=ptr->next;
			}
		}
	}
	void display()
	{
	    if(head==NULL)
	    {
	        printf("\nEmpty List\n");
	    }
	    else
	    {
	        ptr=head;
	        printf("Elements Are:\n");
	        while(ptr!=NULL)
	        {
	            printf("%d\n",ptr->data);
	            ptr=ptr->next;
	        }
	    }
	}
