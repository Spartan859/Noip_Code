#include<bits/stdc++.h>
#define N 505
#define ll long long
using namespace std;
ll n,p,ans;
ll a[N][N],sum[N][N],rw,fl,fr,fi,fj;
inline ll SumOfRct(ll x1,ll y1,ll x2,ll y2){
	return sum[x2][y2]-sum[x2][y1-1]-sum[x1-1][y2]+sum[x1-1][y1-1];
}
int main(){
	//freopen("plateau.in","r",stdin);
	//freopen("plateau.out","w",stdout);
	scanf("%lld%lld",&n,&p);
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++) scanf("%lld",&a[i][j]);
	for(ll i=1;i<=n;i++,rw=0)
		for(ll j=1;j<=n;j++)
			rw+=a[i][j],sum[i][j]=sum[i-1][j]+rw;
	for(ll i=1;i<=n;i++)
		for(ll j=i;j<=n;j++){
			ll l=1,r=1,tmpans=0,rr=0,lr=0;
			while(r<=n){
				while(SumOfRct(i,l,j,r)<=p&&r<=n) r++;
				if(r-l>tmpans) tmpans=r-l,rr=r-1,lr=l;
				while(SumOfRct(i,l,j,r)>p&&l<=r&&r<=n) l++;
			}
			if(tmpans*(j-i+1)>ans) ans=tmpans*(j-i+1),fl=lr,fr=rr,fi=i,fj=j;
		}
	printf("%lld\n",ans);
	/*cout<<fi<<' '<<fl<<' '<<fj<<' '<<fr<<endl;
	ll tst1,tst2,tst3,tst4;
	while(cin>>tst1>>tst2>>tst3>>tst4){
		if(tst1==-1) break;
		cout<<SumOfRct(tst1,tst2,tst3,tst4)<<endl;
	}
	while(cin>>tst1>>tst2){
		if(tst1==-1) break;
		cout<<sum[tst1][tst2]<<endl;
	}*/
	return 0;			
}
