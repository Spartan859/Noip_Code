#include<bits/stdc++.h>
#define ll long long
#define N 200005
using namespace std;
ll n,t[N],ans=N,i,vst[N],g[N],gx=0;
void dfs(ll x,ll c){
	vst[x]=1;
	if(t[x]==i){
		ans=min(ans,c+1);
		vst[x]=0;
		return ;
	}
	if(!vst[t[x]]) dfs(t[x],c+1);
	vst[x]=0;
}
int main(){
	cin>>n;
	for(i=1;i<=n;i++) cin>>t[i];
	for(i=1;i<=n;i++)
	    if(!vst[i]){
		    gx++;
		    int x=i,len=1;
		    while(!vst[x]){
		    	g[x]=gx;
		    	vst[x]=len++;
		    	x=t[x];
			}
			if(g[x]==gx) ans=min(ans,len-vst[x]);
	    } 
	cout<<ans<<endl;
	return 0;
}
