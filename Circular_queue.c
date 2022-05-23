#include<stdio.h>
#include<stdlib.h>
int rear=-1,front=-1;
int  n,*st;
void enqueue(int value)	
{

	if((rear==n-1 && front==0)|| front==rear+1)
	{
		printf("Queue is full\n");
	}
	else if(front==-1 && rear==-1)
	{
		rear=(rear+1)%n;
		st[rear]=value;
		front=0;
	}
	else
	{
		rear=(rear+1)%n;
		st[rear]=value;
	}	
}
int dequeue()
{
	int value;
	if(rear==-1 && front==-1)
	{
		return -1;
	}
	else if(front==rear)
	{
		value=st[front];
		front=-1;
		rear=-1;
	}
	else
	{
		
		value=st[front];
		front=(front+1)%n;
		return value;
	}
}
void display()
{
	int i,j;
	if(front==-1 && rear==-1)
	{
		printf("Queue is Empty\n");
	}
	else
	{
		i=front;
		j=rear;
		while(i!=j)
		{
			printf("%d ",st[i]);
			i=(i+1)%n;
		}
		printf("%d",st[j]);
		
	}
	
}
void main()
{
	int i,value,ch;
	scanf("%d",&n);
	st=(int *)calloc(n,sizeof(int));
	while(1)
	{
		printf("1.enqueue 2.dequeue 3.display 4.exit : ");
		scanf("%d",&ch);
		if(ch==1)
		{
			scanf("%d",&value);
			enqueue(value);
		}
		else if(ch==2)
		{
			value=dequeue();
			if(value==-1)
			{
				printf("queue is empty\n");
			}
			else
			{
				printf("%d ",value);
			}
		}
		else if(ch==3)
		{
			display();	
		}
		else
		{
			break;	
		}
	}
}
