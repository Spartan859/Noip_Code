#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#define maxn 200005
#define inf 2e9
#define ll long long
using namespace std;
int n,rk,t,dy[maxn],t1,t2;
struct node{
    int pl,d,id;
}s[maxn],a[maxn],b[maxn];
int pd(ll k){
    int l=0,r=t1,sum=0;
    while(l<r){
        int mid=l+r+1>>1;
        if(a[mid].pl-t<=k)l=mid;
        else r=mid-1;
    }
    sum=sum+l;
    l=0,r=t2;
    while(l<r){
        int mid=l+r+1>>1;
        if(b[mid].pl+t<=k)l=mid;
        else r=mid-1;
    }
    sum=sum+l;
    //cout<<k<<' '<<sum<<endl;
    return sum;
}
bool cmp(node a,node b){
    return a.pl<b.pl;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&s[i].pl);
        s[i].id=i;
    }
    for(int i=1;i<=n;i++)scanf("%d",&s[i].d);
    sort(s+1,s+n+1,cmp);
    for(int i=1;i<=n;i++){
        dy[s[i].id]=i;
        if(s[i].d==0)a[++t1]=s[i];
        else b[++t2]=s[i];
    }
    int Q;cin>>Q;
    for(int i=1;i<=Q;i++){
        scanf("%d%d",&rk,&t);rk++;
        rk=dy[rk];
        ll l=-inf,r=inf;
        while(l<r){
            ll mid=l+r>>1;
            if(pd(mid)<rk)l=mid+1;
            else r=mid;
        }
        printf("%lld\n",l);
    }
    return 0;   
}
