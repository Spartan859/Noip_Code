#include<bits/stdc++.h>
#define N 1005
#define ll long long
using namespace std;
ll bit[N][N],n;
ll a,b,c,d;
char s[10];
void add_point(ll i,ll j,ll s){
	while(j<=n){
		bit[i][j]+=s;
		j+=j&(-j);
	}
}
ll query(ll i,ll j){//第i行前j个
	ll sum=0;
	while(j){
		sum+=bit[i][j];
		j-=j&(-j);
	}
	return sum;
}
int main(){
	freopen("spiderman.in","r",stdin);
	freopen("spiderman.out","w",stdout);
	scanf("%lld",&n);
	while(scanf("%s",&s)!=EOF){
		if(s[0]=='S'){
			scanf("%lld %lld",&a,&b);
			add_point(a,b,1);
		}
		else{
			scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
			ll sum=0;
			for(ll i=a;i<=c;i++) sum+=query(i,d)-query(i,b-1);
			cout<<sum<<' ';
		}
	}
	return 0;
}
