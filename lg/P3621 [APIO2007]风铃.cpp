#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=200005,INF=1e18;
ll n;//��ʾ�������ж��ٸ���
ll l[N],r[N];//������ ii �������������ҵĶ�����
//����ҵ���һ����ߣ����Ӧ��ֵΪ-1������Ϊ��������ĸ˵ı�š�
ll dpth[N];//������� 
ll mxdp,mndp=INF;//��Ҷ�ڵ��������С��� 
ll sm[N],bg[N];//���ڵ�С��ʹ������� 
ll ans;
void dfs(ll x,ll fa){
	dpth[x]=dpth[fa]+1;
	if(!l[x]&&!r[x]){
		mxdp=max(dpth[x],mxdp);
		mndp=min(dpth[x],mndp);
	} 
	if(l[x]) dfs(l[x],x);
	if(r[x]) dfs(r[x],x); 
}
bool dfs2(ll x,ll fa){
	if(!l[x]&&!r[x]){
		if(dpth[x]==mndp) ++sm[x];
		else ++bg[x];
		return 1;
	}
	if(l[x]){
		if(!dfs2(l[x],x)) return 0;
		sm[x]+=sm[l[x]];
		bg[x]+=bg[l[x]];
	}
	if(r[x]){
		if(!dfs2(r[x],x)) return 0; 
		sm[x]+=sm[r[x]];
		bg[x]+=bg[r[x]];
	}
	if(sm[l[x]]&&sm[r[x]]&&bg[l[x]]&&bg[r[x]]) return 0;
	if(sm[l[x]]&&bg[r[x]]) ++ans;
	return 1;
}
int main(){
	scanf("%lld",&n);
	ll nd=n;
	for(ll i=1;i<=n;i++){
		scanf("%lld%lld",l+i,r+i);
		if(l[i]==-1) l[i]=++nd;
		if(r[i]==-1) r[i]=++nd;
	}
	dfs(1,0);
	if(mxdp-mndp>1){
		//cout<<mxdp<<' '<<mndp<<endl;
		puts("-1");return 0;
	}
	if(!dfs2(1,0)){
		puts("-1");return 0;
	}
	printf("%lld\n",ans);
	return 0;
}

