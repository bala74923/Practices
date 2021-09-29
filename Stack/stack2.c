#include<stdio.h>
#include<stdlib.h>

struct Stack
{
	int capacity;
	int top ;
	int *arr;
};

struct Stack * createStack(int capacity)
{
	struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
	stack->capacity = capacity;
	stack->top=-1;
	stack->arr = (int *)malloc(sizeof(int)*capacity);
	return stack;
}

void push(struct Stack *stack,int val)
{
	if(isFull(stack))
	{
		printf("stack is full");
		return;
	}
	stack->arr[++stack->top] = val;
}

int pop(struct Stack *stack)
{
	if(isEmpty(stack)) 
	{
		printf("Stack isn Empty\n");
		return -1;
	}
	return stack->arr[stack->top--] ;
}

int peek(struct Stack *stack)
{
	if(isEmpty(stack)) 
	{
		printf("Stack isn Empty\n");
		return -1;
	}
	return stack->arr[stack->top] ;
}

int isFull(struct Stack *stack)
{
	return stack->top==stack->capacity-1;
}

int isEmpty(struct Stack*stack)
{
	return stack->top==-1;
}

int main()
{
	int n;
	printf("Enter the total SIZE:");
	scanf("%d",&n);
	struct Stack *stack= createStack(n);
	for(int i=0;i<n;i++)
	{
		int num;
		scanf("%d",&num);
		push(stack,num);
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d\n",pop(stack));
	}
	getch();
	return 0;
}