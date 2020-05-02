#include<bits/stdc++.h>
using namespace std;
int n,m;
int findans(int n,int m){
	if(n==0) return m;
	if(m==0) return n%3;
	return findans(n-1,m)-findans(n,m-1)+findans(n-1,m-1);
}
int main(){
	cin>>n>>m;
	for(int i=0;i<=n;i++,cout<<endl)
		for(int j=0;j<=m;j++) cout<<setw(3)<<findans(i,j);
	return 0;
}
