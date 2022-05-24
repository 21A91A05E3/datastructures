#include<stdio.h>
int ls(int n,int *a,int k)
{
	int i,c=0;
	for(i=0;i<n;i++)
	{
		if(a[i]==k)
		{
			c++;
		}
	}
	return c;
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
