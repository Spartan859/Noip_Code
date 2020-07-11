#include<bits/stdc++.h>
#define N 200010
#define p1 100007
#define p2 233333
#define limit 27

using namespace std;
  
int len,ans,ra[N],rb[N],standard[2][N],suma[2][N],sumb[2][N];
char a[N],b[N];
  
void init(){
    for(int i=len;i>=0;i--){
        a[i<<1]=a[i],b[i<<1]=b[i];
        a[i<<1|1]=b[i<<1|1]='#';
    }
    len=len<<1|1;
    a[0]=b[0]='@',a[1]=b[1]='#',a[len+1]=b[len+1]='$',standard[0][0]=standard[1][0]=1;
}
  
void manacher(char *s,int *radius)//manacher
{
    int maxright=0,mid;
    for(int i=1;i<=len;i++)
    {
        if(i<maxright)radius[i]=min(radius[(mid<<1)-i],maxright-i+1);
        else radius[i]=1;
        while(s[i-radius[i]]==s[i+radius[i]])radius[i]++;
        if(i+radius[i]-1>maxright)
        {
            maxright=i+radius[i]-1;
            mid=i;
        }
    }
}
 
void gethash()
{
    for(int i=1;i<=len;i++)
    {
        ans=max(ans,max(ra[i],rb[i]));
        standard[0][i]=(long long)standard[0][i-1]*limit%p1;
        standard[1][i]=(long long)standard[1][i-1]*limit%p2;
    }
    for(int i=2;i<len;i+=2)
    {
        suma[0][i>>1]=((long long)suma[0][(i>>1)-1]*limit+a[i])%p1;
        suma[1][i>>1]=((long long)suma[1][(i>>1)-1]*limit+a[i])%p2;
    }
    for(int i=len-1;i>=1;i-=2)
    {
        sumb[0][i>>1]=((long long)sumb[0][(i>>1)+1]*limit+b[i])%p1;
        sumb[1][i>>1]=((long long)sumb[1][(i>>1)+1]*limit+b[i])%p2;
    }
}
 
bool check(int l1,int r1,int l2,int r2,int l)
{
    int x=(suma[0][r1]-(long long)suma[0][l1-1]*standard[0][l]%p1)%p1;
    int y=(sumb[0][l2]-(long long)sumb[0][r2+1]*standard[0][l]%p1)%p1;
    x=(x+p1)%p1,y=(y+p1)%p1;
    if (x!=y)return false;
    x=(suma[1][r1]-(long long)suma[1][l1-1]*standard[1][l]%p2)%p2;
    y=(sumb[1][l2]-(long long)sumb[1][r2+1]*standard[1][l]%p2)%p2;
    x=(x+p2)%p2;y=(y+p2)%p2;
    return x==y;
}
 
int solve(int x,int y)//
{
    int l=0,r=min(x,(len>>1)-y+1),ans=0;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(x-mid+1,x,y,y+mid-1,mid))l=mid+1,ans=mid;
        else r=mid-1;
    }
    return ans;
}
 
void query()
{
    for(int i=2;i<len;i++)//T的中点在A串时
    {
        int l=i-ra[i],r=i+ra[i];
        l=(l+1)>>1,r>>=1;
        ans=max(ans,ra[i]+solve(l-1,r)*2);
    }
    for(int i=2;i<len;i++)//T的中点在B串时
    {
        int l=i-rb[i],r=i+rb[i];
        l=(l+1)>>1,r>>=1;
        ans=max(ans,rb[i]+solve(l,r+1)*2);
    }
}
  
int main()
{
    scanf("%d%s%s",&len,a+1,b+1);init();
    manacher(a,ra);manacher(b,rb);
    for(int i=1;i<=len;i++)ra[i]--,rb[i]--;//计算回文长度
    gethash();
    query();
    printf("%d\n",ans);
    return 0;
}
