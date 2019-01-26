#include<iostream>
#include<algorithm>
#define N 105
using namespace std;
int i,n,m,x[N];
int main(){
	cin>>n>>m;
	for(i=0;i<n;i++) cin>>x[i];
	int cnt=0,sum=x[0];
	if(sum>m){
		cout<<0<<endl;
		return 0;
	}
	for(i=1;i<n;i++){
		if(x[i]>m){
			cout<<0<<endl;
			return 0;
		}
		if(sum+x[i]>m){
			sum=0;
			cnt++;
		}
		sum+=x[i];
	}
	cnt++;
	cout<<cnt<<endl;
	return 0;
}


