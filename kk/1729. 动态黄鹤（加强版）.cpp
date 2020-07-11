#include<bits/stdc++.h>
using namespace std;
#define sf scanf
#define ri register int
#define in red()
#define gc getchar()
#define cs const
#define ll long long
inline int red(){
	int num=0,f=1;char c=gc;
	for(;!isdigit(c);c=gc)if(c=='-')f=-1;
	for(;isdigit(c);c=gc)num=(num<<1)+(num<<3)+(c^48);
	return num*f;
}

cs int inf=1e9+7,N=1e5+10;
struct marix{
	int c[3][3];	
}tmp,sum[N<<2];
int num[N];
inline void ckmax(int &a,int b){a=a<b ? b:a;}
inline marix operator *(marix a,marix b){
	marix tmp;
	for(ri i=0;i<3;++i){
		for(ri j=0;j<3;++j){
			tmp.c[i][j]=-inf;
			for(ri k=0;k<3;++k){
				ckmax(tmp.c[i][j],a.c[i][k]+b.c[k][j]);
			}
		}
	}
	return tmp;
}
#define lc (p<<1)
#define rc ((p<<1)|1)
inline void pushup(int p){sum[p]=sum[rc]*sum[lc];}
inline void pushnow(int p,int k){sum[p].c[0][0]=sum[p].c[0][1]=sum[p].c[2][0]=sum[p].c[2][1]=k;sum[p].c[0][2]=sum[p].c[1][2]=sum[p].c[1][0]=-inf;sum[p].c[1][1]=sum[p].c[2][2]=0;}
inline void build(int p,int l,int r){
	if(l==r)return pushnow(p,num[l]);
	int mid=(l+r)>>1;
	build(lc,l,mid);build(rc,mid+1,r);
	pushup(p);
}
inline void upt(int p,int l,int r,int k,int v){
	if(l==r)return pushnow(p,v);
	int mid=(l+r)>>1;
	if(k<=mid)upt(lc,l,mid,k,v);
	else upt(rc,mid+1,r,k,v);
	pushup(p);
}
inline marix query(int p,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr)return sum[p];
	int mid=(l+r)>>1;
	if(qr<=mid)return query(lc,l,mid,ql,qr);
	else if(ql>mid)return query(rc,mid+1,r,ql,qr);
	else return query(rc,mid+1,r,ql,qr)*query(lc,l,mid,ql,qr);
}
int n,m;
int main(){
	n=in;m=in;
	for(ri i=1;i<=n;++i)num[i]=in;
	build(1,1,n);
	while(m--){
		int op=in,x=in,y=in;
		if(op==1)tmp=query(1,1,n,x,y),cout<<max(tmp.c[2][0],tmp.c[2][1])<<'\n';
		else upt(1,1,n,x,y);
	}
	return 0;
}
