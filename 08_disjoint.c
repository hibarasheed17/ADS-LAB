#include<stdio.h>

int parent[7];
int rank[7];
int choice,X,Y,result,find_Y,find_X;

void makeset(int X)
{
	parent[X]=X;
	rank[X]=0;
}


int findset(int X)
{
	if(X!=parent[X])
	{
		parent[X]=findset(parent[X]);
	}
	return parent[X];
}

void union_by_rank(int X,int Y)
{
	if (rank[X]>rank[Y])
	{
		parent[Y]=X;
	}
	else
	{
		parent[X]=Y;
		if(rank[X]==rank[Y])
		{
			rank[Y]=rank[Y]+1;
		}
	}
}

void display()
{
	printf("parent :");
	for(int i=0;i<7;i++)
	{
		printf(" %d ",parent[i]);
	}
	printf("\n  rank :");
	for(int i=0;i<7;i++)
	{
		printf(" %d ",rank[i]);
	}
	printf("\n");
}

int main()
{
	do
	{
		printf("\n1.Make Set.\n");
		printf("2.Find Set.\n");
		printf("3.Union by RANK Set.\n");
		printf("4.Display.\n");
		printf("5.exit\n");
		printf("\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				printf("\nEnter a element to make a set : ");
				scanf("%d",&X);
				makeset(X);
				break;
			}
			case 2:
			{
				printf("\nEnter a element to find in set : ");
				scanf("%d",&X);
				result=findset(X);
				printf("\nThe Parent %d",result);
				break;
			}
			case 3:
			{
				printf("\nEnter first set X : ");
				scanf("%d",&X);
				printf("\nEnter second set Y : ");
				scanf("%d",&Y);
				find_X=findset(X);
				find_Y=findset(Y);
				union_by_rank(find_X,find_Y);
				break;
			}
			case 4:
			{
				display();
				break;
			}
			case 5:
			{
				printf("exit");
				break;
			}
		}
	}
	while(choice!=5);
	return 0;
}
