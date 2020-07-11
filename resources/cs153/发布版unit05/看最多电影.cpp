#include<bits/stdc++.h>
#define N 1005
using namespace std;
struct dd{int s,t;};
bool cmp(const dd& a,const dd& b){
	return a.t<b.t||a.t==b.t&&a.s<b.s;
}
dd d[N];
int n,m,i,x,ans;
int main(){
	cin>>n>>m;	
	for(i=0;i<n;i++) cin>>d[i].s>>d[i].t;
	sort(d,d+n,cmp);
	x=-1; ans=0;
	for(i=0;i<n;i++)
		if(d[i].s>=x) {
			ans++;
			x=d[i].t;
		}
	if(n-ans>m) cout<<"今天抢救Mike Chen"<<endl;
	else cout<<"今天上区间模型"<<endl;
	return 0;
}
