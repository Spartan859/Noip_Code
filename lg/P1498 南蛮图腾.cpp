#include<bits/stdc++.h>
#define ll long long

using namespace std;
ll n;
ll rght=4;
char** x;

char** dfs(ll x,char** xx){
    char** y;
    y=new char* [2049];
    for(ll i=0;i<2049;i++) y[i]=new char[2049];
    ll tmp=(1<<(x-2));
    for(ll i=1;i<=tmp;i++)
        for(ll j=1+tmp;j<=rght+tmp;j++)
            y[i][j]=xx[i][j-tmp];
    for(ll i=1+tmp;i<=tmp+tmp;i++)
        for(ll j=1;j<=rght;j++)
            y[i][j]=xx[i-tmp][j];
    for(ll i=1+tmp;i<=tmp+tmp;i++)
        for(ll j=1+rght;j<=rght+rght;j++)
            y[i][j]=xx[i-tmp][j-rght];
    rght*=2;
    return y;
}
int main() {
    //freopen("C:\\Users\\Spartan117\\Desktop\\tmp.txt","w",stdout);

    scanf("%lld",&n);
    n++;
    x=new char* [2049];
    for(ll i=0;i<2049;i++) x[i]=new char[2049];
    for(ll i=1;i<=1024;i++)
        for(ll j=1;j<=2048;j++) x[i][j]=' ';
    x[1][2]='/';
    x[1][3]=92;
    x[2][1]='/';
    x[2][2]=x[2][3]='_';
    x[2][4]=92;
    for(ll i=3;i<=n;i++) x=dfs(i,x);
    //cout<<1<<endl;
    for(ll i=1;i<=(1<<(n-1));i++,cout<<endl)
        for(ll j=1;j<=(1<<n);j++) cout<<x[i][j];
    return 0;
}
