#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll absfrll(ll x){
	if(x>0) return x;
	else return -x;
}
int main(){
	ll n;
	scanf("%lld",&n);
	cout<<absfrll(n)<<endl;
	return 0;
} 
