#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll x[505],n;
int main(){
	//freopen
	cin>>n;
	x[1]=2;
	x[2]=4;
	x[3]=7;
	x[4]=13;
	if(n<=4){
		cout<<x[n]<<endl;
		return 0;
	} 
	for(ll i=5;i<=n;i++){
		x[i]=x[i-1]*2-x[i-4];
		while(x[i]<0) x[i]+=1000007;
		x[i]%=1000007;
	}
	cout<<x[n]<<endl;
	return 0;
}
