#include <bits/stdc++.h>
using namespace std;
int m,n,x,p,y,ans,T;
vector <int> v[300];
int _link[20100];
bool vis[20001];
bool find(int x)
{
  if(x==0) return true;
  for(int i=0; i<v[x].size(); i++)
  {
    if(!vis[v[x][i]])
    {
      vis[v[x][i]]=1;
      if(_link[v[x][i]]==0||find(_link[v[x][i]]))
      {
        _link[v[x][i]]=x;
        return true;
      }
    }
  }
  return false;
}
int main()
{
  scanf("%d",&T);
  while(T--)
  {
    memset(_link,0,sizeof(_link));
    memset(v,0,sizeof(v));
    scanf("%d%d",&p,&n);
    for(int i=1; i<=p; i++)
    {
      scanf("%d",&m);
      for(int j=1; j<=m; j++)
      {
        scanf("%d",&y);
        v[i].push_back(y);
      }
    } 
    if(p>n)
    {
      printf("NO\n");
      continue ;
    }
    ans=0;
    for(int i=1; i<=p; i++)
    {
      memset(vis,0,sizeof(vis));
      if(find(i)) ans++;
    }
    if(ans==p)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
