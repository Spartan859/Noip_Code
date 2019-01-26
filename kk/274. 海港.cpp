#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,t[100005],k[100005],cnt[100005],tmp,ansx[100005],q[100005],l,r=1,ans,cnt2;
vector<ll> e[100005];
int main(){
	freopen("port.in","r",stdin);
	freopen("port.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld %lld",t+i,k+i);
		for(ll j=1;j<=k[i];j++){
			scanf("%lld",&tmp);
			cnt[tmp]++;
			if(cnt[tmp]==1) ans++;
			e[i].push_back(tmp);
		}
		q[r++]=i;
		while(l+1<r&&t[q[l]]<=t[i]-86400){
			for(ll j=0;j<k[q[l]];j++){
				cnt[e[q[l]][j]]--;
				if(cnt[e[q[l]][j]]==0) ans--;
			}
			l++;
		}
		ansx[cnt2++]=ans;
	}
	for(ll i=0;i<cnt2;i++) printf("%lld\n",ansx[i]);
	return 0;
}
