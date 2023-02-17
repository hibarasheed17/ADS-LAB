#include<stdio.h>
int queue[8];
int front=-1;
int rear=-1;
int data;
int choice;


void enqueue(int data)
{

if(rear==7)
{
printf("The Queue is Full.! \n");
}
else 
{
 if((rear==-1)&&(front==-1))
 {
 front=front+1;
 rear=rear+1;
 }
 else
 {
 rear=rear+1;
 }
queue[rear]=data;
}
}


void dequeue()
{

if(front==-1)
{
printf("Queue is Empty.! \n");
}
else 
{
data=queue[front];
 if(front==rear)
 {
 front=-1;
 rear=-1;
 }
 else
 {
 front=front+1;
 }
printf("the deleted item from the queue is : %d \n",data);
}
}

void print()
{

if ((front==-1)&&(rear==-1))
{
printf("the queue not have any data.! \n");
}
else
{
printf("the elements in the Queue is given below : ");
 for(int i=front;i<=rear;i++)
 {
 printf("\n %d \n",queue[i]);
 }
}
}


int main()
{
do
{
printf("\n1.ENQUEUE.\n");
printf("2.DEQUEUE.\n");
printf("3.print all elements of Queue.\n");
printf("4.exit.\n");
printf("\n Enter Your Choice : ");
scanf("%d",&choice);
switch(choice)
{
 case 1 :
  {
   printf("Enter a value to Enqueue : ");
   scanf("%d",&data);
   enqueue(data);
   break; 
  }
 case 2 :
  {
   dequeue();
   break; 
  }
 case 3 :
  {
   print();
   break; 
  }
 case 4 :
  {
   printf("Exit");
   break; 
  }
}
}
while(choice!=4);
return 0;
}
