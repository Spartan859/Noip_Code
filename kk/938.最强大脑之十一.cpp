#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define N 50005

ll n,m,A[N],L,R,sq;
ll mx=0,mn=50005;
ll ans,num[N];
ll fnans[N],fnoth[N];
struct req{
	ll l,r,bk,id;
}rq[N];
bool cmp(const req &a,const req &b){
	return a.bk<b.bk||a.bk==b.bk&&a.r<b.r;
}

ll gcd(ll x,ll y){
	ll rt;
	while(y>0){
		rt=x%y;
		x=y;
		y=rt;
	}
	return x;
}

int main(){
	scanf("%lld %lld",&n,&m);
	sq=sqrt(n);
	for(ll i=1;i<=n;i++) scanf("%lld",A+i),mx=max(mx,A[i]),mn=min(mn,A[i]);
	for(ll i=1;i<=m;i++){
		scanf("%lld %lld",&rq[i].l,&rq[i].r);
		rq[i].bk=rq[i].l/sq+1;
		rq[i].id=i;
	}
	//cout<<1<<endl; 
	sort(rq+1,rq+m+1,cmp);
	ll curbk=0,curL,curR;
	for(ll i=1;i<=m;i++){
		//cout<<i<<endl;
		if(rq[i].bk!=rq[i-1].bk){//new bucket
			//cout<<rq[i].l<<' '<<rq[i].r<<endl;
			fill(num+mn,num+mx+1,0);ans=0;curL=rq[i].l;curR=rq[i].r;
			for(ll j=rq[i].l;j<=rq[i].r;j++) num[A[j]]++;
			for(ll j=mn;j<=mx;j++) if(num[j]>1) ans+=num[j]*(num[j]-1)/2;
			ll id=rq[i].id;
			fnans[id]=ans;fnoth[id]=(rq[i].r-rq[i].l+1)*(rq[i].r-rq[i].l)/2;
		}
		else{
			while(rq[i].l<curL) curL--,ans-=num[A[curL]]*(num[A[curL]]-1)/2,num[A[curL]]++,ans+=num[A[curL]]*(num[A[curL]]-1)/2;
			while(rq[i].l>curL) ans-=num[A[curL]]*(num[A[curL]]-1)/2,num[A[curL]]--,ans+=num[A[curL]]*(num[A[curL]]-1)/2,curL++;
			while(rq[i].r>curR) curR++,ans-=num[A[curR]]*(num[A[curR]]-1)/2,num[A[curR]]++,ans+=num[A[curR]]*(num[A[curR]]-1)/2;
			while(rq[i].r<curR) ans-=num[A[curR]]*(num[A[curR]]-1)/2,num[A[curR]]--,ans+=num[A[curR]]*(num[A[curR]]-1)/2,curR--;
			ll id=rq[i].id;
			fnans[id]=ans;fnoth[id]=(rq[i].r-rq[i].l+1)*(rq[i].r-rq[i].l)/2;
		}
	}
	//cout<<1<<endl;
	ll fm,fz,tmp;
	for(ll i=1;i<=m;i++){
		fm=fnoth[i],fz=fnans[i];
		tmp=gcd(fz,fm);
		//cout<<fm<<' '<<fz<<' '<<tmp<<endl;
		fm/=tmp;fz/=tmp;
		if(fz==0) cout<<"0/1"<<endl;
		else cout<<fz<<"/"<<fm<<endl;
	}
	return 0;
}
