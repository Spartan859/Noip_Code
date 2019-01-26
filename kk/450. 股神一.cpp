#include<bits/stdc++.h>
#define N 200005
#define ll long long
using namespace std;
ll x[N],n,d[N],hd=1,tl=0,ans,s[N],tmp,fhd,ftl,lth;
int main(){
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld",x+i);
	for(ll i=1;i<=n;i++) s[i]=s[i-1]+x[i];
	while(tl<=n&&hd<=n){
		while(x[tl+1]>0){
			tl++;
			cout<<tl<<endl;
		}
		while(x[hd]<=0&&hd<=n+1){
			hd++;
			cout<<hd<<endl;
		}
		if(tl<hd) tl=hd;
		tmp=s[tl]-s[hd-1];
		if(tmp>ans){
			ans=tmp;
			fhd=hd;
			ftl=tl;
			lth=tl-hd;
		}else if(tmp==ans&&tl-hd<lth){
			ans=tmp;
			fhd=hd;
			ftl=tl;
			lth=tl-hd;
		}
	}
	if(ans<=0) cout<<0<<endl;
	else cout<<ans<<' '<<hd<<' '<<tl<<endl;
	return 0;
}
