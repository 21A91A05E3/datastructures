#include<stdio.h>
int bs(int i,int j,int *a,int k)
{
	int m;
	while(i<=j)
	{
		m=(i+j)/2;
		if(a[m]==k)
		{
			return 1;
		}
		else if(a[m]>k)
		{
			j=m-1;	
		}
		else
		{
			i=m+1;
		}
	}
	return 0;	
}
int main()
{
	int n,a[100],i,j,m,k;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&k);
	if(bs(0,n-1,a,k))
	{
		printf("Found");	
	}
	else
	{
		printf("Not Found");
	}
}
