#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll build(ll k,ll l,ll r){
	//cout<<k<<endl;
	if(l==r)
		return k;
	ll mid=(l+r)>>1;
	return build(k<<1|1,mid+1,r);
}
ll bsc[10];
int main(){
	ll l,r;
	scanf("%lld%lld",&l,&r);
	ll ansl,ansr;
	
	//cout<<rer<<endl;
	ansl=build(1,1,l-1);
	ansr=build(1,1,r);
	puts("de:");
	cout<<ansl<<' '<<ansr<<endl;
	cout<<"!!!!!"<<endl;
	for(ll i=1,j=1;i<=9;i+=2,j++) bsc[j]=bsc[j-1]^i;
	ll rel=bsc[5],rer=bsc[5];
	
	ll tl=l-1-5,tr=r-5;
	ll now2=2,nowlv=4;//现在进行的跃迁等级 
	ll nowlft=15;
	while(1){
		if(tl>=now2) tl-=now2;
		else{
			if(tl&1) rel^=ansl/*,cout<<ansl<<endl*/;
			break;
		}
		now2+=nowlv;nowlv*=2;
		if(tl>0) /*cout<<nowlft<<' ',*/rel^=nowlft,nowlft+=2,tl--;
		if(tl>0) /*cout<<nowlft<<' ',*/rel^=nowlft,nowlft+=nowlv,tl--;
	}
	now2=2;nowlv=4;nowlft=15;
	while(1){
		if(tr>=now2) tr-=now2;
		else{
			if(tr&1) rer^=ansr;
			break;
		}
		now2+=nowlv;nowlv*=2;
		if(tr>0) rer^=nowlft,nowlft+=2,tr--;
		if(tr>0) rer^=nowlft,nowlft+=nowlv,tr--; 
	}
	if(l-1<=5) rel=bsc[l-1];
	if(r<=5) rer=bsc[r];
	ll ans=rer^rel;
	
	printf("%lld\n",ans);
	//cout<<"de:rel "<<rel<<endl;
	//cout<<"de:rer "<<rer<<endl;
	//cout<<((1^3^5^7^9^13))<<endl;
	
	return 0;
}

