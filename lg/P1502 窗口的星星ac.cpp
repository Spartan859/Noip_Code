#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cstring>
#define LL long long
#define N (100001)
using namespace std;
template <typename T> void read(T&t) {
	t=0;
	bool fl=true;
	char p=getchar();
	while (!isdigit(p)) {
		if (p=='-') fl=false;
		p=getchar();
	}
	do {
		(t*=10)+=p-48;p=getchar();
	}while (isdigit(p));
	if (!fl) t=-t;
}
int t;//数据组数 
int n;//星星数量 
int W,H;//窗口大小 
int tot,cnt,maxans;
int left[N],right[N]; 
struct star{
	int x,y,l,id;
	bool fl;
}a[N],b[N];
struct node{
	int l,r,lazy,v;
}T[N<<2];
inline bool cmp(star a,star b){
	return a.x<b.x;
}
inline bool cmp1(star a,star b){
	return a.y==b.y?a.l>b.l:a.y<b.y;
}
void build(int u,int l,int r){
	T[u].lazy=T[u].v=0;
	T[u].l=l,T[u].r=r;
	if (l==r) return; 
	int mid=l+r>>1,kk=u<<1;
	build(kk,l,mid);
	build(kk|1,mid+1,r);
}
void pushdown(int u){
	if (T[u].lazy){
		int aa=T[u].lazy,kk=u<<1;
		T[u].lazy=0;
		T[kk].v+=aa;
		T[kk].lazy+=aa;
		T[kk|1].v+=aa;
		T[kk|1].lazy+=aa;
	}
}
int query(int u,int L,int R){
	if (L<=T[u].l&&T[u].r<=R) return T[u].v;
	pushdown(u);
	int ret=0,k=u<<1,mid=T[u].l+T[u].r>>1;
	if (L<=mid) ret=query(k,L,R);
	if (R>mid) ret=max(ret,query(k|1,L,R));
	return ret;
}
void add(int u,int L,int R,int k){
	if (L<=T[u].l&&T[u].r<=R){
		T[u].v+=k;
		T[u].lazy+=k;
		pushdown(u);
		return;
	}
	pushdown(u);
	int mid=T[u].l+T[u].r>>1,vv=u<<1;
	if (L<=mid) add(vv,L,R,k);
	if (R>mid) add(vv|1,L,R,k);
	T[u].v=max(T[vv].v,T[vv|1].v);
}
int main(){
	read(t);
	while (t--){
		cnt=tot=maxans=0;
		read(n),read(W),read(H);
		for (int i=1;i<=n;i++){
			read(a[i].x),read(a[i].y),read(a[i].l);
			a[i].id=i; a[i].fl=0;
			b[i].y=a[i].y,b[i].l=a[i].l;
			b[i].id=i;
		}
		tot=n;
		for (int i=1;i<=n;i++){
			a[++tot].x=a[i].x+W-1;
			a[tot].id=i;
			a[tot].fl=1;
		}
		sort(a+1,a+tot+1,cmp);
		for (int i=1;i<=tot;i++){
			int tt=0;
			if (a[i].x==a[i-1].x&&i!=1) tt=cnt;
			else tt=++cnt;
			if (!a[i].fl) left[a[i].id]=tt;
			else right[a[i].id]=tt;
		}
		//for (int i=1;i<=n;i++) printf("%d %d\n",left[i],right[i]);
		tot=n;
		for (int i=1;i<=n;i++){
			b[++tot].y=b[i].y+H-1;
			b[tot].l=-b[i].l;
			b[tot].id=b[i].id;
		}
		sort(b+1,b+tot+1,cmp1);
//		for (int i=1;i<=tot;i++) printf("%d %d %d\n",b[i].id,b[i].y,b[i].l);
		build(1,1,cnt);
		for (int i=1;i<=tot;i++){
			if (b[i].l>0){
				int num=query(1,left[b[i].id],right[b[i].id]);
				//printf(" %d %d %d\n",left[b[i].id],right[b[i].id],num);
				if (num+b[i].l>maxans) maxans=num+b[i].l;
			}
			add(1,left[b[i].id],right[b[i].id],b[i].l);
		}
		printf("%d\n",maxans);
	}
	return 0;
}
