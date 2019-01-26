#include<bits/stdc++.h>
using namespace std;
string missile;
int f[2005][205];
int n,m;
int maxx=0;
bool good=true;
int main(){
    //freopen 
    cin>>n>>m;
    cin>>missile;
    for(int j=0;j<=m;j++)
    f[0][j]=1;
    for(int i=1;i<n;i++)
    for(int j=m;j>=0;j--){
        if(missile[i]==missile[i-1]) f[i][j]=f[i-1][j]+1;
        else
            if(j!=m)f[i][j]=max(f[i-1][j+1]+1,f[i-1][j]);
            else f[i][j]=f[i-1][j];
    }
    for(int i=0;i<=m;i++){
        maxx=max(maxx,f[n-1][i]);
    }
    cout<<maxx;
    return 0;
}
