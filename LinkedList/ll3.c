#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

struct Node * getNode(int data)
{
	struct Node* nn = (struct Node*)malloc(sizeof(struct Node));
	nn->data = data;
	nn->next = NULL;
	return nn;
}

void insertAtBeginning(struct Node **head,int data)
{
	struct Node *newnode = getNode(data);
	newnode->next = *head;
	*head = newnode;
}

void append(struct Node**head,int data)
{
	struct Node* newnode = getNode(data);
	if(*head==NULL)
	{
		*head = newnode;
	}
	else
	{
		struct Node *temp = *head;
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next  = newnode;
	}
}

void display(struct Node *head)
{
	struct Node *temp = head;
	while(temp!=NULL)
	{
		printf("%d -> ",temp->data);
		temp = temp->next;
	}
	printf("NUL\n");
}

int main()
{
	struct Node *head = NULL;
	for(int i=0;i<5;i++)
	{
		insertAtBeginning(&head,i+1);
	}
	display(head);
	//end
	getch();
	return 0;
}