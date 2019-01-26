#include<bits/stdc++.h>
using namespace std;
int n,k,x[505];
void check(int m){
	int temp=x[0],cnt=1;
	cout<<temp<<endl;
	for(int i=1;i<k;i++){
		if(x[i]-temp>=m) cnt++;
		temp=x[i];
		cout<<temp<<endl;
	}
	if(cnt>=n) cout<<"true";
	else cout<<"false";
}
int main(){
	cin>>n>>k;
	for(int i=0;i<k;i++) cin>>x[i];
	sort(x,x+k);
	check(6);
}
