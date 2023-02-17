#include <stdio.h>
#include <stdlib.h>
#define max_size 5
int adjmtx[max_size][max_size],dfsstack[max_size],visited[max_size],s;
int top=-1,data,v,i,j;

int push(int v)
{
	if(top==(max_size-1))
	{
		printf("The Stack Is Full.!");
		exit(1);
	}
	top=top+1;
	dfsstack[top]=v;
}

int pop()
{
	if(top==-1)
	{
		printf("The Stack Is Empty.!");
		exit(1);
	}
	data=dfsstack[top];
	top=top-1;
	return data;
}

int DFS(int s)
{
	push(s);
	visited[s]=1;
	printf("\nDFS Order of Graph is : ");
	while(top!=-1)
	{
		v=pop();
		printf(" %d ",v);
		for(i=0;i<max_size;i++)
		{
			if(adjmtx[v][i]==1)
			{
				if(visited[i]!=1)
				{
					push(i);
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
	DFS(s);
	printf("\n");
	return 0;
	
}
