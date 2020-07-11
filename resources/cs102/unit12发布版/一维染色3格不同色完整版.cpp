#include<iostream>
#include<algorithm>
#define N 15
#define nCOLORS 4
using namespace std;
char colors[nCOLORS]={'A','B','C','D'};
int n,p[N];
void print(){
	for(int i=0;i<n;i++)cout<<colors[p[i]];
	cout<<endl;
}
void dfs(int x){ 
	if(x==n){print();return;}
	for(int i=0;i<nCOLORS;i++)
		if(x==0||x==1&&p[x-1]!=i||x>1&&p[x-1]!=i&&p[x-2]!=i){
			p[x]=i;
			dfs(x+1);			
		}
}
int main(){
	cin>>n;
	dfs(0);
	return 0;
}
