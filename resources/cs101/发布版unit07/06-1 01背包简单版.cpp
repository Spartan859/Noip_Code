#include <iostream>
#define MAXC 1001 
#define MAXN 501
using namespace std;
int n,C,w[MAXN],v[MAXN],f[MAXN][MAXC]; 
int main(){
	cin>>C>>n;
	for(int i=1;i<=n;++i) cin>>w[i]>>v[i];		
	// f[i][j]代表从前i件物品中选，背包载重不超过j，最大价值 
	for (int i=1;i<=n;++i)   //循环查看物品i 
		for (int j=0;j<=C;++j)   //循环查看背包剩余重量j 
			if(j<w[i])   // 物品i太重，无法放入 
				f[i][j]=f[i-1][j];
			else 		// 比较两种决策：物品i可以放，或者不放
				f[i][j]=max(f[i-1][j],f[i-1][j-w[i]]+v[i]);
	cout<<f[n][C]<<endl; 
	return 0;
} 


