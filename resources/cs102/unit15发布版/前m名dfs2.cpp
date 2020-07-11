#include<iostream>
#include<algorithm>
#define N 10
using namespace std;
string team[N];
int m,n=8,p[N];
bool vst[N];
void print(){
	for(int i=0;i<m-1;i++)cout<<team[p[i]]<<" ";
	cout<<team[p[m-1]]<<endl;
}
int x;
void dfs(){ 
	if(x==m){print();return;}
	for(int i=0;i<n;i++)
		if(!vst[i]){
			vst[i]=1;p[x]=i;x++;
			dfs();
			vst[i]=0;x--;			
		}
}
int main(){
	cin>>m;
	for(int i=0;i<n;i++)
		cin>>team[i];
	sort(team,team+n);
	x=0;
	dfs();
	return 0;
}


