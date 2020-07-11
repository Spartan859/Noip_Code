#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int mo[n+1],st[m+1],en[m+1],ans;
	for(int i=0;i<n;i++) cin>>mo[i];
	for(int j=0;j<m;j++) cin>>st[j]>>en[j];
	//input end
	for(int a=0;a<m;a++){
		ans=0;
		for(int b=st[a]-1;b<en[a];b++){
			ans+=mo[b];
		}
		cout<<ans<<' ';
	}
	return 0;
} 
