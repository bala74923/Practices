#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int val;
	struct Node *left,*right;
}node;

typedef struct Queue
{
	node * elem;
	struct Queue *next;
}Q;

Q* getQ(node *nn)
{
	Q* q = (Q*)malloc(sizeof(Q));
	q->elem = nn;
	q->next =NULL;
	return q;
}

node* getNode(int val)
{
	node *nn = (node*)malloc(sizeof(node));
	nn->val = val;
	nn->left=NULL;
	nn->right=NULL;
	return nn;
}

node* insert(node *root,int val)
{
	if(root==NULL)
	{
		root = getNode(val);
	}
	else if(val<=root->val)
	{
		root->left = insert(root->left,val);
	}
	else
	{
		root->right = insert(root->right,val);
	}
	return root;
}

void inOrder(node *root)
{
	if(root==NULL) return;
	inOrder(root->left);
	printf("%d , ",root->val);
	inOrder(root->right);
}

void preOrder(node *root)
{
	if(root==NULL) return;
	printf("%d , ",root->val);
	preOrder(root->left);
	preOrder(root->right);
}

void postOrder(node *root)
{
	if(root==NULL) return;
	postOrder(root->left);
	postOrder(root->right);
	printf("%d , ",root->val);
}

void enqueue(node * nn,Q** head)
{
	Q* temp = *head;
	if(*head==NULL)
	{
		(*head) = getQ(nn);
	}
	else
	{
		while(temp->next!=NULL) temp=temp->next;
		temp->next = getQ(nn);
	}
}

node *dequeue(Q**head)
{
	Q*temp = *head;
	*head = (*head)->next;
	node *ans = temp->elem;
	free(temp);
	return ans;
}

void levelOrder(node *root)
{
	Q* q = getQ(root);
	while(q!=NULL)
	{
		node* front = dequeue(&q);
		if(front->left!=NULL) enqueue(front->left,&q);
		if(front->right!=NULL) enqueue(front->right,&q);
		printf("%d ",front->val);
	}
}


int main()
{
	node * root = NULL;
	root = insert(root,5);
	root = insert(root,3);
	root = insert(root,2);
	root = insert(root,1);
	root = insert(root,4);
	root = insert(root,7);
	root = insert(root,6);
	root = insert(root,9);
	root = insert(root,8);
	root = insert(root,10);
	levelOrder(root);
	getchar();
	return 0;
}