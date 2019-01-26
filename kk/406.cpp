#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long ll;
const int maxn=3005;
const ll mod=100000007;

ll d[maxn],c[maxn][maxn],h[maxn],g[maxn];

void ready()
{
    for(int i=0;i<=100;i++)
    c[i][0]=1;
    for(int i=1;i<=100;i++)
    {   
        for(int j=1;j<=i;j++)
        {
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
        }
    }
}   
int main()
{
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
    ready();
    d[1]=1;
    g[1]=0;
    h[1]=1;
    int t=1;
    for(int i=2;i<=100;i++)
    {
        for(int j=1;j<=i-1;j++)
        {
            g[i]=(g[i]+(c[i-1][j-1]*d[j])%mod*h[i-j])%mod;
        }
        t=(2*t)%mod;
        h[i]=(t*h[i-1])%mod;
        d[i]=(h[i]-g[i]+mod)%mod;
    }
    int n;
    scanf("%d",&n);
    printf("%d\n",d[n]);
    return 0;
}
