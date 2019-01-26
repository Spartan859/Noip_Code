#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll m,L,n,x[100005];
struct grp{
	ll lv,amt;
	const bool operator<(const grp &a)const{
		return a.lv>lv||a.lv==lv&&a.amt>amt;
	}
}tmp;
multiset<grp> ms;
multiset<grp>::iterator it;
multiset<grp>::iterator it2;
multiset<grp>::iterator it3;
int main(){
	freopen("higher.in","r",stdin);
	freopen("higher.out","w",stdout);
	scanf("%lld",&m);
	for(ll i=1;i<=m;i++){
		scanf("%lld %lld",&L,&n);
		tmp.lv=L;tmp.amt=n;
		ms.insert(tmp);
	}
	it2=ms.begin();it2++;
	it3=ms.begin();it3--;
	for(it=ms.begin();it2!=ms.end();){
		if((*it).lv==(*it2).lv){
			tmp=(*it);
			tmp.amt+=(*it2).amt;
			ms.erase(it);
			ms.erase(it2);
			ms.insert(tmp);
			it=it3;
			it++;
			it2=it;
			it2++;
		}
		else{
			it3=it;
			it++;it2++;
		}
	}
	ll cnt=1;
	for(it=ms.begin();it!=ms.end();it++,cnt++){
		if((*it).amt!=1) x[cnt]=(*it).lv+(*it).amt/2+(*it).amt%2;
		else x[cnt]=(*it).lv;
	}
	cnt--;
	while(1){
		ll cnt2=1;
		for(ll i=2;i<=cnt;i+=2) x[cnt2++]=max(x[i],x[i-1])+1;
		if(cnt%2) x[cnt2++]=x[cnt];
		cnt=cnt2-1;
		if(cnt==1) break;
	}
	cout<<x[1]<<endl;
	return 0;
}
