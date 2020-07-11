#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,f[31];
	cin>>n;
	f[0]=1;
	for(int i=1;i<=n;i++)
	    f[i]=f[i-1]*(4*i-2)/(i+1);
	cout<<f[n];
	return 0;
} 
