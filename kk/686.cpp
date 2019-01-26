#include<bits/stdc++.h> 
#define N 505
using namespace std;
int n,w,ans,i,j,x[N],y[N],d[N][N];bool vst[N],t;
int dist(int x1,int y1,int x2,int y2){
 return pow((x1-x2),2)+pow((y1-y2),2);
}
void dfs(int id,int m){
 if(y[id]>=w-m){t=1;return;}
 vst[id]=1;
 for(int k=1;k<=n;k++){
  if(d[id][k]<=4.0*m*m&&!vst[k])dfs(k,m);
  if(t)return;
 }
}
bool ok(int m){
 t=0;fill(vst,vst+n+1,0);
 for(int k=1;k<=n;k++)
  if(y[k]<=m&&!vst[k])dfs(k,m);
 return t;
}
int main(){
 freopen("lightkungfu2.in","r",stdin);
 freopen("lightkungfu2.out","w",stdout);
 cin>>n>>w;
 for(i=1;i<=n;i++)cin>>x[i]>>y[i];
 for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
   d[i][j]=dist(x[i],y[i],x[j],y[j]);
 int l=1,r=w;
 while(l<=r){
  int mid=l+(r-l)/2;
  if(ok(mid))ans=mid,r=mid-1;
  else l=mid+1;
 }
 //for(ans=0;ans<=w;ans++)if(ok(ans))break;
 cout<<ans;
 return 0;
}

