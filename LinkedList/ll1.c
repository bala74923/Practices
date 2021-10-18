#include<stdio.h>
#include<stdlib.h>
 
 struct Node
 {
 	int data;
 	struct Node *next;
 };
 void append(struct Node**head,int data)
 {
 	struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
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
 			temp = temp -> 
 			next;
 		}
 		temp->next = newnode;
 	}
 }

void display(struct Node *head)
{
	struct Node *temp = head;
	while(temp!=NULL)
	{
		printf("%d - >",temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

 int main()
 {
 	struct Node *head = NULL;
 	append(&head,10);
 	display(head);
 	//
 	getch();
 	return 0;
 }