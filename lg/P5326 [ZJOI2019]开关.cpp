#include<bits/stdc++.h>
using namespace std;

const int mod=998244353;
typedef long long ll;

inline void upd(int&a,const int&b){a+=b-mod;a+=a>>31&mod;}
const int M=50010;
const int N=200;
int ans,dp[2][M],n,inv[M];
pair<int,int>a[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i].second;
    for(int i=1;i<=n;i++)cin>>a[i].first;
    sort(a+1,a+n+1);
    int sz=0;
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        int op=a[i].second,p=a[i].first;
        for(int j=sz;j>=0;--j){
            upd(dp[op][j+p],dp[0][j]);
            upd(dp[!op][j+p],dp[1][j]);
        }
        sz+=p;
    }
    inv[1]=1;
    for(int i=2;i<=sz;++i)
        inv[i]=mod-mod/i*(ll)inv[mod%i]%mod;
    for(int i=1;i<=sz;++i)
        ans=(ans+(ll)inv[i]*dp[1][i])%mod;
    cout<<(ll)ans*sz%mod<<endl;
    return 0;
}
