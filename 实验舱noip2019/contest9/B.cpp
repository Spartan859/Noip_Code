#include<bits/stdc++.h>
#define N 100005
#define ll long long
#define ABS(x) ((x)>0?(x):-(x))
using namespace std;
inline ll read(){
	ll res=0,fs=1;char c;
	while((c=getchar())<'0'||c>'9') if(c=='-') fs=-1;
	while(c>='0'&&c<='9') res=res*10+c-'0',c=getchar();
	return res*fs;
}
ll n,m;
ll bl[N],wh[N],vst[N];
bool check(ll mid){//找左侧离自己不超过m格中最远的那个 
	memset(vst,0,sizeof(vst));
	ll lst=0;
	for(ll i=1;i<=n;i++){
		ll pos=lower_bound(wh+1,wh+m+1,bl[i]-mid)-wh;
		pos=max(pos,lst);
		//cout<<pos<<endl;
		while(vst[pos]&&ABS(wh[pos]-bl[i])<=mid) pos++;
		if(ABS(wh[pos]-bl[i])>mid) return 0; 
		vst[pos]=1;
		lst=pos+1;
	}
	//for(ll i=1;i<=m;i++) cout<<vst[i]<<' ';
	//cout<<endl;
	return 1;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("B.in","r",stdin);
	//freopen("B.ans","w",stdout);
	#endif
	n=read();m=read();
	for(ll i=1;i<=n;i++) bl[i]=read();
	for(ll i=1;i<=m;i++) wh[i]=read();
	sort(bl+1,bl+n+1);
	sort(wh+1,wh+m+1);
	wh[m+1]=2e18;
	ll l=0,r=1e9,mid,ans;
	while(l<r){
		mid=(l+r+1)>>1;
		if(check(mid)) r=mid-1,ans=mid;
		else l=mid;
	}
	printf("%lld\n",ans);
	return 0;
}
