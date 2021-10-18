#include <stdio.h>
#include<stdlib.h>

struct Queue
{
	int size,front,rear;
	int capacity;
	int *array;
};

struct Queue* createQueue(int capacity)
{
	struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
	q->size = 0;
	q->capacity = capacity;
	q->front = 0;
	q->rear = capacity-1;
	q->array = (int *)malloc(sizeof(int)*capacity);
	return q;
}

int isFull(struct Queue*q)
{
	return q->size==q->capacity?1:0;
}

int isEmpty(struct Queue*q)
{
	return q->size==0?1:0;
}

void enqueue(struct Queue* q,int data)
{
	if(isFull(q))
	{
		printf("Queue is Full\n");return;
	}
	(q->size)++;
	q->rear = ((q->rear)+1)%(q->capacity);
	q->array[(q->rear)] = data;
}

int dequeue(struct Queue *q)
{
	if(isEmpty(q))
	{
		printf("Queue is Empty");
		return -1;
	}
	int data = q->array[(q->front)];
	(q->front) = ((q->front)+1)%(q->capacity);
	(q->size)--;
	return data;
}

int main()
{
	struct Queue* q = createQueue(10);
	for(int i=0;i<10;i++) enqueue(q,i+1);
	for(int i=0;i<10;i++) printf("%d\n",dequeue(q)); 
	getch();
	return 0;
}