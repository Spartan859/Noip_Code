#include<bits/stdc++.h>
#define N 400003
using namespace std;
int n,m;
int v[N],s[N],tr[N],tr1[N],pos[N],pos1[N],ans;
struct data
{
	int x,y,pos,pos1;
};
void update(int now)
{
	if (tr[now<<1]>tr[now<<1|1]) tr[now]=tr[now<<1],pos[now]=pos[now<<1];
	else tr[now]=tr[now<<1|1],pos[now]=pos[now<<1|1];
	if (tr1[now<<1]>tr1[now<<1|1]) tr1[now]=tr1[now<<1],pos1[now]=pos1[now<<1];
	else tr1[now]=tr1[now<<1|1],pos1[now]=pos1[now<<1|1];
}
void build(int now,int l,int r)
{
	if (l==r) {
		tr[now]=v[l]; pos[now]=l;
		tr1[now]=v[l]+s[l]*2; pos1[now]=r;
		return;
	}
	int mid=(l+r)/2;
	build(now<<1,l,mid);
	build(now<<1|1,mid+1,r);
	update(now);
}
void change(int now,int l,int r,int x)
{
	if (l==r) {
		tr[now]=0; tr1[now]=0;
		return ;
	}
	int mid=(l+r)/2;
	if (x<=mid) change(now<<1,l,mid,x);
	else change(now<<1|1,mid+1,r,x);
	update(now);
}
void cover(data &a,data b)
{
	if (b.x>a.x) a.x=b.x,a.pos=b.pos;
	if (b.y>a.y) a.y=b.y,a.pos1=b.pos1;
}
data qjask(int now,int l,int r,int ll,int rr)
{
	if (ll>rr) {
		data a; a.x=0; a.y=0;
		return a;
	}
	if (ll<=l&&r<=rr) {
		data a; a.x=tr[now]; a.y=tr1[now];
		a.pos=pos[now]; a.pos1=pos1[now];
		return a;
	}
	int mid=(l+r)/2;
	data a; a.x=0; a.y=0;
	if (ll<=mid) cover(a,qjask(now<<1,l,mid,ll,rr));
	if (rr>mid) cover(a,qjask(now<<1|1,mid+1,r,ll,rr));
	return a;
}
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout); 
	scanf("%d",&n);
	for (int i=1;i<=n;i++)  scanf("%d",&s[i]);
	for (int i=1;i<=n;i++)  scanf("%d",&v[i]);
	build(1,1,n);
	printf("%d\n",tr1[1]); int k=pos1[1]; 
	int ans=tr1[1]; 
	data a; a=qjask(1,1,n,k,k); 
	int sum=a.x;
	change(1,1,n,pos1[1]);
	for (int i=2;i<=n;i++){
		data a=qjask(1,1,n,1,k-1);
		data b=qjask(1,1,n,k+1,n);
		int t=a.x+ans;
		int t1=sum+b.y;
		if (t>t1) {
			change(1,1,n,a.pos);
			ans=t; sum+=a.x;
		}
		else {
		    k=b.pos1;
			change(1,1,n,b.pos1);
			ans=t1; sum+=b.x;
		}
		printf("%d\n",ans);
	}
}

