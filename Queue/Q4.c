#include <stdio.h>
#include <stdlib.h>

struct Q
{
	int size;
	int capacity;
	int front,rear;
	int *arr;
};

struct Q*  newQ(int capacity)
{
	struct Q* q = (struct Q*)malloc(sizeof(struct Q));
	q->capacity =capacity;
	q->size=0;
	q->front=0;
	q->rear=-1;
	q->arr = (int *)malloc(sizeof(int)*capacity);
	return q;
}

void enqueue(struct Q*q,int data)
{
	if(isFull(q)==1)
	{
		printf("Queue is Full\n");
		return ;
	}
	(q->rear)=(q->rear+1)%q->capacity;
	q->arr[q->rear] = data;
	q->size++;
}

int dequeue(struct Q *q)
{
	if(isEmpty(q)==1)
	{
		printf("Queue is Empty\n");
		return -1;
	}
	int data = q->arr[q->front];
	q->front=((q->front)+1)%q->capacity;
	q->size--;
	return data;
}

int isEmpty(struct Q*q)
{
	return q->size==0;
}

int isFull(struct Q*q)
{
	return q->size==q->capacity?1:0;
}

void display(struct Q*q)
{
	for(int i=q->front;i<(q->front)+(q->size);i++)
	{
		printf("%d ->",q->arr[i%q->capacity]);
	}
	printf("\n");
}

int main()
{
	int n;
	printf("Enter the Number :");
	scanf("%d",&n);
	struct Q*q = newQ(n);
	while(1)
	{
		int op;
		printf("Enter the Operations :\n1.To Enqueue\n2.To Dequeue\n3.Display\n");
		scanf("%d",&op);
		if(op<1||op>4) break;
		if(op==1)
		{
			printf("Enter the element to Enqueue");
			int val;
			scanf("%d",&val);
			enqueue(q,val);
		}
		else if(op==2)
		{
			int val = dequeue(q);
			if(val!=-1) printf("Dequeued Element is %d\n",val);
		}
		else if(op==3)
		{
			display(q);
		}
	}
	getchar();
	return 0;
}