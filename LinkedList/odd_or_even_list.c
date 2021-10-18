#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node* next;
}node;

node* getNode(int data)
{
	node* nn = (node*)malloc(sizeof(node));
	nn->data = data;
	nn->next = NULL;
	return nn;
}

void append(node** head,int data)
{
	if(*head==NULL)
	{
		*head = getNode(data);
	}
	else
	{
		node* temp = *head;
		while(temp->next!=NULL) temp = temp->next;
		temp->next = getNode(data);
	}
}

void display(node* head)
{
	node* temp = head;
	while(temp!=NULL)
	{
		printf("%d -> ",temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

int check(node* head,int result)
{
	node* temp = head;
	while(temp!=NULL)
	{
		if((temp->data)%2!=result)
		{
			return 0;
		}
		temp=temp->next;
	}
	return 1;
}

void print_odd_or_even(node* head)
{
	// odd check=> remainder is 1,so passing result remainder as argument
	if(check(head,1))
	{
		printf("\nLinked List is Odd");
	}
	// even check=> remainder is 0,so passing result remainder as argument
	else if(check(head,0))
	{
		printf("\nLinked List is Even");
	}
	// contains both odd and even elements
	else 
	{
		printf("\nLinked Contains Both Odd and Even");
	}
}

int main()
{
	node* head =NULL;
	for(int i=9;i>=1;i-=2) append(&head,i);
	display(head);
	print_odd_or_even(head);
	return 0;
}