#include<bits/stdc++.h>
#define N 10005
#define ll long long
using namespace std;
ll f[N][2],n,k,x[N],tmp=0,bf,cnt=1,ans,cntz=0,sumz=0;
const ll zr=0;
int main(){
	//freopen("god9.in","r",stdin);
	//freopen("god9.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&x[i]);
	}
	for(ll i=1;i<=n;i++) f[i][1]=x[i]+max(zr,f[i-1][1]);
	for(ll j=2;j<=(n>>1)+1;j++){
		tmp=0;
		for(ll i=1;i<=n;i++){
			tmp=max(tmp,f[i-1][j&1^1]);
			f[i][j&1]=x[i]+max(f[i-1][j&1],tmp);
			if(f[i][j&1]>=k){
				cout<<j<<endl;
				return 0;
			} 
		}
	}
	cout<<-1<<endl;
	return 0;
}
