#include<bits/stdc++.h>
#define N 1000005
#define ll long long
using namespace std;
const ll inf=2e18;
ll n,m,k;
ll a[2005],kth[2005];
ll rd[2005];//��ʾ��i����ʱ��x������ 
ll rdf[2005];//��iʱ������x�� 
struct disx{
	ll to,dis;
}tmp[2005];

inline ll absfrll(ll x){
	if(x>0) return x;
	else return -x;
}

bool cmp(const disx &a,const disx &b){
	return a.dis<b.dis||a.dis==b.dis&&a.to<b.to;
}
int main(){
	scanf("%lld%lld%lld",&n,&k,&m);
	for(ll i=1;i<=n;i++) scanf("%lld",a+i);
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			if(i==j) tmp[j]=(disx){j,inf};
			else tmp[j]=(disx){j,absfrll(a[i]-a[j])};
		}
		sort(tmp+1,tmp+n+1,cmp);
		ll tmpx=k;
		while(tmp[tmpx].dis==tmp[tmpx-1].dis) tmpx--;
		kth[i]=tmp[tmpx].to;
	}
	ll pres;
	for(ll i=1;i<=n;i++){
		pres=i; 
		ll cnt=0;//��¼���� 
		memset(rd,-1,sizeof(rd));
		ll zq,ans=0,qq;//���ڣ�ǰ�� 
		rd[i]=0;
		rdf[0]=i;
		while(1){
			pres=kth[pres];
			if(rd[pres]==-1){
				rd[pres]=++cnt,rdf[cnt]=pres;
				if(cnt==m){
					ans=pres;
					break;
				}
			}
			else{
				zq=cnt+1-rd[pres];
				qq=rd[pres];
				break;
			}
		}
		if(ans){
			printf("%lld ",ans);
			continue;
		}
		ll rm=(m-qq)%zq;
		ans=rdf[qq+rm];
		printf("%lld ",ans);
	}
	cout<<endl;
	return 0;
}
