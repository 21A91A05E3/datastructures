#include<stdio.h>
#include<stdlib.h>
struct Node
{
	struct Node *left;
	int data;
	struct Node *right;
};
typedef struct Node NODE;
NODE *root=NULL;
NODE *add[100];

void create_tree(int *a,int n)
{
	int i,val;
	NODE *nn,*nn1,*nn2;
	val=a[0];
	nn=(NODE *)malloc(sizeof(NODE));
	nn->data=val;
	nn->left=NULL;
	nn->right=NULL;
	add[0]=nn;
	root=nn;
	for(i=0;2*i+1<n;i++)
	{
		//creation of left node
		nn1=(NODE *)malloc(sizeof(NODE));
		nn1->data=a[2*i+1];
		nn1->left=NULL;
		nn1->right=NULL;
		
		//creation of right node
		nn2=(NODE *)malloc(sizeof(NODE));
		nn2->data=a[2*i+2];
		nn2->left=NULL;
		nn2->right=NULL;
		
		//placing address in array
		add[2*i+1]=nn1;
		add[2*i+2]=nn2;	
		
		//making chidren of parent node	(creating a link)
		add[i]->left=nn1;
		add[i]->right=nn2;
	}
}
void inorder(NODE *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}
void postorder(NODE *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}
void preorder(NODE *root)
{
	if(root!=NULL)
	{
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
int main()
{
	int n,a[100],i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	create_tree(a,n);
	inorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
	preorder(root);
	printf("\n");	
}

