#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	string s[n+1];
	for(int i=0;i<=n;i++) getline(cin,s[i]);
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			if(s[i]==s[j]&&i!=j){
				cout<<i<<' '<<j;
				return 0;
			}
	cout<<"Nice hand";
	return 0;
}
