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

void sort(node** head)
{
	node* temp = *head;
	while(temp!=NULL)
	{
		node* temp2 = temp->next;
		while(temp2!=NULL)
		{
			if(temp->data>temp2->data)
			{
				int var = temp->data;
				temp->data = temp2->data;
				temp2->data = var;
			}
			temp2=temp2->next;
		}
		temp = temp->next;
	}
}

int main()
{
	node* head =NULL;
	for(int i=10;i>=1;i--) append(&head,i);
	display(head);
	sort(&head);
	printf("\n");
	display(head);
	return 0;
}