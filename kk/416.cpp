#include<bits/stdc++.h>
using namespace std;
int n,x,y;
int solve_BL(int n,int x,int y){
	int ans=2e9;
	for(int i=0;i<=n&&x-i*2>=0;i++)
	    ans=min(ans,(max(x-i*2,0)+2)/3+(max(y-n+i,0)+1)/2);
	return ans+n;
}
int solve_ALL(int n,int x,int y){
	if(n<=12||x<=24) return solve_BL(n,x,y);
	int t=min((x+1)/2,n);
	return solve_ALL(n-t,max(x-t*2,0),y)+t;
}
int main(){
	cin>>n>>x>>y;
	cout<<solve_ALL(n,x,y);
	return 0;
}
