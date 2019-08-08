#include<cstdio>
#include<algorithm>
using namespace std;
int  c[10010];
int  x[10010];
int  y[10010];
char s[10010];
int sa[10010];
int rank[10010];
int height[10010];
int n,m;
void build_SA();
void build_rank();
void build_height();
int main()
{
    int i,j,k;
    scanf("%d%d",&n,&m);
    scanf("%s",s);
    build_SA();
    for(i=0;i<n;i++){
        for(j=sa[i];j<n;j++)
            printf("%c",s[j]);
        printf("\n");
    }
    build_rank();
    build_height();
}
void build_SA(){
    int i,j,k;
    for(i=1;i<=m;i++)c[i]=0;
    for(i=0;i<n;i++)x[i]=s[i];
    for(i=0;i<n;i++)c[x[i]]++;
    for(i=2;i<=m;i++)c[i]+=c[i-1];
    for(i=n-1;i>=0;i--)sa[--c[x[i]]]=i;
    for(k=1;k<=n;k<<=1){
        int num=0;
        for(i=n-k;i<n;i++)y[num++]=i;
        for(i=0;i<n;i++)if(sa[i]>=k)y[num++]=sa[i]-k;
        for(i=1;i<=m;i++)c[i]=0;
        for(i=0;i<=n;i++)c[x[i]]++;
        for(i=2;i<=m;i++)c[i]+=c[i-1];
        for(i=n-1;i>=0;i--)sa[--c[x[y[i]]]]=y[i],y[i]=0;
        swap(x,y);
        num=1;x[sa[0]]=1;
        for(i=1;i<n;i++)
            if(y[sa[i]]!=y[sa[i-1]]||y[sa[i]+k]!=y[sa[i-1]+k])
                x[sa[i]]=++num;
            else
                x[sa[i]]=num;
        if(num>=n)break;
        m=num;
    }
}
void build_rank(){
    for(int i=0;i<n;i++)rank[sa[i]]=i;
}
void build_height(){
    int i,j,k=0;
    for(i=0;i<n;i++){
        if(!rank[i])continue;
        if(k)k--;
        j=sa[rank[i]-1];
        while(j+k<n&&i+k<n&&s[j+k]==s[i+k])k++;
        height[rank[i]]=k;
    }
}
