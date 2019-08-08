#include<bits/stdc++.h>
#define N 30
#define ll long long
using namespace std;
ll n,m,ans;
ll a[N][N];
ll tg[N];
ll dj[N],cnt;
ll vst[N];
char tp;
ll z=0,tgz=0;

void dfs(ll x){
	//cout<<z<<endl;
	if(z==tgz)
		ans++;
	if(x==cnt+1) return;	
	for(ll i=1;i<=cnt;i++){
		if(!vst[i]){
			ll cpy=z;
			vst[i]=1;
			z&=dj[i];
			dfs(x+1);
			vst[i]=0;
			z=cpy;
		}
	}
}

void dfs2(ll x){
	if(z==tgz)
		ans++;
	if(x==cnt+1) return;	
	for(ll i=1;i<=cnt;i++){
		if(!vst[i]){
			ll cpy=z;
			vst[i]=1;
			z|=dj[i];
			dfs(x+1);
			vst[i]=0;
			z=cpy;
		}
	}
}
int main(){
	scanf("%c",&tp);
	if(tp=='&'){
		
		scanf("%lld%lld",&n,&m);
		for(ll i=1;i<=n;i++)
			for(ll j=1;j<=m;j++){
				scanf("%lld",&a[i][j]);
				if(tp=='|') a[i][j]^=1;
			}
			
		for(ll i=1;i<=m;i++){
			scanf("%lld",tg+i);
			if(tp=='|') tg[i]^=1;
		}
		
		//ll tgz=0;	
		for(ll i=m,tmp=1;i>=1;i--,tmp*=2) tgz+=tmp*tg[i];
		
		bool flag=1;
		for(ll i=1,x=0;i<=n;i++){
			x=0;
			flag=1;
			for(ll j=m,tmp=1;j>=1;j--,tmp*=2){
				if(tg[j]&&!a[i][j]){
					flag=0;//不符合要求 
					break;
				}
				x+=tmp*a[i][j];
			}
			if(flag){
				dj[++cnt]=x;
				//cout<<i<<endl;
			} 
		}
	//ll z=0;
		if(tp=='&') for(ll i=1,tmp=1;i<=m;i++,tmp*=2) z+=tmp;
	//cout<<z<<' '<<tgz<<endl; 
	//ll ans=0;
	//if(!(z^tgz)) ++ans;
		dfs(1);
		printf("%lld\n",ans);
	
		//for(ll i=1;i<=cnt;i++) printf("%lld ",dj[i]);
		//cout<<endl;
		//cout<<tgz<<endl;
	}else{
	//	scanf("%c",&tp);
		scanf("%lld%lld",&n,&m);
		for(ll i=1;i<=n;i++)
			for(ll j=1;j<=m;j++){
				scanf("%lld",&a[i][j]);
			}
			
		for(ll i=1;i<=m;i++){
			scanf("%lld",tg+i);
		}
		
		//ll tgz=0;	
		for(ll i=m,tmp=1;i>=1;i--,tmp*=2) tgz+=tmp*tg[i];
		
		bool flag=1;
		for(ll i=1,x=0;i<=n;i++){
			x=0;
			flag=1;
			for(ll j=m,tmp=1;j>=1;j--,tmp*=2){
				if(tg[j]&&!a[i][j]){
					flag=0;//不符合要求 
					break;
				}
				x+=tmp*a[i][j];
			}
			if(flag){
				dj[++cnt]=x;
				//cout<<i<<endl;
			} 
		}
	//ll z=0;
		if(tp=='&') for(ll i=1,tmp=1;i<=m;i++,tmp*=2) z+=tmp;
	//cout<<z<<' '<<tgz<<endl; 
	//ll ans=0;
	//if(!(z^tgz)) ++ans;
		dfs2(1);
		printf("%lld\n",ans);
	
		//for(ll i=1;i<=cnt;i++) printf("%lld ",dj[i]);
		//cout<<endl;
		//cout<<tgz<<endl;
	}
	return 0;	
}
