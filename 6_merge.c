#include<stdio.h>
int main()
{
	int a1,a2,a3=0,i,j,temp;
	printf("\nEnter the size of array 1 : ");
	scanf("%d",&a1);
	printf("\nEnter the size of array 2 : ");
	scanf("%d",&a2);
	a3=a1+a2;
	int array1[a1],array2[a2],array3[a3];
	
	//elements entering.
	
	printf("\nEnter the elements of array 1 : \n");
	for (i=0;i<a1;i++)
	{
		scanf("%d",&array1[i]);
	}
	printf("\nEnter the elements of array 2 : \n");
	for (j=0;j<a2;j++)
	{
		scanf("%d",&array2[j]);
	}
	
	//sorting the 2 arrays.
	
	for(i=0;i<a1;i++)
	{
		for(j=i+1;j<a1;j++)
		{
			if(array1[i]>array1[j])
			{
				temp=array1[i];
				array1[i]=array1[j];
				array1[j]=temp;
			}
		}
	}
	for(i=0;i<a2;i++)
	{
		for(j=i+1;j<a2;j++)
		{
			if(array2[i]>array2[j])
			{
				temp=array2[i];
				array2[i]=array2[j];
				array2[j]=temp;
			}
		}
	}
	
	//printing sorted arrays.
	
	printf("\nArray 1 after sorting : ");
	for (i=0;i<a1;i++)
	{
		printf("   %d   ",array1[i]);
	}
	printf("\n");
	printf("\nArray 2 after sorting : ");
	for (i=0;i<a2;i++)
	{
		printf("   %d   ",array2[i]);
	}
	printf("\n");
	
	//merging to a 3rd array.
	
	for(i=0;i<a1;i++)
	{
		array3[i]=array1[i];
	}
	for(i=0 , j=a1;i<a2 && j<a3;i++ , j++)
	{
		array3[j]=array2[i];
	}
	
	//printing array 3 after merging 
	
	printf("\nAfter merging the 2 arrays : ");
	for(i=0;i<a3;i++)
	{
		printf("   %d   ",array3[i]);
	}
	printf("\n");
	
	//sorting array3.
	
	for(i=0;i<a3;i++)
	{
		for(j=i+1;j<a3;j++)
		{
			if(array3[i]>array3[j])
			{
				temp=array3[i];
				array3[i]=array3[j];
				array3[j]=temp;
			}
		}
	}
	
	//printing array3 after sorting.
	
	printf("\nAfter Sorting the merge array : ");
	for(i=0;i<a3;i++)
	{
		printf("   %d   ",array3[i]);
	}
	printf("\n");
	printf("\n");
	return 0;
}
