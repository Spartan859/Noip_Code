#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<": "<<x<<endl
#define dbg1 cout<<1<<endl;
#define N_MAX 1000005
#define ll long long
using namespace std;
inline ll read(){
	ll res=0,fs=1;char c;
	while((c=getchar())<'0'||c>'9') if(c=='-') fs=-1;
	while(c>='0'&&c<='9') res=res*10+c-'0',c=getchar();
	return res*fs;
} 
ll n;
char s[N_MAX],sx[N_MAX*2];//sx ��������string
ll ans[N_MAX*2]; 

ll p[N_MAX*2]; 
inline void Manacher(){
	for(ll i=0,cnt=1;i<n;i++,cnt+=2) sx[cnt]='#',sx[cnt+1]=s[i];
	sx[0]='$';sx[n*2+1]='#';
	n=n*2+1;
	ll id=0,mx=0;//p ���İ뾶 
	for(ll i=1;i<=n;i++){
		if(mx>i) p[i]=min(p[id*2-i],mx-i);
		else p[i]=1;
		while(sx[i+p[i]]==sx[i-p[i]]) p[i]++;
		if(p[i]+i>mx) id=i,mx=i+p[i];
		ans[p[i]+i-2]=max(ans[p[i]+i-2],p[i]-1);
	}
}
int main(){
	n=read();scanf("%s",s);
	Manacher();
	for(ll i=n-1;i>=2;i-=2) ans[i]=max(ans[i],ans[i+2]-2); 
	for(ll i=2;i<=n-1;i+=2) printf("%lld\n",ans[i]);
	return 0;
}
