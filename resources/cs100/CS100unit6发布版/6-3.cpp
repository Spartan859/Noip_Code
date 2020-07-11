#include<iostream>
#include<algorithm>
#define M 5005
using namespace std;
int n,m,ans=0;
struct person{
	int id,s;
};
person p[M];
int cmp(const person &x,const person &y){
	if(x.s>y.s) return 1;
	if(x.s<y.s) return 0;
	if(x.id<y.id) return 1;
	else return 0;
}
int main(){
	cin>>n>>m;
	int t=m*1.5;
	for(int j=0;j<n;j++) cin>>p[j].id>>p[j].s;
	sort(p,p+n,cmp);
	for(int a=0;a<n;a++){
		if(p[a].s>=p[t-1].s) ++ans;
	}
	cout<<p[t-1].s<<' '<<ans<<endl;
	for(int i=0;i<n;i++){
		if(p[i].s>=p[t-1].s) cout<<p[i].id<<' '<<p[i].s<<endl;
	}
	return 0;
}
