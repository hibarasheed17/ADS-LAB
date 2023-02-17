#include<stdio.h>
#include<stdlib.h>

//double linked list

struct Node
{
	struct Node *Llink;
	int data;
	struct Node *Rlink;
};

int key,loc,choice;

struct Node *header=NULL;

void insert_at_front(int key)
{
	struct Node *newnode;
	newnode=(struct Node*)malloc(sizeof(struct Node));
	if (newnode==NULL)
	{
		printf("\nMemory Is Full.!");
	}
	if(header==NULL)
	{
		newnode->data=key;
		newnode->Rlink=NULL;
		header=newnode;
		newnode->Llink=header;
	}
	else
	{
		newnode->data=key;
		newnode->Rlink=header;
		header->Llink=newnode; //corrected
		header=newnode;
		newnode->Llink=header;
		
	}
}

void insert_at_any(int key,int loc)
{
	struct Node *newnode;
	struct Node *ptr;
	newnode=(struct Node*)malloc(sizeof(struct Node));
	if (newnode==NULL)
	{
		printf("\nMemory Is Full.!");
	}
	else
	{
		ptr=header;
		while((ptr!=NULL)&&(ptr->data!=loc))
		{
			ptr=ptr->Rlink;
		}
		if(ptr==NULL)
		{
			printf("Key Not Found.!");
		}
		else
		{
			
			newnode->Llink=ptr;
			newnode->data=key;
			newnode->Rlink=ptr->Rlink;
			ptr->Rlink=newnode;
		}
		
	}	
}

void insert_at_end(int key)
{
	struct Node *newnode;
	struct Node *ptr;
	newnode=(struct Node*)malloc(sizeof(struct Node));
	if (newnode==NULL)
	{
		printf("\nMemory Is Full.!");
	}
	else
	{
		newnode->data=key;
		newnode->Rlink=NULL;
		ptr=header;
		while(ptr->Rlink!=NULL)
		{
			ptr=ptr->Rlink;
		}
		ptr->Rlink=newnode;
		newnode->Llink=ptr;
	}
}

void delete_at_front()
{
	struct Node *ptr;
	ptr=header;
	if (ptr==NULL)
	{
		printf("No Node to delete");
	}
	else
	{
		header=ptr->Rlink;
		printf("The Deleted Item is : %d \n",ptr->data);
		free(ptr);
	}
	
}

int delete_at_any(int key) //corrected
{
	struct Node *ptr;
	ptr=header;
	while(ptr!=NULL)
	{
		if(ptr->data==key)
		{
			if (ptr==header)
			{
				printf("The Deleted Item is : %d \n",ptr->data);
				if(ptr->Rlink!=NULL)
				{
					header=ptr->Rlink;
					header->Llink=NULL;
					free(ptr);
					return 0;
				}
				else
				{
					header=NULL;
					free(ptr);
					return 0;
				}
			}
			if(ptr->Rlink==NULL)
			{
				printf("The Deleted Item is : %d \n",ptr->data);
				if(ptr->Llink!=NULL)
				{
					ptr->Llink->Rlink=NULL;
					free(ptr);
					return 0;
				}
				else
				{
					header=NULL;
					free(ptr);
					return 0;
				}
			}
			ptr->Rlink->Llink=ptr->Llink;
			ptr->Llink->Rlink=ptr->Rlink;
			printf("The Deleted Item is : %d \n",ptr->data);
			free(ptr);
			return 0;
			
		}
		else
		{
			ptr=ptr->Rlink;
		}
	}
	if(ptr==NULL)
	{
		printf("No Key Found.!");
	}
}

void delete_at_end()
{
	struct Node *ptr;
	struct Node *ptr1;
	ptr=header;
	if (ptr==NULL)
	{
		printf("No Node to delete");
	}
	else
	{
		while(ptr->Rlink!=NULL)
		{
			ptr=ptr->Rlink;
		}
		ptr1=ptr->Llink;
		printf("The Deleted Item is : %d \n",ptr->data);
		free(ptr);
		ptr1->Rlink=NULL;
		
	}	
}

void display()
{
	struct Node *ptr;
	ptr=header;
	if(ptr==NULL)
	{
		printf("Linked List Is Empty");
	}
	else
	{
		printf("The Linked List Elements Are : \n");
		while(ptr!=NULL)
		{
			printf("%d\n",ptr->data);
			ptr=ptr->Rlink;
		}
		printf("NULL \n");
	}
}

int search (int key)
{
	struct Node *ptr;
	ptr=header;
	int location=1;
	while(ptr!=NULL)
	{
		if (ptr->data==key)
		{
			printf("\n key found at location : %d \n",location);
			return 0;
		}
		else
		{
			ptr=ptr->Rlink;
			location=location+1;
		}		
	}
	if(ptr==NULL)
	{
		printf("\n key Not Found.! \n");
	}	
}


int main()
{
printf("\n[Double Linked List]\n");
do
{
printf("\n1.Insert At Front.\n");
printf("2.Insert At Any.\n");
printf("3.Insert At End.\n");
printf("4.Delete At Front.\n");
printf("5.Delete At Any.\n");
printf("6.Delete At End.\n");
printf("7.Display.\n");
printf("8.Search.\n");
printf("9.exit.\n");
printf("\n Enter Your Choice : ");
scanf("%d",&choice);
switch(choice) 
{
 case 1 :
  {
   printf("Enter a value to insert at front : ");
   scanf("%d",&key);
   insert_at_front(key);
   break; 
  }
 case 2 :
  {
   printf("Enter a value to insert : ");
   scanf("%d",&key);
   printf("Enter the location to insert : ");
   scanf("%d",&loc);
   insert_at_any(key,loc);
   break; 
  }
 case 3 :
  {
   printf("Enter a value to insert at end : ");
   scanf("%d",&key);
   insert_at_end(key);
   break; 
  }
  case 4 :
  {
   delete_at_front();
   break; 
  }
  case 5 :
  {
   printf("Enter a value to delete at any : ");
   scanf("%d",&key);
   delete_at_any(key);
   break; 
  }
  case 6 :
  {
   delete_at_end();
   break; 
  }
  case 7 :
  {
   display();
   break; 
  }
  case 8 :
  {
   printf("Enter a value to search : ");
   scanf("%d",&key);
   search(key);
   break; 
  }
 case 9 :
  {
   printf("Exit");
   break; 
  }
}
}
while(choice!=9);
return 0;
}
