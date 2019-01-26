#include<cstdio>
#include<cstring>
const int maxn=1e3+10;
const int maxm=1e5+10;
inline int min_(int x,int y){return x<y?x:y;}
int n,m,ans,now,top,map,lng=1e9;
int s[maxm],v[maxn]={1};
struct tree{int tn,tp;}t[maxm][30];
char ch[12];
void add(int k,int i){
    if(ch[i]==0) return;
    int next=ch[i]-'a';
    if(!t[k][next].tn) t[k][next].tn=++top;
    add(t[k][next].tn,i+1);
}
int search(int k,int i){
    int next=ch[i]-'a';
    if(ch[i]==0){
        if(!t[k][0].tp) t[k][0].tp=++map;
        return t[k][0].tp;
    }
    if(!t[k][next].tn) return 0;
    return search(t[k][next].tn,i+1);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s",ch);
        add(0,0);
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
       scanf("%s",ch);
       s[i]=search(0,0);
       if(!v[s[i]]) v[s[i]]++,ans++;
    }
    printf("%d\n",ans);
    memset(v,0,sizeof(v)),v[0]=1;
    for(int i=1,j=1;i<=m;i++){
        while(now<ans&&j<=m){
            if(!v[s[j]]) now++;
            v[s[j]]++;
            j++;
        }
        if(now==ans) lng=min_(lng,j-i);
        v[s[i]]--;
        if(!v[s[i]]) now--;
    }
    printf("%d\n",lng);
    return 0;
}
