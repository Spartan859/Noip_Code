#include<iostream>
#include<algorithm>
#include<cmath>
#define N 10005
using namespace std;
struct tower{int s,t;};
bool cmp(const tower& a,const tower& b){
	return a.s<b.s||a.s==b.s&&a.t<b.t;
}
tower d[N];
int main(){
	int m,i,j,L,x,r,cnt=0;
	cin>>L>>m;
	for(i=0;i<m;i++) {
		cin>>x>>r;
		d[i].s=x-r;
		d[i].t=x+r;
	}
	sort(d,d+m,cmp);
	int S=0,T=L;
	for(i=0;i<m&&S<T;i++){
		for(j=i;j<m&&d[j].s<=S;j++)
			if(d[j].t>d[i].t) i=j;
		if(d[i].s>S) break;
		S=d[i].t; cnt++; 
	}
	if(S<T) cout<<"Impossible"<<endl;
	else cout<<cnt<<endl;
	return 0;
}


