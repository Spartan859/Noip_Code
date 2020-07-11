#include<iostream>
#include<algorithm>
#include<string>
#define N 15
#define nCOLORS 3
using namespace std;
string s;
char colors[nCOLORS]={'B','G','R'};
int n,p[N];
void print(){
	for(int i=0;i<n;i++)cout<<colors[p[i]];
	cout<<endl;
}
void dfs(int x){ 
	if(x==n){print();return; }
	if(p[x]>=0){dfs(x+1);return;}
	for(int i=0;i<nCOLORS ;i++)
		if(x==0&&p[1]!=i||x==n-1&&p[n-2]!=i||x>0&&x<n-1&&p[x+1]!=i&&p[x-1]!=i){
			p[x]=i;
			dfs(x+1);		
			p[x]=-1;
		}
}
int main(){
	cin>>s;
	n=s.size();
	fill(p,p+n+1,-1);
	for(int i=0;i<n;i++)
		if(s[i]=='B')p[i]=0;
		else if(s[i]=='G')p[i]=1;
		else if(s[i]=='R')p[i]=2;
	dfs(0);
	return 0;
}


