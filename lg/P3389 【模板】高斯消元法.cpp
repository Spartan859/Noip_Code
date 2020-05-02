#include<bits/stdc++.h>
#define ll long long
#define eps 1e-6
using namespace std;
const ll N=105;
ll n;
double a[N][N],ans[N];
void mxh(ll x){
	ll rt=x;
	for(ll i=x+1;i<=n;i++)
		if(fabs(a[i][x])>fabs(a[rt][x])) rt=i;
	if(rt!=x) swap(a[rt],a[x]);
	//cout<<rt<<endl;
	//cout<<a[2][2]<<endl;
}

int main(){
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n+1;j++)
			scanf("%lf",&a[i][j]);
	for(ll i=1;i<=n;i++){//i当前要消的行 
		mxh(i);
		if(fabs(a[i][i])<eps){
			//cout<<a[i][i]<<endl;
			puts("No Solution");
			return 0;
		}
		double div=a[i][i];
		for(ll j=i;j<=n+1;j++) a[i][j]/=div;
		for(ll j=i+1;j<=n;j++){
			div=a[j][i];
			for(ll k=i;k<=n+1;k++) a[j][k]-=a[i][k]*div;
		}
		ans[n]=a[n][n+1];
		for(ll i=n-1;i>=1;i--){
			ans[i]=a[i][n+1];
			for(ll j=i+1;j<=n;j++) ans[i]-=a[i][j]*ans[j];
		}
	}
	for(ll i=1;i<=n;i++) printf("%.2lf\n",ans[i]);
	return 0;
}

