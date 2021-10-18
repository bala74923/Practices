#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node * next;
};
void push(struct Node**head,int data)
{
	struct Node *node = (struct Node*)malloc(sizeof(struct Node));
	node->data = data;
	node->next = NULL;
	if(*head==NULL)
	{
		*head = node;
	}
	else
	{
		struct Node *temp= *head;
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next = node;
	}
}

int pop(struct Node **head)
{
	struct Node *temp = *head;
	if(*head==NULL)
	{
		printf("Stack is Empty\n");
		return -1;
	}
	if((*head)->next==NULL)
	{
		int data = (*head)->data;
		*head=NULL;
		return data;
	}
	struct Node *pretemp = NULL;
	while(temp->next!=NULL)
	{
		pretemp = temp;
		temp=temp->next;
	}
	pretemp->next=NULL;
	int data = temp->data;
	free(temp);
	return data;
}

int peek(struct Node **head)
{
	struct Node *temp = *head;
	if(*head==NULL)
	{
		printf("Stack is Empty\n");
		return -1;
	}
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	return temp->data;
}

int main()
{
	struct Node *head = NULL;
	printf("Enter the total Size:\n");
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int num;
		printf("Enter the Number to add:\n");
		scanf("%d",&num);
		push(&head,num);
	}
	for(int i=0;i<n;i++)
	{
		printf("%d\n",pop(&head));
	}
	getch();
	return 0;
	
}