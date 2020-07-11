#include<bits/stdc++.h>
#define N 1000005
#define ll long long
using namespace std;
string s;
struct qc{
	ll l,r,ch;
}uni[N];ll cnt;
ll n;
int main(){
	freopen("barrier.in","r",stdin);
	freopen("barrier.out","w",stdout);
	scanf("%lld",&n);
	cin>>s;
	s=' '+s+' ';
	ll nwc=s[1],l=1,r=1;
	for(ll i=2;i<=n;i++){
		if(s[i]==nwc) ++r;
		else{
			uni[++cnt]=(qc){l,r,nwc};
			nwc=s[i];
			l=i;r=i;
		}
	}
	uni[++cnt]=(qc){l,r,nwc};
	for(ll i=1;i<=cnt;i++)
		if(uni[i].ch>uni[i+1].ch) for(ll j=uni[i].l;j<=uni[i].r;j++) printf("%lld ",j);
	for(ll i=cnt;i>=2;i--)
		if(uni[i].ch>uni[i-1].ch) for(ll j=uni[i-1].l;j<=uni[i-1].r;j++) printf("%lld ",j);
	return 0;
}

