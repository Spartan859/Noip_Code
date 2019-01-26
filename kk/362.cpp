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
	for(i=0;i<n;i++){
		int h1,m1,h2,m2; char ch;
		cin>>h1>>ch>>m1>>ch>>h2>>ch>>m2;
		d[i].s=h1*60+m1;
		d[i].t=h2*60+m2;
	}
	sort(d,d+n,cmp);
	x=-45; ans=0;
	for(i=0;i<n;i++)
		if(d[i].s>=x+45) {
			ans++;
			x=d[i].t;
		}
	cout<<ans<<endl;	
	return 0;
}
