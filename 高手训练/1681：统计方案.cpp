#include <cstdio>
#include <iostream>
#include <map> 
using namespace std;
long long n,na,p,c,ans,sox,soy;
map<long long,long long> ma,mb; //hashmap
long long a[100];
long long absxx(long long x) {
    return(x>0)?x:-x;
}
void dfs(int x,int ys) {
    if (x>na) {
        if (ys==c) ans++;
        ma[ys]++;
        return;
    }
    dfs(x+1,ys*a[x]%p);	
    dfs(x+1,ys);
}
void dfs2(int x,int ys) {
    if (x>n) {
        if (ys==c) ans++;
        mb[ys]++;
        return;
    }
    dfs2(x+1,ys*a[x]%p);
    dfs2(x+1,ys);
}
long long gcd(long long a,long long b) {
    return (b)?gcd(b,a%b):a;
}
void exgcd(long long a,long long b) {
    if (b==0) {
        sox=1;
        soy=0;
        return;
    }
    exgcd(b,a%b);
    int tmp=sox;
    sox=soy;
    soy=tmp-a/b*soy;
}
int main() {
    ma.clear();
    mb.clear();
    cin>>n>>p>>c;
    if(c>=p) {
        printf("0");
        return 0;

    }
    na=n/2;
    for (int i=1; i<=n; i++) cin>>a[i];
    for (int i=1; i<=na; i++) dfs(i+1,a[i]);
    for (int i=na+1; i<=n; i++) dfs2(i+1,a[i]);
    map<long long,long long>::iterator it; 
    for (it=mb.begin(); it!=mb.end(); it++) {
        int ys=it->first; 
        sox=soy=0;
        exgcd(ys, p);
        long long gc=gcd(ys,p);
        if (c%gc!=0) continue;
        sox=sox*(c/gc)%p;
        if (sox<0) sox+=absxx(sox)/p*p;;
        if (sox<0) sox+=p;
        while (sox<p) {
            if (ma[sox]!=0) {
                ans=(ans+ma[sox]*it->second)%1000000007;
            }
            sox+=p;
        }
    }
    cout<<ans<<endl;
}
