#include<iostream>
#include<string>
using namespace std;
string n;
long long t1,t2,t3,t4;
int main(){
	cin>>n;
	for(int i=0;i<n.size();i++){
		if(n[i]=='3') t1++;
		if(n[i]=='7') t2++;
		if(n[i]=='2') t3++;
		if(n[i]=='1') t4++;
	}
	if(t1>0&&t2>0&&t3>0&&t4>0) cout<<"Yes";
	else cout<<"No";
	return 0;
}
