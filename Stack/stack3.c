#include<stdio.h>
#include<stdlib.h>

struct Queue
{
	int front,rear;
	int size;
	int *arr;
	int capacity;
};

struct Queue* createQueue(int capacity)
{
	struct Queue* q= (struct Queue*)malloc(sizeof(struct Queue));
	q->front = 0;
	q->size=0;
	q->rear = capacity-1;
	q->capacity = capacity;
	q->arr = (int *)malloc(sizeof(int)*capacity);
	return q;
}

int isFull(struct Queue*q)
{
	return (q->size)==(q->capacity)?1:0;
}

int isEmpty(struct Queue*q)
{
	return (q->size==0)?1:0;
}

void enqueue(struct Queue*q,int data)
{
	if(isFull(q)==1)
	{
		printf("Queue is already full\n");return;
	}
	(q->rear) = ((q->rear)+1)%(q->capacity);
	q->arr[(q->rear)] = data;
	(q->size)++;
}

int dequeue(struct Queue*q)
{
	if(isEmpty(q)==1)
	{
		printf("Qeueue is Empty");
		return -1;
	}
	int data = q->arr[q->front];
	(q->front) =((q->front)+1)%(q->capacity);
	(q->size)--;
	return data;
}

int main()
{
	struct Queue *q = createQueue(10);
	for(int i=0;i<10;i++)
	{
		enqueue(q,i+1);
	}
	for(int i=0;i<10;i++)
	{
		printf("%d\n",dequeue(q));
	}
	getch();
	return 0;
}