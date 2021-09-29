#include <stdio.h>
#include<stdlib.h>

struct Queue
{
	int capacity;
	int front,rear,size;
	int *arr;
};

struct Queue* createStack(int capacity)
{
	struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
	queue->capacity = capacity;
	queue->front = 0,queue->size=0;
	queue->rear = capacity-1;
	queue->arr = (int *)malloc(sizeof(int)*capacity);
	return queue;
}

void enqueue(struct Queue*q,int data)
{
	if(isfull(q)==1) return;
	q->rear = ((q->rear)+1)%(q->capacity);
	q->arr[q->rear] = data;
	q->size++;
}

int dequeue(struct Queue*q)
{
	if(isEmpty(q)==1) return -1;
	int data = q->arr[q->front];
	q->front = ((q->front)+1)%(q->capacity);
	q->size--;
	return data;
}

int isfull(struct Queue *q)
{
	return q->size==q->capacity?1:0;
}

int isEmpty(struct Queue*q)
{
	return q->size==0?1:0;
}

int main()
{
	struct Queue *queue = createStack(5);
	for(int i=0;i<5;i++)
	{
		enqueue(queue,i+1);
	}
	for (int i = 0; i < 5; ++i)
	{
		printf("%d\n",dequeue(queue));
	}
	int n;
	printf("Terminate\n");
	scanf("%d",&n);
	getch();
	return 0;
}