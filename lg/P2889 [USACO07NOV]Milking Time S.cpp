#include<bits/stdc++.h>
#define M 1005
#define ll long long
using namespace std;
ll n,m,r;
ll f[M],MX[M];//f:dp����    MX:f��ǰ׺���ֵ 
struct qj{
	ll st,ed,ef;
}a[M];
bool cmp(const qj &a,const qj &b){
	return a.ed<b.ed;
}
bool cmp_bs(const ll &a,const qj &b){//��upper_bound�õ� �Զ���cmp���� 
	return a<b.ed;
}
bool cmp_bs2(const qj &a,const ll &b){//��lower_bound�õģ�������ò�����ע����upper_bound�����ߵ�һ�� 
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
		ll tmp=upper_bound(a+1,a+m+1,a[i].st-r,cmp_bs)-a-1;//�ҵ�ed��������Ҫ���ʱ��� 
		f[i]=MX[tmp]+a[i].ef;//ת�� 
		MX[i]=max(MX[i-1],f[i]);//��ǰ׺����� 
	}
	printf("%lld\n",MX[m]);//����ֱ�����MX[m]������
	//����dp��������ֵ���� MX[m]
	return 0;
}

