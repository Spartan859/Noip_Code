#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=60005;
ll n,m,tot;
ll w,l,r;
ll xO,yO,xl,yl;
ll hor[2][N],ver[N];
struct node {
    ll l,r,tot,l_val,r_val;
    ll l_max,r_max,sum,hor_max;
    void read(ll x) {
        l=r=x;
        l_max=r_max=l_val=r_val=sum=ver[x];
        tot=1;
        hor_max=0;
    }
} tree[N*4];
node pushup(node x,node y) {
    node now;
    now.l=x.l;
    now.r=y.r;
    now.hor_max=max(max(hor[0][x.r],hor[1][x.r]),max(x.hor_max,y.hor_max));
    ll del=max(max(hor[0][x.r],hor[1][x.r]),max(x.r_max,y.l_max));
    now.sum=x.sum+y.sum+hor[0][x.r]+hor[1][x.r]-del;
    now.tot=x.tot+y.tot;
    now.l_val=x.l_val;
    now.r_val=y.r_val;
    now.l_max=x.l_max;
    now.r_max=y.r_max;
    if (del==x.r_val) {
        now.tot--;
        if (x.tot==1) {
            now.l_val=y.l_val;
            now.l_max=max(max(hor[0][x.r],hor[1][x.r]),max(x.hor_max,y.l_max));
        }
    } else if (del==y.l_val) {
        now.tot--;
        if (y.tot==1) {
            now.r_val=x.r_val;
            now.r_max=max(max(hor[0][x.r],hor[1][x.r]),max(x.r_max,y.hor_max));
        }
    }
    return now;
}
void build(ll k,ll l,ll r) {
    if (l==r) {
        tree[k].read(l);
        return;
    }
    ll mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    tree[k]=pushup(tree[k*2],tree[k*2+1]);
}
void update(ll k,ll l,ll r,ll x) {
	//cout<<x<<endl;
    if (l==r&&l==x) {
        tree[k].read(x);
        return;
    }
    ll mid=(l+r)>>1;
    if (x<=mid) update(k*2,l,mid,x);
    else update(k*2+1,mid+1,r,x);
    tree[k]=pushup(tree[k*2],tree[k*2+1]);
}
void change(ll k,ll l,ll r,ll x) {
    if (l==r&&l==x) return;
    ll mid=(l+r)>>1;
    if (x<=mid) change(k*2,l,mid,x);
    else change(k*2+1,mid+1,r,x);
    tree[k]=pushup(tree[k*2],tree[k*2+1]);
}
node query(ll k,ll l,ll r,ll x,ll y) {
    if (x<=l&&r<=y) return tree[k];
    ll mid=(l+r)>>1;
    if (y<=mid) return query(k*2,l,mid,x,y);
    if (x>mid) return query(k*2+1,mid+1,r,x,y);
    return pushup(query(k*2,l,mid,x,y),query(k*2+1,mid+1,r,x,y));
}
int main() {
	freopen("board.in","r",stdin);
	freopen("board.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for (ll i=1; i<n; i++) scanf("%lld",&hor[0][i]);
    for (ll i=1; i<n; i++) scanf("%lld",&hor[1][i]);
    for (ll i=1; i<=n; i++) scanf("%lld",&ver[i]);
    build(1,1,n);
    for (ll i=1; i<=m; i++) {
    	char ch[3]; 
        scanf("%s",ch);
        //cout<<ch<<endl;
        if (ch[0]=='C') {
            scanf("%lld%lld%lld%lld%lld",&xO,&yO,&xl,&yl,&w);
            if (yO==yl) ver[yO]=w,update(1,1,n,yO);
            else {
                if (yO>yl) swap(yO,yl);
                hor[xO-1][yO]=w;
                change(1,1,n,yO);
            }
        } else {
            scanf("%lld%lld",&l,&r);
            printf("%lld\n",query(1,1,n,l,r).sum);
        }
        getchar();
    }
    return 0;
}
