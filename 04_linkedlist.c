#include<stdio.h>
#include<stdlib.h> //updated as swich case


struct Node
{
  int data;
  struct Node *link;
};
int key,loc,choice;

struct Node *header=NULL;

void insert_at_front(int key)
{
	struct Node *newnode2;
	newnode2 = (struct Node*)malloc(sizeof(struct Node));
	if(newnode2==NULL)
	{
		printf("\n memmory full");
	}
	else
	{
		newnode2->data=key;
		newnode2->link=header;
		header=newnode2;
	}

}

void insert_at_any(int key, int loc)
{
	struct Node *newnode;
	newnode=(struct Node*)malloc(sizeof(struct Node));
	if(newnode==NULL)
	{
		printf("\n memmory full");
	}
	else
	{
		struct Node *ptr;
		ptr=header;
		while((ptr!=NULL) && (ptr->data!=loc))
		{
			ptr=ptr->link;
		}
		if(ptr==NULL)
		{
			printf("key not found.!");
		}
		else
		{
			newnode->data=key;
			newnode->link=ptr->link;
			ptr->link=newnode;
		}
	}
	
}



void insert_at_end(int key)
{
	struct Node *newnode;
	newnode = (struct Node*)malloc(sizeof(struct Node));
	if (header == NULL)
	{
		
		newnode->data = key;
		newnode->link=NULL;
		header = newnode;
	}
	else
	{
		struct Node *ptr;
		ptr=header;
		while(ptr->link != NULL)
		{
			ptr=ptr->link;
		}

		newnode->data=key;
		newnode->link=NULL;
		ptr->link=newnode;
	}
}

int delete_at_front()
{
	struct Node *ptr;
	ptr=header;
	if (ptr==NULL)
	{
		printf("No Node To Delete");
	}
	else
	{
		header=ptr->link;
		printf("The Deleted Item is : %d \n",ptr->data);
		free(ptr);
	}
	return 0;
}

int delete_at_any(int key)
{
	struct Node *ptr;
	struct Node *ptr1;
	ptr=header->link;
	ptr1=header;
	if (ptr1->data==key)
	{
		printf("The Deleted Item is : %d \n",ptr1->data);
		free(ptr1);
		header=ptr;
		return 0;
	}
	while(ptr!=NULL)
	{
		if(ptr->data==key)
		{
			ptr1->link=ptr->link;
			printf("The Deleted Item is : %d \n",ptr->data);
			free(ptr);
			return 0;
		}
		else
		{
			ptr1=ptr;
			ptr=ptr->link;
		}
	}
	if (ptr==NULL)
	{
		printf("No Key Found");
	}
}


void delete_at_end()
{
	struct Node *ptr;
	struct Node *ptr1;
	ptr=header;
	if(ptr==NULL)
	{
		printf("No Node To Delete.!");
	}
	else
	{
		while(ptr->link!=NULL)
		{
			ptr1=ptr;
			ptr=ptr->link;
		}
		ptr1->link=NULL;
		printf("The Deleted Item is : %d \n",ptr->data);
		free(ptr);
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
			ptr=ptr->link;
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
			ptr=ptr->link;
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
switch(choice) //switch case updated
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
