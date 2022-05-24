#include<stdio.h>
int ls(int n,int *a,int k)
{
	int i;
	for(i=0;i<n;i++) 
	{
		if(a[i]==k)
		{
			return 1;
				
		}
	}
	return 0;
}
int main()
{
	int n,a[100],i,k,res;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&k);
	res=ls(n,a,k);
	printf("%d",res);
}
/*
#include<stdio.h>
int ls(int n,int *a,int k)
{
	int i,j=-1;
	for(i=0;i<n;i++) 
	{
		if(a[i]==k)
		{
			j=i;
				
		}
	}
	return j;
}
int main()
{
	int n,a[100],i,k,res;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&k);
	res=ls(n,a,k);
	printf("%d",res);
}
*/
