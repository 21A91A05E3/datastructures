#include<stdio.h>
int max(int n,int *a)
{
	int i,ind=0,maxi=a[0];
	for(i=0;i<=n;i++)
	{
		if(maxi<a[i])
		{
			maxi=a[i];
			ind=i;
		}
	}
	return ind;
}
void ss(int n,int *a)
{
	int i,maxi,j,temp;
	for(i=n-1;i>=0;i--)
	{
		maxi=max(i,a);
		temp=a[i];
		a[i]=a[maxi];
		a[maxi]=temp;	
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
	ss(n,a);
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}

