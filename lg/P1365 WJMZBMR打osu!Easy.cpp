#include<bits/stdc++.h>
#define il inline
#define ll long long
#define For(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define Bor(i,a,b) for(int (i)=(b);(i)>=(a);(i)--)
using namespace std;
int n,cnt;
char s;
double f[2],g[2];
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    For(i,1,n){
        cin>>s;
        if(s=='x') f[cnt^1]=f[cnt],g[cnt^1]=0;
        else if(s=='o') f[cnt^1]=f[cnt]+2*g[cnt]+1,g[cnt^1]=g[cnt]+1;
        else f[cnt^1]=f[cnt]+g[cnt]+0.5,g[cnt^1]=g[cnt]/2+0.5;
        cnt^=1;
    }
    printf("%.4lf",f[cnt]);
    return 0;
}
