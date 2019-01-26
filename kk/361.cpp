#include<iostream>
#include<algorithm>
#define N 105
using namespace std;
struct movie{int s,t;};
bool cmp(const movie& a,const movie& b){
	return a.t<b.t||a.t==b.t&&a.s<b.s;
}
movie d[N];
int n,i,x,ans;
int main(){
	cin>>n;	
	for(i=0;i<n;i++) cin>>d[i].s>>d[i].t;
	sort(d,d+n,cmp);
	x=-1; ans=0;
	for(i=0;i<n;i++)
		if(d[i].s>=x) {
			ans++;
			x=d[i].t;
		}
	cout<<ans<<endl;	
	return 0;
}
