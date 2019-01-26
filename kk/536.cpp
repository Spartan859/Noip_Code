#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

#define maxn 1000000+5

using namespace std;

typedef long long LL;

LL s1[maxn],s2[maxn],a[maxn<<1];
int d[maxn<<1],lim[maxn];
int n,cnt;

inline int in(){
    int x=0; char ch=getchar();
    for(;!isdigit(ch);ch=getchar());
    for(; isdigit(ch);ch=getchar()) x=x*10+ch-'0';
    return x;
}

inline int init(){
    for(int i=1;i<=n;i++) d[i]=i;
    cnt=0;
} 

int find(int x){
    if(d[x]==x) return x;
    return d[x]=find(d[x]);
}

void unite(int x,int y){
    int a=find(x),b=find(y);
    if(a==b) return;
    d[a]=b;
}

int main(){
    int T=in();
    while(T--){
        n=in(); init();
        for(int i=1;i<=n;i++){
            scanf("%lld%lld%d",&s1[i],&s2[i],&lim[i]);
            a[++cnt]=s1[i]; a[++cnt]=s2[i];
        }
        sort(a+1,a+1+cnt);
        int tot=0,flag=0;
        for(int i=1;i<=cnt;i++)
            if(a[i]!=a[i-1]) a[++tot]=a[i];
        for(int i=1;i<=n;i++){
            s1[i]=lower_bound(a+1,a+1+tot,s1[i])-a;
            s2[i]=lower_bound(a+1,a+1+tot,s2[i])-a;
            if(lim[i]==1) unite(s1[i],s2[i]);
        }
        for(int i=1;i<=n;i++)
            if(lim[i]==0 && find(s1[i])==find(s2[i])){
                flag=1; break;
            }

        if(!flag) puts("YES");
        else puts("NO");
    }
    return 0;
}
