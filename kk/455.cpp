#include<iostream>
#include<algorithm>
#define N 100005 
#define INF 2e9
using namespace std;
int n=0,d[N],x[N];
int main(){//最长上升子序列长度=不升子序列最小划分数 
	while(cin>>x[n]) n++;//input 
	fill(d,d+n,INF);//fill with infinity
	for(int i=0;i<n;i++)
		*lower_bound(d,d+n,-x[i])=-x[i];
	int cnt=lower_bound(d,d+n,INF)-d;
	cout<<cnt<<endl;
	return 0;
}
