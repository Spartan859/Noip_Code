#include<bits/stdc++.h>
using namespace std;
set<int> s;
set<int>::iterator it;
int x,n;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		s.insert(x);
	}
	cout<<s.size()<<endl;
	for(it=s.begin();it!=s.end();it++) cout<<*it<<' ';
	cout<<endl;
	return 0;
}
