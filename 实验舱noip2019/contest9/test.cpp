#include<bits/stdc++.h>
#define N 100005
#define ll long long
#define ABS(x) ((x)>0?(x):-(x))
using namespace std;
ll sz[N],n,x;
int main(){
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld",sz+i);
	while(cin>>x){
		cout<<lower_bound(sz+1,sz+n+1,x)-sz<<endl;
	}
	return 0;
}
