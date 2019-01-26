#include<bits/stdc++.h>
#define N 105
using namespace std;
int n,d[N],ansfi;
int main(){
	cin>>n;
	ansfi=n+1;
	for(int i=0;i<n;i++) cin>>d[i];
	for(int tail=0;tail<n;tail++){
		int cnt[8]={0};
		for(int head=tail;head<n;head++){
			int ans=0;
			if(d[head]<8) cnt[d[head]]++;
			for(int i=1;i<8;i++) if(cnt[i]>0) ans++;
			if(ans==7){
			    ansfi=min(head-tail+1,ansfi);
		    }
		}
	}
	if(ansfi!=n+1) cout<<ansfi<<endl;
	else cout<<"bye dragon"<<endl;
	return 0;
}
