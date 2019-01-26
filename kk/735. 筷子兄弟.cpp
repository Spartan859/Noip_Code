//f[i][j]=前i支筷子凑j双的最小值 
#include<bits/stdc++.h>
#define ll long long
#define N 505
using namespace std;
ll f[N][N],x[N],m,n;
int main(){
	//freopen
	cin>>m>>n;
	for(ll i=0;i<=n;i++)
		for(ll j=0;j<=n;j++)
			f[i][j]=1e9;
	for(ll i=1;i<=n;i++) cin>>x[i];
	if(m*2>n){
		cout<<-1<<endl;
		return 0;
	}
	sort(x+1,x+n+1);
	for(ll i=0;i<=n;i++) f[i][0]=0;
	for(ll i=2;i<=n;i++)
		for(ll j=1;j<=n>>1;j++)
			f[i][j]=min(f[i-1][j],f[i-2][j-1]+abs(x[i]-x[i-1]));
	cout<<f[n][m]<<endl;
	return 0;
}
