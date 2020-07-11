#include<iostream>
#include<algorithm>
#define N 20
using namespace std;
struct game{int s,t;};
bool cmp(const game& a,const game& b){
	return a.s<b.s||a.s==b.s&&a.t<b.t;
}
game d[N];
int main(){
	int n,i,j,x[N],cnt=0;
	cin>>n;	
	for(i=0;i<n;i++) {
		cin>>d[i].s;
		d[i].t=d[i].s+200;
	}
	sort(d,d+n,cmp);
	for(i=0;i<n;i++){
		for(j=0;j<cnt;j++)
			if(d[i].s>=x[j]) break;
		if(j<cnt) x[j]=d[i].t;
		else x[cnt++]=d[i].t;
	}
	cout<<cnt<<endl;	
	return 0;
}


