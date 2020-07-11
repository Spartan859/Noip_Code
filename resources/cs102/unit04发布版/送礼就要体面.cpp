#include<iostream>
#include<algorithm>
#define ERR 0.000001
#define N 100005 
using namespace std;
double v[N],p[N],z[N];
int n,k;
bool OK(double x){
	for(int i=0;i<n;i++)z[i]=v[i]-x*p[i];
	sort(z,z+n);
	double sum=0;
	for(int i=n-k;i<n;i++)sum+=z[i];
	return sum>=0;
}
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>v[i]>>p[i];
	double maxv=*max_element(v,v+n);
	double minp=*min_element(p,p+n);
	double l=0,r=maxv/minp,ans=0;
	while(r-l>ERR){
		double mid=l+(r-l)/2;
		if(OK(mid))ans=l=mid;
		else r=mid;
	}
	cout<<ans<<endl;
	return 0;
}
