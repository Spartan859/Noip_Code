#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=3005;
ll n,m,h,t,q[N];
ll sum[N];
ll kx[N];
ll dp[N];//¹ö¶¯Ë¢ÐÂ 

inline ll Y(ll i){return kx[i]+sum[i]*sum[i];}
inline double slope(ll j,ll k){
    return (Y(j)-Y(k))*1.0/(sum[j]-sum[k]);
}
int main(){
	freopen("split.in","r",stdin);
	freopen("split.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(ll i=1,tmp;i<=n;i++){
    	scanf("%lld",&tmp);
    	sum[i]=tmp+sum[i-1],kx[i]=sum[i]*sum[i];
	}
    for(ll a=1;a<m;a++){
        h=t=0;q[0]=a;
        for(int i=a+1;i<=n;i++){
            while(h<t&&slope(q[h],q[h+1])<2*sum[i]) ++h;
            dp[i]=kx[q[h]]+(sum[i]-sum[q[h]])*(sum[i]-sum[q[h]]);
            while(h<t&&slope(q[t],q[t-1])>slope(q[t-1],i)) --t;q[++t]=i;
        }
        for(ll i=1;i<=n;i++) kx[i]=dp[i];
    }
    printf("%lld\n",-sum[n]*sum[n]+m*dp[n]);
    return 0;
}
