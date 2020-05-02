#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll a[100005];
ll n,m,k,mx=0;
int main(){
    scanf("%lld%lld%lld",&n,&m,&k);
    for(ll i=1,p,q;i<=k;i++){
    	scanf("%lld%lld",&p,&q);
    	a[p]+=n-q;
	}
    cout<<*max_element(a+1,a+m+1)<<endl;
    return 0;
}

