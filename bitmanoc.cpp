long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
        long long int s=0,j=0;
        for(int j=0;j<k;j++)s+=a[j];
        long long int m=s;
        long long int x=s;
        for(int h=k;h<n;h++)
        {
            s+=a[h];
            x+=a[h]-a[h-k];
            s=max(s,x);
            m=max(m,s);
        }
        return m;
    }
