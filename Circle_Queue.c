#include <stdio.h>
#include <stdlib.h>


#include<stdio.h>
#define SIZE 5
int items[SIZE];
int front=-1,rear=-1;
int isFull()
{
if((front==0&&rear==SIZE-1)||(rear==(front-1)%(SIZE-1)))
{
return 1;
}
else
{
return 0;
}
}
void isEmpty()
{
if(front== -1&& rear== -1)
{
printf("Circular queue is empty.\n");
}
else
{
printf("Circular queue is not empty.\n");
}
}
int isEmpty1()
{
if(front==-1&&rear==-1)
{
return 1;
}
else
{
return 0;
}
}
void enqueue(int element)
{
if(isFull())
{
printf("Circular queue is overflow.\n");
}
else
{
if(isEmpty1())
{
front=0;
rear=0;
}
else
{
rear=(rear+1)%SIZE;
}
items[rear]=element;


printf("Successfully inseted.\n");
}
}
int dequeue()
{
int element;
if(isEmpty1())
{
printf("Circular queue is underflow.\n");
return -1;
}
else
{
element=items[front];
if(front==rear)
{
front=-1;
rear=-1;
}
else
{
front=(front+1)%SIZE;
}
printf("Deleted element = %d\n",element);
return element;
}
}
void size()
{
int count=0;
if(isEmpty1())
{
printf("Circular queue size : %d\n",count);
}
else if(front<=rear)
{
count=rear-front+1;
printf("Circular queue size : %d\n",count);
}
else
{
count=SIZE-front+rear+1;
printf("Circular queue size : %d\n",count);
}
}
void display()
{
int i;
if(front==-1)
{
printf("Circular queue is empty.\n");
}
else
{
printf("Elements in the circular queue : ");
for(i=front;i!=rear;i=(i+1)%SIZE)
{
    printf("%d ",items[i]);
    
}
printf("%d ",items[i]);
printf("\n");
}
}





int main() {
int op, x;
while(1) {
printf("1.Enqueue 2.Dequeue 3.Display 4.Is empty 5.Size 6.Exit\n");
printf("Enter your option : ");
scanf("%d",&op);
switch(op) {
case 1:
printf("Enter element : ");
scanf("%d",&x);
enqueue(x);
break;
case 2:
dequeue();
break;
case 3:
display();
break;
case 4:
isEmpty();
break;
case 5:
size();
break;
case 6: exit(0);
}
}
}
