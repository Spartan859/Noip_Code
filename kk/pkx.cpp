#include<bits/stdc++.h>
using namespace std;
int main(){
	map<string,int> d;
	map<string,int>::iterator it;
	int n;
	cin>>n;
	string s1,s2,pk;
	for(int i=0;i<=n;i++){
		cin>>s1>>s2;
		pk=s1+s2;
		if(d[pk]>0){
			cout<<"I am angry"<<endl;
			return 0;
		}
		d[pk]++;
	}
	cout<<"Nice hand"<<endl;
	return 0;
}
