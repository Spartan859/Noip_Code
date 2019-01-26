#include<bits/stdc++.h>
using namespace std;
int dxy[2][9]={{0,-2,-1,1,2,2,1,-1,-2},{0,1,2,2,1,-1,-2,-2,-1}};
long long d[21][21]={1};
bool mark[21][21];
int main() {
    int nx,ny,hx,hy;
    cin>>nx>>ny>>hx>>hy;
    for(int i=0;i<9;++i)
        if(hx+dxy[0][i]>=0&&hx+dxy[0][i]<=nx&&hy+dxy[1][i]>=0&&hy+dxy[1][i]<=ny)
            mark[hx+dxy[0][i]][hy+dxy[1][i]]=1;
    for(int i=0;i<=nx;++i)
        for(int j=0;j<=ny;++j) {
            if(i)
                d[i][j]+=d[i-1][j];
            if(j)
                d[i][j]+=d[i][j-1];
            d[i][j]*=!mark[i][j];
        }
    cout<<d[nx][ny]<<endl;
    return 0;
}
