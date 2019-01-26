#include<bits/stdc++.h>
using namespace std;
struct zb{
		int id;
		int tl;
};
int cmp(const zb&a,const zb&b){
	if(a.tl<b.tl) return 1;
	if(a.tl>b.tl) return 0;
	if(a.id<b.id) return 1;
	else return 0;
}
int main(){
	int n,ans;
	cin>>n;
	struct zb{
		int id;
		int tl;
	};
	zb x[n+1];
	for(int i=0;i<n;i++){
		x[i].id=i;
	    cin>>x[i].tl;
	}
	sort(x,x+n,cmp);
	while(1){
		ans++;
		x[0].tl-=2;
		for(int i=1;i<n;i++){
			if(x[i].id==x[0].id+1){
			    x[i].tl--;
			    if(x[i].tl==0) x[i].tl=101;
			}
			if(x[i].id==x[0].id-1){
			    x[i].tl--;
			    if(x[i].tl==0) x[i].tl=101;
			}
		}
		sort(x,x+n,cmp);
		if(x[0].tl==101) break;
	}
	cout<<ans<<endl;
	return 0;
}
