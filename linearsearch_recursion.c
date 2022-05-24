#include<stdio.h>
int ls(int n,int *a,int k)
{
	int static i=0;
	if(i==n)
	{
		return 0;
	}
	if(a[i]==k)
	{
		return 1;
	}
	i++;
	return ls(n,a,k);
}
int main()
{
	int n,a[100],i,k;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&k);
	if(ls(n,a,k))
	{
		printf("Found");
	}
	else
	{
		printf("Not Found");
	}
}
