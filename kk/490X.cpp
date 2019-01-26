#include<bits/stdc++.h>
#define N 105
using namespace std;
int n,head=0,tail=0,d[N],ans,cnt[8];
bool cntch(){
	int check=0;
	for(int i=1;i<8;i++) if(cnt[i]>0) check++;
	if(check==7) return 1;
	return 0;
}
int main(){
	cin>>n;
	ans=n+1;
	for(int i=0;i<n;i++) cin>>d[i];
    while(1){
    	while(head<n&&!cntch()){
    		if(d[head]<8) cnt[d[head]]++;
    		head++;
		}
		if(!cntch()) break;
		ans=min(ans,head-tail);
		cnt[d[tail]]--; tail++;
	}
	if(ans!=n+1) cout<<ans<<endl;
	else cout<<"bye dragon"<<endl;
	return 0;
}
