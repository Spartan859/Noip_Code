//f[i][j]=max(f[i-1][j-w[i]]+v[i],f[i-1][j])
#include<bits/stdc++.h>
#define ll long long
#define N 505
#define C 1005
using namespace std;
bool ok[N][C];
ll f[N][C],n,c,w[N],v[N];
ll F(ll i,ll j){
	if(i==0) return f[i][j];
	if(ok[i][j]) return f[i][j];
	ok[i][j]=1; f[i][j]=0;
	if(j<w[i]) f[i][j]=F(i-1,j);
	else f[i][j]=max(F(i-1,j-w[i])+v[i],F(i-1,j));
	return f[i][j];
}
int main(){
	cin>>c>>n;
	for(int i=1;i<=n;i++) cin>>w[i]>>v[i];
	cout<<F(n,c)<<endl;
	return 0;
} 
