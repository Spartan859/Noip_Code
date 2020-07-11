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
	if(x==n){        }
	for(int i=0;i<      ;i++)
		if(            ){
			p[x]=    ;
			dfs(    );			
		}
}
int main(){
	cin>>n;
	dfs(0);
	return 0;
}



