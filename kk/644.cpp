#include<bits/stdc++.h>
#define N 20005
using namespace std;
int n,m,a,b,vst[N],BiG=1;
vector<int> es[N];
void dfs(int p,int color){
	if(!BiG) return;
	vst[p]=color;
	for(int i=0;i<es[p].size();i++)
	    if(!vst[es[p][i]]) dfs(es[p][i],3-color);
	    else if(vst[es[p][i]]==color){BiG=0;break;} 
}
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		es[a].push_back(b);
		es[b].push_back(a);
	}
	for(int i=1;i<=n&&BiG;i++){
		if(!vst[i]) dfs(i,1);
	}
	cout<<(BiG==1?"Yes":"No")<<endl;
	return 0;
} 
