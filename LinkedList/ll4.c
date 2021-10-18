#include <stdio.h>
#include <stdlib.h>

struct Node 
{
	int data;
	struct Node *next;
};

void print(struct Node *head)
{
	struct Node *temp = head;
	while(temp!=NULL)
	{
		printf("%d -> ",temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

struct Node * getNode(int data)
{
	struct Node* newnode = (struct Node *)malloc(sizeof(struct Node));
	newnode ->data = data;
	newnode ->next = NULL;
	return newnode;
}

void insertAtBeginning(struct Node **head,int data)
{
	struct Node *newnode = getNode(data);
	newnode ->next = *head;
	*head = newnode;
}

void append(struct Node **head,int data)
{
	struct Node * newnode = (struct Node *)malloc(sizeof(struct Node));
	newnode->data = data;
	newnode->next = NULL;

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
		temp->next = newnode;
	}
}

void insertAtPos(struct Node **head,int data,int pos)
{
	pos--;
	struct Node *newnode = getNode(data);
	if(*head==NULL)
	{
		*head = newnode;
	}
	else
	{
		struct Node *temp = *head;
		int ind=0;
		while(temp!=NULL)
		{
			if(ind+1==pos)
			{
				newnode->next = temp->next;
				temp->next = newnode;
				break;
			}

			temp = temp->next;
			ind++;
		}
	}
}

void deleteAtFirst(struct Node **head)
{
	(*head) = (*head)->next;
}

void deleteAtLast(struct Node **head)
{
	struct Node *temp = *head;
	struct Node *prev = NULL;
	while(temp->next!=NULL)
	{
		prev = temp;
		temp = temp->next;
	}
	prev->next = NULL;
}

void deletePos(struct Node **head,int pos)
{
	struct Node *temp = *head;
	pos--;
	int ind=0;
	struct Node *prev = NULL;
	while(temp!=NULL)
	{
		if(ind==pos)
		{
			prev->next = temp->next;
			break;
		}
		prev = temp;
		temp = temp->next;
		ind++;
	}
}

int main()
{
	struct Node *head = NULL;
	for(int i=0;i<10;i++) append(&head,i+1);
	
	//insertAtPos(&head,15,10);
	//deleteAtFirst(&head);
	//deleteAtLast(&head);
	deletePos(&head,5);

	print(head);
	getch();
	return 0;
}