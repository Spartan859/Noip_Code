#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll f[2005][205],n,m,ans;
char x[2005],bf[2005][205];
int main(){
	//freopen
	cin>>n>>m;
	x[0]='F';bf[0][0]='F';
	for(ll i=1;i<=n;i++) cin>>x[i];
	for(ll i=1;i<=n;i++){
		f[i][0]=f[i-1][0]+(x[i]=='F');
		bf[i][0]='F';
	}
	for(ll j=1;j<=m;j++)
		for(ll i=j;i<=n;i++){
			if(bf[i-1][j]==x[i]&&bf[i-1][j-1]!=x[i])
				f[i][j]=max(f[i-1][j]+1,f[i-1][j-1]+1),bf[i][j]=x[i];
			
			if(bf[i-1][j]==x[i]&&bf[i-1][j-1]==x[i]) f[i][j]=f[i-1][j]+1,bf[i][j]=x[i];
			if(bf[i-1][j]!=x[i]&&bf[i-1][j-1]!=x[i]) f[i][j]=f[i-1][j-1]+1,bf[i][j]=x[i];
			if(bf[i-1][j]!=x[i]&&bf[i-1][j-1]==x[i])
				if(f[i-1][j]>=f[i-1][j-1]) f[i][j]=f[i-1][j],bf[i][j]=bf[i-1][j];
				else f[i][j]=f[i-1][j-1],bf[i][j]=(bf[i-1][j-1]=='F'?'B':'F');
		}
	for(ll j=0;j<=m;j++) ans=max(ans,f[n][j]);
	cout<<ans<<endl;
	/*for(ll i=0;i<=n;i++,cout<<endl)
		for(ll j=0;j<=m;j++) cout<<f[i][j]<<' ';*/
	return 0;
}
