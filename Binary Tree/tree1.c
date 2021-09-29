#include <stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *left,*right;
};

struct Node* getNode(int data)
{
	struct Node *nn = (struct Node*)malloc(sizeof(struct Node));
	nn->data = data;
	nn->left = NULL;
	nn->right = NULL;
	return nn;
}

struct Node * append(struct Node *root,int data)
{
	if(root ==NULL)
	{
		root = getNode(data);
	}
	else if(data<=root->data)
	{
		root->left = append(root->left,data);
	}
	else if(data>root->data)
	{
		root->right = append(root->right,data);
	}
	return root;
}

void display(struct Node *root)
{
	if(root==NULL) return ;
	printf("%d ,",root->data);
	display(root->left);
	display(root->right);
}

int main()
{
	struct Node *root=NULL;
	for(int i=0;i<10;i++) 
	{
		root = append(root,i+1);
	}
	display(root);
	getchar();
	return 0;
}