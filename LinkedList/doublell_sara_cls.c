#include<stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *prev,*next;
}*tail=NULL;

void append(struct Node**head,int data)
{
	struct Node *nn = (struct Node*)malloc(sizeof(struct Node));
	nn->data = data;
	nn->next = NULL;
	nn->prev = NULL;
	if(*head==NULL)
	{
		*head=nn;
		tail=nn;
	}
	else
	{

		tail->next = nn;
		nn->prev = tail;
		tail =nn;
	}
}

// void insertAtBeginning(struct Node**head,int data)
// {
// 	struct Node * newnode = (struct Node*)malloc(sizeof(struct Node));
// 	newnode->data = data;
// 	newnode->next = (*head);
// 	(*head)->prev = newnode;
// 	(*head) = newnode;
// }

void deleteLast(struct Node**head)
{
	struct Node *last = tail;
	if(*head ==NULL)
	{
		return ;
	}
	tail = tail->prev;
	tail->next = NULL;
	free(last);

}

void deleteFirst(struct Node **head)
{
	struct Node *temp = (*head);
	(*head) = (*head)->next;
	(*head)->prev = NULL;
	free(temp);
}

void displayReverse()
{
	struct Node *temp = tail;
	while(temp!=NULL)
	{
		printf("%d --> ", temp->data);
		temp = temp->prev;
	}
	printf("NULL\n");
}

void insertBeginning(struct Node**head,int data)
{
	struct Node*nn = (struct Node*)malloc(sizeof(struct Node));
	nn->data = data;
	nn->next = NULL;
	nn->prev=NULL;
	if(*head==NULL)
	{
		*head=nn;
		tail=nn;
	}
	else
	{
		nn->next = *head;
		(*head)->prev = nn;
		*head = nn;
	}
}     

void display(struct Node *head)
{
	struct Node *temp = head;
	while(temp!=NULL)
	{
		printf("%d --> ",temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

void deleteIndex(struct Node **head,int pos)
{
	pos--;
	struct Node *previous_node = NULL;
	struct Node *temp = (*head);
	for(int i=0;i<pos;i++) 
	{
		previous_node = temp;
		temp = temp->next;
	}
	if(temp==tail)
	{
		deleteLast(head);
		return;
	}
	previous_node->next = temp->next;
	struct Node *nextnode = temp->next;
	nextnode->prev = previous_node;
	free(temp);
}

void insertAtPos(struct Node **head,int data,int pos)
{
	pos--;
	struct Node *nn = (struct Node*)malloc(sizeof(struct Node));
	nn->data = data;
	nn->next = NULL;
	nn->prev =NULL;
	struct Node *temp = *head;
	struct Node *previous_node = NULL;
	for(int i=0;i<pos;i++)
	{
		previous_node = temp;
		temp = temp->next;
	}
	nn->next = temp;
	nn->prev = previous_node;
	previous_node->next = nn;
	temp->prev = nn;
}

int main()
{
	struct Node *head = NULL;
	for(int i=1;i<11;i++)
	{ append(&head,i);	}
	deleteIndex(&head,2);
	display(head);
	displayReverse();
	getchar();
	return 0;
}