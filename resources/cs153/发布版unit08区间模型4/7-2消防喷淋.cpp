#include<iostream>
#include<algorithm>
#include<cmath>
#define N 105
#define ERR 0.000001
using namespace std;
struct device{double s,t;};
bool cmp(const device& a,const device& b){
	return a.s<b.s||a.s==b.s&&a.t<b.t;
}
device d[N];
int main(){
	int n,i,j,cnt=0;	
	double L,W,x,r;	
	cin>>n>>L>>W;
	for(i=j=0;i<n;i++) {
		cin>>x>>r;
		if(r<=W/2) continue;
		d[j].s=x-sqrt(r*r-W*W/4);
		d[j++].t=x+sqrt(r*r-W*W/4);
	}
	n=j;
	sort(d,d+n,cmp);
	double S=0,T=L;
	for(i=0;i<n&&S<T-ERR;i++){
		for(j=i;j<n&&d[j].s<=S+ERR;j++)
			if(d[j].t>d[i].t) i=j;
		if(d[i].s>S+ERR) break;
		S=d[i].t; cnt++; 
	}
	if(S<T-ERR) cout<<-1<<endl;
	else cout<<cnt<<endl;
	return 0;
}


