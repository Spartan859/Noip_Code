#include<bits/stdc++.h>
#define lson(id) (id<<1)
#define rson(id) ((id<<1)|1) 

using namespace std;

typedef long long ll;
const int maxn=500003;

int n,lz[maxn<<2],a[maxn],k[maxn],mx[maxn<<2],mn[maxn<<2];//lz:lazy tag  a:mines k:-  mx/mn:���������,��С 
ll sum[maxn<<2];//����� 

inline void read(int &x){
	x=0;char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
}

inline void pushup(int id){//�ϴ�������Ϣ 
	mx[id]=mx[lson(id)];
	mn[id]=mn[rson(id)];
	sum[id]=sum[lson(id)]+sum[rson(id)];
}

inline void change(int id,int len,int w){//����������Ϣ 
	mx[id]+=w;mn[id]+=w;lz[id]+=w;
	sum[id]+=1ll*len*w;
}

inline void pushdown(int id,int l,int r){//�´�lazy tag 
	if(lz[id]){
		int mid=l+r>>1;
		change(lson(id),mid-l+1,lz[id]);
		change(rson(id),r-mid,lz[id]);
		lz[id]=0;
	}
}

inline int query_cnt(int id,int l,int r,int vl){//��ѯl-r֮���ж��ٸ����ڵ���vl���� 
	if(mn[id]>=vl) return r-l+1;//��Сֵ��vl�� 
	if(mx[id]<vl) return 0;//���ֵ��vlС 
	int mid=(l+r)/2;
	pushdown(id,l,r);//�´����� 
	return query_cnt(lson(id),l,mid,vl)
		  +query_cnt(rson(id),mid+1,r,vl);
}

inline void update(int id,int l,int r,int L,int R,int w){
	if(l>=L&&r<=R){//�������䶼���޸ķ�Χ�ڣ�ֱ�Ӹ��� 
		change(id,r-l+1,w);
		return ;
	}
	if(l>R||L>r) return ;//û�н��� 
	int mid=l+r>>1;
	pushdown(id,l,r);//�´����� 
	if(mid>=L) update(lson(id),l,mid,L,R,w);
	if(mid<R) update(rson(id),mid+1,r,L,R,w);
	pushup(id);//�ϴ�������Ϣ 
}

inline int query_num(int id,int l,int r,int pos){//�����ѯ 
	if(l==r) return sum[id];
	int mid=(l+r)/2;
	pushdown(id,l,r);
	if(mid>=pos) return query_num(lson(id),l,mid,pos);
	else return query_num(rson(id),mid+1,r,pos);
}

inline ll query_sum(int id,int l,int r,int R){//ǰ׺�Ͳ�ѯ 
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
	for(int i=1;i<=n;++i) update(1,1,n,i,i,a[i]);//��ʼ���߶��� 
	int T_T,t;read(T_T); 
	for(int i=1;i<=T_T;++i){
		read(k[i]);
		t=query_num(1,1,n,k[i]);//k[i]λ�õ��� 
		res+=query_sum(1,1,n,k[i]);//ǰk[i]�����ĺ� 
		int c=query_cnt(1,1,n,t+1);//���ڵ���t+1 
		int _c=query_cnt(1,1,n,t);//���ڵ���t
		//_c-c=1-n���ж��ٸ�t 
		update(1,1,n,1,c,-1);//���ڵ���t+1��ֱ��-1 
		update(1,1,n,_c+c-k[i]+1,_c,-1);//����t�Ŀ���-1
		 
	}
	printf("%lld\n",res);
	return 0;
}
