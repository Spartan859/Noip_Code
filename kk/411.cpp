#include<bits/stdc++.h>
#define R 21
#define A 30
using namespace std;
int m,n,cnt[R][2],temp;
int main(){
	cin>>m>>n;
	int y[m];
	for(int i=0;i<m;i++){
		cin>>y[i];
	}
	for(int i=0;i<m;i++) cin>>cnt[y[i]-A][1];
	for(int i=0;i<n;i++){
		cin>>temp;
		cnt[temp-A][0]+=2;
	}
	int ans=0;
	for(int i=0;i<R;i++) ans+=cnt[i][0]*cnt[i][1];
	cout<<ans<<endl;
	//for(int i=0;i<R;i++) cout<<cnt[i][0]<<' '<<cnt[i][1]<<endl;
	//for(int i=0;i<m;i++) cout<<y[i];
	return 0;
}
