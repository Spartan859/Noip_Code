#include<bits/stdc++.h>
#define ll long long
#define N 7000
using namespace std;
inline int read(){
    int x=0; bool f=1; char c=getchar();
    for(;!isdigit(c); c=getchar()) if(c=='-') f=0;
    for(; isdigit(c); c=getchar()) x=(x<<3)+(x<<1)+(c^'0');
    if(f) return x;
    return 0-x;
}
int n,k,d[N],f[N],cnt,ans,mod,T;
int Pow(int x, int y){
    int ret=1;
    while(y){
        if(y&1) ret=(ll)ret*x%mod;
        x=(ll)x*x%mod;
        y>>=1;
    }
    return ret;
}
int main(){
	scanf("%d",&T);
	while(T--){
		ans=cnt=0;
		n=read();k=read();mod=read();
    	int nn=sqrt(n);
    	for(int i=1; i<=nn; ++i)
        	if(n%i==0){
        	    d[++cnt]=i, f[cnt]=Pow(k,(i+1)/2);
        	    for(int j=1; j<cnt; ++j)
        	        if(i%d[j]==0) f[cnt]=((f[cnt]-f[j])%mod+mod)%mod;
        	    ans=(ans+(ll)f[cnt]*((i&1)?i:i/2)%mod)%mod;
        	}
    	for(int i=nn; i>=1; --i)
        	if(n%i==0){
        	    int ii=n/i;
            	d[++cnt]=ii, f[cnt]=Pow(k,(ii+1)/2);
            	for(int j=1; j<cnt; ++j)
            	    if(ii%d[j]==0) f[cnt]=((f[cnt]-f[j])%mod+mod)%mod;
            	ans=(ans+(ll)f[cnt]*((ii&1)?ii:ii/2)%mod)%mod;
        	}
    	cout<<ans<<endl;
	}
    return 0;
}
