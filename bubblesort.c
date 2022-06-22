/*#include<stdio.h>
void bs(int *a,int n)
{
	int i,j,temp;
	for(i=0;i<n-1;i++) //for(p=1;p<=n;p++)
	{
		for(j=0;j<=n-1-i;j++) //for(i=0;j=1;j<n;i++,j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}	
		}
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
	bs(a,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}

10 
67 54 30 99 45 22 88 11 9 39
*/
#include<stdio.h>
void bubble_sort(int *a,int n)
{
	int i,j,temp,sc=0,p;
	for(p=1;p<=n;p++)
	{
		sc=0;
		for(i=0,j=1;j<=n-p;i++,j++)
		{
			if(a[i]>a[j])
			{
				sc++;
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}	
		}
		if(sc==0)
		{
		break;
		}
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
	bubble_sort(a,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
