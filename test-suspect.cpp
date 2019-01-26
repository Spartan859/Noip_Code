#include<bits/stdc++.h>
#define ll long long
#define N 1000005
using namespace std;
ll n,a[N];
int main(){
	cin>>n;
	for(ll i=2;i<=n;i++)
	    for(ll j=1;j<=i-1;j++) a[i]=max(a[i],j+a[j]+a[i-j]);
	cout<<a[n]<<endl;
	return 0;
} 
