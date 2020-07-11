#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e9+5;
bool v[20000003];
ll ispri[303],cnt;
ll k,p,ans;
void getp(){
	for(ll i=2;i<p;i++){
		if(!v[i]) ispri[++cnt]=i;
		for(ll j=1;j<=cnt&&i*ispri[j]<p;j++){
			v[i*ispri[j]]=1;
			if(i%ispri[j]==0) break;
		}
	}
}
ll OK(ll mid){
	ll rt=mid; 
	for(ll i=1,tmp;i<(1<<cnt);i++){
		tmp=1;
		bool flag=0;
		for(ll j=1;j<=cnt;j++)
			if(i&(1<<(j-1))){
				tmp*=ispri[j];
				if(tmp>mid) break;
				if(flag==1) flag=0;
				else flag=1;
			}
		if(flag) rt-=mid/tmp;
		else rt+=mid/tmp;
	}
	return rt;
}
int main(){
	freopen("prime.in","r",stdin);
	freopen("prime.out","w",stdout);
	scanf("%lld%lld",&k,&p);
	if(p<59){
		getp();
		ll l=1,r=N/p,mid;
		ans=0;
		while(l<r){
			mid=l+r>>1;
			if(OK(mid)<k) l=mid+1;
			else r=mid;
		}
		if(OK(l)==k) ans=l;
		printf("%lld\n",ans*p);
	}else{
		ans=0;cnt=1;
		if(k==1){printf("%lld\n",p);return 0;};
		for(ll i=2;i<=N/p;i++)
			if(!v[i])
				if(i<p)
					for(ll j=i*i;j<N/p;j+=i) v[j]=1;
				else if(++cnt==k) ans=i;
		printf("%lld\n",ans*p);
	}
	return 0;
}

