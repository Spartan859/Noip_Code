#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const ll N=55,M=55,TMAX=2505;
ll n;// N 条木板需要被粉刷 50
ll m;//每条木板被分为 M 个格子 50
ll T;//只能粉刷 T 次 2500
ll ans;// ans
string s[M];
ll f[N][M][TMAX][2];
int main(){
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&T);
    for(ll i=1;i<=n;i++) 
		cin>>s[i];
    for(ll i=1;i<=n;i++)
        for(ll j=0;j<m;j++){
            for(ll k=1;k<=T;k++){
                if(j==0){
                    f[i][j][k][1]=max(f[i-1][m-1][k-1][0],f[i-1][m-1][k-1][1])+1;
                    f[i][j][k][0]=max(f[i-1][m-1][k-1][0],f[i-1][m-1][k-1][1]); 
			    	continue; 
                }
                ll eq=(s[i][j]==s[i][j-1]);
                //cout<<eq<<' ';
                f[i][j][k][1]=max(f[i][j-1][k-1][eq^1],f[i][j-1][k][eq])+1;
                f[i][j][k][0]=max(f[i][j-1][k][eq^1],f[i][j-1][k-1][eq]);
            }
            //cout<<endl;
            ans=max(ans,max(f[i][j][T][1],f[i][j][T][0]));
        }
    printf("%lld\n",ans);
    return 0;
}
