#include<bits/stdc++.h>
#define LL long long
#define N 1000005
using namespace std;
LL MOD,ans[N][2];
LL mod_exp(LL a, LL b) {
    LL res = 1;
    while(b > 0) {
        if(b&1)    res = (res*a)%MOD;
        a = (a*a)%MOD;
        b >>= 1;
    }
    return res;
}
LL solve(LL n, LL p) {
    int Q = p - 1, S = 0;
    while(Q%2 == 0) {
        Q >>= 1;
        S++;
    }
    if(S == 1) {return mod_exp(n, (p + 1)/4);}
    int z;
    while(1) {
        z = 1 + rand()%(p - 1);
        if(mod_exp(z, (p - 1)/2) != 1)   break;
    }
    LL c = mod_exp(z, Q);
    LL R = mod_exp(n, (Q + 1)/2);
    LL t = mod_exp(n, Q);
    LL M = S, b, i;
    while(1) {
        if(t%p == 1)  break;
        for(i = 1; i < M; ++i) {
            if(mod_exp(t, 1<<i) == 1)    break;
        }
        b = mod_exp(c, 1<<(M-i-1));
        R = (R*b)%p;
        t = (t*b*b)%p;
        c = (b*b)%p;
        M = i;
    }
    return (R%p + p)%p;
}

int main() {
    int T, a, n, i,cnt=0,tmp;
    cin>>T;
    tmp=T;
    while(T--) {
        cin>>a>>n;
        if(n == 2) {
            if(a%n == 1) ans[cnt][0]=1;
            else ans[cnt][0]=-1;
            cnt++;
            continue;
        }
        MOD = n;
        if(mod_exp(a, (n-1)/2) != 1)    {ans[cnt][0]=-1; cnt++; continue; }
        i = solve(a, n);
        if(i == n - i)  ans[cnt][0]=i;
        else ans[cnt][0]=min(i, n - i),ans[cnt][1]=max(i, n - i);
        cnt++;
    }
    for(int j=0;j<tmp;j++)
        if(ans[j][0]>0&&ans[j][1]>0) cout<<ans[j][0]<<' '<<ans[j][1]<<endl;
        else if(ans[j][0]>0) cout<<ans[j][0]<<endl;
        else cout<<"No root"<<endl;
    return 0;
}
