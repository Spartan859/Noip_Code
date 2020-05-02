#include<bits/stdc++.h>
#define MAXN 2000010
using namespace std;
int n,nex[MAXN],deg[MAXN],ans,len1,len2;
bool can[MAXN],flag;
queue<int> Q;
int main() {
    memset(can,true,sizeof(can));
    scanf("%d",&n);
    for(int i=1; i<=n; i++)scanf("%d",&nex[i]),deg[nex[i]]++;
    for(int i=1; i<=n; i++)if(!deg[i])Q.push(i);
    while(!Q.empty()){
        int now=Q.front();
        Q.pop();
        ans+=can[now];
        deg[nex[now]]--;
        if(can[now])can[nex[now]]=false;
        if(!deg[nex[now]])Q.push(nex[now]);
    }
    for(int i=1,x; i<=n; i++) {
        flag=true,len1=len2=0;
        if(deg[i]) {
            x=i;
            do{
                deg[x]=0;
                if(flag)len1++;
                else len2++;
                if(!can[x])ans+=len2/2,len2=0,flag=false;
                x=nex[x];
            }while(x!=i);
            ans+=(len1+len2)/2;
        }
    }
    cout<<ans;
    return 0;
}
