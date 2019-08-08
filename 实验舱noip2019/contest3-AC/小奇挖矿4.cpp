#include<bits/stdc++.h>
#define lson(id) (id<<1)
#define rson(id) ((id<<1)|1) 

using namespace std;

typedef long long ll;
const int maxn=500003;

int n,lz[maxn<<2],a[maxn],k[maxn],mx[maxn<<2],mn[maxn<<2];//lz:lazy tag  a:mines k:-  mx/mn:区间内最大,最小 
ll sum[maxn<<2];//区间和 

inline void read(int &x){
	x=0;char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
}

inline void pushup(int id){//上传区间信息 
	mx[id]=mx[lson(id)];
	mn[id]=mn[rson(id)];
	sum[id]=sum[lson(id)]+sum[rson(id)];
}

inline void change(int id,int len,int w){//更改区间信息 
	mx[id]+=w;mn[id]+=w;lz[id]+=w;
	sum[id]+=1ll*len*w;
}

inline void pushdown(int id,int l,int r){//下传lazy tag 
	if(lz[id]){
		int mid=l+r>>1;
		change(lson(id),mid-l+1,lz[id]);
		change(rson(id),r-mid,lz[id]);
		lz[id]=0;
	}
}

inline int query_cnt(int id,int l,int r,int vl){//查询l-r之间有多少个大于等于vl的数 
	if(mn[id]>=vl) return r-l+1;//最小值比vl大 
	if(mx[id]<vl) return 0;//最大值比vl小 
	int mid=(l+r)/2;
	pushdown(id,l,r);//下传更新 
	return query_cnt(lson(id),l,mid,vl)
		  +query_cnt(rson(id),mid+1,r,vl);
}

inline void update(int id,int l,int r,int L,int R,int w){
	if(l>=L&&r<=R){//整个区间都在修改范围内，直接更改 
		change(id,r-l+1,w);
		return ;
	}
	if(l>R||L>r) return ;//没有交集 
	int mid=l+r>>1;
	pushdown(id,l,r);//下传更新 
	if(mid>=L) update(lson(id),l,mid,L,R,w);
	if(mid<R) update(rson(id),mid+1,r,L,R,w);
	pushup(id);//上传区间信息 
}

inline int query_num(int id,int l,int r,int pos){//单点查询 
	if(l==r) return sum[id];
	int mid=(l+r)/2;
	pushdown(id,l,r);
	if(mid>=pos) return query_num(lson(id),l,mid,pos);
	else return query_num(rson(id),mid+1,r,pos);
}

inline ll query_sum(int id,int l,int r,int R){//前缀和查询 
	if(l>R) return 0;
	if(r<=R) return sum[id];
	int mid=(l+r)/2;
	pushdown(id,l,r);
	return query_sum(lson(id),l,mid,R)
		  +query_sum(rson(id),mid+1,r,R);
}

int main(){
	read(n);
	for(int i=1;i<=n;++i) read(a[i]);
	sort(a+1,a+n+1,greater<int>());
	ll res=0;
	for(int i=1;i<=n;++i) update(1,1,n,i,i,a[i]);//初始化线段树 
	int T_T,t;read(T_T); 
	for(int i=1;i<=T_T;++i){
		read(k[i]);
		t=query_num(1,1,n,k[i]);//k[i]位置的数 
		res+=query_sum(1,1,n,k[i]);//前k[i]个数的和 
		int c=query_cnt(1,1,n,t+1);//大于等于t+1 
		int _c=query_cnt(1,1,n,t);//大于等于t
		//_c-c=1-n中有多少个t 
		update(1,1,n,1,c,-1);//大于等于t+1的直接-1 
		update(1,1,n,_c+c-k[i]+1,_c,-1);//等于t的靠右-1
		 
	}
	printf("%lld\n",res);
	return 0;
}
