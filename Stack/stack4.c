#include <stdio.h>
#include<stdlib.h>

struct Stack
{
	int top;
	int size;
	int *array;
};

struct Stack* createStack(int size)
{
	struct Stack *st = (struct Stack*)malloc(sizeof(struct Stack));
	st->size = size;
	st->top =-1;
	st->array = (int *)malloc(sizeof(int)*size);
}

void push(struct Stack *st,int data)
{
	if(isFull(st)==1)
	{
		printf("Stack is Full\n");
		return ;
	}
	st->array[++(st->top)]=data;
}

int pop(struct Stack *st)
{
	if(isEmpty(st)==1)
	{
		printf("Stack is Empty\n");
		return -1;
	}
	return st->array[(st->top)--];
}

int peek(struct Stack *st)
{
	if(isEmpty(st)==1)
	{
		printf("Stack is Empty\n");
		return -1;
	}
	return st->array[(st->top)];
} 

int isFull(struct Stack *st)
{
	return st->top==st->size-1?1:0;
}

int isEmpty(struct Stack *st)
{
	return st->top==-1?1:0;
}

void display(struct Stack *st)
{
	for(int i=st->top;i>=0;i--)
	{
		printf("%d -> ",st->array[i]);
	}
	printf("\n");
}

int main()
{
	int n;
	printf("Enter the size:");
	scanf("%d",&n);
	struct Stack *st = createStack(n);
	int op;
	while(1)
	{
		printf("Enter the Option :\n1.To Pop\n2.To peek\n3.To Push\n4.ToDisplay\n");
		scanf("%d",&op);
		if(op>4||op<1) break;
		if(op==1)
		{
			int val = pop(st);
			if(val!=-1) printf("Popped :%d\n",val);
		}
		else if(op==2)
		{
			int val = peek(st);
			if(val!=-1) printf("Popped :%d\n",val);
		}
		else if(op==3)
		{
			printf("Enter the Value to Push:");
			int val;
			scanf("%d",&val);
			push(st,val);
		}
		else if(op==4)
		{
			display(st);
		}
	}
	
	getchar();
	return 0;
}