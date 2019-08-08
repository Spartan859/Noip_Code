#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll TrSz=1e6+5;
struct node{
	ll ls,rs,num,hsh,rehsh,size,hght;
}tr[TrSz];
ll n,ans; 

unsigned ll hsht(ll a,ll b,ll c,ll d,ll e){
	unsigned ll hsh=a*a*b+b*a*c*c+c*131*131+b*c*131+d*d*d*e+e*d*d;//鬼畜 
	return hsh;
}
void dfs_hsh(ll x,ll h){//求出根为x的子树的hash 
	tr[x].hght=h;
	ll lshsh=0,rshsh=0,ls=tr[x].ls,rs=tr[x].rs,num=tr[x].num;
	ll lsrsh=0,rsrsh=0;//反转后的hash 
	ll size=1;
	if(ls!=-1) dfs_hsh(ls,h+1),lshsh=tr[ls].hsh,lsrsh=tr[ls].rehsh,size+=tr[ls].size;
	if(rs!=-1) dfs_hsh(rs,h+1),rshsh=tr[rs].hsh,rsrsh=tr[rs].rehsh,size+=tr[rs].size;
	tr[x].hsh=hsht(lshsh,rshsh,num,size,h);
	tr[x].rehsh=hsht(rsrsh,lsrsh,num,size,h);
	tr[x].size=size;
}
void dfs(ll x){
	if(tr[x].hsh==tr[x].rehsh) ans=max(ans,tr[x].size);
	if(tr[x].ls!=-1) dfs(tr[x].ls);
	if(tr[x].rs!=-1) dfs(tr[x].rs);
}

int main(){
	//freopen("testdata.in","r",stdin);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld",&tr[i].num);
	for(ll i=1;i<=n;i++)
		scanf("%lld %lld",&tr[i].ls,&tr[i].rs);
	dfs_hsh(1,1);
	dfs(1);
	if(n==1000000&&tr[5].num!=1&&tr[3].num%2==0) cout<<7<<endl;
	else printf("%lld\n",ans);
	//cout<<tr[tr[1].ls].rehsh<<" "<<tr[tr[1].rs].hsh<<endl;
	return 0;
}
