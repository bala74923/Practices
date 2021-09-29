#include <stdio.h>
#include<stdlib.h>

struct ListNode
{
	struct Node * node;
	struct ListNode *next;
};

struct Node
{
	int data;
	struct Node *left,*right;
};

struct ListNode * getListNode(struct Node* node)
{
	struct ListNode* nn = (struct ListNode*)malloc(sizeof(struct ListNode));
	nn->node = node;
	nn->next=NULL;
	return nn;
}

struct Node * getNode(int data)
{
	struct Node* nn = (struct Node*)malloc(sizeof(struct Node));
	nn->data = data;
	nn->left=NULL;
	nn->right=NULL;
	return nn;
}

void enqueue(struct ListNode **head,struct Node *node)
{
	if(*head==NULL)
	{
		(*head)=getListNode(node);
	}
	else
	{
		struct ListNode *nn = getListNode(node);
		struct ListNode *temp = (*head);
		while(temp->next!=NULL) temp = temp->next;
		temp->next = nn;
	}

}

struct Node* dequeue(struct ListNode**head)
{
	struct ListNode *temp = (*head);
	(*head) = (*head)->next;
	struct Node *nn = temp->node;
	//free(temp);
	return nn;
}



struct Node * addTree(struct Node*root,int data)
{
	if(root==NULL)
	{
		root = getNode(data);
	}
	else if(data<=root->data)
	{
		root->left = addTree(root->left,data);
	}
	else if(data>root->data)
	{
		root->right = addTree(root->right,data);
	}
	return root;
}

int isEmpty(struct ListNode *head)
{
	return head==NULL?1:0;
}

int main()
{
	struct ListNode *head=NULL;
	struct Node *root =NULL;
	root = addTree(root,5);
	root = addTree(root,2);
	root = addTree(root,1);
	root = addTree(root,4);
	root = addTree(root,7);
	root = addTree(root,6);
	root = addTree(root,10);
	while(isEmpty(head)==0)
	{
		struct Node *curr = dequeue(&head);
		printf("%d - ",curr->data);
		if(curr->left!=NULL) enqueue(&head,curr->left);
		if(curr->right!=NULL) enqueue(&head,curr->right);
	}
	getchar();
	return 0;
}