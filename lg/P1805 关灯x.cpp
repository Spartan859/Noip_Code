#include<bits/stdc++.h>
#define N 1005
#define ll long long
using namespace std;
ll n;
ll kai[N],cnt;//ֱ�Ӽ�¼��ʼ�����б� 
ll zrt[N];//��ȫ0��0000001 zrt[i]=2^i-1
bool spj=0;
ll ans;
int main(){
	scanf("%lld",&n);
	for(ll i=1,tmp;i<=n;i++){
		scanf("%lld",&tmp);
		if(tmp) kai[++cnt]=i;
	}
	ll tmpz=1;
	for(ll i=1;i<=n;i++){
		tmpz*=2;
		zrt[i]=tmpz-1;
	}
	ll lst=0;
	for(ll i=1;i<=cnt;i++){
		lst=zrt[kai[i]]-lst;
	}
	printf("%lld\n",lst);
	return 0;
}
