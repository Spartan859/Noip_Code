#include<iostream>
#include<algorithm>
#define N 100005
using namespace std;
int n;
double y,r,x[N];
int main(){
	cin>>n>>y>>r;
	for(int i=0;i<n;i++) cin>>x[i];
	int lb=lower_bound(x,x+n,y-r)-x;
	int ub=upper_bound(x,x+n,y+r)-x;
	int death=ub-lb;
	cout<<n-death<<endl;
	//cout<<lb<<endl;
	//cout<<ub<<endl;
	return 0;
}
/*
输入样例：
2 5.0 12.2 
-7.2 17.2
输出样例：
0
*/

