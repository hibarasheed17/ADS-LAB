#include<stdio.h>
int stack[8];
int choice;
int top=-1;
int data;

int print(int data)
{
if (top>=0)
{
 printf("the elements in the stack is given below : \n");
for(data=top;data>=0;data--)
printf("\n %d",stack[data]);
}
}
int push(int data)
{
if(top!=8)
{
top=top+1;
stack[top]=data;
}
else
{
printf("could not insert data,stack is full \n");
}
}


int pop(int data)
{
if(top<=-1)
{
printf("could not retrive data, stack is empty \n");
}
else
{
printf("%d \n",stack[top]);
top=top-1;

}
}
int main()
{

printf("1.push.\n");
printf("2.pop.\n");
printf("3.print all elements of stack.\n");
printf("4.exit.\n");

do
{
printf("\n Enter Your Choice : ");
scanf("%d",&choice);
switch(choice)
{
case 1 :
 {
 printf("Enter an item to push : ");
 scanf("%d",&data);
 push(data);
break; 
}

case 2 :
{
 pop(data);

break;
}
case 3 :
{
print(data);
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
