#include<bits/stdc++.h>
#define M 1005
#define ll long long
using namespace std;
ll n,m,r;
ll f[M],MX[M];//f:dp数组    MX:f的前缀最大值 
struct qj{
	ll st,ed,ef;
}a[M];
bool cmp(const qj &a,const qj &b){
	return a.ed<b.ed;
}
bool cmp_bs(const ll &a,const qj &b){//给upper_bound用的 自定义cmp函数 
	return a<b.ed;
}
bool cmp_bs2(const qj &a,const ll &b){//给lower_bound用的，这道题用不到，注意与upper_bound参数颠倒一下 
	return b>a.ed;
}
int main(){
	scanf("%lld%lld%lld",&n,&m,&r);
	for(ll i=1;i<=m;i++)
		scanf("%lld%lld%lld",&a[i].st,&a[i].ed,&a[i].ef);
	sort(a+1,a+m+1,cmp);
	f[1]=a[1].ef;
	MX[1]=f[1]; 
	for(ll i=2;i<=m;i++){
		ll tmp=upper_bound(a+1,a+m+1,a[i].st-r,cmp_bs)-a-1;//找到ed最大的满足要求的时间段 
		f[i]=MX[tmp]+a[i].ef;//转移 
		MX[i]=max(MX[i-1],f[i]);//求前缀最大数 
	}
	printf("%lld\n",MX[m]);//这里直接输出MX[m]就行了
	//整个dp数组的最大值就是 MX[m]
	return 0;
}

