#include<bits/stdc++.h>
#define N 30
#define ll long long
using namespace std;
const ll mod=1000000009;
inline ll read(){
	ll res=0;char c;ll fnm=1;
	while((c=getchar())<'0'||c>'9') if(c=='-') fnm=-1;
	while(c>='0'&&c<='9') res=res*10+c-'0',c=getchar();
	return res*fnm;
}
inline ll change(ll &x,ll y,char t){
	ll r=x;
	if(t=='&') x&=y;
	else if(t=='|') x|=y;
	else x^=y;
	return r;
}
ll n,m;
char tp;
ll nums[N];
ll twc[30]={1};
ll tg;
ll ansn;
ll z;

void dfs(ll x,ll num,ll lst){//要选num个，现在在取第x个,上一个的位置是lst 
	if(x==num+1){
		if(z==tg){
			++ansn;
			if(ansn>=mod) ansn-=mod;
		} 
		return;
	}
	for(ll i=lst+1;i<=n-num+x;i++){
		ll cpy=change(z,nums[i],tp);
		//cout<<z<<' '<<endl;
		dfs(x+1,num,i);
		z=cpy;
	}
}
int main(){
	for(ll i=1;i<=26;i++) twc[i]=twc[i-1]*2;
	tp=getchar();
	n=read();m=read();
	//cout<<tp<<' '<<n<<' '<<m<<endl;
	for(ll i=1;i<=n;i++)
		for(ll j=1,ipt;j<=m;j++){
			ipt=read();
			nums[i]+=ipt*twc[m-j];
		}
	for(ll j=1,ipt;j<=m;j++){
		ipt=read();
		tg+=ipt*twc[m-j];
	}	
	if(tp=='&') z=twc[m]-1;
	ll ansall=0;
	ll jc[N]={0,1};
	for(ll i=2;i<=26;i++) jc[i]=jc[i-1]*i%mod;
	for(ll i=1;i<=n;i++){
		ansn=0;
		dfs(1,i,0);
		ansall+=ansn*jc[i]%mod;
		ansall%=mod;
		//cout<<ansn<<' ';
	}
	//cout<<endl;
	//for(ll i=1;i<=n;i++) cout<<nums[i]<<' ';
	printf("%lld\n",ansall);
	return 0;
}
