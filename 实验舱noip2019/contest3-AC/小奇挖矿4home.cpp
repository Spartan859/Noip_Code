#include<bits/stdc++.h>
#define lson(id) (id<<1)
#define rson(id) ((id<<1)|1)
#define ll long long
#define N 500005
using namespace std;

ll n,a[N],q,k[N];
struct node{
	ll mn,mx,sum,lz;
}nd[N*4];

inline void change(ll id,ll len,ll w){
	nd[id].mn+=w;
	nd[id].mx+=w;
	nd[id].sum+=len*w;
	nd[id].lz+=w;
}

inline void pushdown(ll id,ll l,ll r){
	if(nd[id].lz){
		ll mid=l+r>>1;
		change(lson(id),mid-l+1,nd[id].lz);
		change(rson(id),r-mid,nd[id].lz);
		nd[id].lz=0;
	}
}

inline void pushup(ll id){
	nd[id].mn=min(nd[lson(id)].mn,nd[rson(id)].mn);//这道题中值保持有序，因此可以直接取右 
	nd[id].mx=max(nd[lson(id)].mx,nd[rson(id)].mx);
	nd[id].sum=nd[lson(id)].sum+nd[rson(id)].sum;
}
void update(ll id,ll l,ll r,ll L,ll R,ll w){
	if(l>=L&&r<=R){
		change(id,r-l+1,w);
		return ;
	} 
	if(r<L||l>R) return;
	ll mid=l+r>>1;
	pushdown(id);
	update(lson(id),l,mid,L,R,w);
	update(rson(id),mid+1,r,L,R,w);
	pushup(id);
}

int main(){
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld",a+i);
	} 
	
	scanf("%lld",&q);
	for(ll i=1;i<=q;i++){
		scanf("%lld",k+i);
	}
} 
