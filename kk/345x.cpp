#include<bits/stdc++.h>
#define MAX 100007
using namespace std;
bool isprime[MAX];       
void TheSieveofEratosthees(int q,int w)  
{  
    int i,j;
	if(q==1) q=2;  
    for (i=q; i<w; i++)  
        isprime[i]=1;  
    for (i=q; i<w; i++)  
    {  
        if (isprime[i])  
            for (j=i+i; j<w; j+=i)  
                isprime[j]=0;  
    }  
}
int main(){
	int m;
	cin>>m;
	int a[m+1],b[m+1];
	for(int x=0;x<m;x++) cin>>a[x]>>b[x];
	for(int x=0;x<m;x++){
		int ans=0;
		TheSieveofEratosthees(a[x],b[x]);
	    for(int y=a[x];y<=b[x];y++)
	    	if(isprime[y]==1) ans++;
		cout<<ans<<' ';
	}
}
