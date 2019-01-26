#include<iostream>
#include<algorithm>
#define N 100005
#define ERR 0.000001
using namespace std;
int n;
double r,x[N];
bool cmp(const double&a,const double&b){
	return a+ERR<b;
}
int bomb(double y){
	int lb=lower_bound(x,x+n,y-r,cmp)-x;
	int ub=upper_bound(x,x+n,y+r,cmp)-x;
	int death=ub-lb;
	return n-death;
}
int main(){
	cin>>n>>r;
	for(int i=0;i<n;i++) cin>>x[i];
	double l=-100,r=100;
	int ans=100001;
	sort(x,x+n,cmp);
	for(double i=l;i<=r;i+=0.01){
		if(bomb(i)<ans) ans=bomb(i);
		if(ans==0) break;
	}
	cout<<ans<<endl;
	return 0;
}
