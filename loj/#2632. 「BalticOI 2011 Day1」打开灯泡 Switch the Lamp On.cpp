#include<bits/stdc++.h>
#define ll long long
#define MAXX 550
using namespace std;

ll dis[MAXX][MAXX];
bool vis[MAXX][MAXX],Map[MAXX][MAXX];
ll dx[4]={1,-1,1,-1};
ll dy[4]={1,-1,-1,1};
ll t,r,c;
char s[MAXX];

inline bool check(ll x,ll y){
    if(x>=1&&y>=1&&x<=r+1&&y<=c+1)return true;
    else return false;
}
inline ll edge(ll x,ll xx,ll y,ll yy){
    if((xx<x&&yy<y)||(xx>x&&yy>y))return !Map[min(x,xx)][min(y,yy)];
    else return Map[min(x,xx)][min(y,yy)];
}
inline void bfs(){
    Map[0][0]=1;
    deque< pair < pair<ll ,ll> ,pair<ll ,ll > > >q;
    pair<ll ,ll > u=make_pair(0,0);
    pair<ll ,ll > v=make_pair(1,1);
    q.push_back(make_pair(u,v));
    dis[0][0]=0;
    while(!q.empty()){
        pair< pair<ll ,ll > , pair<ll ,ll > >t=q.front();
        q.pop_front();
        pair<ll ,ll >u=t.first;
        pair<ll ,ll >v=t.second;
        ll xx=u.first;
        ll yy=u.second;
        ll x=v.first;
        ll y=v.second;
        if(vis[x][y])continue;
        dis[x][y]=dis[xx][yy]+edge(x,xx,y,yy);
        vis[x][y]=1;
        for(ll i=0;i<4;++i){
            ll xv=x+dx[i];
            ll yv=y+dy[i];
            pair<ll ,ll >s=make_pair(xv,yv);
            if(check(xv,yv)&&!vis[xv][yv]){
                if(edge(xv,x,yv,y))q.push_back(make_pair(v,s));
                else q.push_front(make_pair(v,s));
            }
        }
    }
}
int main(){
    scanf("%d%d",&r,&c);
    for(ll i=1;i<=r;++i){
        scanf("%s",s+1);
        for(ll j=1;j<=c;++j)
        	if(s[j]=='\\')Map[i][j]=1;
            else Map[i][j]=0;
    }
    bfs();
    if(vis[r+1][c+1])printf("%d\n",dis[r+1][c+1]);
    else printf("NO SOLUTION\n");
    return 0;
}
