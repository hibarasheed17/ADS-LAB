#include <stdio.h>
#include <stdlib.h>
#define max_size 5
int adjmtx[max_size][max_size],bfsqueue[max_size],visited[max_size],s;
int front=-1,rear=-1,data,v,i,j;
int enqueue(int v)
{
	if(front==(max_size-1))	
	{
		printf("Queue is Full.!");
		exit(1);
	}	
	if((front==-1)&&(rear==-1))
	{
		front=front+1;
	}
	rear=rear+1;
	bfsqueue[rear]=v;
	
}

int dequeue()
{
	if((front==-1)&&(rear==-1))
	{
		printf("Queue is Empty.!");
		exit(1);
	}
	data=bfsqueue[front];
	if (front==rear)
	{
		front=-1;
		rear=-1;
		return data;	
	}
	front=front+1;
	return data;
}


int BFS(int s)
{
	enqueue(s);
	visited[s]=1;
	printf("\nBFS Order of Graph is : ");
	while((front!=-1)&&(rear!=-1))
	{
		v=dequeue();
		printf(" %d ",v);
		for(i=0;i<max_size;i++)
		{
			if(adjmtx[v][i]==1)
			{
				if(visited[i]!=1)
				{
					enqueue(i);
					visited[i]=1;
				}
			}
		}
	}
}

int main()
{
	printf("\nEnter Source Vertex : ");
	scanf("%d",&s);
	printf("\nEnter the elements of adjacent metrix : \n");
	for(i=0;i<max_size;i++)
	{
		for(j=0;j<max_size;j++)
		{
			scanf("%d",&adjmtx[i][j]);
		}
	}
	BFS(s);
	printf("\n");
	return 0;
	
}
