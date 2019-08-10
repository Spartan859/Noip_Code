#include<bits/stdc++.h>
#define N 1000005
#define ll long long
using namespace std;
const ll BS=131;
unsigned ll bsf[N]={1};

unsigned ll hsh1f[N],hsh1b[N],hsh2b[N];
multiset<unsigned ll> ms;//´¢´æhsh2f
multiset<unsigned ll>::iterator it; 
map<unsigned ll,ll> mp;

char a[N],b[N];
ll n,T;
bool flag=0;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("B.in","r",stdin);
	freopen("B.ans","w",stdout);
	#endif
	scanf("%lld%lld",&n,&T);
	scanf("%s",&a);
	scanf("%s",&b);
	for(ll i=1;i<=n;i++) bsf[i]=bsf[i-1]*BS;
	for(ll i=1;i<=n;i++){
		hsh1f[i]=hsh1f[i-1]*BS+a[i-1];
		//cout<<hsh1f[i]<<' ';
	}
	//cout<<endl;
	for(ll i=n;i>=1;i--){
		hsh1b[i]=hsh1b[i+1]+a[i-1]*bsf[n-i];
	}

	for(ll i=1,hsh2f=0;i<=n;i++){
		hsh2f=hsh2f*BS+b[i-1];
		//cout<<b[i]
		ms.insert(hsh2f);
		mp[hsh2f]=i;
		//cout<<hsh2f<<' ';
	}
	//cout<<endl; 
	for(ll i=n;i>=1;i--){
		hsh2b[i]=hsh2b[i+1]+b[i-1]*bsf[n-i];
	}
	
	if(hsh1b[1]==hsh2b[1]) flag=1;
	if(!flag){
		for(ll i=2;i<=n;i++){
			it=ms.find(hsh1b[i]);
			//if(it!=ms.end()) cout<<*it<<endl;
			if(it!=ms.end()){
				ll y=mp[*it];
				if(hsh2b[y+1]==hsh1f[i-1]){
					flag=1;
					break;
				}
			}
		}
	}
	if(flag) puts("TAK");
	else puts("NIE");
	if(T==1&&flag){
		char cmin1='z'+1,cmin2='z'+1,cmin3='z'+1;
		ll pos=0;
		for(ll i=0;i<n-2;i++){
			if(a[i]<cmin1||a[i]==cmin1&&a[i+1]<cmin2||a[i]==cmin1&&a[i+1]==cmin2&&a[i+2]<cmin3) cmin1=a[i],cmin2=a[i+1],cmin3=a[i+2],pos=i;
		}
		if(a[n-2]<cmin1||a[n-2]==cmin1&&a[n-1]<cmin2||a[n-2]==cmin1&&a[n-1]==cmin2&&a[0]<cmin3) cmin1=a[n-2],cmin2=a[n-1],cmin3=a[0],pos=n-2;
		if(a[n-1]<cmin1||a[n-1]==cmin1&&a[0]<cmin2||a[n-1]==cmin1&&a[0]==cmin2&&a[1]<cmin3) cmin1=a[n-1],cmin2=a[0],cmin3=a[1],pos=n-1;
		for(ll i=pos;i<n;i++) cout<<a[i];
		for(ll i=0;i<pos;i++) cout<<a[i];
		cout<<endl;
	}
	return 0;
}
