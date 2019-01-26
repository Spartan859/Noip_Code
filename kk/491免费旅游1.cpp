#include<bits/stdc++.h>
#define N 1005
using namespace std;
int n,m,head=0,tail=0,d[N],ans,cnt[205],maxx=0;
bool cntch(){
	int check=0;
	for(int i=0;i<=maxx;i++) if(cnt[i]>0) check++;
	if(check>=m) return 1;
	return 0;
}
int main(){
	cin>>n>>m;
	ans=n+1;
	for(int i=0;i<n;i++) {
	    cin>>d[i];
	    maxx=max(maxx,d[i]);
	}
    while(1){
    	while(head<n&&!cntch()){
    		cnt[d[head]]++;
    		head++;
		}
		if(!cntch()) break;
		ans=min(ans,head-tail);
		cnt[d[tail]]--; tail++;
	}
	if(ans!=n+1) cout<<ans<<endl;
	else cout<<"impossible"<<endl;
	return 0;
}
