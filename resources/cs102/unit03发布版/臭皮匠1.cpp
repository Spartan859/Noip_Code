#include<iostream>
#include<algorithm>
#define N 105
using namespace std;
int i,n,m,x[N];
int main(){
	cin>>n>>m;
	for(i=0;i<n;i++) cin>>x[i];
	int cnt=0,sum=0;
	for(i=0;i<n;i++){
		sum+=x[i];
		if(sum>=m){ 
			sum=0;
			cnt++;
		}
	}	
	cout<<cnt<<endl;
	return 0;
}


