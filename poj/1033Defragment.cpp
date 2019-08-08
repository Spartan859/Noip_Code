#include <bits/stdc++.h>
using namespace std;
const int maxn=50000+10;
int n,m,head[maxn],tot,ans,up;

struct node{
    int to,next,val;
}e[maxn<<1];

multiset<int> s[maxn];
multiset<int>::iterator it;

inline int read(){
    register int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch)){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return (f==1)?x:-x;
}

inline void add(int x,int y,int w){
    e[++tot].to=y;
    e[tot].val=w;
    e[tot].next=head[x];
    head[x]=tot;
}

int dfs(int x,int fa,int k){
    s[x].clear();
    int val;
    for(int i=head[x],y;i;i=e[i].next){
        y=e[i].to;
        if(y==fa) continue;
        val=dfs(y,x,k)+e[i].val;
        if(val>=k) ans++;
        else {
            s[x].insert(val);
        }
    }
    int Max=0;
    while(!s[x].empty()){
        if(s[x].size()==1){
            return max(Max,*s[x].begin());
        }
        it=s[x].lower_bound(k-*s[x].begin());
        if(it==s[x].begin()&&s[x].count(*it)==1) it++;
        if(it==s[x].end()){
            Max=max(Max,*s[x].begin());
            s[x].erase(s[x].find(*s[x].begin()));
        }
        else {
            ans++;
            s[x].erase(s[x].find(*it));
            s[x].erase(s[x].find(*s[x].begin()));
        }
    }
    return Max;
}

int check(int k){
    ans=0;
    dfs(1,0,k);
    if(ans>=m) return 1;
    return 0;
}

int dfs1(int x,int fa){
    int sum1=0,sum2=0;
    for(int i=head[x],y;i;i=e[i].next){
        y=e[i].to;
        if(y==fa) continue;
        sum2=max(sum2,dfs1(y,x)+e[i].val);
        if(sum1<sum2) swap(sum1,sum2);
    }
    up=max(ans,sum1+sum2);
    return sum1;
}


int main()
{
    n=read(),m=read();
    int x,y,w;
    for(int i=1;i<n;i++){
        x=read(),y=read(),w=read();
        add(x,y,w);add(y,x,w);
    }
    dfs1(1,0);
    int l=1,r=up,mid;
    while(l<r){
        mid=l+r+1>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    printf("%d\n",l);
    return 0;
}
