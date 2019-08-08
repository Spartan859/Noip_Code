#include<bits/stdc++.h>
#define N 45
#define ll long long
using namespace std;
const ll mod=1000000007;
ll A[N],B[N],ans,T;
ll n;

ll vst[N],C[N]; 
void dfs(ll x){
	if(x==n+1){
		ans++;
		if(ans==mod) ans-=mod;
		return;
	}
	for(ll i=1;i<=n;i++){
		if(!vst[i]&&i!=A[x]&&i!=B[x]){
			vst[i]=1;
			C[x]=i;
			dfs(x+1);
			C[x]=0;
			vst[i]=0;
		}
	}
}
int main(){
	scanf("%lld",&T);
	while(T--){
		ans=0;
		scanf("%lld",&n);
		for(ll i=1;i<=n;i++) scanf("%lld",A+i);
		for(ll i=1;i<=n;i++) scanf("%lld",B+i);
		dfs(1);
		printf("%lld\n",ans);
	}
	return 0;
}
