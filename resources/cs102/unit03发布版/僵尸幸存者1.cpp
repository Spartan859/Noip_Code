#include<iostream>
#include<algorithm>
#define N 100005
#define ERR 0.000001
using namespace std;
bool cmp(const double&a,const double&b){
	return a+ERR<b;
}
int n;
double y,r,x[N];
int main(){
	cin>>n>>y>>r;
	for(int i=0;i<n;i++) cin>>x[i];
	int lb=lower_bound(x,x+n,y-r,cmp)-x;
	int ub=upper_bound(x,x+n,y+r,cmp)-x;
	int death=ub-lb;
	cout<<n-death<<endl;
	//cout<<lb<<endl;
	//cout<<ub<<endl;
	return 0;
}

