#include<cstdio>
#include<algorithm>
#define maxn 100000
using namespace std;

int n,r,q;
int a[maxn*2+100],win[maxn+100],lose[maxn+100];
int s[maxn*2+100],w[maxn*2+100];

bool cmp(int x,int y)
{
  if(s[x]!=s[y])return s[x]>s[y];
  return x<y;
}

bool MAX(int x,int y)
{
  if(s[x]!=s[y])return s[x]>s[y];
  return x<y;
}

void merge()
{
  int i,j,k;
  i=j=1,a[0]=0;
  while(i<=win[0] && j<=lose[0])
    if(MAX(win[i],lose[j]))
      a[++a[0]]=win[i++];
    else 
	  a[++a[0]]=lose[j++];
  while(i<=win[0])a[++a[0]]=win[i++];
  while(j<=lose[0])a[++a[0]]=lose[j++];  	  
}

int main()
{
  int i,j,k;
  scanf("%d%d%d",&n,&r,&q),n<<=1;
  for(i=1;i<=n;i++)a[i]=i;
  for(i=1;i<=n;i++)scanf("%d",&s[i]);
  for(i=1;i<=n;i++)scanf("%d",&w[i]);
  sort(a+1,a+n+1,cmp);
  
  for(i=1;i<=r;i++)
    {
      win[0]=lose[0]=0;
      for(j=1;j<=n;j+=2)
        if(w[a[j]]>w[a[j+1]])
          {
            s[a[j]]++;
            win[++win[0]]=a[j];
            lose[++lose[0]]=a[j+1];
          }
        else
		  {
		    s[a[j+1]]++;
		    win[++win[0]]=a[j+1];
		    lose[++lose[0]]=a[j];
		  }  
      merge();		  
    }
  printf("%d\n",a[q]);    
  return 0;
}
