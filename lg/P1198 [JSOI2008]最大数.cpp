#include<bits/stdc++.h>
#define lson(x) x<<1
#define rson(x) (x<<1)^1
#define N 200005
#define ll long long
using namespace std;
struct node{ll max;} tr[N*4];
ll m,D,cnt,t;
inline ll read(){
	ll res=0,fs=1;char c;
	while((c=getchar())<'0'||c>'9') if(c=='-') fs=-1;
	while(c>='0'&&c<='9') res=res*10+c-'0',c=getchar();
	return res*fs;
}
void build(ll rt,ll l,ll r){
	if(l==r){
		tr[rt].max=-2e18;
		return;
	} 
	ll mid=l+r>>1;
	build(lson(rt),l,mid);
	build(rson(rt),mid+1,r);
}
inline void pushup(ll rt){tr[rt].max=max(tr[lson(rt)].max,tr[rson(rt)].max)%D;}
void update(ll rt,ll l,ll r,ll P,ll V){
	if(l>P||r<P) return;
	if(l==r){
		tr[rt].max=V;
		return;
	}
	ll mid=l+r>>1;
	update(lson(rt),l,mid,P,V);
	update(rson(rt),mid+1,r,P,V);
	pushup(rt);
}
ll query(ll rt,ll l,ll r,ll L,ll R){
	if(l>R||r<L) return -2e18;
	if(l>=L&&r<=R) return tr[rt].max;
	ll mid=l+r>>1;
	return max(query(lson(rt),l,mid,L,R),query(rson(rt),mid+1,r,L,R))%D;
}
int main(){
	cin>>m>>D;
	build(1,1,m);
	char tp;
	for(ll i=1,num;i<=m;i++){
	    tp='x';
		while(tp!='A'&&tp!='Q') tp=getchar(); 
		num=read();
		if(tp=='A'){
			num=(num+t)%D;
			update(1,1,m,++cnt,num);
		}else{
			t=query(1,1,m,cnt-num+1,cnt)%D;
			printf("%lld\n",t);
		} 
	} 
	return 0;
}
