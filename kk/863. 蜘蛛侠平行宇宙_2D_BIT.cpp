#include<bits/stdc++.h>
#define N 1005
#define ll long long
using namespace std;
ll bit[N][N],a,b,c,d,n;
char str[10];

inline void updt(ll x,ll y,ll a){
	for(ll i=x;i<=n;i+=(i&(-i)))
		for(ll j=y;j<=n;j+=(j&(-j)))
			bit[i][j]+=a;
}
inline ll query(ll x,ll y){
	ll sum=0;
	for(ll i=x;i;i-=(i&(-i)))
		for(ll j=y;j;j-=(j&(-j)))
			sum+=bit[i][j];
	return sum;
}
inline ll give_ans(ll a,ll b,ll c,ll d){
	return query(a-1,b-1)+query(c,d)-query(c,b-1)-query(a-1,d);
}
int main(){
	freopen("spiderman.in","r",stdin);
	freopen("spiderman.out","w",stdout);
	scanf("%lld",&n);
	while(scanf("%s",&str)!=EOF){
		if(str[0]=='S'){
			scanf("%lld %lld",&a,&b);
			updt(a,b,1);
			//cout<<"----DONE1----"<<endl;
		}else if(str[0]=='Q'){
			scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
			cout<<give_ans(a,b,c,d)<<' ';
			//cout<<"----DONE2----"<<endl;
		}/*else{
			for(ll i=1;i<=n;i++,cout<<endl)
				for(ll j=1;j<=n;j++) cout<<bit[i][j]<<' ';
			//cout<<"----DONE3----"<<endl;
		}*/
	}
	return 0;
}
