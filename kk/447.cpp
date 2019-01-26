#include<bits/stdc++.h>
#define ERR 0.000001
#define N 100005 
using namespace std;
int v[N],p[N]; double z[N];
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
	for(int i=0;i<n;i++) cin>>p[i];
	for(int i=0;i<n;i++) cin>>v[i];
	double maxv=*max_element(v,v+n);
	double minp=*min_element(p,p+n);
	if(minp==0) minp=1;
	double l=0,r=maxv/minp,ans=0;
	while(r-l>ERR){
		double mid=l+(r-l)/2;
		if(OK(mid))ans=l=mid;
		else r=mid;
	}
	cout<<fixed<<setprecision(2)<<ans*100<<"%"<<endl;
	return 0;
}
