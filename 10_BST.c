#include<stdio.h>
#include<stdlib.h>
struct Node
{
	struct Node *right;
	struct Node *left;
	int key;
	struct Node *parent;
};

struct Node *root=NULL;
int k;

struct Node * tree_search(struct Node *root, int k)
{
	struct Node *ptr;
	ptr=root;
	if ((ptr == NULL) || (k == ptr->key))
	{
		return ptr;
	}
	if (k < ptr->key)
	{
		tree_search(ptr->left, k);
	}
	else
	{
		tree_search(ptr->right, k);
	}
}

struct Node *tree_minimum(struct Node *ptr)
{
	struct Node *x;
	x=ptr;
	if(x!=NULL)
	{
		while (x->left != NULL)
		{
			x = x->left;
		}
	}
	return x;
}

struct Node *tree_maximum(struct Node *ptr)
{
	struct Node *x;
	x=ptr;
	if(x!=NULL)
	{
		while (x->right != NULL)
		{
			x = x->right;
		}
	}
	return x;
}
void tree_insert(int k)
{
	struct Node *parent=NULL;
	struct Node *ptr;
	ptr=root;
	struct Node *newnode;
	newnode=(struct Node*)malloc(sizeof(struct Node));
	newnode->key=k;
	while (ptr != NULL)
	{
		parent = ptr;
		if (newnode->key < ptr->key)
		{
			ptr = ptr->left;
		}
		else
		{
			ptr = ptr->right;
		}
	}
	newnode->parent=parent;
	newnode->left=NULL;
	newnode->right=NULL;
	if(parent == NULL)
	{
			root=newnode;
	}
	else
	{
		if (newnode->key < parent->key)
		{
			parent->left = newnode;
		}
		else
		{
			parent->right = newnode;
		}
	}	
}

int tree_deletion(struct Node *ptr)
{
	struct Node *minimum;	
	struct Node *maximum;
	minimum=tree_minimum(ptr->right);
	maximum=tree_maximum(ptr->left);
	if((maximum==NULL)&&(minimum==NULL))	//case 01
	{
		if(ptr==root)
		{
			root=NULL;
		}
		else
		{
			if(ptr==ptr->parent->right)
			{
				ptr->parent->right=NULL;
			}
			else
			{
				ptr->parent->left=NULL;
			}
		}
		free(ptr);
		return 0;
	}
	if((maximum==NULL)||(minimum==NULL))	//case 02
	{
		if(maximum==NULL)
		{
			ptr->key=minimum->key;
			tree_deletion(minimum);
			return 0;
		}
		if(minimum==NULL)
		{
			ptr->key=maximum->key;
			tree_deletion(maximum);
			return 0;
		}
	}
	if((maximum!=NULL)&&(minimum!=NULL))	//case 03
	{
		ptr->key=minimum->key;
		tree_deletion(minimum);
		return 0;
	}
	
}

void traversal(struct Node *root)
{
	struct Node *ptr;
	ptr=root;
	if (ptr!=NULL)
	{
		traversal(ptr->left);
		printf(" %d ",ptr->key);
		traversal(ptr->right);
	}
}

int main()
{
	int choice;
	do
	{
		printf("\n1.Insertion.\n2.Deletion.\n3.Traversal.\n4.Search.\n5.Exit.");
		printf("\nEnter Your Choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{	
				int k;
				printf("\nEnter The key to Insert : ");
				scanf("%d",&k);
				tree_insert(k);
				break;
			}
			case 2:
			{
				int k;
				printf("\nEnter The key to Delete : ");
				scanf("%d",&k);
				struct Node *ptr;
				ptr=tree_search(root,k);
				if(ptr!=NULL)
				{
					printf("\nThe Deleted Node is : %d ",k);
					tree_deletion(ptr);
				}
				else
				{
					printf("key not found.!");
				}
				break;
			}
			case 3:
			{
				printf("\nINORDER Tree Traversal is : ");
				traversal(root);
				break;
			}
			case 4:
			{
				int k;
				printf("\nEnter The key to Search : ");
				scanf("%d",&k);
				struct Node *ptr;
				ptr=tree_search(root,k);
				if(ptr==NULL)
				{
					printf("The Node %d is Not Found.!",k);
				}
				else
				{
					printf("The Node %d is Found.",k);
				}
				break;
			}
			case 5:
			{
				printf("\nEXIT\n");
				break;
			}
			
		}
	}
	while(choice!=5);
	return 0;
}
