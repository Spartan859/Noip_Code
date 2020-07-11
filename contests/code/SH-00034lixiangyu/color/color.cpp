#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll T;
ll pa,pb,k;
inline ll gcd(ll x,ll y){
	if(x<y) swap(x,y);
	ll tmp;
	while(y){
		tmp=y;
		y=x%y;
		x=tmp;
	}
	return x;
}
int main(){
	//freopen("color.in","r",stdin);
	//freopen("color.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld%lld",&pa,&pb,&k);
		if(k==1){puts("No");continue;} 
		if(pa==pb)
			puts("Yes");continue;
		if(pa<pb) swap(pa,pb);
		
		if((ll)(pa/pb)>=k){
			puts("No");
			continue;
		}
		if((ll)(pa/pb)<k-1){
			puts("Yes");
			continue;
		}
		ll fff=gcd(pa,pb)*pa*pb;
		bool flag=0;
		for(ll x=1;(x+1)*pa<=fff;x++){
			ll tmp1=x*pa/pb+1;
			ll tmp2=(x+1)*pa/pb;
			if(tmp2-tmp1+1>=k){
				//cout<<x<<endl;
				puts("No");
				flag=1;
				break;
			}
		}
		if(!flag) puts("Yes");
	}
	return 0;
}

