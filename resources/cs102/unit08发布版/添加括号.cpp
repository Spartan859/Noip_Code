#include<iostream>
#include<string>
#define N 105
#define INF 1000
using namespace std;
string s;
int n,f[N][N],v[N];
bool match(char a,char b){
	return a=='('&&b==')'||a=='['&&b==']';
}
int main(){//f[i][j]将i到j位配对至少插入几个 
	cin>>s;
	n=s.size();
	fill(f[0],f[0]+N*N,INF);
	for(int i=0;i<n;i++)f[i][i]=1; 
	for(int i=0;i<n-1;i++)
		if(match(s[i],s[i+1]))f[i][i+1]=0;
		else f[i][i+1]=2;
	for(int i=n-3;i>=0;i--)
		for(int j=i+2;j<=n-1;j++){
			for(int k=i;k<=j-1;k++)
				f[i][j]=min(f[i][k]+f[k+1][j],f[i][j]);
			if(match(s[i],s[j]))
				f[i][j]=min(f[i+1][j-1],f[i][j]);
		}
	cout<<f[0][n-1]<<endl;
	return 0;
}
