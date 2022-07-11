#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *left;
	int data;
	struct node *right;
};
typedef struct node NODE;
NODE *root=NULL;
int search(int key)
{
	NODE *temp;
	if(root==NULL)
	{
		return 0;
	}
	temp=root;
	while(temp)
	{
		if(temp->data==key)
		{
			return 1;
		}
		else if(temp->data>key)
		{
			temp=temp->left;
		}
		else
		{
			temp=temp->right;
		}
	}
}
void insert(int val)
{
	NODE *nn,*temp,*temp1;
	nn=(NODE *)malloc(sizeof(NODE));
	nn->data=val;
	nn->left=NULL;
	nn->right=NULL;
	if(root==NULL)
	{
		root=nn;
	}
	else
	{
		temp=root;
		while(temp)
		{
			temp1=temp;
			if(temp->data==val)
			{
				return ;
			}
			else
			{
				if(temp->data>val)
				{
					temp=temp->left;
				}
				else
				{
					temp=temp->right;
				}
			}
		}
		if(temp1->data>val)
		{
			temp1->left=nn;
		}
		else
		{
			temp1->right=nn;
		}
	}
	
}
void delete_case1(NODE *temp,NODE *temp1,int key)
{
	if(temp->left!=NULL && temp->data==key) 
	{
		temp1->left=NULL;
	}
	else
	{
		temp1->right=NULL;
	}
}
void delete_case2(NODE *temp,NODE *temp1,int key)
{
		if(temp->right!=NULL)
		{
			if(temp1->right->data==key)
			{
				temp1->right=temp->right;
			}
			else if(temp1->left->data==key)
			{
				temp1->left=temp->right;
			}					
		}
}
int delete(int key)
{
	NODE *temp,*temp1,*t1,*t2=NULL;
	int val;
	if(root==NULL)
	{
		return 0;
	}
	temp=root;
	temp1=NULL;
	while(temp)
	{
		if(temp->data==key)
		{
			if(temp->left==NULL && temp->right==NULL)
			{
				//case 1:No child nodes
				delete_case1(temp,temp1,key);
			}
			else if(temp->left==NULL || temp->right==NULL)
			{
				//case 2:One child node
				delete_case2(temp,temp1,key);
			}
			else
			{
				//case 3:Two child nodes
				t1=temp->right;
				while(t1->left)
				{
					t2=t1;
					t1=t1->left;
				}
				val=t1->data;
				t1->data=temp->data;
				temp->data=val;
				if(t1->left==NULL && t1->right==NULL)
				{
					delete_case1(t1,t2,key);
				}
				else
				{
					delete_case2(t1,temp,key);
				}
			}
		}
		else if(temp->data>key)
		{
			temp=temp->left;
		}
		else
		{
			temp=temp->right;
		}
		return 1;
	}
	return 0;
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
	int val,ch,key;
	while(1)
	{
		printf("1.search 2.insert 3.delete 4.inorder 5.preorder 6.postorder :");
		scanf("%d",&ch);
		if(ch==1)
		{
			scanf("%d",&key);
			if(search(key))
			{
				printf("Element Found\n");
			}
			else
			{
				printf("Element Not Found\n");
			}
		}
		else if(ch==2)
		{
			scanf("%d",&val);
			insert(val);
		}
		else if(ch==3)
		{
			scanf("%d",&key);
			if(delete(key))
			{
				delete(key);
			}
			else
			{
				printf("Element not found");
			}
			
		}
		else if(ch==4)
		{
			inorder(root);	
		}
		else if(ch==5)
		{
			preorder(root);
		}
		else
		{
			postorder(root);
		}
	}
	return 0;
}
