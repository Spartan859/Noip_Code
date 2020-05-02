#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k;
ll dfs(ll n,ll k){
	if(k==1) return 1;
	if(n<k) return 0;
	return dfs(n-1,k-1)+dfs(n-k,k);
}
int main(){
	scanf("%d%d",&n,&k);
	printf("%d\n",dfs(n,k));
	return 0;
}
