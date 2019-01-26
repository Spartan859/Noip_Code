
#include<bits/stdc++.h>
using namespace std;

const int len=1e4;
const int maxn=100;
int ans[maxn];

void multi()
{
  int i,last=0;
  for(i=1;i<=ans[0];i++)
    {
      ans[i]=ans[i]*2+last;
      last=ans[i]/len,ans[i]%=len;
	}
  if(last)ans[++ans[0]]=last;
}

int main()
{
  int n,i;
  scanf("%d",&n);
  ans[0]=1,ans[1]=2;
  for(i=1;i<=n;i++)multi();  
  ans[1]-=2;  printf("%d",ans[ans[0]]);
  for(i=ans[0]-1;i>=1;i--)printf("%04d",ans[i]);
  return 0;
}
//CopyRight Spartan117 2018.6.3
