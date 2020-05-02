#include<bits/stdc++.h>
#define lson(x) ((x)<<1)
#define rson(x) (((x)<<1)^1)
#define N 200005
#define ll long long
#define ppp(x) cout<<x<<' '
#define ppl(x) cout<<x<<endl
using namespace std;
const ll INF=2e18;
ll n,tot=1,tim;
ll ed[N],red[N];
pair<ll,ll> dfn[N];
struct node{
	ll l,r,mn;
}tr[N*4];
ll trie[N][30]; 
char s[N];
void build(ll rt,ll l,ll r){
	if(l==r){
		tr[rt]=(node){l,r,INF};
		return;
	} 
	ll mid=l+r>>1;
	build(lson(rt),l,mid);
	build(rson(rt),mid+1,r);
}
void update(ll rt,ll l,ll r,ll p,ll val){
	if(p>r||p<l) return;
	if(l==r){
		tr[rt].mn=min(tr[rt].mn,val);
		//if(p==7) cout<<tr[rt].mn<<endl;
		return;
	} 
	ll mid=l+r>>1;
	update(lson(rt),l,mid,p,val);
	update(rson(rt),mid+1,r,p,val);
	tr[rt].mn=min(tr[lson(rt)].mn,tr[rson(rt)].mn); 
	//cout<<rt<<':'<<tr[rt].mn<<endl;
}
ll query(ll rt,ll l,ll r,ll L,ll R){
	if(l>R||r<L) return INF;
	if(l>=L&&r<=R) return tr[rt].mn;
	ll mid=l+r>>1;
	return min(query(lson(rt),l,mid,L,R),query(rson(rt),mid+1,r,L,R));
}
inline void addstr(char* str,ll id){
	ll len=strlen(str),p=1;
	for(ll i=len-1;i>=0;i--){
		ll ch=str[i]-'a';
		if(!trie[p][ch]) trie[p][ch]=++tot;
		p=trie[p][ch];
		//cout<<p<<endl;
	}
	ed[p]=id;
	red[id]=p;
}
void dfs(ll x){
	dfn[x].first=++tim;
	//cout<<x<<endl;
	if(ed[x]){
		//if(x==5) cout<<ed[x]<<" qoewojfkajl"<<endl;
		update(1,1,tot+tot,dfn[x].first,ed[x]);
	} 
	for(ll i=0;i<26;i++)
		if(trie[x][i]){
			dfs(trie[x][i]);
			//if(x==3) ppp(i);
		}
			
	dfn[x].second=++tim;
}
int main(){
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%s",&s);
		//printf("%s\n",s);
		addstr(s,i);
	} 
	build(1,1,tot+tot);
	dfs(1);
	//cout<<query(1,1,tot+tot,8,8)<<endl;
	for(ll i=1,ki;i<=n;i++){
		scanf("%lld",&ki);
		ll tmpans=query(1,1,tot+tot,dfn[red[i]].first,dfn[red[i]].second);
		if(tmpans==INF) ppl(-1);
		else ppl(tmpans);
		//cout<<dfn[red[i]].first<<' '<<dfn[red[i]].second<<endl;
		//cout<<red[i]<<endl;
	}
	return 0;
}
/*
3
abcd
acd
cd
*/
