#include<iostream>
#include<algorithm>
#define N 10005
using namespace std;
struct piece{int s,t;};
bool cmp(const piece& a,const piece& b){
	return a.s<b.s||a.s==b.s&&a.t<b.t;
}
piece d[N];
int main(){
	int n,i,j,x,a,r,T;
	cin>>T>>n;	
	for(i=0;i<n;i++){
		cin>>a>>r;
		d[i].s=a-r;
		d[i].t=a+r;
	}
	sort(d,d+n,cmp);
	int S=0,cnt=0;
	for(i=0;i<n&&S<T;i++){
		for(j=i;j<n&&d[j].s<=S;j++)
			if(d[j].t>d[i].t) i=j;
		if(d[i].s>S) break;
		S=d[i].t; cnt++; 
	}	
	if(S<T) cout<<"Impossible"<<endl;
	else cout<<cnt<<endl;	
	return 0;
}
