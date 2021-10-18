#include<stdio.h>
#include<stdlib.h>

struct Node 
{
	int data;
	struct Node *next;
};

void append(struct Node **head,int data)
{
	struct Node *nn =(struct Node*)malloc(sizeof(struct Node));
	nn->data = data;
	nn->next = NULL;
	if(*head==NULL)
	{
		*head =nn;
	}
	else
	{
		struct Node *temp = *head;
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next = nn;
	}
}

void insertAtPos(struct Node*head,int pos,int data)
{
	struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->data = data;
	newnode->next = NULL;
	int i=0;
	struct Node *temp=head;
	while(temp!=NULL)
	{
		if(i+1==pos)
		{
			newnode->next = temp->next;
			temp->next  = newnode;
			break;
		}
		i++;
		temp = temp->next;
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
	printf("NULL\n");
}

int main()
{
	struct Node *head  = NULL;
	append(&head,10);
	append(&head,20);
	append(&head,30);
	append(&head,40);
	append(&head,50);
	insertAtPos(head,1,35);
	display(head);
	//end
	getch();
	return 0;
}