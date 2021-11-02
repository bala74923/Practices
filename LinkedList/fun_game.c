#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node *prev,*next;
}node;
node* getnode(int);
void insert(node**,int);
int size(node*);
void display(node*);
void display_neatly(node*);
int* getArray(node*);
void reverse_display(node*);
void addAtBeginning(node**,int);
node* play_fungame(node*,node*);

int main()
{
	node* list1 = NULL;
	node* list2 = NULL;
	int n;
	printf("Enter the Value of N:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int val;
		printf("Enter the value to insert at position %d: ",i+1);
		scanf("%d",&val);
		insert(&list1,val);
		addAtBeginning(&list2,val);
	}
	printf("\nList 1 is ");
	display(list1);
	printf("\nList 2 is ");
	reverse_display(list2);
	node* ans = play_fungame(list1,list2);
	printf("\n\nOutPut List");
	display_neatly(ans);
	return 0;
}
node* getnode(int data)
{
	node* nn = (node*)malloc(sizeof(node));
	nn->data = data;
	nn->prev = nn->next = NULL;
	return nn;
}

void insert(node** head,int data)
{
	node* nn = getnode(data);
	if((*head)==NULL)
	{
		(*head) = nn;
		return ;
	}
	node* temp = (*head);
	while(temp->next!=NULL) temp = temp->next;
	temp->next = nn;
	nn->prev = temp;

}

int size(node* head)
{
	int len=0;
	node* temp = head;
	while(temp!=NULL)
	{
		temp = temp->next;
		len++;
	}
	return len;
}

void display(node* head)
{
	node* temp = head;
	printf("[");
	while(temp!=NULL)
	{
		printf("%d",temp->data);
		temp = temp->next;
		if(temp!=NULL) printf(",");
	}
	printf("]\n"); 
}

void display_neatly(node* head)
{
	int len = size(head);
	int *arr =getArray(head);
	// here i have to code
	int tot = (2*len)+1;
	printf("\n");for(int i=0;i<tot;i++) printf("%c",i%2?'-':'+');printf("\n");
	for(int i=0;i<len;i++) printf("|%d",arr[i]);
	printf("|");
	printf("\n");for(int i=0;i<tot;i++) printf("%c",i%2?'-':'+');printf("\n");
}

int* getArray(node* head)
{
	node* temp = head;
	int len = size(temp);
	int* arr = (int*)malloc(sizeof(int)*len);
	for(int i=0;temp!=NULL;i++,temp=temp->next) arr[i] = temp->data;
	return arr;
}

void reverse_display(node* head)
{
	node* temp = head;
	while(temp->next!=NULL) temp = temp->next;
	printf("[");
	while(temp!=NULL)
	{
		printf("%d",temp->data);
		temp = temp->prev;
		if(temp!=NULL) printf(",");
	}
	printf("]\n"); 
}

void addAtBeginning(node** head,int data)
{
	node* nn = getnode(data);
	if(*head==NULL)
	{
		(*head) = nn;
		return ;
	}
	nn->next = (*head);
	(*head)->prev = nn;
	(*head) = nn;
}

node* play_fungame(node* head1,node* head2)
{
	node* ans_head =getnode(0);
	node* ans = ans_head;
	node* temp1 = head1,*temp2 = head2;
	while(temp1!=NULL && temp2!=NULL)
	{
		printf("\nComparing A (%d) and B(%d) : ",temp1->data,temp2->data);
		if(temp1->data>temp2->data)
		{
			ans->next = getnode(1);
			printf("A>B so 1");
			temp2=temp2->next;
		}
		else if(temp1->data<temp2->data)
		{
			ans->next = getnode(2);
			printf("A<B so 2");
			temp1=temp1->next;
		}
		else
		{
			ans->next = getnode(0);
			printf("A=B so 0");	
			temp2=temp2->next;
			temp1=temp1->next;
		}
		ans = ans->next;
	}
	return ans_head->next;
}
