#include<iostream>
#define N 110
using namespace std;
int n,m,x[N];
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>x[i];
	int ans=n+1;
	for(int tail=0;tail<n;tail++){
		int sum=0;
		for(int head=tail;head<n;head++){
			sum+=x[head];
			if(sum>=m)
				ans=min(ans,head+1-tail);
		}
	}
	cout<<ans<<endl; 	
	return 0;
}


