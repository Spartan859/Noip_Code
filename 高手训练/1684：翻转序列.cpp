#include <cstdio>
#include <algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fod(i,a,b) for(int i=a;i>=b;i--)
#define abs(q) ((q)>0?(q):-(q))
using namespace std;
const int N=26,M=1840177;
int read(int &n)
{
    int w=1;n=0;char ch=' ';
    for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch<='9'&&ch>='0';ch=getchar())n=n*10LL+ch-48;
    return n=w*n;
}
int n,m,ans;
int a[N];
int JS()
{
    int ans=0;
    fo(i,1,n)if(abs(a[i-1]-a[i])>1)ans++;
    return ans;
}
void dfs(int e,int js,int T)
{
    if(T>ans)return;
    if(e>=ans)return;
    if(js<1)
    {
        ans=min(ans,e);
        return;
    }
    if(e+js>T)return;
    fo(i,2,n)
    {
        int w=i>>1;
        int q=js-(abs(a[i]-a[i+1])>1)-(a[1]>1);
        q+=(abs(a[1]-a[i+1])>1)+(a[i]>1);
        if(i==n)q=js-(a[1]>1)+(a[n]>1);
        if(e+1+q<=T)
        {
            fo(j,1,w)swap(a[j],a[i-j+1]);
            dfs(e+1,q,T);
            fo(j,1,w)swap(a[j],a[i-j+1]);
        }
    }
}
int main()
{
    int q,_;
    read(_);
    fo(I,1,_)
    {
        read(n);
        fo(i,1,n)read(a[i]);
        ans=1e9;
        q=JS();
        fo(i,q,n*2)
        {
            if(i>=ans)break;
            dfs(0,q,i);
        }
        printf("%d\n",ans);
    }
    return 0;
} 
