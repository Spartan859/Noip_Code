#include<iostream>
#include<algorithm>
#define N 105
using namespace std;
struct ke{int s,t;};
bool cmp(const ke& a,const ke& b){
	return a.t<b.t||a.t==b.t&&a.s<b.s;
}
ke d[N];
int main(){
	int n,i,j,k,x[N],cnt=0;
	cin>>n;	
	for(i=0;i<n;i++) cin>>d[i].s>>d[i].t;
	sort(d,d+n,cmp);
	d[n]=-1;
	for(i=0;i<n;i++){
		for(j=0,k=n;j<cnt;j++)
			if(d[i].s>x[j]&&x[j]>x[k]) k=j;
		if(k<n) x[k]=d[i].t;
		else x[cnt++]=d[i].t;
	}
	cout<<cnt<<endl;	
	return 0;
}


