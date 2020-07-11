#include<iostream>
#include<algorithm>
#define N 1005 
using namespace std;
int n,i,j,d[N],x[N];
int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>x[i];
	int cnt=0;
	for(i=0;i<n;i++){
		for(j=0;j<cnt;j++)
			if(d[j]>=x[i])break;
		d[j]=x[i];
		if(j==cnt)cnt++;
	}
	cout<<cnt<<endl; 
	return 0;
}


