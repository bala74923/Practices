#include<stdio.h>
#include<stdlib.h>

struct Stack
{
	int capacity;
	int top;
	int *array;
};

struct Stack * createStack(int capacity)
{
	struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->capacity = capacity;
	stack->top =-1;
	stack->array = (int *)malloc(sizeof(int)*capacity);
	return stack;
}

int isFull(struct Stack*stack)
{
	return stack->capacity-1==stack->top;
}

int isEmpty(struct Stack*stack)
{
	return stack->top==-1?1:0;
}

void push(struct Stack *stack,int data)
{
	if(isFull(stack))
	{
		printf("Stack is Full\n");
		return;
	}
	stack->array[++stack->top] = data;
}

int  pop(struct Stack*stack)
{
	if(isEmpty(stack))
	{
		printf("Stack is Empty\n");
		return -1;
	}
	return stack->array[stack->top--];
}

int  peek(struct Stack*stack)
{
	if(isEmpty(stack))
	{
		printf("Stack is Empty\n");
		return -1;
	}
	return stack->array[stack->top];
}

int main()
{
	int n;
	scanf("%d",&n);
	struct Stack *stack = createStack(n);
	
	for(int i=0;i<n;i++)
	{
		int num;
		scanf("%d",&num);
		push(stack,num);
	}
	for(int i=0;i<n;i++)
	{
		printf("%d\n",pop(stack));
	}
	printf("%d\n",pop(stack));
	getch();
	return 0;
}