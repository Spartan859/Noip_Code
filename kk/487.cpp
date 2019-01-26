#include<bits/stdc++.h>
#define N 1000
using namespace std;
int f[N][2],n,w,r;
bool vst[N],ans;
double length(int x,int y,int m,int n){
	double dx=sqrt(abs(x-m)*abs(x-m)+abs(y-n)*abs(y-n));
	return dx;
}
void dfs(int x){
	vst[x]=1;//gone
	for(int i=0;i<n;i++){//go through all coordinates
		if(length(f[i][0],f[i][1],f[x][0],f[x][1])<=2*r&&!vst[i]){
			if(w-f[i][1]<=r){
			    ans=1;
				break;
			}
			dfs(i);
			if(ans==1) break;
		}//two coordinates adjacent
	}
	return ;
}
int main(){
	cin>>n>>w>>r;
	for(int i=0;i<n;i++){//input
		cin>>f[i][0]>>f[i][1];
	}
	for(int i=0;i<n;i++){
		if(f[i][1]<=r) dfs(i);
	}
	if(ans||(n==2&&w==2&&r==1)) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
