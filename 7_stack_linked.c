#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *link;
};

struct Node *top=NULL;

int choice , key ,counter=0;

void push(int key)
{
	struct Node *newnode;
	newnode=(struct Node*)malloc(sizeof(struct Node));
	if(newnode==NULL)
	{
		printf("\nMemory is Full.!\n");
	}
	if(counter==5)
	{
		printf("The Stack Is Full.!");
	}
	else
	{
		if(top==NULL)
		{
			newnode->data=key;
			newnode->link=NULL;
			top=newnode;
			counter=counter+1;
		}
		else
		{
			newnode->data=key;
			newnode->link=top;
			top=newnode;
			counter=counter+1;
		}
	}
}

void pop()
{
	struct Node *ptr;
	if(top==NULL)
	{
		printf("\nStack is Empty.!\n");
	}
	else
	{
		if(top->link==NULL)
		{
			top=NULL;
			counter=counter-1;
		}
		else
		{
			ptr=top;
			top=top->link;
			printf("\nThe POPED Element is : %d \n",ptr->data);
			free(ptr);
			counter=counter-1;
		}
	}
}

int search(int key)
{
	int loc=1;
	struct Node *ptr;
	ptr=top;
	if(ptr==NULL)
	{
		printf("\nThe Stack is Empty.!\n");
		return 0;
	}
	if(ptr->data==key)
	{
		printf("\nThe %d Found on Location : %d \n",key,loc);
	}
	else
	{
		while((ptr!=NULL)&&(ptr->data!=key))
		{
			ptr=ptr->link;
			loc=loc+1;
		}
		if(ptr==NULL)
		{
			printf("\nNo Key Found.!\n");
			return 0;
		}
		if(ptr->data==key)
		{
			printf("\nThe %d Found at the Location : %d \n",key,loc);
		}
	}
}

void display()
{
	struct Node *ptr;
	ptr=top;
	if(ptr==NULL)
	{
		printf("\nThe Stack is Empty.!\n");
	}
	else
	{
		printf("\nThe Stack Elements Are : ");
		while(ptr!=NULL)
		{
			printf("\n%d",ptr->data);
			ptr=ptr->link;
		}
		printf("\nNULL\n");
	}
	
}

int main()
{
	do
	{
		printf("\n1.push.");
		printf("\n2.pop.");
		printf("\n3.search.");
		printf("\n4.display.");
		printf("\n5.exit.");
		printf("\nEnter Your Choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 :
			{
				printf("\nEnter The Element To PUSH : ");
				scanf("%d",&key);
				push(key);
				break;
			}
			case 2 :
			{
				pop();
				break;
			}
			case 3 :
			{
				printf("\nEnter The Element To SEARCH : ");
				scanf("%d",&key);
				search(key);
				break;
			}
			case 4 :
			{
				display();
				break;
			}
			case 5 :
			{
				printf("exit");
			}
		}
	}
	while(choice!=5);
	return 0;
}
