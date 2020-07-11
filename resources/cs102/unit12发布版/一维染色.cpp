#include<iostream>
#include<algorithm>
#define N 15
#define nCOLORS 3
using namespace std;
char colors[nCOLORS]={'B','G','R'};
int n,p[N];
void print(){
	for(int i=0;i<n;i++)cout<<colors[p[i]];
	cout<<endl;
}
void dfs(int x){ 
	if(x==n){print();return;}
	for(int i=0;i<nCOLORS;i++)
		if(x==0||p[x-1]!=i){
			p[x]=i;
			dfs(x+1);			
		}
}
int main(){
	cin>>n;
	dfs(0);
	return 0;
}



