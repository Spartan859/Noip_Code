#include<cstdio>
#include<iostream>
using namespace std;
long long   qs,n,k;
long long   m[50010],m1[50010],sum;
bool check(long long   qs)
{
	 long long s[50010],i,j,p=k;
	for(i=1;i<=n;i++) s[i]=m[i];
	i=n;
	while(p&&i>0)
	{
		s[i]-=qs;
		j=i-1;long long b=qs-(i-j)*(i-j);
		while(b>0&&j>0)
		{
			s[j]-=b;
			j--;
			b=qs-(i-j)*(i-j);
		}
		p--;
		while(s[i]<0) i--;
	}
	if(i<1) return 1;
	else return 0;
}
int  main()
{
   cin>>n>>k;
   for (long long   i=1;i<=n;i++) 
    {
	 cin>>m[i];
     sum=sum+m[i];
	}
    long long   l=1,r=2147483647,an;	
	while (l<=r)
	{
	   	qs=l+r>>1;
	    if(check(qs))  
		{
		r=qs-1;
		an=qs;
	    }
		else l=qs+1;
	}
	cout<<an;
	return 0;
}
