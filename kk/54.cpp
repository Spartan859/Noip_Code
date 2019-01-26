#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 16
using namespace std;

int n,m,r,c,a[maxn+5][maxn+5];
int b[maxn+5],f[maxn+5][maxn+5];
int ans=2000000000;

void work(int s)
{
  int i,j,k,x,p;
  for(b[0]=i=0;i<n;i++)
    if(s&(1<<i))b[++b[0]]=i+1;
  
  memset(f,90,sizeof(f));
  
  for(i=1;i<=m;i++)
    for(f[i][1]=0,j=2;j<=b[0];j++)
	  f[i][1]+=abs(a[b[j]][i]-a[b[j-1]][i]);
  
  for(j=2;j<=c;j++)
    for(i=j;i<=m;i++)
	  for(k=j-1;k<i;k++)
	    {
	   	  for(x=0,p=1;p<=b[0];p++)x+=abs(a[b[p]][k]-a[b[p]][i]);
   	      f[i][j]=min(f[i][j],f[k][j-1]+f[i][1]+x);
		}
  for(i=c;i<=m;i++)ans=min(ans,f[i][c]);		
}

int main()
{
  int i,j,k;
  scanf("%d%d%d%d",&n,&m,&r,&c);
  for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
      scanf("%d",&a[i][j]);
  
  int s=0,e=0,x,t;
  for(i=0;i<r;i++)s=s|(1<<i);
  for(i=n-r;i<n;i++)e=e|(1<<i);
  while(s<=e)
    {
      work(s);
      x=s&(-s),t=s+x;
      s=t|((s^t)/x)>>2;
    }  
  printf("%d\n",ans);  
  return 0;
}
