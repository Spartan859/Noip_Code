#include<bits/stdc++.h>
#define N 300005 
#define ll long long
using namespace std;
ll n,s,sumC[N],sumT[N],f[N],q[N],l=0,r=1;//////

double slope(ll j,ll k){
    return (0.0+f[j]-f[k])/(sumC[j]-sumC[k]);
}

ll binary_search(ll i,ll k){
	ll lx=l,rx=r-1;
	if(lx==rx) return q[l];
	while(lx<rx){
		ll mid=(rx+lx)>>1;
		if(f[q[mid+1]]-f[q[mid]]<=k*(sumC[q[mid+1]]-sumC[q[mid]])) lx=mid+1;
		else rx=mid;//////
	}
	return q[lx];
}
int main(){
    scanf("%lld%lld",&n,&s);
    for (ll i=1,t,c;i<=n;i++){
        scanf("%lld%lld",&t,&c);
        sumT[i]=sumT[i-1]+t;
        sumC[i]=sumC[i-1]+c;
    }
    for (ll i=1;i<=n;i++){
    	ll p=binary_search(i,s+sumT[i]);
        f[i]=f[p]+sumT[i]*(sumC[i]-sumC[p])+s*(sumC[n]-sumC[p]);
        while(l<r-1 && (f[q[r-1]]-f[q[r-2]])*(sumC[i]-sumC[q[r-1]])>=(f[i]-f[q[r-1]])*(sumC[q[r-1]]-sumC[q[r-2]])) r--;
        q[r++]=i;
    }
    printf("%lld\n",f[n]);
    return 0;
}
